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
  struct e_struct_T;
  struct struct3_T;
  struct m_struct_T;
  struct l_struct_T;
}

// Function Declarations
namespace RAT
{
  void fMinSearch(::coder::array<real_T, 1U> &x, real_T options_MaxIter, real_T
                  options_MaxFunEvals, real_T options_TolX, real_T
                  options_TolFun, const char_T dis_data[], const int32_T
                  dis_size[2], const e_struct_T *varargin_1, const ::coder::
                  array<real_T, 2U> &varargin_2_param, const ::coder::array<
                  real_T, 2U> &varargin_2_backgroundParam, const ::coder::array<
                  real_T, 2U> &varargin_2_scalefactor, const ::coder::array<
                  real_T, 2U> &varargin_2_qzshift, const ::coder::array<real_T,
                  2U> &varargin_2_bulkIn, const ::coder::array<real_T, 2U>
                  &varargin_2_bulkOut, const ::coder::array<real_T, 2U>
                  &varargin_2_resolutionParam, const ::coder::array<real_T, 2U>
                  &varargin_2_domainRatio, const struct3_T *varargin_3, const
                  m_struct_T *varargin_4, real_T *fval, real_T *exitflag,
                  l_struct_T *output);
}

#endif

// End of code generation (fMinSearch.h)
