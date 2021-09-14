#include <vector>
#include <iostream>
#include <string>
#include "Sorts.h"
#include "Searches.h"

int main (){

int arr[] = {9, 33, 80, 349, 400, 5, 10};

int *arrPtr = arr;

printf("%d %d %d %d", *(arrPtr++), *(arrPtr+2), *arrPtr, *(--arrPtr));

return 0;
}
