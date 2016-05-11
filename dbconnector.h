#ifndef DBCONNECTOR_H
#define DBCONNECTOR_H

#include <QSqlDatabase>


class dbconnector
{
public:
    dbconnector();
    bool insertIntoOwner(const QString& company_name, const QString& country,const QString& address,const QString& city,const QString& state,const QString& email,const QString& phone,const QString& website,const QString& tin,const QString& currency,const QString& additional_info,const QByteArray& logoByteArray );
    bool insertIntoProduct(const QString& product_name,const QString& price,const QString& company_id );



     ~dbconnector();

private:
    QSqlDatabase digi_db;
};

#endif // DBCONNECTOR_H
