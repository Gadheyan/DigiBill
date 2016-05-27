#include <dbconnector.h>
#include <QApplication>

#include <QtSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QtDebug>
#include <QFileInfo>
#include <QFile>
#include <QStringList>






dbconnector::dbconnector()
{
    digi_db = openDb("QSQLITE","digibill.db");
    QSqlQuery qry;


            // Creating table owner
            qry.prepare( "CREATE TABLE IF NOT EXISTS owner (owner_id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, company_name VARCHAR(30), country VARCHAR(30), address VARCHAR(100), city VARCHAR(30), state VARCHAR(30), email VARCHAR(30), phone VARCHAR(30), website VARCHAR(30),  tin VARCHAR(30), currency VARCHAR(30), additional_info VARCHAR(30), logo BLOB)" );
            if( !qry.exec() )
                qDebug() << qry.lastError();
            //else
               // qDebug() << "Table1 created!";

            // Creating table company_details
            qry.prepare( "CREATE TABLE IF NOT EXISTS company_details (company_id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, company_name VARCHAR(30), contact VARCHAR(15) )" );
            if( !qry.exec() )
                qDebug() << qry.lastError();
            //else
               // qDebug() << "Table2 created!";

            // Creating table product_details
            qry.prepare( "CREATE TABLE IF NOT EXISTS product_details (product_id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, product_name VARCHAR(30), price FLOAT, company_id INTEGER, FOREIGN KEY(company_id) REFERENCES company_details(company_id)  )" );
            if( !qry.exec() )
                qDebug() << qry.lastError();
            //else
                //qDebug() << "Table3 created!";


            // Creating table client_details
            qry.prepare( "CREATE TABLE IF NOT EXISTS client_details (client_id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, company_name VARCHAR(30),contact_name VARCHAR(40), country VARCHAR(30), address VARCHAR(50),city VARCHAR(30), state VARCHAR(30), email VARCHAR(80), phone VARCHAR(15), website VARCHAR(80), tin VARCHAR(30)  )" );
            if( !qry.exec() )
                qDebug() << qry.lastError();
            //else
               // qDebug() << "Table4 created!";

            // Creating table invoice_details
            qry.prepare( "CREATE TABLE IF NOT EXISTS invoice_details (invoice_id INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT, date_of_invoice TEXT, client_id INTEGER, product_id INTEGER, FOREIGN KEY(client_id) REFERENCES client_details(client_id), FOREIGN KEY(product_id) REFERENCES product_details(product_id)  )" );
            if( !qry.exec() )
                qDebug() << qry.lastError();
            //else
                //qDebug() << "Table5 created!";

}





QSqlDatabase dbconnector::openDb(const QString &driver, const QString &name) const
{
    QSqlDatabase db;

    // contains() default argument is initialized to default connection
    if (QSqlDatabase::contains())
    {
        db = QSqlDatabase::database(QLatin1String(QSqlDatabase::defaultConnection), false);
    }
    else
    {
        db = QSqlDatabase::addDatabase(driver.toUpper());
    }

    db.setDatabaseName(name);

    if (!db.isValid())
    {
        // Log error (last error: db.lastError().text()) and throw exception
    }

    if (!db.open())
    {
        // Log error (last error: db.lastError().text()) and throw exception
    }
    // qDebug() <<"Database main open";
    return db;
}






dbconnector::~dbconnector()
{
    if(digi_db.isOpen())
    {
        digi_db.close();
        qDebug() <<"Database main closed";
    }
}

