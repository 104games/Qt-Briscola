#ifndef PLAYER_H
#define PLAYER_H

#include "mazzo.h"

#include<stack>
#include <iostream>

using namespace std;

class Player
{
public:
    Carta carta1;
    Carta carta2;
    Carta carta3;
    bool can_carta1=true;
    bool can_carta2=true;
    bool can_carta3=true;
    string nome;
    bool is_bot;
    Player();
    Player(string n, bool bt);
    void pesca_carta(int n);
};


#endif // PLAYER_H
