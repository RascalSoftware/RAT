/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * dev_custlay_paraContrasts_initialize.c
 *
 * Code generation for function 'dev_custlay_paraContrasts_initialize'
 *
 */

/* Include files */
#include "dev_custlay_paraContrasts_initialize.h"
#include "_coder_dev_custlay_paraContrasts_mex.h"
#include "dev_custlay_paraContrasts_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void dev_custlay_paraContrasts_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mex_InitInfAndNan();
  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (dev_custlay_paraContrasts_initialize.c) */
