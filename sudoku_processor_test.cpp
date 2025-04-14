#ifndef sudoku_processor_test_cpp
#define sudoku_processor_test_cpp

#include "elimination_handler_test.cpp"
#include "box_range_calculator_test.cpp"
#include "constants.cpp"

#include <iostream>

using namespace std;

class Sudoku_Processor_Test
{
public:
	static void process(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS])
	{
		for (int row = MIN_ROW; row < MAX_ROW; row++)
		{
			bool has_made_progress = false;

			for (int col = MIN_COL; col < MAX_COL; col++)
			{
				int first_row = 0, first_col = 0; 
				int second_row = 1, second_col = 1;
				int third_row = 2, third_col = 2;
				int forth_row = 3, forth_col = 3;
				int fifth_row = 4, fifth_col = 4;
				int sixth_row = 5, sixth_col = 5;
				int seventh_row = 6, seventh_col = 6;
				int eighth_row = 7, eighth_col = 7;
				int ninth_row = 8, ninth_col = 8;

				int box_end_row = INVALID_ROW, box_end_col = INVALID_COL;
				Box_Range_Calculator_Test :: calculate_box_end(first_row, second_col, box_end_row, box_end_col);
				if (box_end_row != third_row || box_end_col != third_col)
				{
					cout << "value of box_end_row :"<< "\t" << box_end_row << "\t";
					cout << "value of box_end_column :" << "\t"<< box_end_col << endl;
					cout << "calculate_box_end is not calculating box_end_row and box_end_col correctly for first_row and second_col"<< endl;
				}
				else
				{
					cout << "the function calculate_box_end is calulating box_end_row and box_end_col correctly for first_row and second_col"<< endl;
				}

				box_end_row = INVALID_ROW, box_end_col = INVALID_COL;
				Box_Range_Calculator_Test :: calculate_box_end(third_row, second_col, box_end_row, box_end_col);
				if (box_end_row != third_row || box_end_col != third_col)
				{
					cout << "value of box_end_row :"<< "\t" << box_end_row << "\t";
					cout << "value of box_end_column :" << "\t"<< box_end_col << endl;
					cout<< "calculate_box_end is not calculating box_end_row and box_end_col correctly for third_row and second_col" << endl;
				}
				else
				{
					cout << "the function calculate_box_end is calulating box_end_row and box_end_col correctly for third_row and second_col" << endl;
				}

				box_end_row = INVALID_ROW, box_end_col = INVALID_COL;
				Box_Range_Calculator_Test :: calculate_box_end(forth_row, fifth_col, box_end_row, box_end_col);
				if (box_end_row != sixth_row || box_end_col != sixth_col)
				{
					cout << "value of box_end_row :"<< "\t" << box_end_row << "\t";
					cout << "value of box_end_column :" << "\t"<< box_end_col << endl;
					cout<< "calculate_box_end is not calculating box_end_row and box_end_col correctly for forth_row and fifth_col" << endl;
				}
				else
				{
					cout << "the function calculate_box_end is calulating box_end_row and box_end_col correctly for forth_row and fifth_col" << endl;
				}

				box_end_row = INVALID_ROW, box_end_col = INVALID_COL;
				Box_Range_Calculator_Test :: calculate_box_end(second_row, eighth_col, box_end_row, box_end_col);
				if (box_end_row != third_row || box_end_col != ninth_col)
				{
					cout << "value of box_end_row :"<< "\t" << box_end_row << "\t";
					cout << "value of box_end_column :" << "\t"<< box_end_col << endl;
					cout<< "calculate_box_end is not calculating box_end_row and box_end_col correctly for second_row and eighth_col" << endl;
				}
				else
				{
					cout << "the function calculate_box_end is calulating box_end_row and box_end_col correctly for second_row and eighth_col" << endl;
				}

				box_end_row = INVALID_ROW, box_end_col = INVALID_COL;
				Box_Range_Calculator_Test :: calculate_box_end(row, col, box_end_row, box_end_col);
				if (first_row == box_end_row && third_col == box_end_col)
				{
					if (Elimination_Handler_Test :: eliminate_using_unsolved_cells(sudoku_3d, first_row, third_col))
					{
						has_made_progress = true;
					}
				}
				if (fifth_row == box_end_row && forth_col == box_end_col)
				{
					if (Elimination_Handler_Test :: eliminate_using_unsolved_cells(sudoku_3d, fifth_row, forth_col))
					{
						has_made_progress = true;
					}
				}
				if (seventh_row == box_end_row && eighth_col == box_end_col)
				{
					if (Elimination_Handler_Test :: eliminate_using_unsolved_cells(sudoku_3d, seventh_row, eighth_col))
					{
						has_made_progress = true;
					}
				}
				if (sixth_row == box_end_row && ninth_col == box_end_col)
				{
					if (Elimination_Handler_Test :: eliminate_using_unsolved_cells(sudoku_3d, sixth_row, ninth_col))
					{
						has_made_progress = true;
					}
				}
			}
			if (has_made_progress && row == ROW_RESET_LIMIT)
			{
				row = INVALID_ROW;
			}
		}
	}
};

#endif