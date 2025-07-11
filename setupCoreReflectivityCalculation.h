//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// setupCoreReflectivityCalculation.h
//
// Code generation for function 'setupCoreReflectivityCalculation'
//
#ifndef SETUPCOREREFLECTIVITYCALCULATION_H
#define SETUPCOREREFLECTIVITYCALCULATION_H

// Include files
#include "RATMain_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void setupCoreReflectivityCalculation(const double backgroundParamIndex_data[],
    const int backgroundParamIndex_size[2], const double
    resolutionParamIndex_data[], const int resolutionParamIndex_size[2], const ::
    coder::array<double, 2U> &backgroundParams, const ::coder::array<double, 2U>
    &resolutionParams, const char backgroundType_data[], const int
    backgroundType_size[2], const char resolutionType_data[], const int
    resolutionType_size[2], const ::coder::array<cell_wrap_10, 2U> &customFiles,
    double scalefactor, double dataPresent, const ::coder::array<double, 2U>
    &data, const double dataLimits[2], const double simulationLimits[2], double
    numSimulationPoints, ::coder::array<double, 2U> &background, ::coder::array<
    double, 2U> &resolution, ::coder::array<double, 2U> &shiftedData, ::coder::
    array<double, 1U> &simulationXData, double dataIndices[2]);
}

#endif

// End of code generation (setupCoreReflectivityCalculation.h)
