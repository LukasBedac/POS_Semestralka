//
// Created by Lukas on 30. 12. 2023.
//

#include "HraciaPlocha.h"
#include "Kocka.h"
#include "Player.h"
#include <vector>

#ifndef POS_SEMESTRALKA_GAME_H
#define POS_SEMESTRALKA_GAME_H

class game {
private:
    HraciaPlocha hraciaPlocha;
    int pocetHracov = 4;
    Kocka kocka;
    Player *hracNaTahu;
    //Player *hraci = new Player[4];
    std::vector<Player*> hraci;
    bool spustenaHra = true;
    char domcekZnak = '*';

public:
    game();
    void vytvorHraciuPlochu();
    void ukonciHru();
    void kontrolaHry();
    bool vybratieZDomceka(Player *hrac);
    void zmenaHracaNaTahu();
    void priebehHry();
    void priradDomceky();
    void vyhodeniePanacika(Player *hrac);
    void vybratieFigurkyZDomceka(Player  *hrac, int hodHraca, int cisloVyberanejFigurky);
    void figurkaDoKoncovehoDomceka(Player  *hrac, int hodHraca, int cisloVyberanejFigurky);
    void posunFigurkyPoHracejPloche(Player  *hrac, int hodHraca, int cisloVyberanejFigurky);
    void posunVKoncovomDomceku(Player  *hrac, int hodHraca, int cisloVyberanejFigurky);
    //int vyberFigurkyPriPosune(Player *hrac);
    bool getSpustenaHra();
    void pridelHracov(Player &hrac1, Player &hrac2, Player &hrac3, Player &hrac4);
    int getPocetHracov();
    void prvyPosunPanacika(Player *hrac, int hodKockou, int cisloVyberanejFigurky);
    void daniePanacikaNaZaciatok(Player *hrac, int hodKockou, int cisloVyberanejFigurky);

    ~game();

    void novyHracZDomceka(int cisloVyberanejFigurky, int hodHraca);
    Player &getHracNaTahu();
    int vybratieFigurkyZDomceku(bool a);
    bool vyberAkcie();
    void setHracNaTahu(Player *player);

    char vypisPlochuPreKlienta(int riadok, int stlpec);

    int vyberFigurkyPriPosune(Player *hrac);
};

#endif //POS_SEMESTRALKA_GAME_H
