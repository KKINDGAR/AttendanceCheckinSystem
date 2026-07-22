#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QSerialPort>
#include <QSqlQueryModel>
#include <QSettings>
#include "mysql.h"
#include "registerwidget.h"
#include "systemmanagementpanel.h"
#include "loginadminwidget.h"
#include "userregisterwidget.h"
#include "usermodifywidget.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void onClockTick();                         // 时钟刷新
    void onCardScanned(const QString &card);    // 刷卡处理
    void on_adminEntryButton_clicked();         // 管理员入口
    void onSerialReadyRead();                   // 串口数据接收+解析
    void onCardTimeout();                       // 刷卡超时:解析缓冲区内容

signals:
    void cardParsed(const QString &cardNumber);             // 解析后的纯净卡号：发给注册页
    void rawSerialData(const QString &rawText);             // 原始串口数据：发给串口页显示
    void cardParsedToModify(const QString &cardNumber);     //解析后的纯净卡号：发给修改页
    void cardParseAttendance(const QString &cardNumber);    //解析后的纯净卡号：发给考勤查询页
    void cardParseRecharge(const QString &cardNumber);      //解析后的纯净卡号：发给充值扣款页
    void cardParseRegistPage(const QString &cardNumber);    //解析后的纯净卡号：发给管理员注册页
    void cardParseLoginPage(const QString &cardNumber);     //解析后的纯净卡号：发给管理员登录页面
private:
    void setupRecentRecords();              // 初始化最近打卡表格
    void refreshRecentRecords();            // 刷新最近打卡数据
    void tryAutoOpenSerial();               // 启动时读取QSettings自动打开串口
    void updateSerialStatus(bool isOpen);   // 更新打卡区串口状态提示
    void doCheckIn(const QString &card, const QString &name);  // 签到方法
    void doCheckOut(const QString &card, const QString &name); // 签退方法

    Ui::Widget *ui;
    QTimer *m_clockTimer;            // 时钟定时器
    QSerialPort *m_sharedSerial;     // 全局唯一串口
    QSqlQueryModel *m_recentModel;   // 最近打卡数据

    RegisterWidget *m_regis;        //注册页指针，跳转注册页
    SystemManagementPanel *m_smp;   //登录页指针，跳转登录页
    LoginAdminWidget *m_loginAdmin; //控制面板页指针，分发串口

    QByteArray m_cardBuffer;     // 卡号数据缓冲区
    QTimer *m_cardTimeout;       // 刷卡超时定时器
    QString m_lastCard;          // 上次刷卡卡号(去重用)
    QTime m_lastCardTime;        // 上次刷卡时间(去重用)
};

#endif // WIDGET_H
