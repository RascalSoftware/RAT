/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_resampleLayers_new_mex.c
 *
 * Code generation for function '_coder_resampleLayers_new_mex'
 *
 */

/* Include files */
#include "_coder_resampleLayers_new_api.h"
#include "_coder_resampleLayers_new_mex.h"

/* Function Declarations */
static void resampleLayers_new_mexFunction(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[1]);

/* Function Definitions */
static void resampleLayers_new_mexFunction(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[1])
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
                        18, "resampleLayers_new");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 18,
                        "resampleLayers_new");
  }

  /* Call the function. */
  resampleLayers_new_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(resampleLayers_new_atexit);

  /* Module initialization. */
  resampleLayers_new_initialize();

  /* Dispatch the entry-point. */
  resampleLayers_new_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  resampleLayers_new_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_resampleLayers_new_mex.c) */
