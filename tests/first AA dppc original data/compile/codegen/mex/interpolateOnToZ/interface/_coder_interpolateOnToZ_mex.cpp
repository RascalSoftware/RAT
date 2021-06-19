//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  _coder_interpolateOnToZ_mex.cpp
//
//  Code generation for function '_coder_interpolateOnToZ_mex'
//


// Include files
#include "_coder_interpolateOnToZ_mex.h"
#include "_coder_interpolateOnToZ_api.h"
#include "interpolateOnToZ.h"
#include "interpolateOnToZ_data.h"
#include "interpolateOnToZ_initialize.h"
#include "interpolateOnToZ_mexutil.h"
#include "interpolateOnToZ_terminate.h"

// Function Declarations
MEXFUNCTION_LINKAGE void interpolateOnToZ_mexFunction(int32_T nlhs, mxArray
  *plhs[1], int32_T nrhs, const mxArray *prhs[3]);

// Function Definitions
void interpolateOnToZ_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
  const mxArray *prhs[3])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  st.tls = emlrtRootTLSGlobal;

  // Check for proper number of arguments.
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        16, "interpolateOnToZ");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 16,
                        "interpolateOnToZ");
  }

  // Call the function.
  interpolateOnToZ_api(prhs, nlhs, outputs);

  // Copy over outputs to the caller.
  emlrtReturnArrays(1, plhs, &outputs[0]);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  mexAtExit(&interpolateOnToZ_atexit);
  emlrtLoadMATLABLibrary("sys/os/glnxa64/libiomp5.so");

  // Initialize the memory manager.
  omp_init_lock(&emlrtLockGlobal);
  omp_init_nest_lock(&emlrtNestLockGlobal);

  // Module initialization.
  interpolateOnToZ_initialize();
  st.tls = emlrtRootTLSGlobal;
  try {
    // Dispatch the entry-point.
    interpolateOnToZ_mexFunction(nlhs, plhs, nrhs, prhs);

    // Module termination.
    interpolateOnToZ_terminate();
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&emlrtNestLockGlobal);
  } catch (...) {
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&emlrtNestLockGlobal);
    emlrtReportParallelRunTimeError(&st);
  }
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal,
                     &emlrtLockerFunction, omp_get_num_procs());
  return emlrtRootTLSGlobal;
}

// End of code generation (_coder_interpolateOnToZ_mex.cpp)
