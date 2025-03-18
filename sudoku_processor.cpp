#ifndef sudoku_processor_cpp
#define sudoku_processor_cpp

#include <iostream>

#include "elimination_handler.cpp"
#include "solved_cell_checker.cpp"

using namespace std;

class Sudoku_Processor
{
	public:
		static void process(int sudoku_2d[9][9], int sudoku_3d[9][9][10])
		{
			
			for (int row = 0; row <= 9; row++)
			{
				if (row == 9)
				{
					row = -1;
				}
			
				else
				{
					for (int col = 0; col < 9; col++)
					{
						if (Solved_Cell_Checker :: is_cell_solved(sudoku_2d, sudoku_3d, row, col))
						{
							if (Elimination_Handler :: perform_elimination(sudoku_2d, sudoku_3d, row, col ))
							{}
						}
					}
					
				}
				
			}
		}
};

#endif