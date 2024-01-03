#include <iostream>
#include <string>
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
            hrac->getFigurka(cisloVyberanejFigurky).setVDomceku(false);
            hrac->setFigurkaNaCeste(cisloVyberanejFigurky);
            hraciaPlocha.nastavDomcek(hrac->getFigurka(cisloVyberanejFigurky).getDomcek().getRiadok(),
                                      hrac->getFigurka(cisloVyberanejFigurky).getDomcek().getStlpec(), '*');
            hrac->pridajFigurkuNaCestu();
            hraciaPlocha.vypisPlochu();

            hodKockou = hrac->hodKockou(kocka);
            std::cout << ">> hrac " << hrac->getZnak() << " hodil " << hodKockou << std::endl;

            hrac->posunFigurku(hodKockou, hrac->getFigurka(cisloVyberanejFigurky));
            hrac->getFigurka(cisloVyberanejFigurky).pridajPrejdenuVzdialenost(hodKockou);
            std::cout << ">> hrac presiel vzdialenost" << hrac->getFigurka(cisloVyberanejFigurky).getPrejdenaVzdialenost() << "po hodeni kocky"<< std::endl;
            hraciaPlocha.nastavZnak(hrac->getFigurka(cisloVyberanejFigurky).getPozicia(), hrac->getZnak(), hodKockou);
            hraciaPlocha.vypisPlochu();
            zmenaHracaNaTahu();
            return;
        }

    }
    std::cout << ">> hrac " << hrac->getZnak() << " nehodil na tri pokusy cislo 6 " << std::endl;
    std::cout << " " << std::endl;
    zmenaHracaNaTahu();
}

int game::vybratieFigurkyZDomceku(bool a) {
    int vDomceku[4];;
    int vybranaFigurka = 0;
    for (int i = 0; i < sizeof(vDomceku) / sizeof(vDomceku[0]) ; ++i) { //figurky v domcekoch
        if (hracNaTahu->getFigurkyNaCeste(i) != i) {
            vDomceku[i] = i;
        } else{
            vDomceku[i] = -1;
        }
    }
    if (a) {
        std::cout << "hrac " << hracNaTahu->getZnak() << " vybera dalsiu figurku z domceka " << std::endl;
        std::cout << "Vyberte si figurku z domceku: ";
        for (int i = 0; i < sizeof(vDomceku) / sizeof(vDomceku[0]); ++i) {
            if (vDomceku[i] != -1) {
                std::cout << vDomceku[i] << " ";
            }
        }
        std::cout << std::endl;
        std::cin >> vybranaFigurka;
        std::cout << std::endl;
        if (vybranaFigurka < 0 || vybranaFigurka > 4 || vDomceku[vybranaFigurka] == -1) {
            vybratieFigurkyZDomceku(a);
        } else {
            hracNaTahu->setFigurkaNaCeste(vybranaFigurka);
            return vybranaFigurka;
        }
    } else {
        std::cout << "hrac " << hracNaTahu->getZnak() << " vybera figurku, ktorou sa chce posunut " << std::endl;
        std::cout << "Vyberte si figurku na ceste: ";
        for (int i = 0; i < sizeof(vDomceku) / sizeof(vDomceku[0]); ++i) {
            if (vDomceku[i] == -1) {
                std::cout << hracNaTahu->getFigurkyNaCeste(i) << " ";
            }
        }
        std::cout << std::endl;
        std::cin >> vybranaFigurka;
        std::cout << std::endl;
        if (vybranaFigurka < 0 || vybranaFigurka > 4 || hracNaTahu->getFigurkyNaCeste(vybranaFigurka) == -1) {
            vybratieFigurkyZDomceku(a);
        } else {
            return vybranaFigurka;
        }
    }
}

