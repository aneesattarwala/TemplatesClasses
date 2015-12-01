//
//  main.cpp
//  SEc4.2b_Ex4
//  Copyright (c) 2015 MichaelScott. All rights reserved.
// Stack class and illustration of composition of template classes

#include <iostream>
#include "Array.hpp"
#include "Stack.hpp"
#include"ArrayException.hpp"
#include "OutOfBoundsException.hpp"
#include "Point.hpp"
using namespace Anees::Containers;
using namespace Anees::CAD;
int main()
{
    try
    {
        Stack<int> intstackd;   //default int stack size of 5 elements
        Stack<Point> pointstackd; // default point stack of 5 points
        Stack<Point> pointstack(10); //stack of points of size 10
        
        for (int i=0;i<5;++i)    //filling default stack intstackd
        {
            intstackd.Push(i*10);
        }
        //intstackd.Push(6);       //throws exception stack full
        
        cout<<"popping default int stack intstackd"<<endl;
        for (int i=0;i<5;++i)    
        {
            cout<<intstackd.Pop()<<" ";
        }
        cout<<endl;
        
        // Pushing points in Point stack
        for (int i=0;i<10;i++)
        {
            pointstack.Push(Point(i,i));
        }
      
        //pointstack.Push(Point(10,10));  // Throws exception stack full
        cout<<endl;
        cout<<"popping 3 last points out of pointstack, so that it is 7 elements full"<<endl;
        for (int i=0;i<3;i++)
        {
            cout<<pointstack.Pop()<<endl;
        }
        cout<<endl;
        Stack<Point> pointstack2(pointstack);  //copy constructing pointstack2.
        cout<<"pointstack2 is copy constructed from pointstack with 7 points"<<endl;
        cout<<"popping 2 points out of pointstack2 so it is now 5 points full"<<endl;
        for (int i=0;i<2;i++)
        {
            cout<<pointstack2.Pop()<<endl;
        }
        cout<<endl;
        cout<<"Assigning pointstack2 to pointstackd with 5 points"<<endl;
        pointstackd=pointstack2; //assigning pointstack2 to pointstackd.
        cout<<"popping remaining 5 points out of pointstackd "<<endl;
        for (int i=0;i<5;i++)
        {
            cout<<pointstackd.Pop()<<endl;
        }
        
        cout<<pointstackd.Pop(); // throws exception stack empty
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

