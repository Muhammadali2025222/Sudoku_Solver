#ifndef cell_selection_cpp
#define cell_selection_cpp

#include <iostream>

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

class Cell_Selection_Builder
{
	public:
		static void cell_selector(int sudoku_2d[9][9], int new_sudoku_3d[9][9][10])
		{

			int row_reset_count = 0;
			for (int row = 0; row <= 9; row++)
			{
				
				for (int col = 0; col < 9; col++)
				{
					if (sudoku_2d[row][col] < 1)
					{
						cout << "Cell [" << row << "][" << col << "] has no fixed value (Multiple possibilities)\n";
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
					else
					{
						cout << "Cell [" << row << "][" << col << "] has fixed value: " << sudoku_2d[row][col] << "\n";
					}
					cout << "2d sudoku: " << sudoku_2d[row][col] << "\n";
					cout << "3d sudoku: ";
					for (int poss = 0; poss < 10; poss++)
					{
						cout << new_sudoku_3d[row][col][poss] << "\t";
					}
					cout << "\n";
				}

				if (Solved_Sudoku :: is_sudoku_solved(new_sudoku_3d))
				{
					cout << "Sudoku is solved!";
					Print_Updated_Sudoku_2d :: print_updated_sudoku_2d(sudoku_2d);
					return;
					break;
				}
				
				else if (row == 8)
				{
					row_reset_count++;
					if( row_reset_count == 10)
					{
						Print_Updated_Sudoku_2d :: print_updated_sudoku_2d(sudoku_2d);
						break;
					}
					row = -1; 
				}
			}
		}
};

#endif