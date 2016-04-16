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


    if(flag==0)
    {
        ownerCompanyDetailsGetter dialogue;
        dialogue.setModal(true);
        dialogue.exec();

    }
    dbconnector db;

    db.insertIntoOwner("san","fran","cisco");
    db.insertIntoProduct("san","400","1");
    return a.exec();





}
