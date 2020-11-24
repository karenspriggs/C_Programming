#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Player.h"
//#include "Card.h"
#include "Deck.h"

using namespace B;

int match = 0;
int who_won = 0;

Player* dealer = new Player();
Player* player = new Player();
Deck* deck = new Deck();

void deal(){
    int player_first = deck->get_card();
    int player_second = deck->get_card();
    int dealer_first = deck->get_card();
    int dealer_second = deck->get_card();

    player->update_total(player_first);
    player->update_total(player_second);
    dealer->update_total(dealer_first);
    dealer->update_total(dealer_second);
}

void player_moves(){
    int player_choice = player->make_choice();
    int next_card = deck->get_card();

    if (player_choice == 3){
        who_won = 1;
    } else {
        if (player_choice == 2){
            player->update_total(next_card);
            player_moves();
        }
    }
}

void dealer_moves(){
    int dealer_choice = player->make_choice_dealer();
    int next_card = deck->get_card();

    if (dealer_choice == 3){
        who_won = 2;
    } else {
        if (dealer_choice == 2){
            dealer->update_total(next_card);
            dealer_moves();
        }
    }
}

void play() {
    // This is what is run 100 times
    // First you deal the first 2 cards to the players, player goes first then dealer
    // They choose to either stand or hit depending on what they have
    // Whoever wins gets a point
    deal();

    dealer_moves();
    player_moves();

    if (who_won == 2){
        dealer->score++;
    } else {
        player->score++;
    }

    match++;
    deck->add_cards();
}

void game(){
    while (match < 100){
        play();
    }
}

// Print how many times each person won
void print_scores(){
    printf("%d", player->score);
    printf("%s", "\n");
    printf("%d", dealer->score);
}

int main() {
    printf("%s", "pee");
    srand(time(0));

    game();
    print_scores();
}