//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: standardTF_layers_core.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "standardTF_layers_core.h"
#include "applyBackgroundCorrection.h"
#include "callReflectivity.h"
#include "chiSquared.h"
#include "groupLayers_Mod.h"
#include "makeSLDProfiles.h"
#include "resampleLayers.h"
#include "rt_nonfinite.h"
#include "shiftdata.h"
#include "coder_array.h"

// Function Definitions
//
// This is the main reflectivity calculation for all Layers models in the
//    standard target function.
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
//    'Simulation' which can be a different range to allow extrapolation.
//    The background correction is the applied, and finally chi-squared is
//    calculated.
//
//  Inputs:
//    contrastLayers  :
//    rough           :
//    geometry        :
//    nba             :
//    nbs             :
//    resample        :
//    calcSld         :
//    sf              :
//    qshift          :
//    dataPresent     :
//    data            :
//    dataLimits      :
//    simLimits       :
//    repeatLayers    :
//    background      :
//    resol           :
//    backsType       :
//    params          :
//    paralellPoints  :
//
//  Outputs:
//
//
//
//  ------------------------------------------------------------------------
//
//        (c) Arwel Hughes  -   12/1/21
//
//        Last Modified: 12/1/21 by Arwel Hughes.
//
//  ------------------------------------------------------------------------
//
// Arguments    : const real_T contrastLayers_data[]
//                const int32_T contrastLayers_size[2]
//                real_T rough
//                const char_T geometry_data[]
//                const int32_T geometry_size[2]
//                real_T nba
//                real_T nbs
//                real_T resample
//                real_T calcSld
//                real_T sf
//                real_T qshift
//                real_T dataPresent
//                const real_T data_data[]
//                const int32_T data_size[2]
//                const real_T dataLimits[2]
//                const real_T simLimits_data[]
//                const real_T repeatLayers[2]
//                real_T background
//                real_T resol
//                real_T backsType
//                real_T params
//                const real_T resamPars[2]
//                ::coder::array<real_T, 2U> &sldProfile
//                ::coder::array<real_T, 2U> &reflect
//                ::coder::array<real_T, 2U> &Simul
//                real_T shifted_dat_data[]
//                int32_T shifted_dat_size[2]
//                real_T theseLayers_data[]
//                int32_T theseLayers_size[2]
//                ::coder::array<real_T, 2U> &resamLayers
//                real_T *chiSq
//                real_T *ssubs
// Return Type  : void
//
namespace RAT
{
  void b_standardTF_layers_core(const real_T contrastLayers_data[], const
    int32_T contrastLayers_size[2], real_T rough, const char_T geometry_data[],
    const int32_T geometry_size[2], real_T nba, real_T nbs, real_T resample,
    real_T calcSld, real_T sf, real_T qshift, real_T dataPresent, const real_T
    data_data[], const int32_T data_size[2], const real_T dataLimits[2], const
    real_T simLimits_data[], const real_T repeatLayers[2], real_T background,
    real_T resol, real_T backsType, real_T params, const real_T resamPars[2], ::
    coder::array<real_T, 2U> &sldProfile, ::coder::array<real_T, 2U> &reflect, ::
    coder::array<real_T, 2U> &Simul, real_T shifted_dat_data[], int32_T
    shifted_dat_size[2], real_T theseLayers_data[], int32_T theseLayers_size[2],
    ::coder::array<real_T, 2U> &resamLayers, real_T *chiSq, real_T *ssubs)
  {
    ::coder::array<real_T, 2U> b_theseLayers_data;
    ::coder::array<real_T, 2U> layerSld;
    real_T b_data_data[5000];
    int32_T b_data_size[2];
    int32_T loop_ub;

    //  Bulid up the layers matrix for this contrast
    groupLayers_Mod(contrastLayers_data, contrastLayers_size, rough,
                    geometry_data, geometry_size, nba, nbs, theseLayers_data,
                    theseLayers_size, ssubs);

    //  Make the SLD profiles.
    //  If resampling is needed, then enforce the calcSLD flag, so as to catch
    //  the error af trying to resample a non-existent profile.
    if ((resample == 1.0) && (calcSld == 0.0)) {
      calcSld = 1.0;
    }

    //  If calc SLD flag is set, then calculate the SLD profile
    if (calcSld == 1.0) {
      b_theseLayers_data.set(&theseLayers_data[0], theseLayers_size[0],
        theseLayers_size[1]);
      makeSLDProfiles(nba, nbs, b_theseLayers_data, *ssubs, repeatLayers,
                      sldProfile);
    } else {
      sldProfile.set_size(1, 2);
      sldProfile[0] = 0.0;
      sldProfile[sldProfile.size(0)] = 0.0;
    }

    //  If required, then resample the SLD
    if (resample == 1.0) {
      resampleLayers(sldProfile, resamPars, layerSld);
      resamLayers.set_size(layerSld.size(0), 3);
      loop_ub = layerSld.size(0);
      for (int32_T i{0}; i < 3; i++) {
        for (int32_T i1{0}; i1 < loop_ub; i1++) {
          resamLayers[i1 + resamLayers.size(0) * i] = layerSld[i1 +
            layerSld.size(0) * i];
        }
      }
    } else {
      layerSld.set_size(theseLayers_size[0], 3);
      resamLayers.set_size(1, 3);
      loop_ub = theseLayers_size[0];
      for (int32_T i{0}; i < 3; i++) {
        for (int32_T i1{0}; i1 < loop_ub; i1++) {
          layerSld[i1 + layerSld.size(0) * i] = theseLayers_data[i1 +
            theseLayers_size[0] * i];
        }

        resamLayers[resamLayers.size(0) * i] = 0.0;
      }
    }

    //  Apply scale factors and q shifts to the data
    b_data_size[0] = data_size[0];
    b_data_size[1] = data_size[1];
    loop_ub = data_size[1] - 1;
    for (int32_T i{0}; i <= loop_ub; i++) {
      int32_T b_loop_ub;
      b_loop_ub = data_size[0] - 1;
      for (int32_T i1{0}; i1 <= b_loop_ub; i1++) {
        b_data_data[i1 + b_data_size[0] * i] = data_data[i1 + data_size[0] * i];
      }
    }

    shiftdata(sf, qshift, dataPresent, b_data_data, b_data_size, dataLimits,
              simLimits_data, shifted_dat_data, shifted_dat_size);

    //  Calculate the reflectivity
    b_callReflectivity(nba, nbs, simLimits_data, repeatLayers, shifted_dat_data,
                       shifted_dat_size, layerSld, *ssubs, resol, reflect, Simul);

    //  Apply background correction, either to the simulation or the data
    applyBackgroundCorrection(reflect, Simul, shifted_dat_data, shifted_dat_size,
      background, backsType);

    //  Calculate chi squared.
    *chiSq = chiSquared(shifted_dat_data, shifted_dat_size, reflect, params);
  }

