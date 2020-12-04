#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>

#include "Hopper.h"
#include "Reservoir.h"

using namespace C;
using namespace std;

Hopper* hopper = new Hopper();
Reservoir* reservoir = new Reservoir();

int take_input(){
    int cups = 0;
    std::cout << "Please enter the amount of cups of coffee you want to make" << std::endl;
    // Make sure that you have a try/catch for exceptions here
    std::cin >> cups;

    if (cups > 4){
        take_input();
    } else {
        return cups;
    }
}

void make_coffee(int cups){
    std::cout << "Making coffee: " << cups << " cups" << std::endl;
}

void finish(int cups){
    std::cout << "done" << std::endl;
}

void make(){
    int cups = take_input();

    hopper->fill(cups);
    hopper->grind();
    reservoir->fill(cups);
    reservoir->boil();
    make_coffee(cups);
    finish(cups);
}

int main(){
    make();
}