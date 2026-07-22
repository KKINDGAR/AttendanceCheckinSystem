#ifndef USERMODIFYWIDGET_H
#define USERMODIFYWIDGET_H

#include <QWidget>
#include "mysql.h"
#include "serialsetwidget.h"
#include "userregisterwidget.h"
//用户信息修改类
namespace Ui {
class UserModifyWidget;
}

class UserModifyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UserModifyWidget(QWidget *parent = nullptr);
    ~UserModifyWidget();
    void setSerial(QSerialPort *serial);

private slots:
    void on_confirmModifyButton_clicked();//确认修改按钮槽函数

    void on_resetButton_clicked(); //重置linEdit按钮槽函数

    void on_deleteEmployeeButton_clicked(); //删除员工按钮槽函数

    void on_refrshUserTableButton_clicked();

public slots:
    void onCardReceived(const QString &cardNumber); //接收解析后的纯卡号

private:
    Ui::UserModifyWidget *ui;
    QSqlTableModel *m_model;
    QSerialPort *m_serial; // 全局串口指针
    MySql *db;
    QByteArray m_cardBuffer; //刷卡数据缓冲区
    QString m_cardNumber;
    UserRegisterWidget *newUser;
};

#endif // USERMODIFYWIDGET_H
