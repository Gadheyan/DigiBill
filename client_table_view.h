#ifndef CLIENT_TABLE_VIEW_H
#define CLIENT_TABLE_VIEW_H

#include <QDialog>
#include <QItemSelection>
namespace Ui {
class client_table_view;
}

class client_table_view : public QDialog
{
    Q_OBJECT

public:
    explicit client_table_view(QWidget *parent = 0);
    ~client_table_view();

private slots:
    void on_client_table_doubleClicked(const QModelIndex &index);

    void on_delete_client_clicked();

    void on_edit_client_clicked();

    void on_add_client_clicked();

    void setTitleForWindow(QString& title);


    void disableButtons(const QItemSelection & selected, const QItemSelection & deselected);




private:
    Ui::client_table_view *ui;
    QString window_title;
};

#endif // CLIENT_TABLE_VIEW_H
