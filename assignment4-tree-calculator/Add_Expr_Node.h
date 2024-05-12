//==============================================================================
/**
 * @file       Add_Expr_Node.h
 *
 * $Id: Add_Expr_Node.h $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _ADD_EXPR_NODE_H_
#define _ADD_EXPR_NODE_H_

#include "Binary_Expr_Node.h"
class Expr_Node_Visitor;

/**
 * @class Add_Expr_Node
 *
 * Class for addition node types.
 */
class Add_Expr_Node : public Binary_Expr_Node
{
public:
  /// Default constructor.
  Add_Expr_Node (void);

  /// Initializing constructor.
  Add_Expr_Node (Expr_Node * node1, Expr_Node * node2);

  /// Destructor.
  virtual ~Add_Expr_Node (void);

  /// Virtual method to evaluate node.
  virtual int eval (void);

  /// Virtual method to visit node.
  virtual void accept (Expr_Node_Visitor & visitor);
};

#endif   // !defined _ADD_EXPR_NODE_H_