//
//  main.cpp
//  Sec4.2b_Ex6
//  Copyright (c) 2015 MichaelScott. All rights reserved.
// Exercise on value template arguments

#include <iostream>
#include "Array.hpp"
#include "Stack.hpp"
#include"ArrayException.hpp"
#include "OutOfBoundsException.hpp"
#include "Point.hpp"
#include"StackException.hpp"
using namespace Anees::Containers;
using namespace Anees::CAD;
int main()
{
    try
    {
        Stack<int,5> intstackd;   //int stack size of 5 elements
        Stack<Point,5> pointstackd; // point stack of 5 points
        Stack<Point,10> pointstack; //point stack of 10 points
        
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
        
        //Stack<Point,7> pointstack2(pointstack);- Error as LHS has template value 7 and RHS has 10.
        
        //Below works
        Stack<Point,10> pointstack2(pointstack);  //copy constructing pointstack2.
        cout<<"pointstack2 is copy constructed from pointstack with 7 points"<<endl;
        cout<<"popping 2 points out of pointstack2 so it is now 5 points full"<<endl;
        for (int i=0;i<2;i++)
        {
            cout<<pointstack2.Pop()<<endl;
        }
        cout<<endl;
        cout<<"Assigning pointstack2 to pointstackd with 5 points"<<endl;
        
        //pointstackd=pointstack2; //Error as LHS has template value 5 and RHS has 10
        
        // Below works!
        Stack<Point,10> pointstackd1=pointstack2; //assigning pointstack2 to pointstackd.

        cout<<"popping remaining 5 points out of pointstackd1 "<<endl;
        for (int i=0;i<5;i++)
        {
            cout<<pointstackd.Pop()<<endl;
        }
        
        cout<<pointstackd1.Pop(); // throws exception stack empty
    }
    catch(StackException& SE)
    {
        cout<<SE.GetMessage();
        
    }
    catch(...)
    {
        cout<<"Unknown exception thrown!"<<endl;
    }
    return 0;
}
