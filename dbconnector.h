#ifndef DBCONNECTOR_H
#define DBCONNECTOR_H

#include <QSqlDatabase>


class dbconnector
{
public:
    dbconnector();

private:
    QSqlDatabase digi_db;
};

#endif // DBCONNECTOR_H
