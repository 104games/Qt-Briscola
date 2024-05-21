#include "game.h"
#include "player.h"
#include "playercreation.h"
#include "ui_game.h"

#include<vector>
#include<stack>

#include <iostream>
using namespace std;

using namespace std;
game::game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::game)
{
    ui->setupUi(this);
}

game::~game()
{
    delete ui;
}

Mazzo mazz = Mazzo();

Player::Player(string n, bool i)
{
    carta1 = mazz.mazzo.top();
    mazz.mazzo.pop();
    carta2 = mazz.mazzo.top();
    mazz.mazzo.pop();
    carta3 = mazz.mazzo.top();
    mazz.mazzo.pop();
    nome = n;
    is_bot = i;
}

void Player::pesca_carta(int n){
    if(mazz.mazzo.empty()){
        if(n==1){
            can_carta1 = false;
        }
        if(n==2){
            can_carta2 = false;
        }
        if(n==3){
            can_carta3 = false;
        }
        return;
    }
    if(n==1){
        carta1=mazz.mazzo.top();
        mazz.mazzo.pop();
    }
    if(n==2){
        carta2=mazz.mazzo.top();
        mazz.mazzo.pop();
    }
    if(n==3){
        carta3=mazz.mazzo.top();
        mazz.mazzo.pop();
    }

}


void game::passa_bot(vector<bool> bt){
    bots = bt;
    players = bt.size();
}
void game::passa_nomi(vector<string> n){
    nomi = n;
}

int game::cpu(){
    if(tavolo.size()==0){
        if(giocatori[attuale].carta1.punti <= giocatori[attuale].carta2.punti && giocatori[attuale].carta1.punti <= giocatori[attuale].carta3.punti){
            if(giocatori[attuale].carta1.seme!=mazz.briscola.seme){
                return 1;
            }
        }
        if(giocatori[attuale].carta2.punti <= giocatori[attuale].carta1.punti && giocatori[attuale].carta2.punti <= giocatori[attuale].carta3.punti){
            if(giocatori[attuale].carta2.seme!=mazz.briscola.seme){
                return 2;
            }
        }
        if(giocatori[attuale].carta3.punti <= giocatori[attuale].carta2.punti || giocatori[attuale].carta3.punti <= giocatori[attuale].carta1.punti){
            if(giocatori[attuale].carta1.seme!=mazz.briscola.seme){
                return 3;
            }
        }
        return 1;
    }
    int punti = 0;
    for(int x=0;x<tavolo.size();x++){
        punti+=tavolo[x].punti;
    }
    if (punti > 0){
        if(giocatori[attuale].carta1.seme==mazz.briscola.seme){
            return 1;
        }
        if(giocatori[attuale].carta2.seme==mazz.briscola.seme){
            return 2;
        }
        if(giocatori[attuale].carta1.seme==mazz.briscola.seme){
            return 3;
        }
    }

    if(giocatori[attuale].carta1.punti <= giocatori[attuale].carta2.punti && giocatori[attuale].carta1.punti <= giocatori[attuale].carta3.punti){
        if(giocatori[attuale].carta1.seme!=mazz.briscola.seme){
            return 1;
        }
    }
    if(giocatori[attuale].carta2.punti <= giocatori[attuale].carta1.punti && giocatori[attuale].carta2.punti <= giocatori[attuale].carta3.punti){
        if(giocatori[attuale].carta2.seme!=mazz.briscola.seme){
            return 2;
        }
    }
    if(giocatori[attuale].carta3.punti <= giocatori[attuale].carta2.punti || giocatori[attuale].carta3.punti <= giocatori[attuale].carta1.punti){
        if(giocatori[attuale].carta1.seme!=mazz.briscola.seme){
            return 3;
        }
    }
    return 1;
}

