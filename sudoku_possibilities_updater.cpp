#ifndef sudoku_possibilities_updater_cpp
#define sudoku_possibilities_updater_cpp

#include "sudoku_validator.cpp"

#include "possibility_limiter.cpp"

class Sudoku_Possibilities_Updater
{
	public:
		static bool update(int sudoku_3d[9][9][10], int row, int col)
		{
			bool is_substituted = false;	
			if (Sudoku_Validator :: validate_solved_value(sudoku_3d, row, col))
			{
				for (int poss = MIN_POSS; poss < MAX_POSS; poss++) 
				{
					sudoku_3d[row][col][poss] = -1;
					is_substituted = true;
				}
			}
			return is_substituted;
		}
};

#endif