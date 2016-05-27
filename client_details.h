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

    void setTitleForWindow(const QString& title);

    void populateData(const QString& client_id);

    ~client_details();

private slots:
    void add_items_to_countrycombobox();

    void on_pushButton_2_clicked();

    void on_cancel_button_clicked();







private:
    Ui::client_details *ui;

    QString window_title;
    QString current_client_id;


};

#endif // CLIENT_DETAILS_H
