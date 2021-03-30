//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  chiSquared.h
//
//  Code generation for function 'chiSquared'
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
real_T chiSquared(const emlrtStack *sp, const coder::array<real_T, 2U> &thisData,
                  const coder::array<real_T, 2U> &thisFit, real_T P);

// End of code generation (chiSquared.h)
