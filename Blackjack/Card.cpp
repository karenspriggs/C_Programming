#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include "Card.h"

using namespace B;

class Card{
    public:
        int value;
        Card(int x) {
            value = x;
        }
};
