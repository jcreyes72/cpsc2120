/*
 * Name: Julio Reyes
 * Date Submitted:9/28/2020
 * Lab Section: 004
 * Assignment Name: Lab 4 - Searching and Sorting
 */


 #if !defined(SEARCHES_H_INCLUDED_7FB96876_45C4_4812_89BA_7514C868DE32)
 #define SEARCHES_H_INCLUDED_7FB96876_45C4_4812_89BA_7514C868DE32

#include <vector>
#include <iostream>
#include <string>

template <class T>
int linearSearch(std::vector<T> data, T target){

  int high = 0;                                               // Last element in the vector                                                                // First element in the vector

      for (auto i : data){                                    // Obtaining the last element
          high++;
      }

    for (int i = 0; i < high; i++){                           // Iterating through...return
        if (data[i] == target)                                // if element is found
            return i;
    }

return -1;                                                    // Negative one if target does
}                                                             // not exist


template <class T>
int binarySearch(std::vector<T> data, T target){

    int high = 0;                                                               // Last element in the vector
    int low = 0;                                                                // First element in the vector

        for (auto i : data){                                                    // Obtaining the last element
            high++;
        }

        while (low <= high){
            int mid = (high + low) / 2;

            if (data[mid] == target)
                return mid;

            if (data[mid] < target)
                low = mid + 1;

            else
                high = mid - 1;
        }

return -1;
}

#endif // !defined(SEARCHES_H_INCLUDED_7FB96876_45C4_4812_89BA_7514C868DE32)
