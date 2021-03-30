//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  sldFunc.h
//
//  Code generation for function 'sldFunc'
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
void sldFunc(const emlrtStack *sp, real_T x, const coder::array<real_T, 2U> &SLD,
             coder::array<real_T, 1U> &sldVal);

// End of code generation (sldFunc.h)
