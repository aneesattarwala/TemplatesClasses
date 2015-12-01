//
//  NumericArray.h
//  Sec4.2b_Ex2

//  Copyright (c) 2015 MichaelScott. All rights reserved.
// NumericArray class inherited from generic Array class with additional functions

#ifndef __Sec4_2b_Ex2__NumericArray__
#define __Sec4_2b_Ex2__NumericArray__
#include"Array.hpp"
#include <iostream>
namespace Anees {namespace Containers{

template <class T>
class NumericArray:public Array<T>
{
public:
    //constructors and destructor
    NumericArray();   //default constructor
    NumericArray(int n);// constructor with arguments of size of numeric array
    NumericArray(const NumericArray<T>& NA);      // copy constructor
    ~NumericArray();              // destructor
   
    // operator overloading
    NumericArray<T>& operator = (const NumericArray<T>& NA); //assignment operator
    NumericArray<T> operator * (double factor) const; //operator to scale the array
    NumericArray<T> operator + (const NumericArray<T>& NA) const; //operator to add two arrays element by element

    //modifier function (Dot product can also be implemented as overloaded operator)
    double dotproduct(const NumericArray<T>& NA) const;
    
};
}}
#ifndef NumericArray_CPP
#include "NumericArray.cpp"
#endif

#endif /* defined(__Sec4_2b_Ex2__NumericArray__) */
