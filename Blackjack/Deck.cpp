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
        void add_cards();
        int get_card();
        Deck() {

        }
};

// Deck Class Constructor
Deck::Deck(){
    add_cards();
}

// Adding the cards to the deck
void Deck::add_cards(){

}

// Drawing cards from the deck
int Deck::get_card(){
    // Change to the length of the array instead of 63
    int index = rand() % 63;
    Card drawncard;

    return drawncard.value;
}