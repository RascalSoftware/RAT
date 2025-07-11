//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// coreCustomXYCalculation.h
//
// Code generation for function 'coreCustomXYCalculation'
//
#ifndef CORECUSTOMXYCALCULATION_H
#define CORECUSTOMXYCALCULATION_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  double coreCustomXYCalculation(double bulkIn, double bulkOut, ::coder::array<
    double, 2U> &shiftedData, const ::coder::array<double, 1U> &simulationXData,
    const double dataIndices[2], const ::coder::array<double, 2U> &background,
    const ::coder::array<double, 2U> &resolution, const char
    backgroundAction_data[], const int backgroundAction_size[2], const char
    parallel_data[], const int parallel_size[2], double resampleMinAngle, double
    resampleNPoints, double roughness, const ::coder::array<double, 2U>
    &contrastSld, double nParams, ::coder::array<double, 2U> &reflectivity, ::
    coder::array<double, 2U> &simulation, ::coder::array<double, 2U> &sldProfile,
    ::coder::array<double, 2U> &layers, ::coder::array<double, 2U>
    &resampledLayers);
}

#endif

// End of code generation (coreCustomXYCalculation.h)
