

#ifndef POS_SEMESTRALKA_PLAYER_H
#define POS_SEMESTRALKA_PLAYER_H
#include "Figurka.h"

class Player {
private:
    int currentPos = 0;
    int cisloHraca = 0;
    int zaciatocnaPozicia = 0;
    char znak;
    bool playerTurn = false;
    Figurka figurky[4];
    int pocetFiguriekVDomceku = 4;

    bool inHome[4] = {false, false, false, false};
    bool win = false;
public:
    Player();
    void movePlayer(int count, Player player);
    bool winCondition(Player player);
    void setZaciatocnaPozicia(int pozicia);
    int getPociatocnaPozicia();
    void setCisloHraca(int cislo);
    int getCisloHraca();
    char getZnak();
    void setZnak(char znak);
    void setPocetFiguriekVDomceku(int pocet);
    int getPocetFiguriekVDomceku();
    void vybratFigurkuZDomceka();

    ~Player();
};


#endif //POS_SEMESTRALKA_PLAYER_H
