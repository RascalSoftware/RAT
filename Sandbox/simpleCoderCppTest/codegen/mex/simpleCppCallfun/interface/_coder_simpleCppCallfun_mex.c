/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_simpleCppCallfun_mex.c
 *
 * Code generation for function '_coder_simpleCppCallfun_mex'
 *
 */

/* Include files */
#include "_coder_simpleCppCallfun_mex.h"
#include "_coder_simpleCppCallfun_api.h"
#include "simpleCppCallfun.h"
#include "simpleCppCallfun_data.h"
#include "simpleCppCallfun_initialize.h"
#include "simpleCppCallfun_terminate.h"

/* Function Declarations */
MEXFUNCTION_LINKAGE void simpleCppCallfun_mexFunction(int32_T nlhs, mxArray
  *plhs[1], int32_T nrhs, const mxArray *prhs[1]);

/* Function Definitions */
void simpleCppCallfun_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
  const mxArray *prhs[1])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1, 4,
                        16, "simpleCppCallfun");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 16,
                        "simpleCppCallfun");
  }

  /* Call the function. */
  simpleCppCallfun_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(&simpleCppCallfun_atexit);

  /* Module initialization. */
  simpleCppCallfun_initialize();

  /* Dispatch the entry-point. */
  simpleCppCallfun_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  simpleCppCallfun_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_simpleCppCallfun_mex.c) */
