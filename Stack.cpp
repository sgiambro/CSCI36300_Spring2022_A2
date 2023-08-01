// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Stack.h"
#include <stdexcept>
#include <iostream>

//
// Stack
//
template <typename T>
Stack <T>::Stack (void)
: sTop_      (0),
  array_()
{}

//
// Stack (const Stack &)
//
template <typename T>
Stack <T>::Stack (const Stack & s)
: sTop_      (s.sTop_),
  array_(s.array_)
{}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
    // COMMENT The stack should grow if out of space.
    //
    // SOLUTION: If the stack is out of space then it will
    // resize itself to have more space

    if(sTop_ < array_->cur_size_){
        sTop_++;
        array_->set((sTop_ - 1) , element);
    }
    else{
        array_->resize(array_->cur_size_ + 10)
        sTop_++;
        array_->set((sTop_ - 1) , element);
    })
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
    if(sTop_ > 0){
        sTop_--;
    }
    else{
        std::cout << "--STACK IS EMPTY--\N--CANNOT POP ANYMORE--" << std::endl;
    })
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
    if(this != &rhs){

        array_->resize(rhs.array_->cur_size);

        for(int i = 0; i< rhs.array_->cur_size; i++){
            array_->set(i , rhs.array_->get(i));
        }

        this->sTop_ = rhs.sTop_;
    }

    return *this;
}

//
// top
//
T Stack <T>::top (void)
{
    try{
        if(sTop_ == 0){
            throw 999;
        }
        return array_->get(sTop_ - 1);
    }
    catch(int oor){
        std::cout << "--STACK IS EMPTY--" << std::endl;
    }
}

//
// is_empty
//
bool Stack <T>::is_empty (void)
{
    if(sTop > 0){
        return false;
    }
    else{
        return true;
    }
}


//
// size
//
size_t Stack <T>::size (void)
{
    return sTop_;
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
    sTop_ = 0;
}
