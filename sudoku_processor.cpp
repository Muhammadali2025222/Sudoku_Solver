#ifndef sudoku_processor_cpp
#define sudoku_processor_cpp

#include <iostream>

#include "elimination_implementor.cpp"
#include "fixed_value_checker.cpp"

#include "Solved_sudoku.cpp"

#include "print_updated_2d_sudoku.cpp"

using namespace std;

class Sudoku_Processor
{
	public:
		static void process_sudoku(int sudoku_2d[9][9], int new_sudoku_3d[9][9][10])
		{
			int row_reset_count = 0;
			for (int row = 0; row <= 9; row++)
			{
				if (Solved_Sudoku :: is_sudoku_solved(new_sudoku_3d))
				{
					cout << "Sudoku is solved!";
					Print_Updated_Sudoku_2d :: print_updated_sudoku_2d(sudoku_2d);

					break;
				}
				
				else if (row == 8)
				{
					row_reset_count++;
					if( row_reset_count == 10)
					{
						Print_Updated_Sudoku_2d :: print_updated_sudoku_2d(sudoku_2d);
						break;
					}
					row = -1; 
				}
				else
				{
					for (int col = 0; col < 9; col++)
					{
						if (Fixed_Value_Checker :: is_value_fixed(sudoku_2d, new_sudoku_3d, row, col))
						{
							Elimination_Implementor :: perform_elimination(sudoku_2d, new_sudoku_3d, row, col);
						}
					}
				}
			}
		}                                
};

#endif