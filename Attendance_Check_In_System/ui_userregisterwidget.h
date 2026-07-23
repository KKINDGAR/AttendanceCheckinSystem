/********************************************************************************
** Form generated from reading UI file 'userregisterwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERREGISTERWIDGET_H
#define UI_USERREGISTERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserRegisterWidget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *headerLayout;
    QSpacerItem *headerLeftSpacer;
    QLabel *label;
    QHBoxLayout *topHorizontalLayout;
    QFrame *registerMainCard;
    QVBoxLayout *cardVerticalLayout;
    QLabel *cardTitleLabel;
    QLabel *cardLogoLabel;
    QLabel *promptLabel;
    QFrame *editFormFrame;
    QGridLayout *formGridLayout;
    QSpinBox *ageSpinBox;
    QLineEdit *nameEdit;
    QLabel *cardNumLabel;
    QHBoxLayout *cardNumInputLayout;
    QLineEdit *cardNumLineEdit;
    QPushButton *refreshCardNummButton;
    QPushButton *clearCardNumButton;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *sexComboBox;
    QLabel *nameLabel;
    QLabel *ageLabel;
    QLabel *sexLabel;
    QHBoxLayout *buttonHorizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *saveButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *resetButton;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *refrshRegistTableButton;
    QSpacerItem *buttonHorizontalSpacer;
    QTableView *userInfoTableView;

    void setupUi(QWidget *UserRegisterWidget)
    {
        if (UserRegisterWidget->objectName().isEmpty())
            UserRegisterWidget->setObjectName(QString::fromUtf8("UserRegisterWidget"));
        UserRegisterWidget->resize(1301, 831);
        UserRegisterWidget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    font-family: \"Microsoft YaHei\", \"\345\276\256\350\275\257\351\233\205\351\273\221\", \"PingFang SC\", sans-serif;\n"
"    font-size: 14px;\n"
"    color: #2D3748;\n"
"	    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}\n"
"QWidget#UserRegisterWidget{\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        gridLayout = new QGridLayout(UserRegisterWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        headerLayout = new QHBoxLayout();
        headerLayout->setObjectName(QString::fromUtf8("headerLayout"));
        headerLeftSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        headerLayout->addItem(headerLeftSpacer);

        label = new QLabel(UserRegisterWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 30));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));

        headerLayout->addWidget(label);


        gridLayout->addLayout(headerLayout, 0, 0, 1, 1);

        topHorizontalLayout = new QHBoxLayout();
        topHorizontalLayout->setSpacing(20);
        topHorizontalLayout->setObjectName(QString::fromUtf8("topHorizontalLayout"));
        registerMainCard = new QFrame(UserRegisterWidget);
        registerMainCard->setObjectName(QString::fromUtf8("registerMainCard"));
        registerMainCard->setMinimumSize(QSize(301, 340));
        registerMainCard->setMaximumSize(QSize(301, 373));
        registerMainCard->setStyleSheet(QString::fromUtf8("QFrame#registerMainCard{\n"
"    background: transparent;\n"
"	border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        registerMainCard->setFrameShape(QFrame::StyledPanel);
        registerMainCard->setFrameShadow(QFrame::Raised);
        cardVerticalLayout = new QVBoxLayout(registerMainCard);
        cardVerticalLayout->setSpacing(10);
        cardVerticalLayout->setObjectName(QString::fromUtf8("cardVerticalLayout"));
        cardVerticalLayout->setContentsMargins(10, 10, 10, 10);
        cardTitleLabel = new QLabel(registerMainCard);
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

        cardLogoLabel = new QLabel(registerMainCard);
        cardLogoLabel->setObjectName(QString::fromUtf8("cardLogoLabel"));
        cardLogoLabel->setMinimumSize(QSize(261, 171));
        cardLogoLabel->setMaximumSize(QSize(280, 171));
        cardLogoLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    background:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        cardLogoLabel->setPixmap(QPixmap(QString::fromUtf8(":/image/ICcard.png")));
        cardLogoLabel->setScaledContents(true);

        cardVerticalLayout->addWidget(cardLogoLabel);

        promptLabel = new QLabel(registerMainCard);
        promptLabel->setObjectName(QString::fromUtf8("promptLabel"));
        promptLabel->setMinimumSize(QSize(151, 20));
        promptLabel->setMaximumSize(QSize(280, 20));
        promptLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    background:transparent;\n"
"}"));

        cardVerticalLayout->addWidget(promptLabel);


        topHorizontalLayout->addWidget(registerMainCard);

        editFormFrame = new QFrame(UserRegisterWidget);
        editFormFrame->setObjectName(QString::fromUtf8("editFormFrame"));
        editFormFrame->setMinimumSize(QSize(0, 340));
        editFormFrame->setStyleSheet(QString::fromUtf8("QFrame#editFormFrame{\n"
"    background: transparent;\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        editFormFrame->setFrameShape(QFrame::StyledPanel);
        editFormFrame->setFrameShadow(QFrame::Raised);
        formGridLayout = new QGridLayout(editFormFrame);
        formGridLayout->setSpacing(12);
        formGridLayout->setObjectName(QString::fromUtf8("formGridLayout"));
        formGridLayout->setContentsMargins(20, 10, 20, 10);
        ageSpinBox = new QSpinBox(editFormFrame);
        ageSpinBox->setObjectName(QString::fromUtf8("ageSpinBox"));
        ageSpinBox->setMinimumSize(QSize(0, 41));
        ageSpinBox->setMaximumSize(QSize(400, 41));
        ageSpinBox->setStyleSheet(QString::fromUtf8("QSpinBox{\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 10px;\n"
"    padding: 8px 14px;\n"
"    font-size: 15px;\n"
"    color: rgb(0, 0, 0);\n"
"}\n"
"QSpinBox:focus{\n"
"    border: 1px solid #348aff;\n"
"}"));
        ageSpinBox->setMinimum(0);
        ageSpinBox->setMaximum(100);

        formGridLayout->addWidget(ageSpinBox, 2, 1, 1, 1);

        nameEdit = new QLineEdit(editFormFrame);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setMinimumSize(QSize(0, 41));
        nameEdit->setMaximumSize(QSize(400, 41));
        nameEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 10px;\n"
"    padding: 11px 14px;\n"
"    font-size: 15px;\n"
"    color: rgb(0, 0, 0);\n"
"}\n"
"QLineEdit:focus{\n"
"    border: 1px solid #348aff;\n"
"}\n"
"QLineEdit::placeholder{\n"
"    color: #888888;\n"
"}"));

        formGridLayout->addWidget(nameEdit, 1, 1, 1, 1);

        cardNumLabel = new QLabel(editFormFrame);
        cardNumLabel->setObjectName(QString::fromUtf8("cardNumLabel"));
        cardNumLabel->setMinimumSize(QSize(80, 41));
        cardNumLabel->setMaximumSize(QSize(100, 41));
        cardNumLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    qproperty-alignment: AlignCenter;\n"
"    background:transparent;\n"
"}"));

        formGridLayout->addWidget(cardNumLabel, 0, 0, 1, 1);

        cardNumInputLayout = new QHBoxLayout();
        cardNumInputLayout->setSpacing(10);
        cardNumInputLayout->setObjectName(QString::fromUtf8("cardNumInputLayout"));
        cardNumLineEdit = new QLineEdit(editFormFrame);
        cardNumLineEdit->setObjectName(QString::fromUtf8("cardNumLineEdit"));
        cardNumLineEdit->setMinimumSize(QSize(400, 41));
        cardNumLineEdit->setMaximumSize(QSize(400, 41));
        cardNumLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 10px;\n"
"    padding: 11px 14px;\n"
"    font-size: 15px;\n"
"    color: rgb(0, 0, 0);\n"
"}\n"
"QLineEdit:focus{\n"
"    border: 1px solid #348aff;\n"
"}\n"
"QLineEdit::placeholder{\n"
"    color: #888888;\n"
"}"));
        cardNumLineEdit->setReadOnly(true);

        cardNumInputLayout->addWidget(cardNumLineEdit);

        refreshCardNummButton = new QPushButton(editFormFrame);
        refreshCardNummButton->setObjectName(QString::fromUtf8("refreshCardNummButton"));
        refreshCardNummButton->setMinimumSize(QSize(100, 41));
        refreshCardNummButton->setMaximumSize(QSize(100, 41));
        refreshCardNummButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        cardNumInputLayout->addWidget(refreshCardNummButton);

        clearCardNumButton = new QPushButton(editFormFrame);
        clearCardNumButton->setObjectName(QString::fromUtf8("clearCardNumButton"));
        clearCardNumButton->setMinimumSize(QSize(100, 41));
        clearCardNumButton->setMaximumSize(QSize(100, 41));
        clearCardNumButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        cardNumInputLayout->addWidget(clearCardNumButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        cardNumInputLayout->addItem(horizontalSpacer_3);


        formGridLayout->addLayout(cardNumInputLayout, 0, 1, 1, 1);

        sexComboBox = new QComboBox(editFormFrame);
        sexComboBox->addItem(QString());
        sexComboBox->addItem(QString());
        sexComboBox->setObjectName(QString::fromUtf8("sexComboBox"));
        sexComboBox->setMinimumSize(QSize(0, 41));
        sexComboBox->setMaximumSize(QSize(400, 41));
        sexComboBox->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 10px;\n"
"    padding: 8px 14px;\n"
"    font-size: 15px;\n"
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
"    border-top-right-radius: 10px;\n"
"    border-bottom-right-radius: 10px;\n"
"}"));

        formGridLayout->addWidget(sexComboBox, 3, 1, 1, 1);

        nameLabel = new QLabel(editFormFrame);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setMinimumSize(QSize(80, 41));
        nameLabel->setMaximumSize(QSize(100, 41));
        nameLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    qproperty-alignment: AlignCenter;\n"
"    background:transparent;\n"
"}"));

        formGridLayout->addWidget(nameLabel, 1, 0, 1, 1);

        ageLabel = new QLabel(editFormFrame);
        ageLabel->setObjectName(QString::fromUtf8("ageLabel"));
        ageLabel->setMinimumSize(QSize(80, 41));
        ageLabel->setMaximumSize(QSize(100, 41));
        ageLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    qproperty-alignment: AlignCenter;\n"
"    background:transparent;\n"
"}"));

        formGridLayout->addWidget(ageLabel, 2, 0, 1, 1);

        sexLabel = new QLabel(editFormFrame);
        sexLabel->setObjectName(QString::fromUtf8("sexLabel"));
        sexLabel->setMinimumSize(QSize(80, 41));
        sexLabel->setMaximumSize(QSize(100, 41));
        sexLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    qproperty-alignment: AlignCenter;\n"
"    background:transparent;\n"
"}"));

        formGridLayout->addWidget(sexLabel, 3, 0, 1, 1);

        buttonHorizontalLayout = new QHBoxLayout();
        buttonHorizontalLayout->setSpacing(20);
        buttonHorizontalLayout->setObjectName(QString::fromUtf8("buttonHorizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonHorizontalLayout->addItem(horizontalSpacer);

        saveButton = new QPushButton(editFormFrame);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setMinimumSize(QSize(120, 44));
        saveButton->setMaximumSize(QSize(160, 48));
        saveButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        buttonHorizontalLayout->addWidget(saveButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonHorizontalLayout->addItem(horizontalSpacer_2);

        resetButton = new QPushButton(editFormFrame);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setMinimumSize(QSize(120, 44));
        resetButton->setMaximumSize(QSize(160, 48));
        resetButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        buttonHorizontalLayout->addWidget(resetButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonHorizontalLayout->addItem(horizontalSpacer_4);

        refrshRegistTableButton = new QPushButton(editFormFrame);
        refrshRegistTableButton->setObjectName(QString::fromUtf8("refrshRegistTableButton"));
        refrshRegistTableButton->setMinimumSize(QSize(120, 44));
        refrshRegistTableButton->setMaximumSize(QSize(160, 48));
        refrshRegistTableButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        buttonHorizontalLayout->addWidget(refrshRegistTableButton);

        buttonHorizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonHorizontalLayout->addItem(buttonHorizontalSpacer);


        formGridLayout->addLayout(buttonHorizontalLayout, 4, 0, 1, 2);


        topHorizontalLayout->addWidget(editFormFrame);


        gridLayout->addLayout(topHorizontalLayout, 1, 0, 1, 1);

        userInfoTableView = new QTableView(UserRegisterWidget);
        userInfoTableView->setObjectName(QString::fromUtf8("userInfoTableView"));
        userInfoTableView->setStyleSheet(QString::fromUtf8("QTableView{\n"
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
        userInfoTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        userInfoTableView->setAlternatingRowColors(true);
        userInfoTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        gridLayout->addWidget(userInfoTableView, 2, 0, 1, 1);


        retranslateUi(UserRegisterWidget);

        QMetaObject::connectSlotsByName(UserRegisterWidget);
    } // setupUi

    void retranslateUi(QWidget *UserRegisterWidget)
    {
        UserRegisterWidget->setWindowTitle(QApplication::translate("UserRegisterWidget", "Form", nullptr));
        label->setText(QApplication::translate("UserRegisterWidget", "\345\275\223\345\211\215\346\263\250\345\206\214\344\272\272\346\225\260\357\274\232----", nullptr));
        cardTitleLabel->setText(QApplication::translate("UserRegisterWidget", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\345\221\230\345\267\245IC\345\215\241\346\263\250\345\206\214</span></p></body></html>", nullptr));
        cardLogoLabel->setText(QString());
        promptLabel->setText(QApplication::translate("UserRegisterWidget", "<html><head/><body><p align=\"center\">\345\210\267\345\215\241\350\207\252\345\212\250\350\257\273\345\217\226\345\215\241\345\217\267</p></body></html>", nullptr));
        nameEdit->setPlaceholderText(QApplication::translate("UserRegisterWidget", "\350\257\267\350\276\223\345\205\245\345\221\230\345\267\245\345\247\223\345\220\215", nullptr));
        cardNumLabel->setText(QApplication::translate("UserRegisterWidget", "\345\215\241\345\217\267", nullptr));
        cardNumLineEdit->setPlaceholderText(QApplication::translate("UserRegisterWidget", "\345\210\267\345\215\241\350\207\252\345\212\250\350\257\273\345\217\226\345\215\241\345\217\267", nullptr));
        refreshCardNummButton->setText(QApplication::translate("UserRegisterWidget", "\345\210\267\346\226\260\345\215\241\345\217\267", nullptr));
        clearCardNumButton->setText(QApplication::translate("UserRegisterWidget", "\346\270\205\347\251\272\345\215\241\345\217\267", nullptr));
        sexComboBox->setItemText(0, QApplication::translate("UserRegisterWidget", "\347\224\267", nullptr));
        sexComboBox->setItemText(1, QApplication::translate("UserRegisterWidget", "\345\245\263", nullptr));

        nameLabel->setText(QApplication::translate("UserRegisterWidget", "\345\247\223\345\220\215", nullptr));
        ageLabel->setText(QApplication::translate("UserRegisterWidget", "\345\271\264\351\276\204", nullptr));
        sexLabel->setText(QApplication::translate("UserRegisterWidget", "\346\200\247\345\210\253", nullptr));
        saveButton->setText(QApplication::translate("UserRegisterWidget", "\344\277\235\345\255\230", nullptr));
        resetButton->setText(QApplication::translate("UserRegisterWidget", "\351\207\215\347\275\256", nullptr));
        refrshRegistTableButton->setText(QApplication::translate("UserRegisterWidget", "\345\210\267\346\226\260\346\263\250\345\206\214\350\241\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserRegisterWidget: public Ui_UserRegisterWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERREGISTERWIDGET_H
