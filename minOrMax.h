//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// minOrMax.h
//
// Code generation for function 'minOrMax'
//
#ifndef MINORMAX_H
#define MINORMAX_H

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
      double b_maximum(const double x[3]);
      void maximum(const ::coder::array<double, 2U> &x, ::coder::array<double,
                   2U> &ex);
      double maximum(const ::coder::array<double, 1U> &x);
      double maximum(const ::coder::array<double, 2U> &x);
      void maximum(const ::coder::array<double, 2U> &x, double ex[2]);
      double maximum(const double x[2]);
      void maximum2(const ::coder::array<double, 1U> &x, double y, ::coder::
                    array<double, 1U> &ex);
      void maximum2(const ::coder::array<double, 1U> &x, const ::coder::array<
                    double, 1U> &y, ::coder::array<double, 1U> &ex);
      void minimum(const ::coder::array<double, 1U> &x, double *ex, int *idx);
      double minimum(const double x[2]);
      void minimum(const double x[50], double *ex, int *idx);
      void minimum(const ::coder::array<double, 2U> &x, double ex[2]);
      void minimum2(const ::coder::array<double, 1U> &x, double y, ::coder::
                    array<double, 1U> &ex);
      void minimum2(const ::coder::array<double, 1U> &y, ::coder::array<double,
                    1U> &ex);
    }
  }
}

#endif

// End of code generation (minOrMax.h)
