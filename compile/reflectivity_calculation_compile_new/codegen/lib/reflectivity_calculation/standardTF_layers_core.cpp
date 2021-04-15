//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: standardTF_layers_core.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 15-Apr-2021 10:46:16
//

// Include Files
#include "standardTF_layers_core.h"
#include "callReflectivity.h"
#include "chiSquared.h"
#include "groupLayers_Mod.h"
#include "makeSLDProfileXY.h"
#include "reflectivity_calculation.h"
#include "resampleLayers.h"
#include "rt_nonfinite.h"
#include "shiftdata.h"
#include "standardTF_stanLay_reflectivityCalculation.h"

// Function Definitions

//
// function [sldProfile,reflect,Simul,shifted_dat,layerSld,chiSquared,ssubs] = ...
//      standardTF_stanlay_core(contrastLayers, rough, ...
//      geometry, nba, nbs, resample, calcSld, sf, qshift,...
//      dataPresent, data, dataLimits, simLimits, repeatLayers,...
//      background,resol,backsType,params,paralellPoints)
//
//    This is the main reflectivity calculation for Layers models in the
//    standard target function. The function first arranges the
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
// Arguments    : const coder::array<double, 2U> *contrastLayers
//                double rough
//                const coder::array<char, 2U> *geometry
//                double nba
//                double nbs
//                double resample
//                double calcSld
//                double sf
//                double qshift
//                double dataPresent
//                const coder::array<double, 2U> *data
//                const double dataLimits[2]
//                const double simLimits[2]
//                const double repeatLayers[2]
//                double background
//                double resol
//                double backsType
//                double params
//                coder::array<double, 2U> *sldProfile
//                coder::array<double, 2U> *reflect
//                coder::array<double, 2U> *Simul
//                coder::array<double, 2U> *shifted_dat
//                coder::array<double, 2U> *layerSld
//                double *chiSq
//                double *ssubs
// Return Type  : void
//
void b_standardTF_layers_core(const coder::array<double, 2U> &contrastLayers,
  double rough, const coder::array<char, 2U> &geometry, double nba, double nbs,
  double resample, double calcSld, double sf, double qshift, double dataPresent,
  const coder::array<double, 2U> &data, const double dataLimits[2], const double
  simLimits[2], const double repeatLayers[2], double background, double resol,
  double backsType, double params, coder::array<double, 2U> &sldProfile, coder::
  array<double, 2U> &reflect, coder::array<double, 2U> &Simul, coder::array<
  double, 2U> &shifted_dat, coder::array<double, 2U> &layerSld, double *chiSq,
  double *ssubs)
{
  coder::array<double, 2U> b_sldProfile;
  int loop_ub;
  int i;
  coder::array<double, 1U> b_shifted_dat;

  //  Bulid up the layers matrix for this contrast
  groupLayers_Mod(contrastLayers, rough, geometry, nba, nbs, layerSld, ssubs);

  //  Make the SLD profiles.
  //  If resampling is needed, then enforce the calcSLD flag, so as to catch
  //  the error af trying to resample a non-existent profile.
  if ((resample == 1.0) && (calcSld == 0.0)) {
    calcSld = 1.0;
  }

  //  If cal SLD flag is set, then calculate the SLD profile
  if (calcSld == 1.0) {
    double b_repeatLayers;
    if (repeatLayers[0] == 0.0) {
      b_repeatLayers = 1.0;
    } else {
      b_repeatLayers = repeatLayers[1];
    }

    makeSLDProfileXY(nba, nbs, *ssubs, layerSld, static_cast<double>
                     (layerSld.size(0)), b_repeatLayers, b_sldProfile);
    sldProfile.set_size(b_sldProfile.size(0), 2);
    loop_ub = b_sldProfile.size(0) * b_sldProfile.size(1);
    for (i = 0; i < loop_ub; i++) {
      sldProfile[i] = b_sldProfile[i];
    }
  } else {
    sldProfile.set_size(1, 3);
    sldProfile[0] = 0.0;
    sldProfile[1] = 0.0;
    sldProfile[2] = 0.0;
  }

  //  If required, then resample the SLD
  if (resample == 1.0) {
    resampleLayers(sldProfile, layerSld);
  }

  //  Apply scale factors and q shifts to the data
  shifted_dat.set_size(data.size(0), data.size(1));
  loop_ub = data.size(0) * data.size(1);
  for (i = 0; i < loop_ub; i++) {
    shifted_dat[i] = data[i];
  }

  shiftdata(sf, qshift, dataPresent, shifted_dat, dataLimits);

  //  Calculate the reflectivity
  b_callReflectivity(nba, nbs, simLimits, repeatLayers, shifted_dat, layerSld,
                     *ssubs, resol, reflect, Simul);

  //  Apply background correction, either to the simulation or the data
  switch (static_cast<int>(backsType)) {
   case 1:
    // Add background to the simulation
    loop_ub = reflect.size(0) * reflect.size(1);
    reflect.set_size(reflect.size(0), 2);
    for (i = 0; i < loop_ub; i++) {
      reflect[i] = reflect[i] + background;
    }

    loop_ub = Simul.size(0) * Simul.size(1);
    Simul.set_size(Simul.size(0), 2);
    for (i = 0; i < loop_ub; i++) {
      Simul[i] = Simul[i] + background;
    }
    break;

   case 2:
    //          %Subtract the background from the data..
    loop_ub = shifted_dat.size(0) - 1;
    b_shifted_dat.set_size(shifted_dat.size(0));
    for (i = 0; i <= loop_ub; i++) {
      b_shifted_dat[i] = shifted_dat[i + shifted_dat.size(0)] - background;
    }

    loop_ub = b_shifted_dat.size(0);
    for (i = 0; i < loop_ub; i++) {
      shifted_dat[i + shifted_dat.size(0)] = b_shifted_dat[i];
    }

    // shifted_dat(:,3) = shifted_dat(:,3) - backg;
    break;
  }

  //  Calculate chi squared.
  *chiSq = chiSquared(shifted_dat, reflect, params);
}

