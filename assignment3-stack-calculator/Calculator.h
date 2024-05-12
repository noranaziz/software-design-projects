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

#include "Stack.h"
#include "Queue.h"
#include "Array_Iterator.h"
#include "Expr_Command.h"
#include "Expr_Command_Factory.h"
#include "Stack_Expr_Command_Factory.h"

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
   * Convert infix to postfix
   *
   * @param[in]     infix         The input expression.
   * @param[in]     factory       Abstract Factory class.
   * @param[in]     postfix       The output expression.
   */
  void infix_to_postfix (const std::string & infix, Expr_Command_Factory & factory, Array <Expr_Command *> & postfix);

  /**
   * Evaluate postfix expression
   * 
   * @param[in]     postfix         Postfix expression.
  */
  void evaluate_postfix (Array<Expr_Command *> & postfix);

  /// calculate result of postfix expression.
  void calculate (void);
};

#endif   // !defined _CALCULATOR_H_