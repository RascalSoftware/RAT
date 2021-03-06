//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  reflectivity_calculation_gpu_terminate.cu
//
//  Code generation for function 'reflectivity_calculation_gpu_terminate'
//


// Include files
#include "reflectivity_calculation_gpu_terminate.h"
#include "_coder_reflectivity_calculation_gpu_mex.h"
#include "reflectivity_calculation_gpu.h"
#include "reflectivity_calculation_gpu_data.h"
#include "rt_nonfinite.h"

// Function Definitions
void reflectivity_calculation_gpu_atexit()
{
  mexFunctionCreateRootTLS();
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void reflectivity_calculation_gpu_terminate()
{
  cudaError_t errCode;
  errCode = cudaGetLastError();
  if (errCode != cudaSuccess) {
    emlrtThinCUDAError(false, emlrtRootTLSGlobal);
  }

  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

// End of code generation (reflectivity_calculation_gpu_terminate.cu)
