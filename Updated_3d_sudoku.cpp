#ifndef Updated_3d_sudoku_cpp
#define Updated_3d_sudoku_cpp

class Updated_3d_Sudoku
{
	public:
		static void sudoku_3d_updater(int sudoku_2d[9][9], int sudoku_3d[9][9][10], int row, int col)
		{	
			if (sudoku_2d[row][col] > 0 && sudoku_2d[row][col] < 10 )
			{
				sudoku_3d[row][col][0] = sudoku_2d[row][col];
				for (int poss = 1; poss <= 9; poss++)
				{
					sudoku_3d[row][col][poss] = -1;
				}
			}	
		}
};

#endif