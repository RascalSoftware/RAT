//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// runDREAM.h
//
// Code generation for function 'runDREAM'
//
#ifndef RUNDREAM_H
#define RUNDREAM_H

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
  struct e_struct_T;
}

// Function Declarations
namespace RAT
{
  void runDREAM(ProblemDefinition &problemStruct, const Controls *controls, ::
                coder::array<cell_wrap_7, 1U> &result_reflectivity, ::coder::
                array<cell_wrap_7, 1U> &result_simulation, ::coder::array<
                cell_wrap_8, 1U> &result_shiftedData, ::coder::array<cell_wrap_8,
                1U> &result_backgrounds, ::coder::array<cell_wrap_7, 1U>
                &result_resolutions, ::coder::array<cell_wrap_9, 2U>
                &result_sldProfiles, ::coder::array<cell_wrap_9, 2U>
                &result_layers, ::coder::array<cell_wrap_9, 2U>
                &result_resampledLayers, ::coder::array<double, 2U>
                &result_fitParams, ::coder::array<cell_wrap_10, 1U>
                &result_fitNames, e_struct_T &bayesResults, CalculationResults &
                result_calculationResults, ContrastParams &result_contrastParams);
}

#endif

// End of code generation (runDREAM.h)
