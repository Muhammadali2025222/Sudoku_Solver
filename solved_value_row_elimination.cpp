#ifndef solved_value_row_elimination_cpp
#define solved_value_row_elimination_cpp

#include "constants.cpp"

class Row_Elimination
{
public:
	static bool eliminate(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS], int row, int col)
	{
		bool is_possibility_eliminated = false;

		int eliminated_value = sudoku_3d[row][col][SOLVED_INDEX];
		
		for (int col_3d = MIN_COL; col_3d < MAX_COL; col_3d++)
		{
			for (int poss = MIN_POSS; poss < MAX_POSS; poss++)
			{
				if (sudoku_3d[row][col_3d][poss] == eliminated_value)
				{
					sudoku_3d[row][col_3d][poss] = BLANK_INDEX;
					is_possibility_eliminated = true;
				}
			}
		}

		return is_possibility_eliminated;
	}
};

#endif