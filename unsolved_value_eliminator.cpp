#ifndef unsolved_value_eliminator_cpp
#define unsolved_value_eliminator_cpp

#include "multiple_possibility_row_elimination.cpp"
#include "multiple_possibility_column_elimination.cpp"

class Unsolved_Value_Eliminator
{
public:
    static bool perform_elimination(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS], int row, int col)
    {
        bool is_eliminated = false;
        if (Row_Possibility_Eliminator ::eliminate(sudoku_3d, row, col))
        {
            is_eliminated = true;
        }
        if (Column_Possibility_Eliminator ::eliminate(sudoku_3d, row, col))
        {
            is_eliminated = true;
        }
        return is_eliminated;
    }
};

#endif