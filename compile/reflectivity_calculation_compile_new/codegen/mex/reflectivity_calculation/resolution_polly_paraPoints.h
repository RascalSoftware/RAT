//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  resolution_polly_paraPoints.h
//
//  Code generation for function 'resolution_polly_paraPoints'
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
void resolution_polly_paraPoints(const emlrtStack *sp, const coder::array<real_T,
  1U> &xdata, const coder::array<real_T, 1U> &ydata, real_T res, real_T points,
  coder::array<real_T, 1U> &out);

// End of code generation (resolution_polly_paraPoints.h)
