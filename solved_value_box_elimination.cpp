#ifndef solved_value_box_elimination_cpp
#define solved_value_box_elimination_cpp

class Box_Elimination
{
	public:

		static void eliminate(int sudoku_2d[9][9], int sudoku_3d[9][9][10], int row, int col)
		{
			int solved_value = sudoku_2d[row][col];
			if (solved_value > 0 && solved_value < 10 )
			{
				int box_start_row = (row/3)*3;
				int box_start_col = (col/3)*3;

				for (int box_row = box_start_row; box_row < box_start_row + 3; box_row++)
				{
					for (int box_col = box_start_col; box_col < box_start_col + 3; box_col++)
					{
						for (int poss = 1; poss <= 9; poss++)
						{
							if (sudoku_3d[box_row][box_col][poss] == solved_value)
							{
								sudoku_3d[box_row][box_col][poss] = -1;
							}
						}
					}
				}
			}
		}
};

#endif