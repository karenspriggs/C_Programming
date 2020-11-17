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
int who_won = 0;

Player dealer;
Player player;
Deck deck;

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

void player_moves(){
    int who_won;
    int player_choice = player.make_choice();
    if (player_choice == 3){
        who_won = 1;
    }
}

void dealer_moves(){
    int dealer_choice = player.make_choice_dealer();

    if (dealer_choice == 3){
        who_won = 1;
    } else {
        if (dealer_choice == 2){

        }
    }
}

void play() {
    // This is what is run 100 times
    // First you deal the first 2 cards to the players, player goes first then dealer
    // They choose to either stand or hit depending on what they have
    // Whoever wins gets a point
    deal();

    player_moves();
    dealer_moves();
    
    if (who_won == 1){
        dealer.score++;
    } else {
        player.score++;
    }

    round++;
    deck.add_cards();
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