#ifndef sudoku_validator_cpp
#define sudoku_validator_cpp

#include "constants.cpp"

class Sudoku_Validator
// Responsilities :
// 1 . Checks that the cell in sudoku_2d is solved or not.
// 2 . Checks that the cell in sudoku_3d is solved or not.
// 3 . Checks that the possibilities exists in the cell or not.
{
public:
	static bool is_cell_solved(int sudoku_2d[MAX_ROW][MAX_COL], int row, int col)
	// Intended action : 
	// 1 . Checks if the cell in sudoku_2d is solved and return true.
	// 2 . If the cell is not solved returns false.
	{
		return (sudoku_2d[row][col] >= MIN_POSS && sudoku_2d[row][col] < MAX_POSS);
	}
	static bool is_cell_solved(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS], int row, int col)
	// Intended action : 
	// 1 . Checks if the cell in sudoku_3d is solved and return true.
	// 2 . If the cell is not solved returns false.
	{
		return do_possibilities_exist(sudoku_3d, row, col, SOLVED_CELL);
	}
	static bool do_possibilities_exist(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS], int row, int col, int poss)
	// Intended action : 
	// 1 . Checks if the possibilities exist in the cell and return true.
	// 2 . If the possibilities do not exist returns false.
	{
		return (sudoku_3d[row][col][poss] >= MIN_POSS && sudoku_3d[row][col][poss] < MAX_POSS);	
	}
};
#endif