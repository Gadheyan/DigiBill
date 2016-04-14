#-------------------------------------------------
#
# Project created by QtCreator 2016-04-13T09:15:49
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DigiBill
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dbconnector.cpp

HEADERS  += mainwindow.h \
    dbconnector.h

FORMS    += mainwindow.ui
