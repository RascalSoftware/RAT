//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// runNestedSampler.h
//
// Code generation for function 'runNestedSampler'
//
#ifndef RUNNESTEDSAMPLER_H
#define RUNNESTEDSAMPLER_H

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
  struct cell_wrap_8;
  struct struct6_T;
  struct struct10_T;
  struct struct11_T;
  struct struct12_T;
  struct struct13_T;
  struct struct14_T;
}

// Function Declarations
namespace RAT
{
  void runNestedSampler(e_struct_T *problemStruct, const ::coder::array<real_T,
                        2U> &problemLimits_params, const ::coder::array<real_T,
                        2U> &problemLimits_backgroundParams, const ::coder::
                        array<real_T, 2U> &problemLimits_scalefactors, const ::
                        coder::array<real_T, 2U> &problemLimits_qzshifts, const ::
                        coder::array<real_T, 2U> &problemLimits_bulkIns, const ::
                        coder::array<real_T, 2U> &problemLimits_bulkOuts, const ::
                        coder::array<real_T, 2U> &problemLimits_resolutionParams,
                        const ::coder::array<real_T, 2U>
                        &problemLimits_domainRatios, const struct4_T *controls,
                        const ::coder::array<cell_wrap_8, 1U>
                        &inPriors_priorNames, const ::coder::array<real_T, 2U>
                        &inPriors_priorValues, struct6_T *result, struct10_T
                        *bayesResults_predictionIntervals, struct11_T
                        *bayesResults_confidenceIntervals, struct12_T
                        *bayesResults_dreamParams, struct13_T
                        *bayesResults_dreamOutput, struct14_T
                        *bayesResults_nestedSamplerOutput, ::coder::array<real_T,
                        2U> &bayesResults_chain);
}

#endif

// End of code generation (runNestedSampler.h)
