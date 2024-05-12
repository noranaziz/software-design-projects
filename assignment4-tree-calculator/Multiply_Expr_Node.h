//==============================================================================
/**
 * @file       Multiply_Expr_Node.h
 *
 * $Id: Multiply_Expr_Node.h $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _MULTIPLY_EXPR_NODE_H_
#define _MULTIPLY_EXPR_NODE_H_

#include "Binary_Expr_Node.h"

/**
 * @class Multiply_Expr_Node
 *
 * Class for multiplication node types.
 */
class Multiply_Expr_Node : public Binary_Expr_Node
{
public:
  /// Default constructor.
  Multiply_Expr_Node (void);

  /// Initializing constructor.
  Multiply_Expr_Node (Expr_Node * num1, Expr_Node * num2);

  /// Destructor.
  virtual ~Multiply_Expr_Node (void);

  /// Virtual method to evaluate node.
  virtual int eval (void);

  /// Virtual method to visit node.
  virtual void accept (Expr_Node_Visitor & visitor);
};

#endif   // !defined _MULTIPLY_EXPR_NODE_H_