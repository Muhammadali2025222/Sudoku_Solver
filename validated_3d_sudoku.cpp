#ifndef validated_3d_sudoku_cpp
#define validated_3d_sudoku_cpp

#include "possibility_limiter.cpp"

class Sudoku_3d_Validator
{
	public:
		static bool validate(int sudoku_3d[9][9][10], int row, int col)
		{
            for (int poss = min_poss; poss < max_poss; poss++)
            {
                if (sudoku_3d[row][col][poss] > 0 && sudoku_3d[row][col][poss] < 10)
			    {
				    return true;
			    }
                return false;
            }
		}
};

#endif