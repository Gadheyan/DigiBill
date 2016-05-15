#include "ownercompanydetailsgetter.h"
#include "ui_ownercompanydetailsgetter.h"
#include "dbconnector.h"
#include "currencydb.h"
#include "QMessageBox"
#include <QFileDialog>
#include <QRegularExpression>
#include <QDir>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlRecord>



ownerCompanyDetailsGetter::ownerCompanyDetailsGetter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ownerCompanyDetailsGetter)
{
    ui->setupUi(this);
    add_item_to_comboBox();
    add_item_to_comboBox_currency();



}

ownerCompanyDetailsGetter::~ownerCompanyDetailsGetter()
{
    delete ui;
}

void ownerCompanyDetailsGetter::on_pushButton_clicked()
{

    dbconnector db;
    QString company_name,country,address,city,state,email,phone,website,tin,currency,additional_info;
    company_name = ui->company_name->text();
    country = ui->comboBox->currentText();
    address = ui->address->toPlainText();
    city = ui->city->text();
    state = ui->state->text();
    email = ui->email->text();
    phone = ui->phone->text();
    website = ui->website->text();
    tin = ui->tin->text();
    currency = ui->comboBox_currency->currentText();
    additional_info = ui->additional_info->text();
    db.insertIntoOwner(company_name,country,address,city,state,email,phone,website,tin,currency,additional_info,logoByteArray);
    QMessageBox::information(
        this,
        tr("Saved"),
        tr("Information has been saved.") );





    this->close();

}


void ownerCompanyDetailsGetter::add_item_to_comboBox(){


  currencydb currencyobj;
  QSqlQueryModel* modal = new QSqlQueryModel();
  QSqlQuery* qry = new QSqlQuery(currencyobj.currency) ;

  qry->exec("select country from currency");

  modal->setQuery(*qry);
  ui->comboBox->setModel(modal);


  //qDebug() << qry->lastError().text();
  //qDebug() <<"Flag:" <<flag;




}

void ownerCompanyDetailsGetter::add_item_to_comboBox_currency(){

    currencydb currencyobj;
    QSqlQueryModel* modal = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery(currencyobj.currency) ;

    qry->exec("select currency from currency");

    modal->setQuery(*qry);
    ui->comboBox_currency->setModel(modal);

}


void ownerCompanyDetailsGetter::on_pushButton_2_clicked()
{
    this->close();
}

void ownerCompanyDetailsGetter::on_email_textChanged()
{
    QString email;
    email = ui->email->text();

    QRegularExpression regex("^[0-9a-zA-Z]+([0-9a-zA-Z]*[-._+])*[0-9a-zA-Z]+@[0-9a-zA-Z]+([-.][0-9a-zA-Z]+)*([0-9a-zA-Z]*[.])[a-zA-Z]{2,6}$");
    if(!regex.match(email).hasMatch())
        {
            ui->email_validation->setStyleSheet("QLabel {  color : red; }");
            ui->email_validation->setText("Not valid");
        }
    else
    {
        ui->email_validation->setStyleSheet("QLabel {  color : green; }");
        ui->email_validation->setText("valid");
    }


}

void ownerCompanyDetailsGetter::on_pushButton_3_clicked()
{

           QString filepath = QFileDialog::getOpenFileName(
               this,
               tr("Select Logo"),
               QDir::homePath(),
               "All files(*.*)"

               );


            QFile file(filepath);
            if (!file.open(QIODevice::ReadOnly)) return;
           logoByteArray = file.readAll();



}

void ownerCompanyDetailsGetter::on_comboBox_activated(const QString &arg1)
{
    QString cur_item_in_combo = ui->comboBox->currentText();
    currencydb currencyobj;
    QString currency_label_set_value;
    QSqlRecord record;


    QSqlQuery* qry = new QSqlQuery(currencyobj.currency);

   bool flag =  qry->exec("select currency from currency where country='"+cur_item_in_combo+"'");

   while( qry->next() ){
    record=qry->record();
    currency_label_set_value=record.value("currency").toString();
   }
 //qDebug()<<"Currency="<<currency_label_set_value;

   ui->comboBox_currency->setCurrentIndex(ui->comboBox_currency->findText(currency_label_set_value));





}
