#include "client_table_view.h"
#include "ui_client_table_view.h"
#include "dbconnector.h"
#include "QSqlQueryModel"
#include <QSqlQuery>
#include <QDebug>
#include "client_details.h"

client_table_view::client_table_view(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::client_table_view)
{
    ui->setupUi(this);


    dbconnector db;
    QSqlQueryModel* modal = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery(db.digi_db) ;

    qry->exec("select client_id,company_name,contact_name,address,email,phone from client_details");

    modal->setQuery(*qry);
    ui->client_table->setModel(modal);

    for (int c = 0; c < ui->client_table->horizontalHeader()->count(); ++c)
    {
        ui->client_table->horizontalHeader()->setSectionResizeMode(
            c, QHeaderView::Stretch);
    }
    ui->client_table->setSelectionBehavior(QAbstractItemView::SelectRows);//select the whole row instead of individual cell
    ui->client_table->setShowGrid(false);
    ui->client_table->setColumnHidden(0,true);


}




client_table_view::~client_table_view()
{
    delete ui;
}

void client_table_view::on_client_table_doubleClicked(const QModelIndex &index)
{
    int row = index.row();
    QString client_id =  index.sibling(row, 0).data().toString();

    client_details client_dialogue;
    client_dialogue.setModal(true);
    client_dialogue.exec();

}

void client_table_view::on_delete_client_clicked()
{
    QModelIndexList indexList = ui->client_table->selectionModel()->selectedRows();

    int row;
    foreach (QModelIndex index, indexList) {
        row = index.row();
        qDebug()<<row;

    }
}