bool dbconnector::insertIntoOwner(const QString& company_name, const QString& country,const QString& address,const QString& city,const QString& state,const QString& email,const QString& phone,const QString& website,const QString& tin,const QString& currency,const QString& additional_info,const QByteArray& logoByteArray )
{
    QSqlQuery insqry;
    insqry.prepare("INSERT INTO owner(company_name,country,address,city,state,email,phone,website,tin,currency,additional_info,logo) VALUES (:company_name,:country,:address,:city,:state,:email,:phone,:website,:tin,:currency,:additional_info,:logoByteArray)");


     insqry.bindValue( ":company_name", company_name );
     insqry.bindValue( ":country", country );
     insqry.bindValue( ":address", address );
     insqry.bindValue( ":city", city );
     insqry.bindValue( ":state", state );
     insqry.bindValue( ":email", email );
     insqry.bindValue( ":phone", phone );\
     insqry.bindValue( ":website", website );
     insqry.bindValue( ":tin", tin );
     insqry.bindValue( ":currency", currency );
     insqry.bindValue( ":additional_info", additional_info );
     insqry.bindValue( ":logoByteArray", logoByteArray );


     if( !insqry.exec() )
         qDebug() << insqry.lastError();
     else{

         qDebug() << "inserted into owner";

}

return true;
}




bool dbconnector::insertIntoClient(const QString& company_name, const QString& country,const QString& contact_name,const QString& address,const QString& city,const QString& state,const QString& email,const QString& phone,const QString& website,const QString& tin)
{
    QSqlQuery inscqry;
    inscqry.prepare("INSERT INTO client_details(company_name,country,contact_name,address,city,state,email,phone,website,tin) VALUES (:company_name,:country,:contact_name,:address,:city,:state,:email,:phone,:website,:tin)");
    inscqry.bindValue( ":company_name", company_name );
    inscqry.bindValue( ":country", country );
    inscqry.bindValue( ":contact_name", contact_name );
    inscqry.bindValue( ":address", address );
    inscqry.bindValue( ":city", city );
    inscqry.bindValue( ":state", state );
    inscqry.bindValue( ":email", email );
    inscqry.bindValue( ":phone", phone );\
    inscqry.bindValue( ":website", website );
    inscqry.bindValue( ":tin", tin );
    if( !inscqry.exec() )
        qDebug() << inscqry.lastError();
    else
    {

        qDebug() << "inserted into client";

}
return true;
}



bool dbconnector::insertIntoProduct(const QString& product_name,const QString& price,const QString& company_id )
{
     QSqlQuery insqry;
     insqry.prepare("INSERT INTO product_details(product_name,price,company_id) VALUES ('"+product_name+"','"+price+"','"+company_id+"')");




     if( !insqry.exec() )
         qDebug() << insqry.lastError();
    // else{
        // qDebug() << "inserted into product yaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
     //}
     return true;


}


bool dbconnector::updateClient(const QString& company_name, const QString& country,const QString& contact_name,const QString& address,const QString& city,const QString& state,const QString& email,const QString& phone,const QString& website,const QString& tin,const QString& client_id )
{
    QSqlQuery insqry;
    insqry.prepare("UPDATE client_details SET  company_name=:company_name,country=:country,contact_name=:contact_name,address=:address,city=:city,state=:state,email=:email,phone=:phone,website=:website,tin=:tin where client_id = :client_id");


     insqry.bindValue( ":company_name", company_name );
     insqry.bindValue( ":country", country );
     insqry.bindValue( ":contact_name", contact_name );
     insqry.bindValue( ":address", address );
     insqry.bindValue( ":city", city );
     insqry.bindValue( ":state", state );
     insqry.bindValue( ":email", email );
     insqry.bindValue( ":phone", phone );\
     insqry.bindValue( ":website", website );
     insqry.bindValue( ":tin", tin );
     insqry.bindValue( ":client_id", client_id );



     if( !insqry.exec() )
         qDebug() << insqry.lastError();
     else{

         qDebug() << "inserted into client";

}

return true;
}




QStringList dbconnector::sqlExecute(const QString& client_id)
{
    QStringList list ;

    QSqlQuery qry;
    qry.prepare("select * from client_details where client_id = '"+client_id+"'");
    if(qry.exec()){

        while(qry.next()){

           for(int i=0;i<11;i++){//very important change limit according to column number
               list.append(qry.value(i).toString());
           }

        }

    }
    else{
        qDebug()<<"error executing statement";
    }



    return list;
}
