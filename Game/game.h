//
// Created by Lukas on 30. 12. 2023.
//

#include "HraciaPlocha.h"
#include "Kocka.h"
#include "Player.h"

#ifndef POS_SEMESTRALKA_GAME_H
#define POS_SEMESTRALKA_GAME_H


class game {
private:
    HraciaPlocha hraciaPlocha;
    int pocetHracov = 4;
    Kocka kocka;
    Player hracNaTahu;
    Player* hraci = new Player[5];
    bool spustenaHra = true;
    int cesta[2][40];

    //indexy tych zaciatocnych pozicii jednotlivych hracov
    int zaciatocnaHraca1[2][1] = { {5}, {1}};
    int zaciatocnaHraca2[2][1] = {{1}, {7}};
    int zaciatocnaHraca3[2][1] = {7,11};
    int zaciatocnaHraca4[2][1] = {11,7};


public:
    game();
    void vytvorHraciuPlochu();
    void ukonciHru();
    void kontrolaHry();
    void zahajitHru();
    void zmenaHracaNaTahu();
    void priebehHry();
    void setHracaNaZaciatocnuPoziciu(Player player);
    ~game();
};


#endif //POS_SEMESTRALKA_GAME_H
