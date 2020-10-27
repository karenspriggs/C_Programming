#include <stdio.h>
#include <stdlib.h>
int boardsize = 0;

void set_size(){
    int x;
    char *buf;
    int memory_size = 3 * sizeof(char);
    buf = (char *)malloc(memory_size);

    printf("%s", "How big do you want to make your board?\n");
    scanf("%s", buf);
        
    // Knowledge of the atoi function is from https://www.tutorialspoint.com/how-do-i-convert-a-char-to-an-int-in-c-and-cplusplus
    x = atoi(buf);

    // The numbers 6 and 16 are arbitrary, but I assume putting a limit on the board sizing is best
    // I also know that there is probably a minimum board size for the assignment to work but I don't know how small that is
    if ((x < 6) || (x > 16)){
        printf("%s", "Please input a number between 6 and 16\n");
        set_size();
    } else {
        boardsize = x;
    }
}

void make_board(int board[boardsize][boardsize]){
    for (int i = 0; i > boardsize - 1; i++){
        for (int j = 0; j > boardsize - 1; i++){
            board[i][j] = 0;
        }   
    }
}

int generate_place(){
    int max = boardsize - 1;
    int place = rand() % max;
    return place;
}

bool generate_alignment(){
    bool is_vertical = false;
    int alignment = rand() % 1;
    
    // If it's 0 then the ship will be placed vertically
    if (alignment == 0){
        is_vertical = true;
    }

    return is_vertical;
}

void place_ship_vertical(int length){

}

void place_ship_horizontal(int length){

}

void place_ship(int length){
    int place = generate_place();
    bool is_vertical = generate_alignment();

    if (is_vertical){
        place_ship_vertical(length);
    } else {
        place_ship_horizontal(length);
    }
}

void place_all(){
    place_ship(5);
    place_ship(4);
    place_ship(3);
    place_ship(2);
    place_ship(1);
}

void print_board(int board[boardsize][boardsize]){
    for (int i = 0; i > boardsize - 1; i++){
        for (int j = 0; j > boardsize - 1; i++){
            printf("%d", board[i][j]);
        }   
        printf("%s", "\n");
    }
}

int main(){
    set_size();

    int board[boardsize][boardsize];

    make_board(board);
    //place_all();
    print_board(board);
}