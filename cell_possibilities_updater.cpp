#ifndef cell_possibilities_updater_cpp
#define cell_possibilities_updater_cpp

#include "sudoku_validator.cpp"
#include "constants.cpp"

class Cell_Possibilities_Updater
{
public:
	static bool update_possibility(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS], int row, int col)
	{
		bool are_possibilities_updated = false;
		
		if (Sudoku_Validator :: is_cell_solved(sudoku_3d, row, col))
		{
			for (int poss = MIN_POSS; poss < MAX_POSS; poss++)
			{
				sudoku_3d[row][col][poss] = BLANK_CELL;
				are_possibilities_updated = true;
			}
		}
		return are_possibilities_updated;
	}
};

#endif