#include "client_details.h"
#include "ui_client_details.h"
#include "currencydb.h"
#include "dbconnector.h"
#include "QMessageBox"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>


client_details::client_details(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::client_details)
{
    ui->setupUi(this);

    add_items_to_countrycombobox();




}

client_details::~client_details()
{
    delete ui;
}

void client_details::add_items_to_countrycombobox()
{
    currencydb currencyobj;
    QSqlQueryModel* modal = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery(currencyobj.currency) ;

    qry->exec("select country from currency");

    modal->setQuery(*qry);
    ui->countrycombobox->setModel(modal);



}



void client_details::on_pushButton_2_clicked()
{


    dbconnector db;
    QString company_name,contact_name,country,address,city,state,email,phone,website,tin;
    company_name = ui->company_name->text();
    contact_name = ui->contact_name->text();
    country = ui->countrycombobox->currentText();
    address = ui->address->toPlainText();
    city = ui->city->text();
    state = ui->state->text();
    email = ui->email->text();
    phone = ui->phone->text();
    website = ui->website->text();
    tin = ui->tin->text();
    if(window_title=="Edit Info"){

    //qDebug()<<window_title;
        db.updateClient(company_name,country,contact_name,address,city,state,email,phone,website,tin,current_client_id);

    }
    else if(window_title=="Add Client"){

    db.insertIntoClient(company_name,country,contact_name,address,city,state,email,phone,website,tin);
    }



    QMessageBox::information(
        this,
        tr("Saved"),
        tr("Information has been saved.") );



    this->close();
    this->setResult(QDialog::Accepted);




}

void client_details::on_cancel_button_clicked()
{
    this->close();
    this->setResult(QDialog::Rejected);
}


void client_details::setTitleForWindow(const QString& title)
{
    window_title = title;
    this->setWindowTitle(title);


}

void client_details::populateData(const QString& client_id){
    current_client_id = client_id;


    dbconnector db;
    QStringList result = db.sqlExecute(client_id);

    ui->company_name->setText(result[1]);
    ui->contact_name->setText(result[2]);
    ui->countrycombobox->setCurrentIndex(ui->countrycombobox->findText(result[3]));
    ui->address->setText(result[4]);
    ui->city->setText(result[5]);
    ui->state->setText(result[6]);
    ui->email->setText(result[7]);
    ui->phone->setText(result[8]);
    ui->website->setText(result[9]);
    ui->tin->setText(result[10]);




}




