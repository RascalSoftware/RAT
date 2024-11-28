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
  struct struct3_T;
  struct f_struct_T;
}

// Function Declarations
namespace RAT
{
  void runSimplex(e_struct_T *problemStruct, const ::coder::array<real_T, 2U>
                  &problemLimits_param, const ::coder::array<real_T, 2U>
                  &problemLimits_backgroundParam, const ::coder::array<real_T,
                  2U> &problemLimits_scalefactor, const ::coder::array<real_T,
                  2U> &problemLimits_qzshift, const ::coder::array<real_T, 2U>
                  &problemLimits_bulkIn, const ::coder::array<real_T, 2U>
                  &problemLimits_bulkOut, const ::coder::array<real_T, 2U>
                  &problemLimits_resolutionParam, const ::coder::array<real_T,
                  2U> &problemLimits_domainRatio, const struct3_T *controls,
                  f_struct_T *result);
}

#endif

// End of code generation (runSimplex.h)
