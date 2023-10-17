#include </usr/local/include/CUnit/CUnit.h>
#include </usr/local/include/CUnit/Basic.h>
#include "tictactoe.h"

void testCheckWin() {
    int grid1[9] = {1, 1, 1, 0, 0, 0, 0, 0, 0}; // Player 1 wins horizontally
    int grid2[9] = {0, 0, 0, 1, 1, 1, 0, 0, 0}; // Player 1 wins vertically
    int grid3[9] = {0, 0, 0, 0, 0, 0, 1, 1, 1}; // Player 1 wins diagonally
    int grid4[9] = {1, 0, 0, 1, 0, 0, 1, 0, 0}; // Player 1 wins diagonally

    CU_ASSERT_EQUAL(checkWin(grid1), 1);
    CU_ASSERT_EQUAL(checkWin(grid2), 1);
    CU_ASSERT_EQUAL(checkWin(grid3), 1);
    CU_ASSERT_EQUAL(checkWin(grid4), 1);
}

void testIsValidMove() {
    int grid1[9] = {1, 0, 0, 0, 0, 0, 0, 0, 0}; // Valid move
    int grid2[9] = {1, 0, 0, 0, 1, 0, 0, 0, 0}; // Invalid move
    int grid3[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0}; // Valid move
    int grid4[9] = {1, 1, 1, 0, 0, 0, 0, 0, 0}; // Invalid move

    CU_ASSERT_EQUAL(isValidMove(grid1, 1), 1);
    CU_ASSERT_EQUAL(isValidMove(grid2, 4), 0);
    CU_ASSERT_EQUAL(isValidMove(grid3, 4), 1);
    CU_ASSERT_EQUAL(isValidMove(grid4, 0), 0);
}

void testIsDraw() {
    int grid1[9] = {1, 2, 1, 2, 1, 2, 2, 1, 0}; // Not a draw
    int grid2[9] = {1, 2, 1, 2, 1, 2, 2, 1, 2}; // Draw

    CU_ASSERT_EQUAL(isDraw(grid1), 0);
    CU_ASSERT_EQUAL(isDraw(grid2), 1);
}

void testSaveAndLoadGame() {
    int grid1[9] = {1, 0, 0, 0, 0, 0, 0, 0, 0}; // Initial grid
    int grid2[9]; // Loaded grid

    saveGame(grid1);
    loadGame(grid2);

    for (int i = 0; i < 9; i++) {
        CU_ASSERT_EQUAL(grid1[i], grid2[i]);
    }
}

int main() {
    CU_initialize_registry();

    CU_pSuite suite = CU_add_suite("Tic Tac Toe Test Suite", NULL, NULL);
    CU_add_test(suite, "Test checkWin", testCheckWin);
    CU_add_test(suite, "Test isValidMove", testIsValidMove);
    CU_add_test(suite, "Test isDraw", testIsDraw);
    CU_add_test(suite, "Test saveAndLoadGame", testSaveAndLoadGame);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}
