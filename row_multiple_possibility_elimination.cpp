#ifndef row_multiple_possibility_elimination_cpp
#define row_multiple_possibility_elimination_cpp

bool compare_Col0_Col1_dimensions(int new_sudoku_3d[9][9][10]) 
{
    for (int col = 0; col < 9; col++)
	{
		for (int row = 0; row < 9; row++)
		{
			for (int poss = 1; poss < 10; poss++) 
			{
				if (new_sudoku_3d[ row ][ col ][ poss ] != new_sudoku_3d[ row ][ col + 1 ][ poss ]) 
				{
					return false;
				}
			}
		}
    }
	return true;
}

bool compare_Col0_Col2_dimensions(int new_sudoku_3d[9][9][10]) 
{
    for (int col = 0; col < 9; col++)
	{
		for (int row = 0; row < 9; row++)
		{
			for (int poss = 1; poss < 10; poss++) 
			{
				if (new_sudoku_3d[ row ][ col ][ poss ] != new_sudoku_3d[ row ][ col + 2 ][ poss ]) 
				{
					return false;
				}
			}
		}
    }
	return true;
}

void row_multiple_possibility_elimination(int sudoku_2d[9][9], int new_sudoku_3d[9][9][10])
{
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			for (int poss = 1; poss <= 9; poss++)
            {
				if ( col > 0 || col > 3 || col > 6 && new_sudoku_3d[ row ][ col ][ poss ] > -1 )
				{
					if ( compare_Col0_Col1_dimensions( new_sudoku_3d ) &&
						 compare_Col0_Col2_dimensions( new_sudoku_3d ) )
				   {
					   for (int remove_col = 0; remove_col < 9; remove_col++)
					   {
						   if ( remove_col != col && remove_col != col + 1 && remove_col != col + 2)
						   {
							new_sudoku_3d[ row ][ remove_col ][ poss ] = -1;
						   }
					   }
				   }
				   else if ( compare_Col0_Col2_dimensions( new_sudoku_3d ) )
				   {
					   for (int remove_col = 0; remove_col < 9; remove_col++)
					   {
						   if (remove_col != col && remove_col != col + 1)
						   {
							new_sudoku_3d[ row ][ remove_col ][ poss ] = -1;
						   }
					   }
				   }
				   else if ( compare_Col0_Col2_dimensions( new_sudoku_3d ) )
				   {
					   for (int remove_col = 0; remove_col < 9; remove_col++)
					   {
						   if (remove_col != col && remove_col != col + 2)
						   {
							new_sudoku_3d[ row ][ remove_col ][ poss ] = -1;
						   }
					   }
				   }
				}
            }
		}
	}
}

#endif