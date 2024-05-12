// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Expr_Tree.h"

// constructor
Expr_Tree::Expr_Tree (void)
    : root_ (nullptr),
      visitor_ (new Eval_Expr_Tree())
{

}

// initializer
Expr_Tree::Expr_Tree (Expr_Node * root)
    : root_ (root),
      visitor_ (new Eval_Expr_Tree())
{

}

// destructor
Expr_Tree::~Expr_Tree (void)
{
    delete root_;
    delete visitor_;
}

// evaluate
int Expr_Tree::eval (void)
{
    // evaluate the tree by accepting the visitor, then returning its result.
    root_->accept(*visitor_);
    return visitor_->result();
}

// get root
Expr_Node * Expr_Tree::get_root (void)
{
    return root_;
}

// set root
void Expr_Tree::set_root (Expr_Node * root)
{
    root_ = root;
}