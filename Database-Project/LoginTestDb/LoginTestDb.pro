#-------------------------------------------------
#
# Project created by QtCreator 2018-07-09T13:24:06
#
#-------------------------------------------------

QT       += core gui sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LoginTestDb
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


SOURCES += \
        main.cpp \
        login.cpp \
    admindialog.cpp \
    officialdialog.cpp \
    healthcaredialog.cpp \
    officialfield.cpp \
    groomdialog.cpp \
    userinfodialog.cpp \
    weddingfield.cpp \
    adminview.cpp \
    adminweddingview.cpp \
    bridedialog.cpp

HEADERS += \
        login.h \
    admindialog.h \
    officialdialog.h \
    healthcaredialog.h \
    officialfield.h \
    groomdialog.h \
    userinfodialog.h \
    weddingfield.h \
    adminview.h \
    adminweddingview.h \
    bridedialog.h

FORMS += \
        login.ui \
    admindialog.ui \
    officialdialog.ui \
    healthcaredialog.ui \
    officialfield.ui \
    groomdialog.ui \
    userinfodialog.ui \
    weddingfield.ui \
    adminview.ui \
    adminweddingview.ui \
    .ui \
    bridedialog.ui
