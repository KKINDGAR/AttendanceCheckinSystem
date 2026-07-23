#include "usermodifywidget.h"
#include "ui_usermodifywidget.h"
#include "face/faceengine.h"
#include "face/facecapture.h"
#include <QMediaPlayer>
#include <QFile>

UserModifyWidget::UserModifyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserModifyWidget)
{
    ui->setupUi(this);
    db = MySql::getMySql();//获取数据库
    m_model = new QSqlQueryModel(this);

    //绑定员工表，实时查看修改信息
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
    m_model->setHeaderData(5, Qt::Horizontal, "卡内余额");

    //表格外观
    ui->userInfoTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->userInfoTableView->setAlternatingRowColors(true);
    ui->userInfoTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->userInfoTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

UserModifyWidget::~UserModifyWidget()
{
    delete ui;
}

void UserModifyWidget::setSerial(QSerialPort *serial)
{
    m_serial = serial;//获取串口
}

void UserModifyWidget::on_confirmModifyButton_clicked()
{
    MySql *db = MySql::getMySql();
    QString name = ui->nameEdit->text();
    int age = ui->ageSpinBox->value();
    QString sex = ui->sexComboBox->currentText();
    if(m_cardNumber.isEmpty()||name.isEmpty())
    {
        playSound(":/image/modify_fail_empty_form.wav");
        return;
    }
    db->updateUser(m_cardNumber,name,age,sex);
    m_model->setQuery("SELECT card,name,age,sex,registerTime,balance FROM user");
    playSound(":/image/modify_success.wav");
}

void UserModifyWidget::on_resetButton_clicked()
{
    ui->cardNumEdit->clear();
    ui->nameEdit->clear();
    ui->ageSpinBox->clear();
    ui->sexComboBox->clear();
    ui->registerTimeEdit->clear();
}

void UserModifyWidget::on_deleteEmployeeButton_clicked()
{
    MySql *db = MySql::getMySql();
    QString cardNumber = ui->cardNumEdit->text();
    if(cardNumber.isEmpty())
    {
        QMessageBox::critical(this,"错误","卡号为空，无法操作");
        return;
    }
    QMessageBox::StandardButton btn = QMessageBox::question(
        this, "确认删除", "确定删除该员工吗？\n此操作不可恢复！",
        QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
    if (btn == QMessageBox::Yes) {
        db->deleteUser(m_cardNumber);
        m_model->setQuery("SELECT card,name,age,sex,registerTime,balance FROM user");
    }
}
//关闭打开摄像头
void UserModifyWidget::showEvent(QShowEvent *ev)
{
    QWidget::showEvent(ev); FaceCapture::instance()->start();
}
void UserModifyWidget::hideEvent(QHideEvent *ev)
{
    QWidget::hideEvent(ev); FaceCapture::instance()->stop();
}

void UserModifyWidget::onCardReceived(const QString &cardNumber)
{
    if(!this->isVisible())
    {
        return;
    }
    ui->cardNumEdit->setText(cardNumber);
    m_cardNumber = cardNumber;
    QString name;
    QString sex;
    int age;
    double blance = db->getUserBalance(cardNumber);
    QString registerTime = db->getUserRegisterTime(cardNumber);
    if(db->getUserByCard(cardNumber,name,age,sex,registerTime,blance))
    {
        ui->nameEdit->setText(name);
        ui->ageSpinBox->setValue(age);
//        ui->sexComboBox->setCurrentText(sex);
        ui->registerTimeEdit->setText(registerTime);
    }
}

void UserModifyWidget::on_captureFaceBtn_clicked()
{
    if (m_cardNumber.isEmpty()) {
        QMessageBox::warning(this, "提示", "请先刷卡定位员工");
        return;
    }

    QImage frame = FaceCapture::instance()->currentFrame();
    if (frame.isNull()) {
        QMessageBox::warning(this, "提示", "摄像头未就绪，请稍后再试");
        return;
    }

    std::vector<float> feat;
    if (!FaceEngine::instance()->detectFace(frame, feat)) {
        QMessageBox::warning(this, "提示", "未检测到人脸，请面对摄像头");
        return;
    }

    if (db->updateUserFace(m_cardNumber, feat)) {
        playSound(":/image/face_supplement_success.wav");
    } else {
        QMessageBox::critical(this, "失败", "人脸数据保存失败");
    }
}

void UserModifyWidget::on_refrshUserTableButton_clicked()
{
    m_model->setQuery("SELECT card,name,age,sex,registerTime,balance FROM user");
}

void UserModifyWidget::playSound(const QString &file)
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
