#ifndef box_fixed_possibility_elimination_cpp
#define box_fixed_possibility_elimination_cpp

void box_fixed_possibility_elimination(int sudoku_2d[9][9], int new_sudoku_3d[9][9][10])
{
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			int fixed_value = sudoku_2d[row][col];
			if (fixed_value > -1)
			{
				int box_start_row = (row/3)*3;
				int box_start_col = (col/3)*3;

				for (int box_row = box_start_row; box_row < box_start_row + 3; box_row++)
				{
					for (int box_col = box_start_col; box_col < box_start_col + 3; box_col++)
					{
						for (int poss = 1; poss <= 9; poss++)
						{
							if (new_sudoku_3d[box_row][box_col][poss] == fixed_value)
							{
								new_sudoku_3d[box_row][box_col][poss] = -1;
							}
						}
					}
				}
			}
		}
	}
}

#endif