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
    int place = rand() % boardsize;
    return place;
}

bool generate_alignment(){
    bool is_vertical = false;
    int alignment = rand() % 2;
    
    // If it's 0 then the ship will be placed vertically
    if (alignment == 0){
        is_vertical = true;
    }

    return is_vertical;
}

bool up(int x, int y, int* board){
    bool is_free;
    int location = boardsize * y + x;
    
    for (int i = 1; i < 4; i++){
        bool is_free = (board[location - i * boardsize] != 1);
    }

    return is_free;
}

bool down(int x, int y, int* board){
    bool is_free;
    int location = boardsize * y + x;
    
    for (int i = 1; i < 4; i++){
        bool is_free = (board[location + i * boardsize] != 1);
    }

    return is_free;
}

bool check_up(int x, int y, int* board){
    bool is_free;
    
    // this is terrible im so sorry
    if (y == 0){
        return true;
    } else {
        if (y == 1){
            return (board[x] != 1);
        } else {
            if (y == 2){
                return ((board[x] != 1) && (board[x*boardsize] != 1));
            } else {
                is_free = up(x, y, board);
                return is_free;
            }
        }
    }
}

bool check_down(int x, int y, int* board){
    bool is_free;
    int second_last = (boardsize - 1) * y + x;
    int third_last = (boardsize - 2) * y + x;

    // this is terrible im so sorry
    if (y == 9){
        return true;
    } else {
        if (y == 8){
            return (board[second_last] != 1);
        } else {
            if (y == 7){
                return ((board[second_last] != 1) && (board[third_last] != 1));
            } else {
                is_free = up(x, y, board);
                return is_free;
            }
        }
    }
}

bool place_check(int x, int y, int length, int align, int* board){
    bool is_free = true;
    int pos = (((boardsize - 1)* y) + x);

    // vertical placement
    if (align == 0){
        for (int i = 0; i < length; i++){

        }
    }

    return is_free;
}

void make_ship_horizontal(int length, int x, int y, int* board){
    for (int i = 0; i < length; i++){
            int row = boardsize*y;
            int start = row + x;
            int current = start+i;
            board[current] = 1;
    }
}

void place_ship_horizontal(int length, int* board){
    int place_x = generate_place();
    int place_y = generate_place();
    bool valid;

    if (((boardsize - place_x) < length)){
        /**
        printf("%d", (boardsize - place_x));
        printf("%s", "\ntoo high\n");
        printf("%d", place_x);
        printf("%s", "\n");
        **/
        valid = false;
        place_ship_horizontal(length, board);
    } else {
        make_ship_horizontal(length, place_x, place_y, board);
    }

    /**
    for (int i = 0; i < length; i++){
        valid = place_check(place_x+i, board);
    }

    if (valid){
        make_ship_horizontal(length, place_x, place_y, board);
    } else {
        place_ship_horizontal(length, board);
    }
    **/
}

void make_ship_vertical(int length, int x, int y, int* board){
    for (int i = 0; i < length; i++){
            int column = x;
            int start = y+i;
            int place = start*boardsize;
            int current = place+x;
            board[current] = 1;
    }
}

void place_ship_vertical(int length, int* board){
    int place_x = generate_place();
    int place_y = generate_place();
    bool valid;

    if (((boardsize - place_y) < length)) {
        /**
        printf("%d", (boardsize - place_y));
        printf("%s", "\ntoo high\n");
        printf("%d", place_y);
        printf("%s", "\n");
        **/
        valid = false;
        place_ship_vertical(length, board);
    } else {
        make_ship_vertical(length, place_x, place_y, board);
    }

    /**
    for (int i = 0; i < length; i++){
        valid = place_check(place_y+i, board);
    }

    if (valid){
        make_ship_vertical(length, place_x, place_y, board);
    } else {
        place_ship_vertical(length, board);
    }
    **/
}

void place_one(int * board){
    int place_x = generate_place();
    int place_y = generate_place();
    bool valid;

    board[place_x*place_y] = 1;
}

void place_ship(int length, int* board){
    bool is_vertical = generate_alignment();

    if (length == 1){
        place_one(board);
    } else{
        if (is_vertical){
            place_ship_vertical(length, board);
        } else {
            place_ship_horizontal(length, board);
        }
    }
}

void place_all(int* board){
    place_ship(5, board);
    printf("%s", "made ship 5\n");
    place_ship(4, board);
    printf("%s", "made ship 4\n");
    place_ship(3, board);
    printf("%s", "made ship 3\n");
    place_ship(2, board);
    printf("%s", "made ship 2\n");
    place_ship(1, board);
    printf("%s", "made ship 1\n");
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
    srand(time(0));
    
    int size = boardsize*boardsize;
    int memory_size = size * sizeof(int);
    int *board;
    board = (int *) malloc(memory_size);

    make_board(board);

    //place_ship(5, board);
    place_all(board);
    print_board(board);
}