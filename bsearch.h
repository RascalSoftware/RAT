//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// bsearch.h
//
// Code generation for function 'bsearch'
//
#ifndef BSEARCH_H
#define BSEARCH_H

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
      int32_T b_bsearch(const real_T x_data[], real_T xi);
      int32_T b_bsearch(const ::coder::array<real_T, 1U> &x, real_T xi);
      int32_T c_bsearch(const real_T x[3], real_T xi);
    }
  }
}

#endif

// End of code generation (bsearch.h)
