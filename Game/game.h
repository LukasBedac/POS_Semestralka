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
    Player* hraci = new Player[4];
    bool spustenaHra = true;

public:
    game();
    void vytvorHraciuPlochu();
    void nastavZaciatocnuPoziciu(Player hrac);
    void ukonciHru();
    void kontrolaHry();
    void vybratieZDomceka();
    void zmenaHracaNaTahu();
    void priebehHry();
    void setHracaNaZaciatocnuPoziciu(Player player);
    ~game();
};

#endif //POS_SEMESTRALKA_GAME_H
