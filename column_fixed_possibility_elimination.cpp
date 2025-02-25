#ifndef column_fixed_possibility_elimination_cpp
#define column_fixed_possibility_elimination_cpp

void column_fixed_possibility_elimination(int sudoku_2d[9][9], int new_sudoku_3d[9][9][10])
{
	for (int col = 0; col < 9; col++)
	{
		for (int row = 0; row < 9; row++)
		{
			int fixed_value = sudoku_2d[row][col];
			if (fixed_value > -1)
			{
				for (int row_3d = 0; row_3d < 9; row_3d++)
				{
					for (int poss = 1; poss <= 9; poss++)
					{
						if (new_sudoku_3d[row_3d][col][poss] == fixed_value)
						{
							new_sudoku_3d[row_3d][col][poss] = -1;
						}
					}
				}
			}
		}
	}
}

#endif