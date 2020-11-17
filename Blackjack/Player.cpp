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
    int role = 0;
    public:
        int score = 0;
        Player() {

        }
        void update_total(int value);
        int make_choice();
        int make_choice_dealer();
};

// Update the player's total score
void Player::update_total(int value){
    current_total += value;
}

// AI Decides if it should hit or stand
// 1 is hit, 2 is stand
int Player::make_choice() {
    int decider = rand() % 1;
    int decision;

    if (current_total == 21){
        decision = 4;
    } else {
        if (current_total > 21){
        // player busts
        decision = 3;
    } else {
            if (current_total > 17){
                if (decider == 1){
                    // player stands
                    decision = 1;
                } else {
                    // player hits
                    decision = 2;
                }
            } else {
                // player hits
                decision = 2;
            }
        }
    }

    return decision;
}

int Player::make_choice_dealer() {
    int decision;

    if (current_total == 21){
        decision = 4;
    } else {
        // Hits if the total is less than 17
        if (current_total > 21){
            // dealer busts
            decision = 3;
        } else {
            if (current_total < 17){
                // dealer hits
                decision = 2;
            } else {
                // dealer stands
                decision = 1;
            }
        }
    }

    return decision;
}