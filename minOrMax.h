//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void c_binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::array<
    double, 2U> &in2, const ::coder::array<double, 2U> &in3);
  namespace coder
  {
    namespace internal
    {
      double b_maximum(const double x[2]);
      void maximum(const ::coder::array<double, 2U> &x, ::coder::array<double,
                   2U> &ex);
      double maximum(const ::coder::array<double, 1U> &x);
      double maximum(const ::coder::array<double, 2U> &x);
      void maximum(const ::coder::array<double, 2U> &x, double ex[2]);
      double maximum(const double x[3]);
      double minimum(const ::coder::array<double, 1U> &x, int &idx);
      double minimum(const double x[2]);
      double minimum(const double x[50], int &idx);
      void minimum(const ::coder::array<double, 2U> &x, double ex[2]);
    }
  }
}

#endif

// End of code generation (minOrMax.h)
