//==============================================================================
/**
 * @file       Calculator.h
 *
 * $Id: Calculator.h $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <iostream>
#include <sstream>

#include "Expr_Tree_Builder.h"

/**
 * @class Calculator
 *
 * Calculator class to implement commands and abstract factory classes.
 */
class Calculator
{
public:
  /// Default constructor.
  Calculator (void);

  /// Destructor.
  ~Calculator (void);

  /**
   * Get infix expression from user.
   * 
   * @return         Mathematical string in infix.
  */
  std::string get_infix (void);

  /**
   * Evaluate infix expression
   * 
   * @param[in]     infix         Infix expression.
   * @param[in]     builder       Builder for expression.
   * @return                      Result.
  */
  int evaluate_infix (std::string & infix, Expr_Builder & builder);

  /// calculate result of expression.
  void calculate (void);
};

#endif   // !defined _CALCULATOR_H_