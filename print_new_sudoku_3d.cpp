#ifndef print_new_sudoku_3d_cpp
#define print_new_sudoku_3d_cpp

#include <iostream>
using namespace std;

class Print_New_Sudoku_3d
{
    public:
        static void print_new_sudoku_3d(int new_sudoku_3d[9][9][10] , int row, int col)
        {   
            for (int poss = 0; poss < 10; poss++)
            {
                cout << new_sudoku_3d[ row ][ col ][ poss ] << "\t" ;
            }
            cout << "\n" ;
        }
};

#endif