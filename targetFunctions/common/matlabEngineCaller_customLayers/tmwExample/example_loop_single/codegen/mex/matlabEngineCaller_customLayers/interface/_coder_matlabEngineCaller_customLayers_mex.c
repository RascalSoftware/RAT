/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_matlabEngineCaller_customLayers_mex.c
 *
 * Code generation for function '_coder_matlabEngineCaller_customLayers_mex'
 *
 */

/* Include files */
#include "matlabEngineCaller_customLayers.h"
#include "_coder_matlabEngineCaller_customLayers_mex.h"
#include "matlabEngineCaller_customLayers_terminate.h"
#include "_coder_matlabEngineCaller_customLayers_api.h"
#include "matlabEngineCaller_customLayers_initialize.h"
#include "matlabEngineCaller_customLayers_data.h"

/* Function Declarations */
static void d_matlabEngineCaller_customLaye(int32_T nlhs, mxArray *plhs[2],
  int32_T nrhs, const mxArray *prhs[6]);

/* Function Definitions */
static void d_matlabEngineCaller_customLaye(int32_T nlhs, mxArray *plhs[2],
  int32_T nrhs, const mxArray *prhs[6])
{
  int32_T n;
  const mxArray *inputs[6];
  const mxArray *outputs[2];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 6) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 6, 4,
                        31, "matlabEngineCaller_customLayers");
  }

  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 31,
                        "matlabEngineCaller_customLayers");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  matlabEngineCaller_customLayers_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  matlabEngineCaller_customLayers_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(matlabEngineCaller_customLayers_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  matlabEngineCaller_customLayers_initialize();

  /* Dispatch the entry-point. */
  d_matlabEngineCaller_customLaye(nlhs, plhs, nrhs, prhs);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_matlabEngineCaller_customLayers_mex.c) */
