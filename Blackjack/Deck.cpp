#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
//#include "Deck.h"
#include "Card.h"

using namespace B;

class Deck{
    Card cards[64];
    public:
        int get_card();
        Deck() {

        }
};

int Deck::get_card(){

}