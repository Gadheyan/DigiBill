#include "ownercompanydetailsgetter.h"
#include "ui_ownercompanydetailsgetter.h"

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
