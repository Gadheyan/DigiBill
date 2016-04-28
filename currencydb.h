#ifndef CURRENCYDB_H
#define CURRENCYDB_H
#include <QSqlDatabase>


class currencydb
{
public:
    QSqlDatabase currency;
    currencydb();



    ~currencydb();

};

#endif // CURRENCYDB_H
