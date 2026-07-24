#include "widget.h"
#include "ui_widget.h"
#include <QCoreApplication>
#include <QDate>
#include <QTime>
#include <QDebug>
#include <QHeaderView>
#include <QString>
#include <QMediaPlayer>
#include <QFile>
#include <QPainter>
#include <QFontMetrics>
#include "face/faceengine.h"
#include "face/facecapture.h"
#include "face/facedetector.h"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_clockTimer = new QTimer(this);
    m_sharedSerial = new QSerialPort(this);
    m_recentModel = new QSqlQueryModel(this);
    m_cardTimeout = new QTimer(this);
    //创建子页面
    m_regis = new RegisterWidget();
    m_smp = new SystemManagementPanel();
    m_loginAdmin = new LoginAdminWidget();

    // 串口刷卡
    connect(m_sharedSerial,&QSerialPort::readyRead,this,&Widget::onSerialReadyRead);
    m_smp->setSerial(m_sharedSerial);
    //分发串口指针
    m_regis->setSerial(m_sharedSerial);
    m_loginAdmin->setSerialPort(m_sharedSerial);

    //分发友元指针
    m_loginAdmin->setSMP(m_smp);

    // 管理员设置页 → 管理员注册入口（将RegisterWidget传给管理员设置页）
    m_smp->setRegisterWidget(m_regis);

    // 登录界面 → 返回打卡界面
    connect(m_loginAdmin, &LoginAdminWidget::backToCheckIn, this, [=](){
        this->show();
        m_loginAdmin->hide();
    });

    //最近打卡表格
    setupRecentRecords();

    //1秒时钟
    connect(m_clockTimer, &QTimer::timeout, this, &Widget::onClockTick);
    m_clockTimer->start(1000);

    //发送解析卡号给smp页面
    connect(this,&Widget::cardParseSystemPage,m_smp,&SystemManagementPanel::ondataReceived);

    //发送解析卡号的信号给 smp 中实际显示的员工注册页
    connect(this,&Widget::cardParsed,m_smp->getUserRegisterPage(),&UserRegisterWidget::onCardReceived);

    //发送原始串口数据给串口设置页的接收面板
    connect(this,&Widget::rawSerialData,m_smp->getSerialWidget(),&SerialSetWidget::onRawDataReceived);

    //发送解析卡号的信号给smp中实际显示的员工信息修改页
    connect(this,&Widget::cardParsedToModify,m_smp->getUserModifyPage(),&UserModifyWidget::onCardReceived);

    //发送解析卡号的信号给smp中实际显示的考勤表查询页
    connect(this,&Widget::cardParseAttendance,m_smp->getAttendancePage(),&AttendanceRecordsWidget::onCardReceived);

    //发送解析卡号的信号给smp中实际显示的充值扣款页
    connect(this,&Widget::cardParseRecharge,m_smp->getRechargePage(),&RechargeAndDeductionWidget::onCardReceived);

    //发送解析卡号的信号给管理员注册页面
    connect(this,&Widget::cardParseRegistPage,m_regis,&RegisterWidget::onCardReceived);

    //发送解析卡号的信号给管理员登录页面
    connect(this,&Widget::cardParseLoginPage,m_loginAdmin,&LoginAdminWidget::onCardReceived);

    //接收控制面板界面发出的返回信号
    connect(m_smp,&SystemManagementPanel::backToAttendance,[=](){
        this->show();
        m_smp->hide();
    });
    //刷卡超时定时器：500ms内无新数据则强制解析缓冲
    m_cardTimeout->setSingleShot(true);
    connect(m_cardTimeout,&QTimer::timeout,this,&Widget::onCardTimeout);

    //程序启动时，读取QSettings上次保存的串口配置，自动打开串口
    tryAutoOpenSerial();

    //初始化人脸识别引擎
    // 智能模型路径：
    // 1) ./models（相对路径，Enigma 打包 + Qt Creator 正常运行）
    // 2) exe目录/models（绝对路径，windeployqt 打包版）
    // 3) SDK绝对路径（开发环境回退）
    QStringList searchPaths;
    searchPaths << "./models"
                << QString("%1/models").arg(QCoreApplication::applicationDirPath());
