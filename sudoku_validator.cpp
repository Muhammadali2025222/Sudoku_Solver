#ifndef sudoku_validator_cpp
#define sudoku_validator_cpp

#include "constants.cpp"

class Sudoku_Validator
{
public:
	static bool validate_2d_sudoku(int sudoku_2d[MAX_ROW][MAX_COL], int row, int col)
	{
		return (sudoku_2d[row][col] >= MIN_POSS && sudoku_2d[row][col] < MAX_POSS);
	}
	static bool validate_solved_cell(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS], int row, int col)
	{
		return (sudoku_3d[row][col][SOLVED_CELL] >= MIN_POSS && sudoku_3d[row][col][SOLVED_CELL] < MAX_POSS);
	}
	static bool validate_possibility(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS], int row, int col, int poss)
	{
		return (sudoku_3d[row][col][poss] >= MIN_POSS && sudoku_3d[row][col][poss] < MAX_POSS);	
	}
};
#endif