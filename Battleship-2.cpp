#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
int boardsize = 0;
int hits = 0;

void set_size(){
    int x;
    char *buf;
    int memory_size = 3 * sizeof(char);
    buf = (char *)malloc(memory_size);

    printf("%s", "How big do you want to make your board?\n");
    scanf("%s", buf);
        
    // Knowledge of the atoi function is from https://www.tutorialspoint.com/how-do-i-convert-a-char-to-an-int-in-c-and-cplusplus
    x = atoi(buf);

    // If the board is smaller than 12 it seems like its more likely for the placements of the ship to become problematic
    // I set the limit at 16 because if it was too big it would be a bit ridiculous 
    if ((x < 12) || (x > 16)){
        printf("%s", "Please input a number between 12 and 16\n");
        set_size();
    } else {
        boardsize = x;
    }
}

// Makes the board full of 0's
void make_board(int * board){
    for (int i = 0; i < boardsize; i++){
        for (int j = 0; j < boardsize; j++){
            // Referenced from Karl Statz's fill function at 
            // https://gist.github.com/kstatz12/1675e6823134f0c4437734148a9dcce3
            *(board + i * boardsize + j) = 0;
        }
    }
}

// Generates random numbers
int generate_place(){
    int place = rand() % boardsize;
    return place;
}

// Generates if the ship will be placed vertically or horizontally
bool generate_alignment(){
    bool is_vertical = false;
    int alignment = rand() % 2;
    
    // If it's 0 then the ship will be placed vertically
    if (alignment == 0){
        is_vertical = true;
    }

    return is_vertical;
}

// Checking 3 spaces up for a given point for there to be a 1
bool up(int x, int y, int * board){
    bool is_free = true;
    int location = boardsize * y + x;

    for (int i = 1; i < 4; i++){
        is_free = (board[location - (i * boardsize)] != 1);
        if (!is_free){
            return false;
        }
    }

    return is_free;
}

// Checking 3 spaces down for a given point for there to be a 1
bool down(int x, int y, int * board){
    bool is_free = true;
    int location = boardsize * y + x;
    
    for (int i = 1; i < 4; i++){    
        is_free = (board[location + (i * boardsize)] != 1);
        if (!is_free){
            return false;
        }
    }

    return is_free;
}

// Checking 3 spaces left for a given point for there to be a 1
bool left(int x, int y, int * board){
    bool is_free = true;
    int pos = boardsize * y + x; 
    
    for (int i = 1; i < 4; i++){
        is_free = (board[pos-i] != 1);
        if (!is_free){
            return false;
        }
    }

    return is_free;
}

// Checking 3 spaces right for a given point for there to be a 1
bool right(int x, int y, int * board){
    bool is_free = true;
    int pos = boardsize * y + x; 
    
    for (int i = 1; i < 4; i++){
        is_free = (board[pos+i] != 1);
        if (!is_free){
            return false;
        }
    }

    return is_free;
}

// Checks to what will determine that place's validity based on whats above it
bool check_up(int x, int y, int * board){
    bool is_free = true;
    
    // if y is 0, it is starting all the way at the top 
    if (y == 0){
        return true;
    } else {
        // If y is 1, there is only one item above it
        if (y == 1){
            // This is the same as checking y = 0 for this x coordinate
            return (board[x] != 1);
        } else {
            // If y is 2, there are only two items above it
            if (y == 2){
                return ((board[x] != 1) && (board[x*boardsize] != 1));
            } else {
                // Here you run the thing that only goes three times
                is_free = up(x, y, board);
                return is_free;
            }
        }
    }
}

// Checks to see what will determine the validity of this spot based off of whats below it
bool check_down(int x, int y, int * board){
    bool is_free = true;
    // These represent the second to last
    int second_last = (boardsize * (y + 1) + x);
    // And last rows of the board
    int last = (boardsize * (y + 2) + x);

    // If y = (boardsize-1), it is already at the bottom of the board
    if (y == (boardsize-1)){
        return true;
    } else {
        // If y = (boardsize-2), there is only one item to check below it
        if (y == (boardsize-2)){
            return (board[second_last] != 1);
        } else {
            // If y = (boardsize-3), there are only two items to check below it
            if (y == (boardsize-2)){
                return ((board[second_last] != 1) && (board[last] != 1));
            } else {
                // Here you run the thing that only goes three times
                is_free = down(x, y, board);
                return is_free;
            }
        }
    }
}

//Checks to see what will determine the validity of this spot based off of whats to the left of it
bool check_left(int x, int y, int * board){
    bool is_free = true;
    // The current randomly generated position to start on
    int pos = boardsize * y + x;
    
    // If x = 0 then it is already all the way to the left
    if (x == 0){
        return true;
    } else {
        // If x = 1 then there is only one item to check to the left
        if (x == 1){
            return (board[pos-1] != 1);
        } else {
            // If x = 2 then there are only two items to check to the left
            if (x == 2){
                return ((board[pos-1] != 1) && (board[pos-2] != 1));
            } else {
                // Here you run the thing that only goes three times
                is_free = left(x, y, board);
                return is_free;
            }
        }
    }
}

