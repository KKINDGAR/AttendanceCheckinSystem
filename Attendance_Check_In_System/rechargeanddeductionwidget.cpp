#include "rechargeanddeductionwidget.h"
#include "ui_rechargeanddeductionwidget.h"

RechargeAndDeductionWidget::RechargeAndDeductionWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RechargeAndDeductionWidget)
{
    ui->setupUi(this);
    m_model = new QSqlTableModel(this);

        m_model->setTable("records");
        m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        m_model->select();

        ui->transactionTableView->setModel(m_model);
        //隐藏序号列
        ui->transactionTableView->hideColumn(0);

        // 表头中文,对应数据库充值/扣款表
        m_model->setHeaderData(1, Qt::Horizontal, "卡号");
        m_model->setHeaderData(2, Qt::Horizontal, "姓名");
        m_model->setHeaderData(3, Qt::Horizontal, "充值/扣款");
        m_model->setHeaderData(4, Qt::Horizontal, "交易金额");
        m_model->setHeaderData(5, Qt::Horizontal, "卡内余额");
        m_model->setHeaderData(6, Qt::Horizontal, "备注");

        //表格外观
        ui->transactionTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->transactionTableView->setAlternatingRowColors(true);
        ui->transactionTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->transactionTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

RechargeAndDeductionWidget::~RechargeAndDeductionWidget()
{
    delete ui;
}

void RechargeAndDeductionWidget::setSerial(QSerialPort *serial)
{
    m_serial = serial;
}

void RechargeAndDeductionWidget::onCardReceived(const QString &cardNumber)
{
    if(!this->isVisible())
    {
        return;
    }
    MySql *db = MySql::getMySql();
    QString name;
    double balance;
    if(db->getUserNameAndBalanceByCard(cardNumber,name,balance))
    {
        ui->nameEdit->setText(name);
        ui->balanceEdit->setText(QString::number(balance,'f',2));
    }
    m_cardNumber = cardNumber;
    ui->cardNumEdit->setText(cardNumber);
}

void RechargeAndDeductionWidget::on_confirmButton_clicked()
{
    MySql *db = MySql::getMySql();
    QString cardNumber = ui->cardNumEdit->text().trimmed();

    if (cardNumber.isEmpty()) {
        QMessageBox::warning(this, "提示", "请先刷卡或手动输入卡号");
        return;
    }

    // 获取员工姓名和当前余额
    QString name;
    double balance;
    if (!db->getUserNameAndBalanceByCard(cardNumber, name, balance)) {
        QMessageBox::warning(this, "提示", "卡号不存在，请检查输入");
        return;
    }

    double amount = ui->amountSpinBox->value();
    if (amount <= 0) {
        QMessageBox::warning(this, "提示", "请输入有效金额");
        return;
    }

    if (ui->rechargeRadioButton->isChecked()) {
        // 充值：新增一条交易记录
        double newBalance = balance + amount;
        if (db->updateUserBalance(cardNumber, newBalance)) {
            db->addTransaction(cardNumber, name, "充值", amount, newBalance, ui->remarkEdit->text());
            ui->balanceEdit->setText(QString::number(newBalance, 'f', 2));
            // 充值成功音效
            QMediaPlayer *sound = new QMediaPlayer;
            //初始化Qfile对象，用于后续打开音频文件，并设置父对象为sound
            QFile *audioFile = new QFile(":/image/recharge_success.wav", sound);
            //打开音频
            if (audioFile->open(QIODevice::ReadOnly)) {
                sound->setMedia(QMediaContent(), audioFile);
                sound->setVolume(80);
                // 媒体加载完成后自动播放
                connect(sound, &QMediaPlayer::mediaStatusChanged, [sound](QMediaPlayer::MediaStatus status) {
                    if (status == QMediaPlayer::LoadedMedia) {
                        sound->play();
                    }
                });
                // 播放结束后释放内存
                connect(sound, &QMediaPlayer::stateChanged, [sound](QMediaPlayer::State state) {
                    if (state == QMediaPlayer::StoppedState) {
                        sound->deleteLater();
                    }
                });
            } else {
                qDebug() << "充值音效: 无法打开音频文件";
                delete sound;
            }
            QMessageBox::information(this, "成功",
                QString("充值成功！\n卡号：%1\n姓名：%2\n金额：+%3\n余额：%4")
                    .arg(cardNumber, name)
                    .arg(amount)
                    .arg(newBalance, 0, 'f', 2));
        }
    } else if (ui->deductionRadioButton->isChecked()) {
        // 扣款：余额不足则拒绝，否则新增一条交易记录
        if (balance < amount) {
            QMessageBox::critical(this, "错误", "余额不足，无法扣款");
            return;
        }
        double newBalance = balance - amount;
        if (db->updateUserBalance(cardNumber, newBalance)) {
            db->addTransaction(cardNumber, name, "扣款", amount, newBalance, ui->remarkEdit->text());
            ui->balanceEdit->setText(QString::number(newBalance, 'f', 2));
            // 扣款成功音效
            QMediaPlayer *sound = new QMediaPlayer;
            //初始化Qfile对象，用于后续打开音频文件，并设置父对象为sound
            QFile *audioFile = new QFile(":/image/deduct_success.wav", sound);
            //打开音频
            if (audioFile->open(QIODevice::ReadOnly)) {
                sound->setMedia(QMediaContent(), audioFile);
                sound->setVolume(80);
                // 媒体加载完成后自动播放
                connect(sound, &QMediaPlayer::mediaStatusChanged, [sound](QMediaPlayer::MediaStatus status) {
                    if (status == QMediaPlayer::LoadedMedia) {
                        sound->play();
                    }
                });
                // 播放结束后释放内存
                connect(sound, &QMediaPlayer::stateChanged, [sound](QMediaPlayer::State state) {
                    if (state == QMediaPlayer::StoppedState) {
                        sound->deleteLater();
                    }
                });
            } else {
                qDebug() << "充值音效: 无法打开音频文件";
                delete sound;
            }
            QMessageBox::information(this, "成功",
                QString("扣款成功！\n卡号：%1\n姓名：%2\n金额：-%3\n余额：%4")
                    .arg(cardNumber, name)
                    .arg(amount)
                    .arg(newBalance, 0, 'f', 2));
        }
    } else {
        QMessageBox::warning(this, "提示", "请选择充值或扣款");
        return;
    }

    // 刷新交易记录表格,addTransaction 记录会显示为新行
    m_model->select();
    ui->amountSpinBox->setValue(0.0);
}

void RechargeAndDeductionWidget::on_resetButton_clicked()
{
    ui->cardNumEdit->clear();
    ui->nameEdit->clear();
    ui->balanceEdit->clear();
    ui->amountSpinBox->clear();
    ui->remarkEdit->clear();
    m_model->select();
}
