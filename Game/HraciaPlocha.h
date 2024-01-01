

#ifndef POS_SEMESTRALKA_HRACIAPLOCHA_H
#define POS_SEMESTRALKA_HRACIAPLOCHA_H

#include "Policko.h"
#include "Figurka.h"

class HraciaPlocha {
private:
    const static int plochaSirka = 13;
    const static int plochaVyska = 13;
    Policko plocha[plochaSirka][plochaVyska];
    Policko cesta[40];
    Policko zDomceky[4];
    Policko fDomceky[4];
    Policko mDomceky[4];
    Policko rDomceky[4];

public:
    HraciaPlocha();
    void vytvorPlochu();
    void vypisPlochu();
    void nastavZnak(int pozicia, char znak, int hodKockou);
    void nastavCestu();
    char getZnak(int vyska, int sirka);
    int getSirka();
    int getVyska();
    Policko* getZDomceky();
    Policko* getFDomceky();
    Policko* getMDomceky();
    Policko* getRDomceky();
    void pridelDomceky();
    void nastavDomcek(int sirka, int vyska, char znak);

};


#endif //POS_SEMESTRALKA_HRACIAPLOCHA_H
