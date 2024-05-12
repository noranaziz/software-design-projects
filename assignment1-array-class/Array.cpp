// $Id: Array.cpp 820 2011-01-17 15:30:41Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <stdexcept> // for exceptions

// DEFAULT CTOR
// initializes private data members
Array::Array (void)
    : cur_size_ (0),
      max_size_ (1),
      data_ (nullptr)
{

}

// LENGTH PARAM CTOR
// initializes private data members w/ length.
// if length is not a valid param (negative/0), then an exception is thrown.
// otherwise, the elements in data_ are initialized to a default char (A).
Array::Array (size_t length)
    : cur_size_(length), 
      max_size_ (length), 
      data_ (nullptr)
{
    if(static_cast<ssize_t>(length) <= 0 ) {
        throw std::invalid_argument("Array length must be greater than 0");
    }

    data_ = new char[length];
    fill('A');
}

// LENGTH, CHAR PARAM CTOR
// initializes private data members w/ length.
// if length is not a valid param (is negative or 0), then an exception is thrown.
// otherwise, the elements in data_ are initialized to the fill param.
Array::Array (size_t length, char fill)
    : cur_size_ (length),
      max_size_ (length),
      data_ (nullptr)
{
    if(static_cast<ssize_t>(length) <= 0) {
        throw std::invalid_argument("Array length must be greater than 0");
    }

    data_ = new char[length];
    this->fill(fill);
}

// COPY CTOR
// initializes private data members w/ array's members.
// the contents of array is copied into the new array's data_.
Array::Array (const Array & array)
    : cur_size_ (array.cur_size_),
      max_size_ (array.max_size_),
      data_ (new char[array.max_size_])
{
    for (size_t i = 0; i < cur_size_; i++) {
        data_[i] = array.data_[i];
    }
}

// DESTRUCTOR
// deallocates data_.
Array::~Array (void)
{
    delete[] data_;
    
    // COMMENT There is no need to reset the data_ variable since this object is no
    // longer useable after the desturctor returns.
    // RESPONSE I deleted data_ = nullptr.
}

// OPERATOR = OVERLOAD
// similar to copy ctor.
// sets private data members to rhs's members.
// copies contents of rhs to data_.
const Array & Array::operator = (const Array & rhs)
{
    if(this != &rhs) {
        // COMMENT You should only change the allocation size of this array is not
        // large enough to hold rhs.
        // RESPONSE I added an if statement to check if the maximum size of this array 
        // is smaller than rhs's max size. If it is, then data_ is reallocated with the 
        // new max size.
        if(max_size_ < rhs.max_size_) {
            delete[] data_;
            max_size_ = rhs.max_size_;
            data_ = new char[max_size_];
        }

        cur_size_ = rhs.cur_size_;

        for(size_t i = 0; i < cur_size_; i++) {
            data_[i] = rhs.data_[i];
        }
    }

    return *this;
}

// OPERATOR [] OVERLOAD
// if the index is outside the valid range (beyond data_'s bounds), an exception is thrown.
// otherwise, the element at the specified index is returned.
// this can be used to "get" and "set".
char & Array::operator [] (size_t index)
{
    if(index >= cur_size_) {
        throw std::out_of_range("Index out of range");
    }

    return data_[index];
}

// OPERATOR [] OVERLOAD
// if the index is outside the valid range (beyond data_'s bounds), an exception is thrown.
// otherwise, the element at the specified index is returned.
// this can be used to "get", but NOT "set".
const char & Array::operator [] (size_t index) const
{
    if(index >= cur_size_) {
        throw std::out_of_range("Index out of range");
    }

    return data_[index];
}

// GETTER
// if the index is outside the valid range (beyond data_'s bounds), an exception is thrown.
// otherwise, the element at the specified index is returned.
char Array::get (size_t index) const
{
    if(index >= cur_size_) {
        throw std::out_of_range("index is out of range");
    }

    return data_[index];
}

// SETTER
// if the index is outside the valid range (beyond data_'s bounds), an exception is thrown.
// otherwise, the element at the specified index is set to the value param.
void Array::set (size_t index, char value)
{
    if(index >= cur_size_) {
        throw std::out_of_range("index is out of range");
    }

    data_[index] = value;
}

// RESIZE
// adjusts the array size to new_size.
// if new_size is smaller than the current size, the array is truncated.
// if new_size is larger than the current size but smaller than the maximum size, current size is updated.
// if new_size is larger than the max size, the array is made larger.
void Array::resize (size_t new_size)
{
    if(new_size < cur_size_ || (new_size > cur_size_ && new_size <= max_size_)) {
        cur_size_ = new_size;
    } else if(new_size > max_size_) { 
        char * new_data_ = new char[new_size];

        for(size_t i = 0; i < cur_size_; i++) {
            new_data_[i] = data_[i];
        }

        max_size_ = new_size;
        delete[] data_;
        data_ = new_data_;
    }
}

