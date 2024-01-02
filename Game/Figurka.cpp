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
    this->pozicia = pozicia;
}


void Figurka::setDomcek(Policko domcek) {
    this->domcek = domcek;
}

Policko &Figurka::getDomcek() {
    return this->domcek;;
}

int Figurka::getStlpec() {
    return this->stlpec;
}

int Figurka::getRiadok() {
    return riadok;
}

void Figurka::setRiadok(int riadok) {

}

void Figurka::setStlpec(int stlpec) {

}

bool Figurka::getVDomceku() {
    return this->vDomceku;
}

void Figurka::setVDomceku(bool b) {
    this->vDomceku = b;
}

