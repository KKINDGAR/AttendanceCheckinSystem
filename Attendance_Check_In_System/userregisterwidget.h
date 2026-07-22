#ifndef USERREGISTERWIDGET_H
#define USERREGISTERWIDGET_H

#include <QWidget>
#include "mysql.h"
#include "serialsetwidget.h"
//用户信息注册类
namespace Ui {
class UserRegisterWidget;
}

class UserRegisterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UserRegisterWidget(QWidget *parent = nullptr);
    ~UserRegisterWidget();

    void setSerialPort(QSerialPort *serial);
    void setSerial(QSerialPort *serial);

private slots:
    void on_resetButton_clicked(); //重置按钮
    void on_saveButton_clicked(); //保存按钮
    void on_cardReadyRead();//串口数据缓冲

    void on_refreshCardNummButton_clicked();//刷新卡号

    void on_clearCardNumButton_clicked();//清空卡号
signals:

public slots:
    void onCardReceived(const QString &cardNumber);  // 接收解析后的卡号

signals:


private:
    Ui::UserRegisterWidget *ui;
    QSqlTableModel *m_model;
    QSerialPort *m_serial;        // 全局串口指针
    MySql *db;
    QTimer *m_cardTimer;//刷卡超时定时器
    QByteArray m_cardBuffer; //刷卡数据缓冲区
};

#endif // USERREGISTERWIDGET_H
