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
#include "callReflectivity.h"
#include "chiSquared.h"
#include "groupLayersMod.h"
#include "makeSLDProfiles.h"
#include "resampleLayers.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace normalTF
  {
    double b_coreLayersCalculation(const ::coder::array<double, 2U> &layers,
      double rough, const char geometry_data[], const int geometry_size[2],
      double bulkIn, double bulkOut, double resample, boolean_T calcSld, const ::
      coder::array<double, 2U> &shiftedData, const ::coder::array<double, 1U>
      &simulationXData, const double dataIndices[2], const double repeatLayers[2],
      const ::coder::array<double, 2U> &resolution, const ::coder::array<double,
      2U> &background, const char backgroundAction_data[], const int
      backgroundAction_size[2], double params, const char parallelPoints_data[],
      const int parallelPoints_size[2], double resampleMinAngle, double
      resampleNPoints, ::coder::array<double, 2U> &sldProfile, ::coder::array<
      double, 2U> &reflect, ::coder::array<double, 2U> &simulation, ::coder::
      array<double, 2U> &b_shiftedData, ::coder::array<double, 2U> &theseLayers,
      ::coder::array<double, 2U> &resamLayers)
    {
      ::coder::array<double, 2U> b_theseLayers;
      ::coder::array<double, 2U> c_shiftedData;
      ::coder::array<double, 2U> d_theseLayers;
      ::coder::array<double, 2U> layerSld;
      ::coder::array<double, 2U> sldProfileIm;
      ::coder::array<double, 1U> c_theseLayers;
      double ssubs;
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
      //    The background correction is the applied, and finally chi-squared is
      //    calculated.
      //  Pre-definition for Coder
      sldProfile.set_size(1, 2);
      sldProfileIm.set_size(1, 2);
      sldProfile[0] = 0.0;
      sldProfileIm[0] = 0.0;
      sldProfile[sldProfile.size(0)] = 0.0;
      sldProfileIm[sldProfileIm.size(0)] = 0.0;

      //  Build up the layers matrix for this contrast
      ssubs = b_groupLayersMod(layers, rough, geometry_data, geometry_size,
        bulkIn, bulkOut, theseLayers);

      //  Make the SLD profiles.
      //  If resampling is needed, then enforce the calcSLD flag, so as to catch
      //  the error af trying to resample a non-existent profile.
      if ((resample == 1.0) && (!calcSld)) {
        calcSld = true;
      }

      //  If calc SLD flag is set, then calculate the SLD profile
      if (calcSld) {
        int result_tmp;
        signed char b_input_sizes_idx_1;
        signed char b_sizes_idx_1;
        signed char input_sizes_idx_1;
        signed char sizes_idx_1;
        boolean_T empty_non_axis_sizes;

        //  We process real and imaginary parts of the SLD separately
        if (theseLayers.size(0) != 0) {
          result_tmp = theseLayers.size(0);
        } else {
          result_tmp = 0;
        }

        empty_non_axis_sizes = (result_tmp == 0);
        if (empty_non_axis_sizes || (theseLayers.size(0) != 0)) {
          input_sizes_idx_1 = 2;
        } else {
          input_sizes_idx_1 = 0;
        }

        if (empty_non_axis_sizes || (theseLayers.size(0) != 0)) {
          sizes_idx_1 = 1;
        } else {
          sizes_idx_1 = 0;
        }

        empty_non_axis_sizes = (result_tmp == 0);
        if (empty_non_axis_sizes || (theseLayers.size(0) != 0)) {
          b_input_sizes_idx_1 = 1;
        } else {
          b_input_sizes_idx_1 = 0;
        }

        if (empty_non_axis_sizes || (theseLayers.size(0) != 0)) {
          b_sizes_idx_1 = 2;
        } else {
          b_sizes_idx_1 = 0;
        }

        //  Note bulkIn and bulkOut = 0 since there is never any imaginary part
        //  for the bulk phases.
        b_theseLayers.set_size(theseLayers.size(0), 2);
        loop_ub = theseLayers.size(0);
        for (int i{0}; i < 2; i++) {
          for (int i1{0}; i1 < loop_ub; i1++) {
            b_theseLayers[i1 + b_theseLayers.size(0) * i] = theseLayers[i1 +
              theseLayers.size(0) * i];
          }
        }

        c_theseLayers.set_size(theseLayers.size(0));
        loop_ub = theseLayers.size(0);
        for (int i{0}; i < loop_ub; i++) {
          c_theseLayers[i] = theseLayers[i + theseLayers.size(0) * 3];
        }

        d_theseLayers.set_size(result_tmp, input_sizes_idx_1 + sizes_idx_1);
        loop_ub = input_sizes_idx_1;
        for (int i{0}; i < loop_ub; i++) {
          for (int i1{0}; i1 < result_tmp; i1++) {
            d_theseLayers[i1 + d_theseLayers.size(0) * i] = b_theseLayers[i1 +
              result_tmp * i];
          }
        }

        loop_ub = sizes_idx_1;
        for (int i{0}; i < loop_ub; i++) {
          for (int i1{0}; i1 < result_tmp; i1++) {
            d_theseLayers[i1 + d_theseLayers.size(0) * input_sizes_idx_1] =
              c_theseLayers[i1];
          }
        }

        makeSLDProfiles(bulkIn, bulkOut, d_theseLayers, ssubs, repeatLayers,
                        sldProfile);
        c_theseLayers.set_size(theseLayers.size(0));
        loop_ub = theseLayers.size(0);
        for (int i{0}; i < loop_ub; i++) {
          c_theseLayers[i] = theseLayers[i];
        }

        b_theseLayers.set_size(theseLayers.size(0), 2);
        loop_ub = theseLayers.size(0);
        for (int i{0}; i < 2; i++) {
          for (int i1{0}; i1 < loop_ub; i1++) {
            b_theseLayers[i1 + b_theseLayers.size(0) * i] = theseLayers[i1 +
              theseLayers.size(0) * (i + 2)];
          }
        }

        d_theseLayers.set_size(result_tmp, b_input_sizes_idx_1 + b_sizes_idx_1);
        loop_ub = b_input_sizes_idx_1;
        for (int i{0}; i < loop_ub; i++) {
          for (int i1{0}; i1 < result_tmp; i1++) {
            d_theseLayers[i1] = c_theseLayers[i1];
          }
        }

        loop_ub = b_sizes_idx_1;
        for (int i{0}; i < loop_ub; i++) {
          for (int i1{0}; i1 < result_tmp; i1++) {
            d_theseLayers[i1 + d_theseLayers.size(0) * (i + b_input_sizes_idx_1)]
              = b_theseLayers[i1 + result_tmp * i];
          }
        }

        makeSLDProfiles(d_theseLayers, ssubs, repeatLayers, sldProfileIm);
      }

      //  If required, then resample the SLD
      if (resample == 1.0) {
        resampleLayers(sldProfile, sldProfileIm, resampleMinAngle,
                       resampleNPoints, layerSld);
        resamLayers.set_size(layerSld.size(0), 4);
        loop_ub = layerSld.size(0);
        for (int i{0}; i < 4; i++) {
          for (int i1{0}; i1 < loop_ub; i1++) {
            resamLayers[i1 + resamLayers.size(0) * i] = layerSld[i1 +
              layerSld.size(0) * i];
          }
        }
      } else {
        layerSld.set_size(theseLayers.size(0), 4);
        resamLayers.set_size(1, 4);
        loop_ub = theseLayers.size(0);
        for (int i{0}; i < 4; i++) {
          for (int i1{0}; i1 < loop_ub; i1++) {
            layerSld[i1 + layerSld.size(0) * i] = theseLayers[i1 +
              theseLayers.size(0) * i];
          }

          resamLayers[resamLayers.size(0) * i] = 0.0;
        }
      }

      //  Calculate the reflectivity
      callReflectivity(bulkIn, bulkOut, simulationXData, dataIndices,
                       repeatLayers, layerSld, ssubs, resolution,
                       parallelPoints_data, parallelPoints_size, reflect,
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

      applyBackgroundCorrection(reflect, simulation, c_shiftedData, background,
        backgroundAction_data, backgroundAction_size, b_shiftedData);

      //  Calculate chi squared.
      return chiSquared(b_shiftedData, reflect, params);
    }

    double coreLayersCalculation(const ::coder::array<double, 2U> &layers,
      double rough, const char geometry_data[], const int geometry_size[2],
      double bulkIn, double bulkOut, double resample, boolean_T calcSld, const ::
      coder::array<double, 2U> &shiftedData, const ::coder::array<double, 1U>
      &simulationXData, const double dataIndices[2], const double repeatLayers[2],
      const ::coder::array<double, 2U> &resolution, const ::coder::array<double,
      2U> &background, const char backgroundAction_data[], const int
      backgroundAction_size[2], double params, const char parallelPoints_data[],
      const int parallelPoints_size[2], double resampleMinAngle, double
      resampleNPoints, ::coder::array<double, 2U> &sldProfile, ::coder::array<
      double, 2U> &reflect, ::coder::array<double, 2U> &simulation, ::coder::
      array<double, 2U> &b_shiftedData, ::coder::array<double, 2U> &theseLayers,
      ::coder::array<double, 2U> &resamLayers)
    {
      ::coder::array<double, 2U> b_theseLayers;
      ::coder::array<double, 2U> c_shiftedData;
      ::coder::array<double, 2U> d_theseLayers;
      ::coder::array<double, 2U> layerSld;
      ::coder::array<double, 2U> sldProfileIm;
      ::coder::array<double, 1U> c_theseLayers;
      double ssubs;
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
      //    The background correction is the applied, and finally chi-squared is
      //    calculated.
      //  Pre-definition for Coder
      sldProfile.set_size(1, 2);
      sldProfileIm.set_size(1, 2);
      sldProfile[0] = 0.0;
      sldProfileIm[0] = 0.0;
      sldProfile[sldProfile.size(0)] = 0.0;
      sldProfileIm[sldProfileIm.size(0)] = 0.0;

      //  Build up the layers matrix for this contrast
      ssubs = groupLayersMod(layers, rough, geometry_data, geometry_size, bulkIn,
        bulkOut, theseLayers);

      //  Make the SLD profiles.
      //  If resampling is needed, then enforce the calcSLD flag, so as to catch
      //  the error af trying to resample a non-existent profile.
      if ((resample == 1.0) && (!calcSld)) {
        calcSld = true;
      }

      //  If calc SLD flag is set, then calculate the SLD profile
      if (calcSld) {
        int result_tmp;
        signed char b_input_sizes_idx_1;
        signed char b_sizes_idx_1;
        signed char input_sizes_idx_1;
        signed char sizes_idx_1;
        boolean_T empty_non_axis_sizes;

        //  We process real and imaginary parts of the SLD separately
        if (theseLayers.size(0) != 0) {
          result_tmp = theseLayers.size(0);
        } else {
          result_tmp = 0;
        }

        empty_non_axis_sizes = (result_tmp == 0);
        if (empty_non_axis_sizes || (theseLayers.size(0) != 0)) {
          input_sizes_idx_1 = 2;
        } else {
          input_sizes_idx_1 = 0;
        }

        if (empty_non_axis_sizes || (theseLayers.size(0) != 0)) {
          sizes_idx_1 = 1;
        } else {
          sizes_idx_1 = 0;
        }

        empty_non_axis_sizes = (result_tmp == 0);
        if (empty_non_axis_sizes || (theseLayers.size(0) != 0)) {
          b_input_sizes_idx_1 = 1;
        } else {
          b_input_sizes_idx_1 = 0;
        }

        if (empty_non_axis_sizes || (theseLayers.size(0) != 0)) {
          b_sizes_idx_1 = 2;
        } else {
          b_sizes_idx_1 = 0;
        }

        //  Note bulkIn and bulkOut = 0 since there is never any imaginary part
        //  for the bulk phases.
        b_theseLayers.set_size(theseLayers.size(0), 2);
        loop_ub = theseLayers.size(0);
        for (int i{0}; i < 2; i++) {
          for (int i1{0}; i1 < loop_ub; i1++) {
            b_theseLayers[i1 + b_theseLayers.size(0) * i] = theseLayers[i1 +
              theseLayers.size(0) * i];
          }
        }

        c_theseLayers.set_size(theseLayers.size(0));
        loop_ub = theseLayers.size(0);
        for (int i{0}; i < loop_ub; i++) {
          c_theseLayers[i] = theseLayers[i + theseLayers.size(0) * 3];
        }

        d_theseLayers.set_size(result_tmp, input_sizes_idx_1 + sizes_idx_1);
        loop_ub = input_sizes_idx_1;
        for (int i{0}; i < loop_ub; i++) {
          for (int i1{0}; i1 < result_tmp; i1++) {
            d_theseLayers[i1 + d_theseLayers.size(0) * i] = b_theseLayers[i1 +
              result_tmp * i];
          }
        }

        loop_ub = sizes_idx_1;
        for (int i{0}; i < loop_ub; i++) {
          for (int i1{0}; i1 < result_tmp; i1++) {
            d_theseLayers[i1 + d_theseLayers.size(0) * input_sizes_idx_1] =
              c_theseLayers[i1];
          }
        }

        makeSLDProfiles(bulkIn, bulkOut, d_theseLayers, ssubs, repeatLayers,
                        sldProfile);
        c_theseLayers.set_size(theseLayers.size(0));
        loop_ub = theseLayers.size(0);
        for (int i{0}; i < loop_ub; i++) {
          c_theseLayers[i] = theseLayers[i];
        }

        b_theseLayers.set_size(theseLayers.size(0), 2);
        loop_ub = theseLayers.size(0);
        for (int i{0}; i < 2; i++) {
          for (int i1{0}; i1 < loop_ub; i1++) {
            b_theseLayers[i1 + b_theseLayers.size(0) * i] = theseLayers[i1 +
              theseLayers.size(0) * (i + 2)];
          }
        }

        d_theseLayers.set_size(result_tmp, b_input_sizes_idx_1 + b_sizes_idx_1);
        loop_ub = b_input_sizes_idx_1;
        for (int i{0}; i < loop_ub; i++) {
          for (int i1{0}; i1 < result_tmp; i1++) {
            d_theseLayers[i1] = c_theseLayers[i1];
          }
        }

        loop_ub = b_sizes_idx_1;
        for (int i{0}; i < loop_ub; i++) {
          for (int i1{0}; i1 < result_tmp; i1++) {
            d_theseLayers[i1 + d_theseLayers.size(0) * (i + b_input_sizes_idx_1)]
              = b_theseLayers[i1 + result_tmp * i];
          }
        }

        makeSLDProfiles(d_theseLayers, ssubs, repeatLayers, sldProfileIm);
      }

      //  If required, then resample the SLD
      if (resample == 1.0) {
        resampleLayers(sldProfile, sldProfileIm, resampleMinAngle,
                       resampleNPoints, layerSld);
        resamLayers.set_size(layerSld.size(0), 4);
        loop_ub = layerSld.size(0);
        for (int i{0}; i < 4; i++) {
          for (int i1{0}; i1 < loop_ub; i1++) {
            resamLayers[i1 + resamLayers.size(0) * i] = layerSld[i1 +
              layerSld.size(0) * i];
          }
        }
      } else {
        layerSld.set_size(theseLayers.size(0), 4);
        resamLayers.set_size(1, 4);
        loop_ub = theseLayers.size(0);
        for (int i{0}; i < 4; i++) {
          for (int i1{0}; i1 < loop_ub; i1++) {
            layerSld[i1 + layerSld.size(0) * i] = theseLayers[i1 +
              theseLayers.size(0) * i];
          }

          resamLayers[resamLayers.size(0) * i] = 0.0;
        }
      }

      //  Calculate the reflectivity
      callReflectivity(bulkIn, bulkOut, simulationXData, dataIndices,
                       repeatLayers, layerSld, ssubs, resolution,
                       parallelPoints_data, parallelPoints_size, reflect,
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

      applyBackgroundCorrection(reflect, simulation, c_shiftedData, background,
        backgroundAction_data, backgroundAction_size, b_shiftedData);

      //  Calculate chi squared.
      return chiSquared(b_shiftedData, reflect, params);
    }
  }
}

// End of code generation (coreLayersCalculation.cpp)
