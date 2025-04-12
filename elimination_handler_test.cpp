#ifndef elimination_handler_test_cpp
#define elimination_handler_test_cpp

#include "constants.cpp"

#include "row_possibility_elimination_test.cpp"
#include "column_possibility_elimination.cpp"

class Elimination_Handler_Test
{
public:
    static bool eliminate_using_unsolved_cells(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS],
                                               int row, int col)
    {
        bool is_eliminated = false;
        if (Row_Possibility_Eliminator_Test :: eliminate(sudoku_3d, row, col))
        {
            is_eliminated = true;
        }
        if (Column_Possibility_Eliminator :: eliminate(sudoku_3d, row, col))
        {
            is_eliminated = true;
        }
        return is_eliminated;
    }
};
#endif
