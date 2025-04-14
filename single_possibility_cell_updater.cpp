#ifndef single_possibility_cell_updater_cpp
#define single_possibility_cell_updater_cpp

#include "constants.cpp"
#include "sudoku_validator.cpp"
#include "cell_possibilities_updater.cpp"

class Single_Possibility_Cell_Updater
{
private:
	static const int START_COUNT = 0;
	static const int EXPECTED_COUNT = 1;

public:
	static bool update_possibility(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS], int row, int col)
	{
		int count = START_COUNT, last_possibility = INVALID_POSS;

		for (int poss = MIN_POSS; poss < MAX_POSS; poss++)
		{
			if (Sudoku_Validator :: do_possibilities_exist(sudoku_3d, row, col, poss))
			{
				count++;
				last_possibility = sudoku_3d[row][col][poss];
			}
			if (count > EXPECTED_COUNT)
			{
				break;
			}
		}
		if (count == EXPECTED_COUNT)
		{
			sudoku_3d[row][col][SOLVED_CELL] = last_possibility;
			sudoku_3d[row][col][last_possibility] = BLANK_CELL;
			return true;
		}
		return false;
	}
};

#endif