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

}

void game::kontrolaHry() {
    if(hraci.at(0)->maVsetkyFigurkyVDomceku() && hraci[1]->maVsetkyFigurkyVDomceku() && hraci[2]->maVsetkyFigurkyVDomceku() && hraci[3]->maVsetkyFigurkyVDomceku()) {
        this->spustenaHra = false;
    }
    this->spustenaHra = true;
}

bool game::vybratieZDomceka(Player *hrac) {
    /*int hodKockou;
    for(int pocetPokusov = 0; pocetPokusov < 3; pocetPokusov++) {
        //hodKockou = hracNaTahu->hodKockou(kocka);
        hodKockou = 6;
        if(hodKockou == 6) {
            std::cout << ">> hrac v troch pokusoch hodil 6, moze ist von z domceka" << std::endl;
            std::cout << ">> hrac " << hrac->getZnak() << " hodil " << hodKockou << " - ide von z domceka"<< std::endl;
            this->hracNaTahu->setHodKockou(hodKockou);
            return true;
        }
    }
    return false;*/
    int hodKockou = hracNaTahu->hodKockou(kocka);
    int pocetPokusov = 0;
    while(pocetPokusov <= 4) {
        hodKockou = 6;
        if(hodKockou == 6) {
            std::cout << ">> hrac v troch pokusoch hodil 6, moze ist von z domceka" << std::endl;
            std::cout << ">> hrac " << hrac->getZnak() << " hodil " << hodKockou << " - ide von z domceka"<< std::endl;

            //std::string cisloFigurky = "";
            //std::cout << "Ktoru figurku chcete vybrat z domceka? - 0,1,2,3" << std::endl;
            //std::cin >> cisloFigurky;
            //std::cout << std::endl;
            //cisloVyberanejFigurky = std::stoi(cisloFigurky);
            //cisloVyberanejFigurky = hrac->vyberFigurkyPriPosune(); TO BY TAM AJ TAK NEMALO BYT LEBO TO KLIENT VYBEREA

            /*hraciaPlocha.nastavZnak(hrac->getPociatocnaPozicia(), hrac->getZnak(), 0);
            hrac->getFigurka(cisloVyberanejFigurky).setPozicia(hrac->getZaciatocnaPozicia());
            hrac->setPocetFiguriekVDomceku(hrac->getPocetFiguriekVDomceku() - 1);
            hrac->setPocetFigurokNaCeste(hrac->getPocetFigurokNaCeste() + 1);
            hracNaTahu->getFigurka(cisloVyberanejFigurky).setVDomceku(false);
            hraciaPlocha.nastavDomcek(hrac->getFigurka(cisloVyberanejFigurky).getDomcek().getRiadok(), hrac->getFigurka(cisloVyberanejFigurky).getDomcek().getStlpec(), '*');
            hrac->pridajFigurkuNaCestu();

            hracNaTahu->getFigurka(cisloVyberanejFigurky).setRiadok(hraciaPlocha.getCestaSIndexom(hracNaTahu->getFigurka(cisloVyberanejFigurky).getPozicia())->getRiadok());
            hracNaTahu->getFigurka(cisloVyberanejFigurky).setStlpec(hraciaPlocha.getCestaSIndexom(hracNaTahu->getFigurka(cisloVyberanejFigurky).getPozicia())->getStlpec());

            this->vyhodeniePanacika(hrac);
            hraciaPlocha.vypisPlochu();*/

            /*hodKockou = hrac->hodKockou(kocka);
            std::cout << ">> hrac " << hrac->getZnak() << " hodil " << hodKockou << std::endl;
            //cisloVyberanejFigurky = this->vyberFigurkyPriPosune(hracNaTahu);
            //cisloVyberanejFigurky = hrac->vyberFigurkyPriPosune();
            hrac->posunFigurku(hodKockou, hrac->getFigurka(cisloVyberanejFigurky));

            hracNaTahu->getFigurka(cisloVyberanejFigurky).setRiadok(hraciaPlocha.getCestaSIndexom(hracNaTahu->getFigurka(cisloVyberanejFigurky).getPozicia())->getRiadok());
            hracNaTahu->getFigurka(cisloVyberanejFigurky).setStlpec(hraciaPlocha.getCestaSIndexom(hracNaTahu->getFigurka(cisloVyberanejFigurky).getPozicia())->getStlpec());

            hrac->getFigurka(cisloVyberanejFigurky).pridajPrejdenuVzdialenost(hodKockou);
            std::cout << ">> hrac presiel vzdialenost " << hrac->getFigurka(cisloVyberanejFigurky).getPrejdenaVzdialenost() << std::endl;

            hraciaPlocha.nastavZnak(hrac->getFigurka(cisloVyberanejFigurky).getPozicia(), hrac->getZnak(), hodKockou);

            hodKockou = 0;
            this->vyhodeniePanacika(hrac);
            hraciaPlocha.vypisPlochu();
            zmenaHracaNaTahu();
            return true;*/
            return true;
        } else {
            pocetPokusov++;
        }
        return false;
    }
    //int hodKockou = 0; //TREBA PREPISAT HOD KOCKOU
    /*for(int j = 0; j < 3; j++) {
        //hodKockou = hrac->hodKockou(kocka);
        hodKockou = 6;
        if(hodKockou == 6) {
            std::cout << ">> hrac v troch pokusoch hodil 6, moze ist von z domceka" << std::endl;
            std::cout << ">> hrac " << hrac->getZnak() << " hodil " << hodKockou << " - ide von z domceka"<< std::endl;

            //std::string cisloFigurky = "";
            //std::cout << "Ktoru figurku chcete vybrat z domceka? - 0,1,2,3" << std::endl;
            //std::cin >> cisloFigurky;
            //std::cout << std::endl;
            //cisloVyberanejFigurky = std::stoi(cisloFigurky);
            //cisloVyberanejFigurky = hrac->vyberFigurkyPriPosune(); TO BY TAM AJ TAK NEMALO BYT LEBO TO KLIENT VYBEREA

            hraciaPlocha.nastavZnak(hrac->getPociatocnaPozicia(), hrac->getZnak(), 0);
            hrac->getFigurka(cisloVyberanejFigurky).setPozicia(hrac->getZaciatocnaPozicia());
            hrac->setPocetFiguriekVDomceku(hrac->getPocetFiguriekVDomceku() - 1);
            hrac->setPocetFigurokNaCeste(hrac->getPocetFigurokNaCeste() + 1);
            hracNaTahu->getFigurka(cisloVyberanejFigurky).setVDomceku(false);
            hraciaPlocha.nastavDomcek(hrac->getFigurka(cisloVyberanejFigurky).getDomcek().getRiadok(), hrac->getFigurka(cisloVyberanejFigurky).getDomcek().getStlpec(), '*');
            hrac->pridajFigurkuNaCestu();

            hracNaTahu->getFigurka(cisloVyberanejFigurky).setRiadok(hraciaPlocha.getCestaSIndexom(hracNaTahu->getFigurka(cisloVyberanejFigurky).getPozicia())->getRiadok());
            hracNaTahu->getFigurka(cisloVyberanejFigurky).setStlpec(hraciaPlocha.getCestaSIndexom(hracNaTahu->getFigurka(cisloVyberanejFigurky).getPozicia())->getStlpec());

            this->vyhodeniePanacika(hrac);
            hraciaPlocha.vypisPlochu();

            hodKockou = hrac->hodKockou(kocka);
            std::cout << ">> hrac " << hrac->getZnak() << " hodil " << hodKockou << std::endl;
            //cisloVyberanejFigurky = this->vyberFigurkyPriPosune(hracNaTahu);
            //cisloVyberanejFigurky = hrac->vyberFigurkyPriPosune();
            hrac->posunFigurku(hodKockou, hrac->getFigurka(cisloVyberanejFigurky));

            hracNaTahu->getFigurka(cisloVyberanejFigurky).setRiadok(hraciaPlocha.getCestaSIndexom(hracNaTahu->getFigurka(cisloVyberanejFigurky).getPozicia())->getRiadok());
            hracNaTahu->getFigurka(cisloVyberanejFigurky).setStlpec(hraciaPlocha.getCestaSIndexom(hracNaTahu->getFigurka(cisloVyberanejFigurky).getPozicia())->getStlpec());

            hrac->getFigurka(cisloVyberanejFigurky).pridajPrejdenuVzdialenost(hodKockou);
            std::cout << ">> hrac presiel vzdialenost " << hrac->getFigurka(cisloVyberanejFigurky).getPrejdenaVzdialenost() << std::endl;

            hraciaPlocha.nastavZnak(hrac->getFigurka(cisloVyberanejFigurky).getPozicia(), hrac->getZnak(), hodKockou);

            hodKockou = 0;
            this->vyhodeniePanacika(hrac);
            hraciaPlocha.vypisPlochu();
            zmenaHracaNaTahu();
            return true;
        }

    }*/
}


