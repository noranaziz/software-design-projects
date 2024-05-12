//==============================================================================
/**
 * @file       Stack_Expr_Command_Factory.h
 *
 * $Id: Stack_Expr_Command_Factory.h $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef STACK_EXPR_COMMAND_FACTORY_H_
#define STACK_EXPR_COMMAND_FACTORY_H_

#include "Expr_Command_Factory.h"

/**
 * @class Stack_Expr_Command_Factory
 *
 * Abstract Factory class to create concrete commands.
 */
class Stack_Expr_Command_Factory : public Expr_Command_Factory
{
public:
  /// Initializing constructor.
  Stack_Expr_Command_Factory (Stack <int> & stack);

  /// Destructor.
  virtual ~Stack_Expr_Command_Factory (void);

  /// Number command constructor.
  virtual Number_Command * create_number_command (int num);

  /// Add command constructor.
  virtual Add_Command * create_add_command (void);

  /// Subtract command constructor.
  virtual Subtract_Command * create_subtract_command (void);

  /// Multiply command constructor.
  virtual Multiply_Command * create_multiply_command (void);

  /// Divide command constructor.
  virtual Divide_Command * create_divide_command (void);

  /// Modulus command constructor.
  virtual Modulus_Command * create_modulus_command (void);

private:
  Stack <int> & stack_;
};

#endif   // !defined STACK_EXPR_COMMAND_FACTORY_H_