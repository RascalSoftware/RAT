//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// refPercentileConfidenceIntervals.h
//
// Code generation for function 'refPercentileConfidenceIntervals'
//
#ifndef REFPERCENTILECONFIDENCEINTERVALS_H
#define REFPERCENTILECONFIDENCEINTERVALS_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct g_struct_T;
  struct struct3_T;
  struct struct6_T;
  struct i_struct_T;
}

// Function Declarations
namespace RAT
{
  void refPercentileConfidenceIntervals(const ::coder::array<real_T, 2U>
    &bayesOutputs_chain, g_struct_T *problemStruct, const ::coder::array<real_T,
    2U> &problemLimits_param, const ::coder::array<real_T, 2U>
    &problemLimits_backgroundParam, const ::coder::array<real_T, 2U>
    &problemLimits_scalefactor, const ::coder::array<real_T, 2U>
    &problemLimits_qzshift, const ::coder::array<real_T, 2U>
    &problemLimits_bulkIn, const ::coder::array<real_T, 2U>
    &problemLimits_bulkOut, const ::coder::array<real_T, 2U>
    &problemLimits_resolutionParam, const ::coder::array<real_T, 2U>
    &problemLimits_domainRatio, const struct3_T *controls, const struct6_T
    *results, i_struct_T *allPredInts);
}

#endif

// End of code generation (refPercentileConfidenceIntervals.h)
