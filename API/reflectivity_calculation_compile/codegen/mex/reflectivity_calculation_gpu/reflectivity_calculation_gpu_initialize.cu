//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  reflectivity_calculation_gpu_initialize.cu
//
//  Code generation for function 'reflectivity_calculation_gpu_initialize'
//


// Include files
#include "reflectivity_calculation_gpu_initialize.h"
#include "_coder_reflectivity_calculation_gpu_mex.h"
#include "reflectivity_calculation_gpu.h"
#include "reflectivity_calculation_gpu_data.h"
#include "rt_nonfinite.h"

// Function Definitions
void reflectivity_calculation_gpu_initialize()
{
  mex_InitInfAndNan();
  mexFunctionCreateRootTLS();
  emlrtClearAllocCountR2012b(emlrtRootTLSGlobal, false, 0U, 0);
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtLicenseCheckR2012b(emlrtRootTLSGlobal, "Distrib_Computing_Toolbox", 2);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
  cudaGetLastError();
}

// End of code generation (reflectivity_calculation_gpu_initialize.cu)
