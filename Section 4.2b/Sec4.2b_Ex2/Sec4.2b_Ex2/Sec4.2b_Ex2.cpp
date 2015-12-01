//
//  main.cpp
//  Sec4.2b_Ex2
//  Copyright (c) 2015 MichaelScott. All rights reserved.
//  NumericArray class inherited from generic Array class with additional functions. Dot product can also be implemented as an overloaded operator but I have implemented it as functions as required in this exercise.

/******Questions and Answers***************/
//Q:What assumptions do you make about the type used as template argument?
//A: Has addition and scaling operators defined. Has dotproduct function defined. Is assignable and can be copy constructed 
//Q:Can you create a numeric array with Point objects?
//A:Yes we can as shown below.Addition and scaling operations of numerica array class on point objects are also illustrated. Dot product is not meaningful.

#include <iostream>
#include "Array.hpp"
#include "NumericArray.hpp"
#include "Point.hpp"
using namespace Anees::CAD;
using namespace Anees::Containers;
int main()
{    
try{

    NumericArray<int> Nint1(3);    //constructing numeric arrays
    NumericArray<double> Nd2;
    NumericArray<double> Nd4;
    NumericArray<Point> P(3);     //creating numeric array of point objects

    
    cout<<"Size of 1st array :"<<Nint1.size()<<endl;  //printing sizes
    cout<<"Size of 2nd array :"<<Nd2.size()<<endl;
    
    //setting Nint1(3)
    Nint1[0]=10;
    Nint1.SetElement(20,1);
    Nint1[2]=30;
    NumericArray<int> Nint5(Nint1); // copy constructing Nint5
    
    Nint1=Nint1*2;    //scaling Nint1 by 2 and printing
    cout<<"Scaled Array Nint1"<<endl;
    cout<<Nint1[0]<<" "<<Nint1.GetElement(1)<<" "<<Nint1.GetElement(2)<<endl;
        
    Nint5=Nint1+Nint5; // adding arrays
    cout<<"Addition of Nint1 and Nint5"<<endl;
    cout<<Nint5[0]<<" "<<Nint5.GetElement(1)<<" "<<Nint5.GetElement(2)<<endl;
    
        
  //setting array of doubles
    Nd2[0]=1.0;
    Nd2[1]=2.0;
    Nd2[2]=3.04;
    Nd2[3]=4.30;
    Nd2[4]=-3.14;
    
    // Assigning Nd2 to Nd4 and displaying Nint4
    Nd4=Nd2;
    cout<<"Array after assignment"<<endl;
    cout<<Nd4[0]<<" "<<Nd4.GetElement(1)<<" "<<Nd4.GetElement(2)<<" "<<Nd4[3]<<" "<<Nd4[4]<<endl;
    
    // computing dot product of Nint1 and Nint5
    cout<<"Dot product of Nint1 and Nint 2 is :"<<Nint1.dotproduct(Nint5)<<endl;
    
    /*****Numeric Array of Point objects*****************/
    P[0]=Point();         //creating member of Point numeric array
    P[1]=Point(1,2);
    P[2]=Point(3,4);

    cout<<"Printing array of points P"<<endl;
    cout<<P[0]<<" "<<P[1]<<" "<<P[2]<<endl;
    NumericArray<Point> P2(3);
    P2=P; //assignment
    
    P2=P2*2; // scaling
    cout<<"Scaling P2 by 2"<<endl;
    cout<<P2[0]<<" "<<P2[1]<<" "<<P2[2]<<endl;

    P2=P2+P;  //adding
    cout<<"Adding P2 and P"<<endl;
    cout<<P2[0]<<" "<<P2[1]<<" "<<P2[2]<<endl;
    
    //****************EXCEPTIONS***********************************************//
    //Nd2[5]=-2.3;  //out of bounds exception thrown 
    
    //Exception thrown for summing unequal arrays
    //NumericArray<int>Nint7(10);
    //Nint5=Nint1+Nint7;
   
    //Exception thrown for taking dot product of unequal arrays 
    //Nint1.dotproduct(Nint7);
        
    
}
    catch(ArrayException& Ex)
    {
        cout<<Ex.GetMessage();
    }
    
    catch(int err)
    {
        if (err==-1)
        cout<<"Cannot add as arrays are not of same size!"<<endl;
        if (err==-2)
        cout<<"Cannot compute dot product as arrays are not of same size!"<<endl;

    }
    catch(...)
    {
        cout<<"Unknown exception thrown!"<<endl;
    }
return 0;
}