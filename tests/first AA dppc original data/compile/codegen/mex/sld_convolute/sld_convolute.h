//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  sld_convolute.h
//
//  Code generation for function 'sld_convolute'
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
CODEGEN_EXPORT_SYM void sld_convolute(const emlrtStack *sp, const coder::array<
  real_T, 2U> &b_signal, const coder::array<real_T, 2U> &filter, coder::array<
  real_T, 2U> &res);

// End of code generation (sld_convolute.h)
