//==============================================================================
/**
 * @file       Math_Expr.h
 *
 * $Id: Math_Expr.h $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _MATH_EXPR_H_
#define _MATH_EXPR_H_

/**
 * @class Math_Expr
 *
 * Class for math expression.
 */
class Math_Expr
{
public:
  /// Default constructor.
  Math_Expr (void);

  /// Default destructor.
  virtual ~Math_Expr (void);

  /// Method to evaluate the math expression.
  virtual int eval (void) = 0;
};

#endif   // !defined _MATH_EXPR_H_