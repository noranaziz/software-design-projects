// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Stack_Expr_Command_Factory.h"

// initializer
Stack_Expr_Command_Factory::Stack_Expr_Command_Factory (Stack<int> & stack)
    : stack_ (stack)
{

}

// destructor
Stack_Expr_Command_Factory::~Stack_Expr_Command_Factory (void)
{
    
}

// create_number_command
Number_Command * Stack_Expr_Command_Factory::create_number_command (int num)
{
    // returns concrete number command.
    return new Number_Command (stack_, num);
}

Add_Command * Stack_Expr_Command_Factory::create_add_command (void)
{
    // returns concrete add command.
    return new Add_Command (stack_);
}

Subtract_Command * Stack_Expr_Command_Factory::create_subtract_command (void)
{
    // returns concrete subtract command.
    return new Subtract_Command (stack_);
}

Multiply_Command * Stack_Expr_Command_Factory::create_multiply_command (void)
{
    // returns concrete multiply command.
    return new Multiply_Command (stack_);
}

Divide_Command * Stack_Expr_Command_Factory::create_divide_command (void)
{
    // returns concrete divide command.
    return new Divide_Command (stack_);
}

Modulus_Command * Stack_Expr_Command_Factory::create_modulus_command (void)
{
    // returns concrete modulus command.
    return new Modulus_Command (stack_);
}