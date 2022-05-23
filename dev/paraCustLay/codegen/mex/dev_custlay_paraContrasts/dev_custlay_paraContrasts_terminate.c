/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * dev_custlay_paraContrasts_terminate.c
 *
 * Code generation for function 'dev_custlay_paraContrasts_terminate'
 *
 */

/* Include files */
#include "dev_custlay_paraContrasts_terminate.h"
#include "_coder_dev_custlay_paraContrasts_mex.h"
#include "dev_custlay_paraContrasts_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void dev_custlay_paraContrasts_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void dev_custlay_paraContrasts_terminate(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (dev_custlay_paraContrasts_terminate.c) */
