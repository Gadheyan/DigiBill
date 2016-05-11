#ifndef OWNERCOMPANYDETAILSGETTER_H
#define OWNERCOMPANYDETAILSGETTER_H

#include <QDialog>

namespace Ui {
class ownerCompanyDetailsGetter;
}

class ownerCompanyDetailsGetter : public QDialog
{
    Q_OBJECT

public:
    QByteArray logoByteArray;
    explicit ownerCompanyDetailsGetter(QWidget *parent = 0);
    ~ownerCompanyDetailsGetter();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_email_textChanged();


    void on_pushButton_3_clicked();


    void add_item_to_comboBox();
    void add_item_to_comboBox_currency();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::ownerCompanyDetailsGetter *ui;
};

#endif // OWNERCOMPANYDETAILSGETTER_H
