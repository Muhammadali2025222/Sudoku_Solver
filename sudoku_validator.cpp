#ifndef sudoku_validator_cpp
#define sudoku_validator_cpp
#include <iostream>
using namespace std;
class Sudoku_Validator 
{
	public:
		static bool validate_2d_sudoku(int sudoku_2d[9][9], int row, int col)
		{
			if (sudoku_2d[row][col] > 0 && sudoku_2d[row][col] < 10)
			{
				return true;
			}
            return false;
		}
		static bool validate_solved_value(int sudoku_3d[9][9][10], int row, int col)
		{
			if (sudoku_3d[row][col][0] > 0 && sudoku_3d[row][col][0] < 10)
			{
				return true;
			}
			return false;
		}
		static bool validate_possibilities(int sudoku_3d[9][9][10], int row, int col, int poss)
		{
			bool is_substituted = false;
            
			if (sudoku_3d[row][col][poss] > 0 && sudoku_3d[row][col][poss] < 10)
			{
				is_substituted = true;
			}
            return is_substituted;
		}
};
#endif