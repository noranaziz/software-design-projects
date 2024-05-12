//==============================================================================
/**
 * @file       Expr_Tree.h
 *
 * $Id: Expr_Tree.h $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _EXPR_TREE_H_
#define _EXPR_TREE_H_

#include "Expr_Node.h"
#include "Math_Expr.h"
#include "Eval_Expr_Tree.h"

/**
 * @class Expr_Tree
 *
 * Class for math expression as a tree.
 */
class Expr_Tree : public Math_Expr
{
public:
  /// Default constructor.
  Expr_Tree (void);

  /// Initializing constructor.
  Expr_Tree (Expr_Node * root);

  /// Default destructor.
  ~Expr_Tree (void);

  /// Method to evaluate the tree.
  virtual int eval (void);

  /// Get the root of the tree.
  Expr_Node * get_root (void);

  /// Set the root of the tree.
  void set_root (Expr_Node * root);

private:
  Expr_Node * root_;
  Eval_Expr_Tree * visitor_;
};

#endif   // !defined _EXPR_TREE_H_