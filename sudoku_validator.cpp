#ifndef sudoku_validator_cpp
#define sudoku_validator_cpp

#include "constants.cpp"

#include <iostream>
using namespace std;

class Sudoku_Validator
{
public:
	static bool validate_2d_sudoku(int sudoku_2d[MAX_ROW][MAX_COL], int row, int col)
	{
		return (sudoku_2d[row][col] >= MIN_POSS && sudoku_2d[row][col] < MAX_POSS);
		
	}
	static bool validate_solved_value(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS], int row, int col)
	{
		return (sudoku_3d[row][col][SOLVED_INDEX] >= MIN_POSS && sudoku_3d[row][col][SOLVED_INDEX] < MAX_POSS);
	}
	static bool validate_possibilities(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS], int row, int col, int poss)
	{
		bool are_possibilities_validated = false;

		if (sudoku_3d[row][col][poss] >= MIN_POSS && sudoku_3d[row][col][poss] < MAX_POSS)
		{
			are_possibilities_validated = true;
		}
		return are_possibilities_validated;
	}
};
#endif