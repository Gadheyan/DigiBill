#include "currencydb.h"
#include <QApplication>


#include <QtSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QtDebug>
#include <QFileInfo>


currencydb::currencydb()
{

    currency = QSqlDatabase::addDatabase("QSQLITE");
    currency.setDatabaseName("currency.sqlite");
    if (!currency.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database currency: connection ok";
    }
}

currencydb::~currencydb()
{

        if(currency.isOpen())
        {
            currency.close();
            qDebug() <<"Database closed";
        }

}
