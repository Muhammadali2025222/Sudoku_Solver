#ifndef sudoku_printer_cpp
#define sudoku_printer_cpp

#include <iostream>

using namespace std;

class Sudoku_Printer
{
	public:
		static void print(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS])
		{
			cout << "Sudoku 2d : \n ";
			for (int row = MIN_ROW; row < MAX_ROW; row++)
			{
				for (int col = MIN_COL; col < MAX_COL; col++)
				{
					cout << sudoku_3d[row][col][SOLVED_INDEX] << "\t";
				}
				cout << "\n" ;
			}
			cout << "\n" ;
		}
};

#endif