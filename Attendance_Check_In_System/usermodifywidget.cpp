#include "usermodifywidget.h"
#include "ui_usermodifywidget.h"

UserModifyWidget::UserModifyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserModifyWidget)
{
    ui->setupUi(this);
    db = MySql::getMySql();//获取数据库
    m_model = new QSqlTableModel(this);

    //绑定员工表，实时查看修改信息
    m_model->setTable("user");
    m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_model->select();

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
    QString name;
    int age;
    QString sex;
    name = ui->nameEdit->text();
    age = ui->ageSpinBox->value();
    sex = ui->sexComboBox->currentText();
    QMessageBox::information(this,"提示","确认修改员工信息");
    if(m_cardNumber.isEmpty()||name.isEmpty())
    {
        QMessageBox::critical(this,"错误","存在空表单");
    }
    else
    {
        QMessageBox::information(this,"提示","修改成功");
    }
    db->updateUser(m_cardNumber,name,age,sex);
    m_model->select();
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
    }
    else {
            QMessageBox::information(this,"提示","确认删除该员工?");
            db->deleteUser(m_cardNumber);
    }

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
        ui->sexComboBox->setCurrentText(sex);
        ui->registerTimeEdit->setText(registerTime);
    }
}

void UserModifyWidget::on_refrshUserTableButton_clicked()
{
    m_model->select();
}
