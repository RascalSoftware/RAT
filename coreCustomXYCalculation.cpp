//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// coreCustomXYCalculation.cpp
//
// Code generation for function 'coreCustomXYCalculation'
//

// Include files
#include "coreCustomXYCalculation.h"
#include "applyBackgroundCorrection.h"
#include "callReflectivity.h"
#include "chiSquared.h"
#include "resampleLayers.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
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
    &resampledLayers)
  {
    ::coder::array<double, 2U> b_contrastSld;
    ::coder::array<double, 2U> b_resampledLayers;
    int loop_ub;

    //  Resample the layers - always required for a custom XY calculation
    sldProfile.set_size(contrastSld.size(0), 2);
    b_contrastSld.set_size(contrastSld.size(0), 2);
    loop_ub = contrastSld.size(0);
    for (int i{0}; i < 2; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        sldProfile[i1 + sldProfile.size(0) * i] = contrastSld[i1 +
          contrastSld.size(0) * i];
        b_contrastSld[i1 + b_contrastSld.size(0) * i] = contrastSld[i1 +
          contrastSld.size(0) * (i << 1)];
      }
    }

    resampleLayers(sldProfile, b_contrastSld, resampleMinAngle, resampleNPoints,
                   resampledLayers);
    layers.set_size(resampledLayers.size(0), 4);
    loop_ub = resampledLayers.size(0);
    for (int i{0}; i < 4; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        layers[i1 + layers.size(0) * i] = resampledLayers[i1 +
          resampledLayers.size(0) * i];
      }
    }

    b_resampledLayers.set_size(resampledLayers.size(0), 4);
    for (int i{0}; i < 4; i++) {
      loop_ub = resampledLayers.size(0) - 1;
      for (int i1{0}; i1 <= loop_ub; i1++) {
        b_resampledLayers[i1 + b_resampledLayers.size(0) * i] =
          resampledLayers[i1 + resampledLayers.size(0) * i];
      }
    }

    callReflectivity(bulkIn, bulkOut, simulationXData, dataIndices,
                     b_resampledLayers, roughness, resolution, parallel_data,
                     parallel_size, reflectivity, simulation);
    applyBackgroundCorrection(reflectivity, simulation, shiftedData, background,
      backgroundAction_data, backgroundAction_size);
    return chiSquared(shiftedData, reflectivity, nParams);
  }
}

// End of code generation (coreCustomXYCalculation.cpp)
