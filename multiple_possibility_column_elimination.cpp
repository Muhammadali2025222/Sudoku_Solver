#ifndef multiple_possibility_column_elimination_cpp
#define multiple_possibility_column_elimination_cpp

#include "possibilities_validator.cpp"

#include "possibility_limiter.cpp"

class Column_Possibility_Eliminator
{
	public:
		static bool compare_first_two_cells_in_row(int sudoku_3d[9][9][10], int row, int col) 
		{
			for (int poss = MIN_POSS; poss < MAX_POSS; poss++) 
			{
				if (sudoku_3d[row][col][poss] != sudoku_3d[row + 1][col][poss]) 
				{
					return false;
				}
			}
			return true;
		}

		static bool compare_first_and_third_cells_in_row(int sudoku_3d[9][9][10], int row, int col) 
		{
			for (int poss = MIN_POSS; poss < MAX_POSS; poss++)  
			{
				if (sudoku_3d[row][col][poss] != sudoku_3d[row + 2][col][poss]) 
				{
					return false;
				}
			}
			return true;
		}

		static void eliminate(int sudoku_3d[9][9][10], int row, int col)
		{
			for (int poss = MIN_POSS; poss < MAX_POSS; poss++) 
			{
				if (( row > 0 || row > 3 || row > 6 ) &&  (Possibilities_Validator :: validate(sudoku_3d, row, col)))
				{
					if ( compare_first_two_cells_in_row( sudoku_3d, row, col) &&
					compare_first_and_third_cells_in_row( sudoku_3d, row, col))
					{
						for (int remove_row = 0; remove_row < 9; remove_row++)
						{
							if ( remove_row != row && remove_row != row + 1 && remove_row != row + 2)
							{
								sudoku_3d[remove_row][col][poss] = -1;
							}
						}
					}
					else if ( compare_first_two_cells_in_row( sudoku_3d, row, col))
					{
						for (int remove_row = 0; remove_row < 9; remove_row++)
						{
							if (remove_row != row && remove_row != row + 1)
							{
								sudoku_3d[remove_row][col][poss] = -1;
							}
						}
					}
					else if ( compare_first_and_third_cells_in_row( sudoku_3d, row, col))
					{
						for (int remove_row = 0; remove_row < 9; remove_row++)
						{
							if (remove_row != row && remove_row != row + 2)
							{
								sudoku_3d[remove_row][col][poss] = -1;
							}
						}
					}
				}
			}
		}
};

#endif