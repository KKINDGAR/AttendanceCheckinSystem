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
        case 6: ui->navAdminManageButton->setChecked(true); break;
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
    ui->navAdminManageButton->setChecked(false);
    ui->stackedWidget->setCurrentIndex(0);
}

void SystemManagementPanel::on_navRegisterButton_clicked()
{
    ui->navAdminManageButton->setChecked(false);
    ui->stackedWidget->setCurrentIndex(1);
}

void SystemManagementPanel::on_navModifyButton_clicked()
{
    ui->navAdminManageButton->setChecked(false);
    ui->stackedWidget->setCurrentIndex(2);
}

void SystemManagementPanel::on_navRecordsButton_clicked()
{
    ui->navAdminManageButton->setChecked(false);
    ui->stackedWidget->setCurrentIndex(3);
}

void SystemManagementPanel::on_rachargeButton_clicked()
{
    ui->navAdminManageButton->setChecked(false);
    ui->stackedWidget->setCurrentIndex(4);
}

void SystemManagementPanel::on_navSerialButton_clicked()
{
    ui->navAdminManageButton->setChecked(false);
    ui->stackedWidget->setCurrentIndex(5);
}

void SystemManagementPanel::on_navAdminManageButton_clicked()
{
    //非root 用户拒绝进入
    if (m_adminName != "root") {
        QMessageBox::warning(this, "权限不足",
            "只有超级管理员(root)才能进入管理员设置页面");
        ui->navAdminManageButton->setChecked(false);
        return;
    }
    // 显式互斥：管理员设置按钮与其他按钮不同父，autoExclusive 不生效
    ui->navHomeButton->setChecked(false);
    ui->navRegisterButton->setChecked(false);
    ui->navModifyButton->setChecked(false);
    ui->navRecordsButton->setChecked(false);
    ui->rachargeButton->setChecked(false);
    ui->navSerialButton->setChecked(false);
    ui->navAdminManageButton->setChecked(true);
    ui->stackedWidget->setCurrentIndex(6);
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

SetAdminWidge* SystemManagementPanel::getAdminSettingsPage()
{
    return qobject_cast<SetAdminWidge*>(ui->adminSettingsPage);
}

void SystemManagementPanel::setRegisterWidget(RegisterWidget *regis)
{
    qobject_cast<SetAdminWidge*>(ui->adminSettingsPage)->setRegisterWidget(regis);
    qobject_cast<SetAdminWidge*>(ui->adminSettingsPage)->setSystemManagementPanel(this);
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
    qobject_cast<SetAdminWidge*>(ui->adminSettingsPage)->setSerial(serial);
}

void SystemManagementPanel::setAdminCard(const QString &card)
{
    m_cardNumber = card;
    MySql *db = MySql::getMySql();
    QString name;

    // 先按卡号查，再按用户名查（兼容用户名登录时 card 参数实际是用户名的情况）
    bool found = db->getAdminName(card, name);
    if (!found) {
        QSqlQuery q;
        q.prepare("SELECT adminCard, name FROM admin WHERE name = ?");
        q.addBindValue(card);
        if (q.exec() && q.next()) {
            m_cardNumber = q.value(0).toString();  // 修正为真实卡号
            name = q.value(1).toString();
            found = true;
        }
    }

    if (found) {
        m_adminName = name;  // 存储管理员姓名，用于权限判断

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

        // 权限门控：仅超级管理员 root 可见"管理员设置"按钮行
        // 弹簧(verticalSpacer_6/7)始终保留在verticalLayout中，隐藏按钮后仍然参与空间分配
        ui->adminBtnWidget->setVisible(name == "root");
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

    // 转发给管理员设置页（方便修改管理员信息时刷卡录入）
    qobject_cast<SetAdminWidge*>(ui->adminSettingsPage)->onCardReceived(cardNumber);
}

void SystemManagementPanel::updateSerialStatus()
{
    if(m_serial && m_serial->isOpen())
    {
        ui->serailTextLabel->setStyleSheet("QLabel{background:transparent;}");
        ui->serilIconlabel->setPixmap(QPixmap(":/image/serailConnect.png"));
        ui->serailTextLabel->setText(QString("串口%1已连接").arg(m_serial->portName()));
    }
    else
    {
        ui->serilIconlabel->setPixmap(QPixmap(":/image/Serail.png"));
        ui->serailTextLabel->setStyleSheet("QLabel{background:transparent;}");
        ui->serailTextLabel->setText("串口已断开");
    }
}

