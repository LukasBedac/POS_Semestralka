#include <iostream>
#include "game.h"

void game::vytvorHraciuPlochu() {
    hraciaPlocha.vytvorPlochu();
    hraciaPlocha.vypisPlochu();
}

void game::ukonciHru() {
    this->spustenaHra = false;
}

game::game() {

    hraci[0].setZaciatocnaPozicia(0);
    hraci[1].setZaciatocnaPozicia(10);
    hraci[2].setZaciatocnaPozicia(20);
    hraci[3].setZaciatocnaPozicia(30);

    for (int i = 0; i < pocetHracov; ++i) {
        hraci[i].setCisloHraca(i + 1);
    }

    hraci[0].setZnak('z');
    hraci[1].setZnak('m');
    hraci[2].setZnak('r');
    hraci[3].setZnak('f');

    /*for(int i = 0; i < 4; i++) {
        nastavZaciatocnuPoziciu(hraci[i]);
    }*/

    this->vytvorHraciuPlochu();
    hraciaPlocha.nastavCestu();

    hracNaTahu = hraci[0];

    zahajitHru();
    priebehHry();


}

void game::kontrolaHry() {

}

void game::zahajitHru() {
    int hodKockou = 0;
    while(hodKockou != 6 ) {
        for(int j = 0; j < 3; j++) {
            hodKockou = kocka.hodKockou();
            if(hodKockou == 6) {
                hracNaTahu = hraci[hracNaTahu.getCisloHraca()];
                hodKockou = 6;
                std::cout << "hrac " << hracNaTahu.getCisloHraca() << " hodil " << hodKockou << std::endl;
                //hracNaTahu.movePlayer(hodHraca, hracNaTahu);
                //hracNaTahu.posunFigurku(hodKockou, hracNaTahu);
                hraciaPlocha.nastavZnak(hracNaTahu.getPociatocnaPozicia(), hracNaTahu.getZnak());
                break;
            }
        }
        zmenaHracaNaTahu();
    }
}

void game::zmenaHracaNaTahu() {
    int indexAktualnehoHraca = hracNaTahu.getCisloHraca() - 1;
    indexAktualnehoHraca++;
    if(indexAktualnehoHraca > 3) {
        indexAktualnehoHraca = 0;
    }
    hracNaTahu = hraci[indexAktualnehoHraca];
}

void game::priebehHry() {
    for(int i = 0; i < 5; i++) {
        //zmenaHracaNaTahu();
        //hraciaPlocha.vypisPlochu();
        //hracNaTahu.movePlayer(hracNaTahu.hodKockou(kocka), hracNaTahu);
        hraciaPlocha.vypisPlochu();

        int hodHraca = hracNaTahu.hodKockou(kocka);
        std::cout << "hrac " << hracNaTahu.getCisloHraca() << " hodil " << hodHraca << std::endl;
        hracNaTahu.posunFigurku(hodHraca, hracNaTahu.getFigurka(0));
        hraciaPlocha.nastavZnak(hracNaTahu.getFigurka(0).getPozicia(), hracNaTahu.getZnak());
        zmenaHracaNaTahu();
    }
}

game::~game() {
    delete[] hraci;
}

void game::setHracaNaZaciatocnuPoziciu(Player player) {

}

void game::nastavZaciatocnuPoziciu(Player hrac) {
    switch (hrac.getZnak()) {
        case 'z':
            hrac.setZaciatocnaPozicia(0);
            break;
        case 'f':
            hrac.setZaciatocnaPozicia(10);
            break;
        case 'm':
            hrac.setZaciatocnaPozicia(20);
            break;
        case 'r':
            hrac.setZaciatocnaPozicia(30);
            break;
    }

}




