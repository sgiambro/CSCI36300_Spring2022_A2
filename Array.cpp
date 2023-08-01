// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception
#include <iostream>

//
// Array
//
template <typename T>
Array <T>::Array (void)
{}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length)
: Basic_Array(length)
{}

//
// Array (size_t, T)
//
template <typename T>
Array <T>::Array (size_t length, T fill)
: Basic_Array(length , fill)
{}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array)
: Basic_Array(array)
{}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{

    if(this != &rhs){

        delete [] this->data_;
        this->data_ = new T [rhs.max_size_];

        for(int i = 0; i< rhs.cur_size_; i++){
            this->data_[i] = rhs.data_[i];
        }

        this->cur_size_ = rhs.cur_size_;
        this->max_size_ = rhs.max_size_;
    }

    return *this;
}

//
// operator []
//
template <typename T>
T & Array <T>::operator [] (size_t index)
{

    try{
        if(index > this->cur_size_){
            throw 999;
        }
        return *(this->data_ + index);
    }
    catch(int oor){
        std::cout << "--INDEX OUT OF RANGE--" << std::endl;
    }
}

//
// operator [] 
//
template <typename T>
const T & Array <T>::operator [] (size_t index) const
{
    try{
        if(index > cur_size_){
            throw 999;
        }
        return *(this->data_ + index);
    }
    catch(int oor){
        std::cout << "--INDEX OUT OF RANGE--" << std::endl;
    }
}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{

    if(new_size == 0){
        delete [] data_;
        data_ = new T [10];

        max_size_ = 10;
        cur_size_ = 10;
        
    }
    else if (new_size < max_size_){
        cur_size_ = new_size;
    }
    else if (new_size > max_size_)
    {
        T * temp = new T [new_size];
        for(int i=0; i<cur_size_; i++){
            temp[i] = data_[i];
        }

        delete [] data_;
        data_ = temp;
        
        // COMMENT You code will eventually crash because you are deleting
        // the memory you just stored in data_.
        // 
        // Solution: Removed the deletion of temp's memory

        max_size_ = new_size;
        cur_size_ = new_size;
    }
}

//
// operator ==
//
template <typename T>
bool Array <T>::operator == (const Array & rhs) const
{
  
    if (this->cur_size_ != rhs.cur_size_){
        return false;
    }

    for(int i = 0; i<this->cur_size_; i++){
        if(this->data_[i] != rhs.data_[i]){
            return false;
        }
    }

    return true;
    
}

//
// operator !=
//
template <typename T>
bool Array <T>::operator != (const Array & rhs) const
{

    if (this->cur_size_ != rhs.cur_size_){
        return true;
    }

    for(int i = 0; i<this->cur_size_; i++){
        if(this->data_[i] != rhs.data_[i]){
            return true;
        }
    }

    return false;
}
