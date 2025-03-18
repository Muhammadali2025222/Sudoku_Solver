#ifndef solved_cell_checker_cpp
#define solved_cell_checker_cpp

#include "zeroth_index_validator.cpp"
#include "possibility_limiter.cpp"
#include <iostream>

using namespace std;

class Solved_Cell_Checker
{
	public:
		static bool is_cell_solved(int sudoku_2d[9][9], int sudoku_3d[9][9][10], int row, int col)
		{
			if (Zeroth_Index_Validator :: validate(sudoku_3d, row, col))
			{
				cout << "Cell [" << row << "][" << col << "] has solved value: " << sudoku_3d[row][col][0] << "\n";
				
                cout << "2d sudoku: " << sudoku_3d[row][col][0] << "\n";

				cout << "3d sudoku: ";
				for (int poss = 0; poss < MAX_POSS; poss++)
				{
					cout << sudoku_3d[row][col][poss] << "\t";
				}
				cout << "\n";
                return true;
			}
			else
			{
				cout << "Cell [" << row << "][" << col << "] has no solved value (Multiple possibilities)\n";
				
                cout << "2d sudoku: " << sudoku_3d[row][col][0] << "\n";
				
                cout << "3d sudoku: ";
				for (int poss = 0; poss < MAX_POSS; poss++)
				{
					cout << sudoku_3d[row][col][poss] << "\t";
				}
				cout << "\n";
				return false;
            }
		}                                
};

#endif