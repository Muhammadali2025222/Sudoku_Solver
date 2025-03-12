#ifndef single_possibility_in_box_elimination_cpp
#define single_possibility_in_box_elimination_cpp

#include "box_start_determiner.cpp"

#include "possibility_limiter.cpp"

class Box_Possibility_Eliminator
{
	public:
		static void eliminate(int sudoku_3d[9][9][10], int row, int col)
		{
			int box_start_row;
            int box_start_col;

			for (int poss = MIN_POSS; poss < MAX_POSS; poss++) 
			{
				int count = 0;
				int last_row = 0, last_col = 0;

				Box_Start_Determiner :: determine(row, col, box_start_row, box_start_col);
				
				for (int box_row = box_start_row; box_row < box_start_row + 3; box_row++)
				{
					for (int box_col = box_start_col; box_col < box_start_col + 3; box_col++)
					{
						if (sudoku_3d[box_row][box_col][poss] == poss)
						{
							count++;
							last_row = box_row;
							last_col = box_col;
						}
					}
				}
				if (count == 1)
				{
					sudoku_3d[last_row][last_col][0] = poss;
				}
			}
		}
};

#endif