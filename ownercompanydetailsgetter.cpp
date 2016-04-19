#include "ownercompanydetailsgetter.h"
#include "ui_ownercompanydetailsgetter.h"
#include "dbconnector.h"
#include "QMessageBox"


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
