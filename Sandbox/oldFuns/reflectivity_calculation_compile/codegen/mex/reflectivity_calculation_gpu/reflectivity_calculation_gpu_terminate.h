//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  reflectivity_calculation_gpu_terminate.h
//
//  Code generation for function 'reflectivity_calculation_gpu_terminate'
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
CODEGEN_EXPORT_SYM void reflectivity_calculation_gpu_atexit();
CODEGEN_EXPORT_SYM void reflectivity_calculation_gpu_terminate();

// End of code generation (reflectivity_calculation_gpu_terminate.h)
