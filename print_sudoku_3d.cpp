#ifndef print_sudoku_3d_cpp
#define print_sudoku_3d_cpp

#include "constants.cpp"

#include <iostream>

using namespace std;

class Sudoku_3d_Printer
{
    public:
        static void print(int sudoku_3d[MAX_ROW][MAX_COL][MAX_POSS])
        {
            
            cout<<"3d sudoku: \n "; 
            for (int row = MIN_ROW; row < MAX_ROW; row++)
			{
				for (int col = MIN_COL; col < MAX_COL; col++)
				{  
                    for (int poss = SOLVED_INDEX; poss < MAX_POSS; poss++)
                    {
                        cout << sudoku_3d[row][col][poss] << "\t" ;
                    }
                    cout << "\n" ;
                }
            }
        }
};

#endif