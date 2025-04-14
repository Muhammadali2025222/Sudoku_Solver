#ifndef sudoku_processor_cpp
#define sudoku_processor_cpp

#include "elimination_handler.cpp"
#include "sudoku_possibility_updater.cpp"
#include "sudoku_validator.cpp"
#include "box_range_calculator.cpp"

#include <iostream>

using namespace std;

class Sudoku_Processor
{
public:
	static void process(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS])
	{
		for (int row = MIN_ROW; row < MAX_ROW; row++)
		{
			bool has_made_progress = false;
			for (int col = MIN_COL; col < MAX_COL; col++)
			{
				if (Sudoku_Validator :: is_cell_solved(sudoku_3d, row, col))
				{
					if (Elimination_Handler :: eliminate_using_solved_cells(sudoku_3d, row, col))
					{
						has_made_progress = true;
					}
					if (Sudoku_Possibility_Updater :: update_possibility(sudoku_3d, row, col))
					{
						has_made_progress = true;
					}
				}

				int box_end_row = INVALID_ROW, box_end_col = INVALID_COL;
				Box_Range_Calculator :: calculate_box_end(row, col, box_end_row, box_end_col);

				if (row == box_end_row && col == box_end_col)
				{
					if (Elimination_Handler :: eliminate_using_unsolved_cells(sudoku_3d, row, col))
					{
						has_made_progress = true;
					}
				}
			}
			if (has_made_progress && row == ROW_RESET_LIMIT)
			{
				row = INVALID_ROW;
			}
		}
	}
};

#endif