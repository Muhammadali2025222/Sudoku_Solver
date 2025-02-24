#ifndef cell_selection_cpp
#define cell_selection_cpp

#include <iostream>

#include "Solved_sudoku.cpp"
#include "Updated_3d_sudoku.cpp"
#include "print_updated_2d_sudoku.cpp"
#include "column_multiple_possibility_elimination.cpp"
#include "row_multiple_possibility_elimination.cpp"
#include "single_possibility_in_cell.cpp"
#include "box_fixed_possibility_elimination.cpp"
#include "column_fixed_possibility_elimination.cpp"
#include "row_fixed_possibility_elimination.cpp"
#include "single_possibility_in_box.cpp"
#include "print_new_sudoku_3d.cpp"

using namespace std;


void cell_selection(int sudoku_2d[9][9], int new_sudoku_3d[9][9][10])
{
	int row_reset_count = 0;
	for (int row = 0; row <= 9; row++)
	{
		
		for (int col = 0; col < 9; col++)
		{
			if (sudoku_2d[row][col] < 1)
			{
				cout << "Cell [" << row << "][" << col << "] has no fixed value (Multiple possibilities)\n";
				row_fixed_possibility_elimination(sudoku_2d, new_sudoku_3d);
				column_fixed_possibility_elimination(sudoku_2d, new_sudoku_3d);
				box_fixed_possibility_elimination(sudoku_2d, new_sudoku_3d);
				single_possibility_in_box(sudoku_2d, new_sudoku_3d);
				row_fixed_possibility_elimination(sudoku_2d, new_sudoku_3d);
				column_fixed_possibility_elimination(sudoku_2d, new_sudoku_3d);
				box_fixed_possibility_elimination(sudoku_2d, new_sudoku_3d);
				single_possibility_in_cell(sudoku_2d, new_sudoku_3d);
				sudoku_3d_updater(sudoku_2d, new_sudoku_3d);
				row_multiple_possibility_elimination(sudoku_2d, new_sudoku_3d);
				column_multiple_possibility_elimination(sudoku_2d, new_sudoku_3d);
				sudoku_3d_updater(sudoku_2d, new_sudoku_3d);
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

		if (is_sudoku_solved(new_sudoku_3d))
		{
			cout << "Sudoku is solved!";
			print_updated_sudoku_2d(sudoku_2d);
			return;
			break;
		}
		
		else if (row == 8)
		{
			row_reset_count++;
			if( row_reset_count == 10)
			{
				print_updated_sudoku_2d(sudoku_2d);
				break;
			}
			row = -1; 
		}
	}
}

#endif