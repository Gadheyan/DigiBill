#ifndef DBCONNECTOR_H
#define DBCONNECTOR_H

#include <QSqlDatabase>


class dbconnector
{
public:
    dbconnector();
    bool insertIntoOwner(const QString& company_name,const QString& email,const QString& address ,const QString& additional_info );
    bool insertIntoProduct(const QString& product_name,const QString& price,const QString& company_id );



     ~dbconnector();

private:
    QSqlDatabase digi_db;
};

#endif // DBCONNECTOR_H
