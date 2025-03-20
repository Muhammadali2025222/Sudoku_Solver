#ifndef create_sudoku_3d_cpp
#define create_sudoku_3d_cpp

#include "sudoku_validator.cpp"

#include "constants.cpp"

class Sudoku_3d_Creator
{
	public:
		static void create(int sudoku_2d[MAX_ROW][MAX_COL], int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS])
		{
			
			for (int row = MIN_ROW; row < MAX_ROW; row++)
			{
				for (int col = MIN_COL; col < MAX_COL; col++)
				{
					if (Sudoku_Validator :: validate_2d_sudoku(sudoku_2d, row, col))
					{
						sudoku_3d[row][col][SOLVED_INDEX] = sudoku_2d[row][col] ;

						for (int poss = MIN_POSS; poss < MAX_POSS; poss ++)
						{
							sudoku_3d[row][col][poss] = BLANK_INDEX;
						}
					}
					else
					{
						sudoku_3d[row][col][SOLVED_INDEX] = BLANK_INDEX;
						for (int poss = MIN_POSS; poss < MAX_POSS; poss ++)
						{
							sudoku_3d[row][col][poss] = poss ;
						}
					}
				}
			}
		}
};

#endif