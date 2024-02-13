//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// fMinSearch.h
//
// Code generation for function 'fMinSearch'
//
#ifndef FMINSEARCH_H
#define FMINSEARCH_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct d_struct_T;
  struct cell_wrap_2;
  struct cell_wrap_8;
  struct cell_wrap_1;
  struct struct2_T;
  struct l_struct_T;
  struct j_struct_T;
}

// Function Declarations
namespace RAT
{
  void fMinSearch(::coder::array<real_T, 1U> &x, real_T options_MaxIter, real_T
                  options_MaxFunEvals, real_T options_TolX, real_T
                  options_TolFun, const char_T dis_data[], const int32_T
                  dis_size[2], const d_struct_T *varargin_1, const ::coder::
                  array<cell_wrap_2, 2U> &varargin_2_f1, const ::coder::array<
                  cell_wrap_8, 2U> &varargin_2_f2, const ::coder::array<
                  cell_wrap_2, 2U> &varargin_2_f3, const ::coder::array<
                  cell_wrap_2, 2U> &varargin_2_f4, const ::coder::array<
                  cell_wrap_8, 2U> &varargin_2_f5, const ::coder::array<
                  cell_wrap_8, 1U> &varargin_2_f6, const ::coder::array<
                  cell_wrap_1, 2U> &varargin_2_f14, const ::coder::array<
                  cell_wrap_8, 2U> &varargin_2_f19, const struct2_T *varargin_3,
                  const l_struct_T *varargin_4, real_T *fval, real_T *exitflag,
                  j_struct_T *output);
}

#endif

// End of code generation (fMinSearch.h)
