#include <dbconnector.h>
#include <QApplication>

#include <QtSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QtDebug>

dbconnector::dbconnector()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName( "./testdatabase.db" );

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}
