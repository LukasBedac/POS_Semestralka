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
    hraci[0].setZaciatocnaPozicia(1);
    hraci[1].setZaciatocnaPozicia(11);
    hraci[2].setZaciatocnaPozicia(21);
    hraci[3].setZaciatocnaPozicia(31);

    for (int i = 0; i < pocetHracov; ++i) {
        hraci[i].setCisloHraca(i + 1);
    }

    hraci[0].setZnak('z');
    hraci[1].setZnak('m');
    hraci[2].setZnak('c');
    hraci[3].setZnak('r');

    hraci[0].setPociatocnaSirka(1);
    hraci[0].setPociatocnaVyska(7);

    hraci[1].setPociatocnaSirka(5);
    hraci[1].setPociatocnaVyska(1);

    hraci[2].setPociatocnaSirka(11);
    hraci[2].setPociatocnaVyska(7);

    hraci[3].setPociatocnaSirka(5);
    hraci[3].setPociatocnaVyska(11);

    this->vytvorHraciuPlochu();
    hraciaPlocha.nastavCestu();

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
                int hodHraca = kocka.hodKockou();
                std::cout << "hrac " << hracNaTahu.getCisloHraca() << " hodil " << hodHraca << std::endl;
                hracNaTahu.movePlayer(hodHraca, hracNaTahu);
                hraciaPlocha.nastavZnak(hracNaTahu.getPociatocnaVyska(),hracNaTahu.getPociatocnaSirka(),hracNaTahu.getZnak());
                break;
            }
        }
        zmenaHracaNaTahu();
    }
}

void game::zmenaHracaNaTahu() {
    int indexAktualnehoHraca = hracNaTahu.getCisloHraca();
    indexAktualnehoHraca++;
    if(indexAktualnehoHraca > 4) {
        indexAktualnehoHraca = 1;
    }
    hracNaTahu = hraci[indexAktualnehoHraca];
}

void game::priebehHry() {
    while(spustenaHra) {
        //zmenaHracaNaTahu();
        //hraciaPlocha.vypisPlochu();
        hracNaTahu.movePlayer(hracNaTahu.hodKockou(kocka), hracNaTahu);
        hraciaPlocha.vypisPlochu();
        zmenaHracaNaTahu();
    }
}

game::~game() {
    delete[] hraci;
}

void game::setHracaNaZaciatocnuPoziciu(Player player) {

}




