/********************************************************************************
** Form generated from reading UI file 'loginadminwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINADMINWIDGET_H
#define UI_LOGINADMINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginAdminWidget
{
public:
    QGridLayout *gridLayout;
    QFrame *loginFrame;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *loginLabel;
    QFrame *readCardFrame;
    QLabel *cardLabel;
    QLabel *cardIconLabel;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *userEdit;
    QLineEdit *passwordEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *loginButton;
    QPushButton *cancelButton;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *contentLabel;
    QPushButton *backRegisterButton;

    void setupUi(QWidget *LoginAdminWidget)
    {
        if (LoginAdminWidget->objectName().isEmpty())
            LoginAdminWidget->setObjectName(QString::fromUtf8("LoginAdminWidget"));
        LoginAdminWidget->resize(456, 606);
        LoginAdminWidget->setStyleSheet(QString::fromUtf8("QWidget#LoginAdminWidget{\n"
"    background:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"	font-family: \"Microsoft YaHei\";\n"
"}"));
        gridLayout = new QGridLayout(LoginAdminWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        loginFrame = new QFrame(LoginAdminWidget);
        loginFrame->setObjectName(QString::fromUtf8("loginFrame"));
        loginFrame->setMinimumSize(QSize(430, 580));
        loginFrame->setMaximumSize(QSize(430, 580));
        loginFrame->setStyleSheet(QString::fromUtf8("QFrame#loginFrame{\n"
"    background:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 16px;\n"
"    border: none;\n"
"}"));
        loginFrame->setFrameShape(QFrame::StyledPanel);
        loginFrame->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget = new QWidget(loginFrame);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 20, 391, 261));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(10);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(15, 15, 15, 15);
        loginLabel = new QLabel(verticalLayoutWidget);
        loginLabel->setObjectName(QString::fromUtf8("loginLabel"));
        loginLabel->setStyleSheet(QString::fromUtf8("QLabel#loginLabel{\n"
"	border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"	border-radius: 12px;\n"
"	background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        loginLabel->setFrameShadow(QFrame::Plain);
        loginLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(loginLabel);

        readCardFrame = new QFrame(verticalLayoutWidget);
        readCardFrame->setObjectName(QString::fromUtf8("readCardFrame"));
        readCardFrame->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"	border-radius: 12px;\n"
"	background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        readCardFrame->setFrameShape(QFrame::StyledPanel);
        readCardFrame->setFrameShadow(QFrame::Raised);
        cardLabel = new QLabel(readCardFrame);
        cardLabel->setObjectName(QString::fromUtf8("cardLabel"));
        cardLabel->setGeometry(QRect(130, 30, 221, 61));
        cardLabel->setStyleSheet(QString::fromUtf8("QLabel#cardLabel{\n"
"    font-size: 22px;\n"
"    color: rgb(26, 58, 107);\n"
"    font-weight: 500;\n"
"}"));
        cardIconLabel = new QLabel(readCardFrame);
        cardIconLabel->setObjectName(QString::fromUtf8("cardIconLabel"));
        cardIconLabel->setGeometry(QRect(30, 20, 81, 81));
        cardIconLabel->setFrameShape(QFrame::NoFrame);
        cardIconLabel->setPixmap(QPixmap(QString::fromUtf8(":/image/shuaka2.png")));
        cardIconLabel->setScaledContents(true);

        verticalLayout->addWidget(readCardFrame);

        layoutWidget = new QWidget(loginFrame);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 270, 391, 231));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(15);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(15, 15, 15, 15);
        userEdit = new QLineEdit(layoutWidget);
        userEdit->setObjectName(QString::fromUtf8("userEdit"));
        userEdit->setMinimumSize(QSize(0, 40));
        userEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border: 1px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
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

        verticalLayout_2->addWidget(userEdit);

        passwordEdit = new QLineEdit(layoutWidget);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));
        passwordEdit->setMinimumSize(QSize(0, 40));
        passwordEdit->setMaximumSize(QSize(16777215, 40));
        passwordEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border: 1px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
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
        passwordEdit->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(passwordEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(15);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(15, 15, 15, 15);
        loginButton = new QPushButton(layoutWidget);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setMinimumSize(QSize(0, 40));
        loginButton->setMaximumSize(QSize(16777215, 40));
        loginButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        horizontalLayout_2->addWidget(loginButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setMinimumSize(QSize(0, 40));
        cancelButton->setMaximumSize(QSize(16777215, 40));
        cancelButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        horizontalLayout_2->addWidget(cancelButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        layoutWidget1 = new QWidget(loginFrame);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(180, 520, 211, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        contentLabel = new QLabel(layoutWidget1);
        contentLabel->setObjectName(QString::fromUtf8("contentLabel"));
        contentLabel->setMinimumSize(QSize(0, 24));
        contentLabel->setMaximumSize(QSize(16777215, 24));
        contentLabel->setStyleSheet(QString::fromUtf8("QLabel#contentLabel{\n"
"    font-size: 13px;\n"
"    color: #666666;\n"
"    qproperty-alignment: AlignCenter;\n"
"}\n"
""));

        horizontalLayout->addWidget(contentLabel);

        backRegisterButton = new QPushButton(layoutWidget1);
        backRegisterButton->setObjectName(QString::fromUtf8("backRegisterButton"));
        backRegisterButton->setMinimumSize(QSize(0, 24));
        backRegisterButton->setMaximumSize(QSize(16777215, 24));
        backRegisterButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	font-size: 13px;\n"
"    color: #666666;\n"
"	border:none;\n"
"	background:transparent;\n"
"	color:#55aaff;\n"
"}\n"
"QPushButton#backRegisterButton:hover{\n"
"    color: qlineargradient(x1:0,y1:0,x2:0,y2:1,stop:0 #50a3ff, stop:1 #3086fa);\n"
"}"));

        horizontalLayout->addWidget(backRegisterButton);


        gridLayout->addWidget(loginFrame, 0, 0, 1, 1);


        retranslateUi(LoginAdminWidget);

        QMetaObject::connectSlotsByName(LoginAdminWidget);
    } // setupUi

    void retranslateUi(QWidget *LoginAdminWidget)
    {
        LoginAdminWidget->setWindowTitle(QApplication::translate("LoginAdminWidget", "\347\256\241\347\220\206\345\221\230\347\231\273\345\275\225", nullptr));
        loginLabel->setText(QApplication::translate("LoginAdminWidget", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#1a3a6b;\">\347\256\241\347\220\206\345\221\230\347\231\273\345\275\225</span></p></body></html>", nullptr));
        cardLabel->setText(QApplication::translate("LoginAdminWidget", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600; color:#1a3a6b;\">\345\210\267\345\215\241\346\210\226\350\264\246\346\210\267\347\231\273\345\275\225</span></p></body></html>", nullptr));
        cardIconLabel->setText(QString());
        userEdit->setPlaceholderText(QApplication::translate("LoginAdminWidget", "\350\257\267\350\276\223\345\205\245\345\215\241\345\217\267/\347\224\250\346\210\267\345\220\215", nullptr));
        passwordEdit->setPlaceholderText(QApplication::translate("LoginAdminWidget", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        loginButton->setText(QApplication::translate("LoginAdminWidget", "\347\231\273\345\275\225", nullptr));
        cancelButton->setText(QApplication::translate("LoginAdminWidget", "\345\217\226\346\266\210", nullptr));
        contentLabel->setText(QApplication::translate("LoginAdminWidget", "<html><head/><body><p align=\"right\">\350\277\230\346\262\241\346\234\211\350\264\246\345\217\267\357\274\237</p></body></html>", nullptr));
        backRegisterButton->setText(QApplication::translate("LoginAdminWidget", "\347\253\213\345\215\263\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginAdminWidget: public Ui_LoginAdminWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINADMINWIDGET_H
