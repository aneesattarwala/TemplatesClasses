//  main.cpp
//  Sec4.2a_Ex1
//  Copyright (c) 2015 MichaelScott. All rights reserved.
// Templatizing Array container to handle varous shapes

#include <iostream>
#include"Point.hpp"
#include"Line.hpp"
#include"Circle.hpp"
#include"Array.hpp"
using namespace Anees::CAD;
using namespace Anees::Containers;

int main()
{
    try{
        
        Array<double> intarray;
        Array <Point> A(4);     //Point array of size 4. Setting elements more index more than 4 and less than 0.
        A[0]=Point(1,2);
        A[1]=Point(3,4);
        A.SetElement(Point(5,6),2);
        A.SetElement(Point(-1,-2),3);
        
        //**** TEST CASES***//
        
       // A[4]=Point(-4,-5);            // setting index>array size, exception thrown and caught
       
        Array<Point> B(A);         // copy constructing B
        Array<Point> C(4);         // new point array C
        C=A;                      // A assigned to C using assignment operator
        C[0]=A[0]+B[1];            // modifying C using modifier functions
        C[1]=C.GetElement(0);
        
        // priting size and arrays
        cout<<"size of C :"<<C.size()<<endl;
        cout<<"A: "<<A[0]<<" "<<A[1]<<" "<<A.GetElement(2)<<" "<<A.GetElement(3)<<endl;
        cout<<"B: "<<B[0]<<" "<<B[1]<<" "<<B.GetElement(2)<<" "<<B.GetElement(3)<<endl;
        cout<<"C: "<<C[0]<<" "<<C[1]<<" "<<C.GetElement(2)<<" "<<C.GetElement(3)<<endl;
        
        // Array of lines. Setting various lines in array using points
        Array<Line> L(4);
        L[0]=Line (Point(1,2),Point(2,3));
        L[1]=Line (A[1],B[2]);
        L.SetElement(Line(A[2],B.GetElement(1)),2);
        L.SetElement(Line(A[3],C[1]),3);
        
        Array<Line> L2(L);            // copy constructing line
        Array<Line> L3(4);
        
        L3=L;                       //assigning lines
        
        L3[1] = L2[3];        // modifying L3
        L3[2] = L[2];

        //printing lines
        for (int i=0;i<4;i++){
        cout<<L3[i]<<endl;
        }
    }
    
        
    catch(ArrayException& Ex)
    {
        cout<<Ex.GetMessage();
    }
    catch(...)
    {
        cout<<"Uhandled exception occured!"<<endl;
    }
    
    return 0;
}
