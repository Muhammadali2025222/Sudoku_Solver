#ifndef sudoku_processor_cpp
#define sudoku_processor_cpp

#include <iostream>

#include "elimination_handler.cpp"
#include "empty_cell_checker.cpp"

#include "Solved_sudoku.cpp"

#include "print_updated_2d_sudoku.cpp"

using namespace std;

class Sudoku_Processor
{
	public:
		static void process(int sudoku_2d[9][9], int sudoku_3d[9][9][10])
		{
			int row_reset_count = 0;
			for (int row = 0; row <= 9; row++)
			{
				if (Solved_Sudoku :: is_sudoku_solved(sudoku_3d))
				{
					cout << "Sudoku is solved!";
					Sudoku_Printer :: print(sudoku_2d);

					break;
				}
				
				else if (row == 8)
				{
					row_reset_count++;
					if( row_reset_count == 10)
					{
						Sudoku_Printer :: print(sudoku_2d);
						break;
					}
					row = -1; 
				}
				else
				{
					for (int col = 0; col < 9; col++)
					{
						if (Empty_Cell_Checker :: is_cell_empty(sudoku_2d, sudoku_3d, row, col))
						{
							Elimination_Handler :: perform_elimination(sudoku_2d, sudoku_3d, row, col);
						}
					}
				}
			}
		}                                
};

#endif