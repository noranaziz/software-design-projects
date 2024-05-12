//==============================================================================
/**
 * @file       Add_Command.h
 *
 * $Id: Add_Command.h $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _ADD_COMMAND_H_
#define _ADD_COMMAND_H_

#include "Expr_Command.h"
#include "Stack.h"

/**
 * @class Add_Command
 *
 * Command class to simplify execution of the addition operation.
 */
class Add_Command : public Expr_Command
{
public:
  /// Initializing constructor.
  Add_Command (Stack <int> & s);

  /// Get precedence of the command.
  virtual int get_precedence (void);

  /// Get parenthesis level of the command.
  virtual int get_nested_level (void);

  /// Set parenthesis level of the command.
  virtual void set_nested_level (int level);

  /// Virtual method to execute the operation.
  virtual void execute (void);

private:
  Stack <int> & stack_;
  int nested_level;
};

#endif   // !defined _ADD_COMMAND_H_