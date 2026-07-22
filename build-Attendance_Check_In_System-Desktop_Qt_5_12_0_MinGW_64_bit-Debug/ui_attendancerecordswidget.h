/********************************************************************************
** Form generated from reading UI file 'attendancerecordswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATTENDANCERECORDSWIDGET_H
#define UI_ATTENDANCERECORDSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
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

class Ui_AttendanceRecordsWidget
{
public:
    QVBoxLayout *mainVerticalLayout;
    QFrame *searchFrame;
    QVBoxLayout *searchFrameVerticalLayout;
    QLabel *searchTitleLabel;
    QHBoxLayout *searchHorizontalLayout;
    QHBoxLayout *cardSearchLayout;
    QLabel *searchCardLabel;
    QLineEdit *searchCardEdit;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *nameSearchLayout;
    QLabel *searchNameLabel;
    QLineEdit *searchNameEdit;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *dateRangeLayout;
    QLabel *dateRangeLabel;
    QDateEdit *startDateEdit;
    QLabel *dateSepLabel;
    QDateEdit *endDateEdit;
    QHBoxLayout *buttonHorizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *searchButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *resetSearchButton;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *exportButton;
    QSpacerItem *buttonHorizontalSpacer;
    QFrame *statisticsFrame;
    QHBoxLayout *statisticsHorizontalLayout;
    QLabel *totalRecordsLabel;
    QLabel *normalRecordsLabel;
    QLabel *lateRecordsLabel;
    QLabel *absentRecordsLabel;
    QSpacerItem *statisticsHorizontalSpacer;
    QTableView *attendanceTableView;

    void setupUi(QWidget *AttendanceRecordsWidget)
    {
        if (AttendanceRecordsWidget->objectName().isEmpty())
            AttendanceRecordsWidget->setObjectName(QString::fromUtf8("AttendanceRecordsWidget"));
        AttendanceRecordsWidget->resize(1301, 831);
        AttendanceRecordsWidget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    font-family: \"Microsoft YaHei\", \"\345\276\256\350\275\257\351\233\205\351\273\221\", \"PingFang SC\", sans-serif;\n"
"    font-size: 14px;\n"
"    color: #2D3748;\n"
"}\n"
"QWidget#AttendanceRecordsWidget{\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        mainVerticalLayout = new QVBoxLayout(AttendanceRecordsWidget);
        mainVerticalLayout->setSpacing(15);
        mainVerticalLayout->setObjectName(QString::fromUtf8("mainVerticalLayout"));
        mainVerticalLayout->setContentsMargins(15, 15, 15, 15);
        searchFrame = new QFrame(AttendanceRecordsWidget);
        searchFrame->setObjectName(QString::fromUtf8("searchFrame"));
        searchFrame->setMinimumSize(QSize(0, 160));
        searchFrame->setMaximumSize(QSize(16777215, 160));
        searchFrame->setStyleSheet(QString::fromUtf8("QFrame#searchFrame{\n"
"    background:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 16px;\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        searchFrame->setFrameShape(QFrame::StyledPanel);
        searchFrame->setFrameShadow(QFrame::Raised);
        searchFrameVerticalLayout = new QVBoxLayout(searchFrame);
        searchFrameVerticalLayout->setSpacing(10);
        searchFrameVerticalLayout->setObjectName(QString::fromUtf8("searchFrameVerticalLayout"));
        searchFrameVerticalLayout->setContentsMargins(20, 15, 20, 15);
        searchTitleLabel = new QLabel(searchFrame);
        searchTitleLabel->setObjectName(QString::fromUtf8("searchTitleLabel"));
        searchTitleLabel->setMinimumSize(QSize(0, 30));
        searchTitleLabel->setMaximumSize(QSize(16777215, 30));
        searchTitleLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));

        searchFrameVerticalLayout->addWidget(searchTitleLabel);

        searchHorizontalLayout = new QHBoxLayout();
        searchHorizontalLayout->setSpacing(30);
        searchHorizontalLayout->setObjectName(QString::fromUtf8("searchHorizontalLayout"));
        cardSearchLayout = new QHBoxLayout();
        cardSearchLayout->setSpacing(10);
        cardSearchLayout->setObjectName(QString::fromUtf8("cardSearchLayout"));
        searchCardLabel = new QLabel(searchFrame);
        searchCardLabel->setObjectName(QString::fromUtf8("searchCardLabel"));
        searchCardLabel->setMinimumSize(QSize(50, 36));
        searchCardLabel->setMaximumSize(QSize(50, 36));
        searchCardLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));

        cardSearchLayout->addWidget(searchCardLabel);

        searchCardEdit = new QLineEdit(searchFrame);
        searchCardEdit->setObjectName(QString::fromUtf8("searchCardEdit"));
        searchCardEdit->setMinimumSize(QSize(180, 36));
        searchCardEdit->setMaximumSize(QSize(200, 36));
        searchCardEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
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

        cardSearchLayout->addWidget(searchCardEdit);


        searchHorizontalLayout->addLayout(cardSearchLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        searchHorizontalLayout->addItem(horizontalSpacer);

        nameSearchLayout = new QHBoxLayout();
        nameSearchLayout->setSpacing(10);
        nameSearchLayout->setObjectName(QString::fromUtf8("nameSearchLayout"));
        searchNameLabel = new QLabel(searchFrame);
        searchNameLabel->setObjectName(QString::fromUtf8("searchNameLabel"));
        searchNameLabel->setMinimumSize(QSize(50, 36));
        searchNameLabel->setMaximumSize(QSize(50, 36));
        searchNameLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));

        nameSearchLayout->addWidget(searchNameLabel);

        searchNameEdit = new QLineEdit(searchFrame);
        searchNameEdit->setObjectName(QString::fromUtf8("searchNameEdit"));
        searchNameEdit->setMinimumSize(QSize(180, 36));
        searchNameEdit->setMaximumSize(QSize(200, 36));
        searchNameEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
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

        nameSearchLayout->addWidget(searchNameEdit);


        searchHorizontalLayout->addLayout(nameSearchLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        searchHorizontalLayout->addItem(horizontalSpacer_2);

        dateRangeLayout = new QHBoxLayout();
        dateRangeLayout->setSpacing(10);
        dateRangeLayout->setObjectName(QString::fromUtf8("dateRangeLayout"));
        dateRangeLabel = new QLabel(searchFrame);
        dateRangeLabel->setObjectName(QString::fromUtf8("dateRangeLabel"));
        dateRangeLabel->setMinimumSize(QSize(70, 36));
        dateRangeLabel->setMaximumSize(QSize(70, 36));
        dateRangeLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));

        dateRangeLayout->addWidget(dateRangeLabel);

        startDateEdit = new QDateEdit(searchFrame);
        startDateEdit->setObjectName(QString::fromUtf8("startDateEdit"));
        startDateEdit->setMinimumSize(QSize(140, 36));
        startDateEdit->setMaximumSize(QSize(150, 36));
        startDateEdit->setStyleSheet(QString::fromUtf8("QDateEdit{\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: rgb(0, 0, 0);\n"
"}\n"
"QDateEdit:focus{\n"
"    border: 1px solid #348aff;\n"
"}"));
        startDateEdit->setCalendarPopup(true);

        dateRangeLayout->addWidget(startDateEdit);

        dateSepLabel = new QLabel(searchFrame);
        dateSepLabel->setObjectName(QString::fromUtf8("dateSepLabel"));
        dateSepLabel->setMinimumSize(QSize(20, 36));
        dateSepLabel->setMaximumSize(QSize(20, 36));
        dateSepLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));

        dateRangeLayout->addWidget(dateSepLabel);

        endDateEdit = new QDateEdit(searchFrame);
        endDateEdit->setObjectName(QString::fromUtf8("endDateEdit"));
        endDateEdit->setMinimumSize(QSize(140, 36));
        endDateEdit->setMaximumSize(QSize(150, 36));
        endDateEdit->setStyleSheet(QString::fromUtf8("QDateEdit{\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 8px;\n"
"    padding: 6px 10px;\n"
"    font-size: 14px;\n"
"    color: rgb(0, 0, 0);\n"
"}\n"
"QDateEdit:focus{\n"
"    border: 1px solid #348aff;\n"
"}"));
        endDateEdit->setCalendarPopup(true);

        dateRangeLayout->addWidget(endDateEdit);


        searchHorizontalLayout->addLayout(dateRangeLayout);


        searchFrameVerticalLayout->addLayout(searchHorizontalLayout);

        buttonHorizontalLayout = new QHBoxLayout();
        buttonHorizontalLayout->setSpacing(20);
        buttonHorizontalLayout->setObjectName(QString::fromUtf8("buttonHorizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonHorizontalLayout->addItem(horizontalSpacer_5);

        searchButton = new QPushButton(searchFrame);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        searchButton->setMinimumSize(QSize(100, 38));
        searchButton->setMaximumSize(QSize(140, 40));
        searchButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        buttonHorizontalLayout->addWidget(searchButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonHorizontalLayout->addItem(horizontalSpacer_3);

        resetSearchButton = new QPushButton(searchFrame);
        resetSearchButton->setObjectName(QString::fromUtf8("resetSearchButton"));
        resetSearchButton->setMinimumSize(QSize(100, 38));
        resetSearchButton->setMaximumSize(QSize(140, 40));
        resetSearchButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        buttonHorizontalLayout->addWidget(resetSearchButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonHorizontalLayout->addItem(horizontalSpacer_4);

        exportButton = new QPushButton(searchFrame);
        exportButton->setObjectName(QString::fromUtf8("exportButton"));
        exportButton->setMinimumSize(QSize(100, 38));
        exportButton->setMaximumSize(QSize(140, 40));
        exportButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        buttonHorizontalLayout->addWidget(exportButton);

        buttonHorizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonHorizontalLayout->addItem(buttonHorizontalSpacer);


        searchFrameVerticalLayout->addLayout(buttonHorizontalLayout);


        mainVerticalLayout->addWidget(searchFrame);

        statisticsFrame = new QFrame(AttendanceRecordsWidget);
        statisticsFrame->setObjectName(QString::fromUtf8("statisticsFrame"));
        statisticsFrame->setMinimumSize(QSize(0, 50));
        statisticsFrame->setMaximumSize(QSize(16777215, 50));
        statisticsFrame->setStyleSheet(QString::fromUtf8("QFrame#statisticsFrame{\n"
"    background:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border-radius: 12px;\n"
"    border: 2px solid qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        statisticsFrame->setFrameShape(QFrame::StyledPanel);
        statisticsFrame->setFrameShadow(QFrame::Raised);
        statisticsHorizontalLayout = new QHBoxLayout(statisticsFrame);
        statisticsHorizontalLayout->setSpacing(30);
        statisticsHorizontalLayout->setObjectName(QString::fromUtf8("statisticsHorizontalLayout"));
        statisticsHorizontalLayout->setContentsMargins(30, 0, 30, 0);
        totalRecordsLabel = new QLabel(statisticsFrame);
        totalRecordsLabel->setObjectName(QString::fromUtf8("totalRecordsLabel"));
        totalRecordsLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #1A3A6B;\n"
"    background:transparent;\n"
"}"));

        statisticsHorizontalLayout->addWidget(totalRecordsLabel);

        normalRecordsLabel = new QLabel(statisticsFrame);
        normalRecordsLabel->setObjectName(QString::fromUtf8("normalRecordsLabel"));
        normalRecordsLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2D7D46;\n"
"    background:transparent;\n"
"}"));

        statisticsHorizontalLayout->addWidget(normalRecordsLabel);

        lateRecordsLabel = new QLabel(statisticsFrame);
        lateRecordsLabel->setObjectName(QString::fromUtf8("lateRecordsLabel"));
        lateRecordsLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #D4A017;\n"
"    background:transparent;\n"
"}"));

        statisticsHorizontalLayout->addWidget(lateRecordsLabel);

        absentRecordsLabel = new QLabel(statisticsFrame);
        absentRecordsLabel->setObjectName(QString::fromUtf8("absentRecordsLabel"));
        absentRecordsLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    border:none;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #C0392B;\n"
"    background:transparent;\n"
"}"));

        statisticsHorizontalLayout->addWidget(absentRecordsLabel);

        statisticsHorizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        statisticsHorizontalLayout->addItem(statisticsHorizontalSpacer);


        mainVerticalLayout->addWidget(statisticsFrame);

        attendanceTableView = new QTableView(AttendanceRecordsWidget);
        attendanceTableView->setObjectName(QString::fromUtf8("attendanceTableView"));
        attendanceTableView->setStyleSheet(QString::fromUtf8("QTableView{\n"
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
"}\n"
"QTableView QTableCornerButton::section{\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rg"
                        "ba(100, 118, 135, 217), stop:1 rgba(255, 255, 255, 255));\n"
"    border: none;\n"
"}"));
        attendanceTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        attendanceTableView->setAlternatingRowColors(true);
        attendanceTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        mainVerticalLayout->addWidget(attendanceTableView);


        retranslateUi(AttendanceRecordsWidget);

        QMetaObject::connectSlotsByName(AttendanceRecordsWidget);
    } // setupUi

    void retranslateUi(QWidget *AttendanceRecordsWidget)
    {
        AttendanceRecordsWidget->setWindowTitle(QApplication::translate("AttendanceRecordsWidget", "Form", nullptr));
        searchTitleLabel->setText(QApplication::translate("AttendanceRecordsWidget", "<html><head/><body><p><span style=\" font-size:12pt;\">\346\237\245\350\257\242\346\235\241\344\273\266</span></p></body></html>", nullptr));
        searchCardLabel->setText(QApplication::translate("AttendanceRecordsWidget", "\345\215\241\345\217\267", nullptr));
        searchCardEdit->setPlaceholderText(QApplication::translate("AttendanceRecordsWidget", "\350\276\223\345\205\245\346\210\226\345\275\225\345\205\245\345\215\241\345\217\267\346\237\245\350\257\242", nullptr));
        searchNameLabel->setText(QApplication::translate("AttendanceRecordsWidget", "\345\247\223\345\220\215", nullptr));
        searchNameEdit->setPlaceholderText(QApplication::translate("AttendanceRecordsWidget", "\350\276\223\345\205\245\345\247\223\345\220\215\346\237\245\350\257\242", nullptr));
        dateRangeLabel->setText(QApplication::translate("AttendanceRecordsWidget", "\346\227\245\346\234\237\350\214\203\345\233\264", nullptr));
        startDateEdit->setDisplayFormat(QApplication::translate("AttendanceRecordsWidget", "yyyy-MM-dd", nullptr));
        dateSepLabel->setText(QApplication::translate("AttendanceRecordsWidget", "~", nullptr));
        endDateEdit->setDisplayFormat(QApplication::translate("AttendanceRecordsWidget", "yyyy-MM-dd", nullptr));
        searchButton->setText(QApplication::translate("AttendanceRecordsWidget", "\346\237\245\350\257\242", nullptr));
        resetSearchButton->setText(QApplication::translate("AttendanceRecordsWidget", "\351\207\215\347\275\256", nullptr));
        exportButton->setText(QApplication::translate("AttendanceRecordsWidget", "\345\257\274\345\207\272\350\200\203\345\213\244\350\241\250", nullptr));
        totalRecordsLabel->setText(QApplication::translate("AttendanceRecordsWidget", "\346\200\273\350\256\260\345\275\225: 0 \346\235\241", nullptr));
        normalRecordsLabel->setText(QApplication::translate("AttendanceRecordsWidget", "\346\255\243\345\270\270: 0", nullptr));
        lateRecordsLabel->setText(QApplication::translate("AttendanceRecordsWidget", "\350\277\237\345\210\260: 0", nullptr));
        absentRecordsLabel->setText(QApplication::translate("AttendanceRecordsWidget", "\347\274\272\345\213\244: 0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AttendanceRecordsWidget: public Ui_AttendanceRecordsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATTENDANCERECORDSWIDGET_H
