

#include "Policko.h"

Policko::Policko() {

}

char Policko::getZnak() {
    return this->znak;
}

void Policko::setZnak(char znak) {
    this->znak = znak;
}
int Policko::getStlpec() {
    return this->stlpec;
}

int Policko::getRiadok() {
    return this->riadok;
}

void Policko::setSuradnice(int riadok, int stlpec) {
    this->riadok = riadok;
    this->stlpec = stlpec;
}

Policko::~Policko() {

}

int Policko::getPocetHracovNaPolicku() {
    return this->pocetHracovNaPolicku;
}

void Policko::pridajPocetHracovNaPolicku() {
    this->pocetHracovNaPolicku++;
}

void Policko::znisPocetHracovNaPolicku() {
    this->pocetHracovNaPolicku--;
}
