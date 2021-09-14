/*
 * Name: Julio Reyes 
 * Date Submitted:10/25/2020
 * Assignment Name:
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> loadWordlist(string filename);

/*Implement the following function:
  anagram() takes a word (string) and a wordlist of all words (vector of strings)
  and builds a dictionary/map where the key is a specific number of times each
  letter occurs in a word and the associated value is a vector of strings
  containing all words using those letters (anagrams).
  The value returned is a vector of strings containing the corresponding
  set of anagrams
*/
vector<string> anagram(string word, vector<string> wordlist);

int main() {

    vector<string> words;
    vector<string> anagrams;
    string inputWord;

    words = loadWordlist("wordlist.txt");

    cout << "Find single-word anagrams for the following word: ";
    cin >> inputWord;

    anagrams = anagram(inputWord, words);
      
        for (int i=0; i<anagrams.size(); i++) {
            cout << anagrams[i] << endl;
        }

return 0;
}

vector<string> loadWordlist(string filename) {
    
    vector<string> words;
    ifstream inFile;
    string word;
    
    inFile.open(filename);
    
        if(inFile.is_open()) {
        
            while(getline(inFile,word)) {
                if(word.length() > 0){
                    words.push_back(word);
            }

        }
        inFile.close();
    }
    return words;
}

//Implement this function
vector<string> anagram(string word, vector<string> wordlist){


    std::string item;                                               // One word we will grab from the list 
    vector<string> ourAnagrams;                                     // Vector of our anagrams that we find 
    
    
//    ourAnagrams.push_back(word);                                    // Putting our user entered word into vector 
    

    for(int k = 0; k < wordlist.size(); k++){                       // Iterate through entire word list

        item = wordlist[k];                                         // Current word to check
        
        int wordLength = word.length();
        int itemLength = item.length();
        
        unordered_map<char, int> wordCheck;                         // Map to store letters       
        
        if(wordLength != itemLength){                               // Make sure they have the same length
            continue;                                  
        }
        
            for(int i = 0; i < wordLength; i++){                    // Adding keys with values to wordCheck
                wordCheck[word[i]]++;                               
            }
            
            for(int i = 0; i < itemLength; i++){

                if(wordCheck.find(item[i]) == wordCheck.end()){     // If we can't find the specific letter, quit
                    break;                                  
                }
                else {
                    wordCheck[item[i]]--;                           // Remove key from wordcheck        
                    if(wordCheck[item[i]] == 0){
                        wordCheck.erase(item[i]);                   // Erasing...    
                    }
                }
            }

        if(wordCheck.size() == 0){                                  // If each key has been removed                      
            ourAnagrams.push_back(item);                            // They are anagrams
        }    
    } 
   
  return ourAnagrams;
}