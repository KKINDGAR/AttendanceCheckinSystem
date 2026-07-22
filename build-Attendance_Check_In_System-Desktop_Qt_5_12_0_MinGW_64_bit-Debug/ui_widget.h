/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *mainVerticalLayout;
    QVBoxLayout *datetimeLayout;
    QLabel *clockLabel;
    QLabel *dateLabel;
    QFrame *checkInFrame;
    QHBoxLayout *checkInFrameLayout;
    QLabel *cardIconLabel;
    QVBoxLayout *checkInTextLayout;
    QLabel *checkInTitleLabel;
    QLabel *checkInResultLabel;
    QFrame *recentRecordsFrame;
    QVBoxLayout *recentRecordsLayout;
    QLabel *recentRecordsTitleLabel;
    QTableView *recentRecordTableView;
    QHBoxLayout *adminEntryLayout;
    QSpacerItem *adminEntryLeftSpacer;
    QPushButton *adminEntryButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 650);
        Widget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    font-family: \"Microsoft YaHei\", \"\345\276\256\350\275\257\351\233\205\351\273\221\", \"PingFang SC\", sans-serif;\n"
"    font-size: 14px;\n"
"    color: #2D3748;\n"
"}\n"
"QWidget#Widget{\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        mainVerticalLayout = new QVBoxLayout(Widget);
        mainVerticalLayout->setSpacing(15);
        mainVerticalLayout->setContentsMargins(11, 11, 11, 11);
        mainVerticalLayout->setObjectName(QString::fromUtf8("mainVerticalLayout"));
        mainVerticalLayout->setContentsMargins(30, 25, 30, 15);
        datetimeLayout = new QVBoxLayout();
        datetimeLayout->setSpacing(2);
        datetimeLayout->setObjectName(QString::fromUtf8("datetimeLayout"));
        clockLabel = new QLabel(Widget);
        clockLabel->setObjectName(QString::fromUtf8("clockLabel"));
        clockLabel->setMinimumSize(QSize(0, 70));
        clockLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 52px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    qproperty-alignment: AlignCenter;\n"
"    background:transparent;\n"
"}"));
        clockLabel->setAlignment(Qt::AlignCenter);

        datetimeLayout->addWidget(clockLabel);

        dateLabel = new QLabel(Widget);
        dateLabel->setObjectName(QString::fromUtf8("dateLabel"));
        dateLabel->setMinimumSize(QSize(0, 35));
        dateLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 18px;\n"
"    color: #4A5568;\n"
"    qproperty-alignment: AlignCenter;\n"
"    background:transparent;\n"
"}"));
        dateLabel->setAlignment(Qt::AlignCenter);

        datetimeLayout->addWidget(dateLabel);


        mainVerticalLayout->addLayout(datetimeLayout);

        checkInFrame = new QFrame(Widget);
        checkInFrame->setObjectName(QString::fromUtf8("checkInFrame"));
        checkInFrame->setMinimumSize(QSize(0, 180));
        checkInFrame->setMaximumSize(QSize(16777215, 180));
        checkInFrame->setStyleSheet(QString::fromUtf8("QFrame#checkInFrame{\n"
"    background:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 20px;\n"
"    border: 3px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        checkInFrame->setFrameShape(QFrame::StyledPanel);
        checkInFrame->setFrameShadow(QFrame::Raised);
        checkInFrameLayout = new QHBoxLayout(checkInFrame);
        checkInFrameLayout->setSpacing(30);
        checkInFrameLayout->setContentsMargins(11, 11, 11, 11);
        checkInFrameLayout->setObjectName(QString::fromUtf8("checkInFrameLayout"));
        checkInFrameLayout->setContentsMargins(40, 20, 40, 20);
        cardIconLabel = new QLabel(checkInFrame);
        cardIconLabel->setObjectName(QString::fromUtf8("cardIconLabel"));
        cardIconLabel->setMinimumSize(QSize(120, 120));
        cardIconLabel->setMaximumSize(QSize(120, 120));
        cardIconLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    background:transparent;\n"
"}"));
        cardIconLabel->setPixmap(QPixmap(QString::fromUtf8(":/image/shuaka2.png")));
        cardIconLabel->setScaledContents(true);

        checkInFrameLayout->addWidget(cardIconLabel);

        checkInTextLayout = new QVBoxLayout();
        checkInTextLayout->setSpacing(8);
        checkInTextLayout->setObjectName(QString::fromUtf8("checkInTextLayout"));
        checkInTitleLabel = new QLabel(checkInFrame);
        checkInTitleLabel->setObjectName(QString::fromUtf8("checkInTitleLabel"));
        checkInTitleLabel->setMinimumSize(QSize(0, 35));
        checkInTitleLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 22px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));

        checkInTextLayout->addWidget(checkInTitleLabel);

        checkInResultLabel = new QLabel(checkInFrame);
        checkInResultLabel->setObjectName(QString::fromUtf8("checkInResultLabel"));
        checkInResultLabel->setMinimumSize(QSize(0, 30));
        checkInResultLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 16px;\n"
