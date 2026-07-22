#include "loginadminwidget.h"
#include "ui_loginadminwidget.h"
#include <QMessageBox>

LoginAdminWidget::LoginAdminWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginAdminWidget),
    m_serial(nullptr),
    m_smp(nullptr),
    m_regis(nullptr)
{
    ui->setupUi(this);
}

LoginAdminWidget::~LoginAdminWidget()
{
    delete ui;
}

void LoginAdminWidget::setSerialPort(QSerialPort *serial)
{
    m_serial = serial;
}

void LoginAdminWidget::setSMP(SystemManagementPanel *smp)
{
    m_smp = smp;
}

void LoginAdminWidget::setRegisterWidget(RegisterWidget *regis)
{
    m_regis = regis;
}

void LoginAdminWidget::on_loginButton_clicked()
{
    QString account = ui->userEdit->text().trimmed();
    QString password = ui->passwordEdit->text();

    if(account.isEmpty())
    {
        QMessageBox::critical(this,"错误","请输入管理员账号或刷卡登录");
        return;
    }

    MySql *db = MySql::getMySql();
    bool isExits = false;

    if(password.isEmpty())
    {
        // 未输入密码,卡号刷卡登录
        isExits = db->adminLoginByCard(m_cardNumber);
    }
    else
    {
        // 输入了密码 → 先卡号+密码，再姓名+密码
        isExits = db->adminIsExits(account, password) || db->adminLoginByName(account, password);
    }

    if(isExits)
    {
        QMessageBox::information(this,"成功","登录成功！");
        this->hide();
        if(m_smp)
            m_smp->show();
    }
    else {
        QMessageBox::critical(this,"登录失败","账号或密码有误，请重新输入");
        return;
    }
}


void LoginAdminWidget::onCardReceived(const QString &cardNumber)
{
    if(!this->isVisible()) return;

    m_cardNumber = cardNumber;

    // 刷卡自动登录
    MySql *db = MySql::getMySql();
    if(db->adminLoginByCard(m_cardNumber))
    {
        QMessageBox::information(this, "成功", "登录成功！");
        this->hide();
        if(m_smp) m_smp->show();
    }
    else
    {
        QMessageBox::critical(this, "登录失败", "管理员卡号不存在");
    }
}

void LoginAdminWidget::on_cancelButton_clicked()
{
    emit backToCheckIn();
}

void LoginAdminWidget::on_backRegisterButton_clicked()
{
    if(m_regis)
    {
        this->hide();
        m_regis->show();
    }
}
