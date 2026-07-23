#include "registerwidget.h"
#include "ui_registerwidget.h"
#include "widget.h"
#include <QMessageBox>
RegisterWidget::RegisterWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterWidget)
{
    ui->setupUi(this);
    //得到数据库
    MySql *db = MySql::getMySql();
    //创建表
    db->creatTable();

}

RegisterWidget::~RegisterWidget()
{
    delete ui;
}

void RegisterWidget::on_backLoginButton_clicked()
{
    ui->userRegisterEdit->clear();
    ui->passwordRegisterEdit->clear();
    ui->passwordComfirEdit->clear();
    cardNumber.clear();
    emit closeRegister();
}

void RegisterWidget::on_submitButton_clicked()
{
    QString name = ui->userRegisterEdit->text().trimmed();//获取注册用户名
    QString password = ui->passwordRegisterEdit->text();//获取输入密码
    QString comfirPwd = ui->passwordComfirEdit->text();//确认输入密码

    if(name.isEmpty()||password.isEmpty())
    {
        QMessageBox::critical(this,"错误","用户名或密码不能为空，请重新输入");
        return;
    }
    if(comfirPwd.isEmpty())
    {
        QMessageBox::critical(this,"错误","请输入确认密码");
        return;
    }
    if(comfirPwd!=password)
    {
        QMessageBox::critical(this,"错误","两次密码不一样，请确认密码");
        return;
    }

    MySql *db = MySql::getMySql();
    // adminCard
    if(cardNumber.isEmpty())
    {
        QMessageBox::critical(this,"错误","卡号为空，请录入卡号");
        return;
    }
    else
    {
        db->insertData(cardNumber, name, password);
    }
    QMessageBox::information(this,"成功","注册成功，即将跳转登陆界面");
    ui->userRegisterEdit->clear();
    ui->passwordRegisterEdit->clear();
    ui->passwordComfirEdit->clear();
    cardNumber.clear();
    emit closeRegister();
}

void RegisterWidget::on_cancelSubmitButton_clicked()
{
    ui->userRegisterEdit->clear();
    ui->passwordRegisterEdit->clear();
    ui->passwordComfirEdit->clear();
    cardNumber.clear();
}

void RegisterWidget::onCardReceived(const QString &cardNumber)
{
    if(!this->isVisible())
    {
        return;
    }
    this->cardNumber = cardNumber;
    QMessageBox::information(this,"提示",QString("卡号已录入:%1,请继续输入用户名和密码").arg(cardNumber));
}

void RegisterWidget::setSerial(QSerialPort *serial)
{
    m_serial = serial;
}
