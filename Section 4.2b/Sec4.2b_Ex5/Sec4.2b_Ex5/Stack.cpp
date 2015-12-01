//
//  Stack.cpp
//  SEc4.2b_Ex4

//  Copyright (c) 2015 MichaelScott. All rights reserved.
//  Implementation of Stack class using composition
// try catch block to catch array out of bounds exception and re-throw stack exception to main

#ifndef Stack_cpp
#define Stack_cpp

#include "Stack.hpp"
#include "Array.hpp"
#include"ArrayException.hpp"
#include"OutOfBoundsException.hpp"
#include "StackException.hpp"
#include <iostream>
namespace Anees{namespace Containers{
    
    template <class T>
    Stack<T>::Stack():m_current(0)   //Default constructor, and intially stack is empty
    {}

    template <class T>
    Stack<T>::Stack(int n):m_current(0),m_array(Array<T>(n))   //Stack is of size of array of size n.
    {}
    
    //copy constructor - copying Array and m_current. Array copy is done using copy ctr of Array
    //class
    template <class T>
    Stack<T>::Stack(const Stack<T>& source):m_array(source.m_array),m_current(source.m_current)
    {}
    
    template <class T>
    Stack<T>::~Stack(){}              // destructor
    
    //push an element onto stack. Stack overflow exception handled in array class
    template <class T>
    void Stack<T>::Push(const T& value)
    {
        try{
            m_array[m_current]=value;    // will throw array exception if index out of bounds.
            ++m_current;                 // and current index remains unchanged
        }
        catch(ArrayException& ex){
            throw StackFullException();   // throwing StackFullException constructor obj -RETHROW
        }
    }
    
    //pop an element out of stack. Stack underflow exception handled in array class
    template <class T>
    T Stack<T>::Pop() 
    {
        try{
            --m_current;                     
            return(m_array[m_current]);  //Throws array excpetions if current index <0
        }
        catch(ArrayException& ex){
            m_current=0;
            throw StackEmptyException(); // throwing StackEmptyException constructor obj -RETHROW
        }
    }
    
    // operator overloading
    template <class T>
    Stack<T>& Stack<T>::operator = (const Stack<T>& source) //Assignment operator
    {
        if(this==&source)               // avoid self-assignment
            return *this;
        m_array=source.m_array;     // call Array class assignment operator to assign array
        m_current=source.m_current; //simple assignment for current index
        return *this;
    }
}}
#endif