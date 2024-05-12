//==============================================================================
/**
 * @file       Expr_Node_Visitor.h
 *
 * $Id: Expr_Node_Visitor.h $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _EXPR_NODE_VISITOR_H_
#define _EXPR_NODE_VISITOR_H_
/*
#include "Add_Expr_Node.h"
#include "Subtract_Expr_Node.h"
#include "Multiply_Expr_Node.h"
#include "Divide_Expr_Node.h"
#include "Modulus_Expr_Node.h"
#include "Number_Expr_Node.h"*/

class Add_Expr_Node;
class Subtract_Expr_Node;
class Multiply_Expr_Node;
class Divide_Expr_Node;
class Modulus_Expr_Node;
class Number_Expr_Node;


/**
 * @class Expr_Node_Visitor
 *
 * Visitor interface for all node types in expression tree.
 */
class Expr_Node_Visitor
{
public:
  /// Methods for visiting concrete nodes.
  virtual void Visit_Addition_Node (Add_Expr_Node & node) = 0;
  virtual void Visit_Subtraction_Node (Subtract_Expr_Node & node) = 0;
  virtual void Visit_Multiplication_Node (Multiply_Expr_Node & node) = 0;
  virtual void Visit_Division_Node (Divide_Expr_Node & node) = 0;
  virtual void Visit_Modulus_Node (Modulus_Expr_Node & node) = 0;
  virtual void Visit_Number_Node (Number_Expr_Node & node) = 0;
};

#endif   // !defined _EXPR_NODE_VISITOR_H_