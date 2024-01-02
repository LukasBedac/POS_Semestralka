#ifndef POS_SEMESTRALKA_PLAYER_H
#define POS_SEMESTRALKA_PLAYER_H
#include "Figurka.h"
#include "Kocka.h"

class Player {
private:
    int currentPos = 0;
    int cisloHraca;
    int zaciatocnaPozicia = 0;
    char znak;
    bool playerTurn = false;
    Figurka *figurky = new Figurka[4];
    int pocetFiguriekVDomceku = 4;
    int pocetFigiekNaCeste = 0;
    int pociatocnaSirka = 0;
    int pociatocnaVyska = 0;

    bool inHome[4] = {false, false, false, false};
    bool win = false;
public:
    Player();
    bool winCondition(Player& player);
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

    int getPociatocnaSirka();
    int getPociatocnaVyska();

    void setPociatocnaSirka(int x);
    void setPociatocnaVyska(int y);

    ~Player();

    void pridajFigurkuNaCestu();
};

#endif //POS_SEMESTRALKA_PLAYER_H
