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
    dbconnector.cpp \
    ownercompanydetailsgetter.cpp \
    product_details.cpp \
    currencydb.cpp \
    client_details.cpp \
    client_table_view.cpp

HEADERS  += mainwindow.h \
    dbconnector.h \
    ownercompanydetailsgetter.h \
    product_details.h \
    currencydb.h \
    client_details.h \
    client_table_view.h

FORMS    += mainwindow.ui \
    ownercompanydetailsgetter.ui \
    product_details.ui \
    client_details.ui \
    client_table_view.ui

RESOURCES += \
    tick_icon.qrc \
    buttonicon.qrc
