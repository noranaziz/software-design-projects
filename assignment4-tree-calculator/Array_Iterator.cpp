// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array_Iterator.h"
#include <stdexcept>         // for std::out_of_bounds exception

// Initializer
template <typename T>
Array_Iterator <T>::Array_Iterator (Array<T> & array)
    : array_ (array),
      curr_ (0)
{

}

// Destructor
template <typename T>
Array_Iterator <T>::~Array_Iterator (void)
{
    // array_'s destructor will automatically be called 
}

// is_done
template <typename T>
bool Array_Iterator <T>::is_done (void) 
{
    return curr_ >= array_.size();
}

// advance
template <typename T>
void Array_Iterator <T>::advance (void) 
{
    ++curr_;
}

// operator *
template <typename T>
T & Array_Iterator <T>::operator * (void) 
{
    return array_[curr_];
}

// operator ->
template <typename T>
T * Array_Iterator <T>::operator -> (void)
{
    return &array_[curr_];
}