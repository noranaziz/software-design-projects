// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Modulus_Expr_Node.h"

// constructor
// create binary node with precendence of 2
Modulus_Expr_Node::Modulus_Expr_Node (void)
    : Binary_Expr_Node (2)
{

}

// initializer
// create binary node with precendence of 2
// sets children to nodes in parameters.
Modulus_Expr_Node::Modulus_Expr_Node (Expr_Node * num1, Expr_Node * num2)
    : Binary_Expr_Node (2)
{
    set_left_child (num1);
    set_right_child (num2);
}

// destructor
Modulus_Expr_Node::~Modulus_Expr_Node (void)
{

}

// method to evaluate node
int Modulus_Expr_Node::eval (void)
{
    int num1_ = get_left_child()->eval();
    int num2_ = get_right_child()->eval();
    if(num2_ == 0) {
        throw std::runtime_error("Division by 0");
    }
    return num1_ % num2_;
}

// method to visit node
void Modulus_Expr_Node::accept (Expr_Node_Visitor & visitor)
{
    visitor.Visit_Modulus_Node (*this);
}