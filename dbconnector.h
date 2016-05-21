#ifndef DBCONNECTOR_H
#define DBCONNECTOR_H

#include <QSqlDatabase>


class dbconnector
{
public:
    dbconnector();
    QSqlDatabase digi_db;
    bool insertIntoOwner(const QString& company_name, const QString& country,const QString& address,const QString& city,const QString& state,const QString& email,const QString& phone,const QString& website,const QString& tin,const QString& currency,const QString& additional_info,const QByteArray& logoByteArray );
    bool insertIntoProduct(const QString& product_name,const QString& price,const QString& company_id );
    bool insertIntoClient(const QString& company_name, const QString& country,const QString& contact_name,const QString& address,const QString& city,const QString& state,const QString& email,const QString& phone,const QString& website,const QString& tin);
    QSqlDatabase openDb(const QString &driver, const QString &name) const;

     ~dbconnector();

private:

};

#endif // DBCONNECTOR_H
