#include "mainwindow.h"
#include <QApplication>
#include "dbconnector.h"
#include "ownercompanydetailsgetter.h"
int main(int argc, char *argv[])
{
    int flag=0;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();





    return a.exec();





}
