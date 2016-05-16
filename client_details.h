#ifndef CLIENT_DETAILS_H
#define CLIENT_DETAILS_H

#include <QDialog>

namespace Ui {
class client_details;
}

class client_details : public QDialog
{
    Q_OBJECT

public:
    explicit client_details(QWidget *parent = 0);
    ~client_details();

private:
    Ui::client_details *ui;
};

#endif // CLIENT_DETAILS_H
