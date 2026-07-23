#ifndef USERREGISTERWIDGET_H
#define USERREGISTERWIDGET_H

#include <QWidget>
#include <vector>
#include "mysql.h"
#include "serialsetwidget.h"
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
    static void playSound(const QString &file);

private slots:
    void on_resetButton_clicked(); //重置按钮
    void on_saveButton_clicked(); //保存按钮
    void on_cardReadyRead();//串口数据缓冲
    void on_refreshCardNummButton_clicked();//刷新卡号
    void on_clearCardNumButton_clicked();//清空卡号
    void on_refrshRegistTableButton_clicked();

public slots:
    void onCardReceived(const QString &cardNumber);

private:
    Ui::UserRegisterWidget *ui;
    void showEvent(QShowEvent *ev) override;
    void hideEvent(QHideEvent *ev) override;
    QSqlQueryModel *m_model;
    QSerialPort *m_serial;        // 全局串口指针
    MySql *db;
    QTimer *m_cardTimer;//刷卡超时定时器
    QByteArray m_cardBuffer; //刷卡数据缓冲区
    std::vector<float> m_faceFeature; //人脸特征向量
};

#endif // USERREGISTERWIDGET_H
