#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Card.h"
#include "Deck.h"

using namespace B;

int round = 0;
Player* dealer = new Player();
Player* player = new Player();
Deck* deck = new Deck();

void play() {
    // This is what is run 100 times
    // First you deal the first 2 cards to the players, player goes first then dealer
    // They choose to either stand or hit depending on what they have
    // Whoever wins gets a point

    round++;
}

void game(){
    while (round < 100){
        play();
    }
}

// Print how many times each person won
void print_scores(){
    
}

int main() {
    srand(time(0));

    game();
    print_scores();
}