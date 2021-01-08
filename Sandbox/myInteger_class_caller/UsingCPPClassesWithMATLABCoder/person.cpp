#include <iostream>
#include <string>
#include "person.h"



person::person(const std::string a_name , int an_age)
{
	set_name(a_name);
	set_age(an_age);
}

const std::string person::get_name() const
{
	return name;

}

const int person::get_age() const
{
	return age;
}

void person::set_name(const std::string a_name) 
{
	if (a_name == "")
	{
		std::cerr
			<< a_name
			<< "is an invalid name!"
			<< std::endl;
	}
	name = a_name;
}

void person::set_age(const int an_age)
{
	if (an_age < 0)
	{
		std::cerr
			<< an_age
			<< "is an invalid age! Age cannot be negative!"
			<< std::endl;
	}
	age = an_age;
}

person::~person()
{

}