//Checks to see what will determine the validity of this spot based off of whats to the right of it
bool check_right(int x, int y, int * board){
    bool is_free = true;
    // The current randomly generated position to start on
    int pos = boardsize * y + x;

    // If x = (boardsize-1) then it is already all the way to the right
    if (x == (boardsize-1)){
        return true;
    } else {
        // If x = (boardsize-2) then there is only one item to check on the right
        if (x == (boardsize-2)){
            return (board[pos+1] != 1);
        } else {
            // If x = (boardsize-3) then there are only two items to check on the right
            if (x == (boardsize-3)){
                return ((board[pos+1] != 1) && (board[pos+2] != 1));
            } else {
                // Here you run the thing that only goes three times
                is_free = right(x, y, board);
                return is_free;
            }
        }
    }
}

// Used for testing
void print_result(bool input){
    if (input){
        printf("%s", "This test was passed\n");
    } else {
        printf("%s", "This test was not\n");
    }
}

bool place_check(int x, int y, int length, int align, int * board){
    bool is_free = true;
    bool space_free = true;
    bool down_free = true;
    bool up_free = true;
    bool left_free = true;
    bool right_free = true;
    int pos = boardsize * y + x;
    
    // Vertical placement check
    if (align == 0){
        // Here we are running all the checks for each "space" that will make up the ship
        // Since it is vertical, we add i to the y value since we are going "down a space"
        for (int i = 0; i < length; i++){
            space_free = (board[((boardsize * y+i) + x - 1)] != 1);
            down_free = check_down(x, y+i, board);
            up_free = check_up(x, y+i, board);
            left_free = check_left(x, y+i, board);
            right_free = check_right(x, y+i, board);
            is_free = (space_free && down_free && up_free && left_free && right_free);

            if (!is_free){
                return false;
            }
        }
        return is_free;
    // Horizontal placement check
    } else {
        // Here we are running all the checks for each "space" that will make up the ship
        // Since it is horizontal, we add i to the x value since we are going "right a space"
        for (int i = 0; i < length; i++){
            space_free = (board[((boardsize * y) + x + i - 1)] != 1);
            down_free = check_down(x+i, y, board);
            up_free = check_up(x+i, y, board);
            left_free = check_left(x+i, y, board);
            right_free = check_right(x+i, y, board);
            is_free = (space_free && down_free && up_free && left_free && right_free);

            if (!is_free){
                return false;
            }
        }
        return is_free;   
    }

    // It seems to need a return value here so I put this here as well
    return is_free;
}

// The function to actually make the horizontal spaces into 1's after everything has been tested
void make_ship_horizontal(int length, int x, int y, int * board){
    for (int i = 0; i < length; i++){
        int row = boardsize*y;
        int start = row + x;
        int current = start+i;
        board[current] = 1;
    }
}

// The function to run all the checks (and make sure that the ship isn't going to be placed out of bounds)
// If everything looks okay, it makes the ship
void place_ship_horizontal(int length, int * board){
    int place_x = generate_place();
    int place_y = generate_place();
    int place_z = generate_place();

    bool valid = place_check(place_z, place_y, length, 1, board);

    // Checking to make sure what was just generated isn't something out of bounds
    if ((((boardsize - place_z) < length) || (!valid))){
        place_ship_horizontal(length, board);
    } else {
        // If they do, make the ship
        make_ship_horizontal(length, place_z, place_y, board);
    }
}

// The function to actually make the vertical spaces into 1's after everything has been tested
void make_ship_vertical(int length, int x, int y, int * board){
    for (int i = 0; i < length; i++){
        int column = x;
        int start = y+i;
        int place = start*boardsize;
        int current = place+x;
        board[current] = 1;
    }
}

// The function to run all the checks (and make sure that the ship isn't going to be placed out of bounds)
// If everything looks okay, it makes the ship
void place_ship_vertical(int length, int * board){
    int place_x = generate_place();
    int place_y = generate_place();
    int place_z = generate_place();

    bool valid = place_check(place_z, place_y, length, 0, board);

    // Checking to make sure what was just generated isn't something out of bounds
    if ((((boardsize - place_y) < length) || (!valid))){
        place_ship_vertical(length, board);
    } else {
        // If they do, make the ship
        make_ship_vertical(length, place_z, place_y, board);
    }
}

// Function to place a ship that also generates the alignment at which it will be placed
// Then runs the appropriate function
void place_ship(int length, int * board){
    bool is_vertical = generate_alignment();

    if (is_vertical){
        place_ship_vertical(length, board);
        } else {
        place_ship_horizontal(length, board);
    }
}

