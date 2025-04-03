#ifndef elimination_handler_cpp
#define elimination_handler_cpp

#include "row_elimination.cpp"
#include "column_elimination.cpp"
#include "box_elimination.cpp"
#include "row_possibility_elimination.cpp"
#include "column_possibility_elimination.cpp"
#include "constants.cpp"

class Elimination_Handler
{
public:
    static bool eliminate_using_solved_cells(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS],
                                             int row, int col)
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
    static bool eliminate_using_unsolved_cells(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS],
                                               int row, int col)
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
