#ifndef sudoku_validator_test_cpp
#define sudoku_validator_test_cpp

#include "constants.cpp"

class Sudoku_Validator_Test
// Responsilities :
// 1 . Checks that the cell in sudoku_2d is solved or not.
// 2 . Checks that the cell in sudoku_3d is solved or not.
// 3 . Checks that the possibilities exists in the cell or not.
{
public:
	static bool do_possibilities_exist(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS], int row, int col, int poss)
	// Intended action : 
	// 1 . Checks if the possibilities exist in the cell and return true.
	// 2 . If the possibilities do not exist returns false.
	{
		return (sudoku_3d[row][col][poss] >= MIN_POSS && sudoku_3d[row][col][poss] < MAX_POSS);	
	}
};
#endif