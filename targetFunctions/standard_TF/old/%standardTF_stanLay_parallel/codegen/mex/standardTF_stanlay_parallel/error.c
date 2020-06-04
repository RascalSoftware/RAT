/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * error.c
 *
 * Code generation for function 'error'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "standardTF_stanlay_parallel.h"
#include "error.h"

/* Variable Definitions */
static emlrtRTEInfo kc_emlrtRTEI = { 17,/* lineNo */
  9,                                   /* colNo */
  "error",                             /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/error.m"/* pName */
};

/* Function Definitions */
void b_error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2012b(sp, &kc_emlrtRTEI,
    "Coder:toolbox:interp1_nonMonotonicX", 0);
}

void c_error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2012b(sp, &kc_emlrtRTEI,
    "Coder:toolbox:ElFunDomainError", 3, 4, 4, "asin");
}

void error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2012b(sp, &kc_emlrtRTEI, "MATLAB:interp1:NaNinX", 0);
}

/* End of code generation (error.c) */
