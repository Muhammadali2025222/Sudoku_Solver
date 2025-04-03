#ifndef column_elimination_cpp
#define column_elimination_cpp

#include "constants.cpp"

class Column_Elimination
{
public:
	static bool eliminate(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS], int row, int col)
	{
		bool is_possibility_eliminated = false;
		int eliminated_value = sudoku_3d[row][col][SOLVED_CELL];
		for (int remove_row = MIN_ROW; remove_row < MAX_ROW; remove_row++)
		{
			for (int poss = MIN_POSS; poss < MAX_POSS; poss++)
			{
				if (sudoku_3d[remove_row][col][poss] == eliminated_value)
				{
					sudoku_3d[remove_row][col][poss] = BLANK_CELL;
					is_possibility_eliminated = true;
				}
			}
		}
		return is_possibility_eliminated;
	}
};

#endif