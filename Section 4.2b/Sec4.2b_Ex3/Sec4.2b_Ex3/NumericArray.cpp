//
//  NumericArray.cpp
//  Sec4.2b_Ex2

//  Copyright (c) 2015 MichaelScott. All rights reserved.
//

#ifndef NumericArray_CPP
#define NumericArray_CPP

#include "NumericArray.hpp"
#include"Array.hpp"

namespace Anees {namespace Containers{

template <class T>
NumericArray<T>::NumericArray():Array<T>(){} //default constructor, calling base class ctr
    
template <class T>    
NumericArray<T>::NumericArray(int n):Array<T>(n){}; // constructor with size arguement, calling base class ctr.

template<class T>                             // destructor
NumericArray<T>::~NumericArray()
{}

//Copy constructor: Calling base class copy constructor and passing derived class object
template<class T>
NumericArray<T>::NumericArray(const NumericArray<T>& NA):Array<T>(NA){};

    
//Assignment operator
template <class T>
NumericArray<T>& NumericArray<T>::operator = (const NumericArray<T>& NA)
{
    if(this==&NA)               // avoid self-assignment
        return *this;
    Array<T>::operator=(NA);   // calling base call assignment operator to assign base part
    return *this;
}

template <class T>
NumericArray<T> NumericArray<T>::operator * (double factor)const    //operator to scale the array
{
    NumericArray<T> Factor(this->size());
    for (int i=0;i<this->size();++i)
    {
        Factor[i]=this->GetElement(i)*factor;
        
    }
    return Factor;
    
}

//operator to add two arrays element by element
template <class T>
NumericArray<T> NumericArray<T>::operator + (const NumericArray<T>& NA) const
{
    
    if (this->size()!=NA.size())
    {throw (-1);}

    else{
    NumericArray<T> addarray(this->size());
    for (int i=0;i<this->size();++i)
    {
        addarray[i] = this->GetElement(i)+NA[i];
    }
        
    return addarray;
    }
}
//modifier function (Dot product can also be implemented as overloaded dot operator)
template <class T>
double NumericArray<T>::dotproduct(const NumericArray<T>& NA) const
{
    double dp=0;       //variable to store dot product
    if (this->size()!=NA.size())
    {throw (-2);}
    else{
        for (int i=0;i<this->size();++i)
        {
            dp += NA[i]*this->GetElement(i);
        }
        
        return dp;
    }    
}
}}

#endif