// The function that places all of the battleships
void place_all(int * board){
    place_ship(5, board);
    place_ship(4, board);
    place_ship(3, board);
    place_ship(3, board);
    place_ship(2, board);
}

// Method to print the board
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

// Battleship 2 starts here

// Seeing where to check next depending on where a hit (or near hit) was found

// Top Left corner
void tl_corner_check(int * board, int * hit_board){
    int down_result = (check(board, 0, 1));
    int right_result = (check(board, 1, 0));
    bool down_hit = (down_result == 1);
    bool right_hit = (right_result == 1);

    // Changes the adjacent spaces on the hit board
    hit_board[1] = right_result;
    hit_board[boardsize] = down_result;

    // If the hit is found, continue in the direction of the hit
    // Since this is only run if a hit is found in the corner
    // There must be a hit in one of the adjacent spaces
    if(down_hit){
        find_next(board, 0, 1, hit_board);
    } else {
        find_next(board, 1, 0, hit_board);
    }
}

// Top Right corner
void tr_corner_check(int * board, int * hit_board){
    int down_result = (check(board, (boardsize - 1), 1));
    int left_result = (check(board, (boardsize - 2), 0));
    bool down_hit = (down_result == 1);
    bool right_hit = (left_result == 1);

    hit_board[(boardsize - 2)] = left_result;
    hit_board[(2 *(boardsize - 1))] = down_result;

    if(down_hit){
        find_next(board, (boardsize - 1), 1, hit_board);
    } else {
        find_next(board, (boardsize - 2), 0, hit_board);
    }
}

// Bottom Left Corner
void bl_corner_check(int * board, int * hit_board){
    int up_result = (check(board, 0, (boardsize - 2)));
    int right_result = (check(board, 1, 0));
    bool up_hit = (up_result == 1);
    bool right_hit = (right_result == 1);

    hit_board[((boardsize - 1) * boardsize) + 1] = right_result;
    hit_board[(boardsize - 2) * boardsize] = up_result;

    if(up_hit){
        find_next(board, 0, (boardsize - 2), hit_board);
    } else {
        find_next(board, 1, (boardsize - 1), hit_board);
    }
}

// Bottom Right Corner
void br_corner_check(int * board, int * hit_board){
    int up_result = (check(board, (boardsize - 1), (boardsize - 2)));
    int left_result = (check(board, (boardsize - 2), (boardsize - 1)));
    bool up_hit = (up_result == 1);
    bool left_hit = (left_result == 1);

    hit_board[(boardsize * boardsize) - 2] = left_result;
    hit_board[((boardsize - 1) * boardsize) - 1] = up_result;

    if(up_hit){
        find_next(board, (boardsize - 1), (boardsize - 2), hit_board);
    } else {
        find_next(board, (boardsize - 2), (boardsize - 1), hit_board);
    }
}

// Topmost row
void topmost_check(int * board, int pos, int * hit_board){
    // This would check the spaces to the left, right, and below
    // And then continue in the direction that the hit was found
    // If a hit was found in two directions, it would start going left first
    // Until it missed, then it would go right
}

// Bottommost row
void bottommost_check(int * board, int pos, int * hit_board){
    // This would check the spaces to the left, right, and above
    // And then continue in the direction that the hit was found
    // If a hit was found in two directions, it would start going left first
    // Until it missed, then it would go right
}

// Far left column
void leftmost_check(int * board, int pos, int * hit_board){
    // This would check the spaces to the right, above, and below
    // And then continue in the direction that the hit was found
    // If a hit was found in two directions, it would start going up first
    // Until it missed, then it would go down
}

// Far right column
void rightmost_check(int * board, int pos, int * hit_board){
    // This would check the spaces to the left, above, and below
    // And then continue in the direction that the hit was found
    // If a hit was found in two directions, it would start going up first
    // Until it missed, then it would go down
}

// None of the above (default)
void normal_check(int * board, int pos, int * hit_board){
    // This would check the spaces in all adjacent directions
    // And then continue in the direction that the hit was found
    // If the hit was found in two horizontal directions, it would go left first
    // If the hit was found in two verticle directions, it would go up first
}

// If it's a near miss or a hit we are gonna try to find the next one
void find_next(int * board, int x, int y, int * hit_board){
    int pos = (y * boardsize) + x;
    int place = error_codes(pos);

    switch(place){
        case 8 :
        // If it is on the bottom row of the board
        bottommost_check(board, pos, hit_board);
        break;

        case 7 :
        // If it is on the top row
        topmost_check(board, pos, hit_board);
        break;

        case 6 :
        // If it is on the far left column
        leftmost_check(board, pos, hit_board);
        break;

        case 5 :
        // If it is on the far right column
        rightmost_check(board, pos, hit_board);

        break;

        case 4 :
        // If it is in the bottom left corner
        bl_corner_check(board, hit_board);
        break;

        case 3 :
        // If it is in the bottom right corner
        br_corner_check(board, hit_board);
        break;

        case 2:
        // If it is in the top right corner
        tr_corner_check(board, hit_board);
        break;

        case 1:
        // If it is in the top left corner
        tl_corner_check(board, hit_board);
        break;

        default :
        normal_check(board, pos, hit_board);
        break;
    }
}

