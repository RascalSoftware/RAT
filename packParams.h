//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// packParams.h
//
// Code generation for function 'packParams'
//
#ifndef PACKPARAMS_H
#define PACKPARAMS_H

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
  struct cell_wrap_10;
}

// Function Declarations
namespace RAT
{
  void packParams(e_struct_T *problemStruct, const ::coder::array<real_T, 2U>
                  &limits_params, const ::coder::array<real_T, 2U>
                  &limits_backgroundParams, const ::coder::array<real_T, 2U>
                  &limits_scalefactors, const ::coder::array<real_T, 2U>
                  &limits_qzshifts, const ::coder::array<real_T, 2U>
                  &limits_bulkIns, const ::coder::array<real_T, 2U>
                  &limits_bulkOuts, const ::coder::array<real_T, 2U>
                  &limits_resolutionParams, const ::coder::array<real_T, 2U>
                  &limits_domainRatios, ::coder::array<cell_wrap_10, 1U>
                  &fitNames);
}

#endif

// End of code generation (packParams.h)