// FIND
// searches for the first occurence of ch.
// if ch is not found, returns -1.
int Array::find (char ch) const
{
    for(size_t i = 0; i < cur_size_; i++) {
        if(data_[i] == ch) {
            return  i;
        }
    }

    return -1;
}

// OVERLOADED FIND
// searches for the first occurence of ch starting from the given index start
// if ch is not found, returns -1.
int Array::find (char ch, size_t start) const
{
    if(start >= cur_size_) {
        throw std::out_of_range("index is out of range");
    }

    for(size_t i = start; i < cur_size_; i++) {
        if(data_[i] == ch) {
            return  i;
        }
    }

    return -1;
}

// EQUALITY OPERATOR
// checks if the current array is equal to rhs.
// two arrays are considered equal if they have the same current size,
// the same max size, and if their data_ elements are equal.
bool Array::operator == (const Array & rhs) const
{
    // COMMENT Check for self comparison first.
    // RESPONSE I added an if statement that compares this array's 
    // address with rhs's address. If they have the same address, 
    // then they are the same.

    if(this == &rhs) {
        return true;
    }

    if(cur_size_ != rhs.cur_size_) {
        return false;
    }

    if(max_size_ != rhs.max_size_) {
        return false;
    }

    for(size_t i = 0; i < rhs.cur_size_; i++) {
        if(data_[i] != rhs.data_[i]) {
            return false;
        }
    }

    return true;
}

// INEQUALITY OPERATOR
// checks if the current array is not equal to rhs.
// two arrays are considered not equal if they have different current sizes,
// different max sizes, or if their data_ elements are not equal.
bool Array::operator != (const Array & rhs) const
{
    // COMMENT You can define operator != in terms of operator ==.
    // RESPONSE I condensed the code into only a single line 
    // to define this operator in terms of operator ==.

    return !(*this == rhs);
}

// FILL
// sets each element of the array to ch.
void Array::fill (char ch)
{
    for(size_t i = 0; i < cur_size_; i++) {
        data_[i] = ch;
    }
}

// SHRINK
// shrinks the array to reclaim unused space.
// allocates new memory, copies existing elements, deallocates old memory,
// and updates the array's data pointer and max size to match the current size.
void Array::shrink (void)
{
    // COMMENT You should use the cur_size_ and max_size_ to determine if you
    // must shrink the array allocation.
    // RESPONSE I added an if statement to check if the current size
    // is less than max size. The array is shrunk only if that requirement is met.
    
    if(cur_size_ < max_size_) {
        char * new_data_ = new char[cur_size_];

        for(size_t i = 0; i < cur_size_; i++) {
            new_data_[i] = data_[i];
        }

        delete[] data_;
        data_ = new_data_;
        max_size_ = cur_size_;
    }
}

// REVERSE
// reverses the order of elements in the array.
// uses a single for loop to swap elements.
void Array::reverse (void)
{
    // COMMENT There is no need to create a copy of the array to reverse its contents
    // RESPONSE I instead used a for loop with 2 variables, i and j, 
    // each traversing the array in opposite directions to swap each element.

    for(size_t i = 0, j = cur_size_ - 1; i < j; i++, j--) {
        char temp = data_[i];
        data_[i] = data_[j];
        data_[j] = temp;
    }
}

// SLICE
// returns a shallow copy of a portion of the array into a new array object
// selected from begin index to the current size of the array.
// the original array is not modified; throws an exception if begin is out of range.
Array Array::slice (size_t begin) const
{
    if(begin >= cur_size_) {
        throw std::out_of_range("index is out of range");
    }

    size_t length = cur_size_ - begin;
    Array slice(length);

    for(size_t i = 0; i < length; i++) {
        slice.data_[i] = data_[begin + i];
    }

    return slice;
}

// OVERLOADED SLICE
// returns a shallow copy of a portion of the array into a new array object
// selected from begin to end (both indices included).
// the orignal array is not modified; throws an exception if begin or end is out of range.
// if begin is greater than end, the indices are swapped.
Array Array::slice (size_t begin, size_t end) const
{
    if(begin >= cur_size_ || end >= cur_size_) {
        throw std::out_of_range("indices are out of range");
    }

    if(begin > end) {
        size_t temp = begin;
        begin = end;
        end = temp;
    }

    size_t length = end - begin + 1;
    Array slice(length);

    for(size_t i = 0; i < length; i++) {
        slice.data_[i] = data_[begin + i];
    }

    return slice;
}
