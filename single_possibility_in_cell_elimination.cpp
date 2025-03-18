#ifndef single_possibility_in_cell_elimination_cpp
#define single_possibility_in_cell_elimination_cpp

#include "possibility_limiter.cpp"

#include "possibilities_validator.cpp"

class Cell_Possibility_Eliminator
{
	public:
		static bool eliminate(int sudoku_3d[9][9][10], int row, int col)
		{
			int count = 0;
			int last_possibility = 0;
			for (int poss = MIN_POSS; poss < MAX_POSS; poss++) 
			{
				if (Possibilities_Validator :: validate(sudoku_3d, row, col))
				{
					count++;
					last_possibility = sudoku_3d[row][col][poss];
				}
			}
			if (count == 1)
			{
				sudoku_3d[row][col][0] = last_possibility;
				return true;
			}
			return false;
		}
};

#endif