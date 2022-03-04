/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_dev_custlay_paraContrasts_mex.c
 *
 * Code generation for function '_coder_dev_custlay_paraContrasts_mex'
 *
 */

/* Include files */
#include "_coder_dev_custlay_paraContrasts_mex.h"
#include "_coder_dev_custlay_paraContrasts_api.h"
#include "dev_custlay_paraContrasts.h"
#include "dev_custlay_paraContrasts_data.h"
#include "dev_custlay_paraContrasts_initialize.h"
#include "dev_custlay_paraContrasts_terminate.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void dev_custlay_paraContrasts_mexFunction(int32_T nlhs, mxArray *plhs[15],
                                           int32_T nrhs, const mxArray *prhs[4])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[15];
  int32_T b_nlhs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 4, 4,
                        25, "dev_custlay_paraContrasts");
  }
  if (nlhs > 15) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 25,
                        "dev_custlay_paraContrasts");
  }
  /* Call the function. */
  dev_custlay_paraContrasts_api(prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }
  emlrtReturnArrays(b_nlhs, &plhs[0], &outputs[0]);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  static jmp_buf emlrtJBEnviron;
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexAtExit(&dev_custlay_paraContrasts_atexit);
  /* Initialize the memory manager. */
  omp_init_lock(&emlrtLockGlobal);
  omp_init_nest_lock(&emlrtNestLockGlobal);
  /* Module initialization. */
  dev_custlay_paraContrasts_initialize();
  st.tls = emlrtRootTLSGlobal;
  emlrtSetJmpBuf(&st, &emlrtJBEnviron);
  if (setjmp(emlrtJBEnviron) == 0) {
    /* Dispatch the entry-point. */
    dev_custlay_paraContrasts_mexFunction(nlhs, plhs, nrhs, prhs);
    /* Module termination. */
    dev_custlay_paraContrasts_terminate();
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&emlrtNestLockGlobal);
  } else {
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&emlrtNestLockGlobal);
    emlrtReportParallelRunTimeError(&st);
  }
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2021a(&emlrtRootTLSGlobal, &emlrtContextGlobal,
                           &emlrtLockerFunction, omp_get_num_procs(), NULL);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_dev_custlay_paraContrasts_mex.c) */
