#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Player.h"
#include "Card.h"
#include "Deck.h"

using namespace B;

int round = 0;
Player dealer;
Player player;
Deck* deck = new Deck();

void deal(){
    int player_first;
    int player_second;
    int dealer_first;
    int dealer_second;

    player.update_total(player_first);
    player.update_total(player_second);
    dealer.update_total(dealer_first);
    dealer.update_total(dealer_second);
}

void play() {
    // This is what is run 100 times
    // First you deal the first 2 cards to the players, player goes first then dealer
    // They choose to either stand or hit depending on what they have
    // Whoever wins gets a point
    deal();
    int player_choice = player.make_choice();
    int dealer_choice = player.make_choice();

    round++;
}

void game(){
    while (round < 100){
        play();
    }
}

// Print how many times each person won
void print_scores(){
    //cout << "The player won " << player.score << " times" << endl;
}

int main() {
    srand(time(0));

    game();
    print_scores();
}