#ifdef Q_OS_WIN
    searchPaths << "D:/SeetaFace6_Windows/models";
#else
    searchPaths << "/home/zwt/opt/SeetaFace6/models";
#endif

    QString modelPath;
    for (const QString &p : searchPaths) {
        if (QFile::exists(p + "/face_detector.csta")) {
            modelPath = p;
            break;
        }
    }
    bool initOk = false;
    if (!modelPath.isEmpty())
        initOk = FaceEngine::instance()->init(modelPath.toStdString());
    qDebug() << "[人脸] 模型路径:" << modelPath << (initOk ? "成功" : "失败");
qDebug() << "[人脸] FaceEngine初始化:" << (initOk ? "成功" : "失败");

    // 创建人脸检测工作线程（所有重活在此线程执行，不阻塞UI）
    m_faceThread = new QThread(this);
    m_faceWorker = new FaceDetector();
    m_faceWorker->moveToThread(m_faceThread);
    connect(m_faceThread, &QThread::finished, m_faceWorker, &QObject::deleteLater);
    // 主线程 → 工作线程：发送帧
    connect(this, &Widget::frameForDetection, m_faceWorker, &FaceDetector::processFrame);
    // 工作线程 → 主线程：各种结果
    connect(m_faceWorker, &FaceDetector::matchResult,  this, &Widget::onFaceMatch,     Qt::QueuedConnection);
    connect(m_faceWorker, &FaceDetector::noMatch,     this, &Widget::onFaceNoMatch,   Qt::QueuedConnection);
    connect(m_faceWorker, &FaceDetector::noFace,      this, &Widget::onFaceNone,      Qt::QueuedConnection);
    connect(m_faceWorker, &FaceDetector::noUsers,     this, &Widget::onFaceNoUsers,   Qt::QueuedConnection);
    m_faceThread->start();

    // 刷脸状态标签
    m_faceStatusLabel = new QLabel("等待摄像头...", this);
    m_faceStatusLabel->setAlignment(Qt::AlignCenter);
    m_faceStatusLabel->setStyleSheet(
        "QLabel{ border:none; font-size:14px; color:#666; background:transparent; }");
    ui->mainVerticalLayout->insertWidget(ui->mainVerticalLayout->indexOf(ui->recentRecordsFrame),
                                         m_faceStatusLabel);

    // 摄像头按需启动：打卡页显示时抓帧，隐藏时停止
    FaceCapture::instance()->setDisplay(ui->lblCamera);
    connect(FaceCapture::instance(), &FaceCapture::frameCaptured,
            this, &Widget::tryFaceCheckIn);
    // 摄像头由 showEvent/hideEvent 按需启停
}

Widget::~Widget()
{
    FaceCapture::instance()->stop();
    m_faceThread->quit();
    m_faceThread->wait(3000);
    delete ui;
}

// 串口数据接收:只缓冲数据并重置定时器，解析由onCardTimeout统一处理
void Widget::onSerialReadyRead()
{
    m_cardBuffer.append(m_sharedSerial->readAll());
    m_cardTimeout->start(500);
}

//时钟刷新
void Widget::onClockTick()
{
    QTime now = QTime::currentTime();
    QDate today = QDate::currentDate();
    QStringList weekDays = {"日","一","二","三","四","五","六"};

    ui->clockLabel->setText(now.toString("HH:mm:ss"));
    ui->dateLabel->setText(QString("%1年%2月%3日 星期%4")
        .arg(today.year())
        .arg(today.month())
        .arg(today.day())
        .arg(weekDays[today.dayOfWeek() % 7]));
}

