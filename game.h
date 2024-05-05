#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <vector>
#include <iostream>
#include "ui_game.h"
#include "player.h"
#include "playercreation.h"
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
    void passa_nomi(vector<string> n);
    void passa_bot(vector<bool> bt);




private slots:
    void on_carta1_clicked();

private:
    Ui::game *ui;
    vector<Player> giocatori;
    int players;
    vector<string> nomi;
    vector<bool> bots;
    void turno();
    int attuale;
    //creazione mazzo vector e mazzo stack


};

#endif // GAME_H
