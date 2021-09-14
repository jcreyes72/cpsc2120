/*
 * Name: Julio Reyes
 * Date Submitted: 10/12/2020
 * Lab Section: 004
 * Assignment Name: Spell Checker Using a Hash Table
 */

#include <iostream>
#include "stringset.h"




Stringset::Stringset() : table(4), num_elems(0), size(4) {}





//Used in test cases and testStringset() in main.cpp, do not modify
vector<list<string>> Stringset::getTable() const {
    return table;
}




//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getNumElems() const {
    return num_elems;
}





//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getSize() const
{
    return size;
}




void Stringset::insert(string word){


	if(this->find(word))                            // Check if word is there already
		return;


	hash<string> stringHash;                        // index
	int index = stringHash(word) % this->size;


	table[index].push_back(word);                   // Place word in hashed index and increment
	num_elems++;




	if( num_elems == size )	{                       // If we need to increase table size
        size *= 2;
		vector<list<string>> newSize(size);


		for(auto iter : table){                     // Loop through lists
			for(auto elem : iter){                  // Loop through strings
				index = stringHash( elem ) % size;
				newSize[index].push_back( elem );
			}
		}

		table.resize(size);                         // Resize to bigger table
		table.swap(newSize);
	}
}




bool Stringset::find(string word) const {


	hash<string> stringHash;                           // Hash index
	int index = stringHash(word) % size;


	for(auto elem : table[index]){                  // Loop through all strings in list at hash index
		if(elem.compare(word) == 0)                 // Word is found
        return true;
	}


return false;                                       // Word is not found
}





void Stringset::remove(string word) {

	hash<string> stringHash;                            // index
	int index = stringHash(word) % this->size;


	for(auto elem : table[index]){                      // Loop through all strings in list at hash index
		if(word.compare(elem.data()) == 0){             // Word is found
			table[index].remove(word);
			num_elems--;
			return;
		}
	}
}

