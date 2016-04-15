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
    explicit ownerCompanyDetailsGetter(QWidget *parent = 0);
    ~ownerCompanyDetailsGetter();

private:
    Ui::ownerCompanyDetailsGetter *ui;
};

#endif // OWNERCOMPANYDETAILSGETTER_H
