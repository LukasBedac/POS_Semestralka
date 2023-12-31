

#include "HraciaPlocha.h"
#include <iostream>

HraciaPlocha::HraciaPlocha() {

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
                plocha[i][j].setZnak('c');
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
                plocha[i][j].setSuradnice(i, j);
            }
            if ((j == 7) && (i == 1 || i == 2 || i == 3 || i == 4 || i == 5)) {
                plocha[i][j].setZnak('o');
                plocha[i][j].setSuradnice(i, j);
            }
            if ((j == 6) && (i == 2 || i == 3 || i == 4 || i == 5)) {
                plocha[i][j].setZnak('@');
                plocha[i][j].setSuradnice(i, j);
            }
            if ((j == 6) && (i == 1)) {
                plocha[i][j].setZnak('o');
                plocha[i][j].setSuradnice(i, j);
            }

            if ((i == 5) && (j == 1 || j == 2 || j == 3 || j == 4)) {
                plocha[i][j].setZnak('o');
                plocha[i][j].setSuradnice(i, j);
            }
            if ((i == 7) && (j == 1 || j == 2 || j == 3 || j == 4)) {
                plocha[i][j].setZnak('o');
                plocha[i][j].setSuradnice(i, j);
            }
            if ((i == 6) && (j == 2 || j == 3 || j == 4 || j == 5)) {
                plocha[i][j].setZnak('@');
                plocha[i][j].setSuradnice(i, j);
            }
            if ((i == 6) && (j == 1)) {
                plocha[i][j].setZnak('o');
                plocha[i][j].setSuradnice(i, j);
            }

            if ((i == 5) && (j == 7 || j == 8 || j == 9 || j == 10 || j == 11)) {
                plocha[i][j].setZnak('o');
                plocha[i][j].setSuradnice(i, j);
            }
            if ((i == 7) && (j == 5 || j == 7 || j == 8 || j == 9 || j == 10 || j == 11)) {
                plocha[i][j].setZnak('o');
                plocha[i][j].setSuradnice(i, j);
            }
            if ((i == 6) && (j == 7 || j == 8 || j == 9 || j == 10)) {
                plocha[i][j].setZnak('@');
                plocha[i][j].setSuradnice(i, j);
            }
            if ((i == 6) && (j == 11)) {
                plocha[i][j].setZnak('o');
                plocha[i][j].setSuradnice(i, j);
            }

            if ((j == 5) && (i == 8 || i == 9 || i == 10 || i == 11)) {
                plocha[i][j].setZnak('o');
                plocha[i][j].setSuradnice(i, j);
            }
            if ((j == 7) && (i == 8 || i == 9 || i == 10 || i == 11)) {
                plocha[i][j].setZnak('o');
                plocha[i][j].setSuradnice(i, j);
            }
            if ((j == 6) && (i == 7 || i == 8 || i == 9 || i == 10)) {
                plocha[i][j].setZnak('@');
                plocha[i][j].setSuradnice(i, j);
            }
            if ((j == 6) && (i == 11)) {
                plocha[i][j].setZnak('o');
                plocha[i][j].setSuradnice(i, j);
            }

        }
    }
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

void HraciaPlocha::nastavZnak(int vyska, int sirka, char znak) {
    plocha[vyska][sirka].setZnak(znak);
}

void HraciaPlocha::nastavCestu() {
    int cyklus = 40;
    int riadok = 2;
    int stlpec = 6;
    for (int i = 0; i < cyklus; ++i) {
        if (i <= 5) {
            this->cesta[i].setSuradnice(stlpec, riadok);
            riadok++;
        }
        if (i > 5 && i < 9) {
            riadok = 6;
            stlpec -= 1;
            this->cesta[i].setSuradnice(stlpec, riadok);
        }
        if (i >= 9 && i < 12) {
            riadok = 7;
            stlpec += 1;
            this->cesta[i].setSuradnice(stlpec, riadok);
        }

    }

}

char HraciaPlocha::getZnak(int vyska, int sirka) {
    return plocha[vyska][sirka].getZnak();
}

