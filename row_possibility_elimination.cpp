#ifndef row_possibility_elimination_cpp
#define row_possibility_elimination_cpp

#include "sudoku_validator.cpp"
#include "constants.cpp"
#include "cells_possibilities_comparison.cpp"
#include "box_range_determiner.cpp"
#include "box_possibility_checker.cpp"

class Row_Possibility_Eliminator
{
public:
	static bool eliminate(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS], int row, int col)
	{
		bool is_possibility_eliminated = false;
		int box_start_row, box_start_col, box_end_row, box_end_col;

		for (int poss = MIN_POSS; poss < MAX_POSS; poss++)
		{
			Box_Range_Determiner ::determine_Box_Range(row, col, box_start_row, box_start_col,
													   box_end_row, box_end_col);

			for (int box_row = box_start_row; box_row <= box_end_row; box_row++)
			{
				for (int box_col = box_start_col; box_col <= box_end_col; box_col++)
				{
					if (Sudoku_Validator ::validate_possibility(sudoku_3d, row, col, poss))
					{
						int box_next_row = box_row;
						int box_next_col = box_col + BOX_MIDDLE_CELL;
						if (box_next_col <= box_end_col &&
							Cells_Possibilities_Comparison ::do_cells_poss_match(sudoku_3d,
																				 row, col,
																				 box_next_row,
																				 box_next_col))
						{
							if (Box_Possibility_Checker ::exist_only_in_compared_cells(sudoku_3d,
																					   box_start_row,
																					   box_start_col,
																					   box_end_row,
																					   box_end_col,
																					   box_row,
																					   box_col,
																					   box_next_row,
																					   box_next_col,
																					   poss))
							{
								for (int remove_col = MIN_COL; remove_col < MAX_COL; remove_col++)
								{
									if (remove_col != box_col && remove_col != box_next_col)
									{
										sudoku_3d[row][remove_col][poss] = BLANK_CELL;
										is_possibility_eliminated = true;
									}
								}
							}
						}

						box_next_col = box_col + BOX_COL_RANGE;
						if (box_next_col == box_end_col &&
							Cells_Possibilities_Comparison ::do_cells_poss_match(sudoku_3d,
																				 row, col,
																				 box_next_row,
																				 box_next_col))
						{
							if (Box_Possibility_Checker ::exist_only_in_compared_cells(sudoku_3d,
																					   box_start_row,
																					   box_start_col,
																					   box_end_row,
																					   box_end_col,
																					   box_row,
																					   box_col,
																					   box_next_row,
																					   box_next_col,
																					   poss))
							{
								for (int remove_col = MIN_COL; remove_col < MAX_COL; remove_col++)
								{
									if (remove_col != box_col && remove_col != box_next_col)
									{
										sudoku_3d[row][remove_col][poss] = BLANK_CELL;
										is_possibility_eliminated = true;
									}
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