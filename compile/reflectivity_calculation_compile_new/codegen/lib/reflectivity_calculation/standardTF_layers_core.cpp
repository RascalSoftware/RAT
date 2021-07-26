//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// standardTF_layers_core.cpp
//
// Code generation for function 'standardTF_layers_core'
//

// Include files
#include "standardTF_layers_core.h"
#include "applyBackgroundCorrection.h"
#include "callReflectivity.h"
#include "chiSquared.h"
#include "groupLayers_Mod.h"
#include "makeSLDProfiles.h"
#include "reflectivity_calculation_data.h"
#include "resampleLayers.h"
#include "rt_nonfinite.h"
#include "shiftdata.h"
#include "coder_array.h"

// Function Definitions
void b_standardTF_layers_core(
    const coder::array<double, 2U> &contrastLayers, double rough,
    const coder::array<char, 2U> &geometry, double nba, double nbs,
    double resample, double calcSld, double sf, double qshift,
    double dataPresent, const coder::array<double, 2U> &data,
    const double dataLimits[2], const double simLimits[2],
    const double repeatLayers[2], double background, double resol,
    double backsType, double params, coder::array<double, 2U> &sldProfile,
    coder::array<double, 2U> &reflect, coder::array<double, 2U> &Simul,
    coder::array<double, 2U> &shifted_dat, coder::array<double, 2U> &layerSld,
    double *chiSq, double *ssubs)
{
  coder::array<double, 2U> b_data;
  coder::array<double, 2U> r;
  int i;
  int loop_ub;
  //    This is the main reflectivity calculation for all Layers models in the
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
    makeSLDProfiles(nba, nbs, layerSld, *ssubs, repeatLayers, r);
    sldProfile.set_size(r.size(0), 2);
    loop_ub = r.size(0) * 2;
    for (i = 0; i < loop_ub; i++) {
      sldProfile[i] = r[i];
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
  b_data.set_size(data.size(0), data.size(1));
  loop_ub = data.size(0) * data.size(1) - 1;
  for (i = 0; i <= loop_ub; i++) {
    b_data[i] = data[i];
  }
  shiftdata(sf, qshift, dataPresent, b_data, dataLimits, simLimits,
            shifted_dat);
  //  Calculate the reflectivity
  b_callReflectivity(nba, nbs, simLimits, repeatLayers, shifted_dat, layerSld,
                     *ssubs, resol, reflect, Simul);
  //  Apply background correction, either to the simulation or the data
  applyBackgroundCorrection(reflect, Simul, shifted_dat, background, backsType);
  //  Calculate chi squared.
  *chiSq = chiSquared(shifted_dat, reflect, params);
}

void b_standardTF_layers_core(
    const coder::array<char, 2U> &geometry, double nba, double nbs,
    double resample, double calcSld, double sf, double qshift,
    double dataPresent, const coder::array<double, 2U> &data,
    const double dataLimits[2], const double simLimits[2],
    const double repeatLayers[2], double background, double resol,
    double backsType, double params, coder::array<double, 2U> &sldProfile,
    coder::array<double, 2U> &reflect, coder::array<double, 2U> &Simul,
    coder::array<double, 2U> &shifted_dat, coder::array<double, 2U> &layerSld,
    double *chiSq, double *ssubs)
{
  coder::array<double, 2U> b_data;
  coder::array<double, 2U> b_theseLayers_data;
  coder::array<double, 2U> r;
  double theseLayers_data[9];
  int theseLayers_size[2];
  int i;
  int loop_ub;
  //    This is the main reflectivity calculation for all Layers models in the
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
  //  Bulid up the layers matrix for this contrast
  groupLayers_Mod(dv, geometry, theseLayers_data, theseLayers_size, ssubs);
  //  Make the SLD profiles.
  //  If resampling is needed, then enforce the calcSLD flag, so as to catch
  //  the error af trying to resample a non-existent profile.
  if ((resample == 1.0) && (calcSld == 0.0)) {
    calcSld = 1.0;
  }
  //  If cal SLD flag is set, then calculate the SLD profile
  if (calcSld == 1.0) {
    b_theseLayers_data.set(&theseLayers_data[0], theseLayers_size[0],
                           theseLayers_size[1]);
    makeSLDProfiles(nba, nbs, b_theseLayers_data, *ssubs, repeatLayers, r);
    sldProfile.set_size(r.size(0), 2);
    loop_ub = r.size(0) * 2;
    for (i = 0; i < loop_ub; i++) {
      sldProfile[i] = r[i];
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
  } else {
    layerSld.set_size(3, 3);
    for (i = 0; i < 9; i++) {
      layerSld[i] = theseLayers_data[i];
    }
  }
  //  Apply scale factors and q shifts to the data
  b_data.set_size(data.size(0), data.size(1));
  loop_ub = data.size(0) * data.size(1) - 1;
  for (i = 0; i <= loop_ub; i++) {
    b_data[i] = data[i];
  }
  shiftdata(sf, qshift, dataPresent, b_data, dataLimits, simLimits,
            shifted_dat);
  //  Calculate the reflectivity
  b_callReflectivity(nba, nbs, simLimits, repeatLayers, shifted_dat, layerSld,
                     *ssubs, resol, reflect, Simul);
  //  Apply background correction, either to the simulation or the data
  applyBackgroundCorrection(reflect, Simul, shifted_dat, background, backsType);
  //  Calculate chi squared.
  *chiSq = chiSquared(shifted_dat, reflect, params);
}

void standardTF_layers_core(
    const coder::array<double, 2U> &contrastLayers, double rough,
    const coder::array<char, 2U> &geometry, double nba, double nbs,
    double resample, double calcSld, double sf, double qshift,
    double dataPresent, const coder::array<double, 2U> &data,
    const double dataLimits[2], const double simLimits[2],
    const double repeatLayers[2], double background, double resol,
    double backsType, double params, coder::array<double, 2U> &sldProfile,
    coder::array<double, 2U> &reflect, coder::array<double, 2U> &Simul,
    coder::array<double, 2U> &shifted_dat, coder::array<double, 2U> &layerSld,
    double *chiSq, double *ssubs)
{
  coder::array<double, 2U> b_data;
  coder::array<double, 2U> r;
  int i;
  int loop_ub;
  //    This is the main reflectivity calculation for all Layers models in the
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
    makeSLDProfiles(nba, nbs, layerSld, *ssubs, repeatLayers, r);
    sldProfile.set_size(r.size(0), 2);
    loop_ub = r.size(0) * 2;
    for (i = 0; i < loop_ub; i++) {
      sldProfile[i] = r[i];
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
  b_data.set_size(data.size(0), data.size(1));
  loop_ub = data.size(0) * data.size(1) - 1;
  for (i = 0; i <= loop_ub; i++) {
    b_data[i] = data[i];
  }
  shiftdata(sf, qshift, dataPresent, b_data, dataLimits, simLimits,
            shifted_dat);
  //  Calculate the reflectivity
  callReflectivity(nba, nbs, simLimits, repeatLayers, shifted_dat, layerSld,
                   *ssubs, resol, reflect, Simul);
  //  Apply background correction, either to the simulation or the data
  applyBackgroundCorrection(reflect, Simul, shifted_dat, background, backsType);
  //  Calculate chi squared.
  *chiSq = chiSquared(shifted_dat, reflect, params);
}

void standardTF_layers_core(
    const coder::array<char, 2U> &geometry, double nba, double nbs,
    double resample, double calcSld, double sf, double qshift,
    double dataPresent, const coder::array<double, 2U> &data,
    const double dataLimits[2], const double simLimits[2],
    const double repeatLayers[2], double background, double resol,
    double backsType, double params, coder::array<double, 2U> &sldProfile,
    coder::array<double, 2U> &reflect, coder::array<double, 2U> &Simul,
    coder::array<double, 2U> &shifted_dat, coder::array<double, 2U> &layerSld,
    double *chiSq, double *ssubs)
{
  coder::array<double, 2U> b_data;
  coder::array<double, 2U> b_theseLayers_data;
  coder::array<double, 2U> r;
  double theseLayers_data[9];
  int theseLayers_size[2];
  int i;
  int loop_ub;
  //    This is the main reflectivity calculation for all Layers models in the
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
  //  Bulid up the layers matrix for this contrast
  groupLayers_Mod(dv, geometry, theseLayers_data, theseLayers_size, ssubs);
  //  Make the SLD profiles.
  //  If resampling is needed, then enforce the calcSLD flag, so as to catch
  //  the error af trying to resample a non-existent profile.
  if ((resample == 1.0) && (calcSld == 0.0)) {
    calcSld = 1.0;
  }
  //  If cal SLD flag is set, then calculate the SLD profile
  if (calcSld == 1.0) {
    b_theseLayers_data.set(&theseLayers_data[0], theseLayers_size[0],
                           theseLayers_size[1]);
    makeSLDProfiles(nba, nbs, b_theseLayers_data, *ssubs, repeatLayers, r);
    sldProfile.set_size(r.size(0), 2);
    loop_ub = r.size(0) * 2;
    for (i = 0; i < loop_ub; i++) {
      sldProfile[i] = r[i];
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
  } else {
    layerSld.set_size(3, 3);
    for (i = 0; i < 9; i++) {
      layerSld[i] = theseLayers_data[i];
    }
  }
  //  Apply scale factors and q shifts to the data
  b_data.set_size(data.size(0), data.size(1));
  loop_ub = data.size(0) * data.size(1) - 1;
  for (i = 0; i <= loop_ub; i++) {
    b_data[i] = data[i];
  }
  shiftdata(sf, qshift, dataPresent, b_data, dataLimits, simLimits,
            shifted_dat);
  //  Calculate the reflectivity
  callReflectivity(nba, nbs, simLimits, repeatLayers, shifted_dat, layerSld,
                   *ssubs, resol, reflect, Simul);
  //  Apply background correction, either to the simulation or the data
  applyBackgroundCorrection(reflect, Simul, shifted_dat, background, backsType);
  //  Calculate chi squared.
  *chiSq = chiSquared(shifted_dat, reflect, params);
}

// End of code generation (standardTF_layers_core.cpp)
