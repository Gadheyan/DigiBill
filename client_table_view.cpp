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
    connect(ui->client_table->selectionModel(),SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)),
            SLOT(disableButtons(const QItemSelection &, const QItemSelection &))
           );

}




client_table_view::~client_table_view()
{
    delete ui;
}

void client_table_view::on_client_table_doubleClicked(const QModelIndex &index)
{
    //int row = index.row();
    //QString client_id =  index.sibling(row, 0).data().toString();

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

void client_table_view::on_edit_client_clicked()
{
    dbconnector db;

    QStringList list =  db.sqlExecute("hai");
    qDebug()<<list;


}

void client_table_view::on_add_client_clicked()
{

}


void client_table_view::setTitleForWindow(QString& title){
    window_title = title;

}


void client_table_view::disableButtons(const QItemSelection & selected, const QItemSelection & deselected){
    QModelIndexList indexList = ui->client_table->selectionModel()->selectedRows();
    int row=0;
    foreach (QModelIndex index, indexList) {
        row = row+1;
        qDebug()<<row;

    }
    if(row>1)
    {
        ui->edit_client->setEnabled(false);

    }
    else
       {
        ui->edit_client->setEnabled(true);

    }

}
