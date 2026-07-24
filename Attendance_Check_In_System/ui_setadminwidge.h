/********************************************************************************
** Form generated from reading UI file 'setadminwidge.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETADMINWIDGE_H
#define UI_SETADMINWIDGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetAdminWidge
{
public:
    QGridLayout *gridLayout;
    QTableView *adminInfoTableView;
    QHBoxLayout *headerLayout;
    QSpacerItem *headerLeftSpacer;
    QLabel *adminCountLabel;
    QHBoxLayout *topHorizontalLayout;
    QFrame *adminMainCard;
    QVBoxLayout *cardVerticalLayout;
    QLabel *cardTitleLabel;
    QLabel *cardLogoLabel;
    QLabel *promptLabel;
    QFrame *actionFormFrame;
    QVBoxLayout *actionVerticalLayout;
    QLabel *sectionRegisterLabel;
    QPushButton *registerAdminButton;
    QFrame *separatorLine;
    QLabel *sectionModifyLabel;
    QGridLayout *modifyFormGrid;
    QLabel *cardNumLabel;
    QHBoxLayout *cardInputLayout;
    QLineEdit *adminCardEdit;
    QPushButton *refreshCardButton;
    QLabel *adminNameLabel;
    QLineEdit *adminNameEdit;
    QLabel *adminNewPwdLabel;
    QLineEdit *adminNewPwdEdit;
    QLabel *adminConfirmPwdLabel;
    QLineEdit *adminConfirmPwdEdit;
    QHBoxLayout *modifyButtonLayout;
    QSpacerItem *modifyLeftSpacer;
    QPushButton *saveModifyButton;
    QPushButton *resetModifyButton;
    QSpacerItem *modifyRightSpacer;

    void setupUi(QWidget *SetAdminWidge)
    {
        if (SetAdminWidge->objectName().isEmpty())
            SetAdminWidge->setObjectName(QString::fromUtf8("SetAdminWidge"));
        SetAdminWidge->resize(1301, 831);
        SetAdminWidge->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    font-family: \"Microsoft YaHei\", \"\345\276\256\350\275\257\351\233\205\351\273\221\", \"PingFang SC\", sans-serif;\n"
"    font-size: 14px;\n"
"    color: #2D3748;\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}\n"
"QWidget#SetAdminWidge{\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        gridLayout = new QGridLayout(SetAdminWidge);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        adminInfoTableView = new QTableView(SetAdminWidge);
        adminInfoTableView->setObjectName(QString::fromUtf8("adminInfoTableView"));
        adminInfoTableView->setStyleSheet(QString::fromUtf8("QTableView{\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
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
        adminInfoTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        adminInfoTableView->setAlternatingRowColors(true);
        adminInfoTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        gridLayout->addWidget(adminInfoTableView, 2, 0, 1, 1);

        headerLayout = new QHBoxLayout();
        headerLayout->setObjectName(QString::fromUtf8("headerLayout"));
        headerLeftSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        headerLayout->addItem(headerLeftSpacer);

        adminCountLabel = new QLabel(SetAdminWidge);
        adminCountLabel->setObjectName(QString::fromUtf8("adminCountLabel"));
        adminCountLabel->setMinimumSize(QSize(0, 30));
        adminCountLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));

        headerLayout->addWidget(adminCountLabel);


        gridLayout->addLayout(headerLayout, 0, 0, 1, 1);

        topHorizontalLayout = new QHBoxLayout();
        topHorizontalLayout->setSpacing(20);
        topHorizontalLayout->setObjectName(QString::fromUtf8("topHorizontalLayout"));
        adminMainCard = new QFrame(SetAdminWidge);
        adminMainCard->setObjectName(QString::fromUtf8("adminMainCard"));
        adminMainCard->setMinimumSize(QSize(301, 340));
        adminMainCard->setMaximumSize(QSize(301, 373));
        adminMainCard->setStyleSheet(QString::fromUtf8("QFrame#adminMainCard{\n"
"    background: transparent;\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        adminMainCard->setFrameShape(QFrame::StyledPanel);
        adminMainCard->setFrameShadow(QFrame::Raised);
        cardVerticalLayout = new QVBoxLayout(adminMainCard);
        cardVerticalLayout->setSpacing(10);
        cardVerticalLayout->setObjectName(QString::fromUtf8("cardVerticalLayout"));
        cardVerticalLayout->setContentsMargins(10, 10, 10, 10);
        cardTitleLabel = new QLabel(adminMainCard);
        cardTitleLabel->setObjectName(QString::fromUtf8("cardTitleLabel"));
        cardTitleLabel->setMinimumSize(QSize(160, 45));
        cardTitleLabel->setMaximumSize(QSize(280, 45));
        cardTitleLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    qproperty-alignment: AlignCenter;\n"
"    background:transparent;\n"
"}"));

        cardVerticalLayout->addWidget(cardTitleLabel);

        cardLogoLabel = new QLabel(adminMainCard);
        cardLogoLabel->setObjectName(QString::fromUtf8("cardLogoLabel"));
        cardLogoLabel->setMinimumSize(QSize(261, 171));
        cardLogoLabel->setMaximumSize(QSize(280, 200));
        cardLogoLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    background:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        cardLogoLabel->setPixmap(QPixmap(QString::fromUtf8(":/image/manager.png")));
        cardLogoLabel->setScaledContents(true);

        cardVerticalLayout->addWidget(cardLogoLabel);

        promptLabel = new QLabel(adminMainCard);
        promptLabel->setObjectName(QString::fromUtf8("promptLabel"));
        promptLabel->setMinimumSize(QSize(151, 20));
        promptLabel->setMaximumSize(QSize(280, 20));
        promptLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    background:transparent;\n"
"}"));

        cardVerticalLayout->addWidget(promptLabel);


        topHorizontalLayout->addWidget(adminMainCard);

        actionFormFrame = new QFrame(SetAdminWidge);
        actionFormFrame->setObjectName(QString::fromUtf8("actionFormFrame"));
        actionFormFrame->setMinimumSize(QSize(0, 380));
        actionFormFrame->setStyleSheet(QString::fromUtf8("QFrame#actionFormFrame{\n"
"    background: transparent;\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        actionFormFrame->setFrameShape(QFrame::StyledPanel);
        actionFormFrame->setFrameShadow(QFrame::Raised);
        actionVerticalLayout = new QVBoxLayout(actionFormFrame);
        actionVerticalLayout->setSpacing(12);
        actionVerticalLayout->setObjectName(QString::fromUtf8("actionVerticalLayout"));
        actionVerticalLayout->setContentsMargins(30, 20, 30, 20);
        sectionRegisterLabel = new QLabel(actionFormFrame);
        sectionRegisterLabel->setObjectName(QString::fromUtf8("sectionRegisterLabel"));
        sectionRegisterLabel->setMinimumSize(QSize(0, 24));
        sectionRegisterLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));

        actionVerticalLayout->addWidget(sectionRegisterLabel);

        registerAdminButton = new QPushButton(actionFormFrame);
        registerAdminButton->setObjectName(QString::fromUtf8("registerAdminButton"));
        registerAdminButton->setMinimumSize(QSize(0, 44));
        registerAdminButton->setMaximumSize(QSize(16777215, 44));
        registerAdminButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.248927 rgba(85, 116, 143, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    color: rgb(74, 85, 104);\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 6px;\n"
"    font-size: 14px;\n"
"    font: 63 9pt \"Bahnschrift SemiBold SemiConden\";\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    color: #1A3A6B;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    color: #1A3A6B;\n"
"    font-weight: bold;\n"
"}"));

        actionVerticalLayout->addWidget(registerAdminButton);

        separatorLine = new QFrame(actionFormFrame);
        separatorLine->setObjectName(QString::fromUtf8("separatorLine"));
        separatorLine->setMinimumSize(QSize(0, 2));
        separatorLine->setMaximumSize(QSize(16777215, 2));
        separatorLine->setStyleSheet(QString::fromUtf8("QFrame#separatorLine{\n"
"    border:none;\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        separatorLine->setFrameShape(QFrame::HLine);

        actionVerticalLayout->addWidget(separatorLine);

        sectionModifyLabel = new QLabel(actionFormFrame);
        sectionModifyLabel->setObjectName(QString::fromUtf8("sectionModifyLabel"));
        sectionModifyLabel->setMinimumSize(QSize(0, 24));
        sectionModifyLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));

        actionVerticalLayout->addWidget(sectionModifyLabel);

        modifyFormGrid = new QGridLayout();
        modifyFormGrid->setSpacing(10);
        modifyFormGrid->setObjectName(QString::fromUtf8("modifyFormGrid"));
        cardNumLabel = new QLabel(actionFormFrame);
        cardNumLabel->setObjectName(QString::fromUtf8("cardNumLabel"));
        cardNumLabel->setMinimumSize(QSize(70, 36));
        cardNumLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));

        modifyFormGrid->addWidget(cardNumLabel, 0, 0, 1, 1);

        cardInputLayout = new QHBoxLayout();
        cardInputLayout->setSpacing(8);
        cardInputLayout->setObjectName(QString::fromUtf8("cardInputLayout"));
        adminCardEdit = new QLineEdit(actionFormFrame);
        adminCardEdit->setObjectName(QString::fromUtf8("adminCardEdit"));
        adminCardEdit->setMinimumSize(QSize(0, 36));
        adminCardEdit->setMaximumSize(QSize(16777215, 36));
        adminCardEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 8px;\n"
"    padding: 6px 12px;\n"
"    font-size: 14px;\n"
"    color: rgb(0, 0, 0);\n"
"}\n"
"QLineEdit:focus{\n"
"    border: 1px solid #348aff;\n"
"}\n"
"QLineEdit::placeholder{\n"
"    color: #888888;\n"
"}"));

        cardInputLayout->addWidget(adminCardEdit);

        refreshCardButton = new QPushButton(actionFormFrame);
        refreshCardButton->setObjectName(QString::fromUtf8("refreshCardButton"));
        refreshCardButton->setMinimumSize(QSize(90, 36));
        refreshCardButton->setMaximumSize(QSize(90, 36));
        refreshCardButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.248927 rgba(85, 116, 143, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    color: rgb(74, 85, 104);\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 6px;\n"
"    font-size: 13px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    color: #1A3A6B;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    color: #1A3A6B;\n"
"    font-weight: bold;\n"
"}"));

        cardInputLayout->addWidget(refreshCardButton);


        modifyFormGrid->addLayout(cardInputLayout, 0, 1, 1, 2);

        adminNameLabel = new QLabel(actionFormFrame);
        adminNameLabel->setObjectName(QString::fromUtf8("adminNameLabel"));
        adminNameLabel->setMinimumSize(QSize(70, 36));
        adminNameLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));

        modifyFormGrid->addWidget(adminNameLabel, 1, 0, 1, 1);

        adminNameEdit = new QLineEdit(actionFormFrame);
        adminNameEdit->setObjectName(QString::fromUtf8("adminNameEdit"));
        adminNameEdit->setMinimumSize(QSize(0, 36));
        adminNameEdit->setMaximumSize(QSize(16777215, 36));
        adminNameEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 8px;\n"
"    padding: 6px 12px;\n"
"    font-size: 14px;\n"
"    color: rgb(0, 0, 0);\n"
"}\n"
"QLineEdit:focus{\n"
"    border: 1px solid #348aff;\n"
"}\n"
"QLineEdit::placeholder{\n"
"    color: #888888;\n"
"}"));

        modifyFormGrid->addWidget(adminNameEdit, 1, 1, 1, 2);

        adminNewPwdLabel = new QLabel(actionFormFrame);
        adminNewPwdLabel->setObjectName(QString::fromUtf8("adminNewPwdLabel"));
        adminNewPwdLabel->setMinimumSize(QSize(70, 36));
        adminNewPwdLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));

        modifyFormGrid->addWidget(adminNewPwdLabel, 2, 0, 1, 1);

        adminNewPwdEdit = new QLineEdit(actionFormFrame);
        adminNewPwdEdit->setObjectName(QString::fromUtf8("adminNewPwdEdit"));
        adminNewPwdEdit->setMinimumSize(QSize(0, 36));
        adminNewPwdEdit->setMaximumSize(QSize(16777215, 36));
        adminNewPwdEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 8px;\n"
"    padding: 6px 12px;\n"
"    font-size: 14px;\n"
"    color: rgb(0, 0, 0);\n"
"}\n"
"QLineEdit:focus{\n"
"    border: 1px solid #348aff;\n"
"}\n"
"QLineEdit::placeholder{\n"
"    color: #888888;\n"
"}"));
        adminNewPwdEdit->setEchoMode(QLineEdit::Password);

        modifyFormGrid->addWidget(adminNewPwdEdit, 2, 1, 1, 2);

        adminConfirmPwdLabel = new QLabel(actionFormFrame);
        adminConfirmPwdLabel->setObjectName(QString::fromUtf8("adminConfirmPwdLabel"));
        adminConfirmPwdLabel->setMinimumSize(QSize(70, 36));
        adminConfirmPwdLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));

        modifyFormGrid->addWidget(adminConfirmPwdLabel, 3, 0, 1, 1);

        adminConfirmPwdEdit = new QLineEdit(actionFormFrame);
        adminConfirmPwdEdit->setObjectName(QString::fromUtf8("adminConfirmPwdEdit"));
        adminConfirmPwdEdit->setMinimumSize(QSize(0, 36));
        adminConfirmPwdEdit->setMaximumSize(QSize(16777215, 36));
        adminConfirmPwdEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 8px;\n"
"    padding: 6px 12px;\n"
"    font-size: 14px;\n"
"    color: rgb(0, 0, 0);\n"
"}\n"
"QLineEdit:focus{\n"
"    border: 1px solid #348aff;\n"
"}\n"
"QLineEdit::placeholder{\n"
"    color: #888888;\n"
"}"));
        adminConfirmPwdEdit->setEchoMode(QLineEdit::Password);

        modifyFormGrid->addWidget(adminConfirmPwdEdit, 3, 1, 1, 2);

        modifyButtonLayout = new QHBoxLayout();
        modifyButtonLayout->setSpacing(20);
        modifyButtonLayout->setObjectName(QString::fromUtf8("modifyButtonLayout"));
        modifyLeftSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        modifyButtonLayout->addItem(modifyLeftSpacer);

        saveModifyButton = new QPushButton(actionFormFrame);
        saveModifyButton->setObjectName(QString::fromUtf8("saveModifyButton"));
        saveModifyButton->setMinimumSize(QSize(100, 38));
        saveModifyButton->setMaximumSize(QSize(140, 38));
        saveModifyButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.248927 rgba(85, 116, 143, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    color: rgb(74, 85, 104);\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 6px;\n"
"    font-size: 14px;\n"
"    font: 63 9pt \"Bahnschrift SemiBold SemiConden\";\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    color: #1A3A6B;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    color: #1A3A6B;\n"
"    font-weight: bold;\n"
"}"));

        modifyButtonLayout->addWidget(saveModifyButton);

        resetModifyButton = new QPushButton(actionFormFrame);
        resetModifyButton->setObjectName(QString::fromUtf8("resetModifyButton"));
        resetModifyButton->setMinimumSize(QSize(100, 38));
        resetModifyButton->setMaximumSize(QSize(140, 38));
        resetModifyButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.248927 rgba(85, 116, 143, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    color: rgb(74, 85, 104);\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 6px;\n"
"    font-size: 14px;\n"
"    font: 63 9pt \"Bahnschrift SemiBold SemiConden\";\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    color: #1A3A6B;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    color: #1A3A6B;\n"
"    font-weight: bold;\n"
"}"));

        modifyButtonLayout->addWidget(resetModifyButton);

        modifyRightSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        modifyButtonLayout->addItem(modifyRightSpacer);


        modifyFormGrid->addLayout(modifyButtonLayout, 4, 0, 1, 3);


        actionVerticalLayout->addLayout(modifyFormGrid);


        topHorizontalLayout->addWidget(actionFormFrame);


        gridLayout->addLayout(topHorizontalLayout, 1, 0, 1, 1);


        retranslateUi(SetAdminWidge);

        QMetaObject::connectSlotsByName(SetAdminWidge);
    } // setupUi

    void retranslateUi(QWidget *SetAdminWidge)
    {
        SetAdminWidge->setWindowTitle(QApplication::translate("SetAdminWidge", "\347\256\241\347\220\206\345\221\230\350\256\276\347\275\256", nullptr));
        adminCountLabel->setText(QApplication::translate("SetAdminWidge", "\345\275\223\345\211\215\347\256\241\347\220\206\345\221\230\344\272\272\346\225\260\357\274\232----", nullptr));
        cardTitleLabel->setText(QApplication::translate("SetAdminWidge", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\347\256\241\347\220\206\345\221\230\350\264\246\346\210\267\347\256\241\347\220\206</span></p></body></html>", nullptr));
        cardLogoLabel->setText(QString());
        promptLabel->setText(QApplication::translate("SetAdminWidge", "<html><head/><body><p align=\"center\">\347\256\241\347\220\206\345\221\230\346\263\250\345\206\214\344\270\216\344\277\241\346\201\257\344\277\256\346\224\271</p></body></html>", nullptr));
        sectionRegisterLabel->setText(QApplication::translate("SetAdminWidge", "\347\256\241\347\220\206\345\221\230\346\263\250\345\206\214", nullptr));
        registerAdminButton->setText(QApplication::translate("SetAdminWidge", "\346\263\250\345\206\214\346\226\260\347\256\241\347\220\206\345\221\230", nullptr));
        sectionModifyLabel->setText(QApplication::translate("SetAdminWidge", "\347\256\241\347\220\206\345\221\230\344\277\241\346\201\257\344\277\256\346\224\271\357\274\210\347\202\271\345\207\273\350\241\250\346\240\274\350\241\214\351\200\211\346\213\251\357\274\211", nullptr));
        cardNumLabel->setText(QApplication::translate("SetAdminWidge", "\345\215\241\345\217\267", nullptr));
        adminCardEdit->setPlaceholderText(QApplication::translate("SetAdminWidge", "\347\202\271\345\207\273\350\241\250\346\240\274\350\241\214\351\200\211\346\213\251\346\210\226\345\210\267\345\215\241\345\275\225\345\205\245", nullptr));
        refreshCardButton->setText(QApplication::translate("SetAdminWidge", "\345\210\267\346\226\260\345\215\241\345\217\267", nullptr));
        adminNameLabel->setText(QApplication::translate("SetAdminWidge", "\347\224\250\346\210\267\345\220\215", nullptr));
        adminNameEdit->setPlaceholderText(QApplication::translate("SetAdminWidge", "\350\257\267\350\276\223\345\205\245\347\256\241\347\220\206\345\221\230\347\224\250\346\210\267\345\220\215", nullptr));
        adminNewPwdLabel->setText(QApplication::translate("SetAdminWidge", "\346\226\260\345\257\206\347\240\201", nullptr));
        adminNewPwdEdit->setPlaceholderText(QApplication::translate("SetAdminWidge", "\347\225\231\347\251\272\345\210\231\344\270\215\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        adminConfirmPwdLabel->setText(QApplication::translate("SetAdminWidge", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        adminConfirmPwdEdit->setPlaceholderText(QApplication::translate("SetAdminWidge", "\350\257\267\345\206\215\346\254\241\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201", nullptr));
        saveModifyButton->setText(QApplication::translate("SetAdminWidge", "\344\277\235\345\255\230\344\277\256\346\224\271", nullptr));
        resetModifyButton->setText(QApplication::translate("SetAdminWidge", "\351\207\215\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SetAdminWidge: public Ui_SetAdminWidge {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETADMINWIDGE_H
