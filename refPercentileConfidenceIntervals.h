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
  struct e_struct_T;
  struct struct4_T;
  struct cell_wrap_7;
  struct cell_wrap_9;
  struct cell_wrap_11;
}

// Function Declarations
namespace RAT
{
  void refPercentileConfidenceIntervals(const ::coder::array<real_T, 2U>
    &bayesOutputs_chain, e_struct_T *problemStruct, const struct4_T *controls,
    const ::coder::array<cell_wrap_7, 1U> &results_reflectivity, const ::coder::
    array<cell_wrap_9, 2U> &results_sldProfiles, ::coder::array<cell_wrap_11, 1U>
    &allPredInts_reflectivity, ::coder::array<cell_wrap_11, 2U> &allPredInts_sld,
    real_T allPredInts_sampleChi[1000]);
}

#endif

// End of code generation (refPercentileConfidenceIntervals.h)
