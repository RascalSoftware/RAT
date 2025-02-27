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
  struct ProblemDefinition;
  struct Controls;
  struct Results;
  struct PredictionIntervals;
  struct ConfidenceIntervals;
  struct DreamParams;
  struct DreamOutput;
  struct NestedSamplerOutput;
}

// Function Declarations
namespace RAT
{
  void runNestedSampler(ProblemDefinition *problemStruct, const ::coder::array<
                        double, 2U> &problemLimits_params, const ::coder::array<
                        double, 2U> &problemLimits_backgroundParams, const ::
                        coder::array<double, 2U> &problemLimits_scalefactors,
                        const ::coder::array<double, 2U> &problemLimits_bulkIns,
                        const ::coder::array<double, 2U> &problemLimits_bulkOuts,
                        const ::coder::array<double, 2U>
                        &problemLimits_resolutionParams, const ::coder::array<
                        double, 2U> &problemLimits_domainRatios, const Controls *
                        controls, Results *result, PredictionIntervals
                        *bayesResults_predictionIntervals, ConfidenceIntervals
                        *bayesResults_confidenceIntervals, DreamParams
                        *bayesResults_dreamParams, DreamOutput
                        *bayesResults_dreamOutput, NestedSamplerOutput
                        *bayesResults_nestedSamplerOutput, ::coder::array<double,
                        2U> &bayesResults_chain);
}

#endif

// End of code generation (runNestedSampler.h)
