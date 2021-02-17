/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * callFoo.c
 *
 * Code generation for function 'callFoo'
 *
 */

/* Include files */
#include "callFoo.h"
#include "callFoo_data.h"
#include "foo.h"
#include "rt_nonfinite.h"

/* Function Definitions */
real_T callFoo(const emlrtStack *sp)
{
  (void)sp;
  covrtLogFcn(&emlrtCoverageInstance, 0U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 0U);
  covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 0, false);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 2U);
  return foo(10.0, 20.0);
}

/* End of code generation (callFoo.c) */
