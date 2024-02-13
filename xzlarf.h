//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xzlarf.h
//
// Code generation for function 'xzlarf'
//
#ifndef XZLARF_H
#define XZLARF_H

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
      namespace reflapack
      {
        void b_xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau, ::coder::
                      array<real_T, 2U> &C, int32_T ic0, int32_T ldc, ::coder::
                      array<real_T, 1U> &work);
        void c_xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau, ::coder::
                      array<real_T, 2U> &C, int32_T ic0, int32_T ldc, ::coder::
                      array<real_T, 1U> &work);
        void xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau, ::coder::
                    array<real_T, 2U> &C, int32_T ic0, int32_T ldc, ::coder::
                    array<real_T, 1U> &work);
      }
    }
  }
}

#endif

// End of code generation (xzlarf.h)
