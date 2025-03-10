//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// combineVectorElements.h
//
// Code generation for function 'combineVectorElements'
//
#ifndef COMBINEVECTORELEMENTS_H
#define COMBINEVECTORELEMENTS_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::array<
                        double, 2U> &in2, const ::coder::array<double, 2U> &in3,
                        const ::coder::array<double, 1U> &in4, int in5, int in6,
                        int in7);
  void c_binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::array<
    double, 2U> &in2, const ::coder::array<double, 2U> &in3, const ::coder::
    array<double, 1U> &in4, int in5, int in6, int in7);
  namespace coder
  {
    double b_combineVectorElements(const ::coder::array<double, 1U> &x, int vlen);
    int c_combineVectorElements(const ::coder::array<boolean_T, 1U> &x);
    int combineVectorElements(const ::coder::array<boolean_T, 2U> &x);
  }
}

#endif

// End of code generation (combineVectorElements.h)
