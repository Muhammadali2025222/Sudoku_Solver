#ifndef validated_2d_sudoku_cpp
#define validated_2d_sudoku_cpp

class Sudoku_2d_Validator
{
	public:
		static bool validate(int sudoku_2d[9][9], int row, int col)
		{
			if (sudoku_2d[row][col] > 0 && sudoku_2d[row][col] < 10)
			{
				return true;
			}
            return false;
		}
};

#endif