// 刷卡超时：500ms内无新数据 → 解析缓冲内接收到的卡片数据
void Widget::onCardTimeout()
{
    if(m_cardBuffer.isEmpty()) return;

    QString rawData = QString(m_cardBuffer).trimmed();
    m_cardBuffer.clear();

    // 将原始数据发送给串口设置页的接收面板
    emit rawSerialData(rawData);

    //卡号组成形式：13-e4-5f-6
    //从原始数据中提取卡号 — 跳过空行，取含'-'的行
    QString cardNumber;
    QStringList lines = rawData.split(QRegExp("[\r\n]+"), QString::SkipEmptyParts);
    for(int i = 0; i < lines.size(); ++i)
    {
        if(lines[i].contains("卡号"))
        {
            int idxColon = lines[i].indexOf(QRegExp("[：:]"));
            if(idxColon >= 0)
                cardNumber = lines[i].mid(idxColon + 1).trimmed();
            if(cardNumber.isEmpty())
            {
                for(int j = i + 1; j < lines.size(); ++j)
                {
                    if(lines[j].contains('-'))
                    {
                        cardNumber = lines[j].trimmed();
                        break;
                    }
                }
            }
            break;
        }
    }
    if(cardNumber.isEmpty()) return;
qDebug() << "解析到卡号:" << cardNumber;

    if(this->isVisible()){
    onCardScanned(cardNumber);
    }
    emit cardParsed(cardNumber);
    emit cardParsedToModify(cardNumber);
    emit cardParseAttendance(cardNumber);
    emit cardParseRecharge(cardNumber);
    emit cardParseRegistPage(cardNumber);
    emit cardParseLoginPage(cardNumber);
    emit cardParseSystemPage(cardNumber);
}

//刷卡处理
void Widget::onCardScanned(const QString &card)
{
    // 同卡号2秒内不重复处理，防止误刷
    if(card == m_lastCard && m_lastCardTime.msecsTo(QTime::currentTime()) < 5000) {
        return;
    }
    m_lastCard = card;
    m_lastCardTime = QTime::currentTime();

    MySql *db = MySql::getMySql();

    // 判断是否是员工卡,管理员刷卡LoginAdminWidget独立处理
    QString name;
    int age;
    QString sex, registerTime;
    double balance;
    if(db->getUserByCard(card, name, age, sex, registerTime, balance))
    {
        QDate today = QDate::currentDate();
        QString dateStr = today.toString("yyyy-MM-dd");

        if(db->isCheckedInTodayByCard(card, dateStr))
        {
            // 已签到 → 执行签退
            doCheckOut(card, name);
        }
        else
        {
            // 未签到 → 执行签到
            doCheckIn(card, name);
        }
        refreshRecentRecords();
        return;
    }

    // 3. 未注册卡号
    // 未注册卡号音效
    playSound(":/image/invalid_card_detected.wav");

    ui->checkInResultLabel->setStyleSheet(
        "QLabel{ border:none; font-size:16px; color:#C0392B; background:transparent; }");
    ui->checkInResultLabel->setText(QString("未注册卡号：%1").arg(card));
}

