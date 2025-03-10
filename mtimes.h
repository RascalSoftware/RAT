//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
        void mtimes(const ::coder::array<double, 2U> &A, const ::coder::array<
                    double, 2U> &B, double C_data[], int C_size[2]);
        void mtimes(const double A_data[], const int A_size[2], const double
                    B_data[], const int B_size[2], double C_data[], int C_size[2]);
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
