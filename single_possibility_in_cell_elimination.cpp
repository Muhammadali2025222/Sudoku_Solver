#ifndef single_possibility_in_cell_elimination_cpp
#define single_possibility_in_cell_elimination_cpp

class Single_Possibility_In_Cell_Elimination
{
	public:
		static void single_possibility_in_cell_eliminator(int sudoku_2d[9][9], int sudoku_3d[9][9][10], int row, int col)
		{
			int count = 0;
			int last_possibility = 0;
			for (int poss = 1; poss <= 9; poss++)
			{
				if (sudoku_3d[row][col][poss] > -1)
				{
					count++;
					last_possibility = sudoku_3d[row][col][poss];
				}
			}
			if (count == 1)
			{
				sudoku_2d[row][col] = last_possibility;
			}
		}
};

#endif