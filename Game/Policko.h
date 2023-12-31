
#ifndef POS_Semestralka_POLICKO_H
#define POS_Semestralka_POLICKO_H


class Policko {
private:
    char znak = ' ';
    int x;
    int y;
public:
    Policko();
    char getZnak();
    void setZnak(char znak);
    int getX();
    int getY();
    void setSuradnice(int y, int x);
    ~Policko();
};


#endif //POS_Semestralka_POLICKO_H
