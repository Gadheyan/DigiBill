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



ownerCompanyDetailsGetter::ownerCompanyDetailsGetter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ownerCompanyDetailsGetter)
{
    ui->setupUi(this);
    add_item_to_comboBox();




}

ownerCompanyDetailsGetter::~ownerCompanyDetailsGetter()
{
    delete ui;
}

void ownerCompanyDetailsGetter::on_pushButton_clicked()
{

    dbconnector db;
    QString company_name,email,address,additional_info;
    company_name = ui->company_name->text();
    email = ui->email->text();
    address = ui->address->toPlainText();
    additional_info = ui->additional_info->text();
    db.insertIntoOwner(company_name,email,address,additional_info,inByteArray);
    QMessageBox::information(
        this,
        tr("Saved"),
        tr("Information has been saved.") );





    this->close();

}


void ownerCompanyDetailsGetter::add_item_to_comboBox(){
  currencydb db;
  QSqlQueryModel* modal = new QSqlQueryModel();
  QSqlQuery qry;


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
           inByteArray = file.readAll();



}
