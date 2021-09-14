#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

void ReadStdIn2();

int main (){

	ReadStdIn2();

return 0;
}

void ReadStdIn2() {

	std::string userInput;
	int count = 0;

	getline(std::cin, userInput, 'q');

		for (int i = 0; i < userInput.size(); i++){
			if ((userInput[i] == ' ') || (userInput[i] == '\n')){
				count += 1;
			}
		}


	std::cout << count << std::endl;

}
