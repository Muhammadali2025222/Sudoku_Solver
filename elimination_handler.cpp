#ifndef elimination_handler_cpp
#define elimination_handler_cpp

#include <iostream>

#include "solved_value_row_elimination.cpp"
#include "solved_value_column_elimination.cpp"
#include "solved_value_box_elimination.cpp"

#include "single_possibility_in_cell_elimination.cpp"
#include "single_possibility_in_box_elimination.cpp"

#include "multiple_possibility_row_elimination.cpp"
#include "multiple_possibility_column_elimination.cpp"

#include "Updated_3d_sudoku.cpp"

#include "Solved_sudoku.cpp"

#include "print_updated_2d_sudoku.cpp"
#include "print_new_sudoku_3d.cpp"

using namespace std;

class Elimination_Handler
{
	public:
        static void perform_elimination(int sudoku_2d[9][9], int sudoku_3d[9][9][10], int row, int col)
        {
        	Row_Elimination :: eliminate(sudoku_2d, sudoku_3d, row, col);
			Column_Elimination :: eliminate(sudoku_2d, sudoku_3d, row, col);
			Box_Elimination :: eliminate(sudoku_2d, sudoku_3d, row, col);
			Box_Possibility_Eliminator :: eliminate(sudoku_2d, sudoku_3d, row, col);
			Cell_Possibility_Eliminator :: eliminate(sudoku_2d, sudoku_3d, row, col);
			Sudoku_3d_Updater :: update(sudoku_2d, sudoku_3d, row, col);
			Row_Possibility_Eliminator :: eliminate(sudoku_2d, sudoku_3d, row, col);
			Column_Possibility_Eliminator :: eliminate(sudoku_2d, sudoku_3d, row, col);
            Sudoku_3d_Updater :: update(sudoku_2d, sudoku_3d, row, col);
        }

};
#endif