//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// lusolve.h
//
// Code generation for function 'lusolve'
//
#ifndef LUSOLVE_H
#define LUSOLVE_H

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
      void lusolve(const ::coder::array<real_T, 2U> &A, const ::coder::array<
                   real_T, 2U> &B, ::coder::array<real_T, 2U> &X);
    }
  }
}

#endif

// End of code generation (lusolve.h)
