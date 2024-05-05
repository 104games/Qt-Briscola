#ifndef MAZZO_H
#define MAZZO_H

#include "carta.h"

#include <vector>
#include <stack>
#include <random>
#include <algorithm>
using namespace std;

class Mazzo
{
public:
    vector<Carta> mazzo_iniziale;
    stack<Carta> mazzo;
    Carta briscola;
    Mazzo();
    Carta pesca();
    void riempi_mazzo();
    void stack_mazzo();
    vector<Carta> mescola(vector<Carta> vec);

};



#endif // MAZZO_H
