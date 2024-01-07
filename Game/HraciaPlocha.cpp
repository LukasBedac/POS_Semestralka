
#include "HraciaPlocha.h"
#include "Figurka.h"
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
    std::cout << "------ VYPIS PLOCHY ------" << std::endl;
    for (int i = 0; i < plochaSirka; ++i) {
        for (int j = 0; j < plochaVyska; ++j) {
            std::cout << plocha[i][j].getZnak() << ' ';
        }
        std::cout << std::endl;
    }

    std::cout << ' ' << std::endl;
}

void HraciaPlocha::nastavZnak(int pozicia, char znak, int hodKockou) {

    int predchadzajucaPozicia = (pozicia - hodKockou + 40) % 40;

// Nastavenie znaku na znak cesty pre predchádzajúcu pozíciu
    plocha[cesta[predchadzajucaPozicia].getRiadok()][cesta[predchadzajucaPozicia].getStlpec()].setZnak('o');

// Ak panáčik mení políčko, zníž počet hráčov na predchádzajúcom políčku
    if (hodKockou != 0) {
        plocha[cesta[predchadzajucaPozicia].getRiadok()][cesta[predchadzajucaPozicia].getStlpec()].znisPocetHracovNaPolicku();
        //std::cout << "pocet hracov na policku " << cesta[predchadzajucaPozicia].getStlpec() << " " << cesta[predchadzajucaPozicia].getRiadok() << " je " << plocha[cesta[predchadzajucaPozicia].getRiadok()][cesta[predchadzajucaPozicia].getStlpec()].getPocetHracovNaPolicku() << std::endl;
    }

// Nastavenie nového znaku a zvýšenie počtu hráčov na aktuálnom políčku
    plocha[cesta[pozicia].getRiadok()][cesta[pozicia].getStlpec()].setZnak(znak);
    plocha[cesta[pozicia].getRiadok()][cesta[pozicia].getStlpec()].pridajPocetHracovNaPolicku();
    //std::cout << "pocet hracov na policku " << cesta[pozicia].getRiadok() << " " << cesta[pozicia].getStlpec() << " je " << plocha[cesta[pozicia].getRiadok()][cesta[pozicia].getStlpec()].getPocetHracovNaPolicku() << std::endl;
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

void HraciaPlocha::nastavKoniec(Figurka *figurka, int pozicia, int vzdialenost, char znak, int hodKockou) {

    int predchadzajuca = pozicia;

    int pocetPolicok = hodKockou - (39 - vzdialenost);

    //pomocny vypis
    std::cout << hodKockou << std::endl;
    std::cout << vzdialenost << std::endl;
    std::cout << pocetPolicok << std::endl;

    if(znak == 'z') {
        if(this->kontrolaFigurkaMozeIstDoDomceka(1 + pocetPolicok, 6)) {
            return;
        }
        figurka->setRiadok(1 + pocetPolicok);
        figurka->setStlpec(6);
        plocha[1 + pocetPolicok][6].setZnak('z');
        plocha[1 + pocetPolicok][6].pridajPocetHracovNaPolicku();
        this->vyhodenieZCyklu = false;
    } else if (znak == 'm') {
        if(this->kontrolaFigurkaMozeIstDoDomceka(6, 1 + pocetPolicok)) {
            return;
        };
        figurka->setRiadok(6);
        figurka->setStlpec(1 + pocetPolicok);
        plocha[6][1 + pocetPolicok].setZnak('m');
        plocha[6][1 + pocetPolicok].pridajPocetHracovNaPolicku();
        this->vyhodenieZCyklu = false;
    } else if (znak == 'r') {
        if(this->kontrolaFigurkaMozeIstDoDomceka(11 - pocetPolicok, 6)) {
            return;
        };
        figurka->setRiadok(11 - pocetPolicok);
        figurka->setStlpec(6);
        plocha[11 - pocetPolicok][6].setZnak('r');
        plocha[11 - pocetPolicok][6].pridajPocetHracovNaPolicku();
        this->vyhodenieZCyklu = false;
    } else if (znak == 'f') {
        if(this->kontrolaFigurkaMozeIstDoDomceka(6, 11 - pocetPolicok)) {
            return;
        };
        figurka->setRiadok(6);
        figurka->setStlpec(11 - pocetPolicok);
        plocha[6][11 - pocetPolicok].setZnak('f');
        plocha[6][11 - pocetPolicok].pridajPocetHracovNaPolicku();
        this->vyhodenieZCyklu = false;
    }
    plocha[cesta[predchadzajuca].getRiadok()][cesta[predchadzajuca].getStlpec()].setZnak('o');
}

Policko *HraciaPlocha::getCestaSIndexom(int index) {
    return &this->cesta[index];
}

bool HraciaPlocha::kontrolaFigurkaMozeIstDoDomceka(int sirka, int vyska) {
    if(plocha[sirka][vyska].getPocetHracovNaPolicku() >= 1) {
        plocha[sirka][vyska].setFigurkaMozeIstDoDomceka(false);
        this->vyhodenieZCyklu = true;
        return true;
    }
    return false;
}

bool HraciaPlocha::getVyhodenieZCyklu() {
    return this->vyhodenieZCyklu;
}

void HraciaPlocha::setVyhodenieZCyklu(bool b) {
    this->vyhodenieZCyklu = b;
}

void HraciaPlocha::nastavKoniecVKoncovomDomceku(Figurka *figurka, int pozicia, int vzdialenost, char znak, int hodKockou) {
    //nastavenie znaku na znak cest
    //vzdialenost = (vzdialenost + hodKockou)  % 40;

    int predchadzajuciRiadok = figurka->getRiadok();
    int predchadzajuciStlpec = figurka->getStlpec();

    //pomocny vypis
    std::cout << hodKockou << std::endl;

    if(znak == 'z') {
        if(this->kontrolaFigurkaMozeIstDoDomceka(predchadzajuciRiadok + hodKockou, 6)) {
            return;
        };
        if(predchadzajuciRiadok + hodKockou > 5) {
            this->vyhodenieZCyklu = true;
            return;
        }
        figurka->setRiadok(predchadzajuciRiadok + hodKockou);
        figurka->setStlpec(6);
        plocha[predchadzajuciRiadok + hodKockou][6].setZnak('z');
        plocha[predchadzajuciRiadok + hodKockou][6].setPocetHracovNaPolicku(1);
    } else if (znak == 'm') {
        if(this->kontrolaFigurkaMozeIstDoDomceka(6, 1 + predchadzajuciStlpec)) {
            return;
        };
        if(hodKockou + predchadzajuciStlpec > 5) {
            this->vyhodenieZCyklu = true;
            return;
        }
        figurka->setRiadok(6);
        figurka->setStlpec(hodKockou + predchadzajuciStlpec);
        plocha[6][hodKockou + predchadzajuciStlpec].setZnak('m');
        plocha[6][hodKockou + predchadzajuciStlpec].setPocetHracovNaPolicku(1);
    } else if (znak == 'r') {
        if(this->kontrolaFigurkaMozeIstDoDomceka(predchadzajuciRiadok - hodKockou, 6)) {
            return;
        };
        if(predchadzajuciRiadok - hodKockou < 7) {
            this->vyhodenieZCyklu = true;
            return;
        }
        figurka->setRiadok(predchadzajuciRiadok - hodKockou);
        figurka->setStlpec(6);
        plocha[predchadzajuciRiadok - hodKockou][6].setZnak('r');
        plocha[predchadzajuciRiadok - hodKockou][6].setPocetHracovNaPolicku(1);
    } else if (znak == 'f') {
        if(this->kontrolaFigurkaMozeIstDoDomceka(6, predchadzajuciStlpec - hodKockou)) {
            return;
        };
        if(predchadzajuciStlpec - hodKockou < 7) {
            this->vyhodenieZCyklu = true;
            return;
        }
        figurka->setRiadok(6);
        figurka->setStlpec(predchadzajuciStlpec - hodKockou);
        plocha[6][predchadzajuciStlpec - hodKockou].setZnak('f');
        plocha[6][predchadzajuciStlpec - hodKockou].setPocetHracovNaPolicku(1);

    }
    plocha[predchadzajuciRiadok][predchadzajuciStlpec].setPocetHracovNaPolicku(0);
    plocha[predchadzajuciRiadok][predchadzajuciStlpec].setZnak('@');
}






