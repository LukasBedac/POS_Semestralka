

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
    Policko zUkonci[4];
    Policko fUkonci[4];
    Policko mUkonci[4];
    Policko rUkonci[4];
    bool vyhodenieZCyklu;

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
    void nastavKoniec(int pozicia, char znak, int hodKockou);

    bool kontrolaFigurkaMozeIstDoDomceka(int sirka, int vyska);

    Policko *getCestaSIndexom(int index);

    Policko *getZUkonci();

    Policko *geFUkonci();

    Policko *geMUkonci();

    Policko *geRUkonci();

    Policko *getCesta();

    bool getVyhodenieZCyklu();

    void setVyhodenieZCyklu(bool b);

    void nastavKoniecVKoncovomDomceku(Figurka *figurka, int pozicia, int vzdialenost, char znak, int hodKockou);

    void nastavKoniec(Figurka *figurka, int pozicia, int vzdialenost, char znak, int hodKockou);
    Policko** getPlocha();
};


#endif //POS_SEMESTRALKA_HRACIAPLOCHA_H
