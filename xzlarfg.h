//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xzlarfg.h
//
// Code generation for function 'xzlarfg'
//
#ifndef XZLARFG_H
#define XZLARFG_H

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
        real_T xzlarfg(int32_T n, real_T *alpha1, ::coder::array<real_T, 1U> &x);
        real_T xzlarfg(int32_T n, real_T *alpha1, ::coder::array<real_T, 2U> &x,
                       int32_T ix0);
        real_T xzlarfg(int32_T n, real_T *alpha1, real_T x[3]);
      }
    }
  }
}

#endif

// End of code generation (xzlarfg.h)
