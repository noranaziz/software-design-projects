// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Number_Command.h"

// initializer
Number_Command::Number_Command(Stack<int> & s, int n)
    : stack_ (s),
      num_ (n)
{

}

// get_precedence
int Number_Command::get_precedence (void)
{
    return 0;
}

// get_nested_level
int Number_Command::get_nested_level()
{
    return 0;
}

// set_nested_level
void Number_Command::set_nested_level(int level)
{
    // does nothing
}

// execute
void Number_Command::execute (void)
{
    // pushes number to the stack.
    stack_.push(num_);
}