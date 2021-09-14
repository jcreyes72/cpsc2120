/*
 * Name:Julio Reyes
 * Date Submitted: 11/16/2020
 * Lab Section: 004
 * Assignment Name: Using Recursion to Solve the N-Queens Problem
 */

#include <iostream>
#include <vector>

using namespace std;


int findsolution(int **theQueens, int n, int column);


//bool function used to check if we can place queen
bool available(int**theQueens, int n, int column, int row);

// Uses recursion to count how many solutions there are for
// placing n queens on an nxn chess board
int nQueens(int n);


int main()
{
    cout << "1: " << nQueens(1) << endl;
    cout << "2: " << nQueens(2) << endl;
    cout << "3: " << nQueens(3) << endl;
    cout << "4: " << nQueens(4) << endl;
    cout << "5: " << nQueens(5) << endl;
    cout << "6: " << nQueens(6) << endl;
    cout << "7: " << nQueens(7) << endl;
    cout << "8: " << nQueens(8) << endl;
    cout << "9: " << nQueens(9) << endl;
    cout << "10: " << nQueens(10) << endl;
    cout << "11: " << nQueens(11) << endl;
    cout << "12: " << nQueens(12) << endl;
    return 0;
}


int nQueens(int n){

    int **theQueens = new int *[n];
    
        for (int i = 0; i < n; i++) {
            theQueens[i] = new int[n];
                for(int j = 0; j < n; j++) {
                    theQueens[i][j]=0;
                }
        }

    
    return findsolution(theQueens,n,0);


}


int findsolution(int ** theQueens, int n, int column) {
    
    int row;
    int count = 0;
   
        if(column == n) {

            return 1;
        
        }

        for(int i = 0; i < n; i++) {

            row = i;
            
                if(available(theQueens, n, column, row) == true){

                    theQueens[row][column] = 1;                         // Place queen
                    count += findsolution(theQueens, n, column + 1);    
                    theQueens[row][column] = 0; 

                }
        
        }
        
    return count;
}



bool available(int**theQueens, int n, int column, int row) {
    
    
    for(int i = 0; i < n; i++) {                                        // row check
        
        if(theQueens[row][i] == 1){
            return false;
        }

    }

                                                                    
    int j;                                                              
    
    for(int i = row, j = column; i >= 0 && j >= 0; i--,j--) {           // upper left check
        
        if(theQueens[i][j] == 1)
            return false;

    }

    
    for(int i = row, j = column; i < n && j >= 0; i++, j--) {           // low left check
    
        if(theQueens[i][j] == 1)
            return false;
    
    }


    return true;
}