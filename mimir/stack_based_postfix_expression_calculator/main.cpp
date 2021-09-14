#include <iostream>


using namespace std;

int calculatePostfixExpression(string expression[], int length);

int main()
{
    cout << "Hello world!" << endl;

    string exp[] = {"5"};

    cout << "\n\n The answer to the expression is " << calculatePostfixExpression(exp, 1);

    return 0;
}
