#ifndef solved_value_row_elimination_cpp
#define solved_value_row_elimination_cpp

#include "possibility_limiter.cpp"

class Row_Elimination
{
	public:
		static bool eliminate(int sudoku_3d[9][9][10], int row, int col)
		{
			bool is_substituted = false;
			int solved_value = sudoku_3d[row][col][0];
			
			for (int col_3d = 0; col_3d < 9; col_3d++)
			{
				for (int poss = MIN_POSS; poss < MAX_POSS; poss++) 
				{
					if (sudoku_3d[row][col_3d][poss] == solved_value)
					{
						sudoku_3d[row][col_3d][poss] = -1;
						is_substituted = true;
					}
				}
			}
			return is_substituted;
		}
};

#endif