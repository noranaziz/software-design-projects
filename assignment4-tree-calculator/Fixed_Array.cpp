// $Id: Fixed_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
#include "Fixed_Array.h"

//
// Fixed_Array
//
// DEFAULT CTOR
// call the default ctor of the base array class.
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void)
    : Base_Array<T> (N)
{

}

//
// Fixed_Array
//
// COPY CTOR
// call the copy ctor of the base array class.
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> & arr)
    : Base_Array<T> (arr)
{
	
}

//
// Fixed_Array
//
// FILL PARAM CTOR
// call the length, fill ctor of the base array class.
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill)
    : Base_Array<T> (N, fill)
{

}

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
{
    // automatically calls Base_Array destructor.
}

//
// operator =
//
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{
	// check for self assignment.
    if(this == &rhs) {
        return *this;
    }

    // copy elements from the source array to this array.
    for(size_t i = 0; i < N; i++) {
        (*this)[i] = rhs[i];
    }

    return *this;
}
