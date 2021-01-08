/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * mycode.c
 *
 * Code generation for function 'mycode'
 *
 */

/* Include files */
#include "mycode.h"
#include "myclass.h"
#include "rt_nonfinite.h"
#include <functional>
#include <iostream>

/* Type Definitions */
#include "myclass.h"

/* Function Definitions */
int32_T mycode(const emlrtStack *sp)
{
  MyClass p;
  (void)sp;

  /* MYMCODE Summary of this function goes here */
  /*    Detailed explanation goes here */
  p = MyClass();
  return std::mem_fn(&MyClass::mymethod)(p, 5);
}

/* End of code generation (mycode.c) */
