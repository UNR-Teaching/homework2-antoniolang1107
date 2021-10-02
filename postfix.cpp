#include <iostream>
#include <string>
#include "linkedstack.h"
#include "node.h"

string getInfix();
string toPostfix(string);
int calcPostfix(string);
int getResult(char, int, int);
bool isInt(char);
bool isOperator(char);
bool highOperator(char);

int main() {
    string expression;
    expression = getInfix();
    std::cout << "Result: " << calcPostfix(toPostfix(expression)) << std::endl;
} // ends main

string getInfix() {
    string expression;
    std::cout << "Enter your expression: ";
    std::getline(std::cin, expression);
    return expression;
} // ends getInfix

string toPostfix(string infix) {
    LinkedStack<char> readInfix;
    string postfix;

    for (int i = 0; i < infix.length(); i++) {
        if (isInt(infix[i]))
            postfix += infix[i];
        else if (isOperator(infix[i])) {
            if (!readInfix.isEmpty()) {
                if (!highOperator(infix[i])) {
                    postfix += readInfix.peek();
                    readInfix.pop();
                    readInfix.push(infix[i]);
                }
                else
                    readInfix.push(infix[i]);
            }
            else
                readInfix.push(infix[i]);
            
        }
    }
    while(!readInfix.isEmpty()) {
        postfix += readInfix.peek();
        readInfix.pop();
    }

    return postfix;
} // ends toPostfix

int calcPostfix(string postfix) {
    LinkedStack<int> calcPostfix;
    int num1, num2;
    char operand;

    for (int i = 0; i < postfix.length(); i++) {
        if (isOperator(postfix[i])) {
            operand = postfix[i];
            num2 = (int)calcPostfix.peek();
            calcPostfix.pop();
            num1 = (int)calcPostfix.peek();
            calcPostfix.pop();

            calcPostfix.push(getResult(operand, num1, num2));
        }
        else
            calcPostfix.push(postfix[i] - '0');
    }

    return calcPostfix.peek();
} // ends calcPostfix

bool isInt(char input) {
    if (input >= '0' && input <= '9')
        return true;
    else
        return false;
} // ends isInt

bool isOperator(char input) {
    if (input == '*' || input == '/' || input == '+' || input == '-')
        return true;
    else
        return false;
} // ends isOperator

int getResult(char operand, int num1, int num2) {
    if (operand == '*')
        return num1*num2;
    if (operand == '/')
        return num1/num2;
    if (operand == '+')
        return num1+num2;
    if (operand == '-')
        return num2-num1;
} // ends getResult

bool highOperator(char op1) {
    if (op1 == '*' || op1 == '/')
        return true;
    else
        return false;
} // ends highOperator