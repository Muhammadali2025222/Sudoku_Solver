#ifndef Solved_sudoku_cpp
#define Solved_sudoku_cpp

#include "sudoku_validator.cpp"

class Solved_Sudoku
{
public:
	static bool is_sudoku_solved(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS])
	{
		for (int row = MIN_ROW; row < MAX_ROW; row++)
		{
			for (int col = MIN_COL; col < MAX_ROW; col++)
			{
				if (Sudoku_Validator :: validate_solved_value(sudoku_3d, row, col))
				{
					return false;
				}
			}
		}
		return true;
	}
};

#endif