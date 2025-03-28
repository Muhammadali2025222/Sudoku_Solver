#ifndef single_possibility_in_box_elimination_cpp
#define single_possibility_in_box_elimination_cpp

#include "box_start_determiner.cpp"

#include "sudoku_possibilities_updater.cpp"

#include "constants.cpp"

class Single_Possibility_Box_Updater
{
public:
	static bool update(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS], int row, int col)
	{
		int box_start_row, box_start_col, box_end_row, box_end_col, last_possibilities, curr_row, curr_col;
		int count = START_COUNT;
		bool is_updated = false;

		for (int poss = MIN_POSS; poss < MAX_POSS; poss++)
		{
			Box_Determiner ::determine(row, col, box_start_row, box_start_col, box_end_row, box_end_col);

			for (int box_row = box_start_row; box_row <= box_end_row; box_row++)
			{
				for (int box_col = box_start_col; box_col <= box_end_col; box_col++)
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
			if (count == EXPECTED_COUNT)
			{
				sudoku_3d[curr_row][curr_col][SOLVED_INDEX] = last_possibilities;
				is_updated = true;
				Sudoku_Possibilities_Updater :: update(sudoku_3d, row, col);
			}
		}
		return is_updated;
	}
};

#endif