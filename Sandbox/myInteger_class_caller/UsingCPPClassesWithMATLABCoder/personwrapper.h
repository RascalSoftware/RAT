#ifndef PERSON_WRAPPER_H
#define PERSON_WRAPPER_H

#include <stdlib.h>

#if defined __cplusplus
extern "C" {

#endif

typedef void * persontype; 

persontype person_constructor( void );

void get_name_wrapper( persontype  a_person_type,  char* name );
const int get_age_wrapper( persontype a_person_type );
void set_name_wrapper( persontype a_person_type, const char* name );
void set_age_wrapper( persontype a_person_type, int age );
void person_destructor( persontype  a_person_type );

#if defined __cplusplus
}
#endif

#endif