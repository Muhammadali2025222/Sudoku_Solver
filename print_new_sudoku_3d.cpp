#ifndef print_new_sudoku_3d_cpp
#define print_new_sudoku_3d_cpp

#include <iostream>
using namespace std;

void print_new_sudoku_3d(int new_sudoku_3d[9][9][10] )
{
   for (int row = 0; row < 9; row++) 
    {
        for (int col = 0; col < 9; col++) 
        {
            for (int poss = 0; poss < 10; poss++)
            {
              cout << new_sudoku_3d[ row ][ col ][ poss ] << "\t" ;
            }
            cout << "\n" ;
        }
        cout << "\n" ;
    }
}

#endif