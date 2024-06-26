#include "mazzo.h"

Mazzo::Mazzo(){
    riempi_mazzo();
}

Carta Mazzo::pesca() {
    Carta top = mazzo.top();
    mazzo.pop();
    return top;
}

vector<Carta> Mazzo::mescola(vector<Carta> vec){

    srand(time(NULL));
    random_device rd;
    mt19937 g(time(NULL));

    // Shuffle the vector
    shuffle(vec.begin(), vec.end(), g);

    return vec;
}

void Mazzo::stack_mazzo(){
    briscola = mazzo_iniziale[39];
    mazzo_iniziale[39] = mazzo_iniziale[0];
    mazzo_iniziale[0] = briscola;
    for(int i=0; i<mazzo_iniziale.size();i++){
        mazzo.push(mazzo_iniziale[i]);
    }
}

void Mazzo::riempi_mazzo(){
    //aggiungo carte

    //denari
    Carta AssoDenari = Carta(12,1,11,"border-image: url(:/carte/carte/1d.jpg);");
    Carta DueDenari = Carta(2,1,0,"border-image: url(:/carte/carte/2d.jpg);");
    Carta TreDenari = Carta(11,1,10,"border-image: url(:/carte/carte/3d.jpg);");
    Carta QuattroDenari = Carta(4,1,0,"border-image: url(:/carte/carte/4d.jpg);");
    Carta CinqueDenari = Carta(5,1,0,"border-image: url(:/carte/carte/5d.jpg);");
    Carta SeiDenari = Carta(6,1,0,"border-image: url(:/carte/carte/6d.jpg);");
    Carta SetteDenari = Carta(7,1,0,"border-image: url(:/carte/carte/7d.jpg);");
    Carta OttoDenari = Carta(8,1,2,"border-image: url(:/carte/carte/8d.jpg);");
    Carta NoveDenari = Carta(9,1,3,"border-image: url(:/carte/carte/9d.jpg);");
    Carta ReDenari =  Carta(10,1,4,"border-image: url(:/carte/carte/10d.jpg);");

    //bastoni
    Carta AssoBastoni = Carta(12,2,11,"border-image: url(:/carte/carte/1b.jpg);");
    Carta DueBastoni = Carta(2,2,0,"border-image: url(:/carte/carte/2b.jpg);");
    Carta TreBastoni = Carta(11,2,10,"border-image: url(:/carte/carte/3b.jpg);");
    Carta QuattroBastoni = Carta(4,2,0,"border-image: url(:/carte/carte/4b.jpg);");
    Carta CinqueBastoni = Carta(5,2,0,"border-image: url(:/carte/carte/5b.jpg);");
    Carta SeiBastoni = Carta(6,2,0,"border-image: url(:/carte/carte/6b.jpg);");
    Carta SetteBastoni = Carta(7,2,0,"border-image: url(:/carte/carte/7b.jpg);");
    Carta OttoBastoni = Carta(8,2,2,"border-image: url(:/carte/carte/8b.jpg);");
    Carta NoveBastoni = Carta(9,2,3,"border-image: url(:/carte/carte/9b.jpg);");
    Carta ReBastoni =  Carta(10,2,4,"border-image: url(:/carte/carte/10b.jpg);");

    //spade
    Carta AssoSpade = Carta(12,3,11,"border-image: url(:/carte/carte/1s.jpg);");
    Carta DueSpade = Carta(2,3,0,"border-image: url(:/carte/carte/2s.jpg);");
    Carta TreSpade = Carta(11,3,10,"border-image: url(:/carte/carte/3s.jpg);");
    Carta QuattroSpade = Carta(4,3,0,"border-image: url(:/carte/carte/4s.jpg);");
    Carta CinqueSpade = Carta(5,3,0,"border-image: url(:/carte/carte/5s.jpg);");
    Carta SeiSpade = Carta(6,3,0,"border-image: url(:/carte/carte/6s.jpg);");
    Carta SetteSpade = Carta(7,3,0,"border-image: url(:/carte/carte/7s.jpg);");
    Carta OttoSpade = Carta(8,3,2,"border-image: url(:/carte/carte/8s.jpg);");
    Carta NoveSpade = Carta(9,3,3,"border-image: url(:/carte/carte/9s.jpg);");
    Carta ReSpade =  Carta(10,3,4,"border-image: url(:/carte/carte/10s.jpg);");

    //coppe
    Carta AssoCoppe = Carta(12,1,11,"border-image: url(:/carte/carte/1c.jpg);");
    Carta DueCoppe = Carta(2,1,0,"border-image: url(:/carte/carte/2c.jpg);");
    Carta TreCoppe = Carta(11,1,10,"border-image: url(:/carte/carte/3c.jpg);");
    Carta QuattroCoppe = Carta(4,1,0,"border-image: url(:/carte/carte/4c.jpg);");
    Carta CinqueCoppe = Carta(5,1,0,"border-image: url(:/carte/carte/5c.jpg);");
    Carta SeiCoppe = Carta(6,1,0,"border-image: url(:/carte/carte/6c.jpg);");
    Carta SetteCoppe = Carta(7,1,0,"border-image: url(:/carte/carte/7c.jpg);");
    Carta OttoCoppe = Carta(8,1,2,"border-image: url(:/carte/carte/8c.jpg);");
    Carta NoveCoppe = Carta(9,1,3,"border-image: url(:/carte/carte/9c.jpg);");
    Carta ReCoppe =  Carta(10,1,4,"border-image: url(:/carte/carte/10c.jpg);");

    //aggiungo le carte al mazzo

    //denari
    mazzo_iniziale.push_back(AssoDenari);
    mazzo_iniziale.push_back(DueDenari);
    mazzo_iniziale.push_back(TreDenari);
    mazzo_iniziale.push_back(QuattroDenari);
    mazzo_iniziale.push_back(CinqueDenari);
    mazzo_iniziale.push_back(SeiDenari);
    mazzo_iniziale.push_back(SetteDenari);
    mazzo_iniziale.push_back(OttoDenari);
    mazzo_iniziale.push_back(NoveDenari);
    mazzo_iniziale.push_back(ReDenari);

    //bastoni
    mazzo_iniziale.push_back(AssoBastoni);
    mazzo_iniziale.push_back(DueBastoni);
    mazzo_iniziale.push_back(TreBastoni);
    mazzo_iniziale.push_back(QuattroBastoni);
    mazzo_iniziale.push_back(CinqueBastoni);
    mazzo_iniziale.push_back(SeiBastoni);
    mazzo_iniziale.push_back(SetteBastoni);
    mazzo_iniziale.push_back(OttoBastoni);
    mazzo_iniziale.push_back(NoveBastoni);
    mazzo_iniziale.push_back(ReBastoni);

    //spade
    mazzo_iniziale.push_back(AssoSpade);
    mazzo_iniziale.push_back(DueSpade);
    mazzo_iniziale.push_back(TreSpade);
    mazzo_iniziale.push_back(QuattroSpade);
    mazzo_iniziale.push_back(CinqueSpade);
    mazzo_iniziale.push_back(SeiSpade);
    mazzo_iniziale.push_back(SetteSpade);
    mazzo_iniziale.push_back(OttoSpade);
    mazzo_iniziale.push_back(NoveSpade);
    mazzo_iniziale.push_back(ReSpade);

    //coppe
    mazzo_iniziale.push_back(AssoCoppe);
    mazzo_iniziale.push_back(DueCoppe);
    mazzo_iniziale.push_back(TreCoppe);
    mazzo_iniziale.push_back(QuattroCoppe);
    mazzo_iniziale.push_back(CinqueCoppe);
    mazzo_iniziale.push_back(SeiCoppe);
    mazzo_iniziale.push_back(SetteCoppe);
    mazzo_iniziale.push_back(OttoCoppe);
    mazzo_iniziale.push_back(NoveCoppe);
    mazzo_iniziale.push_back(ReCoppe);

    mazzo_iniziale = mescola(mazzo_iniziale);
    stack_mazzo();

}
