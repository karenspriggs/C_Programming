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

void take_input(){
    std::cout << "Please enter the amount of cups of coffee you want to make" << std::endl;

    
}

void make_coffee(){
    std::cout << "Making coffee: " << cups << " cups" << std::endl;
}

void finish(){
    std::cout << "done" << std::endl;
}

void make(){
    hopper->fill(cups);
    hopper->grind();
    reservoir->fill(cups);
    reservoir->boil();
    make_coffee();
}

int main(){
    make();
}