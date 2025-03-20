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

#include "sudoku_possibilities_updater.cpp"

#include "Solved_sudoku.cpp"

using namespace std;

class Elimination_Handler
{
	public:
        static bool perform_elimination(int sudoku_3d[9][9][10], int row, int col)
        {
			bool is_eliminated = false;
			if (Row_Elimination :: eliminate(sudoku_3d, row, col))
			{
				is_eliminated = true;
			}
			if (Column_Elimination :: eliminate(sudoku_3d, row, col))
			{
				is_eliminated = true;
			}
			if (Box_Elimination :: eliminate(sudoku_3d, row, col))
			{
				is_eliminated = true;
			}
			if (Box_Possibility_Eliminator :: eliminate(sudoku_3d, row, col))
			{
				is_eliminated = true;
			}
			if (Sudoku_Possibilities_Updater :: update(sudoku_3d, row, col))
			{
				is_eliminated = true;
			}
			if (Cell_Possibility_Eliminator :: eliminate(sudoku_3d, row, col))
			{
				is_eliminated = true;
			}
			if (Row_Possibility_Eliminator :: eliminate(sudoku_3d, row, col))
			{
				is_eliminated = true;
			}
			if (Column_Possibility_Eliminator :: eliminate(sudoku_3d, row, col))
			{
				is_eliminated = true;
			}			
			return is_eliminated;
        }

};
#endif