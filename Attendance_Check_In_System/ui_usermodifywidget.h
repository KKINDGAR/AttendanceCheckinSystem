/********************************************************************************
** Form generated from reading UI file 'usermodifywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMODIFYWIDGET_H
#define UI_USERMODIFYWIDGET_H

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

class Ui_UserModifyWidget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *topHorizontalLayout;
    QFrame *cardFrame;
    QWidget *cardVerticalLayoutWidget;
    QVBoxLayout *cardVerticalLayout;
    QLabel *cardTitleLabel;
    QLabel *cardLogoLabel;
    QLabel *cardPromptLabel;
    QFrame *editFormFrame;
    QGridLayout *formGridLayout;
    QLabel *cardNumLabel;
    QLineEdit *cardNumEdit;
    QLabel *nameLabel;
    QLineEdit *nameEdit;
    QLabel *ageLabel;
    QSpinBox *ageSpinBox;
    QLabel *sexLabel;
    QComboBox *sexComboBox;
    QLabel *registerTimeLabel;
    QLineEdit *registerTimeEdit;
    QHBoxLayout *buttonHorizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *confirmModifyButton;
    QPushButton *resetButton;
    QPushButton *deleteEmployeeButton;
    QPushButton *captureFaceBtn;
    QPushButton *refrshUserTableButton;
    QSpacerItem *buttonHorizontalSpacer;
    QTableView *userInfoTableView;

    void setupUi(QWidget *UserModifyWidget)
    {
        if (UserModifyWidget->objectName().isEmpty())
            UserModifyWidget->setObjectName(QString::fromUtf8("UserModifyWidget"));
        UserModifyWidget->resize(1257, 960);
        UserModifyWidget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    font-family: \"Microsoft YaHei\", \"\345\276\256\350\275\257\351\233\205\351\273\221\", \"PingFang SC\", sans-serif;\n"
"    font-size: 14px;\n"
"    color: #2D3748;\n"
"	border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}\n"
"QWidget#UserModifyWidget{\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        gridLayout = new QGridLayout(UserModifyWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        topHorizontalLayout = new QHBoxLayout();
        topHorizontalLayout->setSpacing(20);
        topHorizontalLayout->setObjectName(QString::fromUtf8("topHorizontalLayout"));
        cardFrame = new QFrame(UserModifyWidget);
        cardFrame->setObjectName(QString::fromUtf8("cardFrame"));
        cardFrame->setMinimumSize(QSize(301, 340));
        cardFrame->setMaximumSize(QSize(301, 340));
        cardFrame->setStyleSheet(QString::fromUtf8("QFrame#cardFrame{\n"
"    background: transparent;\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        cardFrame->setFrameShape(QFrame::StyledPanel);
        cardFrame->setFrameShadow(QFrame::Raised);
        cardVerticalLayoutWidget = new QWidget(cardFrame);
        cardVerticalLayoutWidget->setObjectName(QString::fromUtf8("cardVerticalLayoutWidget"));
        cardVerticalLayoutWidget->setGeometry(QRect(0, 0, 301, 340));
        cardVerticalLayout = new QVBoxLayout(cardVerticalLayoutWidget);
        cardVerticalLayout->setSpacing(10);
        cardVerticalLayout->setObjectName(QString::fromUtf8("cardVerticalLayout"));
        cardVerticalLayout->setContentsMargins(10, 10, 10, 10);
        cardTitleLabel = new QLabel(cardVerticalLayoutWidget);
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

        cardLogoLabel = new QLabel(cardVerticalLayoutWidget);
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

        cardPromptLabel = new QLabel(cardVerticalLayoutWidget);
        cardPromptLabel->setObjectName(QString::fromUtf8("cardPromptLabel"));
        cardPromptLabel->setMinimumSize(QSize(151, 20));
        cardPromptLabel->setMaximumSize(QSize(280, 20));
        cardPromptLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    background:transparent;\n"
"}"));

        cardVerticalLayout->addWidget(cardPromptLabel);


        topHorizontalLayout->addWidget(cardFrame);

        editFormFrame = new QFrame(UserModifyWidget);
        editFormFrame->setObjectName(QString::fromUtf8("editFormFrame"));
        editFormFrame->setMinimumSize(QSize(0, 340));
        editFormFrame->setStyleSheet(QString::fromUtf8("QFrame#editFormFrame{\n"
"    background: transparent;\n"
"	border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        editFormFrame->setFrameShape(QFrame::StyledPanel);
        editFormFrame->setFrameShadow(QFrame::Raised);
        formGridLayout = new QGridLayout(editFormFrame);
        formGridLayout->setSpacing(15);
        formGridLayout->setObjectName(QString::fromUtf8("formGridLayout"));
        formGridLayout->setContentsMargins(20, 10, 20, 10);
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

        cardNumEdit = new QLineEdit(editFormFrame);
        cardNumEdit->setObjectName(QString::fromUtf8("cardNumEdit"));
        cardNumEdit->setMinimumSize(QSize(0, 41));
        cardNumEdit->setMaximumSize(QSize(400, 41));
        cardNumEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
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
        cardNumEdit->setReadOnly(false);

        formGridLayout->addWidget(cardNumEdit, 0, 1, 1, 1);

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

        registerTimeLabel = new QLabel(editFormFrame);
        registerTimeLabel->setObjectName(QString::fromUtf8("registerTimeLabel"));
        registerTimeLabel->setMinimumSize(QSize(80, 41));
        registerTimeLabel->setMaximumSize(QSize(100, 41));
        registerTimeLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    qproperty-alignment: AlignCenter;\n"
"    background:transparent;\n"
"}"));

        formGridLayout->addWidget(registerTimeLabel, 4, 0, 1, 1);

        registerTimeEdit = new QLineEdit(editFormFrame);
        registerTimeEdit->setObjectName(QString::fromUtf8("registerTimeEdit"));
        registerTimeEdit->setMinimumSize(QSize(0, 41));
        registerTimeEdit->setMaximumSize(QSize(400, 41));
        registerTimeEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
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
        registerTimeEdit->setReadOnly(true);

        formGridLayout->addWidget(registerTimeEdit, 4, 1, 1, 1);

        buttonHorizontalLayout = new QHBoxLayout();
        buttonHorizontalLayout->setSpacing(20);
        buttonHorizontalLayout->setObjectName(QString::fromUtf8("buttonHorizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonHorizontalLayout->addItem(horizontalSpacer);

        confirmModifyButton = new QPushButton(editFormFrame);
        confirmModifyButton->setObjectName(QString::fromUtf8("confirmModifyButton"));
        confirmModifyButton->setMinimumSize(QSize(120, 44));
        confirmModifyButton->setMaximumSize(QSize(160, 48));
        confirmModifyButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        buttonHorizontalLayout->addWidget(confirmModifyButton);

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

        deleteEmployeeButton = new QPushButton(editFormFrame);
        deleteEmployeeButton->setObjectName(QString::fromUtf8("deleteEmployeeButton"));
        deleteEmployeeButton->setMinimumSize(QSize(120, 44));
        deleteEmployeeButton->setMaximumSize(QSize(160, 48));
        deleteEmployeeButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        buttonHorizontalLayout->addWidget(deleteEmployeeButton);

        captureFaceBtn = new QPushButton(editFormFrame);
        captureFaceBtn->setObjectName(QString::fromUtf8("captureFaceBtn"));
        captureFaceBtn->setMinimumSize(QSize(120, 44));
        captureFaceBtn->setMaximumSize(QSize(160, 48));
        captureFaceBtn->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        buttonHorizontalLayout->addWidget(captureFaceBtn);

        refrshUserTableButton = new QPushButton(editFormFrame);
        refrshUserTableButton->setObjectName(QString::fromUtf8("refrshUserTableButton"));
        refrshUserTableButton->setMinimumSize(QSize(120, 44));
        refrshUserTableButton->setMaximumSize(QSize(160, 48));
        refrshUserTableButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        buttonHorizontalLayout->addWidget(refrshUserTableButton);

        buttonHorizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonHorizontalLayout->addItem(buttonHorizontalSpacer);


        formGridLayout->addLayout(buttonHorizontalLayout, 5, 0, 1, 2);


        topHorizontalLayout->addWidget(editFormFrame);


        gridLayout->addLayout(topHorizontalLayout, 0, 0, 1, 1);

        userInfoTableView = new QTableView(UserModifyWidget);
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

        gridLayout->addWidget(userInfoTableView, 1, 0, 1, 1);


        retranslateUi(UserModifyWidget);

        QMetaObject::connectSlotsByName(UserModifyWidget);
    } // setupUi

    void retranslateUi(QWidget *UserModifyWidget)
    {
        UserModifyWidget->setWindowTitle(QApplication::translate("UserModifyWidget", "Form", nullptr));
        cardTitleLabel->setText(QApplication::translate("UserModifyWidget", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\345\221\230\345\267\245\344\277\241\346\201\257\344\277\256\346\224\271</span></p></body></html>", nullptr));
        cardLogoLabel->setText(QString());
        cardPromptLabel->setText(QApplication::translate("UserModifyWidget", "<html><head/><body><p align=\"center\">\345\210\267\345\215\241\350\257\273\345\217\226\345\221\230\345\267\245\344\277\241\346\201\257</p></body></html>", nullptr));
        cardNumLabel->setText(QApplication::translate("UserModifyWidget", "\345\215\241\345\217\267", nullptr));
        cardNumEdit->setPlaceholderText(QApplication::translate("UserModifyWidget", "\350\257\267\350\276\223\345\205\245\346\210\226\345\210\267\345\215\241\345\275\225\345\205\245\345\215\241\345\217\267", nullptr));
        nameLabel->setText(QApplication::translate("UserModifyWidget", "\345\247\223\345\220\215", nullptr));
        nameEdit->setPlaceholderText(QApplication::translate("UserModifyWidget", "\350\257\267\350\276\223\345\205\245\345\221\230\345\267\245\345\247\223\345\220\215", nullptr));
        ageLabel->setText(QApplication::translate("UserModifyWidget", "\345\271\264\351\276\204", nullptr));
        sexLabel->setText(QApplication::translate("UserModifyWidget", "\346\200\247\345\210\253", nullptr));
        sexComboBox->setItemText(0, QApplication::translate("UserModifyWidget", "\347\224\267", nullptr));
        sexComboBox->setItemText(1, QApplication::translate("UserModifyWidget", "\345\245\263", nullptr));

        registerTimeLabel->setText(QApplication::translate("UserModifyWidget", "\346\263\250\345\206\214\346\227\266\351\227\264", nullptr));
        registerTimeEdit->setPlaceholderText(QApplication::translate("UserModifyWidget", "\350\207\252\345\212\250\350\216\267\345\217\226\346\263\250\345\206\214\346\227\266\351\227\264", nullptr));
        confirmModifyButton->setText(QApplication::translate("UserModifyWidget", "\347\241\256\350\256\244\344\277\256\346\224\271", nullptr));
        resetButton->setText(QApplication::translate("UserModifyWidget", "\351\207\215\347\275\256", nullptr));
        deleteEmployeeButton->setText(QApplication::translate("UserModifyWidget", "\345\210\240\351\231\244\345\221\230\345\267\245", nullptr));
        captureFaceBtn->setText(QApplication::translate("UserModifyWidget", "\344\272\272\350\204\270\350\241\245\345\275\225", nullptr));
        refrshUserTableButton->setText(QApplication::translate("UserModifyWidget", "\345\210\267\346\226\260\345\221\230\345\267\245\350\241\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserModifyWidget: public Ui_UserModifyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMODIFYWIDGET_H
