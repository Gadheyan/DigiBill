#include "client_details.h"
#include "ui_client_details.h"

client_details::client_details(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::client_details)
{
    ui->setupUi(this);
}

client_details::~client_details()
{
    delete ui;
}
