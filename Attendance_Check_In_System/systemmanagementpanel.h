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

private:
    Ui::SystemManagementPanel *ui;
    QSerialPort *m_serial;   // 全局串口指针
};

#endif // SYSTEMMANAGEMENTPANEL_H
