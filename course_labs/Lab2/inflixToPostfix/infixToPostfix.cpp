/*
 * Name: Julio Reyes
 * Date Submitted:
 * Lab Section: 004
 * Assignment Name: Lab 2 - Infix to Postfix Conversion
 */

#include <string>
#include <stack>
#include <iostream>

using namespace std;

//Converts an infix arithmetic expression into postfix
//The function takes 3 parameters
//First parameter: array of strings for infix expression
//    each string is either an integer number or operator symbol
//Second parameter: number of strings in infix expression
//Third parameter: array of strings for postfix expression
//    generated by function, same format as first parameter
//    assumes that postfix is at least the size of postfix
//Return value: int, number of strings in postfix expression
//    Returns 0 if an error is encountered when converting expression
//    An error occurs with a mismatched parenthesis, e.g. ( ( ) or ( ) ) etc.
//Operator symbols:
// ( : left parenthesis, all operations between this and ")" take place first
// ) : right parenthesis, all op.s back to previous "(" take place first
// * : multiplication, higher precedence - takes place before "+" and "-"
// / : division, higher precedence - takes place before "+" and "-"
// % : remainder, higher precedence - takes place before "+" and "-"
// + : addition, lower precedence - takes place after "*" , "/" , "%"
// - : subtraction, lower precedence - takes place after "*" , "/" , "%"
//The function is not specified to work with any other operator symbols
//Any string in infix may be assumed to be an integer operand if none
// of the above symbols
int infixToPostfix(string infix[], int length, string postfix[]){


    int parenthesisSwitch = 0;                  // Int we will use to keep track of
                                                // parenthesis


        for (int i = 0; i < length; i++){       // Check if parenthesis are matching
            if (infix[i] == ")"){
                if (parenthesisSwitch == 0){
                    return 0;
                }
                else {
                    parenthesisSwitch--;
                }
            }
            if (infix[i] == "("){
                parenthesisSwitch++;
            }
        }


    stack <std::string> operators;              // This is a stack that we will store
                                                // our operators in

    int h = 0;                                  // h will keep track of postfix element
                                                // in our for loop

        for (int i = 0; i < length; i++){

            if ((infix[i] == "0") || (infix[i] == "1") ||(infix[i] == "2") ||(infix[i] == "3") ||(infix[i] == "4") ||(infix[i] == "5") ||(infix[i] == "6") ||(infix[i] == "7") ||(infix[i] == "8") ||(infix[i] == "9")){
                            postfix[h] = infix[i];
                            h++;

            }




            else if (infix[i] == "("){
                            operators.push(infix[i]);
            }




            else if ((infix[i] == "+") || (infix[i] == "-")){
                            if (operators.empty()){
                                operators.push(infix[i]);
                            }
                            else {
                                while (!operators.empty()){
                                    if (operators.top() == "(")
                                        break;
                                    postfix[h] = operators.top();
                                    operators.pop();
                                    h++;
                                }
                                operators.push(infix[i]);
                            }
            }




            else if ((infix[i] == "*") || (infix[i] == "/") || (infix[i] == "%")){
                            if (operators.empty()){
                                operators.push(infix[i]);
                            }
                            else {
                                while (!operators.empty()){
                                    if ((operators.top() == "(") || (operators.top() == "+") || (operators.top() == "-"))
                                        break;
                                    postfix[h] = operators.top();
                                    operators.pop();
                                    h++;
                                }
                                operators.push(infix[i]);
                            }
            }


            else if (infix[i] == ")"){
                            while (!operators.empty()){
                                if (operators.top() == "(")
                                    break;
                                postfix[h] = operators.top();
                                operators.pop();
                                h++;
                            }
                            operators.pop();
            }


        }



        while (!operators.empty()){
            postfix[h] = operators.top();
            operators.pop();
            h++;
        }

return h;
}

//Main function to test infixToPostfix()
//Should convert 2 + 3 * 4 + ( 5 - 6 + 7 ) * 8
//            to 2 3 4 * + 5 6 - 7 + 8 * +
int main()
{
    string infixExp[] = {"2", "+", "3", "*", "4", "-", "10", "/", "5", "%", "3"};

    string postfixExp[11];
    int postfixLength;

    cout << "Infix expression: ";
    for (int i=0; i<11; i++)
    {
        cout << infixExp[i] << " ";
    }
    cout << endl;
    cout << "Length: 11" << endl << endl;

    postfixLength = infixToPostfix(infixExp, 11, postfixExp);

    cout << "\n\n\nPostfix expression: ";
    for (int i=0; i<postfixLength; i++)
    {
        cout << postfixExp[i] << " ";
    }
    cout << endl;
    cout << "Length: " << postfixLength << endl;

    return 0;
}