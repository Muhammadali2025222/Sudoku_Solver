#ifndef updation_handler_cpp
#define updation_handler_cpp

#include "single_possibility_in_cell_elimination.cpp"
#include "single_possibility_in_box_elimination.cpp"

class Updation_Handler
{
public:
	static bool perform_updation(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS], int row, int col)
	{
		bool is_updated = false;
		if (Single_Possibility_Box_Updater :: update(sudoku_3d, row, col))
		{
			is_updated = true;
		}
		if (Single_Possibility_Cell_Updater :: update(sudoku_3d, row, col))
		{
			is_updated = true;
		}
		return is_updated;
	}
};
#endif