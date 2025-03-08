#ifndef print_sudoku_3d_cpp
#define print_sudoku_3d_cpp

#include "possibility_limiter.cpp"

#include <iostream>

using namespace std;

class Sudoku_3d_Printer
{
    public:
        static void print(int sudoku_3d[9][9][10])
        {
            
            cout<<"3d sudoku: \n "; 
            for (int row = 0; row < 9; row++)
			{
				for (int col = 0; col < 9; col++)
				{  
                    for (int poss = min_poss; poss < max_poss; poss++)
                    {
                        cout << sudoku_3d[ row ][ col ][ poss ] << "\t" ;
                    }
                    cout << "\n" ;
                }
            }
        }
};

#endif