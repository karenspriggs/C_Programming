#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

//#include "Deck.h"
#include "Card.h"

using namespace B;

class Deck{
    int* cards;
    public:
        void add_cards();
        void allocate();
        int get_card();
        Deck() {

        }
};

// Deck Class Constructor
Deck::Deck(){
    add_cards();
}

void Deck::allocate(){
    int memory_size = 64 * sizeof(int);
    cards = (int *) malloc(memory_size);
}

// Adding the cards to the deck
void Deck::add_cards(){
    for (int i = 1; i < 5; i++){
        for (int j = 0; j < 13; j++){
            int index = (i*j) - 1;

            //cards[index] = j;
        }
    }
}

// Drawing cards from the deck
int Deck::get_card(){
    // Change to the length of the array instead of 63
    int index = rand() % 63;
    int drawncard = cards[index];

    return drawncard;
}