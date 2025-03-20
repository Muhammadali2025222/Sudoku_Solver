#ifndef multiple_possibility_column_elimination_cpp
#define multiple_possibility_column_elimination_cpp

#include "sudoku_validator.cpp"

#include "constants.cpp"

class Column_Possibility_Eliminator
{
	public:
		static bool compare_two_cells_in_row(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS], int row, int col, int next_row) 
		{
			for (int poss = MIN_POSS; poss < MAX_POSS; poss++) 
			{
				if (sudoku_3d[row][col][poss] = sudoku_3d[next_row][col][poss]) 
				{
					return true;
				}
			}
			return false;
		}

		static bool eliminate(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS], int row, int col)
		{
			bool is_substituted = false;
			for (int poss = MIN_POSS; poss < MAX_POSS; poss++) 
			{
				if ((Sudoku_Validator :: validate_possibilities(sudoku_3d, row, col, poss)))
				{
					int next_row = row + 1;
					if ( compare_two_cells_in_row( sudoku_3d, row, col, next_row))
					{
						for (int remove_row = MIN_ROW; remove_row < MAX_ROW; remove_row++)
						{
							if (remove_row != row && remove_row != next_row )
							{
								sudoku_3d[remove_row][col][poss] = BLANK_INDEX;
								is_substituted = true;
							}
						}
					}
					next_row = row + 2;
					if ( compare_two_cells_in_row( sudoku_3d, row, col, next_row))
					{
						for (int remove_row = MIN_ROW; remove_row < MAX_ROW; remove_row++)
						{
							if (remove_row != row && remove_row != next_row )
							{
								sudoku_3d[remove_row][col][poss] = BLANK_INDEX;
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