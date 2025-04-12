#ifndef row_possibility_elimination_test_cpp
#define row_possibility_elimination_test_cpp

#include "sudoku_validator_test.cpp"
#include "constants.cpp"
#include "cells_possibilities_comparison_test.cpp"
#include "box_range_calculator_test.cpp"
#include "box_possibility_checker_test.cpp"

#include <iostream>
using namespace std;

class Row_Possibility_Eliminator_Test
// Responsibility :
// 1 . Eliminate the compared possibilities from the row if they donot exist in
// any other cell of the box.
{
public:
    static bool eliminate(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS], int row, int col)
    // Intended Action :
    // 1 . Iterate over the whole 3x3 box.
    // 2 . Compare the possbilities of 1st cell in row with middle cell in row and
    // with last cell in row.
    // 3 . Check that those possibilities are not present in any other cell of box
    // except the ones we compared.
    // 4 . Eliminate the same possibilities from all the other cells present in the row
    // except the ones we compared and returns true.
    // 5 . Otherwise return false.
    {
        bool is_possibility_eliminated = false;

        int first_row = 0, first_col = 0, first_poss = 1;
        int second_row = 1, second_col = 1, second_poss = 2;
        int third_row = 2, third_col = 2, third_poss = 3;
        int forth_row = 3, forth_col = 3, forth_poss = 4;
        int fifth_row = 4, fifth_col = 4, fifth_poss = 5;
        int sixth_row = 5, sixth_col = 5, sixth_poss = 6;
        int seventh_row = 6, seventh_col = 6, seventh_poss = 7;
        int eighth_row = 7, eighth_col = 7, eighth_poss = 8;
        int ninth_row = 8, ninth_col = 8, ninth_poss = 9;

        int box_start_row = INVALID_ROW, box_start_col = INVALID_COL;

        cout << "going to perform calculate box start" << endl;

        Box_Range_Calculator_Test ::calculate_box_start(third_row, second_col, box_start_row, box_start_col);
        if (box_start_row != first_row || box_start_col != first_col)
        {
            cout << "value of box_start_row :" << "\t" << box_start_row << "\t";
            cout << "value of box_start_column :" << "\t" << box_start_col << endl;
            cout << "calculate_box_start is not calculating box_end_row and box_start_col correctly for third_row and second_col" << endl;
        }
        else
        {
            cout << "the function calculate_box_end is calulating box_end_row and box_start_col correctly for third_row and second_col" << endl;
        }

        box_start_row = INVALID_ROW, box_start_col = INVALID_COL;
        Box_Range_Calculator_Test ::calculate_box_start(second_row, fifth_col, box_start_row, box_start_col);
        if (box_start_row != first_row || box_start_col != forth_col)
        {
            cout << "value of box_start_row :" << "\t" << box_start_row << "\t";
            cout << "value of box_start_column :" << "\t" << box_start_col << endl;
            cout << "calculate_box_start is not calculating box_start_row and box_start_col correctly for second_row and fifth_col" << endl;
        }
        else
        {
            cout << "the function calculate_box_start is calulating box_start_row and box_start_col correctly for second_row and fifth_col" << endl;
        }

        box_start_row = INVALID_ROW, box_start_col = INVALID_COL;
        Box_Range_Calculator_Test ::calculate_box_start(sixth_row, third_col, box_start_row, box_start_col);
        if (box_start_row != forth_row || box_start_col != first_col)
        {
            cout << "value of box_start_row :" << "\t" << box_start_row << "\t";
            cout << "value of box_start_column :" << "\t" << box_start_col << endl;
            cout << "calculate_box_start is not calculating box_start_row and box_start_col correctly for sixth_row and third_col" << endl;
        }
        else
        {
            cout << "the function calculate_box_start is calulating box_start_row and box_start_col correctly for sixth_row and third_col" << endl;
        }

        box_start_row = INVALID_ROW, box_start_col = INVALID_COL;
        Box_Range_Calculator_Test ::calculate_box_start(ninth_row, eighth_col, box_start_row, box_start_col);
        if (box_start_row != seventh_row || box_start_col != seventh_col)
        {
            cout << "value of box_start_row :" << "\t" << box_start_row << "\t";
            cout << "value of box_start_column :" << "\t" << box_start_col << endl;
            cout << "calculate_box_start is not calculating box_start_row and box_start_col correctly for ninth_row and eighth_col" << endl;
        }
        else
        {
            cout << "the function calculate_box_start is calulating box_start_row and box_start_col correctly for ninth_row and eighth_col" << endl;
        }

        int box_end_row = INVALID_ROW, box_end_col = INVALID_COL;
        Box_Range_Calculator_Test ::calculate_box_end(row, col, box_end_row, box_end_col);

        for (int box_row = box_start_row; box_row <= box_end_row; box_row++)
        {
            for (int box_col = box_start_col; box_col <= box_end_col; box_col++)
            {
                for (int poss = MIN_POSS; poss < MAX_POSS; poss++)
                {
                    cout << "going to perform do possibilities exist" << endl;
                    if (Sudoku_Validator_Test ::do_possibilities_exist(sudoku_3d, second_row, third_col, first_poss))
                    {
                        cout << "possibility do exist on sudoku_3d[second_row][third_col][first_poss]" << endl;
                    }
                    else
                    {
                        cout << "value of row :" << "\t" << second_row << "\t";
                        cout << "value of column :" << "\t" << third_col << "\t";
                        cout << "value of poss :" << "\t" << first_poss << "\t";
                        cout << "possibility do not exist on sudoku_3d[second_row][third_col][first_poss]" << endl;
                    }
                    if (Sudoku_Validator_Test ::do_possibilities_exist(sudoku_3d, seventh_row, forth_col, ninth_poss))
                    {
                        cout << "possibility do exist on sudoku_3d[seventh_row][forth_col][ninth_poss]" << endl;
                    }
                    else
                    {
                        cout << "value of row :" << "\t" << seventh_row << "\t";
                        cout << "value of column :" << "\t" << forth_col << "\t";
                        cout << "value of poss :" << "\t" << ninth_poss << "\t";
                        cout << "possibility do not exist on sudoku_3d[seventh_row][forth_col][ninth_poss]" << endl;
                    }
                    if (Sudoku_Validator_Test ::do_possibilities_exist(sudoku_3d, forth_row, sixth_col, seventh_poss))
                    {
                        cout << "possibility do exist on sudoku_3d[forth_row][sixth_col][seventh_poss]" << endl;
                    }
                    else
                    {
                        cout << "value of row :" << "\t" << forth_row << "\t";
                        cout << "value of column :" << "\t" << sixth_col << "\t";
                        cout << "value of poss :" << "\t" << seventh_poss << "\t";
                        cout << "possibility do not exist on sudoku_3d[forth_row][sixth_col][seventh_poss]" << endl;
                    }
                    if (!Sudoku_Validator_Test ::do_possibilities_exist(sudoku_3d, ninth_row, forth_col, INVALID_POSS))
                    {
                        cout << "possibility do exist on sudoku_3d[ninth_row][forth_row][INVALID_POSS]" << endl;
                    }
                    else
                    {
                        cout << "value of row :" << "\t" << ninth_row << "\t";
                        cout << "value of column :" << "\t" << forth_col << "\t";
                        cout << "value of poss :" << "\t" << INVALID_POSS << "\t";
                        cout << "possibility do not exist on sudoku_3d[ninth_row][forth_row][INVALID_POSS]" << endl;
                    }
                    if (Sudoku_Validator_Test ::do_possibilities_exist(sudoku_3d, row, col, poss))
                    {
                        int box_next_row = box_row;
                        int box_next_col = box_col + BOX_MIDDLE_CELL;
                        if (Cells_Possibilities_Comparison_Test ::do_cells_poss_match(sudoku_3d, third_row, first_col,
                            third_row, second_col, eighth_poss))
                        {
                            cout << "the possibility on sudoku_3d[third_row][first_col][eighth_poss] is equal to the possibility on sudoku_3d[third_row][second_col][eighth_poss]" << endl;
                        }
                        else
                        {
                            cout << "value of box_row :" << "\t" << third_row << "\t";
                            cout << "value of box_column :" << "\t" << first_col << "\t";
                            cout << "value of box_next_column :" << "\t" << second_col << "\t";
                            cout << "value of poss :" << "\t" << eighth_poss << "\t";
                            cout << "the possibility on sudoku_3d[third_row][first_col][eighth_poss] is not equal to the possibility on sudoku_3d[third_row][second_col][eighth_poss]" << endl;
                        }
                        if (Cells_Possibilities_Comparison_Test ::do_cells_poss_match(sudoku_3d, fifth_row, sixth_col,
                            fifth_row, seventh_col, forth_poss))
                        {
                            cout << "the possibility on sudoku_3d[fifth_row][sixth_col][forth_poss] is equal to the possibility on sudoku_3d[fifth_row][seventh_col][forth_poss]" << endl;
                        }
                        else
                        {
                            cout << "value of row :" << "\t" << fifth_row << "\t";
                            cout << "value of column :" << "\t" << sixth_col << "\t";
                            cout << "value of box_column :" << "\t" << seventh_col << "\t";
                            cout << "value of poss :" << "\t" << forth_poss << "\t";
                            cout << "the possibility on sudoku_3d[fifth_row][sixth_col][forth_poss] is not equal to the possibility on sudoku_3d[fifth_row][seventh_col][forth_poss]" << endl;
                        }
                        if (Cells_Possibilities_Comparison_Test ::do_cells_poss_match(sudoku_3d, first_row, eighth_col,
                            first_row, ninth_col, fifth_poss))
                        {
                            cout << "the possibility on sudoku_3d[first_row][eighth_col][fifth_poss] is equal to the possibility on sudoku_3d[first_row][ninth_col][fifth_poss]" << endl;
                        }
                        else
                        {
                            cout << "value of row :" << "\t" << first_row << "\t";
                            cout << "value of column :" << "\t" << eighth_col << "\t";
                            cout << "value of box_column :" << "\t" << ninth_col << "\t";
                            cout << "value of poss :" << "\t" << fifth_poss << "\t";
                            cout << "the possibility on sudoku_3d[first_row][eighth_col][fifth_poss] is not equal to the possibility on sudoku_3d[first_row][ninth_col][fifth_poss]" << endl;
                        }
                        if (Cells_Possibilities_Comparison_Test ::do_cells_poss_match(sudoku_3d, seventh_row, forth_col,
                            seventh_row, fifth_col, ninth_poss))
                        {
                            cout << "the possibility on sudoku_3d[first_row][forth_col][ninth_poss] is equal to the possibility on sudoku_3d[seventh_row][fifth_col][fifth_poss]" << endl;
                        }
                        else
                        {
                            cout << "value of row :" << "\t" << seventh_row << "\t";
                            cout << "value of column :" << "\t" << forth_col << "\t";
                            cout << "value of box_column :" << "\t" << fifth_col << "\t";
                            cout << "value of poss :" << "\t" << ninth_poss << "\t";
                            cout << "the possibility on sudoku_3d[first_row][forth_col][ninth_poss] is not equal to the possibility on sudoku_3d[seventh_row][fifth_col][fifth_poss]" << endl;
                        }

                        if (box_next_col <= box_end_col &&
                            Cells_Possibilities_Comparison_Test ::do_cells_poss_match(sudoku_3d, box_row, box_col, box_next_row,
                            box_next_col, poss))
                        {
                            if (Box_Possibility_Checker_Test ::exist_only_in_compared_cells(sudoku_3d, first_row, first_col,
                                third_row, third_col, first_row, second_col, first_row, third_col, seventh_poss))
                            {
                                cout << "possibility only exist at sudoku_3d[first_row][second_col][seventh_poss] and sudoku_3d[first_row][third_col][seventh_poss]" << endl;
                            }
                            else
                            {
                                cout << "value of box_row :" << "\t" << first_row << "\t";
                                cout << "value of box_column :" << "\t" << second_col << "\t";
                                cout << "value of box_next_column :" << "\t" << third_col << "\t";
                                cout << "value of poss :" << "\t" << seventh_poss << "\t";
                                cout << "possibility do exist in other cells of box" << endl;
                            }
                            if (Box_Possibility_Checker_Test ::exist_only_in_compared_cells(sudoku_3d, sixth_row, first_col,
                                eighth_row, third_col, seventh_row, first_col, seventh_row, second_col, forth_poss))
                            {
                                cout << "possibility only exist at sudoku_3d[seventh_row][first_col][forth_poss] and sudoku_3d[seventh_row][second_col][forth_poss]" << endl;
                            }
                            else
                            {
                                cout << "value of box_row :" << "\t" << seventh_row << "\t";
                                cout << "value of box_column :" << "\t" << first_col << "\t";
                                cout << "value of box_next_column :" << "\t" << second_col << "\t";
                                cout << "value of poss :" << "\t" << forth_poss << "\t";
                                cout << "possibility do exist in other cells of box" << endl;
                            }
                            if (Box_Possibility_Checker_Test ::exist_only_in_compared_cells(sudoku_3d, forth_row, sixth_col,
                                sixth_row, eighth_col, fifth_row, sixth_col, fifth_row, seventh_col, sixth_poss))
                            {
                                cout << "possibility only exist at sudoku_3d[fifth_row][sixth_col][sixth_poss] and sudoku_3d[fifth_row][seventh_col][sixth_poss]" << endl;
                            }
                            else
                            {
                                cout << "value of box_row :" << "\t" << fifth_row << "\t";
                                cout << "value of box_column :" << "\t" << sixth_col << "\t";
                                cout << "value of box_next_column :" << "\t" << seventh_col << "\t";
                                cout << "value of poss :" << "\t" << sixth_poss << "\t";
                                cout << "possibility do exist in other cells of box" << endl;
                            }
                            if (Box_Possibility_Checker_Test ::exist_only_in_compared_cells(sudoku_3d, first_row, forth_col,
                                third_row, fifth_col, third_row, forth_col, third_row, fifth_col, second_poss))
                            {
                                cout << "possibility only exist at sudoku_3d[third_row][forth_col][second_poss] and sudoku_3d[third_row][fifth_col][seventh_poss]" << endl;
                            }
                            else
                            {
                                cout << "value of box_row :" << "\t" << third_row << "\t";
                                cout << "value of box_column :" << "\t" << forth_col << "\t";
                                cout << "value of box_next_column :" << "\t" << fifth_col << "\t";
                                cout << "value of poss :" << "\t" << second_poss << "\t";
                                cout << "possibility do exist in other cells of box" << endl;
                            }
                            if (Box_Possibility_Checker_Test ::exist_only_in_compared_cells(sudoku_3d, box_start_row,
                                box_start_col, box_end_row, box_end_col, box_row, box_col, box_next_row, box_next_col, poss))
                            {
                                for (int remove_col = MIN_COL; remove_col < MAX_COL; remove_col++)
                                {
                                    if (remove_col != box_col && remove_col != box_next_col)
                                    {
                                        sudoku_3d[row][remove_col][poss] = BLANK_CELL;
                                        is_possibility_eliminated = true;
                                    }
                                }
                            }
                        }

                        box_next_col = box_col + BOX_COL_RANGE;
                        if (box_next_col == box_end_col &&
                            Cells_Possibilities_Comparison_Test ::do_cells_poss_match(sudoku_3d, row, col, box_next_row,
                            box_next_col, poss))
                        {
                            if (Box_Possibility_Checker_Test ::exist_only_in_compared_cells(sudoku_3d, box_start_row, box_start_col,
                                box_end_row, box_end_col, box_row, box_col, box_next_row, box_next_col, poss))
                            {
                                for (int remove_col = MIN_COL; remove_col < MAX_COL; remove_col++)
                                {
                                    if (remove_col != box_col && remove_col != box_next_col)
                                    {
                                        sudoku_3d[row][remove_col][poss] = BLANK_CELL;
                                        is_possibility_eliminated = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return is_possibility_eliminated;
    }
};

#endif