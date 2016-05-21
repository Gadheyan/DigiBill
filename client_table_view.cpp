#include "client_table_view.h"
#include "ui_client_table_view.h"
#include "dbconnector.h"
#include "QSqlQueryModel"
#include <QSqlQuery>

client_table_view::client_table_view(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::client_table_view)
{
    ui->setupUi(this);


    dbconnector db;
    QSqlQueryModel* modal = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery(db.digi_db) ;

    qry->exec("select * from client_details");

    modal->setQuery(*qry);
    ui->client_table->setModel(modal);

}

client_table_view::~client_table_view()
{
    delete ui;
}
