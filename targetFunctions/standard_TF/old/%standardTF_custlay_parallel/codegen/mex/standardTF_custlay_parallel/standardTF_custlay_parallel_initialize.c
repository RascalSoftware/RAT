/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_custlay_parallel_initialize.c
 *
 * Code generation for function 'standardTF_custlay_parallel_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "standardTF_custlay_parallel.h"
#include "standardTF_custlay_parallel_initialize.h"
#include "_coder_standardTF_custlay_parallel_mex.h"
#include "standardTF_custlay_parallel_data.h"

/* Function Definitions */
void standardTF_custlay_parallel_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (standardTF_custlay_parallel_initialize.c) */
