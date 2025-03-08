#ifndef solved_cell_checker_cpp
#define solved_cell_checker_cpp

#include "validated_2d_sudoku.cpp"

#include <iostream>

using namespace std;

class Solved_Cell_Checker
{
	public:
		static bool is_cell_solved(int sudoku_2d[9][9], int sudoku_3d[9][9][10], int row, int col)
		{
			if (Sudoku_2d_Validator :: validate(sudoku_2d, row, col))
			{
				cout << "Cell [" << row << "][" << col << "] has solved value: " << sudoku_2d[row][col] << "\n";
				
                cout << "2d sudoku: " << sudoku_2d[row][col] << "\n";

				cout << "3d sudoku: ";
				for (int poss = 0; poss < 10; poss++)
				{
					cout << sudoku_3d[row][col][poss] << "\t";
				}
				cout << "\n";
                return true;
			}
			else
			{
				cout << "Cell [" << row << "][" << col << "] has no solved value (Multiple possibilities)\n";
				
                cout << "2d sudoku: " << sudoku_2d[row][col] << "\n";
				
                cout << "3d sudoku: ";
				for (int poss = 0; poss < 10; poss++)
				{
					cout << sudoku_3d[row][col][poss] << "\t";
				}
				cout << "\n";
				return false;
            }
		}                                
};

#endif