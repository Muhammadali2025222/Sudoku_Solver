#ifndef box_determiner_cpp
#define box_determiner_cpp

class Box_Determiner
{
public:
    static void determine(int row, int col, int &box_start_row, int &box_start_col, int &box_end_row, int &box_end_col)
    {
        box_start_row = (row / 3) * 3;
        box_start_col = (col / 3) * 3;
        box_end_row = box_start_row + 2;
        box_end_col = box_start_col + 2;
    }
};
#endif