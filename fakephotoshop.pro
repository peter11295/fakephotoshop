#-------------------------------------------------
#
# Project created by QtCreator 2015-09-11T15:51:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = fakephotoshop
TEMPLATE = app

INCLUDEPATH += $$quote(C:\opencv300_x86_vc2013\include)\
               $$quote(C:\opencv300_x86_vc2013\include\opencv)\
               $$quote(C:\opencv300_x86_vc2013\include\opencv2)



LIBS += $$quote(C:\opencv300_x86_vc2013\lib\opencv_ts300.lib)\
        $$quote(C:\opencv300_x86_vc2013\lib\opencv_world300.lib)\
        $$quote(C:\opencv300_x86_vc2013\lib\opencv_ts300d.lib)\
        $$quote(C:\opencv300_x86_vc2013\lib\opencv_world300d.lib)\

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
