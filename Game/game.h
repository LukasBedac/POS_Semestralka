//
// Created by Lukas on 30. 12. 2023.
//

#ifndef POS_SEMESTRALKA_GAME_H
#define POS_SEMESTRALKA_GAME_H

#include "HraciaPlocha.h"
#include "Kocka.h"


class game{

private:
    HraciaPlocha hraciaPlocha;
    Kocka kocka;

public:
    game();
    void vytvorHraciuPlochu();
    void ukonciHru();

};


#endif //POS_SEMESTRALKA_GAME_H
