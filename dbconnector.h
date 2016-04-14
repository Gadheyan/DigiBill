#ifndef DBCONNECTOR_H
#define DBCONNECTOR_H

#include <QSqlDatabase>


class dbconnector
{
public:
    dbconnector();
    bool insertIntoOwner(const QString& owner_name,const QString& company_name,const QString& address );
    bool insertIntoProduct(const QString& product_name,const QString& price,const QString& company_id );


     ~dbconnector();

private:
    QSqlDatabase digi_db;
};

#endif // DBCONNECTOR_H
