// -*- C++ -*-
// $Id: Base_Array.inl 828 2011-02-07 14:21:52Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// size
//
template <typename T>
inline
size_t Base_Array <T>::size (void) const
{
    return cur_size_;
}