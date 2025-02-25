#ifndef column_multiple_possibility_elimination_cpp
#define column_multiple_possibility_elimination_cpp


bool compare_Row0_Row1_dimensions(int new_sudoku_3d[9][9][10]) 
{
    for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			for (int poss = 1; poss < 10; poss++) 
			{
				if (new_sudoku_3d[row][col][poss] != new_sudoku_3d[row + 1][col][poss]) 
				{
					return false;
				}
			}
		}
    }
	return true;
}

bool compare_Row0_Row2_dimensions(int new_sudoku_3d[9][9][10]) 
{
    for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			for (int poss = 1; poss < 10; poss++) 
			{
				if (new_sudoku_3d[row][col][poss] != new_sudoku_3d[row + 2][col][poss]) 
				{
					return false;
				}
			}
		}
    }
	return true;
}

void column_multiple_possibility_elimination(int sudoku_2d[9][9], int new_sudoku_3d[9][9][10])
{
    for (int col = 0; col < 9; col++)
    {
        for (int row = 0; row < 9; row++)
        {
            for (int poss = 1; poss <= 9; poss++)
            {
				if ( row > 0 || row > 3 || row > 6 && new_sudoku_3d[row][col][poss] > -1 )
				{
					if ( compare_Row0_Row1_dimensions( new_sudoku_3d ) &&
						 compare_Row0_Row2_dimensions( new_sudoku_3d ) )
				   {
					   for (int remove_row = 0; remove_row < 9; remove_row++)
					   {
						   if ( remove_row != row && remove_row != row + 1 && remove_row != row + 2)
						   {
							   new_sudoku_3d[remove_row][col][poss] = -1;
						   }
					   }
				   }
				   else if ( compare_Row0_Row2_dimensions( new_sudoku_3d ) )
				   {
					   for (int remove_row = 0; remove_row < 9; remove_row++)
					   {
						   if (remove_row != row && remove_row != row + 1)
						   {
								new_sudoku_3d[remove_row][col][poss] = -1;
						   }
					   }
				   }
				   else if ( compare_Row0_Row2_dimensions( new_sudoku_3d ) )
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
    }
}

#endif