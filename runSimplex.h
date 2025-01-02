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
  struct e_struct_T;
  struct struct4_T;
  struct struct6_T;
}

// Function Declarations
namespace RAT
{
  void runSimplex(e_struct_T *problemStruct, const ::coder::array<real_T, 2U>
                  &problemLimits_params, const ::coder::array<real_T, 2U>
                  &problemLimits_backgroundParams, const ::coder::array<real_T,
                  2U> &problemLimits_scalefactors, const ::coder::array<real_T,
                  2U> &problemLimits_qzshifts, const ::coder::array<real_T, 2U>
                  &problemLimits_bulkIns, const ::coder::array<real_T, 2U>
                  &problemLimits_bulkOuts, const ::coder::array<real_T, 2U>
                  &problemLimits_resolutionParams, const ::coder::array<real_T,
                  2U> &problemLimits_domainRatios, const struct4_T *controls,
                  struct6_T *result);
}

#endif

// End of code generation (runSimplex.h)
