#include <iostream>

bool are_dimensions_equal(int arr1[10], int arr2[10]) {
    for (int i = 0; i < 10; i++) {
        if (arr1[i] != arr2[i]) {
            return false; // If any value is different, return false
        }
    }
    return true; // All values are identical
}

void column_possibility_elimination(int sudoku_2d[9][9], int sudoku_3d[9][9][10]) {
    for (int col = 0; col < 9; col++) { // Iterate through each column
        for (int row = 0; row < 9; row++) { // Iterate through each row
            // Check if three consecutive rows have identical third dimensions
            if (row + 2 < 9 && are_dimensions_equal(sudoku_3d[row][col], sudoku_3d[row + 1][col]) &&
                are_dimensions_equal(sudoku_3d[row][col], sudoku_3d[row + 2][col])) 
            {
                // Remove from all other rows except these three
                for (int remove_row = 0; remove_row < 9; remove_row++) {
                    if (remove_row != row && remove_row != row + 1 && remove_row != row + 2) {
                        for (int poss = 0; poss < 10; poss++) {
                            sudoku_3d[remove_row][col][poss] = -1;
                        }
                    }
                }
            }
            // Check if two consecutive rows have identical third dimensions
            else if (row + 1 < 9 && are_dimensions_equal(sudoku_3d[row][col], sudoku_3d[row + 1][col])) 
            {
                // Remove from all other rows except these two
                for (int remove_row = 0; remove_row < 9; remove_row++) {
                    if (remove_row != row && remove_row != row + 1) {
                        for (int poss = 0; poss < 10; poss++) {
                            sudoku_3d[remove_row][col][poss] = -1;
                        }
                    }
                }
            }
            // Check if a cell matches the one two rows below it
            else if (row + 2 < 9 && are_dimensions_equal(sudoku_3d[row][col], sudoku_3d[row + 2][col])) 
            {
                // Remove from all other rows except these two
                for (int remove_row = 0; remove_row < 9; remove_row++) {
                    if (remove_row != row && remove_row != row + 2) {
                        for (int poss = 0; poss < 10; poss++) {
                            sudoku_3d[remove_row][col][poss] = -1;
                        }
                    }
                }
            }
        }
    }
}
