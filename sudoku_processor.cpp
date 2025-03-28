#ifndef sudoku_processor_cpp
#define sudoku_processor_cpp

#include <iostream>

#include "solved_value_eliminator.cpp"
#include "unsolved_value_eliminator.cpp"
#include "updation_handler.cpp"
#include "sudoku_validator.cpp"

using namespace std;

class Sudoku_Processor
{
public:
	static void process(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS])
	{
		int box_start_row, box_start_col, box_end_row, box_end_col;
		
		for (int row = MIN_ROW; row < MAX_ROW; row++)
		{
			bool is_changed = false;
			for (int col = MIN_COL; col < MAX_COL; col++)
			{
				if (Sudoku_Validator ::validate_solved_value(sudoku_3d, row, col))
				{
					if (Solved_Value_Eliminator :: perform_elimination(sudoku_3d, row, col))
					{
						is_changed = true;
					}
					if (Updation_Handler :: perform_updation(sudoku_3d, row, col))
					{
						is_changed = true;
					}
				}
				Box_Determiner ::determine(row, col, box_start_row, box_start_col, box_end_row, box_end_col);
				if (row == box_end_row && col == box_end_col)
				{
					if (Unsolved_Value_Eliminator :: perform_elimination(sudoku_3d, row, col))
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