#ifndef RECHARGEANDDEDUCTIONWIDGET_H
#define RECHARGEANDDEDUCTIONWIDGET_H

#include <QWidget>
#include "mysql.h"
#include "serialsetwidget.h"
//充值扣款类
namespace Ui {
class RechargeAndDeductionWidget;
}

class RechargeAndDeductionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RechargeAndDeductionWidget(QWidget *parent = nullptr);
    ~RechargeAndDeductionWidget();

    void setSerial(QSerialPort *serial);

public slots:
    void onCardReceived(const QString &cardNumber);  // 接收解析后的卡号
private slots:
    void on_confirmButton_clicked();

    void on_resetButton_clicked();

private:
    Ui::RechargeAndDeductionWidget *ui;
    QSqlTableModel *m_model;
    QSerialPort *m_serial;        // 全局串口指针
    QString m_cardNumber;
};

#endif // RECHARGEANDDEDUCTIONWIDGET_H
