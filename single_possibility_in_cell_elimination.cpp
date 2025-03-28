#ifndef single_possibility_in_cell_elimination_cpp
#define single_possibility_in_cell_elimination_cpp

#include "constants.cpp"

#include "sudoku_validator.cpp"

#include "sudoku_possibilities_updater.cpp"

class Single_Possibility_Cell_Updater
{
public:
	static bool update(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS], int row, int col)
	{
		int count = START_COUNT, last_possibility;

		for (int poss = MIN_POSS; poss < MAX_POSS; poss++)
		{
			if (Sudoku_Validator ::validate_possibilities(sudoku_3d, row, col, poss))
			{
				count++;
				last_possibility = sudoku_3d[row][col][poss];
			}
		}
		if (count == EXPECTED_COUNT)
		{
			sudoku_3d[row][col][SOLVED_INDEX] = last_possibility;
			Sudoku_Possibilities_Updater :: update(sudoku_3d, row, col);
			return true;
		}
		return false;
	}
};

#endif