//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// computeNormMTridiagonal.h
//
// Code generation for function 'computeNormMTridiagonal'
//
#ifndef COMPUTENORMMTRIDIAGONAL_H
#define COMPUTENORMMTRIDIAGONAL_H

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
      namespace reflapack
      {
        double computeNormMTridiagonal(int n, const ::coder::array<double, 1U>
          &d, const ::coder::array<double, 1U> &e, int i0);
      }
    }
  }
}

#endif

// End of code generation (computeNormMTridiagonal.h)
