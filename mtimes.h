//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// mtimes.h
//
// Code generation for function 'mtimes'
//
#ifndef MTIMES_H
#define MTIMES_H

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
      namespace blas
      {
        void b_mtimes(const ::coder::array<double, 2U> &A, const ::coder::array<
                      double, 2U> &B, ::coder::array<double, 2U> &C);
        void mtimes(const ::coder::array<creal_T, 2U> &A, const ::coder::array<
                    creal_T, 2U> &B, ::coder::array<creal_T, 2U> &C);
        void mtimes(const ::coder::array<double, 2U> &A, const ::coder::array<
                    double, 2U> &B, ::coder::array<double, 2U> &C);
        void mtimes(const ::coder::array<double, 2U> &A, const ::coder::array<
                    double, 1U> &B, ::coder::array<double, 1U> &C);
      }
    }
  }
}

#endif

// End of code generation (mtimes.h)
