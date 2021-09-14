/*
 * Name: Julio Reyes 
 * Date Submitted: 10/24/2020
 * Lab Section: 004
 * Assignment Name: Finding the Closest Pair of Points 
 */


// Couldn't get it tried for hours upon hours upon hours upon hours upon hours maybe thats worth something







#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;


struct point {
    double x;
    double y;
    point(double i, double j):x(i), y(j){}
};

double checkNeighbors (int, int, int, double, vector<vector<vector<point>>>);
double checkCell (int, int, int, int, double, vector<vector<vector<point>>>);
double calculateDistance(int, int, int, int, vector<vector<vector<point>>>);

/*Implement the following function
  Reads in a file specified by the parameter
  Format of file: #of points on first line
  remaining (#of points) lines: x-value and y-value of point
  one point per line
  x-value and y-value are double-precision values and
  bounded by the unit square 0.0 <= x,y < 1.0
  Should use "spatial hashing" where the #of cells scales with the #of points
  and find the distance between the closest pair of points which will be
  returned as a double type value
*/
double closestPair(string filename);

int main() {
    
    double min;
    string filename;
    
    std::cout << "File with list of points within unit square: ";
    std::cin >> filename;

    min = closestPair(filename);

    std::cout << setprecision(16);
    std::cout << "Distance between closest pair of points: " << min << endl;

    return 0;
}



double closestPair(string filename){


    std::ifstream infile(filename);                                     // Creating ifstream to read in file

    int numPoints;                                                      // The number of points in our file
    infile >> numPoints;

    int b = sqrt(numPoints);                                            // Calculating b using numPoints
    std::cout << "B IS " << b << std::endl;
    double interval = (double)1 / b;                                    // Interval for our grid 
    std::cout << "INTERVAL IS " << interval << std::endl;

    vector<point> innerVector; 
    vector<vector<vector<point>>> ourGrid;                              // Creating 2D vector to act as our plane
    vector<vector<point>> outerVector;

    double num1, num2;                                                  // Two doubles that will help us read from file 


        for (int j = 0; j < b; j++){                                    // Initializing grid 
            for (int i = 0; i < b; i++){
                vector<point> innerVector;                              // Create inner vector 
                outerVector.push_back(innerVector);                     // Push it into outer vector 
            }   
            ourGrid.push_back(outerVector);                             // Push outer vector into our grid
        }

  

        while (infile >> num1 >> num2){                                 // Storing points into our grid

            int xPos = num1 / interval;
            int yPos = num2 / interval;
            
            ourGrid[xPos][yPos].push_back(point(num1, num2));
        
        }


        double distance = 0;

        for (int i = 0; i < b; i++){
            for (int j = 0; j < b; j++){
                for (int k = 0; k < ourGrid[i][j].size(); k++){
                    for (int m = k+1; m < ourGrid[i][j].size(); m++)
                        distance = checkCell(i, j, k, m, distance, ourGrid);
                    }
                    distance = checkNeighbors(i, j, k, distance, ourGrid);
                }
            }
        }




return distance;
}



