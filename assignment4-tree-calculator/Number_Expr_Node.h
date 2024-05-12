//==============================================================================
/**
 * @file       Number_Expr_Node.h
 *
 * $Id: Number_Expr_Node.h $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _NUMBER_EXPR_NODE_H_
#define _NUMBER_EXPR_NODE_H_

#include "Binary_Expr_Node.h"

/**
 * @class Number_Expr_Node
 *
 * Class for number node types.
 */
class Number_Expr_Node : public Binary_Expr_Node
{
public:
  /// Default constructor.
  Number_Expr_Node (void);

  /// Intializing constructor.
  Number_Expr_Node (int number);

  /// Destructor.
  virtual ~Number_Expr_Node (void);

  /// Virtual method that returns the number the node represents.
  virtual int eval (void);

  /// Virtual method to visit node.
  virtual void accept (Expr_Node_Visitor & visitor);

private:
  int number_;
};

#endif   // !defined _NUMBER_EXPR_NODE_H_