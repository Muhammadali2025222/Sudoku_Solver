#ifndef cells_comparison_cpp
#define cells_comparison_cpp

#include "sudoku_validator.cpp"

#include "constants.cpp"

class Cells_Comparison
{
public:
	static bool compare_two_cells(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS], int box_row, int box_col, int box_next_row, int box_next_col)
	{
		for (int poss = MIN_POSS; poss < MAX_POSS; poss++)
		{
			if (sudoku_3d[box_row][box_col][poss] = sudoku_3d[box_next_row][box_next_col][poss])
			{
				return true;
			}
		}
		return false;
	}
};

#endif