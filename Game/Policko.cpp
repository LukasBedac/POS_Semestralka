

#include "Policko.h"

Policko::Policko() {

}

char Policko::getZnak() {
    return this->znak;
}

void Policko::setZnak(char znak) {
    this->znak = znak;
}
int Policko::getX() {
    return this->x;
}

int Policko::getY() {
    return this->y;
}

void Policko::setSuradnice(int y, int x) {
    this->x = x;
    this->y = y;
}

Policko::~Policko() {

}
