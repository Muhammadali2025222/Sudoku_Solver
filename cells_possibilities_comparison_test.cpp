#ifndef cells_possibilities_comparison_test_cpp
#define cells_possibilities_comparison_test_cpp

#include "constants.cpp"

class Cells_Possibilities_Comparison_Test
// Responsibility :
// 1 . Compare the possibility of two cells.
{
public:
	static bool do_cells_poss_match(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS], int box_row,
									int box_col, int box_next_row, int box_next_col, int poss)
	// Intended Action :
	// 1 . Compare the possibility of current cell and next cell and return a boolean.
	{
		return (sudoku_3d[box_row][box_col][poss] == sudoku_3d[box_next_row][box_next_col][poss]);
	}
};

#endif