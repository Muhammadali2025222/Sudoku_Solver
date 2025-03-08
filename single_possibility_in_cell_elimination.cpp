#ifndef single_possibility_in_cell_elimination_cpp
#define single_possibility_in_cell_elimination_cpp

#include "possibility_limiter.cpp"

#include "validated_3d_sudoku.cpp"

class Cell_Possibility_Eliminator
{
	public:
		static void eliminate(int sudoku_2d[9][9], int sudoku_3d[9][9][10], int row, int col)
		{
			int count = 0;
			int last_possibility = 0;
			for (int poss = min_poss; poss < max_poss; poss++)
			{
				if (Sudoku_3d_Validator :: validate(sudoku_3d, row, col))
				{
					count++;
					last_possibility = sudoku_3d[row][col][poss];
				}
			}
			if (count == 1)
			{
				sudoku_2d[row][col] = last_possibility;
			}
		}
};

#endif