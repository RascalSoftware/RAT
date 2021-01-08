/*
 * MyIntegerWrapper.h
 *
 *  Created on: 18 Dec 2020
 *      Author: root
 */

#ifndef MYINTEGERWRAPPER_H
#define MYINTEGERWRAPPER_H

#include <stdlib.h>

#if defined __cplusplus
extern "C" {

#endif

typedef void * myIntegerType;

myIntegerType MyInteger_constructor(void);

void set_wrapper(myIntegerType an_integer_type, float val);
const float get_wrapper(myIntegerType an_integer_type);


#if defined __cplusplus
}

#endif

#endif /* MYINTEGERWRAPPER_H_ */
