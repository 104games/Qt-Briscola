#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <vector>
#include <iostream>
#include "ui_game.h"
#include "player.h"
#include<stack>
using namespace std;



namespace Ui {
class game;
}

class game : public QMainWindow
{
    Q_OBJECT

public:
    explicit game(QWidget *parent = nullptr);
    ~game();
    void start();




private:
    Ui::game *ui;
    vector<Player> giocatori;

    //creazione mazzo vector e mazzo stack


};

#endif // GAME_H
