#ifndef compare_sudoku_3d_and_new_sudoku_3d_cpp
#define compare_sudoku_3d_and_new_sudoku_3d_cpp

#include <iostream>
using namespace std;

bool compare_sudoku_3d_and_new_sudoku_3d(int sudoku_3d[9][9][10], int new_sudoku_3d[9][9][10]) 
{
    for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			for (int poss = 0; poss < 10; poss++) 
			{
				if (sudoku_3d[row][col][poss] == new_sudoku_3d[row ][col][poss]) 
				{
					cout << "sudoku_3d is equal to new_sudoku_3d";
					return true;
				}
			}
		}
    }
	cout<<"sudoku_3d is not equal to new_sudoku_3d";
	return false;
}

#endif