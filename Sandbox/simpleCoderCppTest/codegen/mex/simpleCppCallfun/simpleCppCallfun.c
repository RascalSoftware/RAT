/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * simpleCppCallfun.c
 *
 * Code generation for function 'simpleCppCallfun'
 *
 */

/* Include files */
#include "simpleCppCallfun.h"
#include "rt_nonfinite.h"
#include "simpleCppCallfun_data.h"

/* Function Definitions */
real_T simpleCppCallfun(const emlrtStack *sp, real_T input)
{
  real_T out;
  (void)sp;
  covrtLogFcn(&emlrtCoverageInstance, 0U, 0U);
  covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 0, false);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 1U);
  simpleCppFunc(input, &out);
  return out;
}

/* End of code generation (simpleCppCallfun.c) */
