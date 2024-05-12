//==============================================================================
/**
 * @file       Unary_Expr_Node.h
 *
 * $Id: Unary_Expr_Node.h $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _UNARY_NODE_H_
#define _UNARY_NODE_H_

#include "Expr_Node.h"

/**
 * @class Unary_Expr_Node
 *
 * Class for unary node types.
 */
class Unary_Expr_Node : public Expr_Node
{
public:
  /// Default constructor.
  Unary_Expr_Node (void);

  /// Default destructor.
  virtual ~Unary_Expr_Node (void);

  /// Get child.
  virtual Expr_Node * get_child (void);

  /// Set child.
  virtual void set_child (Expr_Node * child);

private:
  Expr_Node * child_;
};

#endif   // !defined _UNARY_NODE_H_