//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  shiftdata.h
//
//  Code generation for function 'shiftdata'
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
void shiftdata(const emlrtStack *sp, real_T scalefac, real_T horshift, real_T
               dataPresent, coder::array<real_T, 2U> &data, const real_T
               dataLimits[2]);

// End of code generation (shiftdata.h)
