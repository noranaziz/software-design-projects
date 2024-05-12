// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
#include "Stack.h"
#define default_size_ 7

//
// Stack
//
// DEFAULT CTOR
template <typename T>
Stack <T>::Stack (void)
    : stack_ (default_size_),
      size_ (0)
{

}

//
// Stack
//
// COPY CTOR
template <typename T>
Stack <T>::Stack (const Stack & stack)
    : stack_ (stack.stack_),
      size_ (stack.size_)
{

}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
    // stack_'s destructor will automatically be called 
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
    // resize stack to accomodate new element.
    size_++;
    stack_.resize(size_);

    // assign new element to the top of the stack (end of the array).
    stack_[size_ - 1] = element;
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
    // check if the stack is empty.
    if(is_empty()) {
        throw empty_exception();
    }

    // resize the stack to remove the top element.
    size_--;
    stack_.resize(size_);
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
    // check for self assignment.
    if(this == &rhs) {
        return *this;
    }
    
    // set this to rhs.
    size_ = rhs.size_;
    stack_.resize(size_);
    stack_ = rhs.stack_;

    return *this;
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
    // resize stack to size 0.
    size_ = 0;
    stack_.resize(size_);
}
