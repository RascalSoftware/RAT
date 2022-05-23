/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * eml_int_forloop_overflow_check.c
 *
 * Code generation for function 'eml_int_forloop_overflow_check'
 *
 */

/* Include files */
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo vd_emlrtRTEI = {
    88,                             /* lineNo */
    9,                              /* colNo */
    "check_forloop_overflow_error", /* fName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/lib/matlab/eml/"
    "eml_int_forloop_overflow_check.m" /* pName */
};

/* Function Definitions */
void check_forloop_overflow_error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2018a(
      sp, &vd_emlrtRTEI, "Coder:toolbox:int_forloop_overflow",
      "Coder:toolbox:int_forloop_overflow", 3, 4, 5, "int32");
}

/* End of code generation (eml_int_forloop_overflow_check.c) */
