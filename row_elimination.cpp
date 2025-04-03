#ifndef row_elimination_cpp
#define row_elimination_cpp

#include "constants.cpp"

class Row_Elimination
{
public:
	static bool eliminate(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS], int row, int col)
	{
		bool is_possibility_eliminated = false;

		int eliminated_value = sudoku_3d[row][col][SOLVED_CELL];

		for (int remove_col = MIN_COL; remove_col < MAX_COL; remove_col++)
		{
			for (int poss = MIN_POSS; poss < MAX_POSS; poss++)
			{
				if (sudoku_3d[row][remove_col][poss] == eliminated_value)
				{
					sudoku_3d[row][remove_col][poss] = BLANK_CELL;
					is_possibility_eliminated = true;
				}
			}
		}
		return is_possibility_eliminated;
	}
};

#endif