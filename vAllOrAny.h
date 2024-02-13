//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// vAllOrAny.h
//
// Code generation for function 'vAllOrAny'
//
#ifndef VALLORANY_H
#define VALLORANY_H

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
      void b_genloops(const ::coder::array<real_T, 2U> &x, boolean_T *p, int32_T
                      varargin_1, int32_T varargin_2);
      boolean_T vAllOrAny(const ::coder::array<real_T, 2U> &x);
    }
  }
}

#endif

// End of code generation (vAllOrAny.h)
