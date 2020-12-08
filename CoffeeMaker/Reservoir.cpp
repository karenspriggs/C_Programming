#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>

#include "Reservoir.h"

using namespace C;
using namespace std;
int temperature = 0;

void Reservoir::pour(int cups) {
    std::cout << "Filling Water: " << cups << " cups" << std::endl;
}

void Reservoir::boil() {
    std::cout << "Boiling water" << std::endl;
    std::cout << 0 << std::endl;

    for (int i = 1; i < 13; i++) {
        temperature += 15;
        std::cout << temperature << std::endl;
    }
}