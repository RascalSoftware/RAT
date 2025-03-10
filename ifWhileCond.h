//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
      boolean_T ifWhileCond(const ::coder::array<boolean_T, 1U> &x);
    }
  }
}

#endif

// End of code generation (ifWhileCond.h)
