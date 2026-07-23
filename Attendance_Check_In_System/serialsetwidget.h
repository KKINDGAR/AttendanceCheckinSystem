#ifndef SERIALSETWIDGET_H
#define SERIALSETWIDGET_H

#include <QWidget>
#include "mysql.h"
#include <QtSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QSettings>
//串口设置页面类
namespace Ui {
class SerialSetWidget;
}

class SerialSetWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SerialSetWidget(QWidget *parent = nullptr);
    ~SerialSetWidget();

    static SerialSetWidget * getSerail(void);

    void setSerial(QSerialPort *serial);

public slots:
    void onRawDataReceived(const QString &rawData);  // 接收Widget转发的原始串口数据

private slots:
    void on_openButton_clicked();

    void on_closeButton_clicked();

    void on_sendButton_clicked();

    void on_refreshPortButton_clicked();

    void on_clearReceiveButton_clicked();

private:
    Ui::SerialSetWidget *ui;
    static SerialSetWidget *serial;
    QSerialPort *serialPort = nullptr;
};

#endif // SERIALSETWIDGET_H
