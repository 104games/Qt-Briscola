#include "playercreation.h"
#include "ui_playercreation.h"

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

int mod;

void PlayerCreation::passa_mod(int n){
    mod = n;
}

