//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// anyNonFinite.h
//
// Code generation for function 'anyNonFinite'
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
namespace internal {
boolean_T anyNonFinite(const emlrtStack *sp,
                       const ::coder::array<real_T, 2U> &x);

}
} // namespace coder

// End of code generation (anyNonFinite.h)