void game::turno(){
    ui->mazzo->setText(QString::fromStdString(to_string(mazz.mazzo.size())));
    ui->giocatore->setText(QString::fromStdString(giocatori[attuale].nome));
    ui->punti1->hide();
    ui->punti2->hide();
    if(tavolo.size()==0){
        ui->giocata1->hide();
        ui->giocata2->hide();
        ui->pushButton_3->hide();
    }
    if(tavolo.size()==1){
        ui->giocata1->show();
        ui->giocata1->setStyleSheet(QString::fromStdString(tavolo[0].texture));
    }
    if(tavolo.size()==2){
        ui->giocata2->show();
        ui->giocata2->setStyleSheet(QString::fromStdString(tavolo[1].texture));
    }
    if(tavolo.size()==3){
        ui->pushButton_3->show();
        ui->pushButton_3->setStyleSheet(QString::fromStdString(tavolo[2].texture));
    }

    if(mazz.mazzo.size()==0){
        ui->mazzo->hide();
        ui->briscola->hide();
    }

    if(!giocatori[attuale].can_carta1 && !giocatori[attuale].can_carta2 && !giocatori[attuale].can_carta3){
        if(giocatori.size()==2){
            ui->punti1->setText(QString::fromStdString(giocatori[0].nome+ " " + to_string(punti1)));
            ui->punti2->setText(QString::fromStdString(giocatori[1].nome+ " " + to_string(punti2)));
        }
        if(giocatori.size()==4){
            ui->punti1->setText(QString::fromStdString("team 1 " + to_string(punti1)));
            ui->punti2->setText(QString::fromStdString("team 2 " + to_string(punti2)));
        }
        ui->giocatore->setText("partita finita!");
        ui->textBrowser->hide();
        ui->punti1->show();
        ui->punti2->show();

    }

    if(giocatori[attuale].is_bot==false){

        if(giocatori[attuale].can_carta1){
            ui->carta1->setStyleSheet(QString::fromStdString(giocatori[attuale].carta1.texture));
            ui->carta1->show();
        }
        else{
            ui->carta1->hide();
        }
        if(giocatori[attuale].can_carta2){
            ui->carta2->setStyleSheet(QString::fromStdString(giocatori[attuale].carta2.texture));
            ui->carta2->show();
        }
        else{
            ui->carta2->hide();
        }
        if(giocatori[attuale].can_carta3){
            ui->carta3->setStyleSheet(QString::fromStdString(giocatori[attuale].carta3.texture));
            ui->carta3->show();
        }
        else{
            ui->carta3->hide();
        }




    }
    else{
        int scelta = cpu();
        if(scelta==1){
            tavolo.push_back(giocatori[attuale].carta1);

        }
        if(scelta==2){
            tavolo.push_back(giocatori[attuale].carta1);

        }
        if(scelta==3){
            tavolo.push_back(giocatori[attuale].carta1);

        }
        attuale++;
        if(attuale==giocatori.size()){
            attuale = 0;
            assegna_punti();
        }
        else{
            turno();
        }
    }

}


void game::start(){
    //QString::fromStdString()
    giocata.assign(4,1);
    for(int x=0; x<players; x++){
        Player giocatore = Player(nomi[x],bots[x]);
        giocatori.push_back(giocatore);

    }
    ui->briscola->setStyleSheet(QString::fromStdString(mazz.briscola.texture));
    ui->punti1->hide();
    ui->punti2->hide();
    attuale =0;
    turno();
}


