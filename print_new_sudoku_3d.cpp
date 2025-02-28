#ifndef print_sudoku_3d_cpp
#define print_sudoku_3d_cpp

#include <iostream>
using namespace std;

class Print_Sudoku_3d
{
    public:
        static void sudoku_3d(int sudoku_3d[9][9][10] , int row, int col)
        {   
            for (int poss = 0; poss < 10; poss++)
            {
                cout << sudoku_3d[ row ][ col ][ poss ] << "\t" ;
            }
            cout << "\n" ;
        }
};

#endif