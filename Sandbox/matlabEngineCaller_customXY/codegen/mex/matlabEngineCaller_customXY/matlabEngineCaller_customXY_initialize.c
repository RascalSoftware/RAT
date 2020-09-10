/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * matlabEngineCaller_customXY_initialize.c
 *
 * Code generation for function 'matlabEngineCaller_customXY_initialize'
 *
 */

/* Include files */
#include "matlabEngineCaller_customXY_initialize.h"
#include "_coder_matlabEngineCaller_customXY_mex.h"
#include "matlabEngineCaller_customXY.h"
#include "matlabEngineCaller_customXY_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void matlabEngineCaller_customXY_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mex_InitInfAndNan();
  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (matlabEngineCaller_customXY_initialize.c) */
