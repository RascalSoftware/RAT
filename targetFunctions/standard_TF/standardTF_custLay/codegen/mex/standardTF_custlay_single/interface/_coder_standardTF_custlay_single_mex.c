/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_standardTF_custlay_single_mex.c
 *
 * Code generation for function '_coder_standardTF_custlay_single_mex'
 *
 */

/* Include files */
#include "standardTF_custlay_single.h"
#include "_coder_standardTF_custlay_single_mex.h"
#include "standardTF_custlay_single_terminate.h"
#include "_coder_standardTF_custlay_single_api.h"
#include "standardTF_custlay_single_initialize.h"
#include "standardTF_custlay_single_data.h"

/* Function Declarations */
static void c_standardTF_custlay_single_mex(int32_T nlhs, mxArray *plhs[15],
  int32_T nrhs, const mxArray *prhs[31]);

/* Function Definitions */
static void c_standardTF_custlay_single_mex(int32_T nlhs, mxArray *plhs[15],
  int32_T nrhs, const mxArray *prhs[31])
{
  int32_T n;
  const mxArray *inputs[31];
  const mxArray *outputs[15];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 31) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 31, 4,
                        25, "standardTF_custlay_single");
  }

  if (nlhs > 15) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 25,
                        "standardTF_custlay_single");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  standardTF_custlay_single_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  standardTF_custlay_single_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(standardTF_custlay_single_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  standardTF_custlay_single_initialize();

  /* Dispatch the entry-point. */
  c_standardTF_custlay_single_mex(nlhs, plhs, nrhs, prhs);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_standardTF_custlay_single_mex.c) */
