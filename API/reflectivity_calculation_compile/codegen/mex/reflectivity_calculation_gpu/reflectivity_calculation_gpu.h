//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  reflectivity_calculation_gpu.h
//
//  Code generation for function 'reflectivity_calculation_gpu'
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
CODEGEN_EXPORT_SYM void reflectivity_calculation_gpu(const struct0_T *problemDef,
  const cell_10 *problemDef_cells, const struct1_T *problemDef_limits, const
  struct2_T *controls, struct4_T *problem, cell_13 *result);

// End of code generation (reflectivity_calculation_gpu.h)
