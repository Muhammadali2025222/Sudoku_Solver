#ifndef Solved_sudoku_cpp
#define Solved_sudoku_cpp

class Solved_Sudoku
{
	public:
		static bool is_sudoku_solved(int sudoku_3d[9][9][10])
		{
			for (int row = 0; row < 9; row++)
			{
				for (int col = 0; col < 9; col++)
				{
					if (sudoku_3d[row][col][0] == -1)
					{
						return false;
					}
				}
			}
			return true;
		}
};

#endif