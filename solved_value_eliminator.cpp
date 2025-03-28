#ifndef solved_value_eliminator_cpp
#define solved_value_eliminator_cpp

#include "solved_value_row_elimination.cpp"
#include "solved_value_column_elimination.cpp"
#include "solved_value_box_elimination.cpp"

class Solved_Value_Eliminator
{
public:
    static bool perform_elimination(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS], int row, int col)
    {
        bool is_eliminated = false;
        if (Row_Elimination ::eliminate(sudoku_3d, row, col))
        {
            is_eliminated = true;
        }
        if (Column_Elimination ::eliminate(sudoku_3d, row, col))
        {
            is_eliminated = true;
        }
        if (Box_Elimination ::eliminate(sudoku_3d, row, col))
        {
            is_eliminated = true;
        }
        return is_eliminated;
    }
};
#endif
