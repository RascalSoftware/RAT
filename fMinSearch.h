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
  struct m_struct_T;
  struct k_struct_T;
}

// Function Declarations
namespace RAT
{
  void fMinSearch(::coder::array<real_T, 1U> &x, real_T options_MaxIter, real_T
                  options_MaxFunEvals, real_T options_TolX, real_T
                  options_TolFun, const char_T dis_data[], const int32_T
                  dis_size[2], const e_struct_T *varargin_1, const char_T
                  varargin_2_parallel_data[], const int32_T
                  varargin_2_parallel_size[2], real_T
                  varargin_2_resampleMinAngle, real_T varargin_2_resampleNPoints,
                  boolean_T varargin_2_calcSldDuringFit, real_T
                  varargin_2_updateFreq, real_T varargin_2_updatePlotFreq, const
                  char_T varargin_2_IPCFilePath_data[], const int32_T
                  varargin_2_IPCFilePath_size[2], const m_struct_T *varargin_3,
                  real_T *fval, real_T *exitflag, k_struct_T *output);
}

#endif

// End of code generation (fMinSearch.h)
