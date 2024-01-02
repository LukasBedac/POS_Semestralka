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
            hrac->getFigurka(cisloVyberanejFigurky).pridajPrejdenuVzdialenost(hodKockou);
            std::cout << ">> hrac presiel vzdialenost" << hrac->getFigurka(cisloVyberanejFigurky).getPrejdenaVzdialenost() << std::endl;

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
    for(int i = 0; i < 100; i++) {
    //while(this->spustenaHra) {

        if(hracNaTahu->pocetFigurokVHre() == 0) {
            //cisloVyberanejFigurky = rand() % hracNaTahu->getPocetFiguriekVDomceku();
            std::cout << "cislo figurky je " << cisloVyberanejFigurky << std::endl;
            vybratieZDomceka(hracNaTahu, cisloVyberanejFigurky);

        } else {
            int hodHraca = hracNaTahu->hodKockou(kocka);
            if(hracNaTahu->getFigurka(cisloVyberanejFigurky).getPrejdenaVzdialenost() + hodHraca >= 40) {
                if(hracNaTahu->getFigurka(cisloVyberanejFigurky).getPrejdenaVzdialenost() + hodHraca <= 43) {
                    hraciaPlocha.nastavKoniec(hracNaTahu->getFigurka(cisloVyberanejFigurky).getPozicia(), hracNaTahu->getZnak(), hodHraca);
                }
            } else {
                std::cout << ">> hrac " << hracNaTahu->getZnak() << " hodil " << hodHraca << std::endl;

                //int cisloVyberanejFigurky = 0; // ako index figurky ktoru vyberieme

                /*if (hodHraca == 6) {
                    /*while(!hracNaTahu->getFigurka(cisloVyberanejFigurky).getVDomceku()) {
                        cisloVyberanejFigurky = rand() % hracNaTahu->getPocetFiguriekVDomceku();
                    }
                    std::cout << "cislo figurky je " << cisloVyberanejFigurky << std::endl;
                    std::cout << ">> hrac " << hracNaTahu->getZnak() << " vybera dalsiu figurku z domceka " << std::endl;

                    hracNaTahu->setPocetFiguriekVDomceku(hracNaTahu->getPocetFiguriekVDomceku() - 1);
                    hracNaTahu->getFigurka(cisloVyberanejFigurky).setVDomceku(false);
                    hraciaPlocha.nastavZnak(hracNaTahu->getFigurka(cisloVyberanejFigurky).getPozicia(), hracNaTahu->getZnak(), hodHraca);
                    hraciaPlocha.nastavDomcek(hracNaTahu->getFigurka(cisloVyberanejFigurky).getDomcek().getRiadok(), hracNaTahu->getFigurka(cisloVyberanejFigurky).getDomcek().getStlpec(), '*');
                    //hracNaTahu->posunFigurku(hodHraca, hracNaTahu->getFigurka(cisloVyberanejFigurky));
                    hracNaTahu->pridajFigurkuNaCestu();
                } else {  */
                /*while(hracNaTahu->getFigurka(cisloVyberanejFigurky).getVDomceku()) {
                    cisloVyberanejFigurky = rand() % hracNaTahu->getPocetFiguriekVDomceku();
                }*/

                std::cout << "cislo figurky je " << cisloVyberanejFigurky << std::endl;
                hracNaTahu->getFigurka(cisloVyberanejFigurky).pridajPrejdenuVzdialenost(hodHraca);
                std::cout << ">> hrac presiel vzdialenost" << hracNaTahu->getFigurka(cisloVyberanejFigurky).getPrejdenaVzdialenost() << std::endl;
                hracNaTahu->posunFigurku(hodHraca, hracNaTahu->getFigurka(cisloVyberanejFigurky));
                hraciaPlocha.nastavZnak(hracNaTahu->getFigurka(cisloVyberanejFigurky).getPozicia(), hracNaTahu->getZnak(), hodHraca);

                //vyhodenie hraca
                for(int a = 0; a < 4; a++) {
                    for(int j = 0; j < 4; j++) {
                        if(hracNaTahu->getFigurka(cisloVyberanejFigurky).getPozicia() == hraci[a].getFigurka(j).getPozicia() /*&& hracNaTahu->getFigurka(cisloVyberanejFigurky).getZnak() != hraci[a].getFigurka(j).getZnak()*/) {
                            hraci[a].getFigurka(j).setVDomceku(true);
                            hraciaPlocha.nastavDomcek(hraci[a].getFigurka(j).getDomcek().getRiadok(), hraci[a].getFigurka(j).getDomcek().getStlpec(), hraci[a].getFigurka(j).getZnak());
                            std::cout << ">> hrac " << hracNaTahu->getZnak() << "vyhodil hraca " << hraci[a].getZnak() << std::endl;

                        }
                    }
                }

                hraciaPlocha.vypisPlochu();
                zmenaHracaNaTahu();
            }

        }

            //hraciaPlocha.vypisPlochu();
            //zmenaHracaNaTahu();
        }

    }
//}

game::~game() {
    delete[] hraci;
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