void make_move(int * board, int * hit_board){
    int place_x = generate_place();
    int place_y = generate_place();
    int pos = (place_y*boardsize) + place_x;

    // If the spot just generated is either a hit or miss, generate another
    if (hit_board[pos] == 1 || hit_board[pos] == 3){
        make_move(board, hit_board);
    } else {
        int result = check(board, place_x, place_y);

        printf("%d", place_x);
        printf("%s", "\n");
        printf("%d", place_y);
        printf("%s", "\n");

        update_board(hit_board, place_x, place_y, result);

        // If the result was a hit then try to find another
        if (result != 3){
            find_next(board, place_x, place_y, hit_board);
        }
    }
}

// Check function
int check(int * board, int x, int y){
    int pos = (y * boardsize) + x;
    bool adjacent = (board[pos+1] == 1) || (board[pos-1] == 1) || (board[pos - (boardsize)] == 1) || (board[pos + (boardsize)] == 1);

    if (board[pos] == 1){
        // 1 represents a hit
        return 1;
    } else {
        // Make sure to make this work with edges later
        if (adjacent){
            // 2 represents a near miss
            return 2;
        } else {
            // 3 represents a miss
            return 3;
        }
    }
}

// Checks to see if the position is right up against an edge or corner
// This affects how the next position to be checked will be determined
int error_codes(int pos){
   // Will say if anything violates this

    // Returns 1 if it is in the top left corner
    if (pos == 0){
        return 1;
    } 

    // Returns 2 if it is in the top right corner
    if ((pos % (boardsize-1) == 0) && (pos - boardsize) < 0){
        return 2;
    }

    // Returns 3 if it is in the bottom right corner
    if (pos == ((boardsize*boardsize) - 1)){
        return 3;
    }

    // Returns 4 if it is in the bottom left corner
    if (((pos + boardsize) > (boardsize*boardsize)) && (pos % boardsize == 0)){
        return 4;
    }

    // Returns 5 if it is on the far right
    if (pos % (boardsize - 1) == 0){
        return 5;
    }

    // Returns 6 if it is on the far left
    if ((pos % boardsize) == 0){
        return 6;
    }

    // Returns 7 if it is on the top
    if ((pos - boardsize) < 0){
        return 7;
    } 

    // Returns 8 if it is on the bottom
    if ((pos + boardsize) > (boardsize*boardsize)){
        return 8;
    } 

    // Return 0 if nothing is wrong
    return 0;
}


void update_adjacent(int * board, int pos, int value){
    // This is mainly used for when something misses since the spots adjacent to it must also be empty
    // If the position is anywhere but on the far right, set the value to the right to 3
    if (!(pos % (boardsize - 1) == 0)){
        board[pos+1] = 3;
    } 

    // If the position is anywhere but on the far left, set the value to the left to 3
    if (!(pos % boardsize) == 0){
        board[pos-1] = 3;
    }

    // If the position is anywhere but at the top, set the value on top to 3
    if (!(pos - boardsize) < 0){
        board[pos - boardsize] = 3;
    } 

    // If the position is anywhere but at the bottom, set the value below to 3
    if (!(pos + boardsize) > (boardsize*boardsize)){
        board[pos + boardsize] = 3;
    } 
}

// Updating the board with the check numbers
void update_board(int * board, int x, int y, int value){
    int pos = (y * boardsize) + x;
    board[pos] = value;

    // If its a miss then the ones adjacent to it are also empty
    if (value == 3){
        update_adjacent(board, pos, value);
    } 
}

// Starts the algorithm
void start(int * board, int * hitboard){
    // There will be 17 spaces that make up the ships on the board
    // So once it has hit 17 times, it means that it has found everything
    while(hits < 17){
        make_move(board, hitboard);
    }

    print_board(hitboard);
}

int main(){
    // Setting the board size
    set_size();
    // Seeding the random number generator
    srand(time(0));
    
    // Allocating the memory
    int size = boardsize*boardsize;
    int memory_size = size * sizeof(int);
    int *board;
    board = (int *) malloc(memory_size);

    int *board_hits;
    board_hits = (int *) malloc(memory_size);

    // Making the board all 0s
    make_board(board);
    // Placing the ships on the board
    place_all(board);
    // Printing the completed board
    print_board(board);

    // The algorithm
    start(board, board_hits);
}