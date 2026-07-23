#include "serialsetwidget.h"
#include "ui_serialsetwidget.h"
#include "QDebug"
SerialSetWidget::SerialSetWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SerialSetWidget)
{
    ui->setupUi(this);

    //搜索所有可用的串口
    QStringList serialNamePort;
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        serialNamePort<<info.portName();
    }
    ui->portNameComboBox->addItems(serialNamePort);
}

SerialSetWidget::~SerialSetWidget()
{
    delete ui;
}
SerialSetWidget * SerialSetWidget::serial =nullptr;
SerialSetWidget * SerialSetWidget::getSerail(void)
{
    if(!serial)
    {
        serial = new SerialSetWidget();
    }
    return serial;
}

void SerialSetWidget::on_openButton_clicked()
{
    QSerialPort::BaudRate baudRate;//定义一个波特率
    QSerialPort::DataBits dataBits;//定义一个数据位
    QSerialPort::StopBits stopBits;//定义一个停止位
    QSerialPort::Parity parity;//定义一个校验位
    QSerialPort::FlowControl flowControl;//定义一个停止位

    //设置波特率
    if(ui->baudRateComboBox->currentText()=="4800"){
        baudRate = QSerialPort::Baud4800;
    }else if(ui->baudRateComboBox->currentText()=="9600"){
        baudRate = QSerialPort::Baud9600;
    }else if(ui->baudRateComboBox->currentText()=="115200"){
        baudRate = QSerialPort::Baud115200;
    }
    //设置数据位
    if(ui->dataBitsComboBox->currentText()=="5"){
        dataBits = QSerialPort::Data5;
    }else if (ui->dataBitsComboBox->currentText()=="6"){
        dataBits = QSerialPort::Data6;
    }else if (ui->dataBitsComboBox->currentText()=="7"){
        dataBits = QSerialPort::Data7;
    }else if (ui->dataBitsComboBox->currentText()=="8"){
        dataBits = QSerialPort::Data8;
    }
    //设置停止位
    if(ui->stopBitsComboBox->currentText()==tr("1")){
        stopBits = QSerialPort::OneStop;
    }else if (ui->stopBitsComboBox->currentText()==tr("1.5")){
        stopBits = QSerialPort::OneAndHalfStop;
    }else if (ui->stopBitsComboBox->currentText()==tr("2")){
        stopBits = QSerialPort::TwoStop;
    }
    //设置校验位
    if(ui->parityComboBox->currentText()==tr("None")){
        parity = QSerialPort::NoParity;
    }

    //设置流控制
    if(ui->flowControlBox->currentText()==tr("None"))
    {
        flowControl = QSerialPort::NoFlowControl;
    }
    //设置选择的串口
    serialPort->setPortName(ui->portNameComboBox->currentText());
    serialPort->setBaudRate(baudRate);
    serialPort->setDataBits(dataBits);
    serialPort->setStopBits(stopBits);
    serialPort->setParity(parity);
    serialPort->setFlowControl(flowControl);

    if(serialPort->open(QIODevice::ReadWrite) == true){
        QMessageBox::information(this,"成功","打开串口成功");

        // 保存配置到 QSettings，供下次程序启动时自动打开串口
        QSettings settings("AttendanceSystem", "SerialConfig");
        settings.setValue("port",     ui->portNameComboBox->currentText());
        settings.setValue("baud",     static_cast<int>(serialPort->baudRate()));
        settings.setValue("dataBits", static_cast<int>(serialPort->dataBits()));
        settings.setValue("stopBits", ui->stopBitsComboBox->currentText());
        settings.setValue("parity",   ui->parityComboBox->currentText());
        settings.setValue("flow",     ui->flowControlBox->currentText());
    }else {
        QMessageBox::critical(this,"失败","打开串口失败");
    }
}

void SerialSetWidget::on_closeButton_clicked()
{
    serialPort->close();
//    if(serialPort->open(QIODevice::ReadWrite) == false){
//        QMessageBox::information(this,"成功","关闭成功");
//    }else {
//        QMessageBox::critical(this,"失败","关闭失败");
//    }
}

void SerialSetWidget::on_sendButton_clicked()
{
    serialPort->write(ui->sendDataEdit->text().toUtf8().data());
}

void SerialSetWidget::on_refreshPortButton_clicked()
{
    // 重新扫描系统可用串口列表
    ui->portNameComboBox->clear();
    QStringList portList;
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        portList << info.portName();
    }
    ui->portNameComboBox->addItems(portList);
}

void SerialSetWidget::on_clearReceiveButton_clicked()
{
    ui->receiveTextEdit->clear();
}

void SerialSetWidget::onRawDataReceived(const QString &rawData)
{
    ui->receiveTextEdit->append(rawData);
}

void SerialSetWidget::setSerial(QSerialPort *serial)
{
    serialPort = serial;
    //接收串口信息
    connect(serialPort,&QSerialPort::readyRead,this,[=](){
        QString buffer;
        buffer = QString(serialPort->readAll());
        ui->receiveTextEdit->append(buffer);
    });
}
