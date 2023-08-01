// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Basic_Array.h"
#include <stdexcept>         // for std::out_of_bounds exception
#include <iostream>

//
// Basic_Array
//
template <typename T>
Basic_Array <T>::Basic_Array (void)
: data_     (new T [10]),
  cur_size_ (10),
  max_size_ (10)
{}

//
// Basic_Array (size_t)
//
template <typename T>
Basic_Array <T>::Basic_Array (size_t length)
: data_     (new T [length]),
  cur_size_ (length),
  max_size_ (length)
{}

//
// Basic_Array (size_t, T)
//
template <typename T>
Basic_Array <T>::Basic_Array (size_t length, T fill)
: data_     (new T [length]),
  cur_size_ (length),
  max_size_ (length)
{
    for(int i = 0; i<cur_size_; i++){
        data_[i] = fill;
    }
}

//
// Basic_Array (const Basic_Array &)
//
template <typename T>
Basic_Array <T>::Basic_Array (const Basic_Array & array)
: data_     (new T [arr.max_size_]),
  cur_size_ (arr.cur_size_),
  max_size_ (arr.max_size_)
{   
    for(int i = 0; i<cur_size_; i++){
        data_[i] = arr.data_[i];
    }
}

//
// ~Basic_Array
//
template <typename T>
Basic_Array <T>::~Basic_Array (void)
{
    delete [] data_;
}

//
// operator =
//
template <typename T>
const Basic_Array <T> & Basic_Array <T>::operator = (const Basic_Array & rhs)
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
T & Basic_Array <T>::operator [] (size_t index)
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
const T & Basic_Array <T>::operator [] (size_t index) const
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
// get
//
template <typename T>
T Basic_Array <T>::get (size_t index) const
{

    try{
        if(index > cur_size_){
            throw 999;
        }
        return data_[index];
    }
    catch(int oor){
        std::cout << "--INDEX OUT OF RANGE--" << std::endl;
    }
}

//
// set
//
template <typename T>
void Basic_Array <T>::set (size_t index, T value)
{

    try{
        if(index > cur_size_){
            throw 999;
        }
        data_[index] = value;
    }
    catch(int oor){
        std::cout << "--INDEX OUT OF RANGE--" << std::endl;
    }

}

//
// size
//
size_t Basic_Array <T>::size (void) const{
    return cur_size_;
}

//
// max
//
size_t Basic_Array <T>::max (void) const{
    return max_size_;
}

//
// find (T)
//
template  <typename T>
int Basic_Array <T>::find (T value) const
{

    for(int i = 0; i<cur_size_; i++){
        if(data_[i] == value){
            return i;
        }
    }

    return -1;
}

//
// find (T, size_t) 
//
template <typename T>
int Basic_Array <T>::find (T val, size_t start) const
{

    for(int i = start; i<cur_size_; i++){
        if(data_[i] == val){
            return i;
        }
    }

    return -1;
}

//
// operator ==
//
template <typename T>
bool Basic_Array <T>::operator == (const Basic_Array & rhs) const
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
bool Basic_Array <T>::operator != (const Basic_Array & rhs) const
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

//
// fill
//
template <typename T>
void Basic_Array <T>::fill (T value)
{
    for(int i = 0; i<cur_size_; i++){
        data_[i] = value;
    }
}
