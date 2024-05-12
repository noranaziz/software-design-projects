//==============================================================================
/**
 * @file       Divide_Command.h
 *
 * $Id: Divide_Command.h $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _DIVIDE_COMMAND_H_
#define _DIVIDE_COMMAND_H_

#include "Expr_Command.h"
#include "Stack.h"

/**
 * @class Divide_Command
 *
 * Command class to simplify execution of the division operation.
 */
class Divide_Command : public Expr_Command
{
public:
  /// Initializing constructor.
  Divide_Command (Stack <int> & s);

  /// Get precedence of the command.
  virtual int get_precedence (void);

  // Get parenthesis level of the command.
  virtual int get_nested_level (void);

  /// Set parenthesis level of the command.
  virtual void set_nested_level (int level);

  /// Virtual method to execute the operation.
  virtual void execute (void); 

private:
  Stack <int> & stack_;
  int nested_level;
};

#endif   // !defined _DIVIDE_COMMAND_H_