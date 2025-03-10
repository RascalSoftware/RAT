//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// packParams.h
//
// Code generation for function 'packParams'
//
#ifndef PACKPARAMS_H
#define PACKPARAMS_H

// Include files
#include "RATMain_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct ProblemDefinition;
}

// Function Declarations
namespace RAT
{
  void packParams(ProblemDefinition &problemStruct, const ::coder::array<double,
                  2U> &limits_params, const ::coder::array<double, 2U>
                  &limits_backgroundParams, const ::coder::array<double, 2U>
                  &limits_scalefactors, const ::coder::array<double, 2U>
                  &limits_bulkIns, const ::coder::array<double, 2U>
                  &limits_bulkOuts, const ::coder::array<double, 2U>
                  &limits_resolutionParams, const ::coder::array<double, 2U>
                  &limits_domainRatios, ::coder::array<cell_wrap_10, 1U>
                  &fitNames);
}

#endif

// End of code generation (packParams.h)