//串口自动开启
// 程序启动时读取 QSettings 中上次保存的串口配置，自动打开串口
void Widget::tryAutoOpenSerial()
{
    QSettings settings("AttendanceSystem", "SerialConfig");

    // 读取上次保存的配置，无记录则返回
    QString port   = settings.value("port", "").toString();
    if(port.isEmpty())
    {
qDebug() << "首次启动，无串口配置记录，等待管理员配置";
        updateSerialStatus(false);
        return;
    }

    int baud = settings.value("baud", 115200).toInt();
    int dataBits = settings.value("dataBits", 8).toInt();
    QString stopBits = settings.value("stopBits", "1").toString();
    QString parity = settings.value("parity", "None").toString();
    QString flow = settings.value("flow", "None").toString();

    // 端口名
    m_sharedSerial->setPortName(port);

    // 波特率
    m_sharedSerial->setBaudRate(static_cast<QSerialPort::BaudRate>(baud));

    // 数据位
    if(dataBits == 5)       m_sharedSerial->setDataBits(QSerialPort::Data5);
    else if(dataBits == 6)  m_sharedSerial->setDataBits(QSerialPort::Data6);
    else if(dataBits == 7)  m_sharedSerial->setDataBits(QSerialPort::Data7);
    else                    m_sharedSerial->setDataBits(QSerialPort::Data8);

    // 停止位
    if(stopBits == "1.5")       m_sharedSerial->setStopBits(QSerialPort::OneAndHalfStop);
    else if(stopBits == "2")    m_sharedSerial->setStopBits(QSerialPort::TwoStop);
    else                        m_sharedSerial->setStopBits(QSerialPort::OneStop);

    // 校验位
    if(parity == "Odd")         m_sharedSerial->setParity(QSerialPort::OddParity);
    else if(parity == "Even")   m_sharedSerial->setParity(QSerialPort::EvenParity);
    else                        m_sharedSerial->setParity(QSerialPort::NoParity);

    // 流控制
    if(flow == "Hardware")      m_sharedSerial->setFlowControl(QSerialPort::HardwareControl);
    else if(flow == "Software") m_sharedSerial->setFlowControl(QSerialPort::SoftwareControl);
    else                        m_sharedSerial->setFlowControl(QSerialPort::NoFlowControl);

    // 尝试打开串口
    if(m_sharedSerial->open(QIODevice::ReadWrite))
    {
qDebug() << "串口自动打开成功:" << port;
        updateSerialStatus(true);
    }
    else
    {
qDebug() << "串口自动打开失败:" << port << m_sharedSerial->errorString();
        updateSerialStatus(false);
    }
}

// 更新打卡区界面上的串口状态提示
void Widget::updateSerialStatus(bool isOpen)
{
    if(isOpen)
    {
        ui->checkInTitleLabel->setText("请刷卡签到 / 签退");
        ui->checkInResultLabel->setText("等待刷卡...");
    }
    else
    {
        ui->checkInTitleLabel->setText("串口未连接");
        ui->checkInResultLabel->setText("请联系管理员配置串口");
    }
}

// 通用音效播放（单播放器，新音效自动停旧音效，防止重叠）
void Widget::playSound(const QString &file)
{
    static QMediaPlayer *s_sound = nullptr;
    if (!s_sound) {
        s_sound = new QMediaPlayer(this);
        s_sound->setVolume(80);
    }
    s_sound->stop();
    s_sound->disconnect();
    QFile *af = new QFile(file, s_sound);
    if (af->open(QIODevice::ReadOnly)) {
        s_sound->setMedia(QMediaContent(), af);
        connect(s_sound, &QMediaPlayer::mediaStatusChanged, this, [](QMediaPlayer::MediaStatus st) {
            if (st == QMediaPlayer::LoadedMedia) s_sound->play();
        });
    } else {
        delete af;
    }
}

// 主线程只转发帧到工作线程
void Widget::tryFaceCheckIn(const QImage &image)
{
    if (image.isNull() || !this->isVisible()) return;
    emit frameForDetection(image);
}

void Widget::onFaceNone() {
    m_faceStatusLabel->setText("未检测到人脸");
}
void Widget::onFaceNoUsers() {
    static QTime lastSound;
    m_faceStatusLabel->setText("陌生人脸");
    if (!lastSound.isValid() || lastSound.msecsTo(QTime::currentTime()) > 30000) {
        lastSound = QTime::currentTime();
        playSound(":/image/stranger_face.wav");
    }
}
void Widget::onFaceMatch(const QString &card, const QString &name, float) {
qDebug() << "[人脸] 收到匹配结果:" << name << card;
    m_faceStatusLabel->setText(QString("识别成功: %1").arg(name));
    if (!this->isVisible()) return;

    static QTime lastMatch;
    if (!lastMatch.isValid() || lastMatch.msecsTo(QTime::currentTime()) > 30000) {
        lastMatch = QTime::currentTime();
        // 调签到/签退方法，不走 onCardScanned 的卡片去重逻辑
        MySql *db = MySql::getMySql();
        QDate today = QDate::currentDate();
        QString dateStr = today.toString("yyyy-MM-dd");
        if (db->isCheckedInTodayByCard(card, dateStr))
            doCheckOut(card, name);
        else
            doCheckIn(card, name);
        refreshRecentRecords();
        // 同步更新 checkInResultLabel 显示打卡结果
        QTime now = QTime::currentTime();
        ui->checkInResultLabel->setStyleSheet(
            "QLabel{ border:none; font-size:16px; color:#27AE60; background:transparent; }");
        ui->checkInResultLabel->setText(
            QString("刷脸打卡: %1  %2").arg(name, now.toString("HH:mm:ss")));
    }
}

