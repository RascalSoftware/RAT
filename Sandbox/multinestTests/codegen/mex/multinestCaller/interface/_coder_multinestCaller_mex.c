/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_multinestCaller_mex.c
 *
 * Code generation for function '_coder_multinestCaller_mex'
 *
 */

/* Include files */
#include "multinestCaller.h"
#include "_coder_multinestCaller_mex.h"
#include "multinestCaller_terminate.h"
#include "_coder_multinestCaller_api.h"
#include "multinestCaller_initialize.h"
#include "multinestCaller_data.h"

/* Function Declarations */
static void multinestCaller_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T
  nrhs);

/* Function Definitions */
static void multinestCaller_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T
  nrhs)
{
  const mxArray *outputs[1];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 0, 4,
                        15, "multinestCaller");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 15,
                        "multinestCaller");
  }

  /* Call the function. */
  multinestCaller_api(outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  multinestCaller_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  (void)prhs;
  mexAtExit(multinestCaller_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  multinestCaller_initialize();

  /* Dispatch the entry-point. */
  multinestCaller_mexFunction(nlhs, plhs, nrhs);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_multinestCaller_mex.c) */
