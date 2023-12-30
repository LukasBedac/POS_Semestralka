

#include <cstdlib>
#include "Kocka.h"

Kocka::Kocka() {

}

int Kocka::hodKockou() {
    return rand() % 6 + 1;
}

