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
        hraci[i].setCisloHraca(i );
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

    //vybratieZDomceka();
    priebehHry();


}

void game::kontrolaHry() {

}

void game::vybratieZDomceka() {

        int hodKockou = 0;
        for(int j = 0; j < 3; j++) {
            //hodKockou = 6; // TERAZ NASCHVAL
            hodKockou = hracNaTahu.hodKockou(kocka);

            if(hodKockou == 6) {
                hracNaTahu = hraci[hracNaTahu.getCisloHraca()];
                std::cout << "hrac " << hracNaTahu.getCisloHraca() << " hodil " << hodKockou << std::endl;
                hraciaPlocha.nastavZnak(hracNaTahu.getPociatocnaPozicia(), hracNaTahu.getZnak(), hodKockou);
                hracNaTahu.vybratFigurkuZDomceka();
                hracNaTahu.pridajFigurkuNaCestu();

                hraciaPlocha.vypisPlochu();

                hodKockou = hracNaTahu.hodKockou(kocka);
                std::cout << "hrac " << hracNaTahu.getCisloHraca() << " hodil " << hodKockou << std::endl;

                hracNaTahu.posunFigurku(hodKockou, hracNaTahu.getFigurka(0));
                hraciaPlocha.nastavZnak(hracNaTahu.getFigurka(0).getPozicia(), hracNaTahu.getZnak(), hodKockou);

                hodKockou = 0;
                hraciaPlocha.vypisPlochu();
                zmenaHracaNaTahu();
                break;

            }
        }

}


void game::zmenaHracaNaTahu() {
    int indexAktualnehoHraca = hracNaTahu.getCisloHraca();
    indexAktualnehoHraca++;
    if(indexAktualnehoHraca > 3) {
        indexAktualnehoHraca = 0;
    }
    hracNaTahu = hraci[indexAktualnehoHraca];
}

void game::priebehHry() {
    for(int i = 0; i < 40; i++) {

        if(hracNaTahu.getPocetFiguriekVDomceku() == 4) {
            vybratieZDomceka();
        } else {
            int hodHraca = hracNaTahu.hodKockou(kocka);
            std::cout << "hrac " << hracNaTahu.getCisloHraca() << " hodil " << hodHraca << std::endl;
            hracNaTahu.posunFigurku(hodHraca, hracNaTahu.getFigurka(0));
            hraciaPlocha.nastavZnak(hracNaTahu.getFigurka(0).getPozicia(), hracNaTahu.getZnak(), hodHraca);
            zmenaHracaNaTahu();
        }
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




