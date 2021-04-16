//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  allocateLayersForContrast.h
//
//  Code generation for function 'allocateLayersForContrast'
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
void allocateLayersForContrast(const emlrtStack *sp, const coder::array<real_T,
  2U> &contrastLayers, const coder::array<cell_wrap_15, 2U>
  &outParameterisedLayers, coder::array<real_T, 2U> &thisContrastLayers);

// End of code generation (allocateLayersForContrast.h)
