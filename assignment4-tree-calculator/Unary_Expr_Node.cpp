// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Unary_Expr_Node.h"

// initializer
// sets child node to nullptr
Unary_Expr_Node::Unary_Expr_Node (void)
    : child_ (nullptr)
{

}

// destructor
Unary_Expr_Node::~Unary_Expr_Node (void)
{

}

// get child
Expr_Node * Unary_Expr_Node::get_child (void)
{
    return child_;
}

// set child
void Unary_Expr_Node::set_child (Expr_Node * child)
{
    child_ = child;
}