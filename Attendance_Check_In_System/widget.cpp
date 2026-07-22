#include "widget.h"
#include "ui_widget.h"
#include <QDate>
#include <QTime>
#include <QDebug>
#include <QHeaderView>
#include <QString>
#include <QMediaPlayer>
#include <QFile>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    m_clockTimer(new QTimer(this)),
    m_sharedSerial(new QSerialPort(this)),
    m_recentModel(new QSqlQueryModel(this)),
    m_cardTimeout(new QTimer(this))
{
    ui->setupUi(this);

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
    m_loginAdmin->setRegisterWidget(m_regis);

    // 管理员注册 → 返回登录
    connect(m_regis, &RegisterWidget::closeRegister, this, [=](){
        m_loginAdmin->show();
        m_regis->hide();
    });
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

    //刷卡超时定时器：500ms内无新数据则强制解析缓冲
    m_cardTimeout->setSingleShot(true);
    connect(m_cardTimeout,&QTimer::timeout,this,&Widget::onCardTimeout);

    //程序启动时，读取QSettings上次保存的串口配置，自动打开串口
    tryAutoOpenSerial();

}

Widget::~Widget()
{
    delete ui;
}

// 串口数据接收:只缓冲数据并重置定时器，解析由 onCardTimeout 统一处理
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
    qDebug() << "(超时)解析到卡号:" << cardNumber;

    if(this->isVisible()){
    onCardScanned(cardNumber);
    }
    emit cardParsed(cardNumber);
    emit cardParsedToModify(cardNumber);
    emit cardParseAttendance(cardNumber);
    emit cardParseRecharge(cardNumber);
    emit cardParseRegistPage(cardNumber);
    emit cardParseLoginPage(cardNumber);
}

//刷卡处理
void Widget::onCardScanned(const QString &card)
{
    //同一卡号2秒内只处理一次
    if(card == m_lastCard && m_lastCardTime.msecsTo(QTime::currentTime()) < 2000)
    {
        ui->checkInResultLabel->setStyleSheet(
            "QLabel{ border:none; font-size:16px; color:#ff0000; background:transparent; }");
        ui->checkInResultLabel->setText("请勿重复打卡");
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

    int     baud     = settings.value("baud", 115200).toInt();
    int     dataBits = settings.value("dataBits", 8).toInt();
    QString stopBits = settings.value("stopBits", "1").toString();
    QString parity   = settings.value("parity", "None").toString();
    QString flow     = settings.value("flow", "None").toString();

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

//签到/签退
void Widget::doCheckIn(const QString &card, const QString &name)
{
    //签到逻辑
    MySql *db = MySql::getMySql();
    QDate today = QDate::currentDate();
    QString dateStr = today.toString("yyyy-MM-dd");
    QString timeStr = QTime::currentTime().toString("HH:mm:ss");

    if(db->checkIn(card, name, dateStr, timeStr))
    {
        // 签到成功音效（通过 QFile 流加载 qrc 资源，QMediaPlayer 才能正确识别）
        QMediaPlayer *sound = new QMediaPlayer;
        QFile *audioFile = new QFile(":/image/check_in_success.wav", sound);
        if (audioFile->open(QIODevice::ReadOnly)) {
            sound->setMedia(QMediaContent(), audioFile);
            sound->setVolume(80);
            // 媒体加载完成后自动播放
            connect(sound, &QMediaPlayer::mediaStatusChanged, [sound](QMediaPlayer::MediaStatus status) {
                if (status == QMediaPlayer::LoadedMedia) {
                    sound->play();
                }
            });
            // 播放结束后释放内存
            connect(sound, &QMediaPlayer::stateChanged, [sound](QMediaPlayer::State state) {
                if (state == QMediaPlayer::StoppedState) {
                    sound->deleteLater();
                }
            });
        } else {
            qDebug() << "签到音效: 无法打开音频文件";
            delete sound;
        }

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
        // 签退成功音效（通过 QFile 流加载 qrc 资源，QMediaPlayer 才能正确识别）
        QMediaPlayer *sound = new QMediaPlayer;
        QFile *audioFile = new QFile(":/image/check_out_success.wav", sound);
        if (audioFile->open(QIODevice::ReadOnly)) {
            sound->setMedia(QMediaContent(), audioFile);
            sound->setVolume(80);
            // 媒体加载完成后自动播放
            connect(sound, &QMediaPlayer::mediaStatusChanged, [sound](QMediaPlayer::MediaStatus status) {
                if (status == QMediaPlayer::LoadedMedia) {
                    sound->play();
                }
            });
            // 播放结束后释放内存
            connect(sound, &QMediaPlayer::stateChanged, [sound](QMediaPlayer::State state) {
                if (state == QMediaPlayer::StoppedState) {
                    sound->deleteLater();
                }
            });
        } else {
            qDebug() << "签退音效: 无法打开音频文件";
            delete sound;
        }

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
