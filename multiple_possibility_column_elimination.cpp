#ifndef multiple_possibility_column_elimination_cpp
#define multiple_possibility_column_elimination_cpp

#include "possibilities_validator.cpp"

#include "possibility_limiter.cpp"

class Column_Possibility_Eliminator
{
	public:
		static bool compare_two_cells_in_row(int sudoku_3d[9][9][10], int row, int col, int next_row) 
		{
			for (int poss = MIN_POSS; poss < MAX_POSS; poss++) 
			{
				if (sudoku_3d[row][col][poss] != sudoku_3d[next_row][col][poss]) 
				{
					return false;
				}
			}
			return true;
		}

		static bool eliminate(int sudoku_3d[9][9][10], int row, int col)
		{
			bool is_substituted = false;
			for (int poss = MIN_POSS; poss < MAX_POSS; poss++) 
			{
				if (( row < 3 || row < 6 || row < 9 ) && (Possibilities_Validator :: validate(sudoku_3d, row, col)))
				{
					int next_row = row + 1;
					if ( compare_two_cells_in_row( sudoku_3d, row, col, next_row))
					{
						for (int remove_row = 0; remove_row < 9; remove_row++)
						{
							if (remove_row != row && remove_row != next_row )
							{
								sudoku_3d[remove_row][col][poss] = -1;
								is_substituted = true;
							}
						}
					}
					next_row = row + 2;
					if ( compare_two_cells_in_row( sudoku_3d, row, col, next_row))
					{
						for (int remove_row = 0; remove_row < 9; remove_row++)
						{
							if (remove_row != row && remove_row != next_row )
							{
								sudoku_3d[remove_row][col][poss] = -1;
								is_substituted = true;
							}
						}
					}
				}
			}
			return is_substituted;
		}
};

#endif