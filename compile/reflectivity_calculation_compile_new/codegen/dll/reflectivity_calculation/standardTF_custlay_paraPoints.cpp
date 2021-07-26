//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// standardTF_custlay_paraPoints.cpp
//
// Code generation for function 'standardTF_custlay_paraPoints'
//

// Include files
#include "standardTF_custlay_paraPoints.h"
#include "backSort.h"
#include "callReflectivity.h"
#include "chiSquared.h"
#include "makeSLDProfiles.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_internal_types.h"
#include "reflectivity_calculation_types.h"
#include "resampleLayers.h"
#include "rt_nonfinite.h"
#include "shiftdata.h"
#include "coder_array.h"

// Function Definitions
void standardTF_custlay_paraPoints(
    const struct0_T *problemDef, const cell_14 *problemDef_cells,
    const struct2_T *controls, coder::array<double, 1U> &outSsubs,
    coder::array<double, 1U> &backgs, coder::array<double, 1U> &qshifts,
    coder::array<double, 1U> &sfs, coder::array<double, 1U> &nbas,
    coder::array<double, 1U> &nbss, coder::array<double, 1U> &resols,
    coder::array<double, 1U> &chis,
    coder::array<cell_wrap_10, 1U> &reflectivity,
    coder::array<cell_wrap_10, 1U> &Simulation,
    coder::array<cell_wrap_1, 1U> &shifted_data,
    coder::array<cell_wrap_8, 1U> &layerSlds,
    coder::array<cell_wrap_1, 1U> &sldProfiles,
    coder::array<cell_wrap_29, 1U> &allLayers,
    coder::array<double, 1U> &allRoughs)
{
  coder::array<double, 2U> Simul;
  coder::array<double, 2U> b_layers_data;
  coder::array<double, 2U> b_problemDef_cells;
  coder::array<double, 2U> layerSld;
  coder::array<double, 2U> reflect;
  coder::array<double, 2U> shifted_dat;
  coder::array<double, 2U> sldProfile;
  coder::array<double, 1U> b_shifted_dat;
  double layers_data[15];
  double c_layers_data[9];
  double outLayers[3][3];
  double calcSld;
  double thisBackground;
  double thisNba;
  double thisNbs;
  double thisQshift;
  double thisResol;
  double thisSf;
  int i;
  //  Multi threaded version of the custom layers over reflectivity poimnts
  //  for standardTF reflectivity calculation.
  //  The function extracts the relevant parameters from the input
  //  arrays, allocates these on a pre-contrast basis, then calls the 'core'
  //  calculation (the core layers standardTf calc is shared between multiple
  //  calculation types).
  //  Extract individual cell arrays
  //  Splits up the master input list of all arrays into separate arrays
  //  The min input array 'problemDef_cells' is a master array where
  //  all the cell arrays are grouped together. There are
  //  repeatLayers      - controls repeating of the layers stack
  //  allData           - Array of all the data arrays
  //  dataLimits        - Min max limits in q for the data arrays
  //  simLimits         - Limits in Q for the reflkectivity simulations
  //  Layers details    - Master array of all available layers
  //  contrastLayers    - Which specific combination of arrays are needed for
  //                      each contrast.
  //  Custom files      - Filenames and path for any custom files used
  //  Extract individual parameters from problemDef struct
  // Extract individual parameters from problemDef
  calcSld = controls->calcSld;
  //  Pre-Allocation of output arrays...
  //    --- Begin Memory Allocation ---
  i = static_cast<int>(problemDef->numberOfContrasts);
  backgs.set_size(i);
  //    --- End Memory Allocation ---
  //  Single cored over all contrasts
  allRoughs.set_size(i);
  allLayers.set_size(i);
  outSsubs.set_size(i);
  sldProfiles.set_size(i);
  reflectivity.set_size(i);
  Simulation.set_size(i);
  shifted_data.set_size(i);
  layerSlds.set_size(i);
  chis.set_size(i);
  qshifts.set_size(i);
  sfs.set_size(i);
  nbas.set_size(i);
  nbss.set_size(i);
  resols.set_size(i);
  for (int b_i{0}; b_i < i; b_i++) {
    double b_calcSld;
    int i1;
    int i2;
    int kstr;
    int loop_ub;
    int ssubs;
    boolean_T b_bool;
    //  Extract the relevant parameter values for this contrast
    //  from the input arrays.
    //  First need to decide which values of the backrounds, scalefactors
    //  data shifts and bulk contrasts are associated with this contrast
    backSort(problemDef->contrastBacks[b_i], problemDef->contrastShifts[b_i],
             problemDef->contrastScales[b_i], problemDef->contrastNbas[b_i],
             problemDef->contrastNbss[b_i], problemDef->contrastRes[b_i],
             problemDef->backs, problemDef->shifts, problemDef->sf,
             problemDef->nba, problemDef->nbs, problemDef->res, &thisBackground,
             &thisQshift, &thisSf, &thisNba, &thisNbs, &thisResol);
    //  Call the custom layers function to get the layers array...
    allRoughs[b_i] = 3.0;
    allLayers[b_i].f1.set_size(3, 3);
    for (i1 = 0; i1 < 3; i1++) {
      allLayers[b_i].f1[allLayers[b_i].f1.size(0) * i1] = dv[i1][0];
      allLayers[b_i].f1[allLayers[b_i].f1.size(0) * i1 + 1] = dv[i1][1];
      allLayers[b_i].f1[allLayers[b_i].f1.size(0) * i1 + 2] = dv[i1][2];
    }
    //  For the other parameters, we extract the correct ones from the input
    //  arrays
    //  Now call the core standardTF_stanlay reflectivity calculation
    //  In this case we are multi threaded over
    //  points
    //  Call the reflectivity calculation
    b_calcSld = calcSld;
    //    This is the main reflectivity calculation for all Layers models in the
    //    standard target function.
    //
    //    The function first arranges the
    //    roughness' in the correct order according
    //    to geometry. Then, if required it calculates the SLD profile and if
    //    requested resamples this into a number of zero-roughness layers
    //    (roughness resampling). It the applies any scalefactors and qz shifts
    //    the data requires. This is done before calculating the reflectivity to
    //    ensure that the reflectivity is calculated over the same range in qz
    //    as the shifted datapoints. The main reflectivity calculation is then
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
    //      encountered, and 'ssub' is then the roughness of the outermost
    //      layer. The rougnesses need to be arranged accordingly.
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
    ssubs = 3;
    b_bool = false;
    if (problemDef->geometry.size(1) == 13) {
      kstr = 0;
      int exitg1;
      do {
        exitg1 = 0;
        if (kstr < 13) {
          if (cv[static_cast<unsigned char>(problemDef->geometry[kstr]) &
                 127] != cv[static_cast<int>(cv2[kstr])]) {
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
      for (i1 = 0; i1 < 3; i1++) {
        layers_data[3 * i1] = dv[i1][0];
        layers_data[3 * i1 + 1] = dv[i1][1];
        layers_data[3 * i1 + 2] = dv[i1][2];
      }
      // s_sub = rsub;
    } else {
      ssubs = 4;
      outLayers[0][0] = 10.0;
      outLayers[1][0] = 1.0E-6;
      outLayers[0][1] = 50.0;
      outLayers[1][1] = 2.0E-6;
      outLayers[0][2] = 100.0;
      outLayers[1][2] = 1.0E-6;
      outLayers[2][0] = 3.0;
      outLayers[2][1] = 3.0;
      outLayers[2][2] = 4.0;
      for (i1 = 0; i1 < 3; i1++) {
        layers_data[3 * i1] = outLayers[i1][0];
        layers_data[3 * i1 + 1] = outLayers[i1][1];
        layers_data[3 * i1 + 2] = outLayers[i1][2];
      }
    }
    // Deal with the %coverage if present
    //      problem.layers{i} = layers;
    //      problem.ssubs(i) = s_sub;
    outSsubs[b_i] = ssubs;
    //  Make the SLD profiles.
    //  If resampling is needed, then enforce the calcSLD flag, so as to catch
    //  the error af trying to resample a non-existent profile.
    if ((problemDef->resample[b_i] == 1.0) && (calcSld == 0.0)) {
      b_calcSld = 1.0;
    }
    //  If cal SLD flag is set, then calculate the SLD profile
    if (b_calcSld == 1.0) {
      for (i1 = 0; i1 < 3; i1++) {
        c_layers_data[3 * i1] = layers_data[3 * i1];
        kstr = 3 * i1 + 1;
        c_layers_data[kstr] = layers_data[kstr];
        kstr = 3 * i1 + 2;
        c_layers_data[kstr] = layers_data[kstr];
      }
      b_layers_data.set(&c_layers_data[0], 3, 3);
      makeSLDProfiles(thisNba, thisNbs, b_layers_data,
                      static_cast<double>(ssubs), problemDef_cells->f1[b_i].f1,
                      reflect);
      sldProfile.set_size(reflect.size(0), 2);
      kstr = reflect.size(0);
      for (i1 = 0; i1 < 2; i1++) {
        for (i2 = 0; i2 < kstr; i2++) {
          sldProfile[i2 + sldProfile.size(0) * i1] =
              reflect[i2 + reflect.size(0) * i1];
        }
      }
    } else {
      sldProfile.set_size(1, 3);
      sldProfile[0] = 0.0;
      sldProfile[sldProfile.size(0)] = 0.0;
      sldProfile[sldProfile.size(0) * 2] = 0.0;
    }
    //  If required, then resample the SLD
    if (problemDef->resample[b_i] == 1.0) {
      resampleLayers(sldProfile, layerSld);
    } else {
      layerSld.set_size(3, 3);
      for (i1 = 0; i1 < 3; i1++) {
        layerSld[layerSld.size(0) * i1] = layers_data[3 * i1];
        layerSld[layerSld.size(0) * i1 + 1] = layers_data[3 * i1 + 1];
        layerSld[layerSld.size(0) * i1 + 2] = layers_data[3 * i1 + 2];
      }
    }
    //  Apply scale factors and q shifts to the data
    b_problemDef_cells.set_size(
        problemDef_cells->f2[problemDef_cells->f2.size(0) * b_i].f1.size(0),
        problemDef_cells->f2[problemDef_cells->f2.size(0) * b_i].f1.size(1));
    kstr = problemDef_cells->f2[b_i].f1.size(1) - 1;
    for (i1 = 0; i1 <= kstr; i1++) {
      loop_ub = problemDef_cells->f2[b_i].f1.size(0) - 1;
      for (i2 = 0; i2 <= loop_ub; i2++) {
        b_problemDef_cells[i2 + b_problemDef_cells.size(0) * i1] =
            problemDef_cells->f2[b_i]
                .f1[i2 + problemDef_cells->f2[b_i].f1.size(0) * i1];
      }
    }
    shiftdata(thisSf, thisQshift, problemDef->dataPresent[b_i],
              b_problemDef_cells, problemDef_cells->f3[b_i].f1,
              problemDef_cells->f4[b_i].f1, shifted_dat);
    //  Calculate the reflectivity
    b_callReflectivity(thisNba, thisNbs, problemDef_cells->f4[b_i].f1,
                       problemDef_cells->f1[b_i].f1, shifted_dat, layerSld,
                       static_cast<double>(ssubs), thisResol, reflect, Simul);
    //  Apply background correction, either to the simulation or the data
    switch (static_cast<int>(problemDef->contrastBacksType[b_i])) {
    case 1:
      // Add background to the simulation
      reflect.set_size(reflect.size(0), 2);
      Simul.set_size(Simul.size(0), 2);
      for (i1 = 0; i1 < 2; i1++) {
        kstr = reflect.size(0);
        for (i2 = 0; i2 < kstr; i2++) {
          reflect[i2 + reflect.size(0) * i1] =
              reflect[i2 + reflect.size(0) * i1] + thisBackground;
        }
        kstr = Simul.size(0);
        for (i2 = 0; i2 < kstr; i2++) {
          Simul[i2 + Simul.size(0) * i1] =
              Simul[i2 + Simul.size(0) * i1] + thisBackground;
        }
      }
      break;
    case 2:
      //          %Subtract the background from the data..
      kstr = shifted_dat.size(0) - 1;
      b_shifted_dat.set_size(shifted_dat.size(0));
      for (i1 = 0; i1 <= kstr; i1++) {
        b_shifted_dat[i1] =
            shifted_dat[i1 + shifted_dat.size(0)] - thisBackground;
      }
      kstr = b_shifted_dat.size(0);
      for (i1 = 0; i1 < kstr; i1++) {
        shifted_dat[i1 + shifted_dat.size(0)] = b_shifted_dat[i1];
      }
      // shifted_dat(:,3) = shifted_dat(:,3) - backg;
      break;
    }
    //  Calculate chi squared.
    chis[b_i] = chiSquared(shifted_dat, reflect,
                           static_cast<double>(problemDef->params.size(1)));
    //  Store returned values for this contrast in the output arrays.
    //  As well as the calculated profiles, we also store a record of
    //  the other values (background, scalefactors etc) for each contrast
    //  for future use.
    sldProfiles[b_i].f1.set_size(sldProfile.size(0), sldProfile.size(1));
    kstr = sldProfile.size(1);
    for (i1 = 0; i1 < kstr; i1++) {
      loop_ub = sldProfile.size(0);
      for (i2 = 0; i2 < loop_ub; i2++) {
        sldProfiles[b_i].f1[i2 + sldProfiles[b_i].f1.size(0) * i1] =
            sldProfile[i2 + sldProfile.size(0) * i1];
      }
    }
    reflectivity[b_i].f1.set_size(reflect.size(0), 2);
    kstr = Simul.size(0);
    Simulation[b_i].f1.set_size(Simul.size(0), 2);
    loop_ub = reflect.size(0);
    for (i1 = 0; i1 < 2; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        reflectivity[b_i].f1[i2 + reflectivity[b_i].f1.size(0) * i1] =
            reflect[i2 + reflect.size(0) * i1];
      }
      for (i2 = 0; i2 < kstr; i2++) {
        Simulation[b_i].f1[i2 + Simulation[b_i].f1.size(0) * i1] =
            Simul[i2 + Simul.size(0) * i1];
      }
    }
    shifted_data[b_i].f1.set_size(shifted_dat.size(0), shifted_dat.size(1));
    kstr = shifted_dat.size(1);
    for (i1 = 0; i1 < kstr; i1++) {
      loop_ub = shifted_dat.size(0);
      for (i2 = 0; i2 < loop_ub; i2++) {
        shifted_data[b_i].f1[i2 + shifted_data[b_i].f1.size(0) * i1] =
            shifted_dat[i2 + shifted_dat.size(0) * i1];
      }
    }
    layerSlds[b_i].f1.set_size(layerSld.size(0), 3);
    kstr = layerSld.size(0);
    for (i1 = 0; i1 < 3; i1++) {
      for (i2 = 0; i2 < kstr; i2++) {
        layerSlds[b_i].f1[i2 + layerSlds[b_i].f1.size(0) * i1] =
            layerSld[i2 + layerSld.size(0) * i1];
      }
    }
    backgs[b_i] = thisBackground;
    qshifts[b_i] = thisQshift;
    sfs[b_i] = thisSf;
    nbas[b_i] = thisNba;
    nbss[b_i] = thisNbs;
    resols[b_i] = thisResol;
    allRoughs[b_i] = 3.0;
  }
}

// End of code generation (standardTF_custlay_paraPoints.cpp)
