#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>

#include "Hopper.h"
#include "Reservoir.h"

using namespace C;
using namespace std;

int cups = 0;
Hopper* hopper = new Hopper();
Reservoir* reservoir = new Reservoir();

void take_input() {
    //int cups;
    std::cout << "Please enter the amount of cups of coffee you want to make, between 1 and 4" << std::endl;
    // Make sure that you have a try/catch for exceptions here
    std::cin >> cups;

    if ((cups > 4) || (cups == 0)){
        std::cout << "Please enter an amount between 1 and 4" << std::endl;
        take_input();
    }
}

void make_coffee(int cups) {
    std::cout << "Making coffee: " << cups << " cups" << std::endl;
}

void finish(int cups) {
    std::cout << "done" << std::endl;
}

void make() {
    take_input();

    hopper->fill(cups);
    hopper->grind();
    reservoir->pour(cups);
    reservoir->boil();
    make_coffee(cups);
    finish(cups);
}

int main() {
    make();
}