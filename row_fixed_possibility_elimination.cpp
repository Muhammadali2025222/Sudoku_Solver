#ifndef row_fixed_possibility_elimination_cpp
#define row_fixed_possibility_elimination_cpp

void row_fixed_possibility_elimination(int sudoku_2d[9][9], int new_sudoku_3d[9][9][10])
{
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			int fixed_value = sudoku_2d[row][col];
			if (fixed_value > -1)
			{
				for (int col_3d = 0; col_3d < 9; col_3d++)
				{
					for (int poss = 1; poss <= 9; poss++)
					{
						if (new_sudoku_3d[row][col_3d][poss] == fixed_value)
						{
							new_sudoku_3d[row][col_3d][poss] = -1;
						}
					}
				}
			}
		}

	}
}
#endif