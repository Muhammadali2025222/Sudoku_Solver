#include <iostream>
using namespace std;

bool compare_Row0_Row1_dimensions(int sudoku_3d[9][9][10]) 
{
    for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			for (int poss = 1; poss < 10; poss++) 
			{
				if (sudoku_3d[row][col][poss] != sudoku_3d[row + 1][col][poss]) 
				{
					return false;
				}
			}
		}
    }
	cout<<"equal";
	return true;
}

bool compare_Row0_Row2_dimensions(int sudoku_3d[9][9][10]) 
{
    for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			for (int poss = 1; poss < 10; poss++) 
			{
				if (sudoku_3d[row][col][poss] != sudoku_3d[row + 2][col][poss]) 
				{
					return false;
				}
			}
		}
    }
	cout<<"equal";
	return true;
}

bool compare_Col0_Col1_dimensions(int sudoku_3d[9][9][10]) 
{
    for (int col = 0; col < 9; col++)
	{
		for (int row = 0; row < 9; row++)
		{
			for (int poss = 1; poss < 10; poss++) 
			{
				if (sudoku_3d[ row ][ col ][ poss ] != sudoku_3d[ row ][ col + 1 ][ poss ]) 
				{
					return false;
				}
			}
		}
    }
	cout<<"equal";
	return true;
}

bool compare_Col0_Col2_dimensions(int sudoku_3d[9][9][10]) 
{
    for (int col = 0; col < 9; col++)
	{
		for (int row = 0; row < 9; row++)
		{
			for (int poss = 1; poss < 10; poss++) 
			{
				if (sudoku_3d[ row ][ col ][ poss ] != sudoku_3d[ row ][ col + 2 ][ poss ]) 
				{
					return false;
				}
			}
		}
    }
	cout<<"equal";
	return true;
}

void updated_sudoku_2d(int sudoku_2d[9][9])
{
	cout << "Sudoku 2d : \n ";
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			cout << sudoku_2d[ row ][ col ] << "\t";
		}
		cout << "\n" ;
	}
	cout << "\n" ;
}

bool is_sudoku_solved(int sudoku_3d[9][9][10])
{
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			if (sudoku_3d[row][col][0] == -1)
			{
				
				return false;
			}
		}
	}
	return true;
}

void sudoku_3d_updater(int sudoku_2d[9][9], int sudoku_3d[9][9][10])
{
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			if (sudoku_2d[row][col] > -1)
			{
				sudoku_3d[row][col][0] = sudoku_2d[row][col];
				for (int poss = 1; poss <= 9; poss++)
				{
					sudoku_3d[row][col][poss] = -1;
				}
			}
		}
	}
}

void column_possibility_elimination(int sudoku_2d[9][9], int sudoku_3d[9][9][10])
{
    for (int col = 0; col < 9; col++)
    {
        for (int row = 0; row < 9; row++)
        {
            for (int poss = 1; poss <= 9; poss++)
            {
				if ( row > 0 || row > 3 || row > 6 && sudoku_3d[row][col][poss] > -1 )
				{
					if ( compare_Row0_Row1_dimensions( sudoku_3d ) &&
						 compare_Row0_Row2_dimensions( sudoku_3d ) )
				   {
					   for (int remove_row = 0; remove_row < 9; remove_row++)
					   {
						   if ( remove_row != row && remove_row != row + 1 && remove_row != row + 2)
						   {
							   sudoku_3d[remove_row][col][poss] = -1;
						   }
					   }
				   }
				   else if ( compare_Row0_Row2_dimensions( sudoku_3d ) )
				   {
					   for (int remove_row = 0; remove_row < 9; remove_row++)
					   {
						   if (remove_row != row && remove_row != row + 1)
						   {
							   sudoku_3d[remove_row][col][poss] = -1;
						   }
					   }
				   }
				   else if ( compare_Row0_Row2_dimensions( sudoku_3d ) )
				   {
					   for (int remove_row = 0; remove_row < 9; remove_row++)
					   {
						   if (remove_row != row && remove_row != row + 2)
						   {
							   sudoku_3d[remove_row][col][poss] = -1;
						   }
					   }
				   }
				}
            }
        }
    }
}


void single_possibility_in_cell(int sudoku_2d[9][9], int sudoku_3d[9][9][10])
{
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
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
	}
}


