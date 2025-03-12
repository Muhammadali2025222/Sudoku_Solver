#ifndef box_start_determiner_cpp
#define box_start_determiner_cpp

class Box_Start_Determiner
{
    public:
        static void determine(int row, int col, int &box_start_row, int &box_start_col)
        {
            box_start_row = (row/3)*3;

			box_start_col = (col/3)*3;
        }
};
#endif