#include "mainwindow.h"
#include "ui_mainwindow.h"
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




void MainWindow::on_carta_clicked()
{
    if(ui->carta->styleSheet()=="image: url(:/carte/carte/5s.jpg);"){
        ui->carta->setStyleSheet("image: url(:/carte/carte/10d.jpg);");
    }
    else{
        ui->carta->setStyleSheet("image: url(:/carte/carte/5s.jpg);");
    }

}