void box_elimination(int sudoku_2d[9][9], int sudoku_3d[9][9][10])
{
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			int fixed_value = sudoku_2d[row][col];
			if (fixed_value > -1)
			{
				int box_start_row = (row/3)*3;
				int box_start_col = (col/3)*3;

				for (int box_row = box_start_row; box_row < box_start_row + 3; box_row++)
				{
					for (int box_col = box_start_col; box_col < box_start_col + 3; box_col++)
					{
						for (int poss = 1; poss <= 9; poss++)
						{
							if (sudoku_3d[box_row][box_col][poss] == fixed_value)
							{
								sudoku_3d[box_row][box_col][poss] = -1;
							}
						}
					}
				}
			}
		}
	}
	//single_possibility_in_cell(sudoku_2d, sudoku_3d);
}

void col_elimination(int sudoku_2d[9][9], int sudoku_3d[9][9][10])
{
	for (int col = 0; col < 9; col++)
	{
		for (int row = 0; row < 9; row++)
		{
			int fixed_value = sudoku_2d[row][col];
			if (fixed_value > -1)
			{
				for (int row_3d = 0; row_3d < 9; row_3d++)
				{
					for (int poss = 1; poss <= 9; poss++)
					{
						if (sudoku_3d[row_3d][col][poss] == fixed_value)
						{
							sudoku_3d[row_3d][col][poss] = -1;
						}
					}
				}
			}
		}
	}
	//box_elimination(sudoku_2d, sudoku_3d);
}

void row_elimination(int sudoku_2d[9][9], int sudoku_3d[9][9][10])
{
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			int fixed_value = sudoku_2d[row][col];
			if (fixed_value > -1)
			{
				for (int col_3d = 0; col_3d < 9; col_3d++)
				{
					for (int poss = 1; poss <= 9; poss++)
					{
						if (sudoku_3d[row][col_3d][poss] == fixed_value)
						{
							sudoku_3d[row][col_3d][poss] = -1;
						}
					}
				}
			}
		}

	}
	//col_elimination(sudoku_2d, sudoku_3d);
}

void row_possibility_elimination(int sudoku_2d[9][9], int sudoku_3d[9][9][10])
{
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			for (int poss = 1; poss <= 9; poss++)
            {
				if ( col > 0 || col > 3 || col > 6 && sudoku_3d[ row ][ col ][ poss ] > -1 )
				{
					if ( compare_Col0_Col1_dimensions( sudoku_3d ) &&
						 compare_Col0_Col2_dimensions( sudoku_3d ) )
				   {
					   for (int remove_col = 0; remove_col < 9; remove_col++)
					   {
						   if ( remove_col != col && remove_col != col + 1 && remove_col != col + 2)
						   {
							   sudoku_3d[ row ][ remove_col ][ poss ] = -1;
						   }
					   }
				   }
				   else if ( compare_Col0_Col2_dimensions( sudoku_3d ) )
				   {
					   for (int remove_col = 0; remove_col < 9; remove_col++)
					   {
						   if (remove_col != col && remove_col != col + 1)
						   {
							   sudoku_3d[ row ][ remove_col ][ poss ] = -1;
						   }
					   }
				   }
				   else if ( compare_Col0_Col2_dimensions( sudoku_3d ) )
				   {
					   for (int remove_col = 0; remove_col < 9; remove_col++)
					   {
						   if (remove_col != col && remove_col != col + 2)
						   {
							   sudoku_3d[ row ][ remove_col ][ poss ] = -1;
						   }
					   }
				   }
				}
            }
		}
	}

	//column_possibility_elimination(sudoku_2d, sudoku_3d);
}
void single_possibility_in_box(int sudoku_2d[9][9], int sudoku_3d[9][9][10])
{
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			int box_start_row = (row/3)*3;
			int box_start_col = (col/3)*3;

			for (int poss = 1; poss <= 9; poss++)
			{
				int count = 0;
				int last_row = 0, last_col = 0;
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
					sudoku_2d[last_row][last_col] = poss;
				}
			}
		}
	}
	sudoku_3d_updater(sudoku_2d, sudoku_3d);
	row_elimination(sudoku_2d, sudoku_3d);
}

