#include <stdio.h>
#include <stdlib.h>

int floornumber;
int chosenfloor;

void import_floors(){
    int x;
    //char buf[3];
    char *buf;
    int memory_size = 3 * sizeof(char);
    buf = (char *)malloc(memory_size);

    printf("%s", "Please input your desired amount of floors\n");
    scanf("%s", buf);
        
    // Knowledge of the atoi function is from https://www.tutorialspoint.com/how-do-i-convert-a-char-to-an-int-in-c-and-cplusplus
    x = atoi(buf);
        
    if (x < 1){
        printf("%s", "Please enter a number greater than zero\n");
        import_floors();
    } else {         
        floornumber = x;   
        printf("\nThis building now has %i floors\n", x);
    }

    //free(buf);
}

void choose_floor(){
    int x = 0;
    //char tuf[3];
    char *tuf;
    int memory_size = 3 * sizeof(char);
    tuf = (char *)malloc(memory_size);
        
    printf("%s", "Which floor would you like to go to?\n");
        
    scanf("%s", tuf);
        
    x = atoi(tuf);
        
    printf("\nYou have chosen floor %d\n", x);
        
    if (x > floornumber || x < 1){
        printf("%s", "\nThat number is too big or is not greather than zero, please try again.\n");
        choose_floor();
    } else {
        chosenfloor = x;
    }

    //free(tuf);
}

void ride_elevator(){
    // Change this to heap allocated
    //int floors[floornumber];
    int memory_size = floornumber * sizeof(int);
    int *floors;
    floors = (int *) malloc(memory_size);
        
    for (int i = 0; i < floornumber; i++){
        floors[i] = i+1;
    }
        
    printf("%s", "\nYou pass by the following floors:\n");
        
    for (int i = 0; i < chosenfloor; i++){
        printf("%i\n", floors[i]);
    }

    //free(floors);
    chosenfloor = 0;
}

void exit_elevator(){
    printf("\nWould you like to exit? Enter 0 for yes and anything else for no\n");
        
    int x;
    //char buf[3];
    char *buf;
    int memory_size = 3 * sizeof(char);
    buf = (char *)malloc(memory_size);

    scanf("%s", buf);
        
    x = atoi(buf);
        
    if (x == 0){
        printf("%s", "\nTime to get out of the elevator.");
        exit(0);
    } else {
        printf("%s", "\n");
    }
}

void ride(){
    choose_floor();
    ride_elevator();
    exit_elevator();
    ride();
}

int main()
{
    import_floors();
    ride();
}