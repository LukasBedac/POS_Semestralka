//
// Created by Terezia on 30. 12. 2023.
//

#include "Figurka.h"

Figurka::Figurka() {
    this->riadok = getDomcek().getRiadok();
    this->stlpec = getDomcek().getStlpec();
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
    this->riadok = riadok;
}

void Figurka::setStlpec(int stlpec) {
    this->stlpec = stlpec;
}

bool Figurka::getVDomceku() {
    return this->vDomceku;
}

void Figurka::setVDomceku(bool b) {
    this->vDomceku = b;
}

int Figurka::getPrejdenaVzdialenost() {
    return this->prejdenaVzdialenost;
}

void Figurka::pridajPrejdenuVzdialenost(int kolko) {
    this->prejdenaVzdialenost += kolko;
}

void Figurka::setVKoncovomDomceku(bool b) {
    this->vKoncovomDomceku = b;
}

bool Figurka::getVKoncovomDomceku() {
    return this->vKoncovomDomceku;
}

void Figurka::setDomcek(Policko &domcek) {
    this->domcek = domcek;
}

