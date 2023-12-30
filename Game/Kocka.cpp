//
// Created by Terezia on 30. 12. 2023.
//

#include <cstdlib>
#include "Kocka.h"

Kocka::Kocka() {

}

int Kocka::hodKockou() {
    return rand() % 6 + 1;
}

