#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Deck.h"

using namespace std;
using namespace B;

class Player{
    // List of cards
    int current_total = 0;
    int score;
    public:
        Player() {

        }
        void make_choice();
};

// AI Decides if it should hit or stand
void Player::make_choice() {

}