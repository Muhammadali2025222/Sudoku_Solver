#ifndef Updated_3d_sudoku_cpp
#define Updated_3d_sudoku_cpp

#include "validated_2d_sudoku.cpp"

#include "possibility_limiter.cpp"

class Sudoku_3d_Updater
{
	public:
		static void update(int sudoku_2d[9][9], int sudoku_3d[9][9][10], int row, int col)
		{	
			if (Sudoku_2d_Validator :: validate(sudoku_2d, row, col))
			{
				sudoku_3d[row][col][0] = sudoku_2d[row][col];
				for (int poss = min_poss; poss < max_poss; poss++)
				{
					sudoku_3d[row][col][poss] = -1;
				}
			}
			
			
		}
};

#endif