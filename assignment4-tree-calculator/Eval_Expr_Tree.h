//==============================================================================
/**
 * @file       Eval_Expr_Tree.h
 *
 * $Id: Eval_Expr_Tree.h $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _EVAL_EXPR_TREE_H_
#define _EVAL_EXPR_TREE_H_

#include "Add_Expr_Node.h"
#include "Subtract_Expr_Node.h"
#include "Multiply_Expr_Node.h"
#include "Divide_Expr_Node.h"
#include "Modulus_Expr_Node.h"
#include "Number_Expr_Node.h"
#include "Expr_Node_Visitor.h"
#include "Stack.h"

/**
 * @class Eval_Expr_Tree
 *
 * Class that evaluates expression tree by visiting elements.
 */
class Eval_Expr_Tree : public Expr_Node_Visitor
{
public:
  /// Default constructor.
  Eval_Expr_Tree (void);

  /// Default destructor.
  virtual ~Eval_Expr_Tree (void);

  /// Methods for visiting concrete nodes.
  virtual void Visit_Addition_Node (Add_Expr_Node & node);
  virtual void Visit_Subtraction_Node (Subtract_Expr_Node & node);
  virtual void Visit_Multiplication_Node (Multiply_Expr_Node & node);
  virtual void Visit_Division_Node (Divide_Expr_Node & node);
  virtual void Visit_Modulus_Node (Modulus_Expr_Node & node);
  virtual void Visit_Number_Node (Number_Expr_Node & node);

  int result (void);

private:
  // result of evaluating expression tree
  int result_;

  // stack that keeps track of the values
  Stack<int> * stack_;

  // numbers taken out of stack after visiting
  int num1_;
  int num2_;
};

#endif   // !defined _EVAL_EXPR_TREE_H_