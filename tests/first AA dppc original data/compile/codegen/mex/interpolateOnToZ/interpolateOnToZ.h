//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  interpolateOnToZ.h
//
//  Code generation for function 'interpolateOnToZ'
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
#include "interpolateOnToZ_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
CODEGEN_EXPORT_SYM void interpolateOnToZ(const emlrtStack *sp, const coder::
  array<real_T, 1U> &X, const coder::array<real_T, 1U> &Y, const coder::array<
  real_T, 2U> &z, coder::array<real_T, 2U> &newY);

// End of code generation (interpolateOnToZ.h)
