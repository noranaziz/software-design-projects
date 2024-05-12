// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Add_Expr_Node.h"

// constructor
// create binary node with precendence of 1
Add_Expr_Node::Add_Expr_Node (void)
    : Binary_Expr_Node (1)
{

}

// initializer
// create binary node with precendence of 1
// sets children to nodes in parameters.
Add_Expr_Node::Add_Expr_Node (Expr_Node * node1, Expr_Node * node2)
    : Binary_Expr_Node (1)
{
    set_left_child (node1);
    set_right_child (node2);
}

// destructor
Add_Expr_Node::~Add_Expr_Node (void)
{

}

// method to evaluate node
int Add_Expr_Node::eval (void)
{
    int num1_ = get_left_child()->eval();
    int num2_ = get_right_child()->eval();
    return num1_ + num2_;
}

// method to visit node
void Add_Expr_Node::accept (Expr_Node_Visitor & visitor)
{
    visitor.Visit_Addition_Node (*this);
}