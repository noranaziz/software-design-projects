//==============================================================================
/**
 * @file       Binary_Expr_Node.h
 *
 * $Id: Binary_Expr_Node.h $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _BINARY_NODE_H_
#define _BINARY_NODE_H_

#include "Expr_Node.h"
#include <stdexcept>

/**
 * @class Binary_Expr_Node
 *
 * Class for binary node types.
 */
class Binary_Expr_Node : public Expr_Node
{
public:
  /// Default constructor.
  Binary_Expr_Node (void);

  /// Initializing constructor.
  /// Sets the precedence of the node according to its type.
  Binary_Expr_Node (int precedence);

  /// Default destructor.
  virtual ~Binary_Expr_Node (void);

  /// Used to evaluate node.
  virtual int eval (void) = 0;

  /// Get right child.
  virtual Expr_Node * get_right_child (void);

  /// Get left child.
  virtual Expr_Node * get_left_child (void);

  /// Set right child.
  virtual void set_right_child (Expr_Node * right);

  /// Set left child.
  virtual void set_left_child (Expr_Node * left);

  /// Get precedence of node.
  int get_precedence (void);

  // Get nested level of node.
  int get_nested_level (void);

  /// Set nested level of node.
  void set_nested_level (int nested);

protected:
  Expr_Node * right_;
  Expr_Node * left_;
  int precendence_;
  int nested_;
};

#endif   // !defined _BINARY_NODE_H_