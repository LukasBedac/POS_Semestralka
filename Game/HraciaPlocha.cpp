
#include "HraciaPlocha.h"
#include <iostream>

HraciaPlocha::HraciaPlocha() {
    //nastavCestu();

}

void HraciaPlocha::vytvorPlochu() {
    //ohranicenie
    for (int i = 0; i < plochaSirka; ++i) {
        for (int j = 0; j < plochaVyska; ++j) {

            if (i == 0 || i == plochaSirka - 1 || j == 0 || j == plochaVyska - 1) {
                plocha[i][j].setZnak('#');
            } else {
                plocha[i][j].setZnak(' ');
            }
        }
    }

    //domceky
    for (int i = 0; i < plochaSirka; ++i) {

        for(int j = 0; j < plochaVyska; ++j) {
            if((j == 1  || j == 2 ) && ( i == 1 || i == 2)) {
                plocha[i][j].setZnak('z');
                plocha[i][j].setSuradnice(i, j);
            }
            if((j == 1  || j == 2 ) && ( i == 10 || i == 11)) {
                plocha[i][j].setZnak('m');
                plocha[i][j].setSuradnice(i, j);
            }

            if((j == 10  || j == 11 ) && ( i == 1 || i == 2)) {
                plocha[i][j].setZnak('f');
                plocha[i][j].setSuradnice(i, j);
            }

            if((j == 10  || j == 11 ) && ( i == 10 || i == 11)) {
                plocha[i][j].setZnak('r');
                plocha[i][j].setSuradnice(i, j);
            }

        }

    }

    //cesta
    for(int i = 0; i < plochaSirka; i++) {
        for (int j = 0; j < plochaVyska; j++) {
            if ((j == 5) && (i == 1 || i == 2 || i == 3 || i == 4 || i == 5)) {
                plocha[i][j].setZnak('o');
                plocha[i][j].setSuradnice(i,j);
            }
            if ((j == 7) && (i == 1 || i == 2 || i == 3 || i == 4 || i == 5)) {
                plocha[i][j].setZnak('o');
                plocha[i][j].setSuradnice(i,j);
            }
            if ((j == 6) && (i == 2 || i == 3 || i == 4 || i == 5)) {
                plocha[i][j].setZnak('@');
                plocha[i][j].setSuradnice(i,j);
            }
            if ((j == 6) && (i == 1)) {
                plocha[i][j].setZnak('o');
                plocha[i][j].setSuradnice(i,j);
            }

            if ((i == 5) && (j == 1 || j == 2 || j == 3 || j == 4)) {
                plocha[i][j].setZnak('o');
                plocha[i][j].setSuradnice(i,j);
            }
            if ((i == 7) && (j == 1 || j == 2 || j == 3 || j == 4)) {
                plocha[i][j].setZnak('o');
                plocha[i][j].setSuradnice(i,j);
            }
            if ((i == 6) && (j == 2 || j == 3 || j == 4 || j == 5)) {
                plocha[i][j].setZnak('@');
                plocha[i][j].setSuradnice(i,j);
            }
            if ((i == 6) && (j == 1)) {
                plocha[i][j].setZnak('o');
                plocha[i][j].setSuradnice(i,j);
            }

            if ((i == 5) && (j == 7 || j == 8 || j == 9 || j == 10 || j == 11)) {
                plocha[i][j].setZnak('o');
                plocha[i][j].setSuradnice(i,j);
            }
            if ((i == 7) && (j == 5 || j == 7 || j == 8 || j == 9 || j == 10 || j == 11)) {
                plocha[i][j].setZnak('o');
                plocha[i][j].setSuradnice(i,j);
            }
            if ((i == 6) && (j == 7 || j == 8 || j == 9 || j == 10)) {
                plocha[i][j].setZnak('@');
                plocha[i][j].setSuradnice(i,j);
            }
            if ((i == 6) && (j == 11)) {
                plocha[i][j].setZnak('o');
                plocha[i][j].setSuradnice(i,j);
            }

            if ((j == 5) && (i == 8 || i == 9 || i == 10 || i == 11)) {
                plocha[i][j].setZnak('o');
                plocha[i][j].setSuradnice(i,j);
            }
            if ((j == 7) && (i == 8 || i == 9 || i == 10 || i == 11)) {
                plocha[i][j].setZnak('o');
                plocha[i][j].setSuradnice(i,j);
            }
            if ((j == 6) && (i == 7 || i == 8 || i == 9 || i == 10)) {
                plocha[i][j].setZnak('@');
                plocha[i][j].setSuradnice(i,j);
            }
            if ((j == 6) && (i == 11)) {
                plocha[i][j].setZnak('o');
                plocha[i][j].setSuradnice(i,j);
            }

        }
    }

    //plocha[5][6].setZnak('B'); // RIADOK, STLPEC
}

