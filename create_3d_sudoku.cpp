#ifndef create_3d_sudoku_cpp
#define create_3d_sudoku_cpp

void create_3d_sudoku(int sudoku_2d[9][9], int new_sudoku_3d[9][9][10])
{
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			
			if (sudoku_2d[ row ][ col ] > -1)
			{
				new_sudoku_3d[ row ][ col ][ 0 ] = sudoku_2d[ row ][ col ] ;
				for (int poss = 1 ; poss < 10 ; poss ++)
				{
					new_sudoku_3d[ row ][ col ][ poss ] = -1;
				}
			}
			else if (sudoku_2d[ row ][ col ] == -1)
			{
				new_sudoku_3d[ row ][ col ][ 0 ] = -1;
				for (int poss = 1 ; poss < 10 ; poss ++)
				{
					new_sudoku_3d[ row ][ col ][ poss ] = poss ;
				}
			}
		}
	}
}

#endif