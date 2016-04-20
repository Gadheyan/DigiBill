#include "product_details.h"
#include "ui_product_details.h"
#include "dbconnector.h"
#include <QMessageBox>

product_details::product_details(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::product_details)
{
    ui->setupUi(this);
}

product_details::~product_details()
{
    delete ui;
}

void product_details::on_pushButton_clicked()
{
    QString product_name,price,company_id;
    product_name=ui->product_name->text();
    price=ui->price->text();
    company_id=ui->company_id->text();
    dbconnector db;
    db.insertIntoProduct(product_name,price,company_id);
    QMessageBox::information(
        this,
        tr("Saved"),
        tr("Information has been saved.") );
    this->close();
}

void product_details::on_pushButton_2_clicked()
{
    this->close();
}
