#include "game.h"
#include "player.h"
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

void game::start(){
    ui->textBrowser->setText(QString::fromStdString(mazz.briscola.texture));
}






