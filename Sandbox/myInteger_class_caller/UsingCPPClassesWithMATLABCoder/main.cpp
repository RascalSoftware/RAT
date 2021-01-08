#include <iostream>
#include <cstdlib>
#include <string>
#include "persontest_initialize.h"
#include "persontest_terminate.h"
#include "persontest.h"

int main () {
 
persontest_initialize();
const int name_size[] = {1,9};
int name2_size[] = {1,9};
int age = 35;
char* name2 = (char*)malloc(sizeof(char) * 1024) ;
int *myage = (int*)malloc(sizeof(int));
const char* name = "McAwesome";
persontest( name,  name_size, age, name2,name2_size, myage);
std::cout <<"Person's name is "<<name2<< " and he is " << *myage << " years old."<<std::endl;
persontest_terminate();


}