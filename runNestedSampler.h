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
#include "RATMain_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct ProblemDefinition;
  struct b_struct_T;
}

// Function Declarations
namespace RAT
{
  int runNestedSampler(ProblemDefinition &problemStruct, const char
                       controls_parallel_data[], const int
                       controls_parallel_size[2], double
                       controls_numSimulationPoints, double
                       controls_resampleMinAngle, double
                       controls_resampleNPoints, const char
                       controls_display_data[], const int controls_display_size
                       [2], double controls_nLive, double controls_nMCMC, double
                       controls_nsTolerance, boolean_T controls_calcSLD, const
                       char controls_IPCFilePath_data[], const int
                       controls_IPCFilePath_size[2], b_struct_T &result, ::coder::
                       array<cell_wrap_11, 1U>
                       &bayesResults_predictionIntervals_reflectivity, ::coder::
                       array<cell_wrap_11, 2U>
                       &bayesResults_predictionIntervals_sld, double
                       bayesResults_predictionIntervals_sampleChi_data[],
                       ConfidenceIntervals &bayesResults_confidenceIntervals,
                       NestedSamplerOutput &bayesResults_nestedSamplerOutput, ::
                       coder::array<double, 2U> &bayesResults_chain, DreamParams
                       &bayesResults_dreamParams, DreamOutput &
                       bayesResults_dreamOutput);
}

#endif

// End of code generation (runNestedSampler.h)
