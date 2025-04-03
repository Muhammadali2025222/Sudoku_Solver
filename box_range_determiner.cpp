#ifndef box_range_determiner_cpp
#define box_range_determiner_cpp

#include "constants.cpp"

class Box_Range_Determiner
{
public:
    static void determine_Box_Range(int row, int col, int &box_start_row, int &box_start_col,
                                    int &box_end_row, int &box_end_col)
    {
        box_start_row = (row / BOX_SIZE) * BOX_SIZE;
        box_start_col = (col / BOX_SIZE) * BOX_SIZE;
        box_end_row = box_start_row + BOX_ROW_RANGE;
        box_end_col = box_start_col + BOX_COL_RANGE;
    }
};
#endif