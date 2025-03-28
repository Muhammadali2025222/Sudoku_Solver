#ifndef multiple_possibility_row_elimination_cpp
#define multiple_possibility_row_elimination_cpp

#include "sudoku_validator.cpp"

#include "constants.cpp"

#include "cells_comparison.cpp"

class Row_Possibility_Eliminator
{
public:
	static bool eliminate(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS], int row, int col)
	{
		bool is_possibility_eliminated = false;
		int box_start_row, box_start_col, box_end_row, box_end_col;

		for (int poss = MIN_POSS; poss < MAX_POSS; poss++)
		{
			Box_Determiner ::determine(row, col, box_start_row, box_start_col, box_end_row, box_end_col);

			for (int box_row = box_start_row; box_row <= box_end_row; box_row++)
			{
				for (int box_col = box_start_col; box_col <= box_end_col; box_col++)
				{
					if (Sudoku_Validator ::validate_possibilities(sudoku_3d, row, col, poss))
					{
						int box_next_row = box_row;
						int box_next_col = box_col + 1;
						if (box_next_col >= box_end_col && Cells_Comparison ::compare_two_cells(sudoku_3d, row, col, box_next_row, box_next_col))
						{
							for (int remove_col = MIN_COL; remove_col < MAX_COL; remove_col++)
							{
								if (remove_col != box_col && remove_col != box_next_col)
								{
									sudoku_3d[row][remove_col][poss] = BLANK_INDEX;
									is_possibility_eliminated = true;
								}
							}
						}

						box_next_col = box_col + 2;
						if (box_next_col >= box_end_col && Cells_Comparison ::compare_two_cells(sudoku_3d, row, col,box_next_row, box_next_col))
						{
							for (int remove_col = MIN_COL; remove_col < MAX_COL; remove_col++)
							{
								if (remove_col != box_col && remove_col != box_next_col)
								{
									sudoku_3d[row][remove_col][poss] = BLANK_INDEX;
									is_possibility_eliminated = true;
								}
							}
						}
					}
				}
			}
		}
		return is_possibility_eliminated;
	}
};

#endif