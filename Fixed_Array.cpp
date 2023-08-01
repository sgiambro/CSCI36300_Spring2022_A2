// $Id: Fixed_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Fixed_Array
//

#include "Fixed_Array.h"
#include <iostream>

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void)
: fixed_size_    (10)
{}

//
// Fixed_Array (const Fixed_Array <T, N> &)
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> & arr)
: fixed_size_   (N),
  Basic_Array(arr)
{}


//
// Fixed_Array (T)
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill)
: fixed_size_   (10),
  Basic_Array(10 , fill)
{}

//
//  ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
{}

//
//  operator =
//
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{

    if(this != &rhs){

        delete [] this->data_;
        this->data_ = new T [rhs.max_size_];

        for(int i = 0; i< rhs.cur_size_; i++){
            this->data_[i] = rhs.data_[i];
        }

        this->cur_size_ = rhs.cur_size_;
        this->max_size_ = rhs.max_size_;
        this->fixed_size_ = rhs.fixed_size_;
    }

    return *this;
}

