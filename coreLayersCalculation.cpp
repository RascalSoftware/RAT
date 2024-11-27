//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
  namespace nonPolarisedTF
  {
    void coreLayersCalculation(const ::coder::array<real_T, 2U> &layers, real_T
      rough, const char_T geometry_data[], const int32_T geometry_size[2],
      real_T bulkIn, real_T bulkOut, real_T resample, boolean_T calcSld, const ::
      coder::array<real_T, 2U> &shiftedData, const real_T simLimits[2], const
      real_T repeatLayers[2], real_T resolution, const ::coder::array<real_T, 2U>
      &background, const char_T backgroundAction_data[], const int32_T
      backgroundAction_size[2], real_T params, const char_T parallelPoints_data[],
      const int32_T parallelPoints_size[2], real_T resampleMinAngle, real_T
      resampleNPoints, boolean_T useImaginary, ::coder::array<real_T, 2U>
      &sldProfile, ::coder::array<real_T, 2U> &reflect, ::coder::array<real_T,
      2U> &simulation, ::coder::array<real_T, 2U> &b_shiftedData, ::coder::array<
      real_T, 2U> &theseLayers, ::coder::array<real_T, 2U> &resamLayers, real_T *
      chiSq)
    {
      ::coder::array<real_T, 2U> b_theseLayers;
      ::coder::array<real_T, 2U> c_shiftedData;
      ::coder::array<real_T, 2U> c_theseLayers;
      ::coder::array<real_T, 2U> d_theseLayers;
      ::coder::array<real_T, 2U> e_theseLayers;
      ::coder::array<real_T, 2U> g_theseLayers;
      ::coder::array<real_T, 2U> layerSld;
      ::coder::array<real_T, 2U> sldProfileIm;
      ::coder::array<real_T, 2U> thisSldLays;
      ::coder::array<real_T, 1U> f_theseLayers;
      real_T ssubs;
      int32_T b_loop_ub;
      int32_T i;
      int32_T i1;
      int32_T loop_ub;

      //    This is the main reflectivity calculation for all Layers models in the
      //    non polarised target function.
      //
      //    The function first arranges the
      //    roughness' in the correct order according
      //    to geometry. Then, if required it calculates the SLD profile and if
      //    requested resamples this into a number of zero-roughness layers
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
      if (!useImaginary) {
        groupLayersMod(layers, rough, geometry_data, geometry_size, bulkIn,
                       bulkOut, c_theseLayers, &ssubs);
        theseLayers.set_size(c_theseLayers.size(0), 3);
        loop_ub = c_theseLayers.size(0);
        for (i = 0; i < 3; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            theseLayers[i1 + theseLayers.size(0) * i] = c_theseLayers[i1 +
              c_theseLayers.size(0) * i];
          }
        }
      } else {
        groupLayersModImaginary(layers, rough, geometry_data, geometry_size,
          bulkIn, bulkOut, b_theseLayers, &ssubs);
        theseLayers.set_size(b_theseLayers.size(0), 4);
        loop_ub = b_theseLayers.size(0);
        for (i = 0; i < 4; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            theseLayers[i1 + theseLayers.size(0) * i] = b_theseLayers[i1 +
              b_theseLayers.size(0) * i];
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
          int32_T i2;
          int32_T result;
          int8_T input_sizes_idx_1;
          int8_T sizes_idx_1;
          boolean_T empty_non_axis_sizes;
          if (4 > theseLayers.size(1)) {
            i = -1;
            i1 = -1;
          } else {
            i = 2;
            i1 = 3;
          }

          if (theseLayers.size(0) != 0) {
            result = theseLayers.size(0);
          } else {
            result = 0;
          }

          empty_non_axis_sizes = (result == 0);
          if (empty_non_axis_sizes || (theseLayers.size(0) != 0)) {
            input_sizes_idx_1 = 2;
          } else {
            input_sizes_idx_1 = 0;
          }

          if (empty_non_axis_sizes || ((theseLayers.size(0) != 0) && (i1 - i !=
                0))) {
            sizes_idx_1 = static_cast<int8_T>(i1 - i);
          } else {
            sizes_idx_1 = 0;
          }

          loop_ub = theseLayers.size(0);
          d_theseLayers.set_size(theseLayers.size(0), 2);
          for (i2 = 0; i2 < 2; i2++) {
            for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
              d_theseLayers[b_loop_ub + d_theseLayers.size(0) * i2] =
                theseLayers[b_loop_ub + theseLayers.size(0) * i2];
            }
          }

          loop_ub = theseLayers.size(0);
          b_loop_ub = i1 - i;
          e_theseLayers.set_size(theseLayers.size(0), b_loop_ub);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            for (i2 = 0; i2 < loop_ub; i2++) {
              e_theseLayers[i2 + e_theseLayers.size(0) * i1] = theseLayers[i2 +
                theseLayers.size(0) * ((i + i1) + 1)];
            }
          }

          thisSldLays.set_size(result, input_sizes_idx_1 + sizes_idx_1);
          loop_ub = input_sizes_idx_1;
          for (i = 0; i < loop_ub; i++) {
            for (i1 = 0; i1 < result; i1++) {
              thisSldLays[i1 + thisSldLays.size(0) * i] = d_theseLayers[i1 +
                result * i];
            }
          }

          loop_ub = sizes_idx_1;
          for (i = 0; i < loop_ub; i++) {
            for (i1 = 0; i1 < result; i1++) {
              thisSldLays[i1 + thisSldLays.size(0) * (i + input_sizes_idx_1)] =
                e_theseLayers[i1 + result * i];
            }
          }

          if (theseLayers.size(0) != 0) {
            result = theseLayers.size(0);
          } else {
            result = 0;
          }

          empty_non_axis_sizes = (result == 0);
          if (empty_non_axis_sizes || (theseLayers.size(0) != 0)) {
            input_sizes_idx_1 = 1;
          } else {
            input_sizes_idx_1 = 0;
          }

          if (empty_non_axis_sizes || (theseLayers.size(0) != 0)) {
            sizes_idx_1 = static_cast<int8_T>(theseLayers.size(1) - 2);
          } else {
            sizes_idx_1 = 0;
          }

          //  Note bulkIn and bulkOut = 0 since there is never any imaginary part for
          //  the bulk phases..
          loop_ub = theseLayers.size(0);
          f_theseLayers.set_size(theseLayers.size(0));
          for (i = 0; i < loop_ub; i++) {
            f_theseLayers[i] = theseLayers[i];
          }

          loop_ub = theseLayers.size(0);
          b_loop_ub = theseLayers.size(1) - 3;
          e_theseLayers.set_size(theseLayers.size(0), theseLayers.size(1) - 2);
          for (i = 0; i <= b_loop_ub; i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              e_theseLayers[i1 + e_theseLayers.size(0) * i] = theseLayers[i1 +
                theseLayers.size(0) * (i + 2)];
            }
          }

          g_theseLayers.set_size(result, input_sizes_idx_1 + sizes_idx_1);
          loop_ub = input_sizes_idx_1;
          for (i = 0; i < loop_ub; i++) {
            for (i1 = 0; i1 < result; i1++) {
              g_theseLayers[i1] = f_theseLayers[i1];
            }
          }

          loop_ub = sizes_idx_1;
          for (i = 0; i < loop_ub; i++) {
            for (i1 = 0; i1 < result; i1++) {
              g_theseLayers[i1 + g_theseLayers.size(0) * (i + input_sizes_idx_1)]
                = e_theseLayers[i1 + result * i];
            }
          }

          makeSLDProfiles(g_theseLayers, ssubs, repeatLayers, sldProfileIm);
        }

        makeSLDProfiles(bulkIn, bulkOut, thisSldLays, ssubs, repeatLayers,
                        sldProfile);
      }

      //  If required, then resample the SLD
      if (resample == 1.0) {
        if (!useImaginary) {
          resampleLayers(sldProfile, resampleMinAngle, resampleNPoints,
                         c_theseLayers);
          layerSld.set_size(c_theseLayers.size(0), 3);
          loop_ub = c_theseLayers.size(0);
          for (i = 0; i < 3; i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              layerSld[i1 + layerSld.size(0) * i] = c_theseLayers[i1 +
                c_theseLayers.size(0) * i];
            }
          }
        } else {
          resampleLayersReIm(sldProfile, sldProfileIm, resampleMinAngle,
                             resampleNPoints, b_theseLayers);
          layerSld.set_size(b_theseLayers.size(0), 4);
          loop_ub = b_theseLayers.size(0);
          for (i = 0; i < 4; i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              layerSld[i1 + layerSld.size(0) * i] = b_theseLayers[i1 +
                b_theseLayers.size(0) * i];
            }
          }
        }

        resamLayers.set_size(layerSld.size(0), layerSld.size(1));
        loop_ub = layerSld.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = layerSld.size(0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            resamLayers[i1 + resamLayers.size(0) * i] = layerSld[i1 +
              layerSld.size(0) * i];
          }
        }
      } else {
        layerSld.set_size(theseLayers.size(0), theseLayers.size(1));
        loop_ub = theseLayers.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = theseLayers.size(0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            layerSld[i1 + layerSld.size(0) * i] = theseLayers[i1 +
              theseLayers.size(0) * i];
          }
        }

        resamLayers.set_size(1, 3);
        resamLayers[0] = 0.0;
        resamLayers[resamLayers.size(0)] = 0.0;
        resamLayers[resamLayers.size(0) * 2] = 0.0;
      }

      //  Calculate the reflectivity
      callReflectivity(bulkIn, bulkOut, simLimits, repeatLayers, shiftedData,
                       layerSld, ssubs, resolution, parallelPoints_data,
                       parallelPoints_size, useImaginary, reflect, simulation);

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
      *chiSq = chiSquared(b_shiftedData, reflect, params);
    }
  }
}

// End of code generation (coreLayersCalculation.cpp)
