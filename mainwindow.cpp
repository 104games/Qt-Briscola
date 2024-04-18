#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<vector>
#include<iostream>
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

/*
 * semi:
 *      1 = denari
 *      2 = bastoni
 *      3 = spade
 *      4 = coppe
 */

class Carta{
    public:
    int num;
    int seme;
    int punti;
    string texture;
    Carta(int n, int s, int p, string t){
        num = n;
        seme = s;
        punti = p;
        texture = t;
    }
};



vector<Carta> mazzo;

void riempi_mazzo(){
    Carta ReDenari =  Carta(10,1,4,":/carte/carte/10d.jpg");
    Carta CinqueSpade = Carta(5,3,0,":/carte/carte/5s.jpg");
    mazzo.push_back(ReDenari);
    mazzo.push_back(CinqueSpade);
    cout << mazzo[0].texture << endl << mazzo[1].texture << endl;
}





void MainWindow::on_mod1_clicked()
{
    riempi_mazzo();
}

