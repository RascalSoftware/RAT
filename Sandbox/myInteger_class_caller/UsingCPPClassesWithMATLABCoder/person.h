// person.h

#ifndef PERSON_H
#define PERSON_H

#include <string>

class person
{
	
public:
	person(const std::string a_name = "John Doe", int an_age = 35);
	~person(void);
	const std::string get_name() const;
	void set_name(const std::string a_name);
	const int get_age() const;
	void set_age(const int an_age);
private:
	std::string name;
	int age;



};

#endif