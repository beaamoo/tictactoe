#include <stdio.h>
#include "tictactoe.h"

void displayGrid(int* grid) {
    printf(" %c | %c | %c \n", grid[0] == 0 ? ' ' : (grid[0] == 1 ? 'X' : 'O'),
           grid[1] == 0 ? ' ' : (grid[1] == 1 ? 'X' : 'O'),
           grid[2] == 0 ? ' ' : (grid[2] == 1 ? 'X' : 'O'));
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", grid[3] == 0 ? ' ' : (grid[3] == 1 ? 'X' : 'O'),
           grid[4] == 0 ? ' ' : (grid[4] == 1 ? 'X' : 'O'),
           grid[5] == 0 ? ' ' : (grid[5] == 1 ? 'X' : 'O'));
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", grid[6] == 0 ? ' ' : (grid[6] == 1 ? 'X' : 'O'),
           grid[7] == 0 ? ' ' : (grid[7] == 1 ? 'X' : 'O'),
           grid[8] == 0 ? ' ' : (grid[8] == 1 ? 'X' : 'O'));
}

int checkWin(const int* grid) {
    // Check rows
    for (int i = 0; i < 9; i += 3) {
        if (grid[i] != 0 && grid[i] == grid[i + 1] && grid[i] == grid[i + 2]) {
            return grid[i];
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (grid[i] != 0 && grid[i] == grid[i + 3] && grid[i] == grid[i + 6]) {
            return grid[i];
        }
    }

    // Check diagonals
    if (grid[0] != 0 && grid[0] == grid[4] && grid[0] == grid[8]) {
        return grid[0];
    }
    if (grid[2] != 0 && grid[2] == grid[4] && grid[2] == grid[6]) {
        return grid[2];
    }

    return 0; // No winner yet
}

int isValidMove(const int* grid, int position) {
    if (grid[position] == 0) {
        return 1; // Valid move
    } else {
        return 0; // Invalid move
    }
}

int isDraw(const int* grid) {
    for (int i = 0; i < 9; i++) {
        if (grid[i] == 0) {
            return 0; // Game is not a draw
        }
    }
    return 1; // Game is a draw
}

void saveGame(const int* grid) {
    FILE* file = fopen("save.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < 9; i++) {
        fprintf(file, "%d ", grid[i]);
    }

    fclose(file);
    printf("Game saved successfully.\n");
}

void loadGame(int* grid) {
    FILE* file = fopen("save.txt", "r");
    if (file == NULL) {
        printf("No saved game found.\n");
        return;
    }

    for (int i = 0; i < 9; i++) {
        fscanf(file, "%d", &grid[i]);
    }

    fclose(file);
    printf("Game loaded successfully.\n");
}

int firstGrid(int* grid) {
    int choice;

    while (1) {
        printf("Let's Play Tic-Tac-Toe!\n");
        printf("1. Start a new game\n");
        printf("2. Load a saved game\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice. Please enter a valid number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        if (choice == 1) {
            for (int i = 0; i < 9; i++) {
                grid[i] = 0;
            }
            printf("New game started.\n");
            return 1;
        } else if (choice == 2) {
            loadGame(grid);
            return 1;
        } else if (choice == 3) {
            printf("Quitting the game...\n");
            return 0;
        } else {
            printf("Invalid choice. Please enter a valid number.\n");
        }
    }
}
