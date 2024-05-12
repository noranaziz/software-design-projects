// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Divide_Command.h"

// initializer
Divide_Command::Divide_Command(Stack<int> & s)
    : stack_ (s),
      nested_level (0)
{

}

// get_precedence
int Divide_Command::get_precedence (void)
{
    return 2;
}

// get_nested_level
int Divide_Command::get_nested_level()
{
    return nested_level;
}

// set_nested_level
void Divide_Command::set_nested_level(int level)
{
    nested_level = level;
}

// execute
void Divide_Command::execute (void)
{
    // pops numbers from stack, divides them, then pushes
    // the result back onto the stack.
    int num2 = stack_.top();
    stack_.pop();
    int num1 = stack_.top();
    stack_.pop();
    if(num2 == 0) {
        throw std::runtime_error("Math error: Attempted to divide by Zero\n");
    }
    stack_.push(num1 / num2);
}