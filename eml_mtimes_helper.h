//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// eml_mtimes_helper.h
//
// Code generation for function 'eml_mtimes_helper'
//
#ifndef EML_MTIMES_HELPER_H
#define EML_MTIMES_HELPER_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void binary_expand_op(double in1_data[], const ::coder::array<double, 2U> &in2,
                        const ::coder::array<double, 2U> &in3, int in4, const ::
                        coder::array<double, 2U> &in5, int in1_size[2]);
  void binary_expand_op(::coder::array<creal_T, 2U> &in1, const ::coder::array<
                        double, 2U> &in2, const ::coder::array<creal_T, 1U> &in3,
                        const ::coder::array<creal_T, 2U> &in4);
  void binary_expand_op(::coder::array<double, 2U> &in1, double in2, const ::
                        coder::array<double, 2U> &in3, const ::coder::array<
                        double, 2U> &in4);
  void binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::array<
                        double, 2U> &in2, const ::coder::array<double, 2U> &in3);
  void c_binary_expand_op(double in1_data[], const ::coder::array<double, 2U>
    &in2, const ::coder::array<double, 2U> &in3, int in4, const ::coder::array<
    double, 2U> &in5, int in1_size[2]);
}

#endif

// End of code generation (eml_mtimes_helper.h)
