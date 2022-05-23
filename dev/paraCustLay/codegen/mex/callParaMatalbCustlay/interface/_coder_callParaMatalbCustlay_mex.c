/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_callParaMatalbCustlay_mex.c
 *
 * Code generation for function '_coder_callParaMatalbCustlay_mex'
 *
 */

/* Include files */
#include "_coder_callParaMatalbCustlay_mex.h"
#include "_coder_callParaMatalbCustlay_api.h"
#include "callParaMatalbCustlay_data.h"
#include "callParaMatalbCustlay_initialize.h"
#include "callParaMatalbCustlay_terminate.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void callParaMatalbCustlay_mexFunction(int32_T nlhs, mxArray *plhs[2],
                                       int32_T nrhs, const mxArray *prhs[4])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[2];
  int32_T b_nlhs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 4, 4,
                        21, "callParaMatalbCustlay");
  }
  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 21,
                        "callParaMatalbCustlay");
  }
  /* Call the function. */
  callParaMatalbCustlay_api(prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }
  emlrtReturnArrays(b_nlhs, &plhs[0], &outputs[0]);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&callParaMatalbCustlay_atexit);
  /* Module initialization. */
  callParaMatalbCustlay_initialize();
  /* Dispatch the entry-point. */
  callParaMatalbCustlay_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  callParaMatalbCustlay_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2021a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_callParaMatalbCustlay_mex.c) */
