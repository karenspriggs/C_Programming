#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

//#include "Player.h"
#include "Deck.h"
#include "Card.h"

using namespace B;

class Player{
    // List of cards
    int current_total = 0;
    public:
        int score = 0;
        Player() {

        }
        void update_total(int value);
        int make_choice();
};

// Update the player's total score
void Player::update_total(int value){
    current_total += value;
}

// AI Decides if it should hit or stand
// 1 is hit, 2 is stand
int Player::make_choice() {
    int decision;

    // Hits if the total is less than 17
    if (current_total < 17){
        decision = 1;
    } else {
        decision = 2;
    }

    return decision;
}