bool game::vyberAkcie() {
    std::string akcia = "";
    std::cout << "Chcete noveho hraca po hodeni cisla 6?" << std::endl;
    std::cout << "ano nie" << std::endl;
    std::cin >> akcia;
    std::cout << std::endl;
    if (akcia == "ano") {
        return true;
    }else if (akcia == "nie") {

        return false;
    } else {
        std::cout << "Nespravne zadana akcia";
        std::cout << std::endl;
        return vyberAkcie();
    }

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

    int cisloVyberanejFigurky = 0;
    bool chcemNovehohraca = false;
    for(int i = 0; i < 50; i++) {
    //while(this->spustenaHra) {

        if(hracNaTahu->pocetFigurokVHre() == 0) {
            std::cout << "cislo figurky je " << cisloVyberanejFigurky << std::endl;
            vybratieZDomceka(hracNaTahu, cisloVyberanejFigurky);

        } else {

            int hodHraca = hracNaTahu->hodKockou(kocka);
            if(hracNaTahu->getFigurka(cisloVyberanejFigurky).getPrejdenaVzdialenost() + hodHraca >= 40) {
                if(hracNaTahu->getFigurka(cisloVyberanejFigurky).getPrejdenaVzdialenost() + hodHraca >= 44) {
                    return;
                } else {
                    hraciaPlocha.nastavKoniec(hracNaTahu->getFigurka(cisloVyberanejFigurky).getPrejdenaVzdialenost(), hracNaTahu->getZnak(), hodHraca);
                    hraciaPlocha.vypisPlochu();
                    return;
                }
            } else {
                std::cout << ">> hrac " << hracNaTahu->getZnak() << " hodil " << hodHraca << std::endl;
                if (hodHraca == 6) {
                    chcemNovehohraca = vyberAkcie();
                }

                if (chcemNovehohraca) {

                    cisloVyberanejFigurky = vybratieFigurkyZDomceku(chcemNovehohraca);
                    hracNaTahu->setPocetFiguriekVDomceku(hracNaTahu->getPocetFiguriekVDomceku() - 1);
                    hracNaTahu->getFigurka(cisloVyberanejFigurky).setVDomceku(false);
                    //hracNaTahu->setFigurkaNaCeste(cisloVyberanejFigurky);
                    hraciaPlocha.nastavZnak(hracNaTahu->getFigurka(cisloVyberanejFigurky).getPozicia(), hracNaTahu->getZnak(), hodHraca);
                    hraciaPlocha.nastavDomcek(hracNaTahu->getFigurka(cisloVyberanejFigurky).getDomcek().getRiadok(), hracNaTahu->getFigurka(cisloVyberanejFigurky).getDomcek().getStlpec(), '*');
                    //hracNaTahu->posunFigurku(hodHraca, hracNaTahu->getFigurka(cisloVyberanejFigurky));
                    hracNaTahu->pridajFigurkuNaCestu();
                    chcemNovehohraca = false;
                    hraciaPlocha.vypisPlochu();
                    zmenaHracaNaTahu();
                } else {
                    if (hodHraca == 6) {
                        hodHraca += hracNaTahu->hodKockou(kocka);
                        std::cout << "Hrac " << hracNaTahu->getZnak() <<"spolu hodil: " << hodHraca << std::endl;
                    }
                    if (hracNaTahu->getPocetFiguriekVDomceku() != 3) {
                        cisloVyberanejFigurky = vybratieFigurkyZDomceku(chcemNovehohraca);
                    }
                    std::cout << "cislo figurky je " << cisloVyberanejFigurky << std::endl;
                    hracNaTahu->getFigurka(cisloVyberanejFigurky).pridajPrejdenuVzdialenost(hodHraca);
                    std::cout << ">> hrac presiel vzdialenost" << hracNaTahu->getFigurka(cisloVyberanejFigurky).getPrejdenaVzdialenost() << std::endl;
                    hracNaTahu->posunFigurku(hodHraca, hracNaTahu->getFigurka(cisloVyberanejFigurky));
                    hraciaPlocha.nastavZnak(hracNaTahu->getFigurka(cisloVyberanejFigurky).getPozicia(), hracNaTahu->getZnak(), hodHraca);

                    hraciaPlocha.vypisPlochu();
                    zmenaHracaNaTahu();
                }

            }

            //vyhodenie hraca
            for(int a = 0; a < 4; a++) {
                for(int j = 0; j < 4; j++) {
                    if(hracNaTahu->getFigurka(cisloVyberanejFigurky).getPozicia() == hraci[a].getFigurka(j).getPozicia() && hracNaTahu->getFigurka(cisloVyberanejFigurky).getZnak() != hraci[a].getFigurka(j).getZnak()) {
                        hraci[a].getFigurka(j).setVDomceku(true);
                        hraciaPlocha.nastavDomcek(hraci[a].getFigurka(j).getDomcek().getRiadok(), hraci[a].getFigurka(j).getDomcek().getStlpec(), hraci[a].getFigurka(j).getZnak());
                        std::cout << ">> hrac " << hracNaTahu->getZnak() << "vyhodil hraca " << hraci[a].getZnak() << std::endl;

                    }
                }
            }
        }
    }
}

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








