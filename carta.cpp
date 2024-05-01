#include "carta.h"
#include <iostream>
using namespace std;

Carta::Carta()
{

}
Carta::Carta(int n, int s, int p, string t){
    num = n;
    seme = s;
    punti = p;
    texture = t;
}