  //
  // This is the main reflectivity calculation for all Layers models in the
  //    standard target function.
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
  //    'Simulation' which can be a different range to allow extrapolation.
  //    The background correction is the applied, and finally chi-squared is
  //    calculated.
  //
  //  Inputs:
  //    contrastLayers  :
  //    rough           :
  //    geometry        :
  //    nba             :
  //    nbs             :
  //    resample        :
  //    calcSld         :
  //    sf              :
  //    qshift          :
  //    dataPresent     :
  //    data            :
  //    dataLimits      :
  //    simLimits       :
  //    repeatLayers    :
  //    background      :
  //    resol           :
  //    backsType       :
  //    params          :
  //    paralellPoints  :
  //
  //  Outputs:
  //
  //
  //
  //  ------------------------------------------------------------------------
  //
  //        (c) Arwel Hughes  -   12/1/21
  //
  //        Last Modified: 12/1/21 by Arwel Hughes.
  //
  //  ------------------------------------------------------------------------
  //
  // Arguments    : const ::coder::array<real_T, 2U> &contrastLayers
  //                real_T rough
  //                const char_T geometry_data[]
  //                const int32_T geometry_size[2]
  //                real_T nba
  //                real_T nbs
  //                real_T resample
  //                real_T calcSld
  //                real_T sf
  //                real_T qshift
  //                real_T dataPresent
  //                const real_T data_data[]
  //                const int32_T data_size[2]
  //                const real_T dataLimits[2]
  //                const real_T simLimits_data[]
  //                const real_T repeatLayers[2]
  //                real_T background
  //                real_T resol
  //                real_T backsType
  //                real_T params
  //                const real_T resamPars[2]
  //                ::coder::array<real_T, 2U> &sldProfile
  //                ::coder::array<real_T, 2U> &reflect
  //                ::coder::array<real_T, 2U> &Simul
  //                real_T shifted_dat_data[]
  //                int32_T shifted_dat_size[2]
  //                ::coder::array<real_T, 2U> &theseLayers
  //                ::coder::array<real_T, 2U> &resamLayers
  //                real_T *chiSq
  //                real_T *ssubs
  // Return Type  : void
  //
  void b_standardTF_layers_core(const ::coder::array<real_T, 2U> &contrastLayers,
    real_T rough, const char_T geometry_data[], const int32_T geometry_size[2],
    real_T nba, real_T nbs, real_T resample, real_T calcSld, real_T sf, real_T
    qshift, real_T dataPresent, const real_T data_data[], const int32_T
    data_size[2], const real_T dataLimits[2], const real_T simLimits_data[],
    const real_T repeatLayers[2], real_T background, real_T resol, real_T
    backsType, real_T params, const real_T resamPars[2], ::coder::array<real_T,
    2U> &sldProfile, ::coder::array<real_T, 2U> &reflect, ::coder::array<real_T,
    2U> &Simul, real_T shifted_dat_data[], int32_T shifted_dat_size[2], ::coder::
    array<real_T, 2U> &theseLayers, ::coder::array<real_T, 2U> &resamLayers,
    real_T *chiSq, real_T *ssubs)
  {
    ::coder::array<real_T, 2U> layerSld;
    real_T b_data_data[5000];
    int32_T b_data_size[2];
    int32_T loop_ub;

    //  Bulid up the layers matrix for this contrast
    groupLayers_Mod(contrastLayers, rough, geometry_data, geometry_size,
                    theseLayers, ssubs);

    //  Make the SLD profiles.
    //  If resampling is needed, then enforce the calcSLD flag, so as to catch
    //  the error af trying to resample a non-existent profile.
    if ((resample == 1.0) && (calcSld == 0.0)) {
      calcSld = 1.0;
    }

    //  If calc SLD flag is set, then calculate the SLD profile
    if (calcSld == 1.0) {
      makeSLDProfiles(nba, nbs, theseLayers, *ssubs, repeatLayers, sldProfile);
    } else {
      sldProfile.set_size(1, 2);
      sldProfile[0] = 0.0;
      sldProfile[sldProfile.size(0)] = 0.0;
    }

    //  If required, then resample the SLD
    if (resample == 1.0) {
      resampleLayers(sldProfile, resamPars, layerSld);
      resamLayers.set_size(layerSld.size(0), 3);
      loop_ub = layerSld.size(0);
      for (int32_T i{0}; i < 3; i++) {
        for (int32_T i1{0}; i1 < loop_ub; i1++) {
          resamLayers[i1 + resamLayers.size(0) * i] = layerSld[i1 +
            layerSld.size(0) * i];
        }
      }
    } else {
      layerSld.set_size(theseLayers.size(0), 3);
      resamLayers.set_size(1, 3);
      loop_ub = theseLayers.size(0);
      for (int32_T i{0}; i < 3; i++) {
        for (int32_T i1{0}; i1 < loop_ub; i1++) {
          layerSld[i1 + layerSld.size(0) * i] = theseLayers[i1 +
            theseLayers.size(0) * i];
        }

        resamLayers[resamLayers.size(0) * i] = 0.0;
      }
    }

    //  Apply scale factors and q shifts to the data
    b_data_size[0] = data_size[0];
    b_data_size[1] = data_size[1];
    loop_ub = data_size[1] - 1;
    for (int32_T i{0}; i <= loop_ub; i++) {
      int32_T b_loop_ub;
      b_loop_ub = data_size[0] - 1;
      for (int32_T i1{0}; i1 <= b_loop_ub; i1++) {
        b_data_data[i1 + b_data_size[0] * i] = data_data[i1 + data_size[0] * i];
      }
    }

    shiftdata(sf, qshift, dataPresent, b_data_data, b_data_size, dataLimits,
              simLimits_data, shifted_dat_data, shifted_dat_size);

    //  Calculate the reflectivity
    b_callReflectivity(nba, nbs, simLimits_data, repeatLayers, shifted_dat_data,
                       shifted_dat_size, layerSld, *ssubs, resol, reflect, Simul);

    //  Apply background correction, either to the simulation or the data
    applyBackgroundCorrection(reflect, Simul, shifted_dat_data, shifted_dat_size,
      background, backsType);

    //  Calculate chi squared.
    *chiSq = chiSquared(shifted_dat_data, shifted_dat_size, reflect, params);
  }

