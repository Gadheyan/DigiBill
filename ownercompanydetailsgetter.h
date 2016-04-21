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
    QByteArray inByteArray;
    explicit ownerCompanyDetailsGetter(QWidget *parent = 0);
    ~ownerCompanyDetailsGetter();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_email_textChanged(const QString &arg1);


    void on_pushButton_3_clicked();

private:
    Ui::ownerCompanyDetailsGetter *ui;
};

#endif // OWNERCOMPANYDETAILSGETTER_H
