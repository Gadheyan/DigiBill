#include <dbconnector.h>
#include <QApplication>

#include <QtSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QtDebug>
#include <QFileInfo>


dbconnector::dbconnector()
{
    digi_db = QSqlDatabase::addDatabase("QSQLITE");
    digi_db.setDatabaseName( "digibill.db" );

    if (!digi_db.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }


    QSqlQuery qry;


    // Creating table owner
    qry.prepare( "CREATE TABLE IF NOT EXISTS owner (owner_id INTEGER UNIQUE PRIMARY KEY, owner_name VARCHAR(30), company_name VARCHAR(30), address VARCHAR(50))" );
    if( !qry.exec() )
        qDebug() << qry.lastError();
    else
        qDebug() << "Table1 created!";

    // Creating table company_details
    qry.prepare( "CREATE TABLE IF NOT EXISTS company_details (company_id INTEGER UNIQUE PRIMARY KEY, company_name VARCHAR(30), contact VARCHAR(15) )" );
    if( !qry.exec() )
        qDebug() << qry.lastError();
    else
        qDebug() << "Table2 created!";

    // Creating table product_details
    qry.prepare( "CREATE TABLE IF NOT EXISTS product_details (product_id INTEGER UNIQUE PRIMARY KEY, product_name VARCHAR(30), price FLOAT, company_id INTEGER, FOREIGN KEY(company_id) REFERENCES company_details(company_id)  )" );
    if( !qry.exec() )
        qDebug() << qry.lastError();
    else
        qDebug() << "Table3 created!";


    // Creating table client_details
    qry.prepare( "CREATE TABLE IF NOT EXISTS client_details (client_id INTEGER UNIQUE PRIMARY KEY, client_name VARCHAR(30), address VARCHAR(50), phone VARCHAR(15))" );
    if( !qry.exec() )
        qDebug() << qry.lastError();
    else
        qDebug() << "Table4 created!";

    // Creating table
    qry.prepare( "CREATE TABLE IF NOT EXISTS invoice_details (invoice_id INTEGER UNIQUE PRIMARY KEY, date_of_invoice TEXT, client_id INTEGER, product_id INTEGER, FOREIGN KEY(client_id) REFERENCES client_details(client_id), FOREIGN KEY(product_id) REFERENCES product_details(product_id)  )" );
    if( !qry.exec() )
        qDebug() << qry.lastError();
    else
        qDebug() << "Table5 created!";







}