void game::zmenaHracaNaTahu() {
    int indexAktualnehoHraca = hracNaTahu->getCisloHraca();
    indexAktualnehoHraca++;
    if(indexAktualnehoHraca > 3) {
        indexAktualnehoHraca = 0;
    }

    while(hraci.at(indexAktualnehoHraca)->maVsetkyFigurkyVDomceku()) {
        indexAktualnehoHraca++;
        if(indexAktualnehoHraca > 3) {
            indexAktualnehoHraca = 0;
        }
    }

    hracNaTahu = hraci.at(indexAktualnehoHraca);
}

void game::priebehHry() {

    /*int cisloVyberanejFigurky = 0;
    bool chcemNovehohraca = false;

    while (true) {
        if (hracNaTahu->getPocetFigurokNaCeste() == 0) {
            vybratieZDomceka(hracNaTahu);
        } else {
            int hodHraca = hracNaTahu->hodKockou(kocka);
            std::cout << ">> hrac " << hracNaTahu->getZnak() << " hodil " << hodHraca << std::endl;
            //cisloVyberanejFigurky = this->vyberFigurkyPriPosune(hracNaTahu);

            if(hracNaTahu->getFigurka(cisloVyberanejFigurky).getVKoncovomDomceku()) {
                //cisloVyberanejFigurky = this->vyberFigurkyPriPosune(hracNaTahu); // FIX THIS
                cisloVyberanejFigurky = hracNaTahu->vyberFigurkyPriPosune();
                posunVKoncovomDomceku(hracNaTahu, hodHraca, cisloVyberanejFigurky);
                //hraciaPlocha.vypisPlochu(); -> napise sa rovno do metody posunVKoncovomDomceku lebo hra k hracej proche nema pristup
            } else {
                if (hracNaTahu->getFigurka(cisloVyberanejFigurky).getPrejdenaVzdialenost() + hodHraca >= 40) {
                    figurkaDoKoncovehoDomceka(hracNaTahu, hodHraca, cisloVyberanejFigurky);
                        if (hracNaTahu->getFigurka(cisloVyberanejFigurky).getPrejdenaVzdialenost() + hodHraca <= 43) {
                            hraciaPlocha.nastavKoniec(&hracNaTahu->getFigurka(cisloVyberanejFigurky),
                                                      hracNaTahu->getFigurka(cisloVyberanejFigurky).getPozicia(),
                                                      hracNaTahu->getFigurka(cisloVyberanejFigurky).getPrejdenaVzdialenost(),
                                                      hracNaTahu->getZnak(), hodHraca);

                            if (hraciaPlocha.getVyhodenieZCyklu()) {
                                std::cout << "Na tomto mieste v domceku uz stoji figurka" << std::endl;
                                return;
                            }

                            std::cout << "panacik ide do domceka" << std::endl;

                            hracNaTahu->setPocetFiguriekVDomceku(hracNaTahu->getPocetFiguriekVDomceku() + 1);
                            hracNaTahu->getFigurka(cisloVyberanejFigurky).setVKoncovomDomceku(true);
                            hracNaTahu->getFigurka(cisloVyberanejFigurky).pridajPrejdenuVzdialenost(hodHraca);


                            hraciaPlocha.vypisPlochu();
                            //this->vyhodeniePanacika(hracNaTahu);
                            zmenaHracaNaTahu();
                            //return;
                        } else {
                            std::cout << "hrac hodil moc velke cislo, nemoze ist do domceka " << std::endl;
                            continue;
                        }

                } else {
                    if (hodHraca == 6) {
                        chcemNovehohraca = vyberAkcie();
                        if (chcemNovehohraca) {
                            cisloVyberanejFigurky = vybratieFigurkyZDomceku(chcemNovehohraca);
                            hracNaTahu->setPocetFiguriekVDomceku(hracNaTahu->getPocetFiguriekVDomceku() - 1);
                            hracNaTahu->getFigurka(cisloVyberanejFigurky).setVDomceku(false);
                            //hracNaTahu->setFigurkaNaCeste(cisloVyberanejFigurky);
                            hraciaPlocha.nastavZnak(hracNaTahu->getFigurka(cisloVyberanejFigurky).getPozicia(),
                                                    hracNaTahu->getZnak(), hodHraca);
                            hraciaPlocha.nastavDomcek(
                                    hracNaTahu->getFigurka(cisloVyberanejFigurky).getDomcek().getRiadok(),
                                    hracNaTahu->getFigurka(cisloVyberanejFigurky).getDomcek().getStlpec(),
                                    '*');
                            //hracNaTahu->posunFigurku(hodHraca, hracNaTahu->getFigurka(cisloVyberanejFigurky));
                            hracNaTahu->pridajFigurkuNaCestu();
                            posunFigurkyPoHracejPloche(hracNaTahu, hodHraca, cisloVyberanejFigurky);
                            novyHracZDomceka(cisloVyberanejFigurky, hodHraca);
                        } else {
                            //cisloVyberanejFigurky = this->vyberFigurkyPriPosune(hracNaTahu);
                            cisloVyberanejFigurky = hracNaTahu->vyberFigurkyPriPosune();
                            posunFigurkyPoHracejPloche(hracNaTahu, hodHraca, cisloVyberanejFigurky);
                        }
                    } else {
                        //cisloVyberanejFigurky = this->vyberFigurkyPriPosune(hracNaTahu);
                        cisloVyberanejFigurky = hracNaTahu->vyberFigurkyPriPosune();
                        posunFigurkyPoHracejPloche(hracNaTahu, hodHraca, cisloVyberanejFigurky);
                    }

                }
            }

        }


    }*/

}
game::~game() {
    //for (Player* hrac : hraci) {
    //    delete hrac;
    //}
    //hraci.clear();
}

