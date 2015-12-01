//
//  StackException.h
//  Sec4.2b_Ex5
//  Copyright (c) 2015 MichaelScott. All rights reserved.
// Exception class to throw stack exception objects. Stack full and stack empty exception classes are inherited from abstract base class.

#ifndef __Sec4_2b_Ex5__StackException__
#define __Sec4_2b_Ex5__StackException__

#include <iostream>
namespace Anees{namespace Containers{
class StackException
{
public:
    virtual string GetMessage() const=0;   // creating PVMF so that StackException is ABC
 
};
    class StackFullException:public StackException
    {
    public:
      inline string GetMessage() const  // print handle message
        {
            stringstream ss;
            ss<<"Can't push any more as stack is full!"<<endl;
            return (ss.str());
        }
    };
    
    class StackEmptyException:public StackException
    {
    public:
        inline string GetMessage() const  // print handle message
        {
            stringstream ss;
            ss<<"Can't pop any more as stack is empty!"<<endl;
            return (ss.str());
        }
    };

}}

#endif /* defined(__Sec4_2b_Ex5__StackException__) */