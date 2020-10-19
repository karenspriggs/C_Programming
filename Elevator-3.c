#include <stdio.h>
#include <stdlib.h>

int floornumber;
int chosenfloor;

// Node struct
struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

void print_list(){
    // Function to print the list, will be used in ride_elevator
    struct node *ptr = head;
    printf("\n");

    while (ptr != NULL){
        printf("%d", ptr->data);
        ptr = ptr->next;
    }
}

void insert_value(int input){
    // Function to add all of the values to the list to be printed
    struct node *new = (struct node*) malloc(sizeof(struct node));

    new->data = input;
    new->next = head;

    head = new;
}

void clear_list(){
    // Function to clear the list for when the user rides the elevator again
}

void import_floors(){
    int x;
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
}

void choose_floor(){
    int x = 0;
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
}

void ride_elevator(){
    int currentfloor = 0;
    int count = chosenfloor;

    while (count > 0){
        insert_value(currentfloor);
        currentfloor++;
        count--;
    }
        
    print_list();
    clear_list();

    chosenfloor = 0;
}

void exit_elevator(){
    printf("\nWould you like to exit? Enter 0 for yes and anything else for no\n");
        
    int x;
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