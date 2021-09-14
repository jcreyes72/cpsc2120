/*
 * Name: Julio Reyes
 * Date Submitted: 9/17/2020
 * Lab Section: 004
 * Assignment Name: Finding Groups Using Recursion
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

//Represents an occupied square in the grid
//Do not modify the GridSquare class or its member functions
class GridSquare
{
    private:
        int row, col;
    public:
        GridSquare() : row(0), col(0) {} //Default constructor, (0,0) square
        GridSquare(int r, int c) : row(r), col(c) {} //(r,c) square
        //Compare with == operator, used in test cases
        bool operator== (const GridSquare r) const
        {
            if ((row == r.row) && (col == r.col))
            {
                return true;
            }
            return false;
        }
        int getRow() { return row; } //return row value
        int getCol() { return col; } //return column value
        //Output using << operator, used in Grouping::printGroups()
        friend ostream& operator<< (ostream& os, const GridSquare obj);
};

//Function definition for <ostream> << <GridSquare>
ostream& operator<< (ostream& os, const GridSquare obj)
{
    os << "(" << obj.row << "," << obj.col << ")";
    return os;
}

/*
Groups squares in 10x10 grid upon construction
Additional private helper functions may be added
Need to implement the constructor that takes a file name
as well as findGroup
The findGroup function's parameter list may be changed based
on how the function is implemented
*/
class Grouping
{
    private:
        int grid[10][10];
        vector<vector<GridSquare>> groups;
    public:
        Grouping() : grid{},groups() {} //Default constructor, no groups
        Grouping(string fileName); //Implement this function
        void findGroup(int r, int c, vector<GridSquare> &); //Implement this function (recursive)
        void printGroups() //Displays grid's groups of squares
        {
            for(int g=0; g<groups.size(); g++)
            {
                cout << "Group " << g+1 << ": ";
                for(int s=0; s<groups[g].size(); s++)
                {
                    cout << " " << groups[g][s];
                }
                cout << endl;
            }
        }
        vector<vector<GridSquare>> getGroups() //Needed in unit tests
        {
            return groups;
        }
};

//Implement the (parameterized) constructor and findGroup functions below

int numObjects = 0;

Grouping::Grouping (string fileName){

    ifstream infile(fileName);                  // Creates ifstream
    char input;                                 // Char to store file chars
    vector<GridSquare> innerVector;



        for (int i = 0; i < 10; i++){          // Storing chars onto grid
            for (int j = 0; j < 10; j++){
                infile >> input;

                if (input == '.'){              // Converting periods to zeros
                    grid[i][j] = 0;
                }
                else {
                    grid[i][j] = 1;             // Converting other characters to 1
                }
            }
        }

        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                if (grid[i][j] == 1){
                    vector<GridSquare> innerVector;

                    findGroup(i, j, innerVector);
                    groups.push_back(innerVector);
                    //grid[i+1][j] = 0;
                    //grid[i-1][j] = 0;
                    //grid[i][j+1] = 0;
                    //grid[i][j-1] = 0;
                    //grid[i][j] = 0;
                }
            }
        }

}


void Grouping::findGroup(int r, int c, vector<GridSquare> &innerVector){ //Implement this function (recursive)


    GridSquare newSquare(r, c);

    grid[r][c] = 0;


    innerVector.push_back(newSquare);



    if ((r + 1 < 10) && (((grid[r+1][c]) == 1))){
        findGroup(r+1, c, innerVector);
    }
    if ((r - 1 >= 0) && (((grid[r-1][c]) == 1))){
        findGroup(r-1, c, innerVector);
    }
    if ((c + 1 < 10) && (((grid[r][c+1]) == 1))){
        findGroup(r, c+1, innerVector);
    }
    if ((c - 1 >= 0) && (((grid[r][c-1]) == 1))){
        findGroup(r, c-1, innerVector);
    }


}


//Simple main function to test Grouping
int main()
{
    Grouping input1("input2.txt");
    input1.printGroups();

    return 0;
}
