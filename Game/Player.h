#ifndef POS_SEMESTRALKA_PLAYER_H
#define POS_SEMESTRALKA_PLAYER_H
#include "Figurka.h"
#include "Kocka.h"

class Player {
private:
    int cisloHraca;
    int zaciatocnaPozicia = 0;
    char znak;
    Figurka figurky[4];
    int pocetFiguriekVDomceku = 4;
    int pocetFigiekNaCeste = 0;
    int pociatocnaSirka = 0;
    int pociatocnaVyska = 0;

    int figurkyNaCeste[4] = {-1, -1, -1, -1};
    bool win = false;
public:
    Player();
    void setZaciatocnaPozicia(int pozicia);
    int getPociatocnaPozicia();
    void setCisloHraca(int cislo);
    int getCisloHraca();
    char getZnak();
    void setZnak(char znak);
    void setPocetFiguriekVDomceku(int pocet);
    int getPocetFiguriekVDomceku();
    void vybratFigurkuZDomceka(Figurka& figurka);
    Figurka &getFigurka(int cisloFigurky);
    void nastavZaciatocnePozicieFiguriek(int pozicia);
    int pocetFigurokVHre();

    int hodKockou(Kocka& kocka);
    void posunFigurku(int pocetPolicok, Figurka &figurka);
    int getFigurkyNaCeste(int i);
    void *setFigurkaNaCeste(int cisloFigurky);
    int getPociatocnaSirka();
    int getPociatocnaVyska();

    void setPociatocnaSirka(int x);
    void setPociatocnaVyska(int y);

    ~Player();

    void pridajFigurkuNaCestu();
};

#endif //POS_SEMESTRALKA_PLAYER_H
