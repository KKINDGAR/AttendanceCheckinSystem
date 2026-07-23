#include "systemmanagementpanel.h"
#include "ui_systemmanagementpanel.h"
#include <QTime>
#include <QTimer>
SystemManagementPanel::SystemManagementPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SystemManagementPanel)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    HomePageWidget *home = qobject_cast<HomePageWidget*>(ui->homePage);
    connect(home,&HomePageWidget::navigateTo,this,[=](int index){
        ui->stackedWidget->setCurrentIndex(index);
        switch (index)
        {
        //改变侧边栏按钮点击状态
        case 1: ui->navRegisterButton->setChecked(true);   break;
        case 2: ui->navModifyButton->setChecked(true);     break;
        case 3: ui->navRecordsButton->setChecked(true);    break;
        case 4: ui->rachargeButton->setChecked(true);      break;
        }
    });
    m_clockTimer = new QTimer(this);
    connect(m_clockTimer, &QTimer::timeout, this, &SystemManagementPanel::onClockTick);
    m_clockTimer->start(1000);
}

SystemManagementPanel::~SystemManagementPanel()
{
    delete ui;
}

void SystemManagementPanel::on_navHomeButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void SystemManagementPanel::on_navRegisterButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void SystemManagementPanel::on_navModifyButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void SystemManagementPanel::on_navRecordsButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void SystemManagementPanel::on_rachargeButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void SystemManagementPanel::on_navSerialButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

UserRegisterWidget* SystemManagementPanel::getUserRegisterPage()
{
    return qobject_cast<UserRegisterWidget*>(ui->userRegisterPage);
}

SerialSetWidget* SystemManagementPanel::getSerialWidget()
{
    return qobject_cast<SerialSetWidget*>(ui->serailSetPage);
}

UserModifyWidget *SystemManagementPanel::getUserModifyPage()
{
    return qobject_cast<UserModifyWidget*>(ui->userModifyPage);
}

AttendanceRecordsWidget *SystemManagementPanel::getAttendancePage()
{
    return qobject_cast<AttendanceRecordsWidget*>(ui->atendencePage);
}

RechargeAndDeductionWidget *SystemManagementPanel::getRechargePage()
{
    return qobject_cast<RechargeAndDeductionWidget*>(ui->rechargeDeductionPage);
}

void SystemManagementPanel::setSerial(QSerialPort *serial)
{
    m_serial = serial;
    // 分发给 stackedWidget 中的子页面
    qobject_cast<HomePageWidget*>(ui->homePage)->setSerialPort(serial);
    qobject_cast<UserRegisterWidget*>(ui->userRegisterPage)->setSerial(serial);
    qobject_cast<UserModifyWidget*>(ui->userModifyPage)->setSerial(serial);
    qobject_cast<AttendanceRecordsWidget*>(ui->atendencePage)->setSerial(serial);
    qobject_cast<SerialSetWidget*>(ui->serailSetPage)->setSerial(serial);
    qobject_cast<RechargeAndDeductionWidget*>(ui->rechargeDeductionPage)->setSerial(serial);
}

void SystemManagementPanel::setAdminCard(const QString &card)
{
    m_cardNumber = card;
    MySql *db = MySql::getMySql();
    QString name;
    if(db->getAdminName(card, name))
    {
        ui->managerNameLabel->setStyleSheet("QLabel"
        "{"
            "border:none;"
            "font-size: 20px;"
            "font-weight: bold;"
            "color: #1A3A6B;"
            "qproperty-alignment: AlignCenter;"
            "background:transparent;"
        "}");
        ui->managerLabel->setStyleSheet("QLabel"
        "{"
            "border:none;"
            "font-size: 20px;"
            "font-weight: bold;"
            "color: #1A3A6B;"
            "qproperty-alignment: AlignCenter;"
            "background:transparent;"
        "}");
        ui->managerNameLabel->setText(name);
    }
}

void SystemManagementPanel::on_navLogoutButton_clicked()
{
    //退出登录，返回到考勤打卡页面
    emit backToAttendance();
}

void SystemManagementPanel::onClockTick()
{
    QTime now = QTime::currentTime();
    ui->localTimeLabel->setStyleSheet("QLabel"
    "{"
        "border:none;"
        "font-size: 20px;"
        "font-weight: bold;"
        "color: #1A3A6B;"
        "qproperty-alignment: AlignCenter;"
        "background:transparent;"
    "}");
    ui->localTimeLabel->setText(now.toString("HH:mm:ss"));
    updateSerialStatus();
}

void SystemManagementPanel::ondataReceived(const QString &cardNumber)
{
    if(!this->isVisible())
    {
        return;
    }
    m_cardNumber = cardNumber;
}

void SystemManagementPanel::updateSerialStatus()
{
    if(m_serial && m_serial->isOpen())
    {
        ui->serailTextLabel->setStyleSheet("Qlabel{background-color:#27AE60;}");
        ui->serailTextLabel->setText(QString("串口%1已连接").arg(m_serial->portName()));
    }
    else
    {
        ui->serailTextLabel->setStyleSheet("Qlabel{background-color:#C0392B;}");
        ui->serailTextLabel->setText("串口已断开");
    }
}
