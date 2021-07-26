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
  coder::array<double, 1U> b_shifted_dat;
  int i;
  int i1;
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
    loop_ub = r.size(0);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        sldProfile[i1 + sldProfile.size(0) * i] = r[i1 + r.size(0) * i];
      }
    }
  } else {
    sldProfile.set_size(1, 3);
    sldProfile[0] = 0.0;
    sldProfile[sldProfile.size(0)] = 0.0;
    sldProfile[sldProfile.size(0) * 2] = 0.0;
  }
  //  If required, then resample the SLD
  if (resample == 1.0) {
    resampleLayers(sldProfile, layerSld);
  }
  //  Apply scale factors and q shifts to the data
  b_data.set_size(data.size(0), data.size(1));
  loop_ub = data.size(1) - 1;
  for (i = 0; i <= loop_ub; i++) {
    int b_loop_ub;
    b_loop_ub = data.size(0) - 1;
    for (i1 = 0; i1 <= b_loop_ub; i1++) {
      b_data[i1 + b_data.size(0) * i] = data[i1 + data.size(0) * i];
    }
  }
  shiftdata(sf, qshift, dataPresent, b_data, dataLimits, simLimits,
            shifted_dat);
  //  Calculate the reflectivity
  callReflectivity(nba, nbs, simLimits, repeatLayers, shifted_dat, layerSld,
                   *ssubs, resol, reflect, Simul);
  //  Apply background correction, either to the simulation or the data
  switch (static_cast<int>(backsType)) {
  case 1:
    // Add background to the simulation
    reflect.set_size(reflect.size(0), 2);
    Simul.set_size(Simul.size(0), 2);
    for (i = 0; i < 2; i++) {
      loop_ub = reflect.size(0);
      for (i1 = 0; i1 < loop_ub; i1++) {
        reflect[i1 + reflect.size(0) * i] =
            reflect[i1 + reflect.size(0) * i] + background;
      }
      loop_ub = Simul.size(0);
      for (i1 = 0; i1 < loop_ub; i1++) {
        Simul[i1 + Simul.size(0) * i] =
            Simul[i1 + Simul.size(0) * i] + background;
      }
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
  coder::array<double, 2U> b_layers_data;
  coder::array<double, 2U> r;
  coder::array<double, 1U> b_shifted_dat;
  double layers_data[15];
  double allLayers[3][3];
  double c_layers_data[9];
  int b_ssubs;
  int i;
  int i1;
  int kstr;
  boolean_T b_bool;
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
  // Arrange layers according to geometry and apply any coverage correction.
  //
  // [outLayers, outSsubs] =
  // groupLayers_Mod(allLayers,allRoughs,numberOfContrasts,geometry,nbairs,nbsubs)
  //  Inputs:
  //      allLayers = cell array, one for each contrast. Each cell is the
  //                  list of layer values for each contrast.
  //                  e.g. allLayers{1} = [d1, rho1, r1, %hyd, hyd_which
  //                                       d2, rho2, r2, %hyd2, hyd_which_2..
  //                                       etc]
  //      allRoughs = Double of substrate roughness for each contrast.
  //      numberOfContrasts = double.
  //      geometry =  'Air / Liquid (or solid)' or 'Solid / Liquid'
  //      nbairs = vector of nbair values.
  //      nbsubs = vector of nbsub values.
  //
  //      The paratt calculation procedds through the
  //      z,rho,rough stack, and the parameter 'ssub' in
  //      callParatt is the final roughness encountered.
  //      For air liquid 'ssub' is therefore the substrate roughness.
  //      For solid liquid, the substrate roughness is the first roughness
  //      encountered, and 'ssub' is then the roughness of the outermost layer.
  //      The rougnesses need to be arranged accordingly.
  //
  //
  //  Outputs:
  //      outLayers = cell array of layers param values for each contrast.
  //                  e.g. outLayers{1} = [d1 rho1 r1;
  //                                       d2 rho2 r2
  //                                       ... etc   ]
  //      outSsubs = vector of substrate roughness values.
  //
  // outLayers = cell(1,numberOfContrasts);
  // outSsubs = zeros(1,numberOfContrasts);
  // for i = 1:numberOfContrasts
  b_ssubs = 3;
  b_bool = false;
  if (geometry.size(1) == 13) {
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 13) {
        if (cv[static_cast<unsigned char>(geometry[kstr]) & 127] !=
            cv[static_cast<int>(cv2[kstr])]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (b_bool) {
    for (i = 0; i < 3; i++) {
      layers_data[3 * i] = dv[i][0];
      layers_data[3 * i + 1] = dv[i][1];
      layers_data[3 * i + 2] = dv[i][2];
    }
    // s_sub = rsub;
  } else {
    b_ssubs = 4;
    allLayers[0][0] = 10.0;
    allLayers[1][0] = 1.0E-6;
    allLayers[0][1] = 50.0;
    allLayers[1][1] = 2.0E-6;
    allLayers[0][2] = 100.0;
    allLayers[1][2] = 1.0E-6;
    allLayers[2][0] = 3.0;
    allLayers[2][1] = 3.0;
    allLayers[2][2] = 4.0;
    for (i = 0; i < 3; i++) {
      layers_data[3 * i] = allLayers[i][0];
      layers_data[3 * i + 1] = allLayers[i][1];
      layers_data[3 * i + 2] = allLayers[i][2];
    }
  }
  // Deal with the %coverage if present
  //      problem.layers{i} = layers;
  //      problem.ssubs(i) = s_sub;
  //  Make the SLD profiles.
  //  If resampling is needed, then enforce the calcSLD flag, so as to catch
  //  the error af trying to resample a non-existent profile.
  if ((resample == 1.0) && (calcSld == 0.0)) {
    calcSld = 1.0;
  }
  //  If cal SLD flag is set, then calculate the SLD profile
  if (calcSld == 1.0) {
    for (i = 0; i < 3; i++) {
      c_layers_data[3 * i] = layers_data[3 * i];
      kstr = 3 * i + 1;
      c_layers_data[kstr] = layers_data[kstr];
      kstr = 3 * i + 2;
      c_layers_data[kstr] = layers_data[kstr];
    }
    b_layers_data.set(&c_layers_data[0], 3, 3);
    makeSLDProfiles(nba, nbs, b_layers_data, static_cast<double>(b_ssubs),
                    repeatLayers, r);
    sldProfile.set_size(r.size(0), 2);
    kstr = r.size(0);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < kstr; i1++) {
        sldProfile[i1 + sldProfile.size(0) * i] = r[i1 + r.size(0) * i];
      }
    }
  } else {
    sldProfile.set_size(1, 3);
    sldProfile[0] = 0.0;
    sldProfile[sldProfile.size(0)] = 0.0;
    sldProfile[sldProfile.size(0) * 2] = 0.0;
  }
  //  If required, then resample the SLD
  if (resample == 1.0) {
    resampleLayers(sldProfile, layerSld);
  } else {
    layerSld.set_size(3, 3);
    for (i = 0; i < 3; i++) {
      layerSld[layerSld.size(0) * i] = layers_data[3 * i];
      layerSld[layerSld.size(0) * i + 1] = layers_data[3 * i + 1];
      layerSld[layerSld.size(0) * i + 2] = layers_data[3 * i + 2];
    }
  }
  //  Apply scale factors and q shifts to the data
  b_data.set_size(data.size(0), data.size(1));
  kstr = data.size(1) - 1;
  for (i = 0; i <= kstr; i++) {
    int loop_ub;
    loop_ub = data.size(0) - 1;
    for (i1 = 0; i1 <= loop_ub; i1++) {
      b_data[i1 + b_data.size(0) * i] = data[i1 + data.size(0) * i];
    }
  }
  shiftdata(sf, qshift, dataPresent, b_data, dataLimits, simLimits,
            shifted_dat);
  //  Calculate the reflectivity
  callReflectivity(nba, nbs, simLimits, repeatLayers, shifted_dat, layerSld,
                   static_cast<double>(b_ssubs), resol, reflect, Simul);
  //  Apply background correction, either to the simulation or the data
  switch (static_cast<int>(backsType)) {
  case 1:
    // Add background to the simulation
    reflect.set_size(reflect.size(0), 2);
    Simul.set_size(Simul.size(0), 2);
    for (i = 0; i < 2; i++) {
      kstr = reflect.size(0);
      for (i1 = 0; i1 < kstr; i1++) {
        reflect[i1 + reflect.size(0) * i] =
            reflect[i1 + reflect.size(0) * i] + background;
      }
      kstr = Simul.size(0);
      for (i1 = 0; i1 < kstr; i1++) {
        Simul[i1 + Simul.size(0) * i] =
            Simul[i1 + Simul.size(0) * i] + background;
      }
    }
    break;
  case 2:
    //          %Subtract the background from the data..
    kstr = shifted_dat.size(0) - 1;
    b_shifted_dat.set_size(shifted_dat.size(0));
    for (i = 0; i <= kstr; i++) {
      b_shifted_dat[i] = shifted_dat[i + shifted_dat.size(0)] - background;
    }
    kstr = b_shifted_dat.size(0);
    for (i = 0; i < kstr; i++) {
      shifted_dat[i + shifted_dat.size(0)] = b_shifted_dat[i];
    }
    // shifted_dat(:,3) = shifted_dat(:,3) - backg;
    break;
  }
  //  Calculate chi squared.
  *chiSq = chiSquared(shifted_dat, reflect, params);
  *ssubs = b_ssubs;
}

// End of code generation (standardTF_layers_core.cpp)
