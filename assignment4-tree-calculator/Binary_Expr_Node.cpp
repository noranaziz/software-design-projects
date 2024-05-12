// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Binary_Expr_Node.h"

// constructor
Binary_Expr_Node::Binary_Expr_Node (void)
    : right_ (nullptr),
      left_ (nullptr),
      precendence_ (0),
      nested_ (0)
{

}

// initializer
Binary_Expr_Node::Binary_Expr_Node (int precedence)
    : right_ (nullptr),
      left_ (nullptr),
      precendence_ (precedence),
      nested_ (0)
{

}

// destructor
Binary_Expr_Node::~Binary_Expr_Node (void)
{
    delete right_;
    delete left_;
}

// get right child
Expr_Node * Binary_Expr_Node::get_right_child (void)
{
    return right_;
}

// get left child
Expr_Node * Binary_Expr_Node::get_left_child (void)
{
    return left_;
}

// set right child
void Binary_Expr_Node::set_right_child (Expr_Node * right)
{
    right_ = right;
}

// set left child
void Binary_Expr_Node::set_left_child(Expr_Node * left)
{
    left_ = left;
}

// get precedence
int Binary_Expr_Node::get_precedence (void)
{
    return precendence_;
}

// get nested level
int Binary_Expr_Node::get_nested_level (void)
{
    return nested_;
}

// set nested level
void Binary_Expr_Node::set_nested_level (int nested)
{
    nested_ = nested;
}