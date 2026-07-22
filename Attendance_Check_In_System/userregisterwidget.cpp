#include "userregisterwidget.h"
#include "ui_userregisterwidget.h"
#include <QDate>
#include <QTime>
#include <QMessageBox>
UserRegisterWidget::UserRegisterWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserRegisterWidget)
{
    ui->setupUi(this);
    db = MySql::getMySql();
    m_cardTimer = new QTimer(this);
    m_model = new QSqlTableModel(this);
    //绑定数据库user表
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
        QString name;
        int age;
        QString sex;
        QString registerTime;
        QString cardId;
        cardId = ui->cardNumLineEdit->text().trimmed();
        name = ui->nameEdit->text().trimmed();
        age = ui->ageSpinBox->value();
        sex = ui->sexComboBox->currentText();
        registerTime = toDay.toString("yyyy-MM-dd").append(" ").append(now.toString("HH:mm:ss"));
        //判断是否有空
        if(cardId.isEmpty()||name.isEmpty())
        {
            QMessageBox::critical(this,"注册失败","卡号或姓名为空");
            return;
        }
        //卡号去重
        if(db->userExists(cardId))
        {
            QMessageBox::critical(this,"注册失败","检测到重复卡号");
            return;
        }
        if(db->insertUser(cardId,name,age,sex,registerTime))
        {
            QMessageBox::information(this,"成功","注册成功");
            //刷新表格
            m_model->select();
            // 清空所有的输入框
            ui->cardNumLineEdit->clear();
            ui->nameEdit->clear();
            ui->ageSpinBox->setValue(0);
            ui->sexComboBox->setCurrentIndex(0);
            //更新注册人数
            ui->label->setText(QString("当前注册人数：%1").arg(m_model->rowCount()));
        }
        else {
            QMessageBox::critical(this,"失败","注册失败,请重试");
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

void UserRegisterWidget::onCardReceived(const QString &cardNumber)
{
    if(!this->isVisible())
    {
        return;
    }
    ui->cardNumLineEdit->setText(cardNumber);
    m_cardTimer->start(300);//每次有新的数据就更新计时器
}
