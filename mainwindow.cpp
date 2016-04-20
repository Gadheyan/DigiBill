#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "product_details.h"
#include "ownercompanydetailsgetter.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowState(Qt::WindowMaximized);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    ownerCompanyDetailsGetter dialogue;
    dialogue.setModal(true);
    dialogue.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    product_details dialogue1;
   dialogue1.setModal(true);
    dialogue1.exec();
}
