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

void game::vybratieZDomceka(Player *hrac) {

    int hodKockou = 0;
    for(int j = 0; j < 3; j++) {
        //hodKockou = 6; // TERAZ NASCHVAL
        hodKockou = hrac->hodKockou(kocka);

        if(hodKockou == 6) {
            hrac = &hraci[hrac->getCisloHraca()];
            std::cout << "hrac " << hrac->getCisloHraca() << " hodil " << hodKockou << std::endl;
            hraciaPlocha.nastavZnak(hrac->getPociatocnaPozicia(), hrac->getZnak(), 0);

            int cisloVyberanejFigurky = hrac->getPocetFiguriekVDomceku() - 1; // ako index figurky ktoru vyberieme


            std::cout << "Pocet figur pred vyberem: " << hrac->getPocetFiguriekVDomceku() << std::endl;

            //hracNaTahu.vybratFigurkuZDomceka(hracNaTahu.getFigurka(cisloVyberanejFigurky));
            hrac->setPocetFiguriekVDomceku(hrac->getPocetFiguriekVDomceku() - 1);

            std::cout << "Pocet figur po vyberu: " << hrac->getPocetFiguriekVDomceku() << std::endl;




            std::cout << " domcek riadok " <<hrac->getFigurka(cisloVyberanejFigurky).getDomcek().getRiadok() << " domcek stlpec " << hrac->getFigurka(cisloVyberanejFigurky).getDomcek().getStlpec() <<std::endl;

            hraciaPlocha.nastavDomcek(hrac->getFigurka(cisloVyberanejFigurky).getDomcek().getRiadok(), hrac->getFigurka(cisloVyberanejFigurky).getDomcek().getStlpec(), '*');
            hrac->pridajFigurkuNaCestu();

            hraciaPlocha.vypisPlochu();

            hodKockou = hrac->hodKockou(kocka);
            std::cout << "hrac " << hrac->getCisloHraca() << " hodil " << hodKockou << std::endl;

            hrac->posunFigurku(hodKockou, hrac->getFigurka(cisloVyberanejFigurky));
            hraciaPlocha.nastavZnak(hrac->getFigurka(cisloVyberanejFigurky).getPozicia(), hrac->getZnak(), hodKockou);

            hodKockou = 0;
            hraciaPlocha.vypisPlochu();
            zmenaHracaNaTahu();
            return;
        }

    }
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
    for(int i = 0; i < 30; i++) {

        //std::cout << hracNaTahu.getCisloHraca() << "  pocet figurok" << hracNaTahu.getPocetFiguriekVDomceku() << std::endl;

        if(hracNaTahu->pocetFigurokVHre() == 0) {
            vybratieZDomceka(hracNaTahu);
        } else {
            int hodHraca = hracNaTahu->hodKockou(kocka);
            std::cout << "hrac " << hracNaTahu->getCisloHraca() << " hodil " << hodHraca << std::endl;

            int cisloVyberanejFigurky = 1; // ako index figurky ktoru vyberieme

            hracNaTahu->posunFigurku(hodHraca, hracNaTahu->getFigurka(cisloVyberanejFigurky));
            hraciaPlocha.nastavZnak(hracNaTahu->getFigurka(cisloVyberanejFigurky).getPozicia(), hracNaTahu->getZnak(), hodHraca);
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
        //std::cout << hraciaPlocha.getZDomceky()[i].getZnak() << std::endl;
        //std::cout<< hraciaPlocha.getZDomceky()[i].getRiadok() << hraciaPlocha.getZDomceky()[i].getStlpec() << std::endl;
    }
    for(int i = 0 ; i < 4; i++)  {
        hraci[1].getFigurka(i).setDomcek(hraciaPlocha.getMDomceky()[i]);
        //std::cout << hraciaPlocha.getMDomceky()[i].getZnak() << std::endl;
        //std::cout<< hraciaPlocha.getMDomceky()[i].getRiadok() << hraciaPlocha.getMDomceky()[i].getStlpec() << std::endl;
    }

    for(int i = 0 ; i < 4; i++)  {
        hraci[2].getFigurka(i).setDomcek(hraciaPlocha.getRDomceky()[i]);
        //std::cout << hraciaPlocha.getRDomceky()[i].getZnak() << std::endl;
        //std::cout<< hraciaPlocha.getRDomceky()[i].getRiadok() << hraciaPlocha.getRDomceky()[i].getStlpec() << std::endl;
    }

    for(int i = 0 ; i < 4; i++)  {
        hraci[3].getFigurka(i).setDomcek(hraciaPlocha.getFDomceky()[i]);
        //std::cout << hraciaPlocha.getFDomceky()[i].getZnak() << std::endl;
        //std::cout<< hraciaPlocha.getFDomceky()[i].getRiadok() << hraciaPlocha.getFDomceky()[i].getStlpec() << std::endl;
    }
}




