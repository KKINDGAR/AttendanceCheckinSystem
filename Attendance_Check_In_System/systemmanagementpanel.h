#ifndef SYSTEMMANAGEMENTPANEL_H
#define SYSTEMMANAGEMENTPANEL_H

#include <QWidget>
#include "mysql.h"
#include "userregisterwidget.h"
#include "serialsetwidget.h"
#include "usermodifywidget.h"
#include "attendancerecordswidget.h"
#include "rechargeanddeductionwidget.h"
//管理员控制面板类
namespace Ui {
class SystemManagementPanel;
}

class SystemManagementPanel : public QWidget
{
    Q_OBJECT

public:
    explicit SystemManagementPanel(QWidget *parent = nullptr);
    ~SystemManagementPanel();

    void setSerial(QSerialPort *serial);
    void setAdminCard(const QString &card);         // 登录成功后设置管理员姓名
    UserRegisterWidget* getUserRegisterPage();     // 获取员工注册页指针(供Widget转发cardParsed)
    SerialSetWidget* getSerialWidget();            // 获取串口设置页指针(供Widget转发rawSerialData)
    UserModifyWidget* getUserModifyPage();         // 获取员工注册页面指针(供Widget转发cardParsedToModify)
    AttendanceRecordsWidget* getAttendancePage();  // 获取考勤查询页面指针(供widget转发cardParsedAttendance)
    RechargeAndDeductionWidget* getRechargePage(); // 获取充值扣款页面指针(供widget转发cardParsedRecharge)
private slots:
    void on_navHomeButton_clicked();

    void on_navRegisterButton_clicked();

    void on_navModifyButton_clicked();

    void on_navRecordsButton_clicked();

    void on_navSerialButton_clicked();

    void on_rachargeButton_clicked();

    void on_navLogoutButton_clicked();

    void onClockTick();  // 时钟刷新
public slots:
    void ondataReceived(const QString &cardNumber);  // 接收Widget转发的解析后串口数据
signals:
    void backToAttendance();
private:
    Ui::SystemManagementPanel *ui;
    QTimer *m_clockTimer;    // 时钟定时器
    QSerialPort *m_serial;   // 全局串口指针
    QString m_cardNumber;    //卡号成员

    void updateSerialStatus();  //更新串口状态
};

#endif // SYSTEMMANAGEMENTPANEL_H
