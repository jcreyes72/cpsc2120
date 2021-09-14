#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<string> V; //words from wordlist05.txt
unordered_map<string, bool> visited;
unordered_map<string, string> predecessor;
unordered_map<string, int> dist;
unordered_map<string, vector<string>> neighborNode;

//Implement breadth-first search
void makeGraph();
int findPath(string, string, vector<string>&);
void wordLadder(string, string, int&, vector<string>&);


int main(void) {

  int steps = 0;
  string s, t;
  vector<string> path;
  
  cout << "Source: ";
  cin >> s;

  cout << "Target: ";
  cin >> t;

  wordLadder(s, t, steps, path);

  if (steps == 0) {

      cout << "No path!\n";
  
  }
  else {

      cout << "Steps: " << steps << "\n\n";
      
        for (int i=0; i<path.size(); i++) {
            cout << path[i] << endl;
        }

  }

return 0;
}


int findPath(string start, string end, vector<string> &path)	{

    // Make sure end node has a predecessor
    if (predecessor.find(end) == predecessor.end()) {
      return 0;
    }

    if(start.compare(end) != 0)	{

      int jump = 1 + findPath(start, predecessor[end],path);
      path.push_back(end);
      return jump;

    }

    else {

      path.push_back(end);
      return 0;

    }
	
}


void wordLadder(string s, string t, int &steps, vector<string> &p) {

	makeGraph();

	queue<string> unmet;

	unmet.push(s);
	visited[s] = true;
	dist[s] = 0;

    while (!unmet.empty()) {

      string node = unmet.front();
      unmet.pop();

        for (string n : neighborNode[node]) {

          if (!visited[n]) {
            predecessor[n] = node;
            dist[n] = 1 + dist[node];
            visited[n] = true;
            unmet.push(n);
          }

        }

  	}

	steps = findPath(s, t, p);
}


void makeGraph(void) {

	ifstream word_file ("wordlist05.txt");
	string currentWord;

    while(word_file >> currentWord) {
      V.push_back(currentWord);
    }

    for(auto word : V) {

      for(int place = 0; place < word.length(); place++) {

        for(char letter = 'a'; letter <= 'z'; letter++)	{
          
          if(letter == word.at(place)){
            continue;
          }

          string current = word;
          current.at(place) = letter;
          neighborNode[word].push_back(current);

        }
      }
    }

}