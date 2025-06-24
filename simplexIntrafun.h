//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// simplexIntrafun.h
//
// Code generation for function 'simplexIntrafun'
//
#ifndef SIMPLEXINTRAFUN_H
#define SIMPLEXINTRAFUN_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct ProblemDefinition;
  struct Results;
}

// Function Declarations
namespace RAT
{
  double simplexIntrafun(const ::coder::array<double, 1U> &x, ProblemDefinition
    &problemStruct, const char controls_parallel_data[], const int
    controls_parallel_size[2], boolean_T controls_calcSldDuringFit, double
    controls_numSimulationPoints, double controls_resampleMinAngle, double
    controls_resampleNPoints, const ::coder::array<double, 1U> &params_LB, const
    ::coder::array<double, 1U> &params_UB, const ::coder::array<double, 1U>
    &params_BoundClass, Results &result);
}

#endif

// End of code generation (simplexIntrafun.h)
