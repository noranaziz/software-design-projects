//==============================================================================
/**
 * @file       Divide_Expr_Node.h
 *
 * $Id: Divide_Expr_Node.h $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _DIVIDE_EXPR_NODE_H_
#define _DIVIDE_EXPR_NODE_H_

#include "Binary_Expr_Node.h"

/**
 * @class Divide_Expr_Node
 *
 * Class for division node types.
 */
class Divide_Expr_Node : public Binary_Expr_Node
{
public:
  /// Default constructor.
  Divide_Expr_Node (void);

  /// Initializing constructor.
  Divide_Expr_Node (Expr_Node * node1, Expr_Node * node2);

  /// Destructor.
  virtual ~Divide_Expr_Node (void);

  /// Virtual method to evaluate node.
  virtual int eval (void);

  /// Virtual method to visit node.
  virtual void accept (Expr_Node_Visitor & visitor);
};

#endif   // !defined _DIVIDE_EXPR_NODE_H_