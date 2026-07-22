#include "attendancerecordswidget.h"
#include "ui_attendancerecordswidget.h"
#include <QFileDialog>
AttendanceRecordsWidget::AttendanceRecordsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AttendanceRecordsWidget)
{
    ui->setupUi(this);
    m_model = new QSqlTableModel(this);

//        m_model->setTable("user");
//        m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
//        m_model->select();


    m_model->setQuery(
            "SELECT card,name,date,checkInTime,checkOutTime,status "
            "FROM card ORDER BY date DESC");
    // 表头中文
    m_model->setHeaderData(0, Qt::Horizontal, "卡号");
    m_model->setHeaderData(1, Qt::Horizontal, "姓名");
    m_model->setHeaderData(2, Qt::Horizontal, "时间");
    m_model->setHeaderData(3, Qt::Horizontal, "签到时间");
    m_model->setHeaderData(4, Qt::Horizontal, "签退时间");
    m_model->setHeaderData(5, Qt::Horizontal, "打卡状态");

    //表格外观
    ui->attendanceTableView->setModel(m_model);
    ui->attendanceTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->attendanceTableView->setAlternatingRowColors(true);
    ui->attendanceTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->attendanceTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

AttendanceRecordsWidget::~AttendanceRecordsWidget()
{
    delete ui;
}

void AttendanceRecordsWidget::setSerial(QSerialPort *serial)
{
    m_serial = serial;
}

void AttendanceRecordsWidget::onCardReceived(const QString &cardNumber)
{
    if(!this->isVisible())
    {
        return;
    }
    m_cardNumber = cardNumber;
    ui->searchCardEdit->setText(cardNumber);
}

void AttendanceRecordsWidget::on_searchButton_clicked()
{
    QString card = ui->searchCardEdit->text().trimmed();
    QString name = ui->searchNameEdit->text().trimmed();

    bool hasCard = !card.isEmpty();
    bool hasName = !name.isEmpty();

    // 三种查询方式：通过卡号,通过姓名查询,通过卡号+姓名;都为空则查全部
    QString whereClause;
    QSqlQuery query;

    if (hasCard && hasName) {
        // 卡号 + 姓名查询
        whereClause = " WHERE card = :card AND name LIKE :name";
        query.prepare("SELECT card,name,date,checkInTime,checkOutTime,status "
                      "FROM card" + whereClause + " ORDER BY date DESC");
        query.bindValue(":card", card);
        query.bindValue(":name", QString("%%1%").arg(name));
    } else if (hasCard) {
        // 只通过卡号查询
        whereClause = " WHERE card = :card";
        query.prepare("SELECT card,name,date,checkInTime,checkOutTime,status "
                      "FROM card" + whereClause + " ORDER BY date DESC");
        query.bindValue(":card", card);
    } else if (hasName) {
        //只通过姓名查询
        whereClause = " WHERE name LIKE :name";
        query.prepare("SELECT card,name,date,checkInTime,checkOutTime,status "
                      "FROM card" + whereClause + " ORDER BY date DESC");
        query.bindValue(":name", QString("%%1%").arg(name));
    } else {
        // 都为空：查询全部
        query.prepare("SELECT card,name,date,checkInTime,checkOutTime,status "
                      "FROM card ORDER BY date DESC");
    }

    query.exec();
    m_model->setQuery(query);

    //统计查询结果
    QSqlQuery countQuery;
    if (hasCard && hasName) {
        countQuery.prepare("SELECT status, COUNT(*) AS cnt FROM card WHERE card = :card AND name LIKE :name GROUP BY status");
        countQuery.bindValue(":card", card);
        countQuery.bindValue(":name", QString("%%1%").arg(name));
    } else if (hasCard) {
        countQuery.prepare("SELECT status, COUNT(*) AS cnt FROM card WHERE card = :card GROUP BY status");
        countQuery.bindValue(":card", card);
    } else if (hasName) {
        countQuery.prepare("SELECT status, COUNT(*) AS cnt FROM card WHERE name LIKE :name GROUP BY status");
        countQuery.bindValue(":name", QString("%%1%").arg(name));
    } else {
        countQuery.prepare("SELECT status, COUNT(*) FROM card GROUP BY status");
    }

    int total = 0, normal = 0, late = 0, absent = 0;
    if (countQuery.exec()) {
        while (countQuery.next()) {
            QString status = countQuery.value(0).toString();
            int cnt = countQuery.value(1).toInt();
            total += cnt;
            if (status == "正常")       normal += cnt;
            else if (status == "迟到")  late   += cnt;
            else if (status == "早退")  absent += cnt;
            else if (status == "缺勤")  absent += cnt;
        }
    }
    ui->totalRecordsLabel->setText(QString("总记录: %1 条").arg(total));
    ui->normalRecordsLabel->setText(QString("正常: %1").arg(normal));
    ui->lateRecordsLabel->setText(QString("迟到: %1").arg(late));
    ui->absentRecordsLabel->setText(QString("缺勤: %1").arg(absent));
}



void AttendanceRecordsWidget::on_resetSearchButton_clicked()
{
    // 清空输入
    ui->searchCardEdit->clear();
    ui->searchNameEdit->clear();
    ui->startDateEdit->setDate(QDate::currentDate());
    ui->endDateEdit->setDate(QDate::currentDate());

    // 恢复整个考勤记录表
    m_model->setQuery(
        "SELECT card,name,date,checkInTime,checkOutTime,status "
        "FROM card ORDER BY date DESC");

    // 统计全部
    QSqlQuery q;
    int total = 0, normal = 0, late = 0, absent = 0;
    if (q.exec("SELECT status, COUNT(*) FROM card GROUP BY status")) {
        while (q.next()) {
            QString status = q.value(0).toString();
            int cnt = q.value(1).toInt();
            total += cnt;
            if (status == "正常")       normal += cnt;
            else if (status == "迟到")  late   += cnt;
            else if (status == "早退")  absent += cnt;
            else if (status == "缺勤")  absent += cnt;
        }
    }
    ui->totalRecordsLabel->setText(QString("总记录: %1 条").arg(total));
    ui->normalRecordsLabel->setText(QString("正常: %1").arg(normal));
    ui->lateRecordsLabel->setText(QString("迟到: %1").arg(late));
    ui->absentRecordsLabel->setText(QString("缺勤: %1").arg(absent));
}


void AttendanceRecordsWidget::on_exportButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(
        this, "导出考勤表", QString("考勤记录_%1.csv")
            .arg(QDate::currentDate().toString("yyyyMMdd")),
        "CSV 文件 (*.csv)");

    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "导出失败", "无法创建文件");
        return;
    }

    QTextStream out(&file);
    // BOM 头，确保 Excel 正确识别中文
    out.setCodec("UTF-8");
    out << "\xEF\xBB\xBF";

    // 写表头
    out << "卡号,姓名,日期,签到时间,签退时间,状态\n";

    // 写数据行（导出当前表格中显示的数据）
    for (int row = 0; row < m_model->rowCount(); ++row) {
        QStringList cols;
        for (int col = 0; col < m_model->columnCount(); ++col) {
            QString val = m_model->data(m_model->index(row, col)).toString();
            // CSV 转义：含逗号或引号的字段用双引号包裹
            if (val.contains(',') || val.contains('"')) {
                val.replace("\"", "\"\"");
                val = "\"" + val + "\"";
            }
            cols.append(val);
        }
        out << cols.join(",") << "\n";
    }

    file.close();
    QMessageBox::information(this, "导出成功",
        QString("已导出 %1 条记录").arg(m_model->rowCount()));
}

