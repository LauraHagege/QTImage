#-------------------------------------------------
#
# Project created by QtCreator 2016-08-26T16:44:11
#
#-------------------------------------------------

QT       += core gui
CONFIG += thread

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Image
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui


INCLUDEPATH += "C:\Program Files\DCMTK\include"

QMAKE_LIBDIR += "C:\Program Files\DCMTK\lib"
win32:LIBS += -lAdvapi32 -lofstd -loflog -ldcmdata -ldcmnet -ldcmimage -ldcmimgle -lws2_32 -lnetapi32 -lwsock32 -liphlpapi
