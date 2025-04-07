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
#include "groupLayersMod.h"
#include "makeSLDProfile.h"
#include "resampleLayers.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace normalTF
  {
    void b_coreLayersCalculation(const ::coder::array<double, 2U>
      &contrastLayers, double roughness, const char geometry_data[], const int
      geometry_size[2], double bulkIn, double bulkOut, double resample,
      boolean_T calcSld, const ::coder::array<double, 2U> &shiftedData, const ::
      coder::array<double, 1U> &simulationXData, const double dataIndices[2],
      const ::coder::array<double, 2U> &resolution, const ::coder::array<double,
      2U> &background, const char backgroundAction_data[], const int
      backgroundAction_size[2], const char parallelPoints_data[], const int
      parallelPoints_size[2], double resampleMinAngle, double resampleNPoints, ::
      coder::array<double, 2U> &reflectivity, ::coder::array<double, 2U>
      &simulation, ::coder::array<double, 2U> &b_shiftedData, ::coder::array<
      double, 2U> &sldProfile, ::coder::array<double, 2U> &layers, ::coder::
      array<double, 2U> &resampledLayers)
    {
      ::coder::array<double, 2U> ImSLDLayers;
      ::coder::array<double, 2U> ReSLDLayers;
      ::coder::array<double, 2U> c_shiftedData;
      ::coder::array<double, 2U> inputLayers;
      ::coder::array<double, 2U> sldProfileIm;
      double ssubs;
      int loop_ub;
      int y_size_idx_1;

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
      sldProfileIm.set_size(1, 2);
      sldProfile[0] = 0.0;
      sldProfileIm[0] = 0.0;
      sldProfile[sldProfile.size(0)] = 0.0;
      sldProfileIm[sldProfileIm.size(0)] = 0.0;
      resampledLayers.set_size(1, 4);
      resampledLayers[0] = 0.0;
      resampledLayers[resampledLayers.size(0)] = 0.0;
      resampledLayers[resampledLayers.size(0) * 2] = 0.0;
      resampledLayers[resampledLayers.size(0) * 3] = 0.0;

      //  Build up the layers matrix for this contrast
      ssubs = b_groupLayersMod(contrastLayers, roughness, geometry_data,
        geometry_size, layers);
      applyHydration(layers, bulkIn, bulkOut);

      //  Make the SLD profiles.
      //  If resampling is needed, then enforce the SLD calculation, so as to
      //  prevent the error of trying to resample a non-existent profile.
      if (calcSld || (resample == 1.0)) {
        int tmp_size;
        short tmp_data[12];
        signed char b_y_data[11];
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
            ReSLDLayers[i1 + ReSLDLayers.size(0) * i] = layers[i1 + layers.size
              (0) * tmp_data[i]];
          }
        }

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
            ImSLDLayers[i1 + ImSLDLayers.size(0) * i] = layers[i1 + layers.size
              (0) * tmp_data[i]];
          }
        }

        //  Note bulkIn and bulkOut = 0 since there is never any imaginary part
        //  for the bulk phases.
        makeSLDProfile(bulkIn, bulkOut, ReSLDLayers, ssubs, sldProfile);
        makeSLDProfile(ImSLDLayers, ssubs, sldProfileIm);
      }

      //  If required, then resample the SLD
      if (resample == 1.0) {
        resampleLayers(sldProfile, sldProfileIm, resampleMinAngle,
                       resampleNPoints, resampledLayers);
        inputLayers.set_size(resampledLayers.size(0), 4);
        loop_ub = resampledLayers.size(0);
        for (int i{0}; i < 4; i++) {
          for (int i1{0}; i1 < loop_ub; i1++) {
            inputLayers[i1 + inputLayers.size(0) * i] = resampledLayers[i1 +
              resampledLayers.size(0) * i];
          }
        }
      } else {
        inputLayers.set_size(layers.size(0), layers.size(1));
        loop_ub = layers.size(1);
        for (int i{0}; i < loop_ub; i++) {
          y_size_idx_1 = layers.size(0);
          for (int i1{0}; i1 < y_size_idx_1; i1++) {
            inputLayers[i1 + inputLayers.size(0) * i] = layers[i1 + layers.size
              (0) * i];
          }
        }
      }

      //  Calculate the reflectivity
      callReflectivity(bulkIn, bulkOut, simulationXData, dataIndices, 1.0,
                       inputLayers, ssubs, resolution, parallelPoints_data,
                       parallelPoints_size, reflectivity, simulation);

      //  Apply background correction
      c_shiftedData.set_size(shiftedData.size(0), 6);
      loop_ub = shiftedData.size(0) - 1;
      for (int i{0}; i < 6; i++) {
        for (int i1{0}; i1 <= loop_ub; i1++) {
          c_shiftedData[i1 + c_shiftedData.size(0) * i] = shiftedData[i1 +
            shiftedData.size(0) * i];
        }
      }

      applyBackgroundCorrection(reflectivity, simulation, c_shiftedData,
        background, backgroundAction_data, backgroundAction_size, b_shiftedData);
    }

    void coreLayersCalculation(const ::coder::array<double, 2U> &contrastLayers,
      double roughness, const char geometry_data[], const int geometry_size[2],
      double bulkIn, double bulkOut, double resample, boolean_T calcSld, const ::
      coder::array<double, 2U> &shiftedData, const ::coder::array<double, 1U>
      &simulationXData, const double dataIndices[2], double repeatLayers, const ::
      coder::array<double, 2U> &resolution, const ::coder::array<double, 2U>
      &background, const char backgroundAction_data[], const int
      backgroundAction_size[2], const char parallelPoints_data[], const int
      parallelPoints_size[2], double resampleMinAngle, double resampleNPoints, ::
      coder::array<double, 2U> &reflectivity, ::coder::array<double, 2U>
      &simulation, ::coder::array<double, 2U> &b_shiftedData, ::coder::array<
      double, 2U> &sldProfile, ::coder::array<double, 2U> &layers, ::coder::
      array<double, 2U> &resampledLayers)
    {
      ::coder::array<double, 2U> ImSLDLayers;
      ::coder::array<double, 2U> ReSLDLayers;
      ::coder::array<double, 2U> c_shiftedData;
      ::coder::array<double, 2U> inputLayers;
      ::coder::array<double, 2U> r;
      ::coder::array<double, 2U> sldProfileIm;
      double ssubs;
      int b_loop_ub;
      int loop_ub;

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
      sldProfileIm.set_size(1, 2);
      sldProfile[0] = 0.0;
      sldProfileIm[0] = 0.0;
      sldProfile[sldProfile.size(0)] = 0.0;
      sldProfileIm[sldProfileIm.size(0)] = 0.0;
      resampledLayers.set_size(1, 4);
      resampledLayers[0] = 0.0;
      resampledLayers[resampledLayers.size(0)] = 0.0;
      resampledLayers[resampledLayers.size(0) * 2] = 0.0;
      resampledLayers[resampledLayers.size(0) * 3] = 0.0;

      //  Build up the layers matrix for this contrast
      ssubs = groupLayersMod(contrastLayers, roughness, geometry_data,
        geometry_size, layers);
      r.set_size(layers.size(0), layers.size(1));
      loop_ub = layers.size(1);
      for (int i{0}; i < loop_ub; i++) {
        b_loop_ub = layers.size(0);
        for (int i1{0}; i1 < b_loop_ub; i1++) {
          r[i1 + r.size(0) * i] = layers[i1 + layers.size(0) * i];
        }
      }

      applyHydration(r, bulkIn, bulkOut);
      layers.set_size(r.size(0), r.size(1));
      loop_ub = r.size(1);
      for (int i{0}; i < loop_ub; i++) {
        b_loop_ub = r.size(0);
        for (int i1{0}; i1 < b_loop_ub; i1++) {
          layers[i1 + layers.size(0) * i] = r[i1 + r.size(0) * i];
        }
      }

      //  Make the SLD profiles.
      //  If resampling is needed, then enforce the SLD calculation, so as to
      //  prevent the error of trying to resample a non-existent profile.
      if (calcSld || (resample == 1.0)) {
        int tmp_size;
        short tmp_data[5];
        signed char b_y_data[11];
        signed char y_data[10];

        //  We process real and imaginary parts of the SLD separately
        if (layers.size(1) < 4) {
          b_loop_ub = 0;
        } else {
          b_loop_ub = layers.size(1) - 3;
          loop_ub = layers.size(1) - 4;
          for (int i{0}; i <= loop_ub; i++) {
            y_data[i] = static_cast<signed char>(i + 4);
          }
        }

        tmp_size = b_loop_ub + 2;
        tmp_data[0] = 0;
        tmp_data[1] = 1;
        for (int i{0}; i < b_loop_ub; i++) {
          tmp_data[i + 2] = static_cast<short>(y_data[i] - 1);
        }

        ReSLDLayers.set_size(layers.size(0), tmp_size);
        for (int i{0}; i < tmp_size; i++) {
          loop_ub = layers.size(0);
          for (int i1{0}; i1 < loop_ub; i1++) {
            ReSLDLayers[i1 + ReSLDLayers.size(0) * i] = layers[i1 + layers.size
              (0) * tmp_data[i]];
          }
        }

        if (layers.size(1) < 3) {
          b_loop_ub = 0;
        } else {
          b_loop_ub = layers.size(1) - 2;
          loop_ub = layers.size(1) - 3;
          for (int i{0}; i <= loop_ub; i++) {
            b_y_data[i] = static_cast<signed char>(i + 3);
          }
        }

        tmp_size = b_loop_ub + 1;
        tmp_data[0] = 0;
        for (int i{0}; i < b_loop_ub; i++) {
          tmp_data[i + 1] = static_cast<short>(b_y_data[i] - 1);
        }

        ImSLDLayers.set_size(layers.size(0), tmp_size);
        for (int i{0}; i < tmp_size; i++) {
          loop_ub = layers.size(0);
          for (int i1{0}; i1 < loop_ub; i1++) {
            ImSLDLayers[i1 + ImSLDLayers.size(0) * i] = layers[i1 + layers.size
              (0) * tmp_data[i]];
          }
        }

        //  Note bulkIn and bulkOut = 0 since there is never any imaginary part
        //  for the bulk phases.
        makeSLDProfile(bulkIn, bulkOut, ReSLDLayers, ssubs, repeatLayers,
                       sldProfile);
        makeSLDProfile(ImSLDLayers, ssubs, repeatLayers, sldProfileIm);
      }

      //  If required, then resample the SLD
      if (resample == 1.0) {
        resampleLayers(sldProfile, sldProfileIm, resampleMinAngle,
                       resampleNPoints, resampledLayers);
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
          b_loop_ub = layers.size(0);
          for (int i1{0}; i1 < b_loop_ub; i1++) {
            inputLayers[i1 + inputLayers.size(0) * i] = layers[i1 + layers.size
              (0) * i];
          }
        }
      }

      //  Calculate the reflectivity
      callReflectivity(bulkIn, bulkOut, simulationXData, dataIndices,
                       repeatLayers, inputLayers, ssubs, resolution,
                       parallelPoints_data, parallelPoints_size, reflectivity,
                       simulation);

      //  Apply background correction
      c_shiftedData.set_size(shiftedData.size(0), 6);
      loop_ub = shiftedData.size(0) - 1;
      for (int i{0}; i < 6; i++) {
        for (int i1{0}; i1 <= loop_ub; i1++) {
          c_shiftedData[i1 + c_shiftedData.size(0) * i] = shiftedData[i1 +
            shiftedData.size(0) * i];
        }
      }

      applyBackgroundCorrection(reflectivity, simulation, c_shiftedData,
        background, backgroundAction_data, backgroundAction_size, b_shiftedData);
    }
  }
}

// End of code generation (coreLayersCalculation.cpp)
