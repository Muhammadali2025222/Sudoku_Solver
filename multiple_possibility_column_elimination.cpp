#ifndef multiple_possibility_column_elimination_cpp
#define multiple_possibility_column_elimination_cpp

class Multiple_Possibility_Column_Elimination
{
	public:
		static bool compare_Row0_Row1_dimensions(int new_sudoku_3d[9][9][10], int row, int col) 
		{
			for (int poss = 1; poss < 10; poss++) 
			{
				if (new_sudoku_3d[row][col][poss] != new_sudoku_3d[row + 1][col][poss]) 
				{
					return false;
				}
			}
			return true;
		}

		static bool compare_Row0_Row2_dimensions(int new_sudoku_3d[9][9][10], int row, int col) 
		{
			for (int poss = 1; poss < 10; poss++) 
			{
				if (new_sudoku_3d[row][col][poss] != new_sudoku_3d[row + 2][col][poss]) 
				{
					return false;
				}
			}
			return true;
		}

		static void multiple_possibility_column_eliminator(int sudoku_2d[9][9], int new_sudoku_3d[9][9][10], int row, int col)
		{
			for (int poss = 1; poss <= 9; poss++)
			{
				if ( ( row > 0 || row > 3 || row > 6 ) && ( new_sudoku_3d[row][col][poss] > 0 && new_sudoku_3d[row][col][poss] < 10 ) )
				{
					if ( compare_Row0_Row1_dimensions( new_sudoku_3d, row, col) &&
						compare_Row0_Row2_dimensions( new_sudoku_3d, row, col) )
					{
						for (int remove_row = 0; remove_row < 9; remove_row++)
						{
							if ( remove_row != row && remove_row != row + 1 && remove_row != row + 2)
							{
								new_sudoku_3d[remove_row][col][poss] = -1;
							}
						}
					}
					else if ( compare_Row0_Row2_dimensions( new_sudoku_3d, row, col ) )
					{
						for (int remove_row = 0; remove_row < 9; remove_row++)
						{
							if (remove_row != row && remove_row != row + 1)
							{
									new_sudoku_3d[remove_row][col][poss] = -1;
							}
						}
					}
					else if ( compare_Row0_Row2_dimensions( new_sudoku_3d, row, col ) )
					{
						for (int remove_row = 0; remove_row < 9; remove_row++)
						{
							if (remove_row != row && remove_row != row + 2)
							{
									new_sudoku_3d[remove_row][col][poss] = -1;
							}
						}
					}
				}
			}
		}
};

#endif