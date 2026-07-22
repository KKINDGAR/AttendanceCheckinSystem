#include "homepagewidget.h"
#include "ui_homepagewidget.h"
#include <QDebug>
#include <QDate>
#include <QSqlQuery>
#include <QMouseEvent>
#include <QEvent>
#include <QHeaderView>

HomePageWidget::HomePageWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomePageWidget)
{
    ui->setupUi(this);
    m_serial = nullptr;
    m_clockTimer = new QTimer(this);
    m_recentModel = new QSqlTableModel(this);
    //最近考勤表格
    setupRecentTable();

    //四张快捷卡片点击
    setupCardClicks();

    //1秒时钟
    connect(m_clockTimer, &QTimer::timeout, this, &HomePageWidget::onClockTick);
    m_clockTimer->start(1000);
}

HomePageWidget::~HomePageWidget()
{
    delete ui;
}

//外部接口
void HomePageWidget::setAdminCard(const QString &card)
{
    m_adminCard = card;

    MySql *db = MySql::getMySql();
    QString adminName;
    if(db->getAdminName(card, adminName))
    {
        ui->welcomeLabel->setText(
            QString("<html><head/><body><p>"
                    "<span style='font-size:14pt;'>您好，%1，欢迎使用考勤签到管理系统</span>"
                    "</p></body></html>").arg(adminName));
    }
}

void HomePageWidget::setSerialPort(QSerialPort *serial)
{
    m_serial = serial;
    updateSerialStatus();
}

void HomePageWidget::refreshAll()
{
    m_recentModel->setQuery(
        "SELECT card,name,date,checkInTime,checkOutTime,status "
        "FROM card ORDER BY date DESC, checkInTime DESC LIMIT 10");
    updateSystemInfo();
    updateSerialStatus();
}

//时钟槽
void HomePageWidget::onClockTick()
{
    // 每秒刷新系统信息
    updateSystemInfo();
    // 每秒检测串口状态
    updateSerialStatus();
}

//四张卡片点击
void HomePageWidget::setupCardClicks()
{
    // 给每个卡片 QFrame 安装事件过滤器，实现点击导航
    ui->uesrRegisterFrame->installEventFilter(this);
    ui->userModifyFrame->installEventFilter(this);
    ui->recordsFrame->installEventFilter(this);
    ui->recordsLookFrame->installEventFilter(this);
}

// eventFilter处理卡片点击导航
bool HomePageWidget::eventFilter(QObject *obj, QEvent *ev)
{
    if(ev->type() == QEvent::MouseButtonPress)
    {
        if(obj == ui->uesrRegisterFrame)       { emit navigateTo(1); return true; }
        if(obj == ui->userModifyFrame)         { emit navigateTo(2); return true; }
        if(obj == ui->recordsFrame)            { emit navigateTo(3); return true; }
        if(obj == ui->recordsLookFrame)        { emit navigateTo(4); return true; }
    }
    return QWidget::eventFilter(obj, ev);
}

//最近考勤表格
void HomePageWidget::setupRecentTable()
{
    m_recentModel->setQuery(
        "SELECT name,date,checkInTime,checkOutTime,status "
        "FROM card ORDER BY date DESC, checkInTime DESC LIMIT 10");

    m_recentModel->setHeaderData(0, Qt::Horizontal, "姓名");
    m_recentModel->setHeaderData(1, Qt::Horizontal, "日期");
    m_recentModel->setHeaderData(2, Qt::Horizontal, "签到时间");
    m_recentModel->setHeaderData(3, Qt::Horizontal, "签退时间");
    m_recentModel->setHeaderData(4, Qt::Horizontal, "状态");

    ui->recentRecordTableView->setModel(m_recentModel);
    ui->recentRecordTableView->horizontalHeader()->setStretchLastSection(true);
    ui->recentRecordTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

//系统信息
void HomePageWidget::updateSystemInfo()
{
    QSqlQuery q;

    // 当前日期
    ui->currentDateValueLabel->setText(QDate::currentDate().toString("yyyy-MM-dd"));

    // 员工总数
    if(q.exec("SELECT COUNT(*) FROM user") && q.next())
        ui->totalEmployeesValueLabel->setText(q.value(0).toString());

    // 今日签到数
    if(q.exec(QString("SELECT COUNT(*) FROM card WHERE date='%1'")
              .arg(QDate::currentDate().toString("yyyy-MM-dd"))) && q.next())
        ui->todayCheckinValueLabel->setText(q.value(0).toString());
}

//串口状态
void HomePageWidget::updateSerialStatus()
{
    if(m_serial && m_serial->isOpen())
    {
        ui->statusDotLabel->setStyleSheet(
            "QLabel{ border-radius:7px; background-color:#27AE60; }");
        ui->statusLabel->setStyleSheet(
            "QLabel{ border:none; font-weight:bold; font-size:15px; color:#27AE60; background:transparent; }");
        ui->statusLabel->setText("已连接");
    }
    else
    {
        ui->statusDotLabel->setStyleSheet(
            "QLabel{ border-radius:7px; background-color:#C0392B; }");
        ui->statusLabel->setStyleSheet(
            "QLabel{ border:none; font-weight:bold; font-size:15px; color:#C0392B; background:transparent; }");
        ui->statusLabel->setText("未连接");
    }
}
