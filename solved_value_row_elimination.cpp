#ifndef solved_value_row_elimination_cpp
#define solved_value_row_elimination_cpp

class Row_Elimination
{
	public:
		static void eliminate(int sudoku_2d[9][9], int sudoku_3d[9][9][10], int row, int col)
		{
			int solved_value = sudoku_2d[row][col];
			if (solved_value > 0 && solved_value < 10)
			{
				for (int col_3d = 0; col_3d < 9; col_3d++)
				{
					for (int poss = 1; poss <= 9; poss++)
					{
						if (sudoku_3d[row][col_3d][poss] == solved_value)
						{
							sudoku_3d[row][col_3d][poss] = -1;
						}
					}
				}
			}
		}
};

#endif