#ifndef solved_value_column_elimination_cpp
#define solved_value_column_elimination_cpp

#include "constants.cpp"

class Column_Elimination
{
public:
	static bool eliminate(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS], int row, int col)
	{
		bool is_possibility_eliminated = false;
		int eliminated_value = sudoku_3d[row][col][SOLVED_INDEX];
		for (int row_3d = MIN_ROW; row_3d < MAX_ROW; row_3d++)
		{
			for (int poss = MIN_POSS; poss < MAX_POSS; poss++)
			{
				if (sudoku_3d[row_3d][col][poss] == eliminated_value)
				{
					sudoku_3d[row_3d][col][poss] = BLANK_INDEX;
					is_possibility_eliminated = true;
				}
			}
		}
		return is_possibility_eliminated;
	}
};

#endif