
//  main.cpp
//  Sec4.2b_Ex1
//  Copyright (c) 2015 MichaelScott. All rights reserved.


#include <iostream>
#include "Array.hpp"
using namespace std;
using namespace Anees::Containers;
int main()
{

    Array<int> intArray1;
    Array<int> intArray2;
    Array<double> doubleArray;                  //OUTPUT
    cout<<intArray1.DefaultSize()<<endl;        //5  -> since default_size=5 for all types int or double
    cout<<intArray2.DefaultSize()<<endl;        //5  -> since default_size=5 for all types int or double
    cout<<doubleArray.DefaultSize()<<endl;      //5  -> since default_size=5 for all types int or double
    intArray1.DefaultSize(15);                 //Change default_size for int types to 15.
    cout<<intArray1.DefaultSize()<<endl;       //15 -> since default_size=15 for int Array
    cout<<intArray2.DefaultSize()<<endl;       //15 ->since default_size=15 for int Array
    cout<<doubleArray.DefaultSize()<<endl;     //5  ->since default_size is still 5 for double Array, default size
                                               //   ->only changed for int Array
    return 0;
}

