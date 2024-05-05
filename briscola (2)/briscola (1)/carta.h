#ifndef CARTA_H
#define CARTA_H
#include <iostream>
using namespace std;

class Carta
{
public:
    int num;
    int seme;
    int punti;
    string texture;
    Carta();
    Carta(int n, int s, int p, string t);
};

#endif // CARTA_H
