//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// makeEmptyBayesResultsStruct.h
//
// Code generation for function 'makeEmptyBayesResultsStruct'
//
#ifndef MAKEEMPTYBAYESRESULTSSTRUCT_H
#define MAKEEMPTYBAYESRESULTSSTRUCT_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct cell_wrap_11;
  struct DreamParams;
  struct DreamOutput;
  struct c_struct_T;
}

// Function Declarations
namespace RAT
{
  void b_makeEmptyBayesResultsStruct(double nContrasts, boolean_T isDomains, ::
    coder::array<cell_wrap_11, 1U>
    &bayesResults_predictionIntervals_reflectivity, ::coder::array<cell_wrap_11,
    2U> &bayesResults_predictionIntervals_sld, double
    bayesResults_predictionIntervals_sampleChi_data[], int
    *bayesResults_predictionIntervals_sampleChi_size, ::coder::array<double, 2U>
    &bayesResults_confidenceIntervals_percentile95, ::coder::array<double, 2U>
    &bayesResults_confidenceIntervals_percentile65, ::coder::array<double, 2U>
    &bayesResults_confidenceIntervals_mean, DreamParams
    *bayesResults_dreamParams, DreamOutput *bayesResults_dreamOutput, c_struct_T
    *bayesResults_nestedSamplerOutput, ::coder::array<double, 2U>
    &bayesResults_chain);
  void makeEmptyBayesResultsStruct(double nContrasts, boolean_T isDomains,
    double nChains, ::coder::array<cell_wrap_11, 1U>
    &bayesResults_predictionIntervals_reflectivity, ::coder::array<cell_wrap_11,
    2U> &bayesResults_predictionIntervals_sld, double
    bayesResults_predictionIntervals_sampleChi_data[], int
    *bayesResults_predictionIntervals_sampleChi_size, ::coder::array<double, 2U>
    &bayesResults_confidenceIntervals_percentile95, ::coder::array<double, 2U>
    &bayesResults_confidenceIntervals_percentile65, ::coder::array<double, 2U>
    &bayesResults_confidenceIntervals_mean, DreamParams
    *bayesResults_dreamParams, DreamOutput *bayesResults_dreamOutput, c_struct_T
    *bayesResults_nestedSamplerOutput, ::coder::array<double, 2U>
    &bayesResults_chain);
}

#endif

// End of code generation (makeEmptyBayesResultsStruct.h)
