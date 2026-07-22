/********************************************************************************
** Form generated from reading UI file 'rechargeanddeductionwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECHARGEANDDEDUCTIONWIDGET_H
#define UI_RECHARGEANDDEDUCTIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RechargeAndDeductionWidget
{
public:
    QVBoxLayout *mainVerticalLayout;
    QHBoxLayout *topHorizontalLayout;
    QFrame *cardFrame;
    QWidget *cardVerticalLayoutWidget;
    QVBoxLayout *cardVerticalLayout;
    QLabel *cardTitleLabel;
    QLabel *cardLogoLabel;
    QLabel *cardPromptLabel;
    QFrame *editFormFrame;
    QGridLayout *formGridLayout;
    QLineEdit *cardNumEdit;
    QLabel *nameLabel;
    QLabel *amountLabel;
    QLabel *balanceLabel;
    QHBoxLayout *amountHorizontalLayout;
    QDoubleSpinBox *amountSpinBox;
    QLabel *amountUnitLabel;
    QLabel *remarkLabel;
    QHBoxLayout *buttonHorizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *confirmButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *resetButton;
    QSpacerItem *buttonHorizontalSpacer;
    QLineEdit *nameEdit;
    QHBoxLayout *typeHorizontalLayout;
    QRadioButton *rechargeRadioButton;
    QRadioButton *deductionRadioButton;
    QLineEdit *remarkEdit;
    QLineEdit *balanceEdit;
    QLabel *typeLabel;
    QLabel *cardNumLabel;
    QTableView *transactionTableView;

    void setupUi(QWidget *RechargeAndDeductionWidget)
    {
        if (RechargeAndDeductionWidget->objectName().isEmpty())
            RechargeAndDeductionWidget->setObjectName(QString::fromUtf8("RechargeAndDeductionWidget"));
        RechargeAndDeductionWidget->resize(1301, 831);
        RechargeAndDeductionWidget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    font-family: \"Microsoft YaHei\", \"\345\276\256\350\275\257\351\233\205\351\273\221\", \"PingFang SC\", sans-serif;\n"
"    font-size: 14px;\n"
"    color: #2D3748;\n"
"}\n"
"QWidget#RechargeAndDeductionWidget{\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        mainVerticalLayout = new QVBoxLayout(RechargeAndDeductionWidget);
        mainVerticalLayout->setSpacing(15);
        mainVerticalLayout->setObjectName(QString::fromUtf8("mainVerticalLayout"));
        mainVerticalLayout->setContentsMargins(10, 10, 10, 10);
        topHorizontalLayout = new QHBoxLayout();
        topHorizontalLayout->setSpacing(20);
        topHorizontalLayout->setObjectName(QString::fromUtf8("topHorizontalLayout"));
        cardFrame = new QFrame(RechargeAndDeductionWidget);
        cardFrame->setObjectName(QString::fromUtf8("cardFrame"));
        cardFrame->setMinimumSize(QSize(301, 320));
        cardFrame->setMaximumSize(QSize(301, 390));
        cardFrame->setStyleSheet(QString::fromUtf8("QFrame#cardFrame{\n"
"    background: transparent;\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        cardFrame->setFrameShape(QFrame::StyledPanel);
        cardFrame->setFrameShadow(QFrame::Raised);
        cardVerticalLayoutWidget = new QWidget(cardFrame);
        cardVerticalLayoutWidget->setObjectName(QString::fromUtf8("cardVerticalLayoutWidget"));
        cardVerticalLayoutWidget->setGeometry(QRect(0, 0, 301, 391));
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

        editFormFrame = new QFrame(RechargeAndDeductionWidget);
        editFormFrame->setObjectName(QString::fromUtf8("editFormFrame"));
        editFormFrame->setMinimumSize(QSize(0, 320));
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
        cardNumEdit->setReadOnly(true);

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

        amountLabel = new QLabel(editFormFrame);
        amountLabel->setObjectName(QString::fromUtf8("amountLabel"));
        amountLabel->setMinimumSize(QSize(80, 41));
        amountLabel->setMaximumSize(QSize(100, 41));
        amountLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    qproperty-alignment: AlignCenter;\n"
"    background:transparent;\n"
"}"));

        formGridLayout->addWidget(amountLabel, 4, 0, 1, 1);

        balanceLabel = new QLabel(editFormFrame);
        balanceLabel->setObjectName(QString::fromUtf8("balanceLabel"));
        balanceLabel->setMinimumSize(QSize(80, 41));
        balanceLabel->setMaximumSize(QSize(100, 41));
        balanceLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    qproperty-alignment: AlignCenter;\n"
"    background:transparent;\n"
"}"));

        formGridLayout->addWidget(balanceLabel, 2, 0, 1, 1);

        amountHorizontalLayout = new QHBoxLayout();
        amountHorizontalLayout->setSpacing(10);
        amountHorizontalLayout->setObjectName(QString::fromUtf8("amountHorizontalLayout"));
        amountSpinBox = new QDoubleSpinBox(editFormFrame);
        amountSpinBox->setObjectName(QString::fromUtf8("amountSpinBox"));
        amountSpinBox->setMinimumSize(QSize(200, 41));
        amountSpinBox->setMaximumSize(QSize(250, 41));
        amountSpinBox->setStyleSheet(QString::fromUtf8("QDoubleSpinBox{\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 10px;\n"
"    padding: 8px 14px;\n"
"    font-size: 15px;\n"
"    color: rgb(0, 0, 0);\n"
"}\n"
"QDoubleSpinBox:focus{\n"
"    border: 1px solid #348aff;\n"
"}"));
        amountSpinBox->setDecimals(2);
        amountSpinBox->setMinimum(0.000000000000000);
        amountSpinBox->setMaximum(999999.989999999990687);

        amountHorizontalLayout->addWidget(amountSpinBox);

        amountUnitLabel = new QLabel(editFormFrame);
        amountUnitLabel->setObjectName(QString::fromUtf8("amountUnitLabel"));
        amountUnitLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 14px;\n"
"    color: #666666;\n"
"    background:transparent;\n"
"}"));

        amountHorizontalLayout->addWidget(amountUnitLabel);


        formGridLayout->addLayout(amountHorizontalLayout, 4, 1, 1, 1);

        remarkLabel = new QLabel(editFormFrame);
        remarkLabel->setObjectName(QString::fromUtf8("remarkLabel"));
        remarkLabel->setMinimumSize(QSize(80, 41));
        remarkLabel->setMaximumSize(QSize(100, 41));
        remarkLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    qproperty-alignment: AlignCenter;\n"
"    background:transparent;\n"
"}"));

        formGridLayout->addWidget(remarkLabel, 5, 0, 1, 1);

        buttonHorizontalLayout = new QHBoxLayout();
        buttonHorizontalLayout->setSpacing(20);
        buttonHorizontalLayout->setObjectName(QString::fromUtf8("buttonHorizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonHorizontalLayout->addItem(horizontalSpacer);

        confirmButton = new QPushButton(editFormFrame);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        confirmButton->setMinimumSize(QSize(120, 44));
        confirmButton->setMaximumSize(QSize(160, 48));
        confirmButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        buttonHorizontalLayout->addWidget(confirmButton);

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

        buttonHorizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonHorizontalLayout->addItem(buttonHorizontalSpacer);


        formGridLayout->addLayout(buttonHorizontalLayout, 6, 0, 1, 2);

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
        nameEdit->setReadOnly(true);

        formGridLayout->addWidget(nameEdit, 1, 1, 1, 1);

        typeHorizontalLayout = new QHBoxLayout();
        typeHorizontalLayout->setSpacing(40);
        typeHorizontalLayout->setObjectName(QString::fromUtf8("typeHorizontalLayout"));
        rechargeRadioButton = new QRadioButton(editFormFrame);
        rechargeRadioButton->setObjectName(QString::fromUtf8("rechargeRadioButton"));
        rechargeRadioButton->setMinimumSize(QSize(80, 36));
        rechargeRadioButton->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"    font-size: 15px;\n"
"    color: #1A3A6B;\n"
"    font-weight: bold;\n"
"    background: transparent;\n"
"}\n"
"QRadioButton::indicator{\n"
"    width: 18px;\n"
"    height: 18px;\n"
"}"));
        rechargeRadioButton->setChecked(true);

        typeHorizontalLayout->addWidget(rechargeRadioButton);

        deductionRadioButton = new QRadioButton(editFormFrame);
        deductionRadioButton->setObjectName(QString::fromUtf8("deductionRadioButton"));
        deductionRadioButton->setMinimumSize(QSize(80, 36));
        deductionRadioButton->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"    font-size: 15px;\n"
"    color: #C0392B;\n"
"    font-weight: bold;\n"
"    background: transparent;\n"
"}\n"
"QRadioButton::indicator{\n"
"    width: 18px;\n"
"    height: 18px;\n"
"}"));

        typeHorizontalLayout->addWidget(deductionRadioButton);


        formGridLayout->addLayout(typeHorizontalLayout, 3, 1, 1, 1);

        remarkEdit = new QLineEdit(editFormFrame);
        remarkEdit->setObjectName(QString::fromUtf8("remarkEdit"));
        remarkEdit->setMinimumSize(QSize(0, 41));
        remarkEdit->setMaximumSize(QSize(400, 41));
        remarkEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
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

        formGridLayout->addWidget(remarkEdit, 5, 1, 1, 1);

        balanceEdit = new QLineEdit(editFormFrame);
        balanceEdit->setObjectName(QString::fromUtf8("balanceEdit"));
        balanceEdit->setMinimumSize(QSize(0, 41));
        balanceEdit->setMaximumSize(QSize(400, 41));
        balanceEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
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
        balanceEdit->setReadOnly(true);

        formGridLayout->addWidget(balanceEdit, 2, 1, 1, 1);

        typeLabel = new QLabel(editFormFrame);
        typeLabel->setObjectName(QString::fromUtf8("typeLabel"));
        typeLabel->setMinimumSize(QSize(80, 41));
        typeLabel->setMaximumSize(QSize(100, 41));
        typeLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    qproperty-alignment: AlignCenter;\n"
"    background:transparent;\n"
"}"));

        formGridLayout->addWidget(typeLabel, 3, 0, 1, 1);

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


        topHorizontalLayout->addWidget(editFormFrame);


        mainVerticalLayout->addLayout(topHorizontalLayout);

        transactionTableView = new QTableView(RechargeAndDeductionWidget);
        transactionTableView->setObjectName(QString::fromUtf8("transactionTableView"));
        transactionTableView->setStyleSheet(QString::fromUtf8("QTableView{\n"
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
        transactionTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        transactionTableView->setAlternatingRowColors(true);
        transactionTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        mainVerticalLayout->addWidget(transactionTableView);


        retranslateUi(RechargeAndDeductionWidget);

        QMetaObject::connectSlotsByName(RechargeAndDeductionWidget);
    } // setupUi

    void retranslateUi(QWidget *RechargeAndDeductionWidget)
    {
        RechargeAndDeductionWidget->setWindowTitle(QApplication::translate("RechargeAndDeductionWidget", "Form", nullptr));
        cardTitleLabel->setText(QApplication::translate("RechargeAndDeductionWidget", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\345\205\205\345\200\274 / \346\211\243\346\254\276</span></p></body></html>", nullptr));
        cardLogoLabel->setText(QString());
        cardPromptLabel->setText(QApplication::translate("RechargeAndDeductionWidget", "<html><head/><body><p align=\"center\">\345\210\267\345\215\241\350\257\273\345\217\226\345\221\230\345\267\245\344\277\241\346\201\257</p></body></html>", nullptr));
        cardNumEdit->setPlaceholderText(QApplication::translate("RechargeAndDeductionWidget", "\345\210\267\345\215\241\350\207\252\345\212\250\350\257\273\345\217\226\345\215\241\345\217\267", nullptr));
        nameLabel->setText(QApplication::translate("RechargeAndDeductionWidget", "\345\247\223\345\220\215", nullptr));
        amountLabel->setText(QApplication::translate("RechargeAndDeductionWidget", "\351\207\221\351\242\235", nullptr));
        balanceLabel->setText(QApplication::translate("RechargeAndDeductionWidget", "\345\275\223\345\211\215\344\275\231\351\242\235", nullptr));
        amountSpinBox->setPrefix(QApplication::translate("RechargeAndDeductionWidget", "\302\245 ", nullptr));
        amountUnitLabel->setText(QApplication::translate("RechargeAndDeductionWidget", "\345\205\203", nullptr));
        remarkLabel->setText(QApplication::translate("RechargeAndDeductionWidget", "\345\244\207\346\263\250", nullptr));
        confirmButton->setText(QApplication::translate("RechargeAndDeductionWidget", "\347\241\256\350\256\244", nullptr));
        resetButton->setText(QApplication::translate("RechargeAndDeductionWidget", "\351\207\215\347\275\256", nullptr));
        nameEdit->setPlaceholderText(QApplication::translate("RechargeAndDeductionWidget", "\350\207\252\345\212\250\345\233\236\345\241\253", nullptr));
        rechargeRadioButton->setText(QApplication::translate("RechargeAndDeductionWidget", "\345\205\205\345\200\274", nullptr));
        deductionRadioButton->setText(QApplication::translate("RechargeAndDeductionWidget", "\346\211\243\346\254\276", nullptr));
        remarkEdit->setPlaceholderText(QApplication::translate("RechargeAndDeductionWidget", "\345\217\257\345\241\253\345\206\231\345\244\207\346\263\250\344\277\241\346\201\257\357\274\210\351\200\211\345\241\253\357\274\211", nullptr));
        balanceEdit->setPlaceholderText(QApplication::translate("RechargeAndDeductionWidget", "\350\207\252\345\212\250\345\233\236\345\241\253", nullptr));
        typeLabel->setText(QApplication::translate("RechargeAndDeductionWidget", "\346\223\215\344\275\234\347\261\273\345\236\213", nullptr));
        cardNumLabel->setText(QApplication::translate("RechargeAndDeductionWidget", "\345\215\241\345\217\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RechargeAndDeductionWidget: public Ui_RechargeAndDeductionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECHARGEANDDEDUCTIONWIDGET_H
