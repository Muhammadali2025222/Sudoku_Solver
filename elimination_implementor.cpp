#ifndef elimination_implementor_cpp
#define elimination_implementor_cpp

#include <iostream>

// #include "cell_selection.cpp"

#include "fixed_value_row_elimination.cpp"
#include "fixed_value_column_elimination.cpp"
#include "fixed_value_box_elimination.cpp"

#include "single_possibility_in_cell_elimination.cpp"
#include "single_possibility_in_box_elimination.cpp"

#include "multiple_possibility_row_elimination.cpp"
#include "multiple_possibility_column_elimination.cpp"

#include "Updated_3d_sudoku.cpp"

#include "Solved_sudoku.cpp"

#include "print_updated_2d_sudoku.cpp"
#include "print_new_sudoku_3d.cpp"

using namespace std;

class Elimination_Implementor
{
	public:
        static void perform_elimination(int sudoku_2d[9][9], int new_sudoku_3d[9][9][10])
        {
            Fixed_Value_Row_Elimination :: fixed_value_row_eliminator(sudoku_2d, new_sudoku_3d);
			Fixed_Value_Column_Elimination :: fixed_value_column_eliminator(sudoku_2d, new_sudoku_3d);
			Fixed_Value_Box_Elimination :: fixed_value_box_eliminator(sudoku_2d, new_sudoku_3d);
			Single_Possibility_In_Box_Elimination :: single_possibility_in_box_eliminator(sudoku_2d, new_sudoku_3d);
			Single_Possibility_In_Cell_Elimination :: single_possibility_in_cell_eliminator(sudoku_2d, new_sudoku_3d);
			Updated_3d_Sudoku :: sudoku_3d_updater(sudoku_2d, new_sudoku_3d);
			Multiple_Possibility_Row_Elimination :: multiple_possibility_row_eliminator(sudoku_2d, new_sudoku_3d);
			Multiple_Possibility_Column_Elimination :: multiple_possibility_column_eliminator(sudoku_2d, new_sudoku_3d);
            Updated_3d_Sudoku :: sudoku_3d_updater(sudoku_2d, new_sudoku_3d);
        }

};
#endif