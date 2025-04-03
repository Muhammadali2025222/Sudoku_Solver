#ifndef column_possibility_elimination_cpp
#define column_possibility_elimination_cpp

#include "sudoku_validator.cpp"
#include "constants.cpp"
#include "cells_possibilities_comparison.cpp"
#include "box_range_determiner.cpp"
#include "box_possibility_checker.cpp"

class Column_Possibility_Eliminator
{
public:
	static bool eliminate(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS], int row, int col)
	{
		bool is_possibility_eliminated = false;
		int box_start_row, box_start_col, box_end_row, box_end_col;

		for (int poss = MIN_POSS; poss < MAX_POSS; poss++)
		{
			Box_Range_Determiner::determine_Box_Range(row, col, box_start_row,
													  box_start_col, box_end_row, box_end_col);

			for (int box_row = box_start_row; box_row <= box_end_row; box_row++)
			{
				for (int box_col = box_start_col; box_col <= box_end_col; box_col++)
				{
					if (Sudoku_Validator::validate_possibility(sudoku_3d, box_row, box_col, poss))
					{
						int box_next_row = box_row + 1;
						int box_next_col = box_col;

						if (box_next_row <= box_end_row &&
							Cells_Possibilities_Comparison::do_cells_poss_match(sudoku_3d,
																				box_row, box_col,
																				box_next_row, box_next_col))
						{
							if (Box_Possibility_Checker::exist_only_in_compared_cells(sudoku_3d,
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
								for (int remove_row = box_start_row; remove_row <= box_end_row; remove_row++)
								{
									if (remove_row != box_row && remove_row != box_next_row)
									{
										sudoku_3d[remove_row][col][poss] = BLANK_CELL;
										is_possibility_eliminated = true;
									}
								}
							}
						}

						box_next_row = box_row + BOX_ROW_RANGE;
						if (box_next_row == box_end_row &&
							Cells_Possibilities_Comparison::do_cells_poss_match(sudoku_3d,
																				 box_row,
																				 box_col,
																				 box_next_row,
																				 box_next_col))
						{
							if (Box_Possibility_Checker::exist_only_in_compared_cells(sudoku_3d,
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
								for (int remove_row = box_start_row; remove_row <= box_end_row; remove_row++)
								{
									if (remove_row != box_row && remove_row != box_next_row)
									{
										sudoku_3d[remove_row][col][poss] = BLANK_CELL;
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
