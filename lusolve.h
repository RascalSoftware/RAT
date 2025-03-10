//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      void lusolve(const ::coder::array<double, 2U> &A, const ::coder::array<
                   double, 2U> &B, ::coder::array<double, 2U> &X);
    }
  }
}

#endif

// End of code generation (lusolve.h)
