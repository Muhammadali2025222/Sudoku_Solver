#ifndef Updated_3d_sudoku_cpp
#define Updated_3d_sudoku_cpp

void sudoku_3d_updater(int sudoku_2d[9][9], int new_sudoku_3d[9][9][10])
{
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			if (sudoku_2d[row][col] > -1)
			{
				new_sudoku_3d[row][col][0] = sudoku_2d[row][col];
				for (int poss = 1; poss <= 9; poss++)
				{
					new_sudoku_3d[row][col][poss] = -1;
				}
			}
		}
	}
}

#endif