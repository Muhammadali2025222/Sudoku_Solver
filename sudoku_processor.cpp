#ifndef sudoku_processor_cpp
#define sudoku_processor_cpp

#include <iostream>

#include "elimination_handler.cpp"
#include "sudoku_validator.cpp"

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
					row = 0;
				}
			
				else
				{
					for (int col = 0; col < 9; col++)
					{
						if (Sudoku_Validator :: validate_solved_value(sudoku_3d, row, col))
						{
							if (Elimination_Handler :: perform_elimination(sudoku_3d, row, col ))
							{}
						}
					}
				}
			}
		}
};

#endif