#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "Reservoir.h"

using namespace C;
int temperature = 0;

void fill(int cups){

}

void boil(){
    for (int i = 1; i < 17; i++){
        temperature += 15;
        printf("%d", temperature);
    }
}