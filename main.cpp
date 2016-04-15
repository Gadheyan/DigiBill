#include "mainwindow.h"
#include <QApplication>
#include "dbconnector.h"
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();


dbconnector db;

db.insertIntoOwner("san","fran","cisco");
db.insertIntoProduct("san","400","1");


}
