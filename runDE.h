//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// runDE.h
//
// Code generation for function 'runDE'
//
#ifndef RUNDE_H
#define RUNDE_H

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
  struct struct6_T;
  struct struct4_T;
}

// Function Declarations
namespace RAT
{
  void intrafun(const ::coder::array<real_T, 2U> &p, e_struct_T *problemStruct,
                const char_T controls_parallel_data[], const int32_T
                controls_parallel_size[2], real_T controls_resampleMinAngle,
                real_T controls_resampleNPoints, boolean_T
                controls_calcSldDuringFit, real_T *S_MSE_I_nc, real_T
                *S_MSE_FVr_ca, real_T *S_MSE_I_no, real_T *S_MSE_FVr_oa,
                struct6_T *result);
  void runDE(e_struct_T *problemStruct, const ::coder::array<real_T, 2U>
             &problemLimits_params, const ::coder::array<real_T, 2U>
             &problemLimits_backgroundParams, const ::coder::array<real_T, 2U>
             &problemLimits_scalefactors, const ::coder::array<real_T, 2U>
             &problemLimits_qzshifts, const ::coder::array<real_T, 2U>
             &problemLimits_bulkIns, const ::coder::array<real_T, 2U>
             &problemLimits_bulkOuts, const ::coder::array<real_T, 2U>
             &problemLimits_resolutionParams, const ::coder::array<real_T, 2U>
             &problemLimits_domainRatios, const struct4_T *controls, struct6_T
             *result);
}

#endif

// End of code generation (runDE.h)
