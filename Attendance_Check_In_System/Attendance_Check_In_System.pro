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

# 人脸识别模块
SOURCES += face/faceengine.cpp face/facecapture.cpp
HEADERS += face/faceengine.h   face/facecapture.h

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

# ==================== SeetaFace6 人脸识别库 ====================

unix {
    # ---- Ubuntu (GCC) ----
    SEETA_PATH = $$(HOME)/opt/SeetaFace6

    INCLUDEPATH += $$SEETA_PATH/include \
                   $$SEETA_PATH/include/seeta

    LIBS += -L$$SEETA_PATH/lib64 \
            -lSeetaFaceDetector600 \
            -lSeetaFaceLandmarker600 \
            -lSeetaFaceRecognizer610 \
            -lSeetaFaceTracking600 \
            -lSeetaAuthorize \
            -ltennis \
            -lORZ_static
}

win32 {
    # ---- Windows (MinGW) ----
    SEETA_PATH = D:/SeetaFace6_Windows
    INCLUDEPATH += $$SEETA_PATH/include \
                   $$SEETA_PATH/include/seeta

    LIBS += -L$$SEETA_PATH/lib \
            -lSeetaFaceDetector600 \
            -lSeetaFaceLandmarker600 \
            -lSeetaFaceRecognizer610 \
            -lSeetaFaceTracking600 \
            -lSeetaAuthorize \
            -ltennis \
            -lORZ

    # 构建后自动复制 DLL 到 exe 目录
    CONFIG(release, debug|release): DLL_DEST = $$OUT_PWD/release
    CONFIG(debug, debug|release):   DLL_DEST = $$OUT_PWD/debug
    QMAKE_POST_LINK += $$QMAKE_COPY_DIR $$shell_path($$SEETA_PATH/dll) $$shell_path($$DLL_DEST)
}
