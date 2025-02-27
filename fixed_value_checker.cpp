#ifndef fixed_value_checker_cpp
#define fixed_value_checker_cpp

#include <iostream>

using namespace std;

class Fixed_Value_Checker
{
	public:
		static bool is_value_fixed(int sudoku_2d[9][9], int new_sudoku_3d[9][9][10], int row, int col)
		{
			if (sudoku_2d[row][col] < 0 || sudoku_2d[row][col] > 9)
			{
				cout << "Cell [" << row << "][" << col << "] has no fixed value (Multiple possibilities)\n";
				
                cout << "2d sudoku: " << sudoku_2d[row][col] << "\n";
				
                cout << "3d sudoku: ";
				for (int poss = 0; poss < 10; poss++)
				{
					cout << new_sudoku_3d[row][col][poss] << "\t";
				}
				cout << "\n";
				return true;
			}
			else
			{
				cout << "Cell [" << row << "][" << col << "] has fixed value: " << sudoku_2d[row][col] << "\n";
				
                cout << "2d sudoku: " << sudoku_2d[row][col] << "\n";

				cout << "3d sudoku: ";
				for (int poss = 0; poss < 10; poss++)
				{
					cout << new_sudoku_3d[row][col][poss] << "\t";
				}
				cout << "\n";
                return false;
            }
		}                                
};

#endif