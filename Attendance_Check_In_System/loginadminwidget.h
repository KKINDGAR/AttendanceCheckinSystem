#ifndef LOGINADMINWIDGET_H
#define LOGINADMINWIDGET_H

#include <QWidget>
#include <QSerialPort>
#include "mysql.h"
#include "systemmanagementpanel.h"

namespace Ui {
class LoginAdminWidget;
}

class LoginAdminWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginAdminWidget(QWidget *parent = nullptr);
    ~LoginAdminWidget();

    void setSerialPort(QSerialPort *serial);        //获取串口数据
    void setSMP(SystemManagementPanel *smp);        //切换管理员控制面板界面

signals:
    void backToCheckIn();  // 返回打卡界面

public slots:
    void onCardReceived(const QString &cardNumber);  // 接收解析后的卡号
private slots:
    void on_loginButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::LoginAdminWidget *ui;
    QSerialPort *m_serial;
    SystemManagementPanel *m_smp;
    QString m_cardNumber;
};

#endif // LOGINADMINWIDGET_H
