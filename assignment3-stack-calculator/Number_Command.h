//==============================================================================
/**
 * @file       Number_Command.h
 *
 * $Id: Number_Command.h $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _NUMBER_COMMAND_H_
#define _NUMBER_COMMAND_H_

#include "Expr_Command.h"
#include "Stack.h"

/**
 * @class Number_Command
 *
 * Command class to push number to stack.
 */
class Number_Command : public Expr_Command
{
public:
  /// Initializing constructor.
  Number_Command (Stack <int> & s, int n);

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
  int num_;
};

#endif   // !defined _NUMBER_COMMAND_H_