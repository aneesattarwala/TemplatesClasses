
//  main.cpp
//  Sec4.2b_Ex3
//  Copyright (c) 2015 MichaelScott. All rights reserved.
//  Testing functionality of concrete inheritence

#include <iostream>
#include "Array.hpp"
#include "Shape.hpp"
#include "Point.hpp"
#include "PointArray.hpp"
using namespace Anees::Containers;
using namespace Anees::CAD;
int main()
{
try{
    PointArray P;  //default contructing 5 point array eacth (0,0), so 0 length
    cout<<"Length of default PointArray :"<<P.Length()<<endl<<endl;
    PointArray P1(4);     //constructing array of 5 of points
    P1[0]=Point();        //initializing array elements
    P1[1]=Point(3,4);
    P1.SetElement(Point(5,6),2);
    P1[3]=Point(7,8);
    //P1[4]=Point(1,2);  // throws exception!
    
    cout<<"P1 printed below has length :"<<P1.Length()<<endl;
    cout<<"P1---> :"<<P1[0]<<" "<<P1[1]<<" "<<P1[2]<<" "<<P1[3]<<" "<<endl;
    
    PointArray P2(P1);   // copy construction of Point array P2
    cout<<"P2 copy constructed from P1 is printed below and has length :"<<P2.Length()<<endl;
    cout<<"P2---> :"<<P2[0]<<" "<<P2[1]<<" "<<P2[2]<<" "<<P2[3]<<" "<<endl;
    
    //modifying P1
    for (int i=0;i<P1.size();++i)
    {
        P1[i]=Point(i,i);
    }
    
    PointArray P3;
    P3=P1;            // changing P1 and assigning it ot P3.
    
    //printing P3 and its length
    
    cout<<"P3 assigned from P1 is printed below and has length :"<<P3.Length()<<endl;
    cout<<"P3---> :"<<P3[0]<<" "<<P3[1]<<" "<<P3[2]<<" "<<P3[3]<<" "<<endl;
    }
    
catch(ArrayException& Ex)
    {
    cout<<Ex.GetMessage();
    }
catch(...)
    {
    cout<<"Unknown exception thrown!"<<endl;
    }
    
return 0;
}   

