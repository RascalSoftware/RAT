//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// coreLayersCalculation.h
//
// Code generation for function 'coreLayersCalculation'
//
#ifndef CORELAYERSCALCULATION_H
#define CORELAYERSCALCULATION_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  double coreLayersCalculation(const ::coder::array<double, 2U> &contrastLayers,
    double roughness, const char geometry_data[], const int geometry_size[2],
    double bulkIn, double bulkOut, double resample, boolean_T calcSld, ::coder::
    array<double, 2U> &shiftedData, const ::coder::array<double, 1U>
    &simulationXData, const double dataIndices[2], double repeatLayers, const ::
    coder::array<double, 2U> &background, const ::coder::array<double, 2U>
    &resolution, const char backgroundAction_data[], const int
    backgroundAction_size[2], const char parallelPoints_data[], const int
    parallelPoints_size[2], double resampleMinAngle, double resampleNPoints,
    double nParams, ::coder::array<double, 2U> &reflectivity, ::coder::array<
    double, 2U> &simulation, ::coder::array<double, 2U> &sldProfile, ::coder::
    array<double, 2U> &layers, ::coder::array<double, 2U> &resampledLayers);
}

#endif

// End of code generation (coreLayersCalculation.h)
