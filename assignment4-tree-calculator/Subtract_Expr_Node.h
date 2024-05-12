//==============================================================================
/**
 * @file       Subtract_Expr_Node.h
 *
 * $Id: Subtract_Expr_Node.h $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _SUBTRACT_EXPR_NODE_H_
#define _SUBTRACT_EXPR_NODE_H_

#include "Binary_Expr_Node.h"

/**
 * @class Subtract_Expr_Node
 *
 * Class for subtraction node types.
 */
class Subtract_Expr_Node : public Binary_Expr_Node
{
public:
  /// Default constructor.
  Subtract_Expr_Node (void);

  /// Initializing constructor.
  Subtract_Expr_Node (Expr_Node * num1, Expr_Node * num2);

  /// Destructor.
  virtual ~Subtract_Expr_Node (void);

  /// Virtual method to evaluate node.
  virtual int eval (void);

  /// Virtual method to visit node.
  virtual void accept (Expr_Node_Visitor & visitor);
};

#endif   // !defined _SUBTRACT_EXPR_NODE_H_