void game::priradDomceky() {
    for(int i = 0 ; i < 4; i++)  {
        hraci.at(0)->getFigurka(i).setDomcek(hraciaPlocha.getZDomceky()[i]);
    }
    for(int i = 0 ; i < 4; i++)  {
        hraci.at(1)->getFigurka(i).setDomcek(hraciaPlocha.getMDomceky()[i]);
    }

    for(int i = 0 ; i < 4; i++)  {
        hraci.at(2)->getFigurka(i).setDomcek(hraciaPlocha.getRDomceky()[i]);
    }

    for(int i = 0 ; i < 4; i++)  {
        hraci.at(3)->getFigurka(i).setDomcek(hraciaPlocha.getFDomceky()[i]);
    }
}

void game::vyhodeniePanacika(Player *hrac) {
    for(int a = 0; a < 4; a++) {
        for(int j = 0; j < 4; j++) {

            Figurka &aktualnaFigurkaNaTahu = hrac->getFigurka(j);
            Figurka &figurkaNaCeste = hraci.at(a)->getFigurka(j);

            if (aktualnaFigurkaNaTahu.getRiadok() == figurkaNaCeste.getRiadok() && aktualnaFigurkaNaTahu.getStlpec() == figurkaNaCeste.getStlpec() && hrac->getZnak() != hraci.at(a)->getZnak() && !aktualnaFigurkaNaTahu.getVDomceku() && !figurkaNaCeste.getVDomceku()) {
                figurkaNaCeste.setVDomceku(true);
                hraci.at(a)->setPocetFiguriekVDomceku(hraci.at(a)->getPocetFiguriekVDomceku() + 1);
                hraci.at(a)->setPocetFigurokNaCeste(hraci.at(a)->getPocetFigurokNaCeste() - 1);
                hraciaPlocha.nastavDomcek(figurkaNaCeste.getDomcek().getRiadok(), figurkaNaCeste.getDomcek().getStlpec(), hraci.at(a)->getZnak());
                std::cout << ">> hrac " << hrac->getZnak() << " vyhodil hraca " << hraci.at(a)->getZnak() << std::endl;
                std::cout << "Kolízia medzi hráčom " << hrac->getZnak() << " a hráčom " << hraci.at(a)->getZnak() << std::endl;

                std::cout << "Pozicia figurky " << aktualnaFigurkaNaTahu.getPozicia() << std::endl;
                std::cout << "Pozicia vyhodenej figurky " << figurkaNaCeste.getPozicia() << std::endl;

                //ZMENA X Y FIGURKY
                figurkaNaCeste.setRiadok(figurkaNaCeste.getDomcek().getRiadok());
                figurkaNaCeste.setStlpec(figurkaNaCeste.getDomcek().getStlpec());
                figurkaNaCeste.setPozicia(-1);

                return;
            }
        }
    }
}

