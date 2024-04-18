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

void MainWindow::on_button1_clicked()
{
    QString text = ui->textBrowser->toPlainText();
    ui->textBrowser->setText(text+QString(" viva il comunismo"));
    ui->textBrowser->setTextBackgroundColor(QColor(255,0,0));
}


void MainWindow::on_button1_pressed()
{
    //ui->textBrowser->setTextBackgroundColor(QColor(255,0,0));
}