double checkNeighbors (int i, int j, int k, double distance, vector<vector<vector<point>>> ourGrid){

    double newDistance = distance;

    if ((j + 1) < 9){
        for (int m = 0; m < ourGrid[i][j+1].size(); m++){

            double xAnswer = pow(((ourGrid[i][j+1][m].x) - (ourGrid[i][j][k].x)), 2);
            double yAnswer = pow(((ourGrid[i][j+1][m].y) - (ourGrid[i][j][k].y)), 2);
            double finalAnswer = sqrt(xAnswer + yAnswer);

            if (finalAnswer < newDistance){
                newDistance = finalAnswer;
            }
        }
    }
    else {
        
    }
        for (int m = 0; m < ourGrid[i][j-1].size(); m++){
            if ((j - 1) < 0){
                break;
            }
            double xAnswer = pow(((ourGrid[i][j-1][m].x) - (ourGrid[i][j][k].x)), 2);
            double yAnswer = pow(((ourGrid[i][j-1][m].y) - (ourGrid[i][j][k].y)), 2);
            double finalAnswer = sqrt(xAnswer + yAnswer);

            if (finalAnswer < newDistance){
                newDistance = finalAnswer;
            }
        }
        for (int m = 0; m < ourGrid[i+1][j].size(); m++){
            if ((i + 1) > 9){
                break;
            }
            double xAnswer = pow(((ourGrid[i+1][j][m].x) - (ourGrid[i][j][k].x)), 2);
            double yAnswer = pow(((ourGrid[i+1][j][m].y) - (ourGrid[i][j][k].y)), 2);
            double finalAnswer = sqrt(xAnswer + yAnswer);

            if (finalAnswer < newDistance){
                newDistance = finalAnswer;
            }
        }
        for (int m = 0; m < ourGrid[i-1][j].size(); m++){
            if ((i - 1) < 0){
                break;
            }
            double xAnswer = pow(((ourGrid[i-1][j][m].x) - (ourGrid[i][j][k].x)), 2);
            double yAnswer = pow(((ourGrid[i-1][j][m].y) - (ourGrid[i][j][k].y)), 2);
            double finalAnswer = sqrt(xAnswer + yAnswer);

            if (finalAnswer < newDistance){
                newDistance = finalAnswer;
            }
        }
        for (int m = 0; m < ourGrid[i-1][j-1].size(); m++){
            if ((j - 1) < 0){
                break;
            }
            if ((i - 1) < 0){
                break;
            }
            double xAnswer = pow(((ourGrid[i-1][j-1][m].x) - (ourGrid[i][j][k].x)), 2);
            double yAnswer = pow(((ourGrid[i-1][j-1][m].y) - (ourGrid[i][j][k].y)), 2);
            double finalAnswer = sqrt(xAnswer + yAnswer);

            if (finalAnswer < newDistance){
                newDistance = finalAnswer;
            }
        }
        for (int m = 0; m < ourGrid[i+1][j+1].size(); m++){
            if ((j + 1) > 9){
                break;
            }
            if ((i + 1) > 9){
                break;
            }
            double xAnswer = pow(((ourGrid[i+1][j+1][m].x) - (ourGrid[i][j][k].x)), 2);
            double yAnswer = pow(((ourGrid[i+1][j+1][m].y) - (ourGrid[i][j][k].y)), 2);
            double finalAnswer = sqrt(xAnswer + yAnswer);

            if (finalAnswer < newDistance){
                newDistance = finalAnswer;
            }
        }
        for (int m = 0; m < ourGrid[i-1][j+1].size(); m++){
            if ((j + 1) > 9){
                break;
            }
            if ((i - 1) < 0){
                break;
            }
            double xAnswer = pow(((ourGrid[i-1][j+1][m].x) - (ourGrid[i][j][k].x)), 2);
            double yAnswer = pow(((ourGrid[i-1][j+1][m].y) - (ourGrid[i][j][k].y)), 2);
            double finalAnswer = sqrt(xAnswer + yAnswer);

            if (finalAnswer < newDistance){
                newDistance = finalAnswer;
            }
        }
        for (int m = 0; m < ourGrid[i+1][j-1].size(); m++){
            if ((j - 1) < 0){
                break;
            }
            if ((i + 1) > 9){
                break;
            }
            double xAnswer = pow(((ourGrid[i+1][j-1][m].x) - (ourGrid[i][j][k].x)), 2);
            double yAnswer = pow(((ourGrid[i+1][j-1][m].y) - (ourGrid[i][j][k].y)), 2);
            double finalAnswer = sqrt(xAnswer + yAnswer);

            if (finalAnswer < newDistance){
                newDistance = finalAnswer;
            }
        }

return newDistance;
}


double calculateDistance(int i, int j, int k, int m, vector<vector<vector<point>>> ourGrid){

    double xAnswer = pow(((ourGrid[i][j][m].x) - (ourGrid[i][j][k].x)), 2);
    double yAnswer = pow(((ourGrid[i][j][m].y) - (ourGrid[i][j][k].y)), 2);

    double finalAnswer = sqrt(xAnswer + yAnswer);

return finalAnswer;
}


double checkCell (int i, int j, int k, int m, double distance, vector<vector<vector<point>>> ourGrid){

    double newDistance = calculateDistance(i, j, k, m, ourGrid);

        if (newDistance < distance){
            return newDistance;
        }
        else {
            return distance;
        }
}


