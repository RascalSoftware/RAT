//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  _coder_reflectivity_calculation_gpu_mex.cu
//
//  Code generation for function '_coder_reflectivity_calculation_gpu_mex'
//


// Include files
#include "_coder_reflectivity_calculation_gpu_mex.h"
#include "_coder_reflectivity_calculation_gpu_api.h"
#include "reflectivity_calculation_gpu.h"
#include "reflectivity_calculation_gpu_data.h"
#include "reflectivity_calculation_gpu_initialize.h"
#include "reflectivity_calculation_gpu_terminate.h"

// Function Declarations
MEXFUNCTION_LINKAGE void c_reflectivity_calculation_gpu_(int32_T nlhs, mxArray
  *plhs[2], int32_T nrhs, const mxArray *prhs[4]);

// Function Definitions
void c_reflectivity_calculation_gpu_(int32_T nlhs, mxArray *plhs[2], int32_T
  nrhs, const mxArray *prhs[4])
{
  const mxArray *outputs[2];
  int32_T b_nlhs;

  // Check for proper number of arguments.
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal, "EMLRT:runTime:WrongNumberOfInputs",
                        5, 12, 4, 4, 28, "reflectivity_calculation_gpu");
  }

  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal,
                        "EMLRT:runTime:TooManyOutputArguments", 3, 4, 28,
                        "reflectivity_calculation_gpu");
  }

  // Call the function.
  reflectivity_calculation_gpu_api(prhs, nlhs, outputs);

  // Copy over outputs to the caller.
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(&reflectivity_calculation_gpu_atexit);

  // Module initialization.
  reflectivity_calculation_gpu_initialize();

  // Dispatch the entry-point.
  c_reflectivity_calculation_gpu_(nlhs, plhs, nrhs, prhs);

  // Module termination.
  reflectivity_calculation_gpu_terminate();
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

// End of code generation (_coder_reflectivity_calculation_gpu_mex.cu)
