#ifndef SETADMINWIDGE_H
#define SETADMINWIDGE_H

#include <QWidget>
#include <QSerialPort>
#include <QSqlQueryModel>
#include "mysql.h"

class RegisterWidget;
class SystemManagementPanel;

namespace Ui {
class SetAdminWidge;
}

class SetAdminWidge : public QWidget
{
    Q_OBJECT

public:
    explicit SetAdminWidge(QWidget *parent = nullptr);
    ~SetAdminWidge();

    void setSerial(QSerialPort *serial);
    void setRegisterWidget(RegisterWidget *regis);
    void setSystemManagementPanel(SystemManagementPanel *smp);
    void refreshAdminTable();        // 刷新管理员列表

public slots:
    void onCardReceived(const QString &cardNumber);  // 接收刷卡数据（串口转发）

private slots:
    void on_registerAdminButton_clicked();   // 跳转管理员注册
    void on_saveModifyButton_clicked();      // 保存管理员信息修改
    void on_resetModifyButton_clicked();     // 重置修改表单
    void on_refreshCardButton_clicked();     // 刷新卡号（串口刷卡）
    void on_adminInfoTableView_clicked(const QModelIndex &index); // 点击表格行填充表单

private:
    Ui::SetAdminWidge *ui;
    QSerialPort *m_serial;
    RegisterWidget *m_regis;
    SystemManagementPanel *m_smp;
    QSqlQueryModel *m_adminModel;
    QString m_selectedCard;  // 当前选中的管理员卡号（用于修改操作）

    void clearModifyForm();  // 清空修改表单
};

#endif // SETADMINWIDGE_H
