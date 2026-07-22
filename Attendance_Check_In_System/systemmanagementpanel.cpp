#include "systemmanagementpanel.h"
#include "ui_systemmanagementpanel.h"

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