"    color: #666666;\n"
"    background:transparent;\n"
"}"));

        checkInTextLayout->addWidget(checkInResultLabel);


        checkInFrameLayout->addLayout(checkInTextLayout);


        mainVerticalLayout->addWidget(checkInFrame);

        recentRecordsFrame = new QFrame(Widget);
        recentRecordsFrame->setObjectName(QString::fromUtf8("recentRecordsFrame"));
        recentRecordsFrame->setStyleSheet(QString::fromUtf8("QFrame#recentRecordsFrame{\n"
"    background:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 16px;\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        recentRecordsFrame->setFrameShape(QFrame::StyledPanel);
        recentRecordsFrame->setFrameShadow(QFrame::Raised);
        recentRecordsLayout = new QVBoxLayout(recentRecordsFrame);
        recentRecordsLayout->setSpacing(8);
        recentRecordsLayout->setContentsMargins(11, 11, 11, 11);
        recentRecordsLayout->setObjectName(QString::fromUtf8("recentRecordsLayout"));
        recentRecordsLayout->setContentsMargins(15, 12, 15, 12);
        recentRecordsTitleLabel = new QLabel(recentRecordsFrame);
        recentRecordsTitleLabel->setObjectName(QString::fromUtf8("recentRecordsTitleLabel"));
        recentRecordsTitleLabel->setMinimumSize(QSize(0, 30));
        recentRecordsTitleLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));

        recentRecordsLayout->addWidget(recentRecordsTitleLabel);

        recentRecordTableView = new QTableView(recentRecordsFrame);
        recentRecordTableView->setObjectName(QString::fromUtf8("recentRecordTableView"));
        recentRecordTableView->setMinimumSize(QSize(0, 150));
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
"    font-size: 13px;\n"
"    padding: 6px;\n"
"    border: none;\n"
"    border-bottom: 2px solid rgba(100, 118, 135, 80);\n"
"}"));
        recentRecordTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        recentRecordTableView->setAlternatingRowColors(true);
        recentRecordTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        recentRecordsLayout->addWidget(recentRecordTableView);


        mainVerticalLayout->addWidget(recentRecordsFrame);

        adminEntryLayout = new QHBoxLayout();
        adminEntryLayout->setSpacing(6);
        adminEntryLayout->setObjectName(QString::fromUtf8("adminEntryLayout"));
        adminEntryLeftSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        adminEntryLayout->addItem(adminEntryLeftSpacer);

        adminEntryButton = new QPushButton(Widget);
        adminEntryButton->setObjectName(QString::fromUtf8("adminEntryButton"));
        adminEntryButton->setMinimumSize(QSize(160, 44));
        adminEntryButton->setMaximumSize(QSize(200, 48));
        adminEntryButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        adminEntryLayout->addWidget(adminEntryButton);


        mainVerticalLayout->addLayout(adminEntryLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\350\200\203\345\213\244\346\211\223\345\215\241", nullptr));
        clockLabel->setText(QApplication::translate("Widget", "--:--:--", nullptr));
        dateLabel->setText(QApplication::translate("Widget", "----\345\271\264--\346\234\210--\346\227\245 \346\230\237\346\234\237-", nullptr));
        cardIconLabel->setText(QString());
        checkInTitleLabel->setText(QApplication::translate("Widget", "<html><head/><body><p>\350\257\267\345\210\267\345\215\241\347\255\276\345\210\260 / \347\255\276\351\200\200</p></body></html>", nullptr));
        checkInResultLabel->setText(QApplication::translate("Widget", "\347\255\211\345\276\205\345\210\267\345\215\241...", nullptr));
        recentRecordsTitleLabel->setText(QApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:12pt;\">\346\234\200\350\277\221\346\211\223\345\215\241\350\256\260\345\275\225</span></p></body></html>", nullptr));
        adminEntryButton->setText(QApplication::translate("Widget", "\347\256\241\347\220\206\345\221\230\345\205\245\345\217\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
