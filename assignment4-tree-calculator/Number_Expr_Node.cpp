// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Number_Expr_Node.h"

// constructor
// assigns number_ a default value (0)
Number_Expr_Node::Number_Expr_Node (void)
    : Binary_Expr_Node (3),
      number_ (1)
{

}

// initializer
// sets number_ to parameter
Number_Expr_Node::Number_Expr_Node (int number)
    : Binary_Expr_Node (3),
      number_ (number)
{

}

// destructor
Number_Expr_Node::~Number_Expr_Node (void)
{

}

// eval
// returns the number associated with the node
int Number_Expr_Node::eval (void)
{
    return number_;
}

// accept
// visits node
void Number_Expr_Node::accept (Expr_Node_Visitor & visitor)
{
    visitor.Visit_Number_Node (*this);
}