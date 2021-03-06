//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  asymconvstep.h
//
//  Code generation for function 'asymconvstep'
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
void asymconvstep(const emlrtStack *sp, const coder::array<real_T, 2U> &x,
                  real_T xw, real_T xcen, real_T s1, real_T s2, real_T h, coder::
                  array<real_T, 2U> &f);

// End of code generation (asymconvstep.h)