void HraciaPlocha::vypisPlochu() {
    for (int i = 0; i < plochaSirka; ++i) {
        for (int j = 0; j < plochaVyska; ++j) {
            std::cout << plocha[i][j].getZnak() << ' ';
        }
        std::cout << std::endl;
    }

    std::cout << ' ' << std::endl;
}

void HraciaPlocha::nastavZnak(int pozicia, char znak, int hodKockou) {

    pozicia = pozicia % 40;
    int predchadzajucaPozicia = (pozicia - hodKockou + 40) % 40;

    //nastavenie znaku na znak cest
    plocha[cesta[predchadzajucaPozicia].getRiadok()][cesta[predchadzajucaPozicia].getStlpec()].setZnak('o');
    if(hodKockou != 0) {
        plocha[cesta[predchadzajucaPozicia].getRiadok()][cesta[predchadzajucaPozicia].getStlpec()].znisPocetHracovNaPolicku();
    }
    std::cout << "pocet hracov na policku " << cesta[predchadzajucaPozicia].getStlpec() << " " << cesta[predchadzajucaPozicia].getRiadok() << " je " << plocha[cesta[predchadzajucaPozicia].getRiadok()][cesta[predchadzajucaPozicia].getStlpec()].getPocetHracovNaPolicku()<< std::endl;

    //nastavenie noveho znaku
    plocha[cesta[pozicia].getRiadok()][cesta[pozicia].getStlpec()].setZnak(znak);
    plocha[cesta[pozicia].getRiadok()][cesta[pozicia].getStlpec()].pridajPocetHracovNaPolicku();
    std::cout << "pocet hracov na policku " << cesta[pozicia].getStlpec() << " " << cesta[pozicia].getRiadok() << " je " << plocha[cesta[pozicia].getRiadok()][cesta[pozicia].getStlpec()].getPocetHracovNaPolicku()<< std::endl;

    //std::cout << "SURADNICE STLPEC RIADOK SU " << cesta[pozicia].getStlpec() << " " << cesta[pozicia].getRiadok() << std::endl;
}

void HraciaPlocha::nastavCestu() {
    int cyklus = 40; //matika mi nejde
    int riadok = 0;
    int stlpec = 5;

    for (int i = 0; i < cyklus; ++i) {
        if (i <= 4) {
            riadok++;
            this->cesta[i] = this->plocha[riadok][stlpec];
            zUkonci[i] = this->plocha[riadok + 1][stlpec + 1];

        }
        if (i > 4 && i <= 8) {
            riadok = 5;
            stlpec -= 1;
            this->cesta[i] = this->plocha[riadok][stlpec];
        }
        if (i > 8 && i <= 10) {
            riadok++;
            stlpec = 1;
            this->cesta[i] = this->plocha[riadok][stlpec];
        }
        if (i > 10 && i <= 14) {
            riadok = 7;
            stlpec++;
            this->cesta[i] = this->plocha[riadok][stlpec];
            mUkonci[i - 11] = this->plocha[riadok - 1][stlpec];
        }
        if (i > 14 && i <= 18) {
            riadok += 1;
            stlpec = 5;
            this->cesta[i] = this->plocha[riadok][stlpec];
        }
        if (i > 18 && i <= 20) {
            riadok = 11;
            stlpec++;
            this->cesta[i] = this->plocha[riadok][stlpec];
        }
        if (i > 20 && i <= 24) {
            riadok--;
            stlpec = 7;
            this->cesta[i] = this->plocha[riadok][stlpec];
            rUkonci[i - 21] = this->plocha[riadok][stlpec - 1];
        }
        if (i > 24 && i <= 28) {
            riadok = 7;
            stlpec++;
            this->cesta[i] = this->plocha[riadok][stlpec];
        }
        if (i > 28 && i <= 30) {
            riadok--;
            stlpec = 11;
            this->cesta[i] = this->plocha[riadok][stlpec];
        }
        if (i > 30 && i <= 34) {
            riadok = 5;
            stlpec--;
            this->cesta[i] = this->plocha[riadok][stlpec];
            fUkonci[i - 31] = this->plocha[riadok + 1][stlpec];
        }
        if (i > 34 && i <= 38) {
            riadok--;
            stlpec = 7;
            this->cesta[i] = this->plocha[riadok][stlpec];
        }
        if (i > 38) {
            riadok = 1;
            stlpec = 6;
            this->cesta[i] = this->plocha[riadok][stlpec];
        }
        /* Kontrola vypisu
        std::cout << this->cesta[i].getZnak();
        std::cout << this->plocha[stlpec][riadok].getZnak();
        std::cout << i << std::endl;
        */
    }


}

