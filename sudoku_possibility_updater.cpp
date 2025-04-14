#ifndef sudoku_possibility_updater_cpp
#define sudoku_possibility_updater_cpp

#include "single_possibility_cell_updater.cpp"
#include "single_possibility_box_updater.cpp"

class Sudoku_Possibility_Updater
{
public:
	static bool update_possibility(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS], int row, int col)
	{
		bool is_updated = false;
		if (Single_Possibility_Box_Updater :: update_possibility(sudoku_3d, row, col))
		{
			is_updated = true;
		}
		if (Single_Possibility_Cell_Updater :: update_possibility(sudoku_3d, row, col))
		{
			is_updated = true;
		}
		return is_updated;
	}
};
#endif