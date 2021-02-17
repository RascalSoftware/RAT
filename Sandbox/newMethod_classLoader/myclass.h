// myclass.h
#ifndef MYCLASS_H
#define MYCLASS_H
#include <iostream>
#include <string>
class MyClass
{
public:
    MyClass(void){};
    int mymethod(int a)
    {
        std::cout << "MyClass::mymethod() called with input (" + std::to_string(a) + ")." << std::endl;
        return 42;
    };   
};
#endif

