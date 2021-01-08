#include "person.h"
#include "personwrapper.h"
#include <string.h>



persontype person_constructor( void )
{
	person * a_person = new person();
	persontype personpointer = (persontype)a_person;
	return personpointer;
}

void get_name_wrapper( persontype  a_person_type, char* name )
{
	std::string a_name;
	person* a_person = (person*)a_person_type;
	a_name = a_person->get_name();
	memcpy(name,(char*)a_name.c_str(),strlen(a_name.c_str())+1);
	return;
}

const int get_age_wrapper( persontype a_person_type )
{
	
	person* a_person = (person*)a_person_type;
	return a_person->get_age();

}

void set_age_wrapper( persontype a_person_type, int age )
{
	person* a_person = (person*)a_person_type;
	a_person->set_age(age);

}

void set_name_wrapper( persontype a_person_type, const char* name )
{
	std::string strname(name); 
	person* a_person = (person*)a_person_type;
	a_person->set_name(strname);

}

void person_destructor(persontype  a_person_type)
{
	person* a_person = (person*)a_person_type;
	delete(a_person);
}