void game::assegna_punti(){
    int max=0;

    for(int x=0; x<tavolo.size();x++){
        if(giocata[x]==1){
            if (x==0){
                ui->ultimo_carta1->setStyleSheet(QString::fromStdString(giocatori[x].carta1.texture));
            }
            if (x==1){
                ui->ultimo_carta2->setStyleSheet(QString::fromStdString(giocatori[x].carta1.texture));
            }
            if (x==2){
                ui->ultimo_carta3->setStyleSheet(QString::fromStdString(giocatori[x].carta1.texture));
            }
            if (x==3){
                ui->ultimo_carta4->setStyleSheet(QString::fromStdString(giocatori[x].carta1.texture));
            }
        }
        if(giocata[x]==2){
            if (x==0){
                ui->ultimo_carta1->setStyleSheet(QString::fromStdString(giocatori[x].carta2.texture));
            }
            if (x==1){
                ui->ultimo_carta2->setStyleSheet(QString::fromStdString(giocatori[x].carta2.texture));
            }
            if (x==2){
                ui->ultimo_carta3->setStyleSheet(QString::fromStdString(giocatori[x].carta2.texture));
            }
            if (x==3){
                ui->ultimo_carta4->setStyleSheet(QString::fromStdString(giocatori[x].carta2.texture));
            }
        }
        if(giocata[x]==3){
            if (x==0){
                ui->ultimo_carta1->setStyleSheet(QString::fromStdString(giocatori[x].carta1.texture));
            }
            if (x==1){
                ui->ultimo_carta2->setStyleSheet(QString::fromStdString(giocatori[x].carta1.texture));
            }
            if (x==2){
                ui->ultimo_carta3->setStyleSheet(QString::fromStdString(giocatori[x].carta1.texture));
            }
            if (x==3){
                ui->ultimo_carta4->setStyleSheet(QString::fromStdString(giocatori[x].carta1.texture));
            }
        }
        if(tavolo[x].seme == tavolo[max].seme){
            if(tavolo[x].num > tavolo[max].num){
                max=x;

            }
        }
        else if(tavolo[x].seme == mazz.briscola.seme){
            if(tavolo[max].seme == mazz.briscola.seme){
                if(tavolo[x].num > tavolo[max].num){

                    max=x;
                }
            }
            else{

                max=x;
            }
        }
    }


    if(max==0 || max==2){
        for(int x=0; x<tavolo.size(); x++){
            punti1+= tavolo[x].punti;
        }

        if(giocatori.size()==4){
            if(max==2){
                iter_swap(giocatori.begin(),giocatori.begin()+2);
                iter_swap(giocatori.begin()+1,giocatori.begin()+2);
                iter_swap(giocata.begin(),giocata.begin()+2);
                iter_swap(giocata.begin()+1,giocata.begin()+2);
            }
        }
    }

    if(max==1 || max==3){
        for(int x=0; x<tavolo.size(); x++){
            punti2+= tavolo[x].punti;
        }
        if(max==1){
            if (giocatori.size() == 2){
                if(giocatori.size()==2){
                    iter_swap(giocatori.begin(),giocatori.begin()+1);
                    iter_swap(giocata.begin(),giocata.begin()+1);
                }
                else{
                    Player tmp=giocatori[0];
                    int tpm = giocata[0];
                    giocatori.erase(giocatori.begin());
                    giocata.erase(giocata.begin());
                    giocatori.push_back(tmp);
                    giocata.push_back(tpm);
                }

            }
            else{
                iter_swap(giocatori.begin(),giocatori.begin()+3);
                iter_swap(giocatori.begin()+1,giocatori.begin());
                iter_swap(giocatori.begin()+1,giocatori.begin()+2);
                iter_swap(giocata.begin(),giocata.begin()+3);
                iter_swap(giocata.begin()+1,giocata.begin());
                iter_swap(giocata.begin()+1,giocata.begin()+2);
            }
        }
        if(max==3){
            Player tmp = giocatori[3];
            giocatori.pop_back();
            giocatori.insert(giocatori.begin(),tmp);
            int tpm = giocata[3];
            giocata.pop_back();
            giocata.insert(giocata.begin(),tpm);
        }

    }

    ui->ultimo_carta1->show();


    for(int x=0; x<giocatori.size();x++){
        giocatori[x].pesca_carta(giocata[x]);
    }

    rimaste-=tavolo.size();
    tavolo.clear();
    turno();
}

void game::on_carta1_clicked()
{
    tavolo.push_back(giocatori[attuale].carta1);
    giocata[attuale] = 1;
    attuale++;
    if(attuale==giocatori.size()){
        attuale = 0;
        assegna_punti();
    }
    else{
        turno();
    }
}


void game::on_carta2_clicked()
{
    tavolo.push_back(giocatori[attuale].carta2);
    giocata[attuale] = 2;
    attuale++;
    if(attuale==giocatori.size()){
        attuale = 0;
        assegna_punti();
    }
    else{
        turno();
    }
}


void game::on_carta3_clicked()
{
    tavolo.push_back(giocatori[attuale].carta3);
    giocata[attuale] = 3;
    attuale++;
    if(attuale==giocatori.size()){
        attuale = 0;
        assegna_punti();
    }
    else{
        turno();
    }
}


void game::on_pushButton_clicked()
{   if(giocatori.size()==2){
        ui->punti1->setText(QString::fromStdString(giocatori[0].nome+ " " + to_string(punti1)));
        ui->punti2->setText(QString::fromStdString(giocatori[1].nome+ " " + to_string(punti2)));
    }
    if(giocatori.size()==4){
        ui->punti1->setText(QString::fromStdString("team 1 " + to_string(punti1)));
        ui->punti2->setText(QString::fromStdString("team 2 " + to_string(punti2)));
    }
    if(attuale==0 || attuale==2){
        ui->punti1->show();
    }
    if(attuale==1 || attuale==3){
        ui->punti2->show();
    }
}

