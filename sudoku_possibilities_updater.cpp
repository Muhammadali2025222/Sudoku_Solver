#ifndef sudoku_possibilities_updater_cpp
#define sudoku_possibilities_updater_cpp

#include "sudoku_validator.cpp"

#include "constants.cpp"

class Sudoku_Possibilities_Updater
{
	public:
		static bool update(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS], int row, int col)
		{
			bool is_substituted = false;	
			if (Sudoku_Validator :: validate_solved_value(sudoku_3d, row, col))
			{
				for (int poss = MIN_POSS; poss < MAX_POSS; poss++) 
				{
					sudoku_3d[row][col][poss] = BLANK_INDEX;
					is_substituted = true;
				}
			}
			return is_substituted;
		}
};

#endif