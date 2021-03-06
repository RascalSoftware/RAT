/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 * File: _coder_reflectivity_calculation_mex.c
 *
 * MATLAB Coder version            : 5.0
 * C/C++ source code generated on  : 24-Feb-2021 09:21:20
 */

/* Include Files */
#include "_coder_reflectivity_calculation_mex.h"
#include "_coder_reflectivity_calculation_api.h"

/* Function Declarations */
MEXFUNCTION_LINKAGE void c_reflectivity_calculation_mexF(int32_T nlhs, mxArray
  *plhs[2], int32_T nrhs, const mxArray *prhs[4]);

/* Function Definitions */

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[2]
 *                int32_T nrhs
 *                const mxArray *prhs[4]
 * Return Type  : void
 */
void c_reflectivity_calculation_mexF(int32_T nlhs, mxArray *plhs[2], int32_T
  nrhs, const mxArray *prhs[4])
{
  const mxArray *outputs[2];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 4, 4,
                        24, "reflectivity_calculation");
  }

  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 24,
                        "reflectivity_calculation");
  }

  /* Call the function. */
  reflectivity_calculation_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);
}

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[]
 *                int32_T nrhs
 *                const mxArray *prhs[]
 * Return Type  : void
 */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(&reflectivity_calculation_atexit);

  /* Module initialization. */
  reflectivity_calculation_initialize();

  /* Dispatch the entry-point. */
  c_reflectivity_calculation_mexF(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  reflectivity_calculation_terminate();
}

/*
 * Arguments    : void
 * Return Type  : emlrtCTX
 */
emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/*
 * File trailer for _coder_reflectivity_calculation_mex.c
 *
 * [EOF]
 */
