#include "playercreation.h"
#include "ui_playercreation.h"
#include "game.h"
#include <vector>
#include<iostream>
using namespace std;

PlayerCreation::PlayerCreation(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PlayerCreation)
{
    ui->setupUi(this);

}



PlayerCreation::~PlayerCreation()
{
    delete ui;
}



void PlayerCreation::passa_mod(int n){
    if (n==1){
        players = 2;
        ui->team->hide();
    }
    if (n==2){
        players = 4;
    }
    if (n==3){
        ui->crea->hide();
        ui->isbot->hide();
        ui->tit->setText(QString("coming soon"));
        ui->nome->hide();
    }

}





void PlayerCreation::on_crea_clicked()
{
    if(ui->nome->text().size()){

        player_names.push_back(ui->nome->text());
        bots.push_back(ui->isbot->isChecked());
        ui->nome->setText(QString(""));
        player_counts++;
        if(player_counts==1 || player_counts==3){
            ui->team->setText(QString("  TEAM 2"));
        }
        else if(player_counts == 2){
            ui->team->setText(QString("  TEAM 1"));
        }
        if (player_counts == players){

            game *g = new game();
            g->show();
            g->start();
        }
    }
}

