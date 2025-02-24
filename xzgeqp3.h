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
        void qrpf(::coder::array<double, 2U> &A, int m, int n, ::coder::array<
                  double, 1U> &tau, ::coder::array<int, 2U> &jpvt);
        void xzgeqp3(::coder::array<double, 1U> &A, int m, double tau_data[],
                     int *tau_size, int *jpvt);
      }
    }
  }
}

#endif

// End of code generation (xzgeqp3.h)
