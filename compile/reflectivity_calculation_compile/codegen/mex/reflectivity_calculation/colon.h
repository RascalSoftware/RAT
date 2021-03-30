//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  colon.h
//
//  Code generation for function 'colon'
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
void eml_float_colon(const emlrtStack *sp, real_T a, real_T d, real_T b, coder::
                     array<real_T, 2U> &y);

// End of code generation (colon.h)
