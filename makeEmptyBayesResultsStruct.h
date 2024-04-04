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
  struct cell_wrap_10;
  struct struct12_T;
  struct struct13_T;
  struct e_struct_T;
}

// Function Declarations
namespace RAT
{
  void b_makeEmptyBayesResultsStruct(real_T nContrasts, boolean_T isDomains, ::
    coder::array<cell_wrap_10, 1U> &bayesResults_bestFitMean_reflectivity, ::
    coder::array<cell_wrap_10, 2U> &bayesResults_bestFitMean_sld, real_T
    *bayesResults_bestFitMean_chi, ::coder::array<cell_wrap_10, 1U>
    &bayesResults_bestFitMean_data, ::coder::array<cell_wrap_10, 1U>
    &bayesResults_predictionIntervals_reflectivity, ::coder::array<cell_wrap_10,
    2U> &bayesResults_predictionIntervals_sld, ::coder::array<cell_wrap_10, 1U>
    &bayesResults_predictionIntervals_reflectivityXData, ::coder::array<
    cell_wrap_10, 2U> &bayesResults_predictionIntervals_sldXData, real_T
    bayesResults_predictionIntervals_sampleChi_data[], int32_T
    *bayesResults_predictionIntervals_sampleChi_size, ::coder::array<real_T, 2U>
    &bayesResults_confidenceIntervals_percentile95, ::coder::array<real_T, 2U>
    &bayesResults_confidenceIntervals_percentile65, ::coder::array<real_T, 2U>
    &bayesResults_confidenceIntervals_mean, struct12_T *bayesResults_dreamParams,
    struct13_T *bayesResults_dreamOutput, e_struct_T
    *bayesResults_nestedSamplerOutput, ::coder::array<real_T, 2U>
    &bayesResults_chain);
  void makeEmptyBayesResultsStruct(real_T nContrasts, boolean_T isDomains,
    real_T nChains, ::coder::array<cell_wrap_10, 1U>
    &bayesResults_bestFitMean_reflectivity, ::coder::array<cell_wrap_10, 2U>
    &bayesResults_bestFitMean_sld, real_T *bayesResults_bestFitMean_chi, ::coder::
    array<cell_wrap_10, 1U> &bayesResults_bestFitMean_data, ::coder::array<
    cell_wrap_10, 1U> &bayesResults_predictionIntervals_reflectivity, ::coder::
    array<cell_wrap_10, 2U> &bayesResults_predictionIntervals_sld, ::coder::
    array<cell_wrap_10, 1U> &bayesResults_predictionIntervals_reflectivityXData,
    ::coder::array<cell_wrap_10, 2U> &bayesResults_predictionIntervals_sldXData,
    real_T bayesResults_predictionIntervals_sampleChi_data[], int32_T
    *bayesResults_predictionIntervals_sampleChi_size, ::coder::array<real_T, 2U>
    &bayesResults_confidenceIntervals_percentile95, ::coder::array<real_T, 2U>
    &bayesResults_confidenceIntervals_percentile65, ::coder::array<real_T, 2U>
    &bayesResults_confidenceIntervals_mean, struct12_T *bayesResults_dreamParams,
    struct13_T *bayesResults_dreamOutput, e_struct_T
    *bayesResults_nestedSamplerOutput, ::coder::array<real_T, 2U>
    &bayesResults_chain);
}

#endif

// End of code generation (makeEmptyBayesResultsStruct.h)
