#include "mainwindow.h"
#include <QApplication>
#include "dbconnector.h"
int main(int argc, char *argv[])
{

dbconnector db;

db.insertIntoOwner("san","fran","cisco");
db.insertIntoProduct("san","400","1");
}
