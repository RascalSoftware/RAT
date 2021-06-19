//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  linspace.h
//
//  Code generation for function 'linspace'
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
void linspace(const emlrtStack *sp, real_T d1, real_T d2, real_T n1, coder::
              array<real_T, 2U> &y);

// End of code generation (linspace.h)
