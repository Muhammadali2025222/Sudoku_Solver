#ifndef box_elimination_cpp
#define box_elimination_cpp

#include "box_range_determiner.cpp"
#include "constants.cpp"

class Box_Elimination
{
public:
	static bool eliminate(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS], int row, int col)
	{
		bool is_possibility_eliminated = false;

		int eliminated_value = sudoku_3d[row][col][SOLVED_CELL];
		int box_start_row, box_start_col, box_end_row, box_end_col;

		Box_Range_Determiner :: determine_Box_Range(row, col, box_start_row, box_start_col,
								box_end_row, box_end_col);

		for (int box_row = box_start_row; box_row <= box_end_row; box_row++)
		{
			for (int box_col = box_start_col; box_col <= box_end_col; box_col++)
			{
				for (int poss = MIN_POSS; poss < MAX_POSS; poss++)
				{
					if (sudoku_3d[box_row][box_col][poss] == eliminated_value)
					{
						sudoku_3d[box_row][box_col][poss] = BLANK_CELL;
						is_possibility_eliminated = true;
					}
				}
			}
		}
		return is_possibility_eliminated;
	}
};

#endif