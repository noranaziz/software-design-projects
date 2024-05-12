//==============================================================================
/**
 * @file       Expr_Tree_Builder.h
 *
 * $Id: Expr_Tree_Builder.h $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _EXPR_TREE_BUILDER_H_
#define _EXPR_TREE_BUILDER_H_

#include "Expr_Builder.h"
#include "Expr_Tree.h"

/**
 * @class Expr_Tree_Builder
 *
 * Builder class for expression tree.
 */
class Expr_Tree_Builder : public Expr_Builder
{
public:
  /// Default constructor.
  Expr_Tree_Builder (void);

  /// Default destructor.
  virtual ~Expr_Tree_Builder (void);

  /// Methods to build each part of the expression tree.
  virtual void start_expression (void);
  virtual void build_number (int n);
  virtual void build_add_operator (void);
  virtual void build_subtract_operator (void);
  virtual void build_multiply_operator (void);
  virtual void build_divide_operator (void);
  virtual void build_modulus_operator (void);
  virtual void build_open_parenthesis (void);
  virtual void build_close_parenthesis (void);
  virtual void end_expression (void);

  /// Insert node in tree.
  virtual void insert_node (Expr_Node * node);

  /// Get current expression.
  Expr_Tree * get_expression (void);

private:
  /// Current state of expression tree.
  Expr_Tree * tree_;

  /// Other variables to coordinate build process
  /// Node that isn't finished being built.
  Expr_Node * not_finished_;

  /// Used to check if node is finished being built.
  bool finished_;

  /// Keep track of parenthesis.
  int open_parenthesis_;
  int close_parenthesis_;
  bool is_open_;
  Stack<Expr_Node *> parenthesis_;
};

#endif   // !defined _EXPR_TREE_BUILDER_H_