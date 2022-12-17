#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

//Draw the table
void drawTable(char board[]) {
    int i;
    printf("\n");
    printf("+-----+\n");
    for (i = 0; i < 9; i++){
        printf("|%c", board[i]);
        if (((i + 1) % 3) == 0) {
            printf("|\n+-----+\n");
        }
    }
}

//Switch turns
void switchTurn(char *turn){
    if (*turn == 'X') 
        *turn = 'O';
    else
        *turn = 'X';
}

//PVP or PVE
void playerChoice(char board[], char *turn, int *game) {
        int choice;
    int upper = 9;
    int lower = 1;
    if(*turn == 'X'){
        printf("\nPlayer1: make your move! (pick 1-9 starting from top left)\n");
        scanf("%d", &choice);
            if(board[choice - 1] != '-') {
                while(board[choice - 1] != '-') {
                    printf("\nError! Square already filled. Pick a different square. (1-9):\n");
                    scanf("%d", &choice);
                }
            }
    }
    if(*turn == 'O'){
        //PVP choice, player 2 can enter moves.
        if(*game == 1){
        printf("\nPlayer 2: make your move! (pick 1-9 starting from top left)\n");
        scanf("%d", &choice);
            if(board[choice - 1] != '-') {
                while(board[choice - 1] != '-') {
                    printf("\nError! Square already filled. Pick a different square. (1-9):\n");
                    scanf("%d", &choice);
                }
            }
        }
        //PVE choice, random move is selected for CPU.
        if(*game == 2){
            printf("\nThe CPU has moved:\n");
            choice = (rand() % (upper - lower + 1)) + lower;
            if(board[choice - 1] != '-') {
                while(board[choice - 1] != '-') {
                    choice = (rand() % (upper - lower + 1)) + lower;
                }
            }
        }
    }
    //if board has an empty spot then player choice is allowed.
    board[choice - 1] = *turn;
}
//Check for win
bool winCheck(char board[]) {
        bool win = false;
    //check horizontal win condition: (top 0-2) (middle 3-5) (bottom 6-9)
    if (board[0] != '-') {
        if (board[0] == board[1] && board[0] == board[2])
            win = true;;
    }
    if (board[3] != '-') {
        if (board[3] == board[4] && board[3] == board[5])
            win = true;;
    }
    if (board[6] != '-') {
        if (board[6] == board[7] && board[6] == board[8])
            win = true;;
    }
    //check vertical win condition: (left 0 3 6) (middle 1 4 7) (right 2 5 8)
    if (board[0] != '-') {
        if (board[0] == board[3] && board[0] == board[6])
            win = true;;
    }
    if (board[2] != '-') {
        if (board[2] == board[4] && board[2] == board[7])
            win = true;
    }
    if (board[3] != '-') {
        if (board[3] == board[5] && board[3] == board[8])
            win = true;
    }
    //check diagonal win condition: ( \ 0 4 8) ( / 2 4 6)
    if (board[0] != '-') {
        if (board[0] == board[4] && board[0] == board[8])
            win = true;
    }
    if (board[2] != '-') {
        if (board[2] == board[4] && board[2] == board[6])
            win = true;
    }
    return win;
}

//check if out of moves
bool moveCheck(int turns) {
    if (turns < 9) {
        return false;
    }
    else {
        return true;
    }
}