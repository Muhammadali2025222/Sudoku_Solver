#ifndef sudoku_processor_cpp
#define sudoku_processor_cpp

#include <iostream>

#include "elimination_handler.cpp"
#include "sudoku_validator.cpp"

using namespace std;

class Sudoku_Processor
{
	public:
		static void process(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS])
		{
			
			for (int row = MIN_ROW; row <= MAX_ROW; row++)
			{
				if (row == MAX_ROW)
				{
					row = MIN_ROW;
				}
			
				else
				{
					for (int col = MIN_COL; col < MAX_COL; col++)
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