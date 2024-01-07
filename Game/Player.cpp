#include <iostream>
#include "Player.h"

void Player::posunFigurku(int pocetPolicok, Figurka &figurka) {
    int novaPozicia = figurka.getPozicia() + pocetPolicok;
    figurka.setPozicia(novaPozicia % 40);
}

void Player::setZaciatocnaPozicia(int pozicia) {
    this->zaciatocnaPozicia = pozicia;
    this->nastavZaciatocnePozicieFiguriek(pozicia);
}

int Player::getPociatocnaPozicia() {
    return this->zaciatocnaPozicia;
}

void Player::setCisloHraca(int cislo) {
    this->cisloHraca = cislo;
}

int Player::getCisloHraca() {
    return this->cisloHraca;
}

Player::Player() {
    for(int i = 0; i < 4; i++) {
        this->figurky[i].setZnak(this->znak);
    }
}

Player::~Player() {

}

char Player::getZnak() {
    return this->znak;
}

void Player::setZnak(char znak) {
    this->znak = znak;
    for(int i = 0; i < 4; i++) {
        figurky[i].setZnak(znak);
    }
}

void Player::setPocetFiguriekVDomceku(int pocet) {
    this->pocetFiguriekVDomceku = pocet;
}

int Player::getPocetFiguriekVDomceku() {
    return pocetFiguriekVDomceku;
}

void Player::vybratFigurkuZDomceka(Figurka& figurka) {
    this->pocetFiguriekVDomceku--;
}

int Player::getPociatocnaSirka() {
    return this->pociatocnaSirka;
}

int Player::getPociatocnaVyska() {
    return this->pociatocnaVyska;
}

void Player::setPociatocnaSirka(int x) {
    this->pociatocnaSirka = x;
}

void Player::setPociatocnaVyska(int y) {
    this->pociatocnaVyska = y;
}

int Player::hodKockou(Kocka& kocka) {
    return kocka.hodKockou();
}

void Player::pridajFigurkuNaCestu() {
    this->pocetFigiekNaCeste++;
}

void Player::nastavZaciatocnePozicieFiguriek(int pozicia) {
    for(int i = 0; i < 4; i++) {
        figurky[i].setPozicia(pozicia);
    }
}

Figurka &Player::getFigurka(int cisloFigurky) {
    return this->figurky[cisloFigurky];
}

int Player::pocetFigurokVHre() {
    return this->pocetFigiekNaCeste;
}

bool Player::maVsetkyFigurkyVDomceku() {
    if(this->pocetFiguriekVDomceku == 4) {
        return true;
    }
    return false;
}

void *Player::setFigurkaNaCeste(int cisloFigurky) {
    for(int i = 0; i < 4; i++) {
        if(i == cisloFigurky) {
            figurkyNaCeste[i] = cisloFigurky;
        }
    }
}

int Player::getFigurkyNaCeste(int i) {
    if  (figurkyNaCeste[i] != -1) {
        return figurkyNaCeste[i];
    }
    return -1;
}

int Player::getZaciatocnaPozicia() {
    return this->zaciatocnaPozicia;
}

void Player::setPocetFigurokNaCeste(int pocet) {
    this->pocetFigiekNaCeste = pocet;
}

int Player::getPocetFigurokNaCeste() {
    return this->pocetFigiekNaCeste;
}

/*int Player::vyberFigurkyPriPosune() {
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

int &Player::getHodKockou() {
    return this->hod;
}

void Player::setHodKockou(int poslednyHod) {
    this->hod = poslednyHod;
}
