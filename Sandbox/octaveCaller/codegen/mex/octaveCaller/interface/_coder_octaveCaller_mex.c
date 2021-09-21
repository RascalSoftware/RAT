/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_octaveCaller_mex.c
 *
 * Code generation for function '_coder_octaveCaller_mex'
 *
 */

/* Include files */
#include "_coder_octaveCaller_mex.h"
#include "_coder_octaveCaller_api.h"
#include "octaveCaller_data.h"
#include "octaveCaller_initialize.h"
#include "octaveCaller_terminate.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  (void)plhs;
  (void)prhs;
  mexAtExit(&octaveCaller_atexit);
  /* Module initialization. */
  octaveCaller_initialize();
  /* Dispatch the entry-point. */
  octaveCaller_mexFunction(nlhs, nrhs);
  /* Module termination. */
  octaveCaller_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2021a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL);
  return emlrtRootTLSGlobal;
}

void octaveCaller_mexFunction(int32_T nlhs, int32_T nrhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 0, 4,
                        12, "octaveCaller");
  }
  if (nlhs > 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 12,
                        "octaveCaller");
  }
  /* Call the function. */
  octaveCaller_api();
}

/* End of code generation (_coder_octaveCaller_mex.c) */
