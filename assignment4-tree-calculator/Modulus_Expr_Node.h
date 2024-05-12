//==============================================================================
/**
 * @file       Modulus_Expr_Node.h
 *
 * $Id: Modulus_Expr_Node.h $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _MODULUS_EXPR_NODE_H_
#define _MODULUS_EXPR_NODE_H_

#include "Binary_Expr_Node.h"

/**
 * @class Modulus_Expr_Node
 *
 * Class for modulus node types.
 */
class Modulus_Expr_Node : public Binary_Expr_Node
{
public:
  /// Default constructor.
  Modulus_Expr_Node (void);

  /// Initializing constructor.
  Modulus_Expr_Node (Expr_Node * num1, Expr_Node * num2);

  /// Destructor.
  virtual ~Modulus_Expr_Node (void);

  /// Virtual method to evaluate node.
  virtual int eval (void);

  /// Virtual method to visit node.
  virtual void accept (Expr_Node_Visitor & visitor);
};

#endif   // !defined _MODULUS_EXPR_NODE_H_