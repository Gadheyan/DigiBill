#include "client_table_view.h"
#include "ui_client_table_view.h"
#include "dbconnector.h"
#include "QSqlQueryModel"
#include <QSqlQuery>
#include <QDebug>
#include "client_details.h"
#include <QStringList>


client_table_view::client_table_view(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::client_table_view)
{
    ui->setupUi(this);
    initializeTable();


    connect(ui->client_table->selectionModel(),SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)),
            SLOT(disableButtons(const QItemSelection &, const QItemSelection &))
           );
    ui->edit_client->setEnabled(false);


}




client_table_view::~client_table_view()
{
    delete ui;
}

void client_table_view::initializeTable()
{


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
    ui->client_table->setShowGrid(true);
    ui->client_table->setColumnHidden(0,true);
    qDebug()<<"Table Initialized";
}


void client_table_view::refreshTable()
{



    dbconnector db;
    QSqlQueryModel* modal = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery(db.digi_db);


    qry->exec("select client_id,company_name,contact_name,address,email,phone from client_details");

    int qrycount = 0;
    while(qry->next()){
        qrycount=qrycount+1;

       // for(int i=0;i<6;i++){//very important change limit according to column number
            //qDebug()<<"qry"<<qrycount<<"number"<<i<<qry->value(i).toString();
        //}


    }

    modal->setQuery(*qry);
    ui->client_table->setModel(modal);




    for (int c = 0; c < ui->client_table->horizontalHeader()->count(); ++c)
    {
        ui->client_table->horizontalHeader()->setSectionResizeMode(
            c, QHeaderView::Stretch);
    }
    ui->client_table->setSelectionBehavior(QAbstractItemView::SelectRows);//select the whole row instead of individual cell
    ui->client_table->setShowGrid(true);
    ui->client_table->setColumnHidden(0,true);
    qDebug()<<"Table Refreshed";
}


void client_table_view::on_client_table_doubleClicked(const QModelIndex &index)
{
    QModelIndexList indexList = ui->client_table->selectionModel()->selectedRows();
    int row = indexList[0].row();

    QString client_id =  indexList[0].sibling(row, 0).data().toString();
    //qDebug()<<client_id;
    client_details edit_client;
    edit_client.setTitleForWindow("Edit Info");
    edit_client.populateData(client_id);
    edit_client.setModal(true);
    int result =  edit_client.exec();
    if(result == 1)
    {
        refreshTable();

    }
}

void client_table_view::on_delete_client_clicked()
{
    QModelIndexList indexList = ui->client_table->selectionModel()->selectedRows();
     int row;
    foreach (QModelIndex index, indexList) {
        row = index.row();
       // qDebug()<<"deletefunction on client_table_view-row count"<<row;

    }

}

void client_table_view::on_edit_client_clicked()
{
    QModelIndexList indexList = ui->client_table->selectionModel()->selectedRows();
    int row = indexList[0].row();

    QString client_id =  indexList[0].sibling(row, 0).data().toString();
    //qDebug()<<client_id;
    client_details edit_client;
    edit_client.setTitleForWindow("Edit Info");
    edit_client.populateData(client_id);
    edit_client.setModal(true);
    int result =  edit_client.exec();
    if(result == 1)
    {
        refreshTable();

    }





}

void client_table_view::on_add_client_clicked()
{

    client_details add_client;
    add_client.setTitleForWindow("Add Client");
    add_client.setModal(true);

    int result =  add_client.exec();
    if(result == 1)
    {
        refreshTable();

    }
}





void client_table_view::disableButtons(const QItemSelection & selected, const QItemSelection & deselected){
    QModelIndexList indexList = ui->client_table->selectionModel()->selectedRows();
    int row=0;
    foreach (QModelIndex index, indexList) {
        row = row+1;

    }
    if(row>1 || row==0)
    {
        ui->edit_client->setEnabled(false);

    }
    else
       {
        ui->edit_client->setEnabled(true);

    }

}
