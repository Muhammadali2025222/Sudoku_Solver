#ifndef Solved_sudoku_cpp
#define Solved_sudoku_cpp

#include "sudoku_validator.cpp"

class Solved_Sudoku
{
	public:
		static bool is_sudoku_solved(int sudoku_3d[9][9][10])
		{
			for (int row = 0; row < 9; row++)
			{
				for (int col = 0; col < 9; col++)
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