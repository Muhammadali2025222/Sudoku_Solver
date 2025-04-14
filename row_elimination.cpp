#ifndef row_elimination_cpp
#define row_elimination_cpp

#include "constants.cpp"

class Row_Elimination
{
public:
	static bool eliminate(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS], int row, int col)
	{
		bool is_possibility_eliminated = false;

		int value_to_eliminate = sudoku_3d[row][col][SOLVED_CELL];
		int poss = value_to_eliminate;
		for (int remove_col = MIN_COL; remove_col < MAX_COL; remove_col++)
		{
			if (sudoku_3d[row][remove_col][poss] == value_to_eliminate)
			{
				sudoku_3d[row][remove_col][poss] = BLANK_CELL;
				is_possibility_eliminated = true;
			}
		}
		return is_possibility_eliminated;
	}
};

#endif