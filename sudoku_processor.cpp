#ifndef sudoku_processor_cpp
#define sudoku_processor_cpp

#include "elimination_handler.cpp"
#include "sudoku_possibility_updater.cpp"
#include "sudoku_validator.cpp"
#include "box_range_determiner.cpp"

#include <iostream>

using namespace std;

class Sudoku_Processor
{
public:
	static void process(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS])
	{
		for (int row = MIN_ROW; row < MAX_ROW; row++)
		{
			bool is_changed = false;
			for (int col = MIN_COL; col < MAX_COL; col++)
			{
				if (Sudoku_Validator ::validate_solved_cell(sudoku_3d, row, col))
				{
					if (Elimination_Handler ::eliminate_using_solved_cells(sudoku_3d, row, col))
					{
						is_changed = true;
					}
					if (Sudoku_Possibility_Updater ::update_possibility(sudoku_3d, row, col))
					{
						is_changed = true;
					}
				}
				int box_start_row, box_start_col, box_end_row, box_end_col;
				Box_Range_Determiner ::determine_Box_Range(row, col, box_start_row, box_start_col,
														   box_end_row, box_end_col);
				if (row == box_end_row && col == box_end_col)
				{
					if (Elimination_Handler ::eliminate_using_unsolved_cells(sudoku_3d, row, col))
					{
						is_changed = true;
					}
				}
			}
			if (is_changed && row == ROW_RESET_LIMIT)
			{
				row = ROW_START;
			}
		}
	}
};

#endif