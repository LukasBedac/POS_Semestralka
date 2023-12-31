

#include "game.h"

void game::vytvorHraciuPlochu() {
    hraciaPlocha.vytvorPlochu();
    hraciaPlocha.vypisPlochu();
}

void game::ukonciHru() {

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

    this->vytvorHraciuPlochu();
    zahajitHru();
    priebehHry();

}

void game::kontrolaHry() {

}

void game::zahajitHru() {
    int hodKockou = 0;
    //while(hodKockou != 6 ) {
        for(int j = 0; j < 3; j++) {
            hodKockou = kocka.hodKockou();
            if(hodKockou == 6) {
                hracNaTahu = hraci[hracNaTahu.getCisloHraca()];
                int hodHraca = kocka.hodKockou();
                hracNaTahu.movePlayer(hodHraca, hracNaTahu);
                //hraciaPlocha[zaciatocnaHraca1[0]][zaciatocnaHraca1[1]] = hracNaTahu.getZnak();

                hraciaPlocha.nastavZnak(5,1,hracNaTahu.getZnak());
                break;
            }
        //}
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
        zmenaHracaNaTahu();
        hraciaPlocha.vypisPlochu();


    }
}

game::~game() {
    delete[] hraci;
}

void game::setHracaNaZaciatocnuPoziciu(Player player) {

}




