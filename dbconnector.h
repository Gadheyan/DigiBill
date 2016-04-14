#ifndef DBCONNECTOR_H
#define DBCONNECTOR_H

#include <QSqlDatabase>
class dbconnector
{
public:
    dbconnector();

private:
    QSqlDatabase m_db;
};

#endif // DBCONNECTOR_H
