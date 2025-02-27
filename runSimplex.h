//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// runSimplex.h
//
// Code generation for function 'runSimplex'
//
#ifndef RUNSIMPLEX_H
#define RUNSIMPLEX_H

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
  struct Controls;
  struct Results;
}

// Function Declarations
namespace RAT
{
  void runSimplex(ProblemDefinition *problemStruct, const ::coder::array<double,
                  2U> &problemLimits_params, const ::coder::array<double, 2U>
                  &problemLimits_backgroundParams, const ::coder::array<double,
                  2U> &problemLimits_scalefactors, const ::coder::array<double,
                  2U> &problemLimits_bulkIns, const ::coder::array<double, 2U>
                  &problemLimits_bulkOuts, const ::coder::array<double, 2U>
                  &problemLimits_resolutionParams, const ::coder::array<double,
                  2U> &problemLimits_domainRatios, const Controls *controls,
                  Results *result);
}

#endif

// End of code generation (runSimplex.h)
