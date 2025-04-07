#ifndef row_possibility_elimination_cpp
#define row_possibility_elimination_cpp

#include "sudoku_validator.cpp"
#include "constants.cpp"
#include "cells_possibilities_comparison.cpp"
#include "box_range_calculator.cpp"
#include "box_possibility_checker.cpp"

class Row_Possibility_Eliminator
// Responsibility :
// 1 . Eliminate the compared possibilities from the row if they donot exist in
// any other cell of the box.
{
public:
	static bool eliminate(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS], int row, int col)
	// Intended Action :
	// 1 . Iterate over the whole 3x3 box.
	// 2 . Compare the possbilities of 1st cell in row with middle cell in row and
	// with last cell in row.
	// 3 . Check that those possibilities are not present in any other cell of box
	// except the ones we compared.
	// 4 . Eliminate the same possibilities from all the other cells present in the row
	// except the ones we compared and returns true.
	// 5 . Otherwise return false.
	{
		bool is_possibility_eliminated = false;
		int box_start_row = INVALID_ROW, box_start_col = INVALID_COL;
		int box_end_row = INVALID_ROW, box_end_col = INVALID_COL;

		Box_Range_Calculator :: calculate_box_start(row, col, box_start_row, box_start_col);
		Box_Range_Calculator :: calculate_box_end(row, col, box_end_row, box_end_col);

		for (int box_row = box_start_row; box_row <= box_end_row; box_row++)
		{
			for (int box_col = box_start_col; box_col <= box_end_col; box_col++)
			{
				for (int poss = MIN_POSS; poss < MAX_POSS; poss++)
				{
					if (Sudoku_Validator :: do_possibilities_exist(sudoku_3d, row, col, poss))
					{
						int box_next_row = box_row;
						int box_next_col = box_col + BOX_MIDDLE_CELL;
						if (box_next_col <= box_end_col &&
							Cells_Possibilities_Comparison :: do_cells_poss_match(sudoku_3d,
																				 row, col,
																				 box_next_row,
																				 box_next_col, poss))
						{
							if (Box_Possibility_Checker :: exist_only_in_compared_cells(sudoku_3d,
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
							Cells_Possibilities_Comparison :: do_cells_poss_match(sudoku_3d,
																				 row, col,
																				 box_next_row,
																				 box_next_col, poss))
						{
							if (Box_Possibility_Checker :: exist_only_in_compared_cells(sudoku_3d,
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