void game::vybratieFigurkyZDomceka(Player  *hrac, int hodHraca, int cisloVyberanejFigurky) {

    if (hrac->getFigurka(cisloVyberanejFigurky).getVDomceku()) {
        std::cout << "tuto  figurku nemozete vybrat z domceka lebo uz je na hracej ploche";
    } else {
        if (hodHraca == 6) {
            std::cout << "cislo figurky je " << cisloVyberanejFigurky << std::endl;
            std::cout << ">> hrac " << hracNaTahu->getZnak() << " vybera dalsiu figurku z domceka " << std::endl;
            hrac->getFigurka(cisloVyberanejFigurky).setPozicia(hrac->getZaciatocnaPozicia());

            hrac->setPocetFiguriekVDomceku(hracNaTahu->getPocetFiguriekVDomceku() - 1);
            hrac->getFigurka(cisloVyberanejFigurky).setVDomceku(false);
            hraciaPlocha.nastavZnak(hracNaTahu->getFigurka(cisloVyberanejFigurky).getPozicia(), hracNaTahu->getZnak(),hodHraca);
            hraciaPlocha.nastavDomcek(hracNaTahu->getFigurka(cisloVyberanejFigurky).getDomcek().getRiadok(),hracNaTahu->getFigurka(cisloVyberanejFigurky).getDomcek().getStlpec(), '*');
            //hracNaTahu->posunFigurku(hodHraca, hracNaTahu->getFigurka(cisloVyberanejFigurky)); // NEMOZE SA POSUNUT LEBO JE LEN NA ZACIATOCNEJ POZICII
            hrac->pridajFigurkuNaCestu();
        }

    }
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



void game::figurkaDoKoncovehoDomceka(Player *hrac, int hodHraca, int cisloVyberanejFigurky) {
    int i = hrac->getFigurka(cisloVyberanejFigurky).getPrejdenaVzdialenost() + hodHraca;
    //std::cout << ">> hrac " << hrac->getZnak() << " hodil " << hodHraca << std::endl;
    // std::cout << "VYSLEDOK " << hrac->getFigurka(cisloVyberanejFigurky).getPrejdenaVzdialenost() << std::endl;
    if (hrac->getFigurka(cisloVyberanejFigurky).getPrejdenaVzdialenost() + hodHraca >= 40) {
        if (hrac->getFigurka(cisloVyberanejFigurky).getPrejdenaVzdialenost() + hodHraca <= 43) {

            hraciaPlocha.nastavKoniec(&hrac->getFigurka(cisloVyberanejFigurky), hrac->getFigurka(cisloVyberanejFigurky).getPozicia(),hrac->getFigurka(cisloVyberanejFigurky).getPrejdenaVzdialenost(), hrac->getZnak(),hodHraca);
            if (hraciaPlocha.getVyhodenieZCyklu()) {
                std::cout << "Na tomto mieste v domceku uz stoji figurka" << std::endl;
                return;
            }

            hrac->setPocetFiguriekVDomceku(hrac->getPocetFiguriekVDomceku() + 1);
            hrac->getFigurka(cisloVyberanejFigurky).setVKoncovomDomceku(true);
            hrac->getFigurka(cisloVyberanejFigurky).pridajPrejdenuVzdialenost(hodHraca);

            //std::cout << ">> hrac " << hrac->getZnak() << " hodil " << hodHraca << std::endl;
            //std::cout << ">> hrac presiel vzdialenost " << hrac->getFigurka(cisloVyberanejFigurky).getPrejdenaVzdialenost() << std::endl;

            //hraciaPlocha.vypisPlochu();
            //this->vyhodeniePanacika(hracNaTahu);
            //zmenaHracaNaTahu();
            //return;
        }
    }
}

void game::posunFigurkyPoHracejPloche(Player *hrac, int hodHraca, int cisloVyberanejFigurky) {

    if(!hrac->getFigurka(cisloVyberanejFigurky).getVDomceku()) {
        std::cout << ">> hrac " << hrac->getZnak() << " hodil " << hodHraca << std::endl;

        // KOD PRE VYBRATIE FIGURKY Z DOMCEKA

        //std::cout << "cislo figurky je " << cisloVyberanejFigurky << std::endl;
        hrac->getFigurka(cisloVyberanejFigurky).pridajPrejdenuVzdialenost(hodHraca);
        // std::cout << ">> hrac presiel vzdialenost " << hrac->getFigurka(cisloVyberanejFigurky).getPrejdenaVzdialenost() << std::endl;
        hrac->posunFigurku(hodHraca, hrac->getFigurka(cisloVyberanejFigurky));

        hrac->getFigurka(cisloVyberanejFigurky).setRiadok(hraciaPlocha.getCestaSIndexom(hracNaTahu->getFigurka(cisloVyberanejFigurky).getPozicia())->getRiadok());
        hrac->getFigurka(cisloVyberanejFigurky).setStlpec(hraciaPlocha.getCestaSIndexom(hracNaTahu->getFigurka(cisloVyberanejFigurky).getPozicia())->getStlpec());

        hraciaPlocha.nastavZnak(hrac->getFigurka(cisloVyberanejFigurky).getPozicia(), hrac->getZnak(), hodHraca);
        this->vyhodeniePanacika(hrac);
        hraciaPlocha.vypisPlochu();
        zmenaHracaNaTahu();
    }
}

void game::posunVKoncovomDomceku(Player *hrac, int hodHraca, int cisloVyberanejFigurky) {
    if(hrac->getFigurka(cisloVyberanejFigurky).getVKoncovomDomceku()) {
        this->hraciaPlocha.nastavKoniecVKoncovomDomceku(&hrac->getFigurka(cisloVyberanejFigurky), hrac->getFigurka(cisloVyberanejFigurky).getPozicia(),
                                                        hrac->getFigurka(cisloVyberanejFigurky).getPrejdenaVzdialenost(), hrac->getZnak(),
                                                        hodHraca);
        if (hraciaPlocha.getVyhodenieZCyklu()) {
            std::cout << "Na tomto mieste v domceku uz stoji figurka alebo uz sa neda pohnut dalej v domceku" << std::endl;
            return;
        }
    }
}

/*int game::vyberFigurkyPriPosune(Player *hrac) {
    std::string moznosti = "";
    for(int i = 0; i < 4; i++) {
        if(!hrac->getFigurka(i).getVDomceku()) {
            moznosti += std::to_string(i) + " ";
        }
    }
    //std::cout << std::endl;

    std::string cisloFigurkyStr = "";
    std::cout << ">> S ktorou figurkou chcete pohnut? - figurky na hracej ploche -> " << moznosti << std::endl;
    std::cin >> cisloFigurkyStr;
    std::cout << std::endl;

    // Převod řetězce na integer
    int cisloFigurky = std::stoi(cisloFigurkyStr);

    return cisloFigurky;
}*/

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

bool game::getSpustenaHra() {
    return this->spustenaHra;
}

Player &game::getHracNaTahu() {
    return *this->hraci.at(hracNaTahu->getCisloHraca());
}

void game::novyHracZDomceka(int cisloVyberanejFigurky, int hodHraca) {
    hracNaTahu->setPocetFiguriekVDomceku(hracNaTahu->getPocetFiguriekVDomceku() - 1);
    hracNaTahu->getFigurka(cisloVyberanejFigurky).setVDomceku(false);
    //hracNaTahu->setFigurkaNaCeste(cisloVyberanejFigurky);
    hraciaPlocha.nastavZnak(hracNaTahu->getFigurka(cisloVyberanejFigurky).getPozicia(),
                            hracNaTahu->getZnak(), hodHraca);
    hraciaPlocha.nastavDomcek(
            hracNaTahu->getFigurka(cisloVyberanejFigurky).getDomcek().getRiadok(),
            hracNaTahu->getFigurka(cisloVyberanejFigurky).getDomcek().getStlpec(),
            '*');
    //hracNaTahu->posunFigurku(hodHraca, hracNaTahu->getFigurka(cisloVyberanejFigurky));
    hracNaTahu->pridajFigurkuNaCestu();
    posunFigurkyPoHracejPloche(hracNaTahu, hodHraca, cisloVyberanejFigurky);
}

void game::setHracNaTahu(Player *player) {
    this->hracNaTahu = player;
}

void game::pridelHracov(Player &hrac1, Player &hrac2, Player &hrac3, Player &hrac4) {
    //hraci = new Player[4];  // Allocate memory for array of pointers
    //hraci.resize(4);
    hraci.push_back(&hrac1);
    hraci.push_back(&hrac2);
    hraci.push_back(&hrac3);
    hraci.push_back(&hrac4);

    hraci.at(0)->setZaciatocnaPozicia(0);
    hraci.at(1)->setZaciatocnaPozicia(10);
    hraci.at(2)->setZaciatocnaPozicia(20);
    hraci.at(3)->setZaciatocnaPozicia(30);

    hraci.at(0)->setCisloHraca(0);
    hraci.at(1)->setCisloHraca(1);
    hraci.at(2)->setCisloHraca(2);
    hraci.at(3)->setCisloHraca(3);

    hraci.at(0)->setZnak('z');
    hraci.at(1)->setZnak('m');
    hraci.at(2)->setZnak('r');
    hraci.at(3)->setZnak('f');

    this->vytvorHraciuPlochu();
    this->hraciaPlocha.nastavCestu();
    this->hraciaPlocha.pridelDomceky();
    this->priradDomceky();

}

int game::getPocetHracov() {
    int pocetHracov = 0;
    for(int i = 0; i < 4; i++) {
        if(hraci.at(i)->getCisloHraca() == 0) {
            pocetHracov++;
        }
    }
    return pocetHracov;
}

void game::prvyPosunPanacika(Player *hrac, int hodKockou, int cisloVyberanejFigurky) {
    //hodKockou = hrac->hodKockou(kocka);
    std::cout << ">> hrac " << hrac->getZnak() << " hodil " << hodKockou << std::endl;
    //cisloVyberanejFigurky = this->vyberFigurkyPriPosune(hracNaTahu);
    //cisloVyberanejFigurky = hrac->vyberFigurkyPriPosune();
    hrac->posunFigurku(hodKockou, hrac->getFigurka(cisloVyberanejFigurky));

    hracNaTahu->getFigurka(cisloVyberanejFigurky).setRiadok(hraciaPlocha.getCestaSIndexom(hracNaTahu->getFigurka(cisloVyberanejFigurky).getPozicia())->getRiadok());
    hracNaTahu->getFigurka(cisloVyberanejFigurky).setStlpec(hraciaPlocha.getCestaSIndexom(hracNaTahu->getFigurka(cisloVyberanejFigurky).getPozicia())->getStlpec());

    hrac->getFigurka(cisloVyberanejFigurky).pridajPrejdenuVzdialenost(hodKockou);
    std::cout << ">> hrac presiel vzdialenost " << hrac->getFigurka(cisloVyberanejFigurky).getPrejdenaVzdialenost() << std::endl;

    hraciaPlocha.nastavZnak(hrac->getFigurka(cisloVyberanejFigurky).getPozicia(), hrac->getZnak(), hodKockou);

    hodKockou = 0;
    this->vyhodeniePanacika(hrac);
    hraciaPlocha.vypisPlochu();
    zmenaHracaNaTahu();
    return;
}

void game::daniePanacikaNaZaciatok(Player *hrac, int hodKockou, int cisloVyberanejFigurky) {
    hraciaPlocha.nastavZnak(hrac->getPociatocnaPozicia(), hrac->getZnak(), 0);
    hrac->getFigurka(cisloVyberanejFigurky).setPozicia(hrac->getZaciatocnaPozicia());
    hrac->setPocetFiguriekVDomceku(hrac->getPocetFiguriekVDomceku() - 1);
    hrac->setPocetFigurokNaCeste(hrac->getPocetFigurokNaCeste() + 1);
    hracNaTahu->getFigurka(cisloVyberanejFigurky).setVDomceku(false);
    hraciaPlocha.nastavDomcek(hrac->getFigurka(cisloVyberanejFigurky).getDomcek().getRiadok(), hrac->getFigurka(cisloVyberanejFigurky).getDomcek().getStlpec(), '*');
    hrac->pridajFigurkuNaCestu();

    hracNaTahu->getFigurka(cisloVyberanejFigurky).setRiadok(hraciaPlocha.getCestaSIndexom(hracNaTahu->getFigurka(cisloVyberanejFigurky).getPozicia())->getRiadok());
    hracNaTahu->getFigurka(cisloVyberanejFigurky).setStlpec(hraciaPlocha.getCestaSIndexom(hracNaTahu->getFigurka(cisloVyberanejFigurky).getPozicia())->getStlpec());

    this->vyhodeniePanacika(hrac);
    hraciaPlocha.vypisPlochu();
}