#ifndef sudoku_printer_cpp
#define sudoku_printer_cpp

#include <iostream>

using namespace std;

class Sudoku_Printer
{
	public:
		static void print(int sudoku_3d[9][9][10])
		{
			cout << "Sudoku 2d : \n ";
			for (int row = 0; row < 9; row++)
			{
				for (int col = 0; col < 9; col++)
				{
					cout << sudoku_3d[ row ][ col ][ 0 ] << "\t";
				}
				cout << "\n" ;
			}
			cout << "\n" ;
		}
};

#endif