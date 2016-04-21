#include "ownercompanydetailsgetter.h"
#include "ui_ownercompanydetailsgetter.h"
#include "dbconnector.h"
#include "QMessageBox"
#include <QFileDialog>
#include <QRegularExpression>


ownerCompanyDetailsGetter::ownerCompanyDetailsGetter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ownerCompanyDetailsGetter)
{
    ui->setupUi(this);

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
    db.insertIntoOwner(company_name,email,address,additional_info);
    QMessageBox::information(
        this,
        tr("Saved"),
        tr("Information has been saved.") );





    this->close();

}

void ownerCompanyDetailsGetter::on_pushButton_2_clicked()
{
    this->close();
}

void ownerCompanyDetailsGetter::on_email_textChanged(const QString &arg)
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
