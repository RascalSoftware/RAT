//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// standardTF_stanlay_paraPoints.cpp
//
// Code generation for function 'standardTF_stanlay_paraPoints'
//

// Include files
#include "standardTF_stanlay_paraPoints.h"
#include "allocateLayersForContrast.h"
#include "backSort.h"
#include "callReflectivity.h"
#include "chiSquared.h"
#include "groupLayers_Mod.h"
#include "makeSLDProfiles.h"
#include "reflectivity_calculation_internal_types.h"
#include "reflectivity_calculation_types.h"
#include "resampleLayers.h"
#include "rt_nonfinite.h"
#include "shiftdata.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
void standardTF_stanlay_paraPoints(
    const struct0_T *problemDef, const cell_14 *problemDef_cells,
    const struct2_T *controls, coder::array<double, 1U> &outSsubs,
    coder::array<double, 1U> &backgs, coder::array<double, 1U> &qshifts,
    coder::array<double, 1U> &sfs, coder::array<double, 1U> &nbas,
    coder::array<double, 1U> &nbss, coder::array<double, 1U> &resols,
    coder::array<double, 1U> &chis, coder::array<cell_wrap_7, 1U> &reflectivity,
    coder::array<cell_wrap_7, 1U> &Simulation,
    coder::array<cell_wrap_1, 1U> &shifted_data,
    coder::array<cell_wrap_8, 1U> &layerSlds,
    coder::array<cell_wrap_1, 1U> &sldProfiles,
    coder::array<cell_wrap_1, 1U> &allLayers,
    coder::array<double, 1U> &allRoughs)
{
  const coder::array<cell_wrap_2, 1U> *layersDetails;
  coder::array<cell_wrap_15, 2U> outParameterisedLayers;
  coder::array<double, 2U> Simul;
  coder::array<double, 2U> b_problemDef_cells;
  coder::array<double, 2U> r;
  coder::array<double, 2U> reflect;
  coder::array<double, 2U> shifted_dat;
  coder::array<double, 2U> sldProfile;
  coder::array<double, 2U> theseLayers;
  coder::array<double, 1U> b_shifted_dat;
  double thisOutLayer[5];
  double calcSld;
  double ssubs;
  double thisBackground;
  double thisNba;
  double thisNbs;
  double thisQshift;
  double thisResol;
  double thisSf;
  int b_i;
  int i;
  int i1;
  int i2;
  int n;
  //  Standard Layers calculation paralelised over the inner loop
  //  This is the main reflectivity calculation of the standard layers
  //  calculation type. It extracts the required paramters for the contrasts
  //  from the input arrays, then passes the main calculation to
  //  'standardLayersCore', which carries out the calculation iteslf.
  //  The core calculation is common for both standard and custom layers.
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
  //  Extract individual parameters from problemDef
  // Extract individual parameters from problemDef
  calcSld = controls->calcSld;
  //  Allocate the memory for the output arrays before the main loop
  //    --- Begin memory allocation ---
  i = static_cast<int>(problemDef->numberOfContrasts);
  backgs.set_size(static_cast<int>(problemDef->numberOfContrasts));
  allLayers.set_size(static_cast<int>(problemDef->numberOfContrasts));
  for (b_i = 0; b_i < i; b_i++) {
    allLayers[b_i].f1.set_size(2, 1);
    allLayers[b_i].f1[0] = 1.0;
    allLayers[b_i].f1[1] = 1.0;
  }
  //  ---end memory allocation---
  //  First we need to allocate the absolute values of the input
  //  parameters to all the layers in the layers list. This only needs
  //  to be done once, and so is done outside the contrasts loop
  layersDetails = &problemDef_cells->f6;
  //  Allocates parameters from the parameter array to the correct layers
  //
  //  This function takes the list of all layers in 'layersDetails',
  //  then loops over all the layers, putting in the correct
  //  parameter value from the parameters array into each layer in
  //  the 'outLayers' cell array
  for (i1 = 0; i1 < 5; i1++) {
    thisOutLayer[i1] = 0.0;
  }
  outParameterisedLayers.set_size(1, problemDef_cells->f6.size(0));
  i1 = problemDef_cells->f6.size(0);
  for (b_i = 0; b_i < i1; b_i++) {
    i2 = (*layersDetails)[b_i].f1.size(1);
    for (n = 0; n <= i2 - 2; n++) {
      if (!std::isnan((*layersDetails)[b_i].f1[n])) {
        thisOutLayer[n] =
            problemDef
                ->params[static_cast<int>((*layersDetails)[b_i].f1[n]) - 1];
      } else {
        thisOutLayer[n] = rtNaN;
      }
    }
    thisOutLayer[(*layersDetails)[b_i].f1.size(1) - 1] =
        (*layersDetails)[b_i].f1[(*layersDetails)[b_i].f1.size(1) - 1];
    for (i2 = 0; i2 < 5; i2++) {
      outParameterisedLayers[b_i].f1[i2] = thisOutLayer[i2];
    }
  }
  //  Single Loop over all the contrasts
  outSsubs.set_size(static_cast<int>(problemDef->numberOfContrasts));
  sldProfiles.set_size(static_cast<int>(problemDef->numberOfContrasts));
  reflectivity.set_size(static_cast<int>(problemDef->numberOfContrasts));
  Simulation.set_size(static_cast<int>(problemDef->numberOfContrasts));
  shifted_data.set_size(static_cast<int>(problemDef->numberOfContrasts));
  layerSlds.set_size(static_cast<int>(problemDef->numberOfContrasts));
  chis.set_size(static_cast<int>(problemDef->numberOfContrasts));
  qshifts.set_size(static_cast<int>(problemDef->numberOfContrasts));
  sfs.set_size(static_cast<int>(problemDef->numberOfContrasts));
  nbas.set_size(static_cast<int>(problemDef->numberOfContrasts));
  nbss.set_size(static_cast<int>(problemDef->numberOfContrasts));
  resols.set_size(static_cast<int>(problemDef->numberOfContrasts));
  allRoughs.set_size(static_cast<int>(problemDef->numberOfContrasts));
  for (b_i = 0; b_i < i; b_i++) {
    double b_calcSld;
    int loop_ub;
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
    //  Also need to determine which layers from the overall layers list
    //  are required for this contrast, and put them in the correct order
    //  according to geometry
    //  For the other parameters, we extract the correct ones from the input
    //  arrays
    //  Substrate roughness is always first parameter for standard layers
    //  Now call the core standardTF_stanlay reflectivity calculation
    //  In this case we parallelise over points.
    //  Call the calculation
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
    allocateLayersForContrast(problemDef_cells->f5[b_i].f1,
                              outParameterisedLayers, r);
    groupLayers_Mod(r, problemDef->params[0], problemDef->geometry, thisNba,
                    thisNbs, theseLayers, &ssubs);
    outSsubs[b_i] = ssubs;
    //  Make the SLD profiles.
    //  If resampling is needed, then enforce the calcSLD flag, so as to catch
    //  the error af trying to resample a non-existent profile.
    if ((problemDef->resample[b_i] == 1.0) && (calcSld == 0.0)) {
      b_calcSld = 1.0;
    }
    //  If cal SLD flag is set, then calculate the SLD profile
    if (b_calcSld == 1.0) {
      makeSLDProfiles(thisNba, thisNbs, theseLayers, ssubs,
                      problemDef_cells->f1[b_i].f1, reflect);
      sldProfile.set_size(reflect.size(0), 2);
      n = reflect.size(0);
      for (i1 = 0; i1 < 2; i1++) {
        for (i2 = 0; i2 < n; i2++) {
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
      resampleLayers(sldProfile, theseLayers);
    }
    //  Apply scale factors and q shifts to the data
    b_problemDef_cells.set_size(
        problemDef_cells->f2[problemDef_cells->f2.size(0) * b_i].f1.size(0),
        problemDef_cells->f2[problemDef_cells->f2.size(0) * b_i].f1.size(1));
    n = problemDef_cells->f2[b_i].f1.size(1) - 1;
    for (i1 = 0; i1 <= n; i1++) {
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
                       problemDef_cells->f1[b_i].f1, shifted_dat, theseLayers,
                       ssubs, thisResol, reflect, Simul);
    //  Apply background correction, either to the simulation or the data
    switch (static_cast<int>(problemDef->contrastBacksType[b_i])) {
    case 1:
      // Add background to the simulation
      reflect.set_size(reflect.size(0), 2);
      Simul.set_size(Simul.size(0), 2);
      for (i1 = 0; i1 < 2; i1++) {
        n = reflect.size(0);
        for (i2 = 0; i2 < n; i2++) {
          reflect[i2 + reflect.size(0) * i1] =
              reflect[i2 + reflect.size(0) * i1] + thisBackground;
        }
        n = Simul.size(0);
        for (i2 = 0; i2 < n; i2++) {
          Simul[i2 + Simul.size(0) * i1] =
              Simul[i2 + Simul.size(0) * i1] + thisBackground;
        }
      }
      break;
    case 2:
      //          %Subtract the background from the data..
      n = shifted_dat.size(0) - 1;
      b_shifted_dat.set_size(shifted_dat.size(0));
      for (i1 = 0; i1 <= n; i1++) {
        b_shifted_dat[i1] =
            shifted_dat[i1 + shifted_dat.size(0)] - thisBackground;
      }
      n = b_shifted_dat.size(0);
      for (i1 = 0; i1 < n; i1++) {
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
    n = sldProfile.size(1);
    for (i1 = 0; i1 < n; i1++) {
      loop_ub = sldProfile.size(0);
      for (i2 = 0; i2 < loop_ub; i2++) {
        sldProfiles[b_i].f1[i2 + sldProfiles[b_i].f1.size(0) * i1] =
            sldProfile[i2 + sldProfile.size(0) * i1];
      }
    }
    reflectivity[b_i].f1.set_size(reflect.size(0), 2);
    n = Simul.size(0);
    Simulation[b_i].f1.set_size(Simul.size(0), 2);
    loop_ub = reflect.size(0);
    for (i1 = 0; i1 < 2; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        reflectivity[b_i].f1[i2 + reflectivity[b_i].f1.size(0) * i1] =
            reflect[i2 + reflect.size(0) * i1];
      }
      for (i2 = 0; i2 < n; i2++) {
        Simulation[b_i].f1[i2 + Simulation[b_i].f1.size(0) * i1] =
            Simul[i2 + Simul.size(0) * i1];
      }
    }
    shifted_data[b_i].f1.set_size(shifted_dat.size(0), shifted_dat.size(1));
    n = shifted_dat.size(1);
    for (i1 = 0; i1 < n; i1++) {
      loop_ub = shifted_dat.size(0);
      for (i2 = 0; i2 < loop_ub; i2++) {
        shifted_data[b_i].f1[i2 + shifted_data[b_i].f1.size(0) * i1] =
            shifted_dat[i2 + shifted_dat.size(0) * i1];
      }
    }
    layerSlds[b_i].f1.set_size(theseLayers.size(0), 3);
    n = theseLayers.size(0);
    for (i1 = 0; i1 < 3; i1++) {
      for (i2 = 0; i2 < n; i2++) {
        layerSlds[b_i].f1[i2 + layerSlds[b_i].f1.size(0) * i1] =
            theseLayers[i2 + theseLayers.size(0) * i1];
      }
    }
    backgs[b_i] = thisBackground;
    qshifts[b_i] = thisQshift;
    sfs[b_i] = thisSf;
    nbas[b_i] = thisNba;
    nbss[b_i] = thisNbs;
    resols[b_i] = thisResol;
    allRoughs[b_i] = problemDef->params[0];
  }
}

// End of code generation (standardTF_stanlay_paraPoints.cpp)
