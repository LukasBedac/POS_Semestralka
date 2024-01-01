//
// Created by Terezia on 30. 12. 2023.
//

#include "Figurka.h"

Figurka::Figurka() {

}

Figurka::~Figurka() {

}

void Figurka::setZnak(char znak) {

}

char Figurka::getZnak() {
    return this->znak;
}

int Figurka::getPozicia() {
    return this->pozicia;
}

void Figurka::setPozicia(int pozicia) {

}

void Figurka::posun() {
    /*if (pozicia + count <= 40) {
        pozicia += count; //posun na ploche, normalnych policok je 40, ptm 4 domceky
    }
    //posun v hre podla logiky ako urobime + zmena typu returnu neskor

    if (pozicia > 40 && (pozicia + count) < 45) { //kontrola ak je vyse 40 aby si skontroloval ci moze ist do domceka
        int tmpPosHome = pozicia + count - 40;
        if  (!player.inHome[tmpPosHome]) {
            player.inHome[tmpPosHome] = true;
        }
    }

    player.playerTurn = false;
    player.win = player.winCondition(player); //po tom co sa skontroluje sa v hre moze urcit vitaz
    //hned po dohrani tahu ifom a vie sa skoncit hra

    */

}
