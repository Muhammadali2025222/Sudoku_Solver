#ifndef single_possibility_in_box_elimination_cpp
#define single_possibility_in_box_elimination_cpp

#include "box_start_determiner.cpp"

#include "constants.cpp"

class Box_Possibility_Eliminator
{
	public:
		static bool eliminate(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS], int row, int col)
		{
			int box_start_row;
            int box_start_col;

			int last_possibilities;
			int count = START_COUNT;
			int curr_row; 
			int curr_col;

			for (int poss = MIN_POSS; poss < MAX_POSS; poss++) 
			{
				Box_Start_Determiner :: determine(row, col, box_start_row, box_start_col);
				
				for (int box_row = box_start_row; box_row < box_start_row + 3; box_row++)
				{
					for (int box_col = box_start_col; box_col < box_start_col + 3; box_col++)
					{
						if (sudoku_3d[box_row][box_col][poss] == poss)
						{
							count++;
							curr_row = box_row;
							curr_col = box_col;
							last_possibilities = poss;
						}
					}
				}	
			}
			if (count == 1)
			{
				sudoku_3d[curr_row][curr_col][SOLVED_INDEX] = last_possibilities;
				return true;
			}
			return false;
		}
};

#endif