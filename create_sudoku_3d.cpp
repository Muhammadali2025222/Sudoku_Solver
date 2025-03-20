#ifndef create_sudoku_3d_cpp
#define create_sudoku_3d_cpp

#include "sudoku_validator.cpp"

#include "possibility_limiter.cpp"

class Sudoku_3d_Creator
{
	public:
		static void create(int sudoku_2d[9][9], int sudoku_3d[9][9][10])
		{
			
			for (int row = 0; row < 9; row++)
			{
				for (int col = 0; col < 9; col++)
				{
					if (Sudoku_Validator :: validate_2d_sudoku(sudoku_2d, row, col))
					{
						sudoku_3d[ row ][ col ][ 0 ] = sudoku_2d[ row ][ col ] ;

						for (int poss = MIN_POSS; poss < MAX_POSS; poss ++)
						{
							sudoku_3d[ row ][ col ][ poss ] = -1;
						}
					}
					else
					{
						sudoku_3d[ row ][ col ][ 0 ] = -1;
						for (int poss = MIN_POSS; poss < MAX_POSS; poss ++)
						{
							sudoku_3d[ row ][ col ][ poss ] = poss ;
						}
					}
				}
			}
		}
};

#endif