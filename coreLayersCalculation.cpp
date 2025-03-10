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
#include "groupLayersModImaginary.h"
#include "makeSLDProfiles.h"
#include "resampleLayers.h"
#include "resampleLayersReIm.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
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
      double, 2U> &theseLayers, ::coder::array<double, 2U> &resamLayers)
    {
      ::coder::array<double, 2U> b_theseLayers;
      ::coder::array<double, 2U> c_shiftedData;
      ::coder::array<double, 2U> c_theseLayers;
      ::coder::array<double, 2U> e_theseLayers;
      ::coder::array<double, 2U> layerSld;
      ::coder::array<double, 2U> sldProfileIm;
      ::coder::array<double, 2U> thisSldLays;
      ::coder::array<double, 1U> d_theseLayers;
      double ssubs;
      int b_loop_ub;
      int i;
      int i1;
      int loop_ub;
      boolean_T b;

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
      b = !useImaginary;
      if (b) {
        ssubs = groupLayersMod(layers, rough, geometry_data, geometry_size,
          bulkIn, bulkOut, layerSld);
        theseLayers.set_size(layerSld.size(0), 3);
        loop_ub = layerSld.size(0);
        for (i = 0; i < 3; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            theseLayers[i1 + theseLayers.size(0) * i] = layerSld[i1 +
              layerSld.size(0) * i];
          }
        }
      } else {
        ssubs = groupLayersModImaginary(layers, rough, geometry_data,
          geometry_size, bulkIn, bulkOut, layerSld);
        theseLayers.set_size(layerSld.size(0), 4);
        loop_ub = layerSld.size(0);
        for (i = 0; i < 4; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            theseLayers[i1 + theseLayers.size(0) * i] = layerSld[i1 +
              layerSld.size(0) * i];
          }
        }
      }

      //  Make the SLD profiles.
      //  If resampling is needed, then enforce the calcSLD flag, so as to catch
      //  the error af trying to resample a non-existent profile.
      if ((resample == 1.0) && (!calcSld)) {
        calcSld = true;
      }

      //  If calc SLD flag is set, then calculate the SLD profile
      if (calcSld) {
        thisSldLays.set_size(theseLayers.size(0), theseLayers.size(1));
        loop_ub = theseLayers.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = theseLayers.size(0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            thisSldLays[i1 + thisSldLays.size(0) * i] = theseLayers[i1 +
              theseLayers.size(0) * i];
          }
        }

        //  If we need them both, we process real and imaginary parts of the SLD
        //  separately
        if (useImaginary) {
          int result_tmp;
          signed char input_sizes_idx_1;
          signed char sizes_idx_1;
          boolean_T empty_non_axis_sizes;
          if (theseLayers.size(1) < 4) {
            i = 0;
            i1 = 0;
          } else {
            i = 3;
            i1 = 4;
          }

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

          if (empty_non_axis_sizes || ((theseLayers.size(0) != 0) && (i1 - i !=
                0))) {
            sizes_idx_1 = static_cast<signed char>(i1 - i);
          } else {
            sizes_idx_1 = 0;
          }

          b_theseLayers.set_size(theseLayers.size(0), 2);
          loop_ub = theseLayers.size(0);
          for (int i2{0}; i2 < 2; i2++) {
            for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
              b_theseLayers[b_loop_ub + b_theseLayers.size(0) * i2] =
                theseLayers[b_loop_ub + theseLayers.size(0) * i2];
            }
          }

          loop_ub = i1 - i;
          c_theseLayers.set_size(theseLayers.size(0), loop_ub);
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = theseLayers.size(0);
            for (int i2{0}; i2 < b_loop_ub; i2++) {
              c_theseLayers[i2 + c_theseLayers.size(0) * i1] = theseLayers[i2 +
                theseLayers.size(0) * (i + i1)];
            }
          }

          thisSldLays.set_size(result_tmp, input_sizes_idx_1 + sizes_idx_1);
          loop_ub = input_sizes_idx_1;
          for (i = 0; i < loop_ub; i++) {
            for (i1 = 0; i1 < result_tmp; i1++) {
              thisSldLays[i1 + thisSldLays.size(0) * i] = b_theseLayers[i1 +
                result_tmp * i];
            }
          }

          loop_ub = sizes_idx_1;
          for (i = 0; i < loop_ub; i++) {
            for (i1 = 0; i1 < result_tmp; i1++) {
              thisSldLays[i1 + thisSldLays.size(0) * (i + input_sizes_idx_1)] =
                c_theseLayers[i1 + result_tmp * i];
            }
          }

          empty_non_axis_sizes = (result_tmp == 0);
          if (empty_non_axis_sizes || (theseLayers.size(0) != 0)) {
            input_sizes_idx_1 = 1;
          } else {
            input_sizes_idx_1 = 0;
          }

          if (empty_non_axis_sizes || (theseLayers.size(0) != 0)) {
            sizes_idx_1 = static_cast<signed char>(theseLayers.size(1) - 2);
          } else {
            sizes_idx_1 = 0;
          }

          //  Note bulkIn and bulkOut = 0 since there is never any imaginary part for
          //  the bulk phases..
          d_theseLayers.set_size(theseLayers.size(0));
          loop_ub = theseLayers.size(0);
          for (i = 0; i < loop_ub; i++) {
            d_theseLayers[i] = theseLayers[i];
          }

          c_theseLayers.set_size(theseLayers.size(0), theseLayers.size(1) - 2);
          loop_ub = theseLayers.size(1);
          for (i = 0; i <= loop_ub - 3; i++) {
            b_loop_ub = theseLayers.size(0);
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              c_theseLayers[i1 + c_theseLayers.size(0) * i] = theseLayers[i1 +
                theseLayers.size(0) * (i + 2)];
            }
          }

          e_theseLayers.set_size(result_tmp, input_sizes_idx_1 + sizes_idx_1);
          loop_ub = input_sizes_idx_1;
          for (i = 0; i < loop_ub; i++) {
            for (i1 = 0; i1 < result_tmp; i1++) {
              e_theseLayers[i1] = d_theseLayers[i1];
            }
          }

          loop_ub = sizes_idx_1;
          for (i = 0; i < loop_ub; i++) {
            for (i1 = 0; i1 < result_tmp; i1++) {
              e_theseLayers[i1 + e_theseLayers.size(0) * (i + input_sizes_idx_1)]
                = c_theseLayers[i1 + result_tmp * i];
            }
          }

          makeSLDProfiles(e_theseLayers, ssubs, repeatLayers, sldProfileIm);
        }

        makeSLDProfiles(bulkIn, bulkOut, thisSldLays, ssubs, repeatLayers,
                        sldProfile);
      }

      //  If required, then resample the SLD
      if (resample == 1.0) {
        if (b) {
          resampleLayers(sldProfile, resampleMinAngle, resampleNPoints, layerSld);
        } else {
          resampleLayersReIm(sldProfile, sldProfileIm, resampleMinAngle,
                             resampleNPoints, layerSld);
        }

        resamLayers.set_size(layerSld.size(0), layerSld.size(1));
        loop_ub = layerSld.size(1);
        b_loop_ub = layerSld.size(0);
        for (i = 0; i < loop_ub; i++) {
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            resamLayers[i1 + resamLayers.size(0) * i] = layerSld[i1 +
              layerSld.size(0) * i];
          }
        }
      } else {
        resamLayers.set_size(1, 3);
        resamLayers[0] = 0.0;
        resamLayers[resamLayers.size(0)] = 0.0;
        resamLayers[resamLayers.size(0) * 2] = 0.0;
      }

      //  Calculate the reflectivity
      callReflectivity(bulkIn, bulkOut, simulationXData, dataIndices,
                       repeatLayers, layerSld, ssubs, resolution,
                       parallelPoints_data, parallelPoints_size, useImaginary,
                       reflect, simulation);

      //  Apply background correction
      c_shiftedData.set_size(shiftedData.size(0), 6);
      loop_ub = shiftedData.size(0) - 1;
      for (i = 0; i < 6; i++) {
        for (i1 = 0; i1 <= loop_ub; i1++) {
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
