#ifndef sudoku_0th_index_validator_cpp
#define sudoku_0th_index_validator_cpp

class Zeroth_Index_Validator
{
	public:
		static bool validate(int sudoku_3d[9][9][10], int row, int col)
		{
			if (sudoku_3d[row][col][0] > 0 && sudoku_3d[row][col][0] < 10)
			{
				return true;
			}
            return false;
		}
};
#endif