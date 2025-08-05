//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// coreLayersCalculation.cpp
//
// Code generation for function 'coreLayersCalculation'
//

// Include files
#include "coreLayersCalculation.h"
#include "applyBackgroundCorrection.h"
#include "applyHydration.h"
#include "callReflectivity.h"
#include "chiSquared.h"
#include "groupLayersMod.h"
#include "makeSLDProfile.h"
#include "resampleLayers.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
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
    array<double, 2U> &layers, ::coder::array<double, 2U> &resampledLayers)
  {
    ::coder::array<double, 2U> ImSLDLayers;
    ::coder::array<double, 2U> ReSLDLayers;
    ::coder::array<double, 2U> inputLayers;
    ::coder::array<double, 2U> r;
    double ssubs;
    int loop_ub;
    int tmp_size;
    int y_size_idx_1;
    short tmp_data[12];

    //    This is the main reflectivity calculation for all layers models in the
    //    normal target function.
    //
    //    The function first arranges the roughness' in the correct order
    //    according to geometry. Then, if required it calculates the SLD profile
    //    and if requested resamples this into a number of zero-roughness layers
    //    (roughness resampling). It the applies any scalefactors and qz shifts
    //    the data requires. This is done before calculating the reflectivity to
    //    ensure that the reflectivity is calculated over the same range in qz as
    //    the shifted datapoints. The main reflectivity calculation is then
    //    called, including the resolution function. The calculation outputs two
    //    profiles - 'reflect' which is the same range as the points, and
    //    'simulation' which can be a different range to allow extrapolation.
    //    Finally, the background correction is applied.
    //  Pre-definition for Coder
    sldProfile.set_size(1, 2);
    sldProfile[0] = 0.0;
    sldProfile[sldProfile.size(0)] = 0.0;
    resampledLayers.set_size(1, 4);
    resampledLayers[0] = 0.0;
    resampledLayers[resampledLayers.size(0)] = 0.0;
    resampledLayers[resampledLayers.size(0) * 2] = 0.0;
    resampledLayers[resampledLayers.size(0) * 3] = 0.0;

    //  Build up the layers matrix for this contrast
    ssubs = groupLayersMod(contrastLayers, roughness, geometry_data,
      geometry_size, layers);
    applyHydration(layers, bulkIn, bulkOut);

    //  Make the SLD profiles.
    //  If resampling is needed, then enforce the SLD calculation, so as to
    //  prevent the error of trying to resample a non-existent profile.
    if (calcSld || (resample == 1.0)) {
      signed char y_data[10];

      //  We process real and imaginary parts of the SLD separately
      if (layers.size(1) < 4) {
        y_size_idx_1 = 0;
      } else {
        y_size_idx_1 = layers.size(1) - 3;
        loop_ub = layers.size(1) - 4;
        for (int i{0}; i <= loop_ub; i++) {
          y_data[i] = static_cast<signed char>(i + 4);
        }
      }

      tmp_size = y_size_idx_1 + 2;
      tmp_data[0] = 0;
      tmp_data[1] = 1;
      for (int i{0}; i < y_size_idx_1; i++) {
        tmp_data[i + 2] = static_cast<short>(y_data[i] - 1);
      }

      ReSLDLayers.set_size(layers.size(0), tmp_size);
      for (int i{0}; i < tmp_size; i++) {
        loop_ub = layers.size(0);
        for (int i1{0}; i1 < loop_ub; i1++) {
          ReSLDLayers[i1 + ReSLDLayers.size(0) * i] = layers[i1 + layers.size(0)
            * tmp_data[i]];
        }
      }

      makeSLDProfile(bulkIn, bulkOut, ReSLDLayers, ssubs, repeatLayers,
                     sldProfile);
    }

    //  If required, then resample the SLD
    if (resample == 1.0) {
      signed char b_y_data[11];

      //  Here, we need the imaginary part of the SLD
      //  Note bulkIn and bulkOut = 0 since there is never any imaginary part
      //  for the bulk phases.
      if (layers.size(1) < 3) {
        y_size_idx_1 = 0;
      } else {
        y_size_idx_1 = layers.size(1) - 2;
        loop_ub = layers.size(1) - 3;
        for (int i{0}; i <= loop_ub; i++) {
          b_y_data[i] = static_cast<signed char>(i + 3);
        }
      }

      tmp_size = y_size_idx_1 + 1;
      tmp_data[0] = 0;
      for (int i{0}; i < y_size_idx_1; i++) {
        tmp_data[i + 1] = static_cast<short>(b_y_data[i] - 1);
      }

      ImSLDLayers.set_size(layers.size(0), tmp_size);
      for (int i{0}; i < tmp_size; i++) {
        loop_ub = layers.size(0);
        for (int i1{0}; i1 < loop_ub; i1++) {
          ImSLDLayers[i1 + ImSLDLayers.size(0) * i] = layers[i1 + layers.size(0)
            * tmp_data[i]];
        }
      }

      makeSLDProfile(ImSLDLayers, ssubs, repeatLayers, r);
      resampleLayers(sldProfile, r, resampleMinAngle, resampleNPoints,
                     resampledLayers);
      inputLayers.set_size(resampledLayers.size(0), 4);
      loop_ub = resampledLayers.size(0);
      for (int i{0}; i < 4; i++) {
        for (int i1{0}; i1 < loop_ub; i1++) {
          inputLayers[i1 + inputLayers.size(0) * i] = resampledLayers[i1 +
            resampledLayers.size(0) * i];
        }
      }

      repeatLayers = 1.0;
    } else {
      inputLayers.set_size(layers.size(0), layers.size(1));
      loop_ub = layers.size(1);
      for (int i{0}; i < loop_ub; i++) {
        y_size_idx_1 = layers.size(0);
        for (int i1{0}; i1 < y_size_idx_1; i1++) {
          inputLayers[i1 + inputLayers.size(0) * i] = layers[i1 + layers.size(0)
            * i];
        }
      }
    }

    //  Calculate the reflectivity
    callReflectivity(bulkIn, bulkOut, simulationXData, dataIndices, repeatLayers,
                     inputLayers, ssubs, resolution, parallelPoints_data,
                     parallelPoints_size, reflectivity, simulation);

    //  Apply background correction
    applyBackgroundCorrection(reflectivity, simulation, shiftedData, background,
      backgroundAction_data, backgroundAction_size);
    return chiSquared(shiftedData, reflectivity, nParams);
  }
}

// End of code generation (coreLayersCalculation.cpp)
