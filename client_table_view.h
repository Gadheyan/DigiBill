#ifndef CLIENT_TABLE_VIEW_H
#define CLIENT_TABLE_VIEW_H

#include <QDialog>

namespace Ui {
class client_table_view;
}

class client_table_view : public QDialog
{
    Q_OBJECT

public:
    explicit client_table_view(QWidget *parent = 0);
    ~client_table_view();

private:
    Ui::client_table_view *ui;
};

#endif // CLIENT_TABLE_VIEW_H
