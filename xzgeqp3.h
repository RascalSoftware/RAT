//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xzgeqp3.h
//
// Code generation for function 'xzgeqp3'
//
#ifndef XZGEQP3_H
#define XZGEQP3_H

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
        void qrpf(::coder::array<real_T, 2U> &A, int32_T m, int32_T n, ::coder::
                  array<real_T, 1U> &tau, ::coder::array<int32_T, 2U> &jpvt);
        void xzgeqp3(::coder::array<real_T, 1U> &A, int32_T m, real_T tau_data[],
                     int32_T *tau_size, int32_T *jpvt);
      }
    }
  }
}

#endif

// End of code generation (xzgeqp3.h)
