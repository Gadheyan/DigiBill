#-------------------------------------------------
#
# Project created by QtCreator 2016-04-13T09:15:49
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DigiBill
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    databasconnection.cpp

HEADERS  += mainwindow.h \
    databasconnection.h

FORMS    += mainwindow.ui
