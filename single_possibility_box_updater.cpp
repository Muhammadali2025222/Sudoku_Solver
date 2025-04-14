#ifndef SINGLE_POSSIBILITY_BOX_UPDATER_CPP
#define SINGLE_POSSIBILITY_BOX_UPDATER_CPP

#include "box_range_calculator.cpp"
#include "sudoku_validator.cpp"
#include "cell_possibilities_updater.cpp"
#include "constants.cpp"

class Single_Possibility_Box_Updater
{
private:
    static const int START_COUNT = 0;
    static const int EXPECTED_COUNT = 1;

public:
    static bool update_possibility(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS], int row, int col)
    {
        int box_start_row = INVALID_ROW, box_start_col = INVALID_COL;
        int box_end_row = INVALID_ROW, box_end_col = INVALID_COL;
        bool is_updated = false;

        Box_Range_Calculator :: calculate_box_start(row, col, box_start_row, box_start_col);
		Box_Range_Calculator :: calculate_box_end(row, col, box_end_row, box_end_col);


        for (int poss = MIN_POSS; poss < MAX_POSS; poss++)
        {
            int count = START_COUNT;
            int curr_row = INVALID_ROW, curr_col = INVALID_COL;

            for (int box_row = box_start_row; box_row <= box_end_row; box_row++)
            {
                for (int box_col = box_start_col; box_col <= box_end_col; box_col++)
                {
                    if (Sudoku_Validator :: do_possibilities_exist(sudoku_3d, row, col, poss))
                    {
                        count++;
                        curr_row = box_row;
                        curr_col = box_col;
                    }
                    if (count > EXPECTED_COUNT)
                    {
                        break;
                    }
                }
                if (count > EXPECTED_COUNT)
                {
                    break;
                }
            }
            if (count == EXPECTED_COUNT)
            {
                sudoku_3d[curr_row][curr_col][SOLVED_CELL] = poss;
                is_updated = true;
                Cell_Possibilities_Updater :: update_possibility(sudoku_3d, curr_row, curr_col);
            }
        }
        return is_updated;
    }
};

#endif
