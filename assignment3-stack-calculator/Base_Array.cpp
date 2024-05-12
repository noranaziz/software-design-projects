// $Id: Base_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Base_Array.h"
#include <stdexcept>         // for std::out_of_bounds exception
#define default_size_ 7

//
// Base_Array
//
// DEFAULT CTOR
// initializes private data members.
template <typename T>
Base_Array <T>::Base_Array (void)
    : cur_size_ (default_size_),
      data_ (new T[default_size_]),
      shallow_copy_ (false)
{

}

//
// Base_Array (size_t)
//
// LENGTH PARAM CTOR
// initializes private data members.
template <typename T>
Base_Array <T>::Base_Array (size_t length)
    : cur_size_ (length),
      data_ (nullptr),
      shallow_copy_ (false)
{
    // check if length is invalid.
    if(static_cast<ssize_t>(length) <= 0) {
        throw std::invalid_argument("Array length must be greater than 0");
    }

    // allocate memory for the array and fill with default value.
    data_ = new T[length];
    fill(T());
}

//
// Base_Array (size_t, char)
//
// LENGTH, FILL PARAM CTOR
// initializes private data members.
template <typename T>
Base_Array <T>::Base_Array (size_t length, T fill)
    : Base_Array<T> (length)
{
    // fill the array with the specified value.
    this->fill(fill);
}

//
// Base_Array (const Base_Array &)
//
// COPY CTOR
// initializes private data members with array's members.
template <typename T>
Base_Array <T>::Base_Array (const Base_Array & array)
    : Base_Array<T> (array.cur_size_)
{
    // copy data from the source array to the current array.
    for(size_t i = 0; i < cur_size_; i++) {
        data_[i] = array.data_[i];
    }
}

//
// ~Array
//
template <typename T>
Base_Array <T>::~Base_Array (void)
{
    // check if this is not a shallow copy before deleting the array.
    if(shallow_copy_ == false) {
        delete[] data_;
    }
}

//
// operator =
//
template <typename T>
const Base_Array <T> & Base_Array <T>::operator = (const Base_Array & rhs)
{
    // check for self-assignment.
    if(this == &rhs) {
        return *this;
    }

    // if the current array is smaller than the source array, reallocate memory.
    cur_size_ = rhs.cur_size_;
    if(cur_size_ < rhs.cur_size_) {
        delete[] data_;
        data_ = new T[cur_size_];
    }

    // copy data from the source array to the current array.
    for(size_t i = 0; i < cur_size_; i++) {
        data_[i] = rhs.data_[i];
    }

    return *this;
}

//
// operator []
//
template <typename T>
T & Base_Array <T>::operator [] (size_t index)
{
    // check if the index is out of range.
    if(index >= cur_size_) {
        throw std::out_of_range("index out of range");
    }

    // return reference to the element at the specified index.
    return data_[index];
}

//
// operator [] 
//
template <typename T>
const T & Base_Array <T>::operator [] (size_t index) const
{
    // check if the index is out of range.
    if(index >= cur_size_) {
        throw std::out_of_range("index out of range");
    }

    // return constant reference to the element at the specified index.
    return data_[index];
}

//
// get
//
template <typename T>
T Base_Array <T>::get (size_t index) const
{
    // delegate to the operator[] method.
    return (*this)[index];
}

//
// set
//
template <typename T>
void Base_Array <T>::set (size_t index, T value)
{
    // delegate to the operator[] method.
    (*this)[index] = value;
}

//
// find (T)
//
template  <typename T>
int Base_Array <T>::find (T value) const
{
    // check if the array is empty.
    if(cur_size_ == 0) {
        throw std::out_of_range("array is empty");
    }

    // delegate to the find method with a starting index of 0.
    return find(value, 0);
}

//
// find (T, size_t) 
//
template <typename T>
int Base_Array <T>::find (T val, size_t start) const
{
    // check if the starting index is out of range.
    if(start >= cur_size_) {
        throw std::out_of_range("index is out of range");
    }

    // search for the specified value in the array starting from the given index.
    // if found, return the index of the value.
    // otherwise, return -1.
    for(size_t i = start; i < cur_size_; i++) {
        if(data_[i] == val) {
            return i;
        }
    }

    return -1;
}

//
// operator ==
//
template <typename T>
bool Base_Array <T>::operator == (const Base_Array & rhs) const
{
    // check for self-equality.
    if(this == &rhs) {
        return true;
    }

    // check if the sizes are different.
    if(cur_size_ != rhs.cur_size_) {
        return false;
    }

    // compare the contents of the arrays.
    for(size_t i = 0; i < rhs.cur_size_; i++) {
        if(data_[i] != rhs.data_[i]) {
            return false;
        }
    }

    return true;
}

//
// operator !=
//
template <typename T>
bool Base_Array <T>::operator != (const Base_Array & rhs) const
{
    // use the negation of the equality operator.
    return !(*this == rhs);
}

//
// fill
//
template <typename T>
void Base_Array <T>::fill (T value)
{
    // fill the array with the specified value.
    for(size_t i = 0; i < cur_size_; i++) {
        data_[i] = value;
    }
}

//
// reverse
//
template <typename T>
void Base_Array <T>::reverse (void) 
{
    // reverse the elements of the array.
    for(size_t i = 0, j = cur_size_ - 1; i < j; i++, j--) {
        T temp = data_[i];
        data_[i] = data_[j];
        data_[j] = temp;
    }
}

//
// slice
//
template <typename T>
Base_Array <T> Base_Array <T>::slice (size_t begin) const
{
    // delegate to the parameterized slice method with the current size as end.
    return slice(begin, cur_size_);
}

// 
// slice
//
template <typename T>
Base_Array <T> Base_Array <T>::slice (size_t begin, size_t end) const
{
    // check begin index
    if(begin >= cur_size_) {
        throw std::out_of_range("begin index is out of range");
    }

    // check end index
    if(end > cur_size_) {
        throw std::out_of_range("end index is out of range");
    }

    // swap indices if necessary
    if(begin > end) {
        size_t temp = begin;
        begin = end;
        end = temp;
    }

    // create shallow copy
    Base_Array slice;

    // data_ of slice points to starting index of original array
    delete[] slice.data_;
    slice.data_ = data_ + begin;
    slice.shallow_copy_ = true;

    // find new length of slice
    size_t length = end - begin;
    slice.cur_size_ = length;

    return slice;
}