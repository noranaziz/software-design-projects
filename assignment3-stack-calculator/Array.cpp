// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception
#define default_size_ 7

//
// Array
//
// DEFAULT CTOR
// call the default ctor of the base array class.
// set the max_size_ to the default size.
template <typename T>
Array <T>::Array (void)
    : Base_Array<T> (),
      max_size_ (default_size_)
{

}

//
// Array (size_t)
//
// LENGTH PARAM CTOR
// call the length ctor of the base array class.
// set the max_size_ to the specified length.
template <typename T>
Array <T>::Array (size_t length)
    : Base_Array<T> (length),
      max_size_ (length)
{

}

//
// Array (size_t, char)
//
// LENGTH, FILL PARAM CTOR
// call the length, T ctor of the base array class.
// set the max_size_ to the specified length.
template <typename T>
Array <T>::Array (size_t length, T fill)
    : Base_Array<T> (length, fill),
      max_size_ (length)
{

}

//
// Array (const Array &)
//
// COPY CTOR
// call the copy ctor of the base array class.
// copy the max_size_ from the source array.
template <typename T>
Array <T>::Array (const Array & array)
    : Base_Array<T> (array),
      max_size_ (array.max_size_)
{

}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
    // uses Base_Array's destructor.
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
    // check for self-assignment.
    if(this == &rhs) {
        return *this;
    }

    // if the max size is less than the source's max size, reallocate memory.
    if(max_size_ < rhs.max_size_) {
        delete[] this->data_;
        max_size_ = rhs.max_size_;
        this->data_ = new T[max_size_];
    }

    this->cur_size_ = rhs.cur_size_;

    // copy elements from the source array.
    for(size_t i = 0; i < this->cur_size_; i++) {
        this->data_[i] = rhs.data_[i];
    }

    return *this;
}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
    // if the new size is smaller or within the current max size, update the current size.
    if(new_size < this->cur_size_ || (new_size > this->cur_size_ && new_size <= max_size_)) {
        this->cur_size_ = new_size;
    } else if(new_size > max_size_) { 
        // if the new size is larger than the max size, reallocate memory.
        T * new_data_ = new T[new_size];

        // copy elements from the current array to the new array.
        for(size_t i = 0; i < this->cur_size_; i++) {
            new_data_[i] = this->data_[i];
        }

        this->cur_size_ = new_size;
        max_size_ = new_size;
        delete[] this->data_;
        this->data_ = new_data_;
    }
}

// 
// shrink
//
template <typename T>
void Array <T>::shrink (void)
{
    // if the current size is less than the max size, reallocate memory.
    if(this->cur_size_ < max_size_) {
        T * new_data_ = new T[this->cur_size_];

        // copy elements from the current array to the new array.
        for(size_t i = 0; i < this->cur_size_; i++) {
            new_data_[i] = this->data_[i];
        }

        delete[] this->data_;
        this->data_ = new_data_;
        max_size_ = this->cur_size_;
    }
}