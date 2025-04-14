#ifndef column_possibility_elimination_cpp
#define column_possibility_elimination_cpp

#include "constants.cpp"
#include "box_range_calculator.cpp"
#include "box_possibility_checker.cpp"

class Column_Possibility_Eliminator
// Responsibility :
// 1 . Eliminate the compared possibilities from the col if they donot exist in
// any other cell of the box.
{
public:
	static bool eliminate(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS], int row, int col)
	// Intended Action :
	// 1 . Iterate over the whole 3x3 box.
	// 2 . Check that the possibility is not present in any other cell of box
	// except the one we are on.
	// 3 . Eliminate the same possibility from all the other cells present in the
	// col except the one we are on.
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
					if (Box_Possibility_Checker :: exist_only_in_compared_cells(sudoku_3d, box_start_row,
						box_start_col, box_end_row, box_end_col, box_row, box_col, poss))
					{
						for (int remove_row = box_start_row; remove_row <= box_end_row; remove_row++)
						{
							if (remove_row != box_row)
							{
								sudoku_3d[remove_row][col][poss] = BLANK_CELL;
								is_possibility_eliminated = true;
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
