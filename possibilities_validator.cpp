#ifndef possibilities_validator_cpp
#define possibilities_validator_cpp

#include "possibility_limiter.cpp"

class Possibilities_Validator
{
	public:
		static bool validate(int sudoku_3d[9][9][10], int row, int col)
		{
            for (int poss = MIN_POSS; poss < MAX_POSS; poss++) 
            {
                if (sudoku_3d[row][col][poss] > 0 && sudoku_3d[row][col][poss] < 10)
			    {
				    return true;
			    }
            }
			return false;
		}
};

#endif