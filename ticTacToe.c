#include <stdio.h>
#include "ticTacToe.h"

int main() {
    char playAgain = 'n';
    do {
    char turn = 'X';
    int game = 0;
    int turns = 0;
    int playerCounter = 1;
    char board[] = { '-', '-', '-', '-', '-', '-', '-', '-', '-' };
    //Display the Intro to the game
    printf("\n=========================");
    printf("\nWELCOME TO TIC TAC TOE!");
    printf("\n1 --- player 1 vs. player 2");
    printf("\n2 --- player 1 vs. computer");
    printf("\nSelect game type (1 or 2):");
    scanf("%d", &game);
    printf("\nYou have entered choice %d", game);
    printf("\nThe board spaces are numbered like this\n");
    printf("+-----+\n");
    printf("|1|2|3|\n");
    printf("+-----+\n");
    printf("|4|5|6|\n");
    printf("+-----+\n");
    printf("|7|8|9|\n");
    printf("+-----+\n");
    printf("\nThe game is on!\n\n");

    //Game begins and loops until result has been decided. (Winner or draw)
    while (winCheck(board) == 0) {
        drawTable(board);
        //Offers player a choice based on what simulation they chose.
        playerChoice(board, &turn, &game);
        turns++;
        playerCounter++;
        //Check if winner.
        if (winCheck(board)) {
            drawTable(board);
            if(playerCounter % 2 == 0) //Player 1 wins on even turns
                printf("Player1 Wins!\n");
            if(playerCounter % 2 == 1) //Player 2 wins on even turns
                printf("Player2 Wins!\n");
        }
        if (moveCheck(turns)) {
            printf("Tie.\n");
        }
        switchTurn(&turn);
    }
    printf("Would you like to play again? (y/n): \n");
    playAgain = getchar();
    } while (playAgain == 'y' || playAgain == 'Y');
}