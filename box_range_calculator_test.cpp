#ifndef box_range_calculator_test_cpp
#define box_range_calculator_test_cpp

#include "constants.cpp"

class Box_Range_Calculator_Test
// Responsibility : 
// 1 .Calculate the start and end of the box.
{
public:
    static void calculate_box_start(int row, int col, int &box_start_row, int &box_start_col)
    // Intended Action : 
    // 1 . Calculate the box_start_row and box_start_col of the box based on the value 
    // of row and col.
    {
        box_start_row = (row / BOX_SIZE) * BOX_SIZE;
        box_start_col = (col / BOX_SIZE) * BOX_SIZE;
    }
    static void calculate_box_end(int row, int col, int &box_end_row, int &box_end_col)
    // Intended Action : 
    // 1 . Calculate the box_end_row and box_end_col of the box based on the value 
    // of row, col, box_start_row and box_start_col.
    {
        box_end_row = (row / BOX_SIZE) * BOX_SIZE + BOX_ROW_RANGE;
        box_end_col = (col / BOX_SIZE) * BOX_SIZE + BOX_COL_RANGE;
    }
};
#endif