//==============================================================================
/**
 * @file       Array_Iterator.h
 *
 * $Id: Array_Iterator.h $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _ARRAY_ITERATOR_H_
#define _ARRAY_ITERATOR_H_

#include "Array.h"

#include <cstring>          // for size_t definition

/**
 * @class Array_Iterator
 *
 * Iterator class to simplify iteration of elements in Arrays.
 */
template <typename T>
class Array_Iterator
{
public:
  /// Type definition of the element type.
  typedef T type;

  /// Initializing constructor.
  Array_Iterator (Array<T> & array);

  /// Destructor.
  ~Array_Iterator (void);

  /**
   * Checks if iteration is done (has reached end of Array).
   *
   * @retval          true                 At end of the Array
   * @retval          false                Not at end of the Array
   */
  bool is_done (void);

  /// Advances to the next element in the Array.
  void advance (void);

  /**
   * Dereferences the iterator to access the element it currently points to.
   * 
   * @return          Reference to the element currently pointed to by the iterator
  */
  T & operator * (void);

  /**
   * Allows access to the elements of the Array pointed to by the iterator.
   * 
   * @return          Pointer to the Array currently pointed to by the iterator
  */
  T * operator -> (void);

private:
  /// Array that is iterated across.
  Array <T> & array_;
  
  /// current index of iterator.
  size_t curr_;
};

#include "Array_Iterator.cpp"

#endif   // !defined _ARRAY_ITERATOR_H_