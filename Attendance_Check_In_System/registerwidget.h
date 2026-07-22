#ifndef REGISTERWIDGET_H
#define REGISTERWIDGET_H

#include <QWidget>
#include "mysql.h"
#include "serialsetwidget.h"
//登录类
namespace Ui {
class RegisterWidget;
}

class RegisterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterWidget(QWidget *parent = nullptr);
    ~RegisterWidget();

    void setSerial(QSerialPort *serial);

private slots:
    void on_backLoginButton_clicked();
    void on_submitButton_clicked();

    void on_cancelSubmitButton_clicked();
public slots:
    void onCardReceived(const QString &cardNumber);
signals:
    void closeRegister();

private:
    Ui::RegisterWidget *ui;
    QSerialPort *m_serial;        // 全局串口指针
    QString cardNumber;
};

#endif // REGISTERWIDGET_H
