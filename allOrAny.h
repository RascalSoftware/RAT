//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// allOrAny.h
//
// Code generation for function 'allOrAny'
//
#ifndef ALLORANY_H
#define ALLORANY_H

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
      boolean_T c_anon(int n, const ::coder::array<boolean_T, 1U> &X);
      boolean_T d_anon(const boolean_T X_data[]);
      void e_anon(const boolean_T X_data[], boolean_T Y_data[]);
    }
  }
}

#endif

// End of code generation (allOrAny.h)
