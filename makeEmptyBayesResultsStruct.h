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
  struct cell_wrap_8;
  struct c_struct_T;
}

// Function Declarations
namespace RAT
{
  void b_makeEmptyBayesResultsStruct(real_T nContrasts, boolean_T isDomains, ::
    coder::array<cell_wrap_8, 1U> &bayesResults_bestFitsMean_ref, ::coder::array<
    cell_wrap_8, 2U> &bayesResults_bestFitsMean_sld, real_T
    *bayesResults_bestFitsMean_chi, ::coder::array<cell_wrap_8, 1U>
    &bayesResults_bestFitsMean_data, ::coder::array<cell_wrap_8, 1U>
    &bayesResults_predlims_refPredInts, ::coder::array<cell_wrap_8, 2U>
    &bayesResults_predlims_sldPredInts, ::coder::array<cell_wrap_8, 1U>
    &bayesResults_predlims_refXdata, ::coder::array<cell_wrap_8, 2U>
    &bayesResults_predlims_sldXdata, real_T
    bayesResults_predlims_sampleChi_data[], int32_T
    *bayesResults_predlims_sampleChi_size, ::coder::array<real_T, 2U>
    &bayesResults_parConfInts_par95, ::coder::array<real_T, 2U>
    &bayesResults_parConfInts_par65, ::coder::array<real_T, 2U>
    &bayesResults_parConfInts_mean, ::coder::array<real_T, 2U>
    &bayesResults_bestPars, c_struct_T *bayesResults_bayesRes, ::coder::array<
    real_T, 2U> &bayesResults_chain);
  void makeEmptyBayesResultsStruct(real_T nContrasts, boolean_T isDomains,
    real_T nChains, ::coder::array<cell_wrap_8, 1U>
    &bayesResults_bestFitsMean_ref, ::coder::array<cell_wrap_8, 2U>
    &bayesResults_bestFitsMean_sld, real_T *bayesResults_bestFitsMean_chi, ::
    coder::array<cell_wrap_8, 1U> &bayesResults_bestFitsMean_data, ::coder::
    array<cell_wrap_8, 1U> &bayesResults_predlims_refPredInts, ::coder::array<
    cell_wrap_8, 2U> &bayesResults_predlims_sldPredInts, ::coder::array<
    cell_wrap_8, 1U> &bayesResults_predlims_refXdata, ::coder::array<cell_wrap_8,
    2U> &bayesResults_predlims_sldXdata, real_T
    bayesResults_predlims_sampleChi_data[], int32_T
    *bayesResults_predlims_sampleChi_size, ::coder::array<real_T, 2U>
    &bayesResults_parConfInts_par95, ::coder::array<real_T, 2U>
    &bayesResults_parConfInts_par65, ::coder::array<real_T, 2U>
    &bayesResults_parConfInts_mean, ::coder::array<real_T, 2U>
    &bayesResults_bestPars, c_struct_T *bayesResults_bayesRes, ::coder::array<
    real_T, 2U> &bayesResults_chain);
}

#endif

// End of code generation (makeEmptyBayesResultsStruct.h)
