/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_myIntegerTest_mex.c
 *
 * Code generation for function '_coder_myIntegerTest_mex'
 *
 */

/* Include files */
#include "_coder_myIntegerTest_mex.h"
#include "_coder_myIntegerTest_api.h"
#include "myIntegerTest.h"
#include "myIntegerTest_data.h"
#include "myIntegerTest_initialize.h"
#include "myIntegerTest_terminate.h"

/* Function Declarations */
MEXFUNCTION_LINKAGE void myIntegerTest_mexFunction(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[1]);

/* Function Definitions */
void myIntegerTest_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
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
                        13, "myIntegerTest");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 13,
                        "myIntegerTest");
  }

  /* Call the function. */
  myIntegerTest_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(&myIntegerTest_atexit);

  /* Module initialization. */
  myIntegerTest_initialize();

  /* Dispatch the entry-point. */
  myIntegerTest_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  myIntegerTest_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_myIntegerTest_mex.c) */