//
// function [sldProfile,reflect,Simul,shifted_dat,layerSld,chiSquared,ssubs] = ...
//      standardTF_stanlay_core(contrastLayers, rough, ...
//      geometry, nba, nbs, resample, calcSld, sf, qshift,...
//      dataPresent, data, dataLimits, simLimits, repeatLayers,...
//      background,resol,backsType,params,paralellPoints)
//
//    This is the main reflectivity calculation for Layers models in the
//    standard target function. The function first arranges the
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
// Arguments    : const coder::array<double, 2U> *contrastLayers
//                double rough
//                const coder::array<char, 2U> *geometry
//                double nba
//                double nbs
//                double resample
//                double calcSld
//                double sf
//                double qshift
//                double dataPresent
//                const coder::array<double, 2U> *data
//                const double dataLimits[2]
//                const double simLimits[2]
//                const double repeatLayers[2]
//                double background
//                double resol
//                double backsType
//                double params
//                coder::array<double, 2U> *sldProfile
//                coder::array<double, 2U> *reflect
//                coder::array<double, 2U> *Simul
//                coder::array<double, 2U> *shifted_dat
//                coder::array<double, 2U> *layerSld
//                double *chiSq
//                double *ssubs
// Return Type  : void
//
void standardTF_layers_core(const coder::array<double, 2U> &contrastLayers,
  double rough, const coder::array<char, 2U> &geometry, double nba, double nbs,
  double resample, double calcSld, double sf, double qshift, double dataPresent,
  const coder::array<double, 2U> &data, const double dataLimits[2], const double
  simLimits[2], const double repeatLayers[2], double background, double resol,
  double backsType, double params, coder::array<double, 2U> &sldProfile, coder::
  array<double, 2U> &reflect, coder::array<double, 2U> &Simul, coder::array<
  double, 2U> &shifted_dat, coder::array<double, 2U> &layerSld, double *chiSq,
  double *ssubs)
{
  coder::array<double, 2U> b_sldProfile;
  int loop_ub;
  int i;
  coder::array<double, 1U> b_shifted_dat;

  //  Bulid up the layers matrix for this contrast
  groupLayers_Mod(contrastLayers, rough, geometry, nba, nbs, layerSld, ssubs);

  //  Make the SLD profiles.
  //  If resampling is needed, then enforce the calcSLD flag, so as to catch
  //  the error af trying to resample a non-existent profile.
  if ((resample == 1.0) && (calcSld == 0.0)) {
    calcSld = 1.0;
  }

  //  If cal SLD flag is set, then calculate the SLD profile
  if (calcSld == 1.0) {
    double b_repeatLayers;
    if (repeatLayers[0] == 0.0) {
      b_repeatLayers = 1.0;
    } else {
      b_repeatLayers = repeatLayers[1];
    }

    makeSLDProfileXY(nba, nbs, *ssubs, layerSld, static_cast<double>
                     (layerSld.size(0)), b_repeatLayers, b_sldProfile);
    sldProfile.set_size(b_sldProfile.size(0), 2);
    loop_ub = b_sldProfile.size(0) * b_sldProfile.size(1);
    for (i = 0; i < loop_ub; i++) {
      sldProfile[i] = b_sldProfile[i];
    }
  } else {
    sldProfile.set_size(1, 3);
    sldProfile[0] = 0.0;
    sldProfile[1] = 0.0;
    sldProfile[2] = 0.0;
  }

  //  If required, then resample the SLD
  if (resample == 1.0) {
    resampleLayers(sldProfile, layerSld);
  }

  //  Apply scale factors and q shifts to the data
  shifted_dat.set_size(data.size(0), data.size(1));
  loop_ub = data.size(0) * data.size(1);
  for (i = 0; i < loop_ub; i++) {
    shifted_dat[i] = data[i];
  }

  shiftdata(sf, qshift, dataPresent, shifted_dat, dataLimits);

  //  Calculate the reflectivity
  callReflectivity(nba, nbs, simLimits, repeatLayers, shifted_dat, layerSld,
                   *ssubs, resol, reflect, Simul);

  //  Apply background correction, either to the simulation or the data
  switch (static_cast<int>(backsType)) {
   case 1:
    // Add background to the simulation
    loop_ub = reflect.size(0) * reflect.size(1);
    reflect.set_size(reflect.size(0), 2);
    for (i = 0; i < loop_ub; i++) {
      reflect[i] = reflect[i] + background;
    }

    loop_ub = Simul.size(0) * Simul.size(1);
    Simul.set_size(Simul.size(0), 2);
    for (i = 0; i < loop_ub; i++) {
      Simul[i] = Simul[i] + background;
    }
    break;

   case 2:
    //          %Subtract the background from the data..
    loop_ub = shifted_dat.size(0) - 1;
    b_shifted_dat.set_size(shifted_dat.size(0));
    for (i = 0; i <= loop_ub; i++) {
      b_shifted_dat[i] = shifted_dat[i + shifted_dat.size(0)] - background;
    }

    loop_ub = b_shifted_dat.size(0);
    for (i = 0; i < loop_ub; i++) {
      shifted_dat[i + shifted_dat.size(0)] = b_shifted_dat[i];
    }

    // shifted_dat(:,3) = shifted_dat(:,3) - backg;
    break;
  }

  //  Calculate chi squared.
  *chiSq = chiSquared(shifted_dat, reflect, params);
}

//
// File trailer for standardTF_layers_core.cpp
//
// [EOF]
//
