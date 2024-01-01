
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

/*void Player::movePlayer(int count, Player player) {
    if (player.currentPos + count <= 40) {
        player.currentPos += count; //posun na ploche, normalnych policok je 40, ptm 4 domceky
    }
    //posun v hre podla logiky ako urobime + zmena typu returnu neskor

    if (player.currentPos > 40 && (player.currentPos + count) < 45) { //kontrola ak je vyse 40 aby si skontroloval ci moze ist do domceka
        int tmpPosHome = currentPos + count - 40;
        if  (!player.inHome[tmpPosHome]) {
            player.inHome[tmpPosHome] = true;
        }
    }

    player.playerTurn = false;
    player.win = player.winCondition(player); //po tom co sa skontroluje sa v hre moze urcit vitaz
    //hned po dohrani tahu ifom a vie sa skoncit hra
}*/

void Player::posunFigurku(int pocetPolicok, Figurka figurka) {
    int novaPozicia = figurka.getPozicia() + pocetPolicok;
    figurka.setPozicia(novaPozicia);
}

void Player::setZaciatocnaPozicia(int pozicia) {
    this->zaciatocnaPozicia = pozicia;
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
}

void Player::setPocetFiguriekVDomceku(int pocet) {
    this->pocetFiguriekVDomceku = pocet;
}

int Player::getPocetFiguriekVDomceku() {
    return this->pocetFiguriekVDomceku;
}

void Player::vybratFigurkuZDomceka() {
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

Figurka Player::getFigurka(int cisloFigurky) {
    for(int i = 0; i < 4; i++) {
        if(i == cisloFigurky) {
            return figurky[i];
        }
    }
}


