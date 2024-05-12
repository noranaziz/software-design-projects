//==============================================================================
/**
 * @file       Expr_Command.h
 *
 * $Id: Expr_Command.h $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _EXPR_COMMAND_H_
#define _EXPR_COMMAND_H_

#include <string>

/**
 * @class Expr_Command
 *
 * Command class to simplify execution of operations.
 */
class Expr_Command
{
public:
  /// Virtual method to execute an operation.
  virtual void execute (void) = 0;

  /// Get precedence of the command.
  virtual int get_precedence (void) = 0;

  /// Get parenthesis level of the command.
  virtual int get_nested_level (void) = 0;

  /// Set parenthesis level of the command.
  virtual void set_nested_level (int level) = 0;
};

#endif   // !defined _EXPR_COMMAND_H_