  //
  // This is the main reflectivity calculation for all Layers models in the
  //    standard target function.
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
  //    'Simulation' which can be a different range to allow extrapolation.
  //    The background correction is the applied, and finally chi-squared is
  //    calculated.
  //
  //  Inputs:
  //    contrastLayers  :
  //    rough           :
  //    geometry        :
  //    nba             :
  //    nbs             :
  //    resample        :
  //    calcSld         :
  //    sf              :
  //    qshift          :
  //    dataPresent     :
  //    data            :
  //    dataLimits      :
  //    simLimits       :
  //    repeatLayers    :
  //    background      :
  //    resol           :
  //    backsType       :
  //    params          :
  //    paralellPoints  :
  //
  //  Outputs:
  //
  //
  //
  //  ------------------------------------------------------------------------
  //
  //        (c) Arwel Hughes  -   12/1/21
  //
  //        Last Modified: 12/1/21 by Arwel Hughes.
  //
  //  ------------------------------------------------------------------------
  //
  // Arguments    : const real_T contrastLayers_data[]
  //                const int32_T contrastLayers_size[2]
  //                real_T rough
  //                const char_T geometry_data[]
  //                const int32_T geometry_size[2]
  //                real_T nba
  //                real_T nbs
  //                real_T resample
  //                real_T calcSld
  //                real_T sf
  //                real_T qshift
  //                real_T dataPresent
  //                const real_T data_data[]
  //                const int32_T data_size[2]
  //                const real_T dataLimits[2]
  //                const real_T simLimits_data[]
  //                const real_T repeatLayers[2]
  //                real_T background
  //                real_T resol
  //                real_T backsType
  //                real_T params
  //                const real_T resamPars[2]
  //                ::coder::array<real_T, 2U> &sldProfile
  //                ::coder::array<real_T, 2U> &reflect
  //                ::coder::array<real_T, 2U> &Simul
  //                real_T shifted_dat_data[]
  //                int32_T shifted_dat_size[2]
  //                real_T theseLayers_data[]
  //                int32_T theseLayers_size[2]
  //                ::coder::array<real_T, 2U> &resamLayers
  //                real_T *chiSq
  //                real_T *ssubs
  // Return Type  : void
  //
  void standardTF_layers_core(const real_T contrastLayers_data[], const int32_T
    contrastLayers_size[2], real_T rough, const char_T geometry_data[], const
    int32_T geometry_size[2], real_T nba, real_T nbs, real_T resample, real_T
    calcSld, real_T sf, real_T qshift, real_T dataPresent, const real_T
    data_data[], const int32_T data_size[2], const real_T dataLimits[2], const
    real_T simLimits_data[], const real_T repeatLayers[2], real_T background,
    real_T resol, real_T backsType, real_T params, const real_T resamPars[2], ::
    coder::array<real_T, 2U> &sldProfile, ::coder::array<real_T, 2U> &reflect, ::
    coder::array<real_T, 2U> &Simul, real_T shifted_dat_data[], int32_T
    shifted_dat_size[2], real_T theseLayers_data[], int32_T theseLayers_size[2],
    ::coder::array<real_T, 2U> &resamLayers, real_T *chiSq, real_T *ssubs)
  {
    ::coder::array<real_T, 2U> b_theseLayers_data;
    ::coder::array<real_T, 2U> layerSld;
    real_T b_data_data[5000];
    int32_T b_data_size[2];
    int32_T loop_ub;

    //  Bulid up the layers matrix for this contrast
    groupLayers_Mod(contrastLayers_data, contrastLayers_size, rough,
                    geometry_data, geometry_size, nba, nbs, theseLayers_data,
                    theseLayers_size, ssubs);

    //  Make the SLD profiles.
    //  If resampling is needed, then enforce the calcSLD flag, so as to catch
    //  the error af trying to resample a non-existent profile.
    if ((resample == 1.0) && (calcSld == 0.0)) {
      calcSld = 1.0;
    }

    //  If calc SLD flag is set, then calculate the SLD profile
    if (calcSld == 1.0) {
      b_theseLayers_data.set(&theseLayers_data[0], theseLayers_size[0],
        theseLayers_size[1]);
      makeSLDProfiles(nba, nbs, b_theseLayers_data, *ssubs, repeatLayers,
                      sldProfile);
    } else {
      sldProfile.set_size(1, 2);
      sldProfile[0] = 0.0;
      sldProfile[sldProfile.size(0)] = 0.0;
    }

    //  If required, then resample the SLD
    if (resample == 1.0) {
      resampleLayers(sldProfile, resamPars, layerSld);
      resamLayers.set_size(layerSld.size(0), 3);
      loop_ub = layerSld.size(0);
      for (int32_T i{0}; i < 3; i++) {
        for (int32_T i1{0}; i1 < loop_ub; i1++) {
          resamLayers[i1 + resamLayers.size(0) * i] = layerSld[i1 +
            layerSld.size(0) * i];
        }
      }
    } else {
      layerSld.set_size(theseLayers_size[0], 3);
      resamLayers.set_size(1, 3);
      loop_ub = theseLayers_size[0];
      for (int32_T i{0}; i < 3; i++) {
        for (int32_T i1{0}; i1 < loop_ub; i1++) {
          layerSld[i1 + layerSld.size(0) * i] = theseLayers_data[i1 +
            theseLayers_size[0] * i];
        }

        resamLayers[resamLayers.size(0) * i] = 0.0;
      }
    }

    //  Apply scale factors and q shifts to the data
    b_data_size[0] = data_size[0];
    b_data_size[1] = data_size[1];
    loop_ub = data_size[1] - 1;
    for (int32_T i{0}; i <= loop_ub; i++) {
      int32_T b_loop_ub;
      b_loop_ub = data_size[0] - 1;
      for (int32_T i1{0}; i1 <= b_loop_ub; i1++) {
        b_data_data[i1 + b_data_size[0] * i] = data_data[i1 + data_size[0] * i];
      }
    }

    shiftdata(sf, qshift, dataPresent, b_data_data, b_data_size, dataLimits,
              simLimits_data, shifted_dat_data, shifted_dat_size);

    //  Calculate the reflectivity
    callReflectivity(nba, nbs, simLimits_data, repeatLayers, shifted_dat_data,
                     shifted_dat_size, layerSld, *ssubs, resol, reflect, Simul);

    //  Apply background correction, either to the simulation or the data
    applyBackgroundCorrection(reflect, Simul, shifted_dat_data, shifted_dat_size,
      background, backsType);

    //  Calculate chi squared.
    *chiSq = chiSquared(shifted_dat_data, shifted_dat_size, reflect, params);
  }

