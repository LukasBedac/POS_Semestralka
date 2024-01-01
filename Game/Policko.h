
#ifndef POS_Semestralka_POLICKO_H
#define POS_Semestralka_POLICKO_H


class Policko {
private:
    char znak = ' ';
    int stlpec;
    int riadok;
public:
    Policko();
    char getZnak();
    void setZnak(char znak);
    int getStlpec();
    int getRiadok();
    void setSuradnice(int riadok, int slpec);
    ~Policko();
};


#endif //POS_Semestralka_POLICKO_H
