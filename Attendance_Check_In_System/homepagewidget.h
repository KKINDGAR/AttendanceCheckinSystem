#ifndef HOMEPAGEWIDGET_H
#define HOMEPAGEWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QSqlQueryModel>
#include <QSerialPort>
#include "mysql.h"

namespace Ui {
class HomePageWidget;
}

class HomePageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HomePageWidget(QWidget *parent = nullptr);
    ~HomePageWidget();

    // 设置登录管理员卡号(由父窗口构造后调用)
    void setAdminCard(const QString &card);
    // 设置串口指针(由父窗口传入，用于状态显示)
    void setSerialPort(QSerialPort *serial);
    // 刷新首页全部数据
    void refreshAll();

signals:
    // 导航信号：0=首页 1=员工注册 2=员工修改 3=考勤查询 4=充值扣款 5=串口设置
    void navigateTo(int pageIndex);

private slots:
    void onClockTick();          // 时钟刷新

private:
    bool eventFilter(QObject *obj, QEvent *ev) override;  // 处理卡片点击
    void setupCardClicks();      // 给四张卡片绑定点击事件
    void setupRecentTable();     // 初始化最近考勤表格
    void updateSystemInfo();     // 刷新系统信息
    void updateSerialStatus();   // 刷新串口状态

    Ui::HomePageWidget *ui;

    QString    m_adminCard;       // 当前登录管理员卡号
    QSerialPort *m_serial;        // 全局串口指针
    QTimer     *m_clockTimer;     // 1秒定时器
    QSqlQueryModel *m_recentModel;// 最近考勤数据模型
};

#endif // HOMEPAGEWIDGET_H
