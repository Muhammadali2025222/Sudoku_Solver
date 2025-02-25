#ifndef single_possibility_in_cell_cpp
#define single_possibility_in_cell_cpp

void single_possibility_in_cell(int sudoku_2d[9][9], int new_sudoku_3d[9][9][10])
{
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			int count = 0;
			int last_possibility = 0;
			for (int poss = 1; poss <= 9; poss++)
			{
				if (new_sudoku_3d[row][col][poss] > -1)
				{
					count++;
					last_possibility = new_sudoku_3d[row][col][poss];
				}
			}
			if (count == 1)
			{
				sudoku_2d[row][col] = last_possibility;
			}
		}
	}
}

#endif