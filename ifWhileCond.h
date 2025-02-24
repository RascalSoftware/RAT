//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// ifWhileCond.h
//
// Code generation for function 'ifWhileCond'
//
#ifndef IFWHILECOND_H
#define IFWHILECOND_H

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
    namespace internal
    {
      boolean_T b_ifWhileCond(const boolean_T x_data[], const int x_size[2]);
      boolean_T c_ifWhileCond(const ::coder::array<boolean_T, 2U> &x);
      boolean_T ifWhileCond(const boolean_T x_data[], int x_size);
    }
  }
}

#endif

// End of code generation (ifWhileCond.h)
