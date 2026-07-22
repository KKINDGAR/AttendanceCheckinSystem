#-------------------------------------------------
#
# Project created by QtCreator 2026-07-20T11:35:59
#
#-------------------------------------------------

QT       += core gui serialport multimedia multimediawidgets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Attendance_Check_In_System
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        widget.cpp \
    registerwidget.cpp \
    mysql.cpp \
    systemmanagementpanel.cpp \
    homepagewidget.cpp \
    userregisterwidget.cpp \
    usermodifywidget.cpp \
    attendancerecordswidget.cpp \
    serialsetwidget.cpp \
    rechargeanddeductionwidget.cpp \
    loginadminwidget.cpp

HEADERS += \
        widget.h \
    registerwidget.h \
    mysql.h \
    systemmanagementpanel.h \
    homepagewidget.h \
    userregisterwidget.h \
    usermodifywidget.h \
    attendancerecordswidget.h \
    serialsetwidget.h \
    rechargeanddeductionwidget.h \
    loginadminwidget.h

FORMS += \
        widget.ui \
    registerwidget.ui \
    systemmanagementpanel.ui \
    homepagewidget.ui \
    userregisterwidget.ui \
    usermodifywidget.ui \
    attendancerecordswidget.ui \
    serialsetwidget.ui \
    rechargeanddeductionwidget.ui \
    loginadminwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src.qrc
