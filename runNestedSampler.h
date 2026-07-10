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
  struct d_struct_T;
}

// Function Declarations
namespace RAT
{
  void runNestedSampler(ProblemDefinition &problemStruct, const char
                        controls_parallel_data[], const int
                        controls_parallel_size[2], double
                        controls_numSimulationPoints, double
                        controls_resampleMinAngle, double
                        controls_resampleNPoints, const char
                        controls_display_data[], const int
                        controls_display_size[2], double controls_nLive, double
                        controls_nMCMC, double controls_nsTolerance, boolean_T
                        controls_calcSLD, const char controls_IPCFilePath_data[],
                        const int controls_IPCFilePath_size[2], ::coder::array<
                        cell_wrap_7, 1U> &result_reflectivity, ::coder::array<
                        cell_wrap_7, 1U> &result_simulation, ::coder::array<
                        cell_wrap_8, 1U> &result_shiftedData, ::coder::array<
                        cell_wrap_8, 1U> &result_backgrounds, ::coder::array<
                        cell_wrap_7, 1U> &result_resolutions, ::coder::array<
                        cell_wrap_9, 2U> &result_sldProfiles, ::coder::array<
                        cell_wrap_9, 2U> &result_layers, ::coder::array<
                        cell_wrap_9, 2U> &result_resampledLayers, ::coder::array<
                        double, 2U> &result_fitParams, ::coder::array<
                        cell_wrap_10, 1U> &result_fitNames, d_struct_T
                        &bayesResults, CalculationResults &
                        result_calculationResults, ContrastParams &
                        result_contrastParams);
}

#endif

// End of code generation (runNestedSampler.h)
