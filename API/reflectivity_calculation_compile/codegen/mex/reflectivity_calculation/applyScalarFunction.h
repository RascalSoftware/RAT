//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  applyScalarFunction.h
//
//  Code generation for function 'applyScalarFunction'
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
void applyScalarFunction(const emlrtStack *sp, const coder::array<real_T, 2U> &x,
  coder::array<real_T, 2U> &z1);

// End of code generation (applyScalarFunction.h)
