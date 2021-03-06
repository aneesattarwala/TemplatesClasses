//
//  Stack.h
//  SEc4.2b_Ex4
//  Copyright (c) 2015 MichaelScott. All rights reserved.
// Implementation of Stack class using composition
// Stack class has value templete arguments in addition to generic types.

#ifndef Stack_hpp
#define Stack_hpp
#include "Array.hpp"
#include"ArrayException.hpp"
#include"OutOfBoundsException.hpp"
#include <iostream>
namespace Anees{namespace Containers{
template <class T, int size>
class Stack
{
private:
    Array<T> m_array;
    int m_current;
public:
    //constructors and destructor
    Stack();               //default constructor
    Stack(const Stack<T,size>& source);  //copy constructor
    ~Stack();              // destructor
    
    //assignment operator
    Stack<T,size>& operator = (const Stack<T,size>& source);
    
    // modifying functions
    void SetSize(int n);      // setting size of stack
    void Push(const T& value);    //push an element onto stack. Stack overflow exception handled in array class
    T Pop();     //pop an element out of stack. Stack underflow exception handled in array class
   
};
}}

#ifndef Stack_cpp
#include "Stack.cpp"
#endif

#endif /* defined(__SEc4_2b_Ex4__Stack__) */
