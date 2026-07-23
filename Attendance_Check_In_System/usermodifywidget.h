#ifndef USERMODIFYWIDGET_H
#define USERMODIFYWIDGET_H

#include <QWidget>
#include <vector>
#include "mysql.h"
#include "serialsetwidget.h"
#include "userregisterwidget.h"

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
    static void playSound(const QString &file);

private slots:
    void on_confirmModifyButton_clicked();//确认修改按钮槽函数
    void on_resetButton_clicked(); //重置linEdit按钮槽函数
    void on_deleteEmployeeButton_clicked(); //删除员工按钮槽函数
    void on_refrshUserTableButton_clicked();
    void on_captureFaceBtn_clicked();  // 人脸补录

public slots:
    void onCardReceived(const QString &cardNumber);

private:
    Ui::UserModifyWidget *ui;
    void showEvent(QShowEvent *ev) override;
    void hideEvent(QHideEvent *ev) override;
    QSqlQueryModel *m_model; // 员工表模型
    QSerialPort *m_serial;
    MySql *db;
    QByteArray m_cardBuffer;
    QString m_cardNumber;
    UserRegisterWidget *newUser;
};

#endif // USERMODIFYWIDGET_H
