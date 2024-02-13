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
      void LSQFromQR(const ::coder::array<real_T, 2U> &A, const ::coder::array<
                     real_T, 1U> &tau, const ::coder::array<int32_T, 2U> &jpvt, ::
                     coder::array<real_T, 1U> &B, int32_T rankA, ::coder::array<
                     real_T, 1U> &Y);
      void qrsolve(const ::coder::array<real_T, 1U> &A, const ::coder::array<
                   real_T, 2U> &B, ::coder::array<real_T, 2U> &Y);
      int32_T rankFromQR(const ::coder::array<real_T, 2U> &A);
    }
  }
}

#endif

// End of code generation (qrsolve.h)
