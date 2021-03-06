//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  _coder_reflectivity_calculation_gpu_api.h
//
//  Code generation for function '_coder_reflectivity_calculation_gpu_api'
//


#pragma once

// Include files
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "reflectivity_calculation_gpu_types.h"

// Custom Header Code
#ifdef __CUDA_ARCH__
#undef printf
#endif

// Function Declarations
void reflectivity_calculation_gpu_api(const mxArray * const prhs[4], int32_T
  nlhs, const mxArray *plhs[2]);

// End of code generation (_coder_reflectivity_calculation_gpu_api.h)
