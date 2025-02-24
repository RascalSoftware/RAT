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
  struct ProblemDefinition;
  struct j_struct_T;
  struct h_struct_T;
}

// Function Declarations
namespace RAT
{
  void fMinSearch(::coder::array<double, 1U> &x, double options_MaxIter, double
                  options_MaxFunEvals, double options_TolX, double
                  options_TolFun, const char dis_data[], const int dis_size[2],
                  const ProblemDefinition *varargin_1, const char
                  varargin_2_parallel_data[], const int
                  varargin_2_parallel_size[2], double
                  varargin_2_resampleMinAngle, double varargin_2_resampleNPoints,
                  boolean_T varargin_2_calcSldDuringFit, double
                  varargin_2_updateFreq, double varargin_2_updatePlotFreq, const
                  char varargin_2_IPCFilePath_data[], const int
                  varargin_2_IPCFilePath_size[2], const j_struct_T *varargin_3,
                  double *fval, double *exitflag, h_struct_T *output);
}

#endif

// End of code generation (fMinSearch.h)
