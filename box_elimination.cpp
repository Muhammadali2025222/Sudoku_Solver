#ifndef box_elimination_cpp 
#define box_elimination_cpp

#include "box_range_calculator.cpp"
#include "constants.cpp"

class Box_Elimination
{
public:
	static bool eliminate(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS], int row, int col)
	{
		bool is_possibility_eliminated = false;

		int value_to_eliminate = sudoku_3d[row][col][SOLVED_CELL];
		int box_start_row = INVALID_ROW, box_start_col = INVALID_COL;
		int box_end_row = INVALID_ROW, box_end_col = INVALID_COL;

		Box_Range_Calculator :: calculate_box_start(row, col, box_start_row, box_start_col);
		Box_Range_Calculator :: calculate_box_end(row, col, box_end_row, box_end_col);

		for (int box_row = box_start_row; box_row <= box_end_row; box_row++)
		{
			for (int box_col = box_start_col; box_col <= box_end_col; box_col++)
			{
				if (box_row == row && box_col == col)
				{
					continue;
				}

				for (int poss = MIN_POSS; poss < MAX_POSS; poss++)
				{
					if (sudoku_3d[box_row][box_col][poss] == value_to_eliminate)
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
