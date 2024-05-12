//==============================================================================
/**
 * @file       Expr_Command_Factory.h
 *
 * $Id: Expr_Command_Factory.h $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _EXPR_COMMAND_FACTORY_H_
#define _EXPR_COMMAND_FACTORY_H_

#include "Number_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Modulus_Command.h"

/**
 * @class Expr_Command_Factory
 *
 * Abstract Factory class to create commands when converting
 * from infix to postfix.
 */
class Expr_Command_Factory
{
public:
  /// Constructor.
  Expr_Command_Factory (void);
  
  /// Virtual destructor.
  virtual ~Expr_Command_Factory (void) = 0;

  /// Number command constructor.
  virtual Number_Command * create_number_command (int num) = 0;

  /// Add command constructor.
  virtual Add_Command * create_add_command (void) = 0;

  /// Subtract command constructor.
  virtual Subtract_Command * create_subtract_command (void) = 0;

  /// Multiply command constructor.
  virtual Multiply_Command * create_multiply_command (void) = 0;

  /// Divide command constructor.
  virtual Divide_Command * create_divide_command (void) = 0;

  /// Modulus command constructor.
  virtual Modulus_Command * create_modulus_command (void) = 0;

private:
  // prevent client from using these operations.
  Expr_Command_Factory (const Expr_Command_Factory &);
  const Expr_Command_Factory & operator = (const Expr_Command_Factory &);
};

#endif   // !defined _EXPR_COMMAND_FACTORY_H_