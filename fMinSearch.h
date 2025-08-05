//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct ProblemDefinition;
  struct i_struct_T;
  struct g_struct_T;
}

// Function Declarations
namespace RAT
{
  double fMinSearch(::coder::array<double, 1U> &x, double options_MaxIter,
                    double options_MaxFunEvals, double options_TolX, double
                    options_TolFun, const char dis_data[], const int dis_size[2],
                    const ProblemDefinition &varargin_1, const char
                    varargin_2_parallel_data[], const int
                    varargin_2_parallel_size[2], double
                    varargin_2_numSimulationPoints, double
                    varargin_2_resampleMinAngle, double
                    varargin_2_resampleNPoints, double varargin_2_updateFreq,
                    double varargin_2_updatePlotFreq, boolean_T
                    varargin_2_calcSLD, const char varargin_2_IPCFilePath_data[],
                    const int varargin_2_IPCFilePath_size[2], const i_struct_T
                    &varargin_3, g_struct_T &output, double &exitflag);
}

#endif

// End of code generation (fMinSearch.h)
