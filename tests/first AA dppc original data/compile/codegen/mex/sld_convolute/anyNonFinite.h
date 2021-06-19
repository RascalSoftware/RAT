//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  anyNonFinite.h
//
//  Code generation for function 'anyNonFinite'
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
#include "sld_convolute_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
boolean_T anyNonFinite(const emlrtStack *sp, const coder::array<real_T, 2U> &x);

// End of code generation (anyNonFinite.h)
