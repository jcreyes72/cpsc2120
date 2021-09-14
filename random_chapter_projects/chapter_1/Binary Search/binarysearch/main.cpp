// BinarySearch.cpp
// wdg 2016

#include <iostream>


int binarySearch(double *arr, int size, double item) {

    int begin = 0;
    int end = size;
    // invariant: unsearched space is begin, begin+1, ..., end-1

        while( begin < end ) {

           int middle = (begin + end) / 2;

           if( item == arr[middle] ) {
              return middle;
           }
           else if ( item > arr[middle] ) {
              begin = middle+1;
           }
           else{
              end = middle;
           }
        }

return -1;
}

int main( ) {


   double A[] = { 2.0, 3.0, 5.0, 8.0, 13.0, 21.0};


   std::cout << "Position of 3.14 is " << binarySearch( A, 6, 3.14) << std::endl;
   std::cout << "Position of 21.0 is " << binarySearch( A, 6, 21.0) << std::endl;


   return 0;
}




