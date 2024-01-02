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
    this->hraciaPlocha.pridelDomceky();
    this->priradDomceky();


    hracNaTahu = &hraci[0];

    //vybratieZDomceka();
    priebehHry();


}

void game::kontrolaHry() {

}

void game::vybratieZDomceka(Player *hrac, int cisloVyberanejFigurky) {

    int hodKockou = 0;
    for(int j = 0; j < 3; j++) {
        hodKockou = hrac->hodKockou(kocka);

        if(hodKockou == 6) {
            std::cout << ">> hrac " << hrac->getZnak() << " hodil " << hodKockou << std::endl;
            hraciaPlocha.nastavZnak(hrac->getPociatocnaPozicia(), hrac->getZnak(), 0);

            hrac->setPocetFiguriekVDomceku(hrac->getPocetFiguriekVDomceku() - 1);
            hracNaTahu->getFigurka(cisloVyberanejFigurky).setVDomceku(false);
            hraciaPlocha.nastavDomcek(hrac->getFigurka(cisloVyberanejFigurky).getDomcek().getRiadok(), hrac->getFigurka(cisloVyberanejFigurky).getDomcek().getStlpec(), '*');
            hrac->pridajFigurkuNaCestu();

            hraciaPlocha.vypisPlochu();

            hodKockou = hrac->hodKockou(kocka);
            std::cout << ">> hrac " << hrac->getZnak() << " hodil " << hodKockou << std::endl;

            hrac->posunFigurku(hodKockou, hrac->getFigurka(cisloVyberanejFigurky));
            hraciaPlocha.nastavZnak(hrac->getFigurka(cisloVyberanejFigurky).getPozicia(), hrac->getZnak(), hodKockou);

            hodKockou = 0;
            hraciaPlocha.vypisPlochu();
            zmenaHracaNaTahu();
            return;
        }

    }
    std::cout << ">> hrac " << hrac->getZnak() << " nehodil na tri pokusy cislo 6 " << std::endl;
    std::cout << " " << std::endl;
    zmenaHracaNaTahu();
}


void game::zmenaHracaNaTahu() {
    int indexAktualnehoHraca = hracNaTahu->getCisloHraca();
    indexAktualnehoHraca++;
    if(indexAktualnehoHraca > 3) {
        indexAktualnehoHraca = 0;
    }
    hracNaTahu = &hraci[indexAktualnehoHraca];
}

void game::priebehHry() {
    int cisloVyberanejFigurky = 1;
    for(int i = 0; i < 30; i++) {

        //int cisloVyberanejFigurky = rand() % hracNaTahu->getPocetFiguriekVDomceku();

        if(hracNaTahu->pocetFigurokVHre() == 0) {
            cisloVyberanejFigurky = rand() % hracNaTahu->getPocetFiguriekVDomceku();
            vybratieZDomceka(hracNaTahu, cisloVyberanejFigurky);
        } else {

            int hodHraca = hracNaTahu->hodKockou(kocka);
            std::cout << ">> hrac " << hracNaTahu->getZnak() << " hodil " << hodHraca << std::endl;

            //int cisloVyberanejFigurky = 0; // ako index figurky ktoru vyberieme

            if (hodHraca == 6) {
                while(!hracNaTahu->getFigurka(cisloVyberanejFigurky).getVDomceku()) {
                    cisloVyberanejFigurky = rand() % hracNaTahu->getPocetFiguriekVDomceku();
                }

                std::cout << ">> hrac " << hracNaTahu->getZnak() << " vybera dalsiu figurku z domceka " << std::endl;

                hracNaTahu->setPocetFiguriekVDomceku(hracNaTahu->getPocetFiguriekVDomceku() - 1);
                hracNaTahu->getFigurka(cisloVyberanejFigurky).setVDomceku(false);
                hraciaPlocha.nastavZnak(hracNaTahu->getFigurka(cisloVyberanejFigurky).getPozicia(), hracNaTahu->getZnak(), hodHraca);
                hraciaPlocha.nastavDomcek(hracNaTahu->getFigurka(cisloVyberanejFigurky).getDomcek().getRiadok(), hracNaTahu->getFigurka(cisloVyberanejFigurky).getDomcek().getStlpec(), '*');
                //hracNaTahu->posunFigurku(hodHraca, hracNaTahu->getFigurka(cisloVyberanejFigurky));
                hracNaTahu->pridajFigurkuNaCestu();
            } else {
                while(hracNaTahu->getFigurka(cisloVyberanejFigurky).getVDomceku()) {
                    cisloVyberanejFigurky = rand() % hracNaTahu->getPocetFiguriekVDomceku();
                }
                hracNaTahu->posunFigurku(hodHraca, hracNaTahu->getFigurka(cisloVyberanejFigurky));
                hraciaPlocha.nastavZnak(hracNaTahu->getFigurka(cisloVyberanejFigurky).getPozicia(), hracNaTahu->getZnak(), hodHraca);

            }

            //vyhodenie hraca
            /*for(int a = 0; a < 4; a++) {
                for(int j = 0; j < 4; j++) {
                    if(hracNaTahu->getFigurka(cisloVyberanejFigurky).getPozicia() == hraci[a].getFigurka(j).getPozicia() && hracNaTahu->getFigurka(cisloVyberanejFigurky).getZnak() != hraci[a].getFigurka(j).getZnak()) {
                        hraci[a].getFigurka(j).setVDomceku(true);
                        hraciaPlocha.nastavDomcek(hraci[a].getFigurka(j).getDomcek().getRiadok(), hraci[a].getFigurka(j).getDomcek().getStlpec(), hraci[a].getFigurka(j).getZnak());
                        std::cout << ">> hrac " << hracNaTahu->getZnak() << "vyhodil hraca " << hraci[a].getZnak() << std::endl;

                    }
                }
            }*/

            hraciaPlocha.vypisPlochu();
            zmenaHracaNaTahu();
        }

    }
}

game::~game() {
    //delete[] hraci;
}

void game::setHracaNaZaciatocnuPoziciu(Player player) {

}

void game::priradDomceky() {
    for(int i = 0 ; i < 4; i++)  {
        hraci[0].getFigurka(i).setDomcek(hraciaPlocha.getZDomceky()[i]);
    }
    for(int i = 0 ; i < 4; i++)  {
        hraci[1].getFigurka(i).setDomcek(hraciaPlocha.getMDomceky()[i]);
    }

    for(int i = 0 ; i < 4; i++)  {
        hraci[2].getFigurka(i).setDomcek(hraciaPlocha.getRDomceky()[i]);
    }

    for(int i = 0 ; i < 4; i++)  {
        hraci[3].getFigurka(i).setDomcek(hraciaPlocha.getFDomceky()[i]);
    }
}




