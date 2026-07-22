#ifndef ATTENDANCERECORDSWIDGET_H
#define ATTENDANCERECORDSWIDGET_H

#include <QWidget>
#include "mysql.h"
#include "serialsetwidget.h"
//考勤查询类
namespace Ui {
class AttendanceRecordsWidget;
}

class AttendanceRecordsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AttendanceRecordsWidget(QWidget *parent = nullptr);
    ~AttendanceRecordsWidget();

    void setSerial(QSerialPort *serial);

public slots:
    void onCardReceived(const QString &cardNumber);  // 接收解析后的卡号
private slots:
    void on_searchButton_clicked();

    void on_resetSearchButton_clicked();

    void on_exportButton_clicked();

private:
    Ui::AttendanceRecordsWidget *ui;
    QSqlQueryModel *m_model;
    QSerialPort *m_serial;        // 全局串口指针
    QString m_cardNumber;
};

#endif // ATTENDANCERECORDSWIDGET_H
