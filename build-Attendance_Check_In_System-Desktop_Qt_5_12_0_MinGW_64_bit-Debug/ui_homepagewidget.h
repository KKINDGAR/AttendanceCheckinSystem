/********************************************************************************
** Form generated from reading UI file 'homepagewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEPAGEWIDGET_H
#define UI_HOMEPAGEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomePageWidget
{
public:
    QVBoxLayout *mainVerticalLayout;
    QHBoxLayout *titleLayout;
    QLabel *welcomeLabel;
    QSpacerItem *titleHorizontalSpacer;
    QHBoxLayout *cardsHorizontalLayout;
    QFrame *uesrRegisterFrame;
    QVBoxLayout *card1Layout;
    QLabel *card1IconLabel;
    QLabel *card1TitleLabel;
    QLabel *card1DescLabel;
    QFrame *userModifyFrame;
    QVBoxLayout *card2Layout;
    QLabel *card2IconLabel;
    QLabel *card2TitleLabel;
    QLabel *card2DescLabel;
    QFrame *recordsFrame;
    QVBoxLayout *card3Layout;
    QLabel *card3IconLabel;
    QLabel *card3TitleLabel;
    QLabel *card3DescLabel;
    QFrame *recordsLookFrame;
    QVBoxLayout *card4Layout;
    QLabel *card4IconLabel;
    QLabel *card4TitleLabel;
    QLabel *card4DescLabel;
    QHBoxLayout *bottomHorizontalLayout;
    QFrame *recentMemoryFrame;
    QVBoxLayout *recentMemoryVerticalLayout;
    QLabel *recentMemoryTitleLabel;
    QTableView *recentRecordTableView;
    QFrame *serailSetFrame;
    QVBoxLayout *serialStatusVerticalLayout;
    QLabel *serialStatusTitleLabel;
    QLabel *serialIconLabel;
    QHBoxLayout *statusIndicatorLayout;
    QSpacerItem *statusLeftSpacer;
    QLabel *statusDotLabel;
    QLabel *statusLabel;
    QSpacerItem *statusRightSpacer;
    QFrame *serialInfoSeparator;
    QLabel *systemTitleLabel;
    QFormLayout *systemInfoFormLayout;
    QLabel *currentDateTitleLabel;
    QLabel *currentDateValueLabel;
    QLabel *totalEmployeesTitleLabel;
    QLabel *totalEmployeesValueLabel;
    QLabel *todayCheckinTitleLabel;
    QLabel *todayCheckinValueLabel;
    QSpacerItem *serialStatusVerticalSpacer;

    void setupUi(QWidget *HomePageWidget)
    {
        if (HomePageWidget->objectName().isEmpty())
            HomePageWidget->setObjectName(QString::fromUtf8("HomePageWidget"));
        HomePageWidget->resize(1301, 831);
        HomePageWidget->setMinimumSize(QSize(1301, 831));
        HomePageWidget->setMaximumSize(QSize(1301, 831));
        HomePageWidget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    font-family: \"Microsoft YaHei\", \"\345\276\256\350\275\257\351\233\205\351\273\221\", \"PingFang SC\", sans-serif;\n"
"    font-size: 14px;\n"
"    color: #2D3748;\n"
"}\n"
"QWidget#HomePageWidget{\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        mainVerticalLayout = new QVBoxLayout(HomePageWidget);
        mainVerticalLayout->setSpacing(20);
        mainVerticalLayout->setObjectName(QString::fromUtf8("mainVerticalLayout"));
        mainVerticalLayout->setContentsMargins(20, 20, 20, 20);
        titleLayout = new QHBoxLayout();
        titleLayout->setObjectName(QString::fromUtf8("titleLayout"));
        welcomeLabel = new QLabel(HomePageWidget);
        welcomeLabel->setObjectName(QString::fromUtf8("welcomeLabel"));
        welcomeLabel->setMinimumSize(QSize(0, 40));
        welcomeLabel->setMaximumSize(QSize(16777215, 40));
        welcomeLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 20px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));

        titleLayout->addWidget(welcomeLabel);

        titleHorizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        titleLayout->addItem(titleHorizontalSpacer);


        mainVerticalLayout->addLayout(titleLayout);

        cardsHorizontalLayout = new QHBoxLayout();
        cardsHorizontalLayout->setSpacing(20);
        cardsHorizontalLayout->setObjectName(QString::fromUtf8("cardsHorizontalLayout"));
        uesrRegisterFrame = new QFrame(HomePageWidget);
        uesrRegisterFrame->setObjectName(QString::fromUtf8("uesrRegisterFrame"));
        uesrRegisterFrame->setMinimumSize(QSize(280, 300));
        uesrRegisterFrame->setMaximumSize(QSize(280, 300));
        uesrRegisterFrame->setStyleSheet(QString::fromUtf8("QFrame#uesrRegisterFrame{\n"
"    background:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 16px;\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}\n"
"QFrame#uesrRegisterFrame:hover{\n"
"    border: 2px solid #348aff;\n"
"}"));
        uesrRegisterFrame->setFrameShape(QFrame::StyledPanel);
        uesrRegisterFrame->setFrameShadow(QFrame::Raised);
        card1Layout = new QVBoxLayout(uesrRegisterFrame);
        card1Layout->setSpacing(10);
        card1Layout->setObjectName(QString::fromUtf8("card1Layout"));
        card1Layout->setContentsMargins(20, 30, 20, 30);
        card1IconLabel = new QLabel(uesrRegisterFrame);
        card1IconLabel->setObjectName(QString::fromUtf8("card1IconLabel"));
        card1IconLabel->setMinimumSize(QSize(80, 80));
        card1IconLabel->setMaximumSize(QSize(80, 80));
        card1IconLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    background:transparent;\n"
"}"));
        card1IconLabel->setPixmap(QPixmap(QString::fromUtf8(":/image/ICcard.png")));
        card1IconLabel->setScaledContents(true);
        card1IconLabel->setAlignment(Qt::AlignCenter);

        card1Layout->addWidget(card1IconLabel);

        card1TitleLabel = new QLabel(uesrRegisterFrame);
        card1TitleLabel->setObjectName(QString::fromUtf8("card1TitleLabel"));
        card1TitleLabel->setMinimumSize(QSize(0, 30));
        card1TitleLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));
        card1TitleLabel->setAlignment(Qt::AlignCenter);

        card1Layout->addWidget(card1TitleLabel);

        card1DescLabel = new QLabel(uesrRegisterFrame);
        card1DescLabel->setObjectName(QString::fromUtf8("card1DescLabel"));
        card1DescLabel->setMinimumSize(QSize(0, 40));
        card1DescLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 13px;\n"
"    color: #666666;\n"
"    background:transparent;\n"
"}"));
        card1DescLabel->setAlignment(Qt::AlignCenter);

        card1Layout->addWidget(card1DescLabel);


        cardsHorizontalLayout->addWidget(uesrRegisterFrame);

        userModifyFrame = new QFrame(HomePageWidget);
        userModifyFrame->setObjectName(QString::fromUtf8("userModifyFrame"));
        userModifyFrame->setMinimumSize(QSize(280, 300));
        userModifyFrame->setMaximumSize(QSize(280, 300));
        userModifyFrame->setStyleSheet(QString::fromUtf8("QFrame#userModifyFrame{\n"
"    background:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 16px;\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}\n"
"QFrame#userModifyFrame:hover{\n"
"    border: 2px solid #348aff;\n"
"}"));
        userModifyFrame->setFrameShape(QFrame::StyledPanel);
        userModifyFrame->setFrameShadow(QFrame::Raised);
        card2Layout = new QVBoxLayout(userModifyFrame);
        card2Layout->setSpacing(10);
        card2Layout->setObjectName(QString::fromUtf8("card2Layout"));
        card2Layout->setContentsMargins(20, 30, 20, 30);
        card2IconLabel = new QLabel(userModifyFrame);
        card2IconLabel->setObjectName(QString::fromUtf8("card2IconLabel"));
        card2IconLabel->setMinimumSize(QSize(80, 80));
        card2IconLabel->setMaximumSize(QSize(80, 80));
        card2IconLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    background:transparent;\n"
"}"));
        card2IconLabel->setPixmap(QPixmap(QString::fromUtf8(":/image/changeUser.png")));
        card2IconLabel->setScaledContents(true);
        card2IconLabel->setAlignment(Qt::AlignCenter);

        card2Layout->addWidget(card2IconLabel);

        card2TitleLabel = new QLabel(userModifyFrame);
        card2TitleLabel->setObjectName(QString::fromUtf8("card2TitleLabel"));
        card2TitleLabel->setMinimumSize(QSize(0, 30));
        card2TitleLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));
        card2TitleLabel->setAlignment(Qt::AlignCenter);

        card2Layout->addWidget(card2TitleLabel);

        card2DescLabel = new QLabel(userModifyFrame);
        card2DescLabel->setObjectName(QString::fromUtf8("card2DescLabel"));
        card2DescLabel->setMinimumSize(QSize(0, 40));
        card2DescLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 13px;\n"
"    color: #666666;\n"
"    background:transparent;\n"
"}"));
        card2DescLabel->setAlignment(Qt::AlignCenter);

        card2Layout->addWidget(card2DescLabel);


        cardsHorizontalLayout->addWidget(userModifyFrame);

        recordsFrame = new QFrame(HomePageWidget);
        recordsFrame->setObjectName(QString::fromUtf8("recordsFrame"));
        recordsFrame->setMinimumSize(QSize(280, 300));
        recordsFrame->setMaximumSize(QSize(280, 300));
        recordsFrame->setStyleSheet(QString::fromUtf8("QFrame#recordsFrame{\n"
"    background:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 16px;\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}\n"
"QFrame#recordsFrame:hover{\n"
"    border: 2px solid #348aff;\n"
"}"));
        recordsFrame->setFrameShape(QFrame::StyledPanel);
        recordsFrame->setFrameShadow(QFrame::Raised);
        card3Layout = new QVBoxLayout(recordsFrame);
        card3Layout->setSpacing(10);
        card3Layout->setObjectName(QString::fromUtf8("card3Layout"));
        card3Layout->setContentsMargins(20, 30, 20, 30);
        card3IconLabel = new QLabel(recordsFrame);
        card3IconLabel->setObjectName(QString::fromUtf8("card3IconLabel"));
        card3IconLabel->setMinimumSize(QSize(80, 80));
        card3IconLabel->setMaximumSize(QSize(80, 80));
        card3IconLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    background:transparent;\n"
"}"));
        card3IconLabel->setPixmap(QPixmap(QString::fromUtf8(":/image/Records.png")));
        card3IconLabel->setScaledContents(true);
        card3IconLabel->setAlignment(Qt::AlignCenter);

        card3Layout->addWidget(card3IconLabel);

        card3TitleLabel = new QLabel(recordsFrame);
        card3TitleLabel->setObjectName(QString::fromUtf8("card3TitleLabel"));
        card3TitleLabel->setMinimumSize(QSize(0, 30));
        card3TitleLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));
        card3TitleLabel->setAlignment(Qt::AlignCenter);

        card3Layout->addWidget(card3TitleLabel);

        card3DescLabel = new QLabel(recordsFrame);
        card3DescLabel->setObjectName(QString::fromUtf8("card3DescLabel"));
        card3DescLabel->setMinimumSize(QSize(0, 40));
        card3DescLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 13px;\n"
"    color: #666666;\n"
"    background:transparent;\n"
"}"));
        card3DescLabel->setAlignment(Qt::AlignCenter);

        card3Layout->addWidget(card3DescLabel);


        cardsHorizontalLayout->addWidget(recordsFrame);

        recordsLookFrame = new QFrame(HomePageWidget);
        recordsLookFrame->setObjectName(QString::fromUtf8("recordsLookFrame"));
        recordsLookFrame->setMinimumSize(QSize(280, 300));
        recordsLookFrame->setMaximumSize(QSize(280, 300));
        recordsLookFrame->setStyleSheet(QString::fromUtf8("QFrame#recordsLookFrame{\n"
"    background:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 16px;\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}\n"
"QFrame#recordsLookFrame:hover{\n"
"    border: 2px solid #348aff;\n"
"}"));
        recordsLookFrame->setFrameShape(QFrame::StyledPanel);
        recordsLookFrame->setFrameShadow(QFrame::Raised);
        card4Layout = new QVBoxLayout(recordsLookFrame);
        card4Layout->setSpacing(10);
        card4Layout->setObjectName(QString::fromUtf8("card4Layout"));
        card4Layout->setContentsMargins(20, 30, 20, 30);
        card4IconLabel = new QLabel(recordsLookFrame);
        card4IconLabel->setObjectName(QString::fromUtf8("card4IconLabel"));
        card4IconLabel->setMinimumSize(QSize(80, 80));
        card4IconLabel->setMaximumSize(QSize(80, 80));
        card4IconLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    background:transparent;\n"
"}"));
        card4IconLabel->setPixmap(QPixmap(QString::fromUtf8(":/image/RechargeDeduction.png")));
        card4IconLabel->setScaledContents(true);
        card4IconLabel->setAlignment(Qt::AlignCenter);

        card4Layout->addWidget(card4IconLabel);

        card4TitleLabel = new QLabel(recordsLookFrame);
        card4TitleLabel->setObjectName(QString::fromUtf8("card4TitleLabel"));
        card4TitleLabel->setMinimumSize(QSize(0, 30));
        card4TitleLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));
        card4TitleLabel->setAlignment(Qt::AlignCenter);

        card4Layout->addWidget(card4TitleLabel);

        card4DescLabel = new QLabel(recordsLookFrame);
        card4DescLabel->setObjectName(QString::fromUtf8("card4DescLabel"));
        card4DescLabel->setMinimumSize(QSize(0, 40));
        card4DescLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 13px;\n"
"    color: #666666;\n"
"    background:transparent;\n"
"}"));
        card4DescLabel->setAlignment(Qt::AlignCenter);

        card4Layout->addWidget(card4DescLabel);


        cardsHorizontalLayout->addWidget(recordsLookFrame);


        mainVerticalLayout->addLayout(cardsHorizontalLayout);

        bottomHorizontalLayout = new QHBoxLayout();
        bottomHorizontalLayout->setSpacing(20);
        bottomHorizontalLayout->setObjectName(QString::fromUtf8("bottomHorizontalLayout"));
        recentMemoryFrame = new QFrame(HomePageWidget);
        recentMemoryFrame->setObjectName(QString::fromUtf8("recentMemoryFrame"));
        recentMemoryFrame->setMinimumSize(QSize(871, 420));
        recentMemoryFrame->setMaximumSize(QSize(871, 420));
        recentMemoryFrame->setStyleSheet(QString::fromUtf8("QFrame#recentMemoryFrame{\n"
"    background:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 16px;\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        recentMemoryFrame->setFrameShape(QFrame::StyledPanel);
        recentMemoryFrame->setFrameShadow(QFrame::Raised);
        recentMemoryVerticalLayout = new QVBoxLayout(recentMemoryFrame);
        recentMemoryVerticalLayout->setSpacing(10);
        recentMemoryVerticalLayout->setObjectName(QString::fromUtf8("recentMemoryVerticalLayout"));
        recentMemoryVerticalLayout->setContentsMargins(20, 15, 20, 15);
        recentMemoryTitleLabel = new QLabel(recentMemoryFrame);
        recentMemoryTitleLabel->setObjectName(QString::fromUtf8("recentMemoryTitleLabel"));
        recentMemoryTitleLabel->setMinimumSize(QSize(0, 35));
        recentMemoryTitleLabel->setMaximumSize(QSize(16777215, 35));
        recentMemoryTitleLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));

        recentMemoryVerticalLayout->addWidget(recentMemoryTitleLabel);

        recentRecordTableView = new QTableView(recentMemoryFrame);
        recentRecordTableView->setObjectName(QString::fromUtf8("recentRecordTableView"));
        recentRecordTableView->setStyleSheet(QString::fromUtf8("QTableView{\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border: none;\n"
"    gridline-color: rgba(100, 118, 135, 80);\n"
"}\n"
"QTableView::item:selected{\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    color: #1A3A6B;\n"
"}\n"
"QHeaderView::section{\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    color: #1A3A6B;\n"
"    font-weight: bold;\n"
"    font-size: 14px;\n"
"    padding: 8px;\n"
"    border: none;\n"
"    border-bottom: 2px solid rgba(100, 118, 135, 80);\n"
"}"));
        recentRecordTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        recentRecordTableView->setAlternatingRowColors(true);
        recentRecordTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        recentMemoryVerticalLayout->addWidget(recentRecordTableView);


        bottomHorizontalLayout->addWidget(recentMemoryFrame);

        serailSetFrame = new QFrame(HomePageWidget);
        serailSetFrame->setObjectName(QString::fromUtf8("serailSetFrame"));
        serailSetFrame->setMinimumSize(QSize(351, 420));
        serailSetFrame->setMaximumSize(QSize(351, 420));
        serailSetFrame->setStyleSheet(QString::fromUtf8("QFrame#serailSetFrame{\n"
"    background:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 16px;\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        serailSetFrame->setFrameShape(QFrame::StyledPanel);
        serailSetFrame->setFrameShadow(QFrame::Raised);
        serialStatusVerticalLayout = new QVBoxLayout(serailSetFrame);
        serialStatusVerticalLayout->setSpacing(15);
        serialStatusVerticalLayout->setObjectName(QString::fromUtf8("serialStatusVerticalLayout"));
        serialStatusVerticalLayout->setContentsMargins(20, 20, 20, 20);
        serialStatusTitleLabel = new QLabel(serailSetFrame);
        serialStatusTitleLabel->setObjectName(QString::fromUtf8("serialStatusTitleLabel"));
        serialStatusTitleLabel->setMinimumSize(QSize(0, 35));
        serialStatusTitleLabel->setMaximumSize(QSize(16777215, 35));
        serialStatusTitleLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));

        serialStatusVerticalLayout->addWidget(serialStatusTitleLabel);

        serialIconLabel = new QLabel(serailSetFrame);
        serialIconLabel->setObjectName(QString::fromUtf8("serialIconLabel"));
        serialIconLabel->setMinimumSize(QSize(60, 60));
        serialIconLabel->setMaximumSize(QSize(60, 60));
        serialIconLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    background:transparent;\n"
"}"));
        serialIconLabel->setPixmap(QPixmap(QString::fromUtf8(":/image/Serial.png")));
        serialIconLabel->setScaledContents(true);
        serialIconLabel->setAlignment(Qt::AlignCenter);

        serialStatusVerticalLayout->addWidget(serialIconLabel);

        statusIndicatorLayout = new QHBoxLayout();
        statusIndicatorLayout->setSpacing(15);
        statusIndicatorLayout->setObjectName(QString::fromUtf8("statusIndicatorLayout"));
        statusLeftSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        statusIndicatorLayout->addItem(statusLeftSpacer);

        statusDotLabel = new QLabel(serailSetFrame);
        statusDotLabel->setObjectName(QString::fromUtf8("statusDotLabel"));
        statusDotLabel->setMinimumSize(QSize(14, 14));
        statusDotLabel->setMaximumSize(QSize(14, 14));
        statusDotLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border-radius: 7px;\n"
"    background-color: #C0392B;\n"
"}"));

        statusIndicatorLayout->addWidget(statusDotLabel);

        statusLabel = new QLabel(serailSetFrame);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setMinimumSize(QSize(80, 30));
        statusLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-weight: bold;\n"
"    font-size: 15px;\n"
"    color: #C0392B;\n"
"    background:transparent;\n"
"}"));

        statusIndicatorLayout->addWidget(statusLabel);

        statusRightSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        statusIndicatorLayout->addItem(statusRightSpacer);


        serialStatusVerticalLayout->addLayout(statusIndicatorLayout);

        serialInfoSeparator = new QFrame(serailSetFrame);
        serialInfoSeparator->setObjectName(QString::fromUtf8("serialInfoSeparator"));
        serialInfoSeparator->setMinimumSize(QSize(0, 2));
        serialInfoSeparator->setMaximumSize(QSize(16777215, 2));
        serialInfoSeparator->setStyleSheet(QString::fromUtf8("QFrame#serialInfoSeparator{\n"
"    background: rgba(100, 118, 135, 80);\n"
"    border: none;\n"
"}"));

        serialStatusVerticalLayout->addWidget(serialInfoSeparator);

        systemTitleLabel = new QLabel(serailSetFrame);
        systemTitleLabel->setObjectName(QString::fromUtf8("systemTitleLabel"));
        systemTitleLabel->setMinimumSize(QSize(0, 30));
        systemTitleLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));

        serialStatusVerticalLayout->addWidget(systemTitleLabel);

        systemInfoFormLayout = new QFormLayout();
        systemInfoFormLayout->setObjectName(QString::fromUtf8("systemInfoFormLayout"));
        systemInfoFormLayout->setHorizontalSpacing(12);
        systemInfoFormLayout->setVerticalSpacing(12);
        currentDateTitleLabel = new QLabel(serailSetFrame);
        currentDateTitleLabel->setObjectName(QString::fromUtf8("currentDateTitleLabel"));
        currentDateTitleLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 14px;\n"
"    color: #666666;\n"
"    background:transparent;\n"
"}"));

        systemInfoFormLayout->setWidget(0, QFormLayout::LabelRole, currentDateTitleLabel);

        currentDateValueLabel = new QLabel(serailSetFrame);
        currentDateValueLabel->setObjectName(QString::fromUtf8("currentDateValueLabel"));
        currentDateValueLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));

        systemInfoFormLayout->setWidget(0, QFormLayout::FieldRole, currentDateValueLabel);

        totalEmployeesTitleLabel = new QLabel(serailSetFrame);
        totalEmployeesTitleLabel->setObjectName(QString::fromUtf8("totalEmployeesTitleLabel"));
        totalEmployeesTitleLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 14px;\n"
"    color: #666666;\n"
"    background:transparent;\n"
"}"));

        systemInfoFormLayout->setWidget(1, QFormLayout::LabelRole, totalEmployeesTitleLabel);

        totalEmployeesValueLabel = new QLabel(serailSetFrame);
        totalEmployeesValueLabel->setObjectName(QString::fromUtf8("totalEmployeesValueLabel"));
        totalEmployeesValueLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));

        systemInfoFormLayout->setWidget(1, QFormLayout::FieldRole, totalEmployeesValueLabel);

        todayCheckinTitleLabel = new QLabel(serailSetFrame);
        todayCheckinTitleLabel->setObjectName(QString::fromUtf8("todayCheckinTitleLabel"));
        todayCheckinTitleLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 14px;\n"
"    color: #666666;\n"
"    background:transparent;\n"
"}"));

        systemInfoFormLayout->setWidget(2, QFormLayout::LabelRole, todayCheckinTitleLabel);

        todayCheckinValueLabel = new QLabel(serailSetFrame);
        todayCheckinValueLabel->setObjectName(QString::fromUtf8("todayCheckinValueLabel"));
        todayCheckinValueLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));

        systemInfoFormLayout->setWidget(2, QFormLayout::FieldRole, todayCheckinValueLabel);


        serialStatusVerticalLayout->addLayout(systemInfoFormLayout);

        serialStatusVerticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        serialStatusVerticalLayout->addItem(serialStatusVerticalSpacer);


        bottomHorizontalLayout->addWidget(serailSetFrame);


        mainVerticalLayout->addLayout(bottomHorizontalLayout);


        retranslateUi(HomePageWidget);

        QMetaObject::connectSlotsByName(HomePageWidget);
    } // setupUi

    void retranslateUi(QWidget *HomePageWidget)
    {
        HomePageWidget->setWindowTitle(QApplication::translate("HomePageWidget", "Form", nullptr));
        welcomeLabel->setText(QApplication::translate("HomePageWidget", "<html><head/><body><p><span style=\" font-size:14pt;\">\346\202\250\345\245\275\357\274\214\346\254\242\350\277\216\344\275\277\347\224\250\350\200\203\345\213\244\347\255\276\345\210\260\347\256\241\347\220\206\347\263\273\347\273\237</span></p></body></html>", nullptr));
        card1IconLabel->setText(QString());
        card1TitleLabel->setText(QApplication::translate("HomePageWidget", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">\345\221\230\345\267\245\346\263\250\345\206\214</span></p></body></html>", nullptr));
        card1DescLabel->setText(QApplication::translate("HomePageWidget", "<html><head/><body><p align=\"center\">\346\226\260\345\221\230\345\267\245IC\345\215\241\346\263\250\345\206\214<br/>\345\217\221\346\224\276\344\270\216\347\256\241\347\220\206</p></body></html>", nullptr));
        card2IconLabel->setText(QString());
        card2TitleLabel->setText(QApplication::translate("HomePageWidget", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">\345\221\230\345\267\245\344\277\241\346\201\257\344\277\256\346\224\271</span></p></body></html>", nullptr));
        card2DescLabel->setText(QApplication::translate("HomePageWidget", "<html><head/><body><p align=\"center\">\344\277\256\346\224\271\346\210\226\345\210\240\351\231\244<br/>\345\267\262\346\263\250\345\206\214\345\221\230\345\267\245\344\277\241\346\201\257</p></body></html>", nullptr));
        card3IconLabel->setText(QString());
        card3TitleLabel->setText(QApplication::translate("HomePageWidget", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">\350\200\203\345\213\244\350\256\260\345\275\225\346\237\245\350\257\242</span></p></body></html>", nullptr));
        card3DescLabel->setText(QApplication::translate("HomePageWidget", "<html><head/><body><p align=\"center\">\346\237\245\350\257\242\350\200\203\345\213\244\350\256\260\345\275\225<br/>\347\255\276\345\210\260/\347\255\276\351\200\200/\350\277\237\345\210\260/\347\274\272\345\213\244</p></body></html>", nullptr));
        card4IconLabel->setText(QString());
        card4TitleLabel->setText(QApplication::translate("HomePageWidget", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">\345\205\205\345\200\274 / \346\211\243\346\254\276</span></p></body></html>", nullptr));
        card4DescLabel->setText(QApplication::translate("HomePageWidget", "<html><head/><body><p align=\"center\">\350\264\246\346\210\267\344\275\231\351\242\235\345\205\205\345\200\274<br/>\344\270\216\346\211\243\346\254\276\346\223\215\344\275\234</p></body></html>", nullptr));
        recentMemoryTitleLabel->setText(QApplication::translate("HomePageWidget", "<html><head/><body><p><span style=\" font-size:12pt;\">\346\234\200\350\277\221\350\200\203\345\213\244\345\212\250\346\200\201</span></p></body></html>", nullptr));
        serialStatusTitleLabel->setText(QApplication::translate("HomePageWidget", "<html><head/><body><p><span style=\" font-size:12pt;\">\344\270\262\345\217\243\347\212\266\346\200\201</span></p></body></html>", nullptr));
        serialIconLabel->setText(QString());
        statusDotLabel->setText(QString());
        statusLabel->setText(QApplication::translate("HomePageWidget", "\346\234\252\350\277\236\346\216\245", nullptr));
        systemTitleLabel->setText(QApplication::translate("HomePageWidget", "\347\263\273\347\273\237\344\277\241\346\201\257", nullptr));
        currentDateTitleLabel->setText(QApplication::translate("HomePageWidget", "\345\275\223\345\211\215\346\227\245\346\234\237", nullptr));
        currentDateValueLabel->setText(QApplication::translate("HomePageWidget", "----", nullptr));
        totalEmployeesTitleLabel->setText(QApplication::translate("HomePageWidget", "\345\221\230\345\267\245\346\200\273\346\225\260", nullptr));
        totalEmployeesValueLabel->setText(QApplication::translate("HomePageWidget", "----", nullptr));
        todayCheckinTitleLabel->setText(QApplication::translate("HomePageWidget", "\344\273\212\346\227\245\347\255\276\345\210\260", nullptr));
        todayCheckinValueLabel->setText(QApplication::translate("HomePageWidget", "----", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HomePageWidget: public Ui_HomePageWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGEWIDGET_H
