#include <stdio.h>
#include <stdlib.h>
int boardsize;

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

void place_ship(int length){

}

void place_all(){

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