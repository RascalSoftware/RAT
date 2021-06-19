//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// interp1.h
//
// Code generation for function 'interp1'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mex.h"
#include "omp.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
namespace coder {
void interp1(const emlrtStack *sp, const ::coder::array<real_T, 1U> &varargin_1,
             const ::coder::array<real_T, 1U> &varargin_2,
             const ::coder::array<real_T, 2U> &varargin_3,
             ::coder::array<real_T, 2U> &Vq);

}

// End of code generation (interp1.h)
