#ifndef TICTACTOE_H
#define TICTACTOE_H

void displayGrid(int* grid);
int checkWin(const int* grid);
int isValidMove(const int* grid, int position);
int isDraw(const int* grid);
void saveGame(const int* grid);
void loadGame(int* grid);
int firstGrid(int* grid);

#endif
