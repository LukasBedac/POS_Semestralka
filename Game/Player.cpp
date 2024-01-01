
#include "Player.h"


bool Player::winCondition(Player player) { //kontrola domceka pre jednotliveho hraca

    int count = 0;
    for (bool home : player.inHome) {
        if (home) {
            count++;
        }
    }
    if (count == 4) {
        return true;
    }
    return false;
}

void Player::posunFigurku(int pocetPolicok, Figurka &figurka) {
    int novaPozicia = figurka.getPozicia() + pocetPolicok;
    figurka.setPozicia(novaPozicia);
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
    delete[] figurky;
}

char Player::getZnak() {
    return this->znak;
}

void Player::setZnak(char znak) {
    this->znak = znak;
}

void Player::setPocetFiguriekVDomceku(int pocet) {
    this->pocetFiguriekVDomceku = pocet;
}

int Player::getPocetFiguriekVDomceku() {
    return this->pocetFiguriekVDomceku;
}

void Player::vybratFigurkuZDomceka(Figurka figurka) {
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

int Player::hodKockou(Kocka kocka) {
    kocka.hodKockou();
}

void Player::pridajFigurkuNaCestu() {
    pocetFigiekNaCeste++;
}

void Player::nastavZaciatocnePozicieFiguriek(int pozicia) {
    for(int i = 0; i < 4; i++) {
        figurky[i].setPozicia(pozicia);
    }
}

Figurka &Player::getFigurka(int cisloFigurky) {
    for(int i = 0; i < 4; i++) {
        if(i == cisloFigurky) {
            return figurky[i];
        }
    }
}

int Player::pocetFigurokVHre() {
    return this->pocetFigiekNaCeste;
}


