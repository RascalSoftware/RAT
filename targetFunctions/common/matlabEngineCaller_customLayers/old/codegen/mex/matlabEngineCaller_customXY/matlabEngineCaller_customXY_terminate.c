/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * matlabEngineCaller_customXY_terminate.c
 *
 * Code generation for function 'matlabEngineCaller_customXY_terminate'
 *
 */

/* Include files */
#include "matlabEngineCaller_customXY_terminate.h"
#include "_coder_matlabEngineCaller_customXY_mex.h"
#include "matlabEngineCaller_customXY.h"
#include "matlabEngineCaller_customXY_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void matlabEngineCaller_customXY_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);

  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void matlabEngineCaller_customXY_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (matlabEngineCaller_customXY_terminate.c) */
