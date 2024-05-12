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

    void on_carta2_clicked();

    void on_carta3_clicked();

private:
    Ui::game *ui;
    vector<Player> giocatori;
    int players;
    vector<string> nomi;
    vector<bool> bots;
    vector<Carta> tavolo;
    vector<int> giocata;
    int attuale;
    int punti1=0;
    int punti2=0;
    int rimaste=40;
    void turno();
    void assegna_punti();
    int cpu();
    //creazione mazzo vector e mazzo stack


};

#endif // GAME_H
