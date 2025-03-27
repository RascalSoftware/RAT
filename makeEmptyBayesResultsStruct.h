//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// makeEmptyBayesResultsStruct.h
//
// Code generation for function 'makeEmptyBayesResultsStruct'
//
#ifndef MAKEEMPTYBAYESRESULTSSTRUCT_H
#define MAKEEMPTYBAYESRESULTSSTRUCT_H

// Include files
#include "RATMain_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct struct_T;
}

// Function Declarations
namespace RAT
{
  int b_makeEmptyBayesResultsStruct(double nContrasts, boolean_T isDomains, ::
    coder::array<cell_wrap_11, 1U>
    &bayesResults_predictionIntervals_reflectivity, ::coder::array<cell_wrap_11,
    2U> &bayesResults_predictionIntervals_sld, double
    bayesResults_predictionIntervals_sampleChi_data[], ::coder::array<double, 2U>
    &bayesResults_confidenceIntervals_percentile95, ::coder::array<double, 2U>
    &bayesResults_confidenceIntervals_percentile65, ::coder::array<double, 2U>
    &bayesResults_confidenceIntervals_mean, DreamParams &
    bayesResults_dreamParams, DreamOutput &bayesResults_dreamOutput, struct_T
    &bayesResults_nestedSamplerOutput, ::coder::array<double, 2U>
    &bayesResults_chain);
  int makeEmptyBayesResultsStruct(double nContrasts, boolean_T isDomains, double
    nChains, ::coder::array<cell_wrap_11, 1U>
    &bayesResults_predictionIntervals_reflectivity, ::coder::array<cell_wrap_11,
    2U> &bayesResults_predictionIntervals_sld, double
    bayesResults_predictionIntervals_sampleChi_data[], ::coder::array<double, 2U>
    &bayesResults_confidenceIntervals_percentile95, ::coder::array<double, 2U>
    &bayesResults_confidenceIntervals_percentile65, ::coder::array<double, 2U>
    &bayesResults_confidenceIntervals_mean, DreamParams &
    bayesResults_dreamParams, DreamOutput &bayesResults_dreamOutput, struct_T
    &bayesResults_nestedSamplerOutput, ::coder::array<double, 2U>
    &bayesResults_chain);
}

#endif

// End of code generation (makeEmptyBayesResultsStruct.h)
