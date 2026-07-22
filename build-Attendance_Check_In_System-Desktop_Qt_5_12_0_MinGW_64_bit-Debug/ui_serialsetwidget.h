/********************************************************************************
** Form generated from reading UI file 'serialsetwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALSETWIDGET_H
#define UI_SERIALSETWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SerialSetWidget
{
public:
    QGridLayout *gridLayout;
    QFrame *serialConfigFrame;
    QVBoxLayout *serialConfigVerticalLayout;
    QLabel *configTitleLabel;
    QGridLayout *serialConfigGridLayout;
    QLabel *portNameLabel;
    QComboBox *portNameComboBox;
    QPushButton *refreshPortButton;
    QPushButton *openButton;
    QPushButton *closeButton;
    QHBoxLayout *statusLayout;
    QComboBox *flowControlBox;
    QLabel *dataBitsLabel;
    QComboBox *dataBitsComboBox;
    QLabel *baudRateLabel;
    QComboBox *baudRateComboBox;
    QLabel *stopBitsLabel;
    QComboBox *stopBitsComboBox;
    QLabel *parityLabel;
    QComboBox *parityComboBox;
    QLabel *flowControlLabel;
    QFrame *serialTestFrame;
    QVBoxLayout *serialTestVerticalLayout;
    QLabel *testTitleLabel;
    QHBoxLayout *sendHorizontalLayout;
    QLabel *sendDataLabel;
    QLineEdit *sendDataEdit;
    QPushButton *sendButton;
    QHBoxLayout *receiveLabelLayout;
    QLabel *receiveDataLabel;
    QSpacerItem *receiveLabelHorizontalSpacer;
    QTextEdit *receiveTextEdit;
    QHBoxLayout *clearReceiveLayout;
    QSpacerItem *clearReceiveHorizontalSpacer;
    QPushButton *clearReceiveButton;

    void setupUi(QWidget *SerialSetWidget)
    {
        if (SerialSetWidget->objectName().isEmpty())
            SerialSetWidget->setObjectName(QString::fromUtf8("SerialSetWidget"));
        SerialSetWidget->resize(874, 737);
        SerialSetWidget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    font-family: \"Microsoft YaHei\", \"\345\276\256\350\275\257\351\233\205\351\273\221\", \"PingFang SC\", sans-serif;\n"
"    font-size: 14px;\n"
"    color: #2D3748;\n"
"}\n"
"QWidget#SerialSetWidget{\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        gridLayout = new QGridLayout(SerialSetWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        serialConfigFrame = new QFrame(SerialSetWidget);
        serialConfigFrame->setObjectName(QString::fromUtf8("serialConfigFrame"));
        serialConfigFrame->setMinimumSize(QSize(0, 280));
        serialConfigFrame->setMaximumSize(QSize(16777215, 280));
        serialConfigFrame->setStyleSheet(QString::fromUtf8("QFrame#serialConfigFrame{\n"
"    background:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 16px;\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        serialConfigFrame->setFrameShape(QFrame::StyledPanel);
        serialConfigFrame->setFrameShadow(QFrame::Raised);
        serialConfigVerticalLayout = new QVBoxLayout(serialConfigFrame);
        serialConfigVerticalLayout->setSpacing(10);
        serialConfigVerticalLayout->setObjectName(QString::fromUtf8("serialConfigVerticalLayout"));
        serialConfigVerticalLayout->setContentsMargins(30, 20, 30, 20);
        configTitleLabel = new QLabel(serialConfigFrame);
        configTitleLabel->setObjectName(QString::fromUtf8("configTitleLabel"));
        configTitleLabel->setMinimumSize(QSize(0, 30));
        configTitleLabel->setMaximumSize(QSize(16777215, 30));
        configTitleLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));

        serialConfigVerticalLayout->addWidget(configTitleLabel);

        serialConfigGridLayout = new QGridLayout();
        serialConfigGridLayout->setSpacing(20);
        serialConfigGridLayout->setObjectName(QString::fromUtf8("serialConfigGridLayout"));
        portNameLabel = new QLabel(serialConfigFrame);
        portNameLabel->setObjectName(QString::fromUtf8("portNameLabel"));
        portNameLabel->setMinimumSize(QSize(80, 36));
        portNameLabel->setMaximumSize(QSize(80, 36));
        portNameLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));

        serialConfigGridLayout->addWidget(portNameLabel, 0, 0, 1, 1);

        portNameComboBox = new QComboBox(serialConfigFrame);
        portNameComboBox->setObjectName(QString::fromUtf8("portNameComboBox"));
        portNameComboBox->setMinimumSize(QSize(180, 36));
        portNameComboBox->setMaximumSize(QSize(200, 36));
        portNameComboBox->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 8px;\n"
"    padding: 6px 12px;\n"
"    font-size: 14px;\n"
"    color: rgb(0, 0, 0);\n"
"}\n"
"QComboBox:focus{\n"
"    border: 1px solid #348aff;\n"
"}\n"
"QComboBox::drop-down{\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 24px;\n"
"    border-left: 1px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-right-radius: 8px;\n"
"}"));

        serialConfigGridLayout->addWidget(portNameComboBox, 0, 1, 1, 1);

        refreshPortButton = new QPushButton(serialConfigFrame);
        refreshPortButton->setObjectName(QString::fromUtf8("refreshPortButton"));
        refreshPortButton->setMinimumSize(QSize(180, 36));
        refreshPortButton->setMaximumSize(QSize(180, 36));
        refreshPortButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.248927 rgba(85, 116, 143, 217), stop:1 rgba(255, 255, 255, 255));\n"
"	color: rgb(74, 85, 104);\n"
"	border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"	border-radius: 6px;\n"
"	font-size: 14px;\n"
"	font: 63 9pt \"Bahnschrift SemiBold SemiConden\";\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    color: #1A3A6B;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"	color: #1A3A6B;\n"
"    font-weight: bold;\n"
"}"));

        serialConfigGridLayout->addWidget(refreshPortButton, 0, 2, 1, 1);

        openButton = new QPushButton(serialConfigFrame);
        openButton->setObjectName(QString::fromUtf8("openButton"));
        openButton->setMinimumSize(QSize(180, 36));
        openButton->setMaximumSize(QSize(200, 36));
        openButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.248927 rgba(85, 116, 143, 217), stop:1 rgba(255, 255, 255, 255));\n"
"	color: rgb(74, 85, 104);\n"
"	border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"	border-radius: 6px;\n"
"	font-size: 14px;\n"
"	font: 63 9pt \"Bahnschrift SemiBold SemiConden\";\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    color: #1A3A6B;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"	color: #1A3A6B;\n"
"    font-weight: bold;\n"
"}"));

        serialConfigGridLayout->addWidget(openButton, 1, 2, 1, 1);

        closeButton = new QPushButton(serialConfigFrame);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setMinimumSize(QSize(180, 36));
        closeButton->setMaximumSize(QSize(200, 36));
        closeButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.248927 rgba(85, 116, 143, 217), stop:1 rgba(255, 255, 255, 255));\n"
"	color: rgb(74, 85, 104);\n"
"	border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"	border-radius: 6px;\n"
"	font-size: 14px;\n"
"	font: 63 9pt \"Bahnschrift SemiBold SemiConden\";\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    color: #1A3A6B;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"	color: #1A3A6B;\n"
"    font-weight: bold;\n"
"}"));

        serialConfigGridLayout->addWidget(closeButton, 2, 2, 1, 1);

        statusLayout = new QHBoxLayout();
        statusLayout->setSpacing(15);
        statusLayout->setObjectName(QString::fromUtf8("statusLayout"));
        flowControlBox = new QComboBox(serialConfigFrame);
        flowControlBox->addItem(QString());
        flowControlBox->setObjectName(QString::fromUtf8("flowControlBox"));
        flowControlBox->setMinimumSize(QSize(180, 36));
        flowControlBox->setMaximumSize(QSize(200, 36));
        flowControlBox->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 8px;\n"
"    padding: 6px 12px;\n"
"    font-size: 14px;\n"
"    color: rgb(0, 0, 0);\n"
"}\n"
"QComboBox:focus{\n"
"    border: 1px solid #348aff;\n"
"}\n"
"QComboBox::drop-down{\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 24px;\n"
"    border-left: 1px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-right-radius: 8px;\n"
"}"));

        statusLayout->addWidget(flowControlBox);


        serialConfigGridLayout->addLayout(statusLayout, 2, 4, 1, 1);

        dataBitsLabel = new QLabel(serialConfigFrame);
        dataBitsLabel->setObjectName(QString::fromUtf8("dataBitsLabel"));
        dataBitsLabel->setMinimumSize(QSize(80, 36));
        dataBitsLabel->setMaximumSize(QSize(80, 36));
        dataBitsLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));

        serialConfigGridLayout->addWidget(dataBitsLabel, 2, 0, 1, 1);

        dataBitsComboBox = new QComboBox(serialConfigFrame);
        dataBitsComboBox->addItem(QString());
        dataBitsComboBox->addItem(QString());
        dataBitsComboBox->addItem(QString());
        dataBitsComboBox->addItem(QString());
        dataBitsComboBox->setObjectName(QString::fromUtf8("dataBitsComboBox"));
        dataBitsComboBox->setMinimumSize(QSize(180, 36));
        dataBitsComboBox->setMaximumSize(QSize(200, 36));
        dataBitsComboBox->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 8px;\n"
"    padding: 6px 12px;\n"
"    font-size: 14px;\n"
"    color: rgb(0, 0, 0);\n"
"}\n"
"QComboBox:focus{\n"
"    border: 1px solid #348aff;\n"
"}\n"
"QComboBox::drop-down{\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 24px;\n"
"    border-left: 1px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-right-radius: 8px;\n"
"}"));

        serialConfigGridLayout->addWidget(dataBitsComboBox, 2, 1, 1, 1);

        baudRateLabel = new QLabel(serialConfigFrame);
        baudRateLabel->setObjectName(QString::fromUtf8("baudRateLabel"));
        baudRateLabel->setMinimumSize(QSize(80, 36));
        baudRateLabel->setMaximumSize(QSize(80, 36));
        baudRateLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));

        serialConfigGridLayout->addWidget(baudRateLabel, 1, 0, 1, 1);

        baudRateComboBox = new QComboBox(serialConfigFrame);
        baudRateComboBox->addItem(QString());
        baudRateComboBox->addItem(QString());
        baudRateComboBox->addItem(QString());
        baudRateComboBox->setObjectName(QString::fromUtf8("baudRateComboBox"));
        baudRateComboBox->setMinimumSize(QSize(180, 36));
        baudRateComboBox->setMaximumSize(QSize(200, 36));
        baudRateComboBox->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 8px;\n"
"    padding: 6px 12px;\n"
"    font-size: 14px;\n"
"    color: rgb(0, 0, 0);\n"
"}\n"
"QComboBox:focus{\n"
"    border: 1px solid #348aff;\n"
"}\n"
"QComboBox::drop-down{\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 24px;\n"
"    border-left: 1px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-right-radius: 8px;\n"
"}"));

        serialConfigGridLayout->addWidget(baudRateComboBox, 1, 1, 1, 1);

        stopBitsLabel = new QLabel(serialConfigFrame);
        stopBitsLabel->setObjectName(QString::fromUtf8("stopBitsLabel"));
        stopBitsLabel->setMinimumSize(QSize(80, 36));
        stopBitsLabel->setMaximumSize(QSize(80, 36));
        stopBitsLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));

        serialConfigGridLayout->addWidget(stopBitsLabel, 0, 3, 1, 1);

        stopBitsComboBox = new QComboBox(serialConfigFrame);
        stopBitsComboBox->addItem(QString());
        stopBitsComboBox->addItem(QString());
        stopBitsComboBox->addItem(QString());
        stopBitsComboBox->setObjectName(QString::fromUtf8("stopBitsComboBox"));
        stopBitsComboBox->setMinimumSize(QSize(180, 36));
        stopBitsComboBox->setMaximumSize(QSize(200, 36));
        stopBitsComboBox->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 8px;\n"
"    padding: 6px 12px;\n"
"    font-size: 14px;\n"
"    color: rgb(0, 0, 0);\n"
"}\n"
"QComboBox:focus{\n"
"    border: 1px solid #348aff;\n"
"}\n"
"QComboBox::drop-down{\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 24px;\n"
"    border-left: 1px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-right-radius: 8px;\n"
"}"));

        serialConfigGridLayout->addWidget(stopBitsComboBox, 0, 4, 1, 1);

        parityLabel = new QLabel(serialConfigFrame);
        parityLabel->setObjectName(QString::fromUtf8("parityLabel"));
        parityLabel->setMinimumSize(QSize(80, 36));
        parityLabel->setMaximumSize(QSize(80, 36));
        parityLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));

        serialConfigGridLayout->addWidget(parityLabel, 1, 3, 1, 1);

        parityComboBox = new QComboBox(serialConfigFrame);
        parityComboBox->addItem(QString());
        parityComboBox->setObjectName(QString::fromUtf8("parityComboBox"));
        parityComboBox->setMinimumSize(QSize(180, 36));
        parityComboBox->setMaximumSize(QSize(200, 36));
        parityComboBox->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 8px;\n"
"    padding: 6px 12px;\n"
"    font-size: 14px;\n"
"    color: rgb(0, 0, 0);\n"
"}\n"
"QComboBox:focus{\n"
"    border: 1px solid #348aff;\n"
"}\n"
"QComboBox::drop-down{\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 24px;\n"
"    border-left: 1px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-right-radius: 8px;\n"
"}"));

        serialConfigGridLayout->addWidget(parityComboBox, 1, 4, 1, 1);

        flowControlLabel = new QLabel(serialConfigFrame);
        flowControlLabel->setObjectName(QString::fromUtf8("flowControlLabel"));
        flowControlLabel->setMinimumSize(QSize(80, 36));
        flowControlLabel->setMaximumSize(QSize(80, 36));
        flowControlLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));

        serialConfigGridLayout->addWidget(flowControlLabel, 2, 3, 1, 1);


        serialConfigVerticalLayout->addLayout(serialConfigGridLayout);


        gridLayout->addWidget(serialConfigFrame, 0, 0, 1, 1);

        serialTestFrame = new QFrame(SerialSetWidget);
        serialTestFrame->setObjectName(QString::fromUtf8("serialTestFrame"));
        serialTestFrame->setStyleSheet(QString::fromUtf8("QFrame#serialTestFrame{\n"
"    background:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 16px;\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        serialTestFrame->setFrameShape(QFrame::StyledPanel);
        serialTestFrame->setFrameShadow(QFrame::Raised);
        serialTestVerticalLayout = new QVBoxLayout(serialTestFrame);
        serialTestVerticalLayout->setSpacing(10);
        serialTestVerticalLayout->setObjectName(QString::fromUtf8("serialTestVerticalLayout"));
        serialTestVerticalLayout->setContentsMargins(30, 20, 30, 20);
        testTitleLabel = new QLabel(serialTestFrame);
        testTitleLabel->setObjectName(QString::fromUtf8("testTitleLabel"));
        testTitleLabel->setMinimumSize(QSize(0, 30));
        testTitleLabel->setMaximumSize(QSize(16777215, 30));
        testTitleLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));

        serialTestVerticalLayout->addWidget(testTitleLabel);

        sendHorizontalLayout = new QHBoxLayout();
        sendHorizontalLayout->setSpacing(15);
        sendHorizontalLayout->setObjectName(QString::fromUtf8("sendHorizontalLayout"));
        sendDataLabel = new QLabel(serialTestFrame);
        sendDataLabel->setObjectName(QString::fromUtf8("sendDataLabel"));
        sendDataLabel->setMinimumSize(QSize(80, 36));
        sendDataLabel->setMaximumSize(QSize(80, 36));
        sendDataLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));

        sendHorizontalLayout->addWidget(sendDataLabel);

        sendDataEdit = new QLineEdit(serialTestFrame);
        sendDataEdit->setObjectName(QString::fromUtf8("sendDataEdit"));
        sendDataEdit->setMinimumSize(QSize(0, 36));
        sendDataEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 8px;\n"
"    padding: 8px 12px;\n"
"    font-size: 14px;\n"
"    color: rgb(0, 0, 0);\n"
"}\n"
"QLineEdit:focus{\n"
"    border: 1px solid #348aff;\n"
"}\n"
"QLineEdit::placeholder{\n"
"    color: #888888;\n"
"}"));

        sendHorizontalLayout->addWidget(sendDataEdit);

        sendButton = new QPushButton(serialTestFrame);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setMinimumSize(QSize(80, 36));
        sendButton->setMaximumSize(QSize(100, 36));
        sendButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.248927 rgba(85, 116, 143, 217), stop:1 rgba(255, 255, 255, 255));\n"
"	color: rgb(74, 85, 104);\n"
"	border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"	border-radius: 6px;\n"
"	font-size: 14px;\n"
"	font: 63 9pt \"Bahnschrift SemiBold SemiConden\";\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    color: #1A3A6B;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"	color: #1A3A6B;\n"
"    font-weight: bold;\n"
"}"));

        sendHorizontalLayout->addWidget(sendButton);


        serialTestVerticalLayout->addLayout(sendHorizontalLayout);

        receiveLabelLayout = new QHBoxLayout();
        receiveLabelLayout->setSpacing(15);
        receiveLabelLayout->setObjectName(QString::fromUtf8("receiveLabelLayout"));
        receiveDataLabel = new QLabel(serialTestFrame);
        receiveDataLabel->setObjectName(QString::fromUtf8("receiveDataLabel"));
        receiveDataLabel->setMinimumSize(QSize(80, 30));
        receiveDataLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));

        receiveLabelLayout->addWidget(receiveDataLabel);

        receiveLabelHorizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        receiveLabelLayout->addItem(receiveLabelHorizontalSpacer);


        serialTestVerticalLayout->addLayout(receiveLabelLayout);

        receiveTextEdit = new QTextEdit(serialTestFrame);
        receiveTextEdit->setObjectName(QString::fromUtf8("receiveTextEdit"));
        receiveTextEdit->setMinimumSize(QSize(0, 200));
        receiveTextEdit->setStyleSheet(QString::fromUtf8("QTextEdit{\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 10px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"    color: rgb(0, 0, 0);\n"
"}"));
        receiveTextEdit->setReadOnly(true);

        serialTestVerticalLayout->addWidget(receiveTextEdit);

        clearReceiveLayout = new QHBoxLayout();
        clearReceiveLayout->setObjectName(QString::fromUtf8("clearReceiveLayout"));
        clearReceiveHorizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        clearReceiveLayout->addItem(clearReceiveHorizontalSpacer);

        clearReceiveButton = new QPushButton(serialTestFrame);
        clearReceiveButton->setObjectName(QString::fromUtf8("clearReceiveButton"));
        clearReceiveButton->setMinimumSize(QSize(100, 36));
        clearReceiveButton->setMaximumSize(QSize(140, 36));
        clearReceiveButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.248927 rgba(85, 116, 143, 217), stop:1 rgba(255, 255, 255, 255));\n"
"	color: rgb(74, 85, 104);\n"
"	border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"	border-radius: 6px;\n"
"	font-size: 14px;\n"
"	font: 63 9pt \"Bahnschrift SemiBold SemiConden\";\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    color: #1A3A6B;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"	color: #1A3A6B;\n"
"    font-weight: bold;\n"
"}"));

        clearReceiveLayout->addWidget(clearReceiveButton);


        serialTestVerticalLayout->addLayout(clearReceiveLayout);


        gridLayout->addWidget(serialTestFrame, 1, 0, 1, 1);


        retranslateUi(SerialSetWidget);

        QMetaObject::connectSlotsByName(SerialSetWidget);
    } // setupUi

    void retranslateUi(QWidget *SerialSetWidget)
    {
        SerialSetWidget->setWindowTitle(QApplication::translate("SerialSetWidget", "Form", nullptr));
        configTitleLabel->setText(QApplication::translate("SerialSetWidget", "<html><head/><body><p><span style=\" font-size:12pt;\">\344\270\262\345\217\243\345\217\202\346\225\260\350\256\276\347\275\256</span></p></body></html>", nullptr));
        portNameLabel->setText(QApplication::translate("SerialSetWidget", "\344\270\262\345\217\243\345\217\267", nullptr));
        refreshPortButton->setText(QApplication::translate("SerialSetWidget", "\345\210\267\346\226\260\344\270\262\345\217\243", nullptr));
        openButton->setText(QApplication::translate("SerialSetWidget", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        closeButton->setText(QApplication::translate("SerialSetWidget", "\346\226\255\345\274\200\344\270\262\345\217\243", nullptr));
        flowControlBox->setItemText(0, QApplication::translate("SerialSetWidget", "None", nullptr));

        dataBitsLabel->setText(QApplication::translate("SerialSetWidget", "\346\225\260\346\215\256\344\275\215", nullptr));
        dataBitsComboBox->setItemText(0, QApplication::translate("SerialSetWidget", "8", nullptr));
        dataBitsComboBox->setItemText(1, QApplication::translate("SerialSetWidget", "7", nullptr));
        dataBitsComboBox->setItemText(2, QApplication::translate("SerialSetWidget", "6", nullptr));
        dataBitsComboBox->setItemText(3, QApplication::translate("SerialSetWidget", "5", nullptr));

        baudRateLabel->setText(QApplication::translate("SerialSetWidget", "\346\263\242\347\211\271\347\216\207", nullptr));
        baudRateComboBox->setItemText(0, QApplication::translate("SerialSetWidget", "115200", nullptr));
        baudRateComboBox->setItemText(1, QApplication::translate("SerialSetWidget", "9600", nullptr));
        baudRateComboBox->setItemText(2, QApplication::translate("SerialSetWidget", "4800", nullptr));

        stopBitsLabel->setText(QApplication::translate("SerialSetWidget", "\345\201\234\346\255\242\344\275\215", nullptr));
        stopBitsComboBox->setItemText(0, QApplication::translate("SerialSetWidget", "1", nullptr));
        stopBitsComboBox->setItemText(1, QApplication::translate("SerialSetWidget", "1.5", nullptr));
        stopBitsComboBox->setItemText(2, QApplication::translate("SerialSetWidget", "2", nullptr));

        parityLabel->setText(QApplication::translate("SerialSetWidget", "\346\240\241\351\252\214\344\275\215", nullptr));
        parityComboBox->setItemText(0, QApplication::translate("SerialSetWidget", "None", nullptr));

        flowControlLabel->setText(QApplication::translate("SerialSetWidget", "\346\265\201\346\216\247\345\210\266", nullptr));
        testTitleLabel->setText(QApplication::translate("SerialSetWidget", "<html><head/><body><p><span style=\" font-size:12pt;\">\344\270\262\345\217\243\346\224\266\345\217\221</span></p></body></html>", nullptr));
        sendDataLabel->setText(QApplication::translate("SerialSetWidget", "\345\217\221\351\200\201\346\225\260\346\215\256", nullptr));
        sendDataEdit->setPlaceholderText(QApplication::translate("SerialSetWidget", "\350\276\223\345\205\245\350\246\201\345\217\221\351\200\201\347\232\204\346\225\260\346\215\256", nullptr));
        sendButton->setText(QApplication::translate("SerialSetWidget", "\345\217\221\351\200\201", nullptr));
        receiveDataLabel->setText(QApplication::translate("SerialSetWidget", "\346\216\245\346\224\266\346\225\260\346\215\256", nullptr));
        receiveTextEdit->setPlaceholderText(QApplication::translate("SerialSetWidget", "\346\216\245\346\224\266\345\210\260\347\232\204\346\225\260\346\215\256\345\260\206\346\230\276\347\244\272\345\234\250\346\255\244\345\214\272\345\237\237...", nullptr));
        clearReceiveButton->setText(QApplication::translate("SerialSetWidget", "\346\270\205\347\251\272\346\216\245\346\224\266\345\214\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SerialSetWidget: public Ui_SerialSetWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALSETWIDGET_H
