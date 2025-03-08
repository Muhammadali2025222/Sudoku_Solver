#ifndef create_sudoku_3d_cpp
#define create_sudoku_3d_cpp

#include "validated_2d_sudoku.cpp"

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
					if (Sudoku_2d_Validator :: validate(sudoku_2d, row, col))
					{
						sudoku_3d[ row ][ col ][ 0 ] = sudoku_2d[ row ][ col ] ;

						for (int poss = min_poss; poss < max_poss; poss ++)
						{
							sudoku_3d[ row ][ col ][ poss ] = -1;
						}
					}
					else
					{
						sudoku_3d[ row ][ col ][ 0 ] = -1;
						for (int poss = min_poss; poss < max_poss; poss ++)
						{
							sudoku_3d[ row ][ col ][ poss ] = poss ;
						}
					}
				}
			}
		}
};

#endif