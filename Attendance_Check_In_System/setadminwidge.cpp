#include "setadminwidge.h"
#include "ui_setadminwidge.h"
#include "registerwidget.h"
#include "systemmanagementpanel.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QHeaderView>

SetAdminWidge::SetAdminWidge(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetAdminWidge),
    m_serial(nullptr),
    m_regis(nullptr),
    m_smp(nullptr),
    m_adminModel(new QSqlQueryModel(this))
{
    ui->setupUi(this);

    // 初始化管理员列表表格
    refreshAdminTable();
}

SetAdminWidge::~SetAdminWidge()
{
    delete ui;
}

void SetAdminWidge::setSerial(QSerialPort *serial)
{
    m_serial = serial;
}

void SetAdminWidge::setRegisterWidget(RegisterWidget *regis)
{
    m_regis = regis;
}

void SetAdminWidge::setSystemManagementPanel(SystemManagementPanel *smp)
{
    m_smp = smp;
}

// ========== 管理员注册 ==========
void SetAdminWidge::on_registerAdminButton_clicked()
{
    if (!m_regis) {
        QMessageBox::warning(this, "错误", "注册页面未初始化");
        return;
    }
    if (!m_smp) {
        QMessageBox::warning(this, "错误", "管理面板未初始化");
        return;
    }

    // 断开旧的 closeRegister 连接，设置新的返回目标为管理面板
    m_regis->disconnect(SIGNAL(closeRegister()), nullptr, nullptr);
    connect(m_regis, &RegisterWidget::closeRegister, this, [this](){
        m_regis->hide();
        m_smp->show();
        m_smp->raise();
        refreshAdminTable();  // 返回后刷新管理员列表
    });

    // 切换到注册页面
    m_smp->hide();
    m_regis->show();
}

// ========== 刷卡接收（串口转发） ==========
void SetAdminWidge::onCardReceived(const QString &cardNumber)
{
    if (!this->isVisible()) return;

    m_selectedCard = cardNumber;
    ui->adminCardEdit->setText(cardNumber);

    // 根据卡号反查用户名
    QSqlQuery q;
    q.prepare("SELECT name FROM admin WHERE adminCard = ?");
    q.addBindValue(cardNumber);
    if (q.exec() && q.next()) {
        ui->adminNameEdit->setText(q.value(0).toString());
    }

    // 清空密码字段
    ui->adminNewPwdEdit->clear();
    ui->adminConfirmPwdEdit->clear();
}

// ========== 点击表格行：填充修改表单 ==========
void SetAdminWidge::on_adminInfoTableView_clicked(const QModelIndex &index)
{
    int row = index.row();
    QString card = m_adminModel->record(row).value("管理员卡号").toString();
    QString name = m_adminModel->record(row).value("姓名").toString();

    m_selectedCard = card;
    ui->adminCardEdit->setText(card);
    ui->adminNameEdit->setText(name);
    ui->adminNewPwdEdit->clear();
    ui->adminConfirmPwdEdit->clear();
}

// ========== 刷新卡号按钮：通过串口刷卡填充 ==========
void SetAdminWidge::on_refreshCardButton_clicked()
{
    // 由 Widget 转发串口数据到本页面的 onCardReceived
    // 如果串口未连接则提示
    if (!m_serial || !m_serial->isOpen()) {
        QMessageBox::information(this, "提示", "串口未连接，请手动输入卡号或从表格选择");
    }
}

// ========== 保存管理员修改 ==========
void SetAdminWidge::on_saveModifyButton_clicked()
{
    QString card = ui->adminCardEdit->text().trimmed();
    QString name = ui->adminNameEdit->text().trimmed();
    QString newPwd = ui->adminNewPwdEdit->text();
    QString confirmPwd = ui->adminConfirmPwdEdit->text();

    // 验证
    if (card.isEmpty()) {
        QMessageBox::warning(this, "错误", "请先选择或输入管理员卡号");
        return;
    }
    if (name.isEmpty()) {
        QMessageBox::warning(this, "错误", "用户名不能为空");
        return;
    }

    // 检查卡号是否存在
    MySql *db = MySql::getMySql();
    QString existingName;
    if (!db->getAdminName(card, existingName)) {
        QMessageBox::warning(this, "错误", "卡号不存在，请检查后重试");
        return;
    }

    // 如果输入了新密码，验证一致性
    if (!newPwd.isEmpty()) {
        if (confirmPwd.isEmpty()) {
            QMessageBox::warning(this, "错误", "请输入确认密码");
            return;
        }
        if (newPwd != confirmPwd) {
            QMessageBox::warning(this, "错误", "两次密码输入不一致");
            return;
        }
    }

    // 更新用户名（直接执行 SQL）
    QSqlQuery q;
    q.prepare("UPDATE admin SET name = ? WHERE adminCard = ?");
    q.addBindValue(name);
    q.addBindValue(card);
    if (!q.exec()) {
        QMessageBox::critical(this, "错误", "用户名更新失败: " + q.lastError().text());
        return;
    }

    // 更新密码（如果输入了新密码）
    if (!newPwd.isEmpty()) {
        if (!db->updateAdminPwd(card, newPwd)) {
            QMessageBox::critical(this, "错误", "密码更新失败");
            return;
        }
    }

    QMessageBox::information(this, "成功", "管理员信息修改成功！");
    clearModifyForm();
    refreshAdminTable();
}

// ========== 重置修改表单 ==========
void SetAdminWidge::on_resetModifyButton_clicked()
{
    clearModifyForm();
}

void SetAdminWidge::clearModifyForm()
{
    m_selectedCard.clear();
    ui->adminCardEdit->clear();
    ui->adminNameEdit->clear();
    ui->adminNewPwdEdit->clear();
    ui->adminConfirmPwdEdit->clear();
}

// ========== 刷新管理员列表 ==========
void SetAdminWidge::refreshAdminTable()
{
    m_adminModel->setQuery("SELECT adminCard AS '管理员卡号', name AS '姓名' FROM admin");
    ui->adminInfoTableView->setModel(m_adminModel);
    ui->adminInfoTableView->horizontalHeader()->setStretchLastSection(true);
    ui->adminInfoTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // 更新管理员人数
    int count = m_adminModel->rowCount();
    ui->adminCountLabel->setText(QString("当前管理员人数：%1").arg(count));

    // 选中行变化 → 自动填充表单（使用信号连接，只在首次设置Model时连接一次）
    connect(ui->adminInfoTableView->selectionModel(), &QItemSelectionModel::currentRowChanged,
            this, [this](const QModelIndex &current, const QModelIndex &) {
        if (!current.isValid()) return;
        on_adminInfoTableView_clicked(current);
    }, Qt::UniqueConnection);
}
