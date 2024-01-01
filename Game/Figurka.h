//
// Created by Terezia on 30. 12. 2023.
//

#ifndef UNTILTED_FIGURKA_H
#define UNTILTED_FIGURKA_H


class Figurka {
private:
    char znak;
    int pozicia;

public:
    Figurka();
    ~Figurka();
    void setZnak(char znak);
    char getZnak();
    int getPozicia();
    void setPozicia(int pozicia);
    void posun();
};


#endif //UNTILTED_FIGURKA_H
