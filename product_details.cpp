#include "product_details.h"
#include "ui_product_details.h"

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
