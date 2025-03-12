//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// mrdivide_helper.h
//
// Code generation for function 'mrdivide_helper'
//
#ifndef MRDIVIDE_HELPER_H
#define MRDIVIDE_HELPER_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::array<
                        double, 2U> &in2, int in3, const ::coder::array<double,
                        2U> &in4, const ::coder::array<double, 2U> &in5);
  void binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::array<
                        double, 1U> &in2, const ::coder::array<double, 2U> &in3,
                        const ::coder::array<int, 1U> &in4, const int in5_data[],
                        const int &in5_size);
  void c_binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::array<
    double, 2U> &in2, int in3, const ::coder::array<double, 2U> &in4, const ::
    coder::array<double, 2U> &in5);
  namespace coder
  {
    namespace internal
    {
      void mrdiv(const ::coder::array<double, 2U> &A, const ::coder::array<
                 double, 2U> &B, ::coder::array<double, 2U> &Y);
      void mrdiv(const ::coder::array<double, 2U> &A, const ::coder::array<
                 double, 2U> &B, ::coder::array<double, 1U> &Y);
      void mrdiv(const ::coder::array<double, 1U> &A, const ::coder::array<
                 double, 1U> &B, ::coder::array<double, 2U> &Y);
    }
  }
}

#endif

// End of code generation (mrdivide_helper.h)
