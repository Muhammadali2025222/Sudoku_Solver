#ifndef fixed_value_column_elimination_cpp
#define fixed_value_column_elimination_cpp

class Fixed_Value_Column_Elimination
{
	public:

		static void fixed_value_column_eliminator(int sudoku_2d[9][9], int sudoku_3d[9][9][10], int row, int col)
		{
			int fixed_value = sudoku_2d[row][col];
			if (fixed_value > 0 && fixed_value < 10)
			{
				for (int row_3d = 0; row_3d < 9; row_3d++)
				{
					for (int poss = 1; poss <= 9; poss++)
					{
						if (sudoku_3d[row_3d][col][poss] == fixed_value)
						{
							sudoku_3d[row_3d][col][poss] = -1;
						}
					}
				}
			}
		}
};

#endif