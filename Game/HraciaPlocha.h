

#ifndef POS_SEMESTRALKA_HRACIAPLOCHA_H
#define POS_SEMESTRALKA_HRACIAPLOCHA_H

#include "Policko.h"

class HraciaPlocha {
private:
    const static int plochaSirka = 13;
    const static int plochaVyska = 13;
    Policko plocha[plochaSirka][plochaVyska];

public:
    HraciaPlocha();
    void vytvorPlochu();
    void vypisPlochu();
    void nastavZnak(int vyska, int sirka, char znak);
    char getZnak(int vyska, int sirka);
};


#endif //POS_SEMESTRALKA_HRACIAPLOCHA_H
