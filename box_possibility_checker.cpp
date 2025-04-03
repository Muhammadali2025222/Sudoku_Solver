#ifndef box_possibility_checker_cpp
#define box_possibility_checker_cpp

#include "constants.cpp"

class Box_Possibility_Checker
{
private:
    static const int START_COUNT = 0;

public:
    static bool exist_only_in_compared_cells(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS],
                                             int box_start_row, int box_start_col,
                                             int box_end_row, int box_end_col, int box_row,
                                             int box_col, int box_next_row, int box_next_col,
                                             int poss)
    {
        int count = START_COUNT;
        for (int check_row = box_start_row; check_row <= box_end_row; check_row++)
        {
            for (int check_col = box_start_col; check_col <= box_end_col; check_col++)
            {
                if ((check_row == box_row && check_col == box_col) ||
                    (check_row == box_next_row && check_col == box_next_col))
                {
                    continue;
                }
                else if (sudoku_3d[check_row][check_col][poss] == poss)
                {
                    count++;
                }
            }
            if (count > START_COUNT)
            {
                count = START_COUNT;
                break;
            }
        }
        return (count == START_COUNT);
    }
};
#endif
