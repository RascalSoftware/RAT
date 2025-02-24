//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xnrm2.h
//
// Code generation for function 'xnrm2'
//
#ifndef XNRM2_H
#define XNRM2_H

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
        double b_xnrm2(int n, const ::coder::array<double, 1U> &x);
        double xnrm2(int n, const ::coder::array<double, 1U> &x);
        double xnrm2(int n, const ::coder::array<creal_T, 2U> &x, int ix0);
        double xnrm2(int n, const ::coder::array<double, 2U> &x, int ix0);
        double xnrm2(int n, const double x[3]);
      }
    }
  }
}

#endif

// End of code generation (xnrm2.h)
