#ifndef PRODUCT_DETAILS_H
#define PRODUCT_DETAILS_H

#include <QDialog>

namespace Ui {
class product_details;
}

class product_details : public QDialog
{
    Q_OBJECT

public:
    explicit product_details(QWidget *parent = 0);
    ~product_details();

private:
    Ui::product_details *ui;
};

#endif // PRODUCT_DETAILS_H
