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

    if(QSqlDatabase::contains("currencyconnection")){
        currency = QSqlDatabase::database("currencyconnection");
        currency.setDatabaseName("currency.sqlite");
        if(!currency.isOpen())
        {

            if (!currency.open())
            {
                qDebug() << "Error: connection with database fail";
            }
            else
            {
                qDebug() << "Database currency: connection ok";
            }
        }

    }
    else{


    currency = QSqlDatabase::addDatabase("QSQLITE","currencyconnection");
    currency.setDatabaseName("currency.sqlite");
    if(!currency.isOpen())
    {

        if (!currency.open())
        {
            qDebug() << "Error: connection with database fail";
        }
        else
        {
            qDebug() << "Database currency: connection ok";
        }
    }
        }
}

currencydb::~currencydb()
{

        if(currency.isOpen())
        {
            currency.close();
            qDebug() <<"Database currency closed";
        }

}