char HraciaPlocha::getZnak(int vyska, int sirka) {
    return plocha[sirka][vyska].getZnak();
}


int HraciaPlocha::getSirka() {
    return this->plochaSirka;
}

int HraciaPlocha::getVyska() {
    return plochaVyska;
}

Policko *HraciaPlocha::getZDomceky() {
    return this->zDomceky;
}

Policko *HraciaPlocha::getFDomceky() {
    return this->fDomceky;
}

Policko *HraciaPlocha::getMDomceky() {
    return this->mDomceky;
}

Policko *HraciaPlocha::getRDomceky() {
    return this->rDomceky;
}

void HraciaPlocha::pridelDomceky() {
    int indexZ = 0;
    int indexM = 0;
    int indexF = 0;
    int indexR = 0;

    for(int i = 0; i < plochaSirka; i++) {
        for (int j = 0; j < plochaVyska; j++) {
            char znak = plocha[i][j].getZnak();
            if(znak == 'z') {
                zDomceky[indexZ] = plocha[i][j];
                indexZ++;
            } else if (znak == 'm') {
                mDomceky[indexM] = plocha[i][j];
                indexM++;
            } else if (znak == 'f') {
                fDomceky[indexF] = plocha[i][j];
                indexF++;
            } else if (znak == 'r') {
                rDomceky[indexR] = plocha[i][j];
                indexR++;
            }
        }
    }
}

void HraciaPlocha::nastavDomcek(int sirka, int vyska, char znak) {
    plocha[sirka][vyska].setZnak(znak);
}

Policko *HraciaPlocha::getZUkonci() {
    return this->zUkonci;
}

Policko *HraciaPlocha::geFUkonci() {
    return this->fUkonci;
}

Policko *HraciaPlocha::geMUkonci() {
    return this->mUkonci;
}

Policko *HraciaPlocha::geRUkonci() {
    return this->rUkonci;
}

Policko *HraciaPlocha::getCesta() {
    return this->cesta;
}

void HraciaPlocha::nastavKoniec(int pozicia, char znak, int hodKockou) {

    pozicia = pozicia % 40;
    int predchadzajucaPozicia = (pozicia - hodKockou + 40) % 40;

    //nastavenie znaku na znak cest
    plocha[cesta[predchadzajucaPozicia].getRiadok()][cesta[predchadzajucaPozicia].getStlpec()].setZnak('o');

    if(znak == 'z') {
        plocha[zUkonci[pozicia].getRiadok()][zUkonci[pozicia].getStlpec()].setZnak('z');
    } else if (znak == 'm') {
        plocha[mUkonci[pozicia].getRiadok()][mUkonci[pozicia].getStlpec()].setZnak('m');
    } else if (znak == 'r') {
        plocha[rUkonci[pozicia].getRiadok()][rUkonci[pozicia].getStlpec()].setZnak('r');
    } else if (znak == 'f') {
        plocha[fUkonci[pozicia].getRiadok()][fUkonci[pozicia].getStlpec()].setZnak('f');
    }
}




