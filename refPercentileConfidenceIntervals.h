//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// refPercentileConfidenceIntervals.h
//
// Code generation for function 'refPercentileConfidenceIntervals'
//
#ifndef REFPERCENTILECONFIDENCEINTERVALS_H
#define REFPERCENTILECONFIDENCEINTERVALS_H

// Include files
#include "RATMain_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct ProblemDefinition;
}

// Function Declarations
namespace RAT
{
  void refPercentileConfidenceIntervals(const ::coder::array<double, 2U>
    &bayesOutputs_chain, ProblemDefinition &problemStruct, const char
    controls_parallel_data[], const int controls_parallel_size[2], double
    controls_numSimulationPoints, double controls_resampleMinAngle, double
    controls_resampleNPoints, const ::coder::array<cell_wrap_7, 1U>
    &results_reflectivity, const ::coder::array<cell_wrap_7, 2U>
    &results_sldProfiles, ::coder::array<cell_wrap_11, 1U>
    &allPredInts_reflectivity, ::coder::array<cell_wrap_11, 2U> &allPredInts_sld,
    double allPredInts_sampleChi[1000]);
  void refPercentileConfidenceIntervals(const ::coder::array<double, 2U>
    &bayesOutputs_chain, ProblemDefinition &problemStruct, const Controls &
    controls, const ::coder::array<cell_wrap_7, 1U> &results_reflectivity, const
    ::coder::array<cell_wrap_7, 2U> &results_sldProfiles, ::coder::array<
    cell_wrap_11, 1U> &allPredInts_reflectivity, ::coder::array<cell_wrap_11, 2U>
    &allPredInts_sld, double allPredInts_sampleChi[1000]);
}

#endif

// End of code generation (refPercentileConfidenceIntervals.h)
