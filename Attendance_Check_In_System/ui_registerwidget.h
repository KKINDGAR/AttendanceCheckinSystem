/********************************************************************************
** Form generated from reading UI file 'registerwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWIDGET_H
#define UI_REGISTERWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterWidget
{
public:
    QHBoxLayout *horizontalLayout_3;
    QFrame *registerFrame;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *loginLabel;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *userRegisterEdit;
    QLineEdit *passwordRegisterEdit;
    QLineEdit *passwordComfirEdit;
    QFrame *readCardFrame;
    QLabel *cardLabel;
    QLabel *cardIconLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *submitButton;
    QPushButton *cancelSubmitButton;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *contentTextLabel;
    QPushButton *backLoginButton;

    void setupUi(QWidget *RegisterWidget)
    {
        if (RegisterWidget->objectName().isEmpty())
            RegisterWidget->setObjectName(QString::fromUtf8("RegisterWidget"));
        RegisterWidget->resize(456, 606);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/manager.png"), QSize(), QIcon::Normal, QIcon::Off);
        RegisterWidget->setWindowIcon(icon);
        RegisterWidget->setStyleSheet(QString::fromUtf8("QWidget#RegisterWidget{\n"
"    background-image: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"	font-family: \"Microsoft YaHei\";\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(RegisterWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        registerFrame = new QFrame(RegisterWidget);
        registerFrame->setObjectName(QString::fromUtf8("registerFrame"));
        registerFrame->setMinimumSize(QSize(430, 580));
        registerFrame->setMaximumSize(QSize(430, 580));
        registerFrame->setStyleSheet(QString::fromUtf8("QFrame#registerFrame{\n"
"    background:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 16px;\n"
"    border: none;\n"
"}"));
        registerFrame->setFrameShape(QFrame::StyledPanel);
        registerFrame->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget = new QWidget(registerFrame);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 431, 581));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(15, 15, 15, 15);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        loginLabel = new QLabel(verticalLayoutWidget);
        loginLabel->setObjectName(QString::fromUtf8("loginLabel"));
        loginLabel->setMinimumSize(QSize(399, 122));
        loginLabel->setMaximumSize(QSize(399, 122));
        loginLabel->setStyleSheet(QString::fromUtf8("QLabel#loginLabel{\n"
"border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"border-radius: 12px;\n"
"background: rgba(46,125,255,0.03);\n"
"}"));
        loginLabel->setFrameShadow(QFrame::Plain);
        loginLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(loginLabel);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        userRegisterEdit = new QLineEdit(verticalLayoutWidget);
        userRegisterEdit->setObjectName(QString::fromUtf8("userRegisterEdit"));
        userRegisterEdit->setMinimumSize(QSize(0, 45));
        userRegisterEdit->setMaximumSize(QSize(16777215, 45));
        userRegisterEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border: 1px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 10px;\n"
"    padding: 11px 14px;\n"
"    font-size: 15px;\n"
"    color: rgb(0, 0, 0);\n"
"}\n"
"/* \350\276\223\345\205\245\346\241\206\350\201\232\347\204\246\351\253\230\344\272\256 */\n"
"QLineEdit:focus{\n"
"    border: 1px solid #348aff;\n"
"}\n"
"/* \345\215\240\344\275\215\346\217\220\347\244\272\346\265\205\347\201\260\350\211\262 */\n"
"QLineEdit::placeholder{\n"
"    color: #888888;\n"
"}"));

        verticalLayout_2->addWidget(userRegisterEdit);

        passwordRegisterEdit = new QLineEdit(verticalLayoutWidget);
        passwordRegisterEdit->setObjectName(QString::fromUtf8("passwordRegisterEdit"));
        passwordRegisterEdit->setMinimumSize(QSize(0, 45));
        passwordRegisterEdit->setMaximumSize(QSize(16777215, 45));
        passwordRegisterEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border: 1px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 10px;\n"
"    padding: 11px 14px;\n"
"    font-size: 15px;\n"
"    color: rgb(0, 0, 0);\n"
"}\n"
"/* \350\276\223\345\205\245\346\241\206\350\201\232\347\204\246\351\253\230\344\272\256 */\n"
"QLineEdit:focus{\n"
"    border: 1px solid #348aff;\n"
"}\n"
"/* \345\215\240\344\275\215\346\217\220\347\244\272\346\265\205\347\201\260\350\211\262 */\n"
"QLineEdit::placeholder{\n"
"    color: #888888;\n"
"}"));
        passwordRegisterEdit->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(passwordRegisterEdit);

        passwordComfirEdit = new QLineEdit(verticalLayoutWidget);
        passwordComfirEdit->setObjectName(QString::fromUtf8("passwordComfirEdit"));
        passwordComfirEdit->setMinimumSize(QSize(0, 45));
        passwordComfirEdit->setMaximumSize(QSize(16777215, 45));
        passwordComfirEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border: 1px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 10px;\n"
