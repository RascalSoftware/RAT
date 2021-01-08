/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * myIntegerTest.c
 *
 * Code generation for function 'myIntegerTest'
 *
 */

/* Include files */
#include "myIntegerTest.h"
#include "rt_nonfinite.h"

/* Type Definitions */
#include "MyIntegerWrapper.h"

/* Function Definitions */
real_T myIntegerTest(const emlrtStack *sp, real_T value)
{
  myIntegerType myIntegerPtr;
  (void)sp;
  myIntegerPtr = MyInteger_constructor();
  set_wrapper(myIntegerPtr, value);
  return get_wrapper(myIntegerPtr);
}

/* End of code generation (myIntegerTest.c) */
