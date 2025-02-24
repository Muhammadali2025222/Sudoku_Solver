#ifndef print_updated_2d_sudoku_cpp
#define print_updated_2d_sudoku_cpp

#include <iostream>
using namespace std;

void print_updated_sudoku_2d(int sudoku_2d[9][9])
{
	cout << "Sudoku 2d : \n ";
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			cout << sudoku_2d[ row ][ col ] << "\t";
		}
		cout << "\n" ;
	}
	cout << "\n" ;
}

#endif