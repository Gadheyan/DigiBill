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
    qry.prepare( "CREATE TABLE IF NOT EXISTS owner (owner_id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, owner_name VARCHAR(30), company_name VARCHAR(30), address VARCHAR(50))" );
    if( !qry.exec() )
        qDebug() << qry.lastError();
    else
        qDebug() << "Table1 created!";

    // Creating table company_details
    qry.prepare( "CREATE TABLE IF NOT EXISTS company_details (company_id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, company_name VARCHAR(30), contact VARCHAR(15) )" );
    if( !qry.exec() )
        qDebug() << qry.lastError();
    else
        qDebug() << "Table2 created!";

    // Creating table product_details
    qry.prepare( "CREATE TABLE IF NOT EXISTS product_details (product_id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, product_name VARCHAR(30), price FLOAT, company_id INTEGER, FOREIGN KEY(company_id) REFERENCES company_details(company_id)  )" );
    if( !qry.exec() )
        qDebug() << qry.lastError();
    else
        qDebug() << "Table3 created!";


    // Creating table client_details
    qry.prepare( "CREATE TABLE IF NOT EXISTS client_details (client_id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, client_name VARCHAR(30), address VARCHAR(50), phone VARCHAR(15))" );
    if( !qry.exec() )
        qDebug() << qry.lastError();
    else
        qDebug() << "Table4 created!";

    // Creating table
    qry.prepare( "CREATE TABLE IF NOT EXISTS invoice_details (invoice_id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, date_of_invoice TEXT, client_id INTEGER, product_id INTEGER, FOREIGN KEY(client_id) REFERENCES client_details(client_id), FOREIGN KEY(product_id) REFERENCES product_details(product_id)  )" );
    if( !qry.exec() )
        qDebug() << qry.lastError();
    else
        qDebug() << "Table5 created!";


}


dbconnector::~dbconnector()
{
    if(digi_db.isOpen())
    {
        digi_db.close();
        qDebug() <<"Database closed";
    }
}

bool dbconnector::insertIntoOwner(const QString& owner_name,const QString& company_name,const QString& address )
{
     QSqlQuery insqry;
     insqry.prepare("INSERT INTO owner(owner_name,company_name,address) VALUES(:owner_name,:company_name,:address)");



     insqry.bindValue(":owner_name", owner_name);
     insqry.bindValue(":company_name", company_name);
     insqry.bindValue(":address", address);
     if( !insqry.exec() )
         qDebug() << insqry.lastError();
     else
         qDebug() << "inserted";


}



bool dbconnector::insertIntoProduct(const QString& product_name,const QString& price,const QString& company_id )
{
     QSqlQuery insqry;
     insqry.prepare("INSERT INTO product_details(product_name,price,company_id) VALUES(:product_name,:price,:company_id)");



     insqry.bindValue(":product_name", product_name);
     insqry.bindValue(":price", price);
     insqry.bindValue(":company_id", company_id);
     if( !insqry.exec() )
         qDebug() << insqry.lastError();
     else
         qDebug() << "inserted into product";


}

