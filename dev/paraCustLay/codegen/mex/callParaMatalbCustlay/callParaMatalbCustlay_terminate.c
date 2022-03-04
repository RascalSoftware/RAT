/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * callParaMatalbCustlay_terminate.c
 *
 * Code generation for function 'callParaMatalbCustlay_terminate'
 *
 */

/* Include files */
#include "callParaMatalbCustlay_terminate.h"
#include "_coder_callParaMatalbCustlay_mex.h"
#include "callParaMatalbCustlay_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void callParaMatalbCustlay_atexit(void)
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

void callParaMatalbCustlay_terminate(void)
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

/* End of code generation (callParaMatalbCustlay_terminate.c) */
