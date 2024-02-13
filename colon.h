//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// colon.h
//
// Code generation for function 'colon'
//
#ifndef COLON_H
#define COLON_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    void eml_float_colon(real_T a, real_T d, real_T b, ::coder::array<real_T, 2U>
                         &y);
    void eml_integer_colon_dispatcher(int32_T b, ::coder::array<int32_T, 2U> &y);
  }
}

#endif

// End of code generation (colon.h)
