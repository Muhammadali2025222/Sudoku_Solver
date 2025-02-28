#ifndef multiple_possibility_row_elimination_cpp
#define multiple_possibility_row_elimination_cpp

class Multiple_Possibility_Row_Elimination
{
	public:
		static bool compare_Col0_Col1_dimensions(int sudoku_3d[9][9][10], int row, int col) 
		{
			for (int poss = 1; poss < 10; poss++) 
			{
				if (sudoku_3d[ row ][ col ][ poss ] != sudoku_3d[ row ][ col + 1 ][ poss ]) 
				{
					return false;
				}
			}
			return true;
		}

		static bool compare_Col0_Col2_dimensions(int sudoku_3d[9][9][10], int row, int col) 
		{
			for (int poss = 1; poss < 10; poss++) 
			{
				if (sudoku_3d[ row ][ col ][ poss ] != sudoku_3d[ row ][ col + 2 ][ poss ]) 
				{
					return false;
				}
			}
			return true;
		}

		static void multiple_possibility_row_eliminator(int sudoku_2d[9][9], int sudoku_3d[9][9][10], int row, int col)
		{
			for (int poss = 1; poss <= 9; poss++)
			{
				if ( ( col > 0 || col > 3 || col > 6 ) && ( sudoku_3d[row][col][poss] > 0 && sudoku_3d[row][col][poss] < 10 ) )
				{
					if ( compare_Col0_Col1_dimensions( sudoku_3d, row, col ) &&
						compare_Col0_Col2_dimensions( sudoku_3d, row, col ) )
					{
						for (int remove_col = 0; remove_col < 9; remove_col++)
						{
							if ( remove_col != col && remove_col != col + 1 && remove_col != col + 2)
							{
								sudoku_3d[ row ][ remove_col ][ poss ] = -1;
							}
						}
					}
					else if ( compare_Col0_Col2_dimensions( sudoku_3d, row, col ) )
					{
						for (int remove_col = 0; remove_col < 9; remove_col++)
						{
							if (remove_col != col && remove_col != col + 1)
							{
								sudoku_3d[ row ][ remove_col ][ poss ] = -1;
							}
						}
					}
					else if ( compare_Col0_Col2_dimensions( sudoku_3d, row, col ) )
					{
						for (int remove_col = 0; remove_col < 9; remove_col++)
						{
							if (remove_col != col && remove_col != col + 2)
							{
								sudoku_3d[ row ][ remove_col ][ poss ] = -1;
							}
						}
					}
				}
			}
		}
};

#endif