//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// find.h
//
// Code generation for function 'find'
//
#ifndef FIND_H
#define FIND_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void binary_expand_op(::coder::array<int, 1U> &in1, const ::coder::array<
                        double, 1U> &in2, const ::coder::array<double, 1U> &in3);
  void binary_expand_op(::coder::array<int, 1U> &in1, const ::coder::array<
                        double, 2U> &in2, const ::coder::array<double, 2U> &in3);
  void c_binary_expand_op(::coder::array<int, 1U> &in1, const ::coder::array<
    double, 2U> &in2, const ::coder::array<double, 2U> &in3);
  namespace coder
  {
    int b_eml_find(const ::coder::array<boolean_T, 1U> &x, int i_data[]);
    void c_eml_find(const ::coder::array<boolean_T, 1U> &x, ::coder::array<int,
                    1U> &i);
    void d_eml_find(const ::coder::array<double, 2U> &x, int i_data[], int
                    i_size[2]);
    void e_eml_find(const boolean_T x[2], int i_data[], int i_size[2]);
    void eml_find(const ::coder::array<boolean_T, 1U> &x, ::coder::array<int, 1U>
                  &i);
    void f_eml_find(const ::coder::array<boolean_T, 2U> &x, ::coder::array<int,
                    1U> &i);
    void g_eml_find(const ::coder::array<boolean_T, 2U> &x, ::coder::array<int,
                    2U> &i);
  }
}

#endif

// End of code generation (find.h)
