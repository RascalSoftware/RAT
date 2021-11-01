/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_matlabEngineCaller_customXY_mex.c
 *
 * Code generation for function '_coder_matlabEngineCaller_customXY_mex'
 *
 */

/* Include files */
#include "_coder_matlabEngineCaller_customXY_mex.h"
#include "_coder_matlabEngineCaller_customXY_api.h"
#include "matlabEngineCaller_customXY.h"
#include "matlabEngineCaller_customXY_data.h"
#include "matlabEngineCaller_customXY_initialize.h"
#include "matlabEngineCaller_customXY_terminate.h"

/* Function Declarations */
MEXFUNCTION_LINKAGE void c_matlabEngineCaller_customXY_m(int32_T nlhs, mxArray
  *plhs[2], int32_T nrhs, const mxArray *prhs[6]);

/* Function Definitions */
void c_matlabEngineCaller_customXY_m(int32_T nlhs, mxArray *plhs[2], int32_T
  nrhs, const mxArray *prhs[6])
{
  const mxArray *outputs[2];
  int32_T nOutputs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 6) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 6, 4,
                        27, "matlabEngineCaller_customXY");
  }

  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 27,
                        "matlabEngineCaller_customXY");
  }

  /* Call the function. */
  matlabEngineCaller_customXY_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    nOutputs = 1;
  } else {
    nOutputs = nlhs;
  }

  emlrtReturnArrays(nOutputs, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(&matlabEngineCaller_customXY_atexit);

  /* Module initialization. */
  matlabEngineCaller_customXY_initialize();

  /* Dispatch the entry-point. */
  c_matlabEngineCaller_customXY_m(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  matlabEngineCaller_customXY_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_matlabEngineCaller_customXY_mex.c) */
