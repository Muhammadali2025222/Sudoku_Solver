#ifndef sudoku_processor_cpp
#define sudoku_processor_cpp

#include <iostream>

#include "elimination_handler.cpp"
#include "solved_cell_checker.cpp"

#include "Solved_sudoku.cpp"

#include "print_sudoku_2d.cpp"

#include "possibility_limiter.cpp"

#include "validated_3d_sudoku.cpp"

using namespace std;

class Sudoku_Processor
{
	public:
		static void process(int sudoku_2d[9][9], int sudoku_3d[9][9][10])
		{
			int count_unsolved_possibility = 0;
			int prev_unsolved_possibility_count = -1;
			int row_reset_count = 0;
			for (int row = 0; row < 9; row++)
			{
				if (Solved_Sudoku :: is_sudoku_solved(sudoku_3d))
				{
					cout << "Sudoku is solved!";
					Sudoku_Printer :: print(sudoku_2d);
					break;
				}
				
				else
				{
					for (int col = 0; col < 9; col++)
					{
						if (Solved_Cell_Checker :: is_cell_solved(sudoku_2d, sudoku_3d, row, col))
						{
							Elimination_Handler :: perform_elimination(sudoku_2d, sudoku_3d, row, col);
						}
						for (int poss = min_poss; poss < max_poss; poss++)
						{
							if (Sudoku_3d_Validator :: validate(sudoku_3d, row, col))
							{
								count_unsolved_possibility++;
							}
						}
					}
				}
				if (row == 8)
				{
					if(count_unsolved_possibility == prev_unsolved_possibility_count)
					{
						Sudoku_Printer :: print(sudoku_2d);
						cout << "No changes in possibilities. Breaking loop.\n";
						break;
					}
					else
					{
						prev_unsolved_possibility_count = count_unsolved_possibility;
						count_unsolved_possibility = 0;
						row = -1; 
					}
				}
			}
		}
		
          
};

#endif