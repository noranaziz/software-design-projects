// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Multiply_Command.h"

// initializer
Multiply_Command::Multiply_Command(Stack<int> & s)
    : stack_ (s),
      nested_level (0)
{

}

// get_precedence
int Multiply_Command::get_precedence (void)
{
    return 2;
}

// get_nested_level
int Multiply_Command::get_nested_level()
{
    return nested_level;
}

// set_nested_level
void Multiply_Command::set_nested_level(int level)
{
    nested_level = level;
}

// execute
void Multiply_Command::execute (void)
{
    // pops numbers from stack, multiplies them, then pushes
    // the result back onto the stack.
    int num2 = stack_.top();
    stack_.pop();
    int num1 = stack_.top();
    stack_.pop();
    stack_.push(num1 * num2);
}