// 工作线程回调：匹配失败
void Widget::onFaceNoMatch(float) {
    static QTime lastFailSound;
    m_faceStatusLabel->setText("未识别到已注册人脸");
    if (!lastFailSound.isValid() || lastFailSound.msecsTo(QTime::currentTime()) > 10000) {
        lastFailSound = QTime::currentTime();
        playSound(":/image/invalid_card_detected.wav");
    }
}

//签到/签退
void Widget::doCheckIn(const QString &card, const QString &name)
{
    MySql *db = MySql::getMySql();
    QDate today = QDate::currentDate();
    QString dateStr = today.toString("yyyy-MM-dd");
    QString timeStr = QTime::currentTime().toString("HH:mm:ss");

    if(db->checkIn(card, name, dateStr, timeStr))
    {
        playSound(":/image/check_in_success.wav");
        ui->checkInResultLabel->setStyleSheet(
            "QLabel{ border:none; font-size:16px; color:#27AE60; background:transparent; }");
        ui->checkInResultLabel->setText(QString("%1  签到成功  %2").arg(name, timeStr));
    }
}

void Widget::doCheckOut(const QString &card, const QString &name)
{
    MySql *db = MySql::getMySql();
    QDate today = QDate::currentDate();
    QString dateStr = today.toString("yyyy-MM-dd");
    QString timeStr = QTime::currentTime().toString("HH:mm:ss");

    if(db->checkOut(card, dateStr, timeStr))
    {
        playSound(":/image/check_out_success.wav");
        ui->checkInResultLabel->setStyleSheet(
            "QLabel{ border:none; font-size:16px; color:#27AE60; background:transparent; }");
        ui->checkInResultLabel->setText(
            QString("%1  签退成功  %2").arg(name, timeStr));
    }
}

//管理员入口按钮

void Widget::on_adminEntryButton_clicked()
{
    this->hide();
    m_loginAdmin->show();
}

void Widget::showEvent(QShowEvent *ev)
{
    QWidget::showEvent(ev);
    FaceCapture::instance()->start();
qDebug() << "[人脸] 摄像头启动（打卡页显示）";
}

void Widget::hideEvent(QHideEvent *ev)
{
    QWidget::hideEvent(ev);
    FaceCapture::instance()->stop();
qDebug() << "[人脸] 摄像头停止（打卡页隐藏）";
}


//最近打卡表格
void Widget::setupRecentRecords()
{
    m_recentModel->setQuery(
        "SELECT name,date,checkInTime,checkOutTime,status "
        "FROM card ORDER BY date DESC, checkInTime DESC LIMIT 10");

    m_recentModel->setHeaderData(0, Qt::Horizontal, "姓名");
    m_recentModel->setHeaderData(1, Qt::Horizontal, "日期");
    m_recentModel->setHeaderData(2, Qt::Horizontal, "签到时间");
    m_recentModel->setHeaderData(3, Qt::Horizontal, "签退时间");
    m_recentModel->setHeaderData(4, Qt::Horizontal, "状态");

    ui->recentRecordTableView->setModel(m_recentModel);
    ui->recentRecordTableView->horizontalHeader()->setStretchLastSection(true);
    ui->recentRecordTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void Widget::refreshRecentRecords()
{
    m_recentModel->setQuery(
        "SELECT name,date,checkInTime,checkOutTime,status "
        "FROM card ORDER BY date DESC, checkInTime DESC LIMIT 10");
}
