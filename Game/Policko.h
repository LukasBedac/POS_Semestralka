
#ifndef POS_Semestralka_POLICKO_H
#define POS_Semestralka_POLICKO_H


class Policko {
private:
    char znak = ' ';
public:
    Policko();
    char getZnak();
    void setZnak(char znak);
    ~Policko();
};


#endif //POS_Semestralka_POLICKO_H
