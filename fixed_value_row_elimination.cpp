#ifndef fixed_value_row_elimination_cpp
#define fixed_value_row_elimination_cpp

class Fixed_Value_Row_Elimination
{
	public:
		static void fixed_value_row_eliminator(int sudoku_2d[9][9], int new_sudoku_3d[9][9][10], int row, int col)
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
};

#endif