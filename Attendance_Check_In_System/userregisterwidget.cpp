#include "userregisterwidget.h"
#include "ui_userregisterwidget.h"
#include <QDate>
#include <QTime>
#include <QMessageBox>
#include <QMediaPlayer>
#include <QFile>
#include "face/faceengine.h"
#include "face/facecapture.h"
UserRegisterWidget::UserRegisterWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserRegisterWidget)
{
    ui->setupUi(this);
    db = MySql::getMySql();
    m_cardTimer = new QTimer(this);
    m_model = new QSqlQueryModel(this);
    //绑定数据库user表
//    m_model->setTable("user");
//    m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
//    m_model->select();
    m_model->setQuery("SELECT card,name,age,sex,registerTime,balance FROM user");
    ui->userInfoTableView->setModel(m_model);

    // 表头中文
    m_model->setHeaderData(0, Qt::Horizontal, "卡号");
    m_model->setHeaderData(1, Qt::Horizontal, "姓名");
    m_model->setHeaderData(2, Qt::Horizontal, "年龄");
    m_model->setHeaderData(3, Qt::Horizontal, "性别");
    m_model->setHeaderData(4, Qt::Horizontal, "注册时间");
    m_model->setHeaderData(5, Qt::Horizontal, "余额");

    //表格外观
    ui->userInfoTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->userInfoTableView->setAlternatingRowColors(true);
    ui->userInfoTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->userInfoTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //刷卡超时定时器，定时300ms，300ms后没有新的数据，就认为卡号接收完成
    m_cardTimer->setSingleShot(true);
    connect(m_cardTimer,&QTimer::timeout,this,&UserRegisterWidget::on_cardReadyRead);
}

UserRegisterWidget::~UserRegisterWidget()
{
    delete ui;
}

//获取串口指针,接收串口数据
void UserRegisterWidget::setSerial(QSerialPort *serial)
{
    m_serial = serial;
}
//卡号接收完成函数
void UserRegisterWidget::on_cardReadyRead()
{
    if(m_cardBuffer.isEmpty())
    {
        return;
    }
    //接收实际卡号
    QString cardId = QString(m_cardBuffer).trimmed();
    //卡号插入输入框
    ui->cardNumLineEdit->setText(cardId);
}

//重置按钮，清空所有输入框
void UserRegisterWidget::on_resetButton_clicked()
{
    ui->cardNumLineEdit->clear();
    ui->nameEdit->clear();
    ui->ageSpinBox->setValue(0);
    ui->sexComboBox->setCurrentIndex(0);
}

void UserRegisterWidget::on_saveButton_clicked()
{
        QTime now = QTime::currentTime();
        QDate toDay = QDate::currentDate();
        QString cardId = ui->cardNumLineEdit->text().trimmed();
        QString name = ui->nameEdit->text().trimmed();
        int age = ui->ageSpinBox->value();
        QString sex = ui->sexComboBox->currentText();
        QString registerTime = toDay.toString("yyyy-MM-dd").append(" ").append(now.toString("HH:mm:ss"));

        if(cardId.isEmpty()||name.isEmpty())
        {
            playSound(":/image/register_fail_empty_fields.wav");
            return;
        }
        if(db->userExists(cardId))
        {
            playSound(":/image/register_fail_duplicate_card.wav");
            return;
        }
        if(db->insertUser(cardId,name,age,sex,registerTime))
        {
            QImage frame = FaceCapture::instance()->currentFrame();
            std::vector<float> feat;
            if(!frame.isNull() && FaceEngine::instance()->detectFace(frame, feat))
            {
                db->updateUserFace(cardId, feat);
                playSound(":/image/register_success_face_ok.wav");
            }
            else
            {
                playSound(":/image/register_success_face_missing.wav");
            }
            m_model->setQuery("SELECT card,name,age,sex,registerTime,balance FROM user");
            ui->cardNumLineEdit->clear();
            ui->nameEdit->clear();
            ui->ageSpinBox->setValue(0);
            ui->sexComboBox->setCurrentIndex(0);
            ui->label->setText(QString("当前注册人数：%1").arg(m_model->rowCount()));
        }
        else {
            playSound(":/image/register_fail.wav");
        }
}

void UserRegisterWidget::on_refreshCardNummButton_clicked()
{
    ui->cardNumLineEdit->clear();
    m_cardBuffer.clear();
    ui->cardNumLineEdit->setPlaceholderText("请刷卡...");
}

void UserRegisterWidget::on_clearCardNumButton_clicked()
{
    ui->cardNumLineEdit->clear();
    m_cardBuffer.clear();
}

void UserRegisterWidget::showEvent(QShowEvent *ev) { QWidget::showEvent(ev); FaceCapture::instance()->start(); }
void UserRegisterWidget::hideEvent(QHideEvent *ev) { QWidget::hideEvent(ev); FaceCapture::instance()->stop(); }

void UserRegisterWidget::onCardReceived(const QString &cardNumber)
{
    if(!this->isVisible())
    {
        return;
    }
    ui->cardNumLineEdit->setText(cardNumber);
    m_cardTimer->start(300);
}

void UserRegisterWidget::on_refrshRegistTableButton_clicked()
{
    m_model->setQuery("SELECT card,name,age,sex,registerTime,balance FROM user");
    ui->label->setText(QString("当前注册人数：%1").arg(m_model->rowCount()));
}

void UserRegisterWidget::playSound(const QString &file)
{
    static QMediaPlayer *sp = nullptr;
    if (!sp) { sp = new QMediaPlayer; sp->setVolume(80); }
    sp->stop(); sp->disconnect();
    QFile *af = new QFile(file, sp);
    if (af->open(QIODevice::ReadOnly)) {
        sp->setMedia(QMediaContent(), af);
        QMediaPlayer *p = sp;
        QObject::connect(sp, &QMediaPlayer::mediaStatusChanged, [p](QMediaPlayer::MediaStatus st) {
            if (st == QMediaPlayer::LoadedMedia) p->play();
        });
    } else delete af;
}
