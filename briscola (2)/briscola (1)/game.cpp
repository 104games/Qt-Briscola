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


void game::passa_bot(vector<bool> bt){
    bots = bt;
    players = bt.size();
}
void game::passa_nomi(vector<string> n){
    nomi = n;
}

void game::start(){
    //QString::fromStdString()

    for(int x=0; x<players; x++){
        Player giocatore = Player(nomi[x],bots[x]);
        giocatori.push_back(giocatore);
        cout << x << endl;
    }

    ui->giocatore->setText(QString::fromStdString(ui->giocatore->toPlainText().toStdString()+" "+nomi[0]));
    ui->carta1->setStyleSheet(QString::fromStdString(giocatori[0].carta1.texture));
}






