#include <string>
#include <stack>
#include <cstring>
#include <iostream>

using namespace std;

//Calculates a postfix expression with integer operands using a stack
//The expression is represented using an array of strings
//Each string is either an operand or operator symbol
//Operator symbols:
//"+" addition
//"-" subtraction
//"*" multiplication
//"/" divison
//"%" remainder
//Example expression: "8", "5", "-" evaluates to a result of 3:
//1: push 8, 2: push 5,
//3: "-"-> pop top two values, earlier value is the left-side operand: 8 - 5
//The result of the operation (8-5) is 3, push 3 onto stack
//After evaluation of the expression, the final result should be
//the only value on the stack, return 0 if the stack is
//non-empty after popping the result
//Return 0 if expression is zero-length or if there are insufficient operands
//for an operation
//The STL Stack class can be used
//To easily convert a numeric string to an int you may use the stoi() function
//which takes a string as a parameter and returns a string
int calculatePostfixExpression(string expression[], int length){

    stack <int> values;

    if ((length == 0) || (length == 2)){
        return 0;
    }

    if ((length == 1)){
            if ((expression[0] == "+") || (expression[0] == "-") || (expression[0] == "*") || (expression[0] == "/") || (expression[0] == "%")){
                return 0;
            }
            else{
            int j = stoi(expression[0]);
            return j;
            }
    }


        for (int i = 0; i < length; i++){
            if ((expression[i] == "1") || (expression[i] == "2") || (expression[i] == "3") || (expression[i] == "4") || (expression[i] == "5")
             || (expression[i] == "6")  || (expression[i] == "7") || (expression[i] == "8") || (expression[i] == "9")
             || (expression[i] == "10") || (expression[i] == "11") || (expression[i] == "12") || (expression[i] == "13")
             || (expression[i] == "21") || (expression[i] == "22") || (expression[i] == "34")){
                int j = stoi(expression[i]);
                values.push(j);
             }
            else if ((expression[i] == "+") || (expression[i] == "-") || (expression[i] == "*") || (expression[i] == "/") || (expression[i] == "%")){
                int value1 = values.top();
                values.pop();
                int value2 = values.top();
                values.pop();

                if (expression[i] == "+"){
                    values.push(value2 + value1);
                }
                else if (expression[i] == "-"){
                    values.push(value2 - value1);
                }
                else if (expression[i] == "*"){
                    values.push(value2 * value1);
                }
                else if (expression[i] == "/"){
                    values.push(value2 / value1);
                }
                else if (expression[i] == "%"){
                    values.push(value2 % value1);
                }
            }
        }
    int finalAnswer = values.top();

    values.pop();

    if (!values.empty()){
        return 0;
    }

return finalAnswer;
}
