#ifndef POS_SEMESTRALKA_PLAYER_H
#define POS_SEMESTRALKA_PLAYER_H
#include "Figurka.h"
#include "Kocka.h"

class Player {
private:
    int cisloHraca = 0;
    int zaciatocnaPozicia = 0;
    char znak;
    Figurka figurky[4];
    int pocetFiguriekVDomceku = 0;
    int pocetFigiekNaCeste = 0;
    int pociatocnaSirka = 0;
    int pociatocnaVyska = 0;
    int hod = 0;

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
    int& getHodKockou();
    void setHodKockou(int poslednyHod);
    void posunFigurku(int pocetPolicok, Figurka &figurka);
    int getFigurkyNaCeste(int i);
    void *setFigurkaNaCeste(int cisloFigurky);
    int getPociatocnaSirka();
    int getPociatocnaVyska();

    void setPociatocnaSirka(int x);
    void setPociatocnaVyska(int y);
    int getCisloFigurky(int cislo);
    void setPocetFigurokNaCeste(int pocet);
    int getPocetFigurokNaCeste();
    int vyberFigurkyPriPosune();


    ~Player();

    void pridajFigurkuNaCestu();

    bool maVsetkyFigurkyVDomceku();

    int getZaciatocnaPozicia();
};

#endif //POS_SEMESTRALKA_PLAYER_H
