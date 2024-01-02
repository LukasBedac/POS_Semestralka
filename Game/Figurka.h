//
// Created by Terezia on 30. 12. 2023.
//

#ifndef UNTILTED_FIGURKA_H
#define UNTILTED_FIGURKA_H


#include "Policko.h"

class Figurka {
private:
    char znak;
    int pozicia;
    Policko domcek;
    int stlpec;
    int riadok;
    bool vDomceku = true;

public:
    Figurka();
    ~Figurka();
    void setZnak(char znak);
    char getZnak();
    int getPozicia();
    void setPozicia(int pozicia);
    void posun();
    void setDomcek(Policko domcek);
    Policko &getDomcek();
    int getStlpec();
    int getRiadok();
    void setRiadok(int riadok);
    void setStlpec(int stlpec);
    bool getVDomceku();
    void setVDomceku(bool b);
};


#endif //UNTILTED_FIGURKA_H
