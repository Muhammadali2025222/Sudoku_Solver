#ifndef solved_value_column_elimination_cpp
#define solved_value_column_elimination_cpp

#include "possibility_limiter.cpp"

class Column_Elimination
{
	public:
		static void eliminate(int sudoku_2d[9][9], int sudoku_3d[9][9][10], int row, int col)
		{
			int solved_value = sudoku_2d[row][col];
			for (int row_3d = 0; row_3d < 9; row_3d++)
			{
				for (int poss = min_poss; poss < max_poss; poss++)
				{
					if (sudoku_3d[row_3d][col][poss] == solved_value)
					{
						sudoku_3d[row_3d][col][poss] = -1;
					}
				}
			}	
		}
};

#endif