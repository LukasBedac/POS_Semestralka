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
    Player *hracNaTahu;
    Player *hraci = new Player[4];
    bool spustenaHra = true;
    char domcekZnak = '*';

public:
    game();
    void vytvorHraciuPlochu();
    void ukonciHru();
    void kontrolaHry();
    void vybratieZDomceka(Player *hrac, int cisloVyberanejFigurky);
    void zmenaHracaNaTahu();
    void priebehHry();
    void priradDomceky();
    ~game();

    int vybratieFigurkyZDomceku(bool a);
    bool vyberAkcie();
};

#endif //POS_SEMESTRALKA_GAME_H
