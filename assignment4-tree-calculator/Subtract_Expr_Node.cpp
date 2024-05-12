// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Subtract_Expr_Node.h"

// constructor
// create binary node with precendence of 1
Subtract_Expr_Node::Subtract_Expr_Node (void)
    : Binary_Expr_Node (1)
{

}

// initializer
// create binary node with precendence of 1
// sets children to nodes in parameters.
Subtract_Expr_Node::Subtract_Expr_Node (Expr_Node * num1, Expr_Node * num2)
    : Binary_Expr_Node (1)
{
    set_left_child (num1);
    set_right_child (num2);
}

// destructor
Subtract_Expr_Node::~Subtract_Expr_Node (void)
{

}

// method to evaluate node
int Subtract_Expr_Node::eval (void)
{
    int num1_ = get_left_child()->eval();
    int num2_ = get_right_child()->eval();
    return num1_ - num2_;
}

// method to visit node
void Subtract_Expr_Node::accept (Expr_Node_Visitor & visitor)
{
    visitor.Visit_Subtraction_Node (*this);
}