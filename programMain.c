#include <stdio.h>
#include <stdlib.h>
#include "tictactoe.h"

int main() {
    int grid[9] = {0};
    int position;
    char choice;
    int currentPlayer = 1;

    firstGrid(grid); // Load or start a new game

    while (1) {
        displayGrid(grid);

        printf("Player %c's turn. Enter a position (0-8), 's' to save, or 'q' to quit: ", currentPlayer == 1 ? 'X' : 'O');
        if (scanf(" %c", &choice) == 1) {
            if (choice == 's' || choice == 'S') {
                saveGame(grid);
                continue;
            } else if (choice == 'q' || choice == 'Q') {
                printf("Quitting the game...\n");
                break;
            } else if (choice >= '0' && choice <= '8') {
                position = choice - '0';
            } else {
                printf("Invalid input. Please enter a valid position, 's' to save, or 'q' to quit.\n");
                continue;
            }
        } else {
            printf("Invalid input. Please enter a valid position, 's' to save, or 'q' to quit.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        if (!isValidMove(grid, position)) {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        grid[position] = currentPlayer;

        if (checkWin(grid)) {
            displayGrid(grid);
            printf("Player %c wins!\n", currentPlayer == 1 ? 'X' : 'O');
            break;
        }

        if (isDraw(grid)) {
            displayGrid(grid);
            printf("The game is a draw.\n");
            break;
        }

        currentPlayer = currentPlayer == 1 ? 2 : 1;
    }

    return 0;
}
