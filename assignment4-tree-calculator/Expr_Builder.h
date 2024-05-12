//==============================================================================
/**
 * @file       Expr_Builder.h
 *
 * $Id: Expr_Builder.h $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _EXPR_BUILDER_H_
#define _EXPR_BUILDER_H_

#include "Math_Expr.h"

/**
 * @class Expr_Builder
 *
 * Builder class.
 */
class Expr_Builder
{
public:
  /// Default constructor.
  Expr_Builder (void);

  /// Default destructor.
  virtual ~Expr_Builder (void) = 0;

  /// Methods to build each part of the expression tree.
  virtual void start_expression (void) = 0;
  virtual void build_number (int n) = 0;
  virtual void build_add_operator (void) = 0;
  virtual void build_subtract_operator (void) = 0;
  virtual void build_multiply_operator (void) = 0;
  virtual void build_divide_operator (void) = 0;
  virtual void build_modulus_operator (void) = 0;
  virtual void build_open_parenthesis (void) = 0;
  virtual void build_close_parenthesis (void) = 0;
  virtual void end_expression (void) = 0;

  /// Get current expression.
  virtual Math_Expr * get_expression (void) = 0;
};

#endif   // !defined _EXPR_BUILDER_H_