  //
  // This is the main reflectivity calculation for all Layers models in the
  //    standard target function.
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
  //    'Simulation' which can be a different range to allow extrapolation.
  //    The background correction is the applied, and finally chi-squared is
  //    calculated.
  //
  //  Inputs:
  //    contrastLayers  :
  //    rough           :
  //    geometry        :
  //    nba             :
  //    nbs             :
  //    resample        :
  //    calcSld         :
  //    sf              :
  //    qshift          :
  //    dataPresent     :
  //    data            :
  //    dataLimits      :
  //    simLimits       :
  //    repeatLayers    :
  //    background      :
  //    resol           :
  //    backsType       :
  //    params          :
  //    paralellPoints  :
  //
  //  Outputs:
  //
  //
  //
  //  ------------------------------------------------------------------------
  //
  //        (c) Arwel Hughes  -   12/1/21
  //
  //        Last Modified: 12/1/21 by Arwel Hughes.
  //
  //  ------------------------------------------------------------------------
  //
  // Arguments    : const ::coder::array<real_T, 2U> &contrastLayers
  //                real_T rough
  //                const char_T geometry_data[]
  //                const int32_T geometry_size[2]
  //                real_T nba
  //                real_T nbs
  //                real_T resample
  //                real_T calcSld
  //                real_T sf
  //                real_T qshift
  //                real_T dataPresent
  //                const real_T data_data[]
  //                const int32_T data_size[2]
  //                const real_T dataLimits[2]
  //                const real_T simLimits_data[]
  //                const real_T repeatLayers[2]
  //                real_T background
  //                real_T resol
  //                real_T backsType
  //                real_T params
  //                const real_T resamPars[2]
  //                ::coder::array<real_T, 2U> &sldProfile
  //                ::coder::array<real_T, 2U> &reflect
  //                ::coder::array<real_T, 2U> &Simul
  //                real_T shifted_dat_data[]
  //                int32_T shifted_dat_size[2]
  //                ::coder::array<real_T, 2U> &theseLayers
  //                ::coder::array<real_T, 2U> &resamLayers
  //                real_T *chiSq
  //                real_T *ssubs
  // Return Type  : void
  //
  void standardTF_layers_core(const ::coder::array<real_T, 2U> &contrastLayers,
    real_T rough, const char_T geometry_data[], const int32_T geometry_size[2],
    real_T nba, real_T nbs, real_T resample, real_T calcSld, real_T sf, real_T
    qshift, real_T dataPresent, const real_T data_data[], const int32_T
    data_size[2], const real_T dataLimits[2], const real_T simLimits_data[],
    const real_T repeatLayers[2], real_T background, real_T resol, real_T
    backsType, real_T params, const real_T resamPars[2], ::coder::array<real_T,
    2U> &sldProfile, ::coder::array<real_T, 2U> &reflect, ::coder::array<real_T,
    2U> &Simul, real_T shifted_dat_data[], int32_T shifted_dat_size[2], ::coder::
    array<real_T, 2U> &theseLayers, ::coder::array<real_T, 2U> &resamLayers,
    real_T *chiSq, real_T *ssubs)
  {
    ::coder::array<real_T, 2U> layerSld;
    real_T b_data_data[5000];
    int32_T b_data_size[2];
    int32_T loop_ub;

    //  Bulid up the layers matrix for this contrast
    groupLayers_Mod(contrastLayers, rough, geometry_data, geometry_size,
                    theseLayers, ssubs);

    //  Make the SLD profiles.
    //  If resampling is needed, then enforce the calcSLD flag, so as to catch
    //  the error af trying to resample a non-existent profile.
    if ((resample == 1.0) && (calcSld == 0.0)) {
      calcSld = 1.0;
    }

    //  If calc SLD flag is set, then calculate the SLD profile
    if (calcSld == 1.0) {
      makeSLDProfiles(nba, nbs, theseLayers, *ssubs, repeatLayers, sldProfile);
    } else {
      sldProfile.set_size(1, 2);
      sldProfile[0] = 0.0;
      sldProfile[sldProfile.size(0)] = 0.0;
    }

    //  If required, then resample the SLD
    if (resample == 1.0) {
      resampleLayers(sldProfile, resamPars, layerSld);
      resamLayers.set_size(layerSld.size(0), 3);
      loop_ub = layerSld.size(0);
      for (int32_T i{0}; i < 3; i++) {
        for (int32_T i1{0}; i1 < loop_ub; i1++) {
          resamLayers[i1 + resamLayers.size(0) * i] = layerSld[i1 +
            layerSld.size(0) * i];
        }
      }
    } else {
      layerSld.set_size(theseLayers.size(0), 3);
      resamLayers.set_size(1, 3);
      loop_ub = theseLayers.size(0);
      for (int32_T i{0}; i < 3; i++) {
        for (int32_T i1{0}; i1 < loop_ub; i1++) {
          layerSld[i1 + layerSld.size(0) * i] = theseLayers[i1 +
            theseLayers.size(0) * i];
        }

        resamLayers[resamLayers.size(0) * i] = 0.0;
      }
    }

    //  Apply scale factors and q shifts to the data
    b_data_size[0] = data_size[0];
    b_data_size[1] = data_size[1];
    loop_ub = data_size[1] - 1;
    for (int32_T i{0}; i <= loop_ub; i++) {
      int32_T b_loop_ub;
      b_loop_ub = data_size[0] - 1;
      for (int32_T i1{0}; i1 <= b_loop_ub; i1++) {
        b_data_data[i1 + b_data_size[0] * i] = data_data[i1 + data_size[0] * i];
      }
    }

    shiftdata(sf, qshift, dataPresent, b_data_data, b_data_size, dataLimits,
              simLimits_data, shifted_dat_data, shifted_dat_size);

    //  Calculate the reflectivity
    callReflectivity(nba, nbs, simLimits_data, repeatLayers, shifted_dat_data,
                     shifted_dat_size, layerSld, *ssubs, resol, reflect, Simul);

    //  Apply background correction, either to the simulation or the data
    applyBackgroundCorrection(reflect, Simul, shifted_dat_data, shifted_dat_size,
      background, backsType);

    //  Calculate chi squared.
    *chiSq = chiSquared(shifted_dat_data, shifted_dat_size, reflect, params);
  }
}

//
// File trailer for standardTF_layers_core.cpp
//
// [EOF]
//
