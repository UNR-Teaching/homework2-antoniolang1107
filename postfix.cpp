#include <iostream>

int main() {

}


/*
take string of characters (infix expression) and translate it into precendence order (postfix expression)
    make function to do

transform logic:
    if char is (, push to stack
    if char is ), pop until ( is reached
    if is number, add to output string
    while peeking at top, take into account precendence of operators
        exception for nothing to peek at (?)
        pop higher precendence operator before adding lower one to the stack (iterate through comparisons?)
    when infix expression is empty, pop all values into the postfix expression

caluclation logic:
    take string input, get number output (integer division is fine for assignment)
    new stack for operands (aka the numbers) (type-cast to int/float for the stack)
    when operator reached, pop operands off stacks
    push result back on stack
    *peek before popping with stack

other functions
    check for operation vs operand
    convert char to int/float
*/