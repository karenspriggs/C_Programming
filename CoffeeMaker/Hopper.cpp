#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>

#include "Hopper.h"

using namespace C;
using namespace std;
int beans = 0;

void fill(int cups){
    beans = cups * 50;
    std::cout << "Loading " << beans << " beans" << std::endl;
}

void grind(){
    std::cout << "Grinding" << std::endl;

    while (beans !=0){
        beans -= 25;
    }
}