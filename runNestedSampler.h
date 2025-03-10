//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
  struct NestedSamplerOutput;
  struct DreamParams;
  struct DreamOutput;
}

// Function Declarations
namespace RAT
{
  void runNestedSampler(ProblemDefinition &problemStruct, const ::coder::array<
                        double, 2U> &problemLimits_params, const ::coder::array<
                        double, 2U> &problemLimits_backgroundParams, const ::
                        coder::array<double, 2U> &problemLimits_scalefactors,
                        const ::coder::array<double, 2U> &problemLimits_bulkIns,
                        const ::coder::array<double, 2U> &problemLimits_bulkOuts,
                        const ::coder::array<double, 2U>
                        &problemLimits_resolutionParams, const ::coder::array<
                        double, 2U> &problemLimits_domainRatios, const Controls *
                        controls, Results *result, PredictionIntervals &
                        bayesResults_predictionIntervals, ConfidenceIntervals &
                        bayesResults_confidenceIntervals, NestedSamplerOutput &
                        bayesResults_nestedSamplerOutput, ::coder::array<double,
                        2U> &bayesResults_chain, DreamParams &
                        bayesResults_dreamParams, DreamOutput &
                        bayesResults_dreamOutput);
}

#endif

// End of code generation (runNestedSampler.h)
