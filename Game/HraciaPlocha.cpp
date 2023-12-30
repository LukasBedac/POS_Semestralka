//
// Created by Terezia on 30. 12. 2023.
//

#include "HraciaPlocha.h"
#include <iostream>

HraciaPlocha::HraciaPlocha() {

}

void HraciaPlocha::vytvorPlochu() {
    //ohranicenie
    for (int i = 0; i < plochaVyska; ++i) {
        for (int j = 0; j < plochaSirka; ++j) {
            // Nastavení hranic hrací plochy na znak '*'
            if (i == 0 || i == plochaVyska - 1 || j == 0 || j == plochaSirka - 1) {
                plocha[i][j] = '#';
            } else {
                plocha[i][j] = ' '; // Volné místo uvnitř hrací plochy
            }
        }
    }

    //domceky
    for (int i = 0; i < plochaVyska; ++i) {
        for(int j = 0; j < plochaSirka; ++j) {
            if((i == 1  || i == 2 ) && ( j == 1 || j == 2)) {
                plocha[i][j] = 'z';
            }
            if((i == 1  || i == 2 ) && ( j == 10 || j == 11)) {
                plocha[i][j] = 'm';
            }
            if((i == 10  || i == 11 ) && ( j == 1 || j == 2)) {
                plocha[i][j] = 'c';
            }
            if((i == 10  || i == 11 ) && ( j == 10 || j == 11)) {
                plocha[i][j] = 'r';
            }

        }

    }

    //cesta
    for(int i = 0; i < plochaVyska; ++i) {
        for (int j = 0; j < plochaSirka; ++j) {
            if ((i == 5) && (j == 1 || j == 2 || j == 3 || j == 4 || j == 5)) {
                plocha[i][j] = 'o';
            }
            if ((i == 7) && (j == 1 || j == 2 || j == 3 || j == 4 || j == 5)) {
                plocha[i][j] = 'o';
            }
            if ((i == 6) && (j == 2 || j == 3 || j == 4 || j == 5)) {
                plocha[i][j] = '@';
            }
            if ((i == 6) && (j == 1)) {
                plocha[i][j] = 'o';
            }

            if ((j == 5) && (i == 1 || i == 2 || i == 3 || i == 4)) {
                plocha[i][j] = 'o';
            }
            if ((j == 7) && (i == 1 || i == 2 || i == 3 || i == 4)) {
                plocha[i][j] = 'o';
            }
            if ((j == 6) && (i == 2 || i == 3 || i == 4 || i == 5)) {
                plocha[i][j] = '@';
            }
            if ((j == 6) && (i == 1)) {
                plocha[i][j] = 'o';
            }


            if ((i == 5) && (j == 7 || j == 8 || j == 9 || j == 10 || j == 11)) {
                plocha[i][j] = 'o';
            }
            if ((i == 7) && (j == 7 || j == 8 || j == 9 || j == 10 || j == 11)) {
                plocha[i][j] = 'o';
            }
            if ((i == 6) && (j == 7 || j == 8 || j == 9 || j == 10)) {
                plocha[i][j] = '@';
            }
            if ((i == 6) && (j == 11)) {
                plocha[i][j] = 'o';
            }

            if ((j == 5) && (i == 8 || i == 9 || i == 10 || i == 11)) {
                plocha[i][j] = 'o';
            }
            if ((j == 7) && (i == 8 || i == 9 || i == 10 || i == 11)) {
                plocha[i][j] = 'o';
            }
            if ((j == 6) && (i == 7 || i == 8 || i == 9 || i == 10)) {
                plocha[i][j] = '@';
            }
            if ((j == 6) && (i == 11)) {
                plocha[i][j] = 'o';
            }

        }
    }
}

void HraciaPlocha::vypisPlochu() {
    for (int i = 0; i < plochaVyska; ++i) {
        for (int j = 0; j < plochaSirka; ++j) {
            std::cout << plocha[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

