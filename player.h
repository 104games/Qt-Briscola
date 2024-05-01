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
    string nome;
    bool is_bot;
    Player(string n, bool bt);
};


#endif // PLAYER_H
