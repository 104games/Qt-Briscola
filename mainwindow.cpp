//https://magliani.altervista.org/scuola/qt_creator/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "playercreation.h"


using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}





//SCELTA MODALITÁ


void MainWindow::on_mod1_clicked()
{
    PlayerCreation *p = new PlayerCreation();
    p->passa_mod(1);
    p->show();
    ui->~MainWindow();
}


void MainWindow::on_mod2_clicked()
{
    PlayerCreation *p = new PlayerCreation();
    p->passa_mod(2);
    p->show();
    ui->~MainWindow();
}


void MainWindow::on_mod3_clicked()
{
    PlayerCreation *p = new PlayerCreation();
    p->passa_mod(3);
    p->show();
}