void cell_selection(int sudoku_2d[9][9], int sudoku_3d[9][9][10])
{
	int row_reset_count = 0;
	for (int row = 0; row <= 9; row++)
	{
		
		for (int col = 0; col < 9; col++)
		{
			if (sudoku_2d[row][col] < 1)
			{
				cout << "Cell [" << row << "][" << col << "] has no fixed value (Multiple possibilities)\n";
				row_elimination(sudoku_2d, sudoku_3d);
				col_elimination(sudoku_2d, sudoku_3d);
				box_elimination(sudoku_2d, sudoku_3d);
				single_possibility_in_cell(sudoku_2d, sudoku_3d);
				single_possibility_in_box(sudoku_2d, sudoku_3d);
				row_elimination(sudoku_2d, sudoku_3d);
				col_elimination(sudoku_2d, sudoku_3d);
				box_elimination(sudoku_2d, sudoku_3d);
				single_possibility_in_cell(sudoku_2d, sudoku_3d);
				sudoku_3d_updater(sudoku_2d, sudoku_3d);
				row_possibility_elimination(sudoku_2d, sudoku_3d);
				column_possibility_elimination(sudoku_2d, sudoku_3d);
			}
			else
			{
				cout << "Cell [" << row << "][" << col << "] has fixed value: " << sudoku_2d[row][col] << "\n";
			}
			cout << "2d sudoku: " << sudoku_2d[row][col] << "\n";
			cout << "3d sudoku: ";
			for (int poss = 0; poss < 10; poss++)
			{
				cout << sudoku_3d[row][col][poss] << "\t";
			}
			cout << "\n";
		}

		if (is_sudoku_solved(sudoku_3d))
		{
			cout << "Sudoku is solved!";
			return;
			break;
		}
		
		else if (row == 8)
		{
			row_reset_count++;
			if ( row_reset_count == 3)
			{
				break;
			}
			row = 0; 
		}
	}
}


int main()
{
	int sudoku_2d[9][9] = {
		{ 3, -1,  2, -1, -1, -1, -1, -1, -1},
		{-1, -1, -1, -1,  5,  8, -1, -1,  1},
		{ 1, -1, -1, -1,  4, -1,  5, -1,  9},
		{-1,  9, -1, -1, -1, -1, -1, -1,  8},
		{-1, -1,  7, -1, -1, -1,  1, -1, -1},
		{-1, -1, -1, -1,  6, -1, -1,  2, -1},
		{-1, -1, -1,  6, -1,  2, -1,  4, -1},
		{ 9, -1, -1,  3, -1, -1, -1, -1, -1},
		{-1,  4, -1, -1,  1, -1, -1, -1, -1}
	};

	int sudoku_3d[9][9][10] = {
		{
			{  3, -1, -1, -1, -1, -1, -1, -1, -1, -1},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8, -1},
			{  2, -1, -1, -1, -1, -1, -1, -1, -1, -1},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
		},
		{
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8, -1},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8, -1},
			{ -1, -1, -1, -1,  4, -1,  6, -1, -1,  9},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{  5, -1, -1, -1, -1, -1, -1, -1, -1, -1},
			{  8, -1, -1, -1, -1, -1, -1, -1, -1, -1},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{  1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		},
		{
			{  1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8, -1},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8, -1},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{  4, -1, -1, -1, -1, -1, -1, -1, -1, -1},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{  5, -1, -1, -1, -1, -1, -1, -1, -1, -1},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{  9, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		},
		{
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{  9, -1, -1, -1, -1, -1, -1, -1, -1, -1},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{  8, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		},
		{
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{  7, -1, -1, -1, -1, -1, -1, -1, -1, -1},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{  1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
		},
		{
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{  6, -1, -1, -1, -1, -1, -1, -1, -1, -1},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{  2, -1, -1, -1, -1, -1, -1, -1, -1, -1},
			{  1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		},
		{
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{  6, -1, -1, -1, -1, -1, -1, -1, -1, -1},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{  2, -1, -1, -1, -1, -1, -1, -1, -1, -1},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{  4, -1, -1, -1, -1, -1, -1, -1, -1, -1},
			{  1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		},
		{
			{  9, -1, -1, -1, -1, -1, -1, -1, -1, -1},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{  3, -1, -1, -1, -1, -1, -1, -1, -1, -1},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
		},
		{
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{  4, -1, -1, -1, -1, -1, -1, -1, -1, -1},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{  1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
			{ -1,  1,  2,  3,  4,  5,  6,  7,  8,  9},
		},
	};
	
	//compare_Col0_Col1_dimensions(sudoku_3d);
	//compare_Col0_Col2_dimensions(sudoku_3d);
	//compare_Row0_Row1_dimensions(sudoku_3d);
	//compare_Row0_Row2_dimensions(sudoku_3d);
	cell_selection(sudoku_2d, sudoku_3d);
	// row_possibility_elimination(sudoku_2d, sudoku_3d);

}