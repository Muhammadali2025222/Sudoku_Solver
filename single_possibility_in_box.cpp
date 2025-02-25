#ifndef single_possibility_in_box_cpp
#define single_possibility_in_box_cpp

void single_possibility_in_box(int sudoku_2d[9][9], int new_sudoku_3d[9][9][10])
{
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			int box_start_row = (row/3)*3;
			int box_start_col = (col/3)*3;

			for (int poss = 1; poss <= 9; poss++)
			{
				int count = 0;
				int last_row = 0, last_col = 0;
				for (int box_row = box_start_row; box_row < box_start_row + 3; box_row++)
				{
					for (int box_col = box_start_col; box_col < box_start_col + 3; box_col++)
					{
						if (new_sudoku_3d[box_row][box_col][poss] == poss)
						{
							count++;
							last_row = box_row;
							last_col = box_col;
						}
					}
				}
				if (count == 1)
				{
					sudoku_2d[last_row][last_col] = poss;
				}
			}
		}
	}
}

#endif