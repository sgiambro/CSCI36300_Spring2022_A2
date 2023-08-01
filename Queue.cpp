// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Queue.h"
#include <stdexcept>
#include <iostream>

//
// Queue
//
template <typename T>
Queue <T>::Queue (void)
: first_     (0),
  last_      (0),
  array_()
{}

//
// Queue
//
template <typename T>
Queue <T>::Queue (const Queue & q)
: first_     (q.first_),
  last_      (q.last_),
  array_(q.array_)
{}

//
// ~Queue
//
template <typename T>
Queue <T>::~Queue (void)
{}

//
// enqueue
//
template <typename T>
void Queue <T>::enqueue (T element)
{
    // COMMENT The queue should grow if out of space.
    //
    // SOLUTION: If the queue is out of space then it will
    // resize itself to have more space

    if(this->last_ < array_->cur_size){
        last_++;
        array_->set((last_ - 1) , element);
    }
    else{
        array_->resize(array_->cur_size_ + 10)
        last_++;
        array_->set((last_ - 1) , element);
    }
}

//
// dequeue
//
template <typename T>
void Queue <T>::dequeue (void)
{
    // COMMENT This solution will work, but you are wasting space at the front
    // of the array since those "unused" spaces will never be used again. Please
    // come up with a better design that uses memory more efficiently.
    //
    // SOLUTION: each time an element is removed the last position in the queue
    // and all elements are shifted left by one
    
    if(this->last_ > 0){
        last--;
        for(int i = 0 ; i < this->last_ - 1 ; i++){
            array_[i] = array[i + 1];
        }
    }
    else (){
        std::cout << "--QUEUE IS EMPTY--" << std::endl;
    }
}

//
// operator =
//
template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
    if(this != &rhs){

        array_->resize(rhs.array_->cur_size);

        for(int i = 0; i< rhs.array_->cur_size(); i++){
            array_->set(i , rhs.array_->get(i));
        }

        this->last_ = rhs.last_;
    }

    return *this;
}

//
// Queue
//
size_t Queue <T>::size (void)
{
    return last_;
}

//
// clear
//
template <typename T>
void Queue <T>::clear (void)
{
    last_ = 0;
}

