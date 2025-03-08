#ifndef solved_value_box_elimination_cpp
#define solved_value_box_elimination_cpp

#include "box_start_determiner.cpp"

#include "possibility_limiter.cpp"

class Box_Elimination
{
	public:
		static void eliminate(int sudoku_2d[9][9], int sudoku_3d[9][9][10], int row, int col)
		{	
			int solved_value = sudoku_2d[row][col];

            int box_start_row = 0;
            int box_start_col = 0;

			Box_Start_Determiner :: determine(row, col, box_start_row, box_start_col);

			for (int box_row = box_start_row; box_row < box_start_row + 3; box_row++)
			{
				for (int box_col = box_start_col; box_col < box_start_col + 3; box_col++)
				{
					for (int poss = min_poss; poss < max_poss; poss++)
					{
						if (sudoku_3d[box_row][box_col][poss] == solved_value)
						{
							sudoku_3d[box_row][box_col][poss] = -1;
						}
					}
				}
			}
		}
};

#endif