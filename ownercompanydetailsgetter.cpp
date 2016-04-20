#include "ownercompanydetailsgetter.h"
#include "ui_ownercompanydetailsgetter.h"
#include "dbconnector.h"
#include <QMessageBox>

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
    QString owner_name,company_name,address,email;
    owner_name=ui->owner_name->text();
    company_name=ui->company_name->text();
    address=ui->address->toPlainText();
    email=ui->email->text();
    dbconnector db;
    db.insertIntoOwner(owner_name,company_name,email,address);
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
