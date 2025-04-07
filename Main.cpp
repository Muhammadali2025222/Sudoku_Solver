#include "create_sudoku_3d.cpp"
#include "sudoku_processor.cpp"
#include "sudoku_printer.cpp"
#include "constants.cpp"

#include <iostream>

using namespace std;


int main()
{
	int sudoku_2d[MAX_ROW][MAX_COL] = {
		{ 2, -1, -1,  3, -1,  1, -1, -1,  5},
		{-1, -1, -1, -1,  4,  2,  6, -1, -1},
		{-1,  5, -1, -1, -1, -1, -1,  8,  2},
		{-1,  7, -1,  1, -1,  8, -1, -1, -1},
		{-1,  1, -1, -1, -1, -1, -1, -1, -1},
		{ 9, -1,  6, -1,  7, -1, -1, -1, -1},
		{ 6, -1,  5, -1,  9, -1, -1, -1,  7},
		{-1,  8, -1, -1, -1, -1, -1,  3,  9},
		{-1, -1, -1, -1,  3, -1, -1, -1, -1}
	};

	int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS];

	Sudoku_3d_Creator :: create(sudoku_2d ,sudoku_3d);
	
	Sudoku_Printer :: print(sudoku_3d);
	Sudoku_Processor :: process(sudoku_3d);

	Sudoku_Printer :: print(sudoku_3d);
}