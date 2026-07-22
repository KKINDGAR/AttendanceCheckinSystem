/********************************************************************************
** Form generated from reading UI file 'systemmanagementpanel.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMMANAGEMENTPANEL_H
#define UI_SYSTEMMANAGEMENTPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "attendancerecordswidget.h"
#include "homepagewidget.h"
#include "rechargeanddeductionwidget.h"
#include "serialsetwidget.h"
#include "usermodifywidget.h"
#include "userregisterwidget.h"

QT_BEGIN_NAMESPACE

class Ui_SystemManagementPanel
{
public:
    QGridLayout *gridLayout;
    QFrame *navTopFrame;
    QLabel *serailTextLabel;
    QLabel *managerIconLabel;
    QLabel *serilIconlabel;
    QLabel *localTimeLabel;
    QLabel *managerLabel;
    QLabel *managerTitleLabel;
    QLabel *managerNameLabel;
    QFrame *navFrame;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *navFrameVerticalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *navHomeLabel;
    QPushButton *navHomeButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *navRegisterLabel;
    QPushButton *navRegisterButton;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *navModifyLabel;
    QPushButton *navModifyButton;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *navRecordsLabel;
    QPushButton *navRecordsButton;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *navSerialLabel_2;
    QPushButton *rachargeButton;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *navSerialLabel;
    QPushButton *navSerialButton;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *navLogoutLabel;
    QPushButton *navLogoutButton;
    QStackedWidget *stackedWidget;
    HomePageWidget *homePage;
    UserRegisterWidget *userRegisterPage;
    UserModifyWidget *userModifyPage;
    AttendanceRecordsWidget *atendencePage;
    RechargeAndDeductionWidget *rechargeDeductionPage;
    SerialSetWidget *serailSetPage;

    void setupUi(QWidget *SystemManagementPanel)
    {
        if (SystemManagementPanel->objectName().isEmpty())
            SystemManagementPanel->setObjectName(QString::fromUtf8("SystemManagementPanel"));
        SystemManagementPanel->resize(1636, 937);
        SystemManagementPanel->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    font-family: \"Microsoft YaHei\", \"\345\276\256\350\275\257\351\233\205\351\273\221\", \"PingFang SC\", sans-serif;\n"
"    font-size: 14px;\n"
"    color: #2D3748;\n"
"}\n"
"QWidget#SystemManagementPanel {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        gridLayout = new QGridLayout(SystemManagementPanel);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        navTopFrame = new QFrame(SystemManagementPanel);
        navTopFrame->setObjectName(QString::fromUtf8("navTopFrame"));
        navTopFrame->setMinimumSize(QSize(0, 71));
        navTopFrame->setMaximumSize(QSize(16777215, 71));
        navTopFrame->setStyleSheet(QString::fromUtf8("QFrame{\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border: none;\n"
"    border-bottom: 1px solid #E8ECF2;\n"
"}"));
        navTopFrame->setFrameShape(QFrame::StyledPanel);
        navTopFrame->setFrameShadow(QFrame::Raised);
        serailTextLabel = new QLabel(navTopFrame);
        serailTextLabel->setObjectName(QString::fromUtf8("serailTextLabel"));
        serailTextLabel->setGeometry(QRect(1450, 20, 151, 31));
        serailTextLabel->setMinimumSize(QSize(151, 31));
        serailTextLabel->setMaximumSize(QSize(151, 31));
        serailTextLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    font-size: 15px;\n"
"    color: rgb(0, 0, 0);\n"
"    qproperty-alignment: AlignCenter;\n"
"	font-weight: bold;\n"
"	background:transparent;\n"
"}\n"
""));
        managerIconLabel = new QLabel(navTopFrame);
        managerIconLabel->setObjectName(QString::fromUtf8("managerIconLabel"));
        managerIconLabel->setGeometry(QRect(1, 1, 71, 69));
        managerIconLabel->setMinimumSize(QSize(71, 0));
        managerIconLabel->setMaximumSize(QSize(71, 16777215));
        managerIconLabel->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border:none;\n"
"	background:transparent;\n"
"}"));
        managerIconLabel->setPixmap(QPixmap(QString::fromUtf8(":/image/manager.png")));
        managerIconLabel->setScaledContents(true);
        serilIconlabel = new QLabel(navTopFrame);
        serilIconlabel->setObjectName(QString::fromUtf8("serilIconlabel"));
        serilIconlabel->setGeometry(QRect(1410, 20, 30, 30));
        serilIconlabel->setMinimumSize(QSize(30, 30));
        serilIconlabel->setMaximumSize(QSize(30, 30));
        serilIconlabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border-radius: 15px;\n"
"}"));
        serilIconlabel->setPixmap(QPixmap(QString::fromUtf8(":/image/Serail1.png")));
        serilIconlabel->setScaledContents(true);
        localTimeLabel = new QLabel(navTopFrame);
        localTimeLabel->setObjectName(QString::fromUtf8("localTimeLabel"));
        localTimeLabel->setGeometry(QRect(1011, 1, 128, 69));
        localTimeLabel->setMinimumSize(QSize(128, 41));
        localTimeLabel->setMaximumSize(QSize(128, 128));
        localTimeLabel->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	background:transparent;\n"
"}"));
        managerLabel = new QLabel(navTopFrame);
        managerLabel->setObjectName(QString::fromUtf8("managerLabel"));
        managerLabel->setGeometry(QRect(522, 15, 88, 41));
        managerLabel->setMinimumSize(QSize(0, 41));
        managerLabel->setMaximumSize(QSize(16777215, 41));
        managerLabel->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border:none;\n"
"	font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    qproperty-alignment: AlignCenter;\n"
"	background:transparent;\n"
"}"));
        managerTitleLabel = new QLabel(navTopFrame);
        managerTitleLabel->setObjectName(QString::fromUtf8("managerTitleLabel"));
        managerTitleLabel->setGeometry(QRect(90, 0, 160, 71));
        managerTitleLabel->setMinimumSize(QSize(0, 71));
        managerTitleLabel->setMaximumSize(QSize(16777215, 71));
        managerTitleLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border:none;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    qproperty-alignment: AlignCenter;\n"
"	background:transparent;\n"
"}"));
        managerNameLabel = new QLabel(navTopFrame);
        managerNameLabel->setObjectName(QString::fromUtf8("managerNameLabel"));
        managerNameLabel->setGeometry(QRect(619, 15, 110, 41));
        managerNameLabel->setMinimumSize(QSize(0, 41));
        managerNameLabel->setMaximumSize(QSize(16777215, 41));
        managerNameLabel->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border:none;\n"
"	font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    qproperty-alignment: AlignCenter;\n"
"	background:transparent;\n"
"}"));

        gridLayout->addWidget(navTopFrame, 0, 0, 1, 2);

        navFrame = new QFrame(SystemManagementPanel);
        navFrame->setObjectName(QString::fromUtf8("navFrame"));
        navFrame->setMinimumSize(QSize(300, 0));
        navFrame->setMaximumSize(QSize(300, 16777215));
        navFrame->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border: none;\n"
"}"));
        navFrame->setFrameShape(QFrame::StyledPanel);
        navFrame->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget = new QWidget(navFrame);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 301, 831));
        navFrameVerticalLayout = new QVBoxLayout(verticalLayoutWidget);
        navFrameVerticalLayout->setObjectName(QString::fromUtf8("navFrameVerticalLayout"));
        navFrameVerticalLayout->setContentsMargins(10, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        navHomeLabel = new QLabel(verticalLayoutWidget);
        navHomeLabel->setObjectName(QString::fromUtf8("navHomeLabel"));
        navHomeLabel->setMinimumSize(QSize(44, 41));
        navHomeLabel->setMaximumSize(QSize(48, 48));
        navHomeLabel->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	background:transparent;\n"
"}"));
        navHomeLabel->setPixmap(QPixmap(QString::fromUtf8(":/image/home.png")));
        navHomeLabel->setScaledContents(true);

        horizontalLayout->addWidget(navHomeLabel);

        navHomeButton = new QPushButton(verticalLayoutWidget);
        navHomeButton->setObjectName(QString::fromUtf8("navHomeButton"));
        navHomeButton->setMinimumSize(QSize(44, 41));
        navHomeButton->setMaximumSize(QSize(16777215, 48));
        navHomeButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background: transparent;\n"
"	color: rgb(74, 85, 104);\n"
"	border: none;\n"
"	border-radius: 6px;\n"
"	font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    color: #1A3A6B;\n"
"}\n"
"QPushButton:checked {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    color: #1A3A6B;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        navHomeButton->setCheckable(true);
        navHomeButton->setAutoExclusive(true);

        horizontalLayout->addWidget(navHomeButton);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        navRegisterLabel = new QLabel(verticalLayoutWidget);
        navRegisterLabel->setObjectName(QString::fromUtf8("navRegisterLabel"));
        navRegisterLabel->setMinimumSize(QSize(44, 44));
        navRegisterLabel->setMaximumSize(QSize(48, 48));
        navRegisterLabel->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	background:transparent;\n"
"}"));
        navRegisterLabel->setPixmap(QPixmap(QString::fromUtf8(":/image/userModify.png")));
        navRegisterLabel->setScaledContents(true);

        horizontalLayout_3->addWidget(navRegisterLabel);

        navRegisterButton = new QPushButton(verticalLayoutWidget);
        navRegisterButton->setObjectName(QString::fromUtf8("navRegisterButton"));
        navRegisterButton->setMinimumSize(QSize(0, 44));
        navRegisterButton->setMaximumSize(QSize(16777215, 48));
        navRegisterButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background: transparent;\n"
"	color: rgb(74, 85, 104);\n"
"	border: none;\n"
"	border-radius: 6px;\n"
"	font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    color: #1A3A6B;\n"
"}\n"
"QPushButton:checked {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    color: #1A3A6B;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        navRegisterButton->setCheckable(true);
        navRegisterButton->setAutoExclusive(true);

        horizontalLayout_3->addWidget(navRegisterButton);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        navModifyLabel = new QLabel(verticalLayoutWidget);
        navModifyLabel->setObjectName(QString::fromUtf8("navModifyLabel"));
        navModifyLabel->setMinimumSize(QSize(44, 44));
        navModifyLabel->setMaximumSize(QSize(48, 48));
        navModifyLabel->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	background:transparent;\n"
"}"));
        navModifyLabel->setPixmap(QPixmap(QString::fromUtf8(":/image/changeUser.png")));
        navModifyLabel->setScaledContents(true);

        horizontalLayout_2->addWidget(navModifyLabel);

        navModifyButton = new QPushButton(verticalLayoutWidget);
        navModifyButton->setObjectName(QString::fromUtf8("navModifyButton"));
        navModifyButton->setMinimumSize(QSize(0, 44));
        navModifyButton->setMaximumSize(QSize(16777215, 48));
        navModifyButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background: transparent;\n"
"	color: rgb(74, 85, 104);\n"
"	border: none;\n"
"	border-radius: 6px;\n"
"	font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    color: #1A3A6B;\n"
"}\n"
"QPushButton:checked {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    color: #1A3A6B;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        navModifyButton->setCheckable(true);
        navModifyButton->setAutoExclusive(true);

        horizontalLayout_2->addWidget(navModifyButton);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        navRecordsLabel = new QLabel(verticalLayoutWidget);
        navRecordsLabel->setObjectName(QString::fromUtf8("navRecordsLabel"));
        navRecordsLabel->setMinimumSize(QSize(44, 44));
        navRecordsLabel->setMaximumSize(QSize(48, 48));
        navRecordsLabel->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	background:transparent;\n"
"}"));
        navRecordsLabel->setPixmap(QPixmap(QString::fromUtf8(":/image/Records.png")));
        navRecordsLabel->setScaledContents(true);

        horizontalLayout_4->addWidget(navRecordsLabel);

        navRecordsButton = new QPushButton(verticalLayoutWidget);
        navRecordsButton->setObjectName(QString::fromUtf8("navRecordsButton"));
        navRecordsButton->setMinimumSize(QSize(0, 44));
        navRecordsButton->setMaximumSize(QSize(16777215, 48));
        navRecordsButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background: transparent;\n"
"	color: rgb(74, 85, 104);\n"
"	border: none;\n"
"	border-radius: 6px;\n"
"	font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    color: #1A3A6B;\n"
"}\n"
"QPushButton:checked {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    color: #1A3A6B;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        navRecordsButton->setCheckable(true);
        navRecordsButton->setAutoExclusive(true);

        horizontalLayout_4->addWidget(navRecordsButton);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        navSerialLabel_2 = new QLabel(verticalLayoutWidget);
        navSerialLabel_2->setObjectName(QString::fromUtf8("navSerialLabel_2"));
        navSerialLabel_2->setMinimumSize(QSize(44, 44));
        navSerialLabel_2->setMaximumSize(QSize(48, 48));
        navSerialLabel_2->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	background:transparent;\n"
"}"));
        navSerialLabel_2->setPixmap(QPixmap(QString::fromUtf8(":/image/RechargeDeduction.png")));
        navSerialLabel_2->setScaledContents(true);

        horizontalLayout_8->addWidget(navSerialLabel_2);

        rachargeButton = new QPushButton(verticalLayoutWidget);
        rachargeButton->setObjectName(QString::fromUtf8("rachargeButton"));
        rachargeButton->setMinimumSize(QSize(0, 44));
        rachargeButton->setMaximumSize(QSize(16777215, 48));
        rachargeButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background: transparent;\n"
"	color: rgb(74, 85, 104);\n"
"	border: none;\n"
"	border-radius: 6px;\n"
"	font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    color: #1A3A6B;\n"
"}\n"
"QPushButton:checked {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    color: #1A3A6B;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        rachargeButton->setCheckable(true);
        rachargeButton->setAutoExclusive(true);

        horizontalLayout_8->addWidget(rachargeButton);


        verticalLayout->addLayout(horizontalLayout_8);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        navSerialLabel = new QLabel(verticalLayoutWidget);
        navSerialLabel->setObjectName(QString::fromUtf8("navSerialLabel"));
        navSerialLabel->setMinimumSize(QSize(44, 44));
        navSerialLabel->setMaximumSize(QSize(48, 48));
        navSerialLabel->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	background:transparent;\n"
"}"));
        navSerialLabel->setPixmap(QPixmap(QString::fromUtf8(":/image/Serial.png")));
        navSerialLabel->setScaledContents(true);

        horizontalLayout_5->addWidget(navSerialLabel);

        navSerialButton = new QPushButton(verticalLayoutWidget);
        navSerialButton->setObjectName(QString::fromUtf8("navSerialButton"));
        navSerialButton->setMinimumSize(QSize(0, 48));
        navSerialButton->setMaximumSize(QSize(16777215, 44));
        navSerialButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background: transparent;\n"
"	color: rgb(74, 85, 104);\n"
"	border: none;\n"
"	border-radius: 6px;\n"
"	font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    color: #1A3A6B;\n"
"}\n"
"QPushButton:checked {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    color: #1A3A6B;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        navSerialButton->setCheckable(true);
        navSerialButton->setAutoExclusive(true);

        horizontalLayout_5->addWidget(navSerialButton);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        navLogoutLabel = new QLabel(verticalLayoutWidget);
        navLogoutLabel->setObjectName(QString::fromUtf8("navLogoutLabel"));
        navLogoutLabel->setMinimumSize(QSize(44, 44));
        navLogoutLabel->setMaximumSize(QSize(48, 48));
        navLogoutLabel->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	background:transparent;\n"
"}"));
        navLogoutLabel->setPixmap(QPixmap(QString::fromUtf8(":/image/logoout.png")));
        navLogoutLabel->setScaledContents(true);

        horizontalLayout_6->addWidget(navLogoutLabel);

        navLogoutButton = new QPushButton(verticalLayoutWidget);
        navLogoutButton->setObjectName(QString::fromUtf8("navLogoutButton"));
        navLogoutButton->setMinimumSize(QSize(0, 44));
        navLogoutButton->setMaximumSize(QSize(16777215, 48));
        navLogoutButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background: transparent;\n"
"	color: rgb(74, 85, 104);\n"
"	border: none;\n"
"	border-radius: 6px;\n"
"	font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    color: #1A3A6B;\n"
"}\n"
"QPushButton:checked {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    color: #1A3A6B;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        navLogoutButton->setCheckable(true);
        navLogoutButton->setAutoExclusive(true);

        horizontalLayout_6->addWidget(navLogoutButton);


        verticalLayout->addLayout(horizontalLayout_6);


        navFrameVerticalLayout->addLayout(verticalLayout);


        gridLayout->addWidget(navFrame, 1, 0, 1, 1);

        stackedWidget = new QStackedWidget(SystemManagementPanel);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setMinimumSize(QSize(1301, 831));
        stackedWidget->setMaximumSize(QSize(1301, 831));
        homePage = new HomePageWidget();
        homePage->setObjectName(QString::fromUtf8("homePage"));
        stackedWidget->addWidget(homePage);
        userRegisterPage = new UserRegisterWidget();
        userRegisterPage->setObjectName(QString::fromUtf8("userRegisterPage"));
        stackedWidget->addWidget(userRegisterPage);
        userModifyPage = new UserModifyWidget();
        userModifyPage->setObjectName(QString::fromUtf8("userModifyPage"));
        stackedWidget->addWidget(userModifyPage);
        atendencePage = new AttendanceRecordsWidget();
        atendencePage->setObjectName(QString::fromUtf8("atendencePage"));
        stackedWidget->addWidget(atendencePage);
        rechargeDeductionPage = new RechargeAndDeductionWidget();
        rechargeDeductionPage->setObjectName(QString::fromUtf8("rechargeDeductionPage"));
        stackedWidget->addWidget(rechargeDeductionPage);
        serailSetPage = new SerialSetWidget();
        serailSetPage->setObjectName(QString::fromUtf8("serailSetPage"));
        stackedWidget->addWidget(serailSetPage);

        gridLayout->addWidget(stackedWidget, 1, 1, 1, 1);


        retranslateUi(SystemManagementPanel);

        stackedWidget->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(SystemManagementPanel);
    } // setupUi

    void retranslateUi(QWidget *SystemManagementPanel)
    {
        SystemManagementPanel->setWindowTitle(QApplication::translate("SystemManagementPanel", "Form", nullptr));
        serailTextLabel->setText(QApplication::translate("SystemManagementPanel", "\350\256\276\345\244\207COMn\345\267\262\350\277\236\346\216\245", nullptr));
        managerIconLabel->setText(QString());
        serilIconlabel->setText(QString());
        localTimeLabel->setText(QApplication::translate("SystemManagementPanel", "<html><head/><body><p><span style=\" font-size:11pt;\">\345\256\236\346\227\266\345\275\223\345\211\215\346\227\266\351\227\264</span></p></body></html>", nullptr));
        managerLabel->setText(QApplication::translate("SystemManagementPanel", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:600;\">\347\256\241\347\220\206\345\221\230\357\274\232</span></p></body></html>", nullptr));
        managerTitleLabel->setText(QApplication::translate("SystemManagementPanel", "<html><head/><body><p><span style=\" font-size:16pt;\">\347\256\241\347\220\206\345\221\230\351\235\242\346\235\277</span></p></body></html>", nullptr));
        managerNameLabel->setText(QApplication::translate("SystemManagementPanel", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:600;\">\347\256\241\347\220\206\345\221\230\345\247\223\345\220\215</span></p></body></html>", nullptr));
        navHomeLabel->setText(QString());
        navHomeButton->setText(QApplication::translate("SystemManagementPanel", "\351\246\226\351\241\265", nullptr));
        navRegisterLabel->setText(QString());
        navRegisterButton->setText(QApplication::translate("SystemManagementPanel", "\345\221\230\345\267\245\346\263\250\345\206\214", nullptr));
        navModifyLabel->setText(QString());
        navModifyButton->setText(QApplication::translate("SystemManagementPanel", "\345\221\230\345\267\245\344\277\241\346\201\257\344\277\256\346\224\271", nullptr));
        navRecordsLabel->setText(QString());
        navRecordsButton->setText(QApplication::translate("SystemManagementPanel", "\350\200\203\345\213\244\350\256\260\345\275\225\346\237\245\350\257\242", nullptr));
        navSerialLabel_2->setText(QString());
        rachargeButton->setText(QApplication::translate("SystemManagementPanel", "\345\205\205\345\200\274\346\211\243\346\254\276", nullptr));
        navSerialLabel->setText(QString());
        navSerialButton->setText(QApplication::translate("SystemManagementPanel", "\344\270\262\345\217\243\350\256\276\347\275\256", nullptr));
        navLogoutLabel->setText(QString());
        navLogoutButton->setText(QApplication::translate("SystemManagementPanel", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SystemManagementPanel: public Ui_SystemManagementPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMMANAGEMENTPANEL_H
