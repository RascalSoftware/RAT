/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_callFoo_mex.c
 *
 * Code generation for function '_coder_callFoo_mex'
 *
 */

/* Include files */
#include "_coder_callFoo_mex.h"
#include "_coder_callFoo_api.h"
#include "callFoo.h"
#include "callFoo_data.h"
#include "callFoo_initialize.h"
#include "callFoo_terminate.h"

/* Function Declarations */
MEXFUNCTION_LINKAGE void callFoo_mexFunction(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs);

/* Function Definitions */
void callFoo_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs)
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 0, 4, 7,
                        "callFoo");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 7,
                        "callFoo");
  }

  /* Call the function. */
  callFoo_api(nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  (void)prhs;
  mexAtExit(&callFoo_atexit);

  /* Module initialization. */
  callFoo_initialize();

  /* Dispatch the entry-point. */
  callFoo_mexFunction(nlhs, plhs, nrhs);

  /* Module termination. */
  callFoo_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_callFoo_mex.c) */
