/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_standardTF_stanlay_parallel_mex.c
 *
 * Code generation for function '_coder_standardTF_stanlay_parallel_mex'
 *
 */

/* Include files */
#include "standardTF_stanlay_parallel.h"
#include "_coder_standardTF_stanlay_parallel_mex.h"
#include "standardTF_stanlay_parallel_terminate.h"
#include "_coder_standardTF_stanlay_parallel_api.h"
#include "standardTF_stanlay_parallel_initialize.h"
#include "standardTF_stanlay_parallel_data.h"

/* Variable Definitions */
static jmp_buf emlrtJBEnviron;

/* Function Declarations */
static void c_standardTF_stanlay_parallel_m(int32_T nlhs, mxArray *plhs[15],
  int32_T nrhs, const mxArray *prhs[30]);

/* Function Definitions */
static void c_standardTF_stanlay_parallel_m(int32_T nlhs, mxArray *plhs[15],
  int32_T nrhs, const mxArray *prhs[30])
{
  int32_T n;
  const mxArray *inputs[30];
  const mxArray *outputs[15];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 30) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 30, 4,
                        27, "standardTF_stanlay_parallel");
  }

  if (nlhs > 15) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 27,
                        "standardTF_stanlay_parallel");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  standardTF_stanlay_parallel_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  standardTF_stanlay_parallel_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexAtExit(standardTF_stanlay_parallel_atexit);

  /* Initialize the memory manager. */
  omp_init_lock(&emlrtLockGlobal);
  omp_init_nest_lock(&emlrtNestLockGlobal);
  emlrtLoadLibrary("/usr/local/MATLAB/R2016b/sys/os/glnxa64/libiomp5.so");

  /* Module initialization. */
  standardTF_stanlay_parallel_initialize();
  st.tls = emlrtRootTLSGlobal;
  emlrtSetJmpBuf(&st, &emlrtJBEnviron);
  if (setjmp(emlrtJBEnviron) == 0) {
    /* Dispatch the entry-point. */
    c_standardTF_stanlay_parallel_m(nlhs, plhs, nrhs, prhs);
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
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal,
                     emlrtLockerFunction, omp_get_num_procs());
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_standardTF_stanlay_parallel_mex.c) */
