#include "MyInteger.h"
#include "MyIntegerWrapper.h"
#include<iostream>
#include<algorithm>

myIntegerType MyInteger_constructor(void)
{
	MyInteger * an_integer = new MyInteger();
	myIntegerType myIntegerPointer = (myIntegerType)an_integer;
	return myIntegerPointer;
}

const float get_wrapper(myIntegerType an_integer_type)
{

	MyInteger* an_instance = (MyInteger*)an_integer_type;
	return an_instance->get();

}

void set_wrapper(myIntegerType an_integer_type, float val)
{
	MyInteger* an_integer = (MyInteger*)an_integer_type;
	an_integer-> set(val);

}