"    padding: 11px 14px;\n"
"    font-size: 15px;\n"
"    color: rgb(0, 0, 0);\n"
"}\n"
"/* \350\276\223\345\205\245\346\241\206\350\201\232\347\204\246\351\253\230\344\272\256 */\n"
"QLineEdit:focus{\n"
"    border: 1px solid #348aff;\n"
"}\n"
"/* \345\215\240\344\275\215\346\217\220\347\244\272\346\265\205\347\201\260\350\211\262 */\n"
"QLineEdit::placeholder{\n"
"    color: #888888;\n"
"}"));
        passwordComfirEdit->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(passwordComfirEdit);


        verticalLayout_3->addLayout(verticalLayout_2);

        readCardFrame = new QFrame(verticalLayoutWidget);
        readCardFrame->setObjectName(QString::fromUtf8("readCardFrame"));
        readCardFrame->setMinimumSize(QSize(399, 79));
        readCardFrame->setMaximumSize(QSize(399, 79));
        readCardFrame->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"border-radius: 12px;\n"
"background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        readCardFrame->setFrameShape(QFrame::StyledPanel);
        readCardFrame->setFrameShadow(QFrame::Raised);
        cardLabel = new QLabel(readCardFrame);
        cardLabel->setObjectName(QString::fromUtf8("cardLabel"));
        cardLabel->setGeometry(QRect(160, 10, 231, 61));
        cardLabel->setStyleSheet(QString::fromUtf8("QLabel#cardLabel{\n"
"    font-size: 22px;\n"
"    color: rgb(26, 58, 107);\n"
"    font-weight: 500;\n"
"}"));
        cardIconLabel = new QLabel(readCardFrame);
        cardIconLabel->setObjectName(QString::fromUtf8("cardIconLabel"));
        cardIconLabel->setGeometry(QRect(30, 10, 61, 61));
        cardIconLabel->setFrameShape(QFrame::NoFrame);
        cardIconLabel->setPixmap(QPixmap(QString::fromUtf8(":/image/shuaka2.png")));
        cardIconLabel->setScaledContents(true);

        verticalLayout_3->addWidget(readCardFrame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        submitButton = new QPushButton(verticalLayoutWidget);
        submitButton->setObjectName(QString::fromUtf8("submitButton"));
        submitButton->setMinimumSize(QSize(0, 41));
        submitButton->setMaximumSize(QSize(16777215, 41));
        submitButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        horizontalLayout->addWidget(submitButton);

        cancelSubmitButton = new QPushButton(verticalLayoutWidget);
        cancelSubmitButton->setObjectName(QString::fromUtf8("cancelSubmitButton"));
        cancelSubmitButton->setMinimumSize(QSize(0, 41));
        cancelSubmitButton->setMaximumSize(QSize(16777215, 41));
        cancelSubmitButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        horizontalLayout->addWidget(cancelSubmitButton);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        contentTextLabel = new QLabel(verticalLayoutWidget);
        contentTextLabel->setObjectName(QString::fromUtf8("contentTextLabel"));
        contentTextLabel->setMinimumSize(QSize(0, 18));
        contentTextLabel->setMaximumSize(QSize(16777215, 18));
        contentTextLabel->setStyleSheet(QString::fromUtf8("QLabel#contentTextLabel{\n"
"    font-size: 13px;\n"
"    color: #666666;\n"
"    qproperty-alignment: AlignCenter;\n"
"}\n"
""));

        horizontalLayout_2->addWidget(contentTextLabel);

        backLoginButton = new QPushButton(verticalLayoutWidget);
        backLoginButton->setObjectName(QString::fromUtf8("backLoginButton"));
        backLoginButton->setMinimumSize(QSize(0, 18));
        backLoginButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        horizontalLayout_2->addWidget(backLoginButton);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(verticalLayout_3);


        horizontalLayout_3->addWidget(registerFrame);


        retranslateUi(RegisterWidget);

        QMetaObject::connectSlotsByName(RegisterWidget);
    } // setupUi

    void retranslateUi(QWidget *RegisterWidget)
    {
        RegisterWidget->setWindowTitle(QApplication::translate("RegisterWidget", "\347\256\241\347\220\206\345\221\230\346\263\250\345\206\214", nullptr));
        loginLabel->setText(QApplication::translate("RegisterWidget", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; color:#1a3a6b;\">\347\256\241\347\220\206\345\221\230\346\263\250\345\206\214</span></p></body></html>", nullptr));
        userRegisterEdit->setPlaceholderText(QApplication::translate("RegisterWidget", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        passwordRegisterEdit->setPlaceholderText(QApplication::translate("RegisterWidget", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        passwordComfirEdit->setPlaceholderText(QApplication::translate("RegisterWidget", "\350\257\267\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        cardLabel->setText(QApplication::translate("RegisterWidget", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600; color:#1a3a6b;\">\350\257\267\345\210\267\345\215\241\345\275\225\345\205\245\345\215\241\345\217\267</span></p></body></html>", nullptr));
        cardIconLabel->setText(QString());
        submitButton->setText(QApplication::translate("RegisterWidget", "\346\263\250\345\206\214", nullptr));
        cancelSubmitButton->setText(QApplication::translate("RegisterWidget", "\345\217\226\346\266\210", nullptr));
        contentTextLabel->setText(QString());
        backLoginButton->setText(QApplication::translate("RegisterWidget", "\350\277\224\345\233\236\347\256\241\347\220\206\345\221\230\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWidget: public Ui_RegisterWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWIDGET_H
