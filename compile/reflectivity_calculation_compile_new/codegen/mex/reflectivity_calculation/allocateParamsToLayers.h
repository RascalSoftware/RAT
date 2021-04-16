//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  allocateParamsToLayers.h
//
//  Code generation for function 'allocateParamsToLayers'
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
#include "omp.h"
#include "reflectivity_calculation_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
void allocateParamsToLayers(const emlrtStack *sp, const coder::array<real_T, 2U>
  &params, const coder::array<cell_wrap_2, 1U> &layersDetails, coder::array<
  cell_wrap_15, 2U> &outLayers);

// End of code generation (allocateParamsToLayers.h)
