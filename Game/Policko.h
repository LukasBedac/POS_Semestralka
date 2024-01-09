
#ifndef POS_Semestralka_POLICKO_H
#define POS_Semestralka_POLICKO_H


class Policko {
private:
    char znak = ' ';
    int stlpec;
    int riadok;
    int pocetHracovNaPolicku = 0;
    bool figurkaMozeIstDoDomceka;
public:
    Policko();
    char getZnak();
    void setZnak(char znak);
    int getStlpec();
    int getRiadok();
    void setSuradnice(int riadok, int slpec);
    int getPocetHracovNaPolicku();
    void pridajPocetHracovNaPolicku();
    void znisPocetHracovNaPolicku();
    ~Policko();

    void setFigurkaMozeIstDoDomceka(bool b);

    void setPocetHracovNaPolicku(int i);

    bool getFigutkaMozeIstDoDomceka();
};


#endif //POS_Semestralka_POLICKO_H
