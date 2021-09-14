/*
 * Name: Julio Reyes
 * Date Submitted:9/28/2020
 * Lab Section: 004
 * Assignment Name: Lab 4 - Searching and Sorting
 */

 #if !defined(SORTS_H_INCLUDED_8DCEB0EC_6B5A_47FC_8CFC_E70E5185991B)
 #define SORTS_H_INCLUDED_8DCEB0EC_6B5A_47FC_8CFC_E70E5185991B

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include "Searches.h"








template <class T>
void realSort(std::vector<T> list, int low, int high) {

  while (1){
      int pivotPosition = rand() % list.size();
      T *pivot = &list[pivotPosition];
      T *startPtr = &list[low];
      T *endPtr = &list[high];

          while (*startPtr < *pivot){
              startPtr = &list[low + 1];
          }

          while (*endPtr > *pivot){
              endPtr = &list[high - 1];
          }

          if (*startPtr <= *endPtr)
              std::swap (startPtr, endPtr);

          startPtr = &list[low + 1];
          endPtr = &list[high - 1];

          if (startPtr == endPtr){
            break;
          }
  }

}





template <class T>
std::vector<T> mergeSort(std::vector<T> list){
}




template <class T>
std::vector<T> quickSort(std::vector<T> list){

    int low = 0;
    int high = 0;

      for (auto i : list){
        high++;
      }

    realSort(list, low, high);

return list;
}

#endif // !defined(SORTS_H_INCLUDED_8DCEB0EC_6B5A_47FC_8CFC_E70E5185991B)
