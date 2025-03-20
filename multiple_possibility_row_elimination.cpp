#ifndef multiple_possibility_row_elimination_cpp
#define multiple_possibility_row_elimination_cpp

#include "sudoku_validator.cpp"

#include "constants.cpp"

class Row_Possibility_Eliminator
{
	public:
		static bool compare_two_cells_in_col(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS], int row, int col, int next_col) 
		{
			for (int poss = MIN_POSS; poss < MAX_POSS; poss++)
			{
				if (sudoku_3d[ row ][ col ][ poss ] = sudoku_3d[ row ][ next_col ][ poss ]) 
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
					int next_col = col + 1;
					if ( compare_two_cells_in_col( sudoku_3d, row, col, next_col))
					{
						for (int remove_col = MIN_COL; remove_col < MAX_COL; remove_col++)
						{
							if (remove_col != col && remove_col != next_col)
							{
								sudoku_3d[ row ][ remove_col ][ poss ] = BLANK_INDEX;
								is_substituted = true;
							}
						}
					}
					next_col = col + 2;
					if ( compare_two_cells_in_col( sudoku_3d, row, col, next_col))
					{
						for (int remove_col = MIN_COL; remove_col < MAX_COL; remove_col++)
						{
							if (remove_col != col && remove_col != next_col)
							{
								sudoku_3d[ row ][ remove_col ][ poss ] = BLANK_INDEX;
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