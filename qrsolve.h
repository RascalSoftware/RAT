//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// qrsolve.h
//
// Code generation for function 'qrsolve'
//
#ifndef QRSOLVE_H
#define QRSOLVE_H

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
      void LSQFromQR(const ::coder::array<double, 2U> &A, const ::coder::array<
                     double, 1U> &tau, const ::coder::array<int, 2U> &jpvt, ::
                     coder::array<double, 1U> &B, int rankA, ::coder::array<
                     double, 1U> &Y);
      void qrsolve(const ::coder::array<double, 1U> &A, const ::coder::array<
                   double, 2U> &B, ::coder::array<double, 2U> &Y);
      int rankFromQR(const ::coder::array<double, 2U> &A);
    }
  }
}

#endif

// End of code generation (qrsolve.h)
