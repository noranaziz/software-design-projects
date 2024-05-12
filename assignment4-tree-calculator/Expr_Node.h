//==============================================================================
/**
 * @file       Expr_Node.h
 *
 * $Id: Expr_Node.h $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _EXPR_NODE_H_
#define _EXPR_NODE_H_

#include "Expr_Node_Visitor.h"

/**
 * @class Expr_Node
 *
 * Base class for all node types in expression tree.
 */
class Expr_Node
{
public:
  /// Default constructor.
  Expr_Node (void);

  /// Default destructor.
  virtual ~Expr_Node (void);

  /// Used to evaluate a node.
  virtual int eval (void) = 0;

  /// Used to traverse the tree.
  virtual void accept (Expr_Node_Visitor & visitor) = 0;

  /// Get right child.
  virtual Expr_Node * get_right_child (void) = 0;

  /// Get left child.
  virtual Expr_Node * get_left_child (void) = 0;

  /// Set right child.
  virtual void set_right_child (Expr_Node * right) = 0;

  /// Set left child.
  virtual void set_left_child (Expr_Node * left) = 0;

  /// Get precedence of node.
  virtual int get_precedence (void) = 0;

  /// Get nested level of node.
  virtual int get_nested_level (void) = 0;

  /// Set nested level of node.
  virtual void set_nested_level (int nested) = 0;
};

#endif   // !defined _EXPR_NODE_H_