#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Deck.h"

using namespace B;

/**
class Deck{
    int* cards;
    public:
        void add_cards();
        void allocate();
        int get_card();
        Deck() {

        }
};
**/

// Deck Class Constructor
Deck::Deck() {
    allocate();
    add_cards();
}


void Deck::allocate() {
    int memory_size = 13 * sizeof(int);
    cards = (int*)malloc(memory_size);
}

// Adding the cards to the deck
void Deck::add_cards() {
    // There are only really 13 "values" possible when not counting the suits, so an array of 13
    // makes sense for me for this
    cards[0] = 11;
    cards[1] = 2;
    cards[2] = 3;
    cards[3] = 4;
    cards[4] = 5;
    cards[5] = 6;
    cards[6] = 7;
    cards[7] = 8;
    cards[8] = 9;
    cards[9] = 10;
    cards[10] = 10;
    cards[11] = 10;
    cards[12] = 10;
}

// Drawing cards from the deck
int Deck::get_card() {
    int index = rand() % 13;
    int drawncard = cards[index];

    return drawncard;
}