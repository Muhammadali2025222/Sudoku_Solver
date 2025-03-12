#ifndef sudoku_3d_updater_cpp
#define sudoku_3d_updater_cpp

#include "sudoku_0th_index_validator.cpp"

#include "possibility_limiter.cpp"

class Sudoku_3d_Updater
{
	public:
		static void update_possibilities(int sudoku_2d[9][9], int sudoku_3d[9][9][10], int row, int col)
		{	
			if (Zeroth_Index_Validator :: validate(sudoku_3d, row, col))
			{
				for (int poss = MIN_POSS; poss < MAX_POSS; poss++) 
				{
					sudoku_3d[row][col][poss] = -1;
				}
			}
			
			
		}
};

#endif