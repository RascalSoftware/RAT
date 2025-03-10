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
  namespace normalTF
  {
    double coreLayersCalculation(const ::coder::array<double, 2U> &layers,
      double rough, const char geometry_data[], const int geometry_size[2],
      double bulkIn, double bulkOut, double resample, boolean_T calcSld, const ::
      coder::array<double, 2U> &shiftedData, const ::coder::array<double, 1U>
      &simulationXData, const double dataIndices[2], const double repeatLayers[2],
      const ::coder::array<double, 2U> &resolution, const ::coder::array<double,
      2U> &background, const char backgroundAction_data[], const int
      backgroundAction_size[2], double params, const char parallelPoints_data[],
      const int parallelPoints_size[2], double resampleMinAngle, double
      resampleNPoints, boolean_T useImaginary, ::coder::array<double, 2U>
      &sldProfile, ::coder::array<double, 2U> &reflect, ::coder::array<double,
      2U> &simulation, ::coder::array<double, 2U> &b_shiftedData, ::coder::array<
      double, 2U> &theseLayers, ::coder::array<double, 2U> &resamLayers);
  }
}

#endif

// End of code generation (coreLayersCalculation.h)
