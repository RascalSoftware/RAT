//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// makeEmptyResultStruct.h
//
// Code generation for function 'makeEmptyResultStruct'
//
#ifndef MAKEEMPTYRESULTSTRUCT_H
#define MAKEEMPTYRESULTSTRUCT_H

// Include files
#include "RATMain_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void makeEmptyResultStruct(double nContrasts, double nParams, boolean_T
    domains, ::coder::array<cell_wrap_7, 1U> &result_reflectivity, ::coder::
    array<cell_wrap_7, 1U> &result_simulation, ::coder::array<cell_wrap_8, 1U>
    &result_shiftedData, ::coder::array<cell_wrap_8, 1U> &result_backgrounds, ::
    coder::array<cell_wrap_7, 1U> &result_resolutions, ::coder::array<
    cell_wrap_9, 2U> &result_sldProfiles, ::coder::array<cell_wrap_9, 2U>
    &result_layers, ::coder::array<cell_wrap_9, 2U> &result_resampledLayers, ::
    coder::array<double, 2U> &result_fitParams, ::coder::array<cell_wrap_10, 1U>
    &result_fitNames, CalculationResults &result_calculationResults,
    ContrastParams &result_contrastParams);
}

#endif

// End of code generation (makeEmptyResultStruct.h)
