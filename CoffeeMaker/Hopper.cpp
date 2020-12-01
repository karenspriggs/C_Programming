#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "Hopper.h"

using namespace C;

void fill(int cups){
    int beans = cups * 50;
    printf("%s", "Loading ");
    printf("%d", beans);
    printf("%s", " beans");
}

void grind(){
    printf("%s", "\nGrinding");
}