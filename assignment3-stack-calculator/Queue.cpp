// $Id: Queue.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
#include "Queue.h"
#define default_size_ 7

//
// Queue
//
// DEFAULT CTOR
template <typename T>
Queue <T>::Queue (void)
    : queue_ (default_size_),
      size_ (0),
      front_ (0)
{

}

//
// Queue
//
// COPY CTOR
template <typename T>
Queue <T>::Queue (const Queue & queue)
    : queue_ (queue.queue_),
      size_ (queue.size_),
      front_ (queue.front_)
{

}

//
// ~Queue
//
template <typename T>
Queue <T>::~Queue (void)
{
    // queue_'s destructor will automatically be called 
}

//
// enqueue
//
template <typename T>
void Queue <T>::enqueue (T element)
{
    // resize queue to accomodate the new element.
    size_t new_size = front_ + size_ + 1;
    queue_.resize(new_size);
    size_++;

    // assign new element to the back of the queue (end of the array).
    size_t new_position_ = front_ + size_ - 1;
    queue_[new_position_] = element;
}

//
// dequeue
//
template <typename T>
T Queue <T>::dequeue (void)
{
    // check if queue is empty
    if(is_empty()) {
        throw empty_exception();
    }
    
    // COMMENT This design is OK, but it is not the best design. This will be
    // a very expensive array to use if you are dequeing a lot of elements. This
    // is because you are copying N elements each time you dequeue 1 element.
    // Instead, you only want to copy element when necessary. Come up with a better
    // design that is not as expensive for the client to use.

    // RESPONSE I added a new private member variable called front_ to keep track of
    // whatever element needs to be dequeued. This avoids the need to copy N elements 
    // on every dequeue. The front index is updated, and the size is reduced, ensuring
    // efficient space management.

    // store first element (front of the array).
    T first_ = queue_[front_];

    // remove element by updating front_ and size_.
    front_++;
    size_--;

    return first_;
}

//
// operator =
//
template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
    // check for self assignment.
    if(this == &rhs) {
        return *this;
    }
    
    // set this to rhs.
    size_ = rhs.size_;
    queue_.resize(size_);
    queue_ = rhs.queue_;

    return *this;
}

//
// clear
//
template <typename T>
void Queue <T>::clear (void)
{
    // resize the queue to size 0.
    size_ = 0;
    queue_.resize(size_);
    front_ = 0;
}
