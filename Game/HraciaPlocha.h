//
// Created by Terezia on 30. 12. 2023.
//

#ifndef POS_SEMESTRALKA_HRACIAPLOCHA_H
#define POS_SEMESTRALKA_HRACIAPLOCHA_H

class HraciaPlocha {
private:
    const static int plochaSirka = 13;
    const static int plochaVyska = 13;
    char plocha[plochaSirka][plochaVyska];

public:
    HraciaPlocha();
    void vytvorPlochu();
    void vypisPlochu();
};


#endif //POS_SEMESTRALKA_HRACIAPLOCHA_H
