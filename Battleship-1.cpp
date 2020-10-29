#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
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

void make_board(int * board){
    for (int i = 0; i < boardsize; i++){
        for (int j = 0; j < boardsize; j++){
            // Referenced from Karl Statz's fill function at 
            // https://gist.github.com/kstatz12/1675e6823134f0c4437734148a9dcce3
            *(board + i * boardsize + j) = 0;
        }
    }
}

int generate_place(){
    int max = boardsize - 1;
    int place = rand() % max;
    return place;
}

void make_ship(int* board){
    int place = generate_place();

    board[0] = 1;
    board[1] = 1;
    board[2] = 1;
    board[3] = 1;
    board[4] = 1;
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

bool place_check(int pos, int* line){
    bool is_free = true;

    for (int i = 1; i < 4; i++){
        if ((line[pos+i] == 1)){
            is_free = false;
        }
    }

    return is_free;
}

void place_ship_horizontal(int length, int* row){
    int place_x = generate_place();
    int place_y = generate_place();
    bool valid;

    if (((boardsize - place_x) < length) || ((boardsize - place_y) < length)){
        place_x = generate_place();
        place_y = generate_place();
    }

    for (int i = 0; i < length; i++){
        valid = place_check(place_x+i, row);
    }

    if (valid){

    } else {
        place_ship_horizontal(length, row);
    }
}

void place_ship_vertical(int length){
    int place = generate_place();

}

void place_ship(int length, int* board){
    bool is_vertical = generate_alignment();

    if (is_vertical){
        place_ship_vertical(length);
    } else {
        //place_ship_horizontal(length, board);
    }
}

void place_all(int* board){
    place_ship(5, board);
    place_ship(4, board);
    place_ship(3, board);
    place_ship(2, board);
    place_ship(1, board);
}

void print_board(int * board){
    for (int i = 0; i < boardsize; i++){
        for (int j = 0; j < boardsize; j++){
            int current = *(board + i * boardsize + j);
            printf("%d", current);
            printf("%s", "   ");
        }   
        printf("%s", "\n");
    }
}

int main(){
    set_size();
    int size = boardsize*boardsize;
    int memory_size = size * sizeof(int);
    int *board;
    board = (int *) malloc(memory_size);
    
    // Segmentation fault
    make_board(board);
    make_ship(board);
    print_board(board);
}