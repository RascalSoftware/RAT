//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: standardTF_stanlay_paraAll.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 24-Feb-2021 09:21:20
//

// Include Files
#include "standardTF_stanlay_paraAll.h"
#include "allocateLayersForContrast.h"
#include "allocateParamsToLayers.h"
#include "backSort.h"
#include "reflectivity_calculation.h"
#include "rt_nonfinite.h"
#include "standardTF_layers_core.h"

// Function Definitions

//
// Allocate the memory for the output arrays before the main loop
//    --- Begin memory allocation ---
// Arguments    : const coder::array<double, 2U> *resample
//                double numberOfContrasts
//                const coder::array<char, 2U> *geometry
//                const coder::array<cell_wrap_0, 2U> *repeatLayers
//                const coder::array<double, 2U> *cBacks
//                const coder::array<double, 2U> *cShifts
//                const coder::array<double, 2U> *cScales
//                const coder::array<double, 2U> *cNbas
//                const coder::array<double, 2U> *cNbss
//                const coder::array<double, 2U> *cRes
//                const coder::array<double, 2U> *backs
//                const coder::array<double, 2U> *shifts
//                const coder::array<double, 2U> *sf
//                const coder::array<double, 2U> *nba
//                const coder::array<double, 2U> *nbs
//                const coder::array<double, 2U> *res
//                const coder::array<double, 2U> *dataPresent
//                const coder::array<cell_wrap_1, 2U> *allData
//                const coder::array<cell_wrap_0, 2U> *dataLimits
//                const coder::array<cell_wrap_0, 2U> *simLimits
//                double nParams
//                const coder::array<double, 2U> *params
//                const coder::array<cell_wrap_11, 2U> *contrastLayers
//                const coder::array<cell_wrap_3, 1U> *layersDetails
//                const coder::array<double, 2U> *backsType
//                double calcSld
//                coder::array<double, 1U> *outSsubs
//                coder::array<double, 1U> *backgs
//                coder::array<double, 1U> *qshifts
//                coder::array<double, 1U> *sfs
//                coder::array<double, 1U> *nbas
//                coder::array<double, 1U> *nbss
//                coder::array<double, 1U> *resols
//                coder::array<double, 1U> *chis
//                coder::array<cell_wrap_6, 1U> *reflectivity
//                coder::array<cell_wrap_6, 1U> *Simulation
//                coder::array<cell_wrap_1, 1U> *shifted_data
//                coder::array<cell_wrap_1, 1U> *layerSlds
//                coder::array<cell_wrap_11, 1U> *sldProfiles
//                coder::array<cell_wrap_10, 1U> *allLayers
//                coder::array<double, 1U> *allRoughs
// Return Type  : void
//
void standardTF_stanlay_paraAll(const coder::array<double, 2U> &resample, double
  numberOfContrasts, const coder::array<char, 2U> &geometry, const coder::array<
  cell_wrap_0, 2U> &repeatLayers, const coder::array<double, 2U> &cBacks, const
  coder::array<double, 2U> &cShifts, const coder::array<double, 2U> &cScales,
  const coder::array<double, 2U> &cNbas, const coder::array<double, 2U> &cNbss,
  const coder::array<double, 2U> &cRes, const coder::array<double, 2U> &backs,
  const coder::array<double, 2U> &shifts, const coder::array<double, 2U> &sf,
  const coder::array<double, 2U> &nba, const coder::array<double, 2U> &nbs,
  const coder::array<double, 2U> &res, const coder::array<double, 2U>
  &dataPresent, const coder::array<cell_wrap_1, 2U> &allData, const coder::array<
  cell_wrap_0, 2U> &dataLimits, const coder::array<cell_wrap_0, 2U> &simLimits,
  double nParams, const coder::array<double, 2U> &params, const coder::array<
  cell_wrap_11, 2U> &contrastLayers, const coder::array<cell_wrap_3, 1U>
  &layersDetails, const coder::array<double, 2U> &backsType, double calcSld,
  coder::array<double, 1U> &outSsubs, coder::array<double, 1U> &backgs, coder::
  array<double, 1U> &qshifts, coder::array<double, 1U> &sfs, coder::array<double,
  1U> &nbas, coder::array<double, 1U> &nbss, coder::array<double, 1U> &resols,
  coder::array<double, 1U> &chis, coder::array<cell_wrap_6, 1U> &reflectivity,
  coder::array<cell_wrap_6, 1U> &Simulation, coder::array<cell_wrap_1, 1U>
  &shifted_data, coder::array<cell_wrap_1, 1U> &layerSlds, coder::array<
  cell_wrap_11, 1U> &sldProfiles, coder::array<cell_wrap_10, 1U> &allLayers,
  coder::array<double, 1U> &allRoughs)
{
  int ub_loop;
  coder::array<cell_wrap_17, 2U> outParameterisedLayers;
  coder::array<double, 2U> thisContrastLayers;
  coder::array<double, 2U> sldProfile;
  coder::array<double, 2U> reflect;
  coder::array<double, 2U> Simul;
  coder::array<double, 2U> shifted_dat;
  coder::array<double, 2U> thisData;
  double thisSsubs;
  double thisChiSquared;
  double thisResol;
  double thisNbs;
  double thisNba;
  double thisSf;
  double thisQshift;
  double thisBackground;
  int loop_ub;
  int c_i;
  ub_loop = static_cast<int>(numberOfContrasts);
  allLayers.set_size(ub_loop);
  for (int i = 0; i < ub_loop; i++) {
    allLayers[i].f1.set_size(2);
    allLayers[i].f1[0] = 1.0;
    allLayers[i].f1[1] = 1.0;
  }

  //  ---end memory allocation---
  //  First we need to allocate the absolute values of the input
  //  parameters to all the layers in the layers list. This only needs
  //  to be done once, and so is done outside the contrasts loop
  allocateParamsToLayers(params, layersDetails, outParameterisedLayers);
  outSsubs.set_size(ub_loop);
  sldProfiles.set_size(ub_loop);
  reflectivity.set_size(ub_loop);
  Simulation.set_size(ub_loop);
  shifted_data.set_size(ub_loop);
  layerSlds.set_size(ub_loop);
  chis.set_size(ub_loop);
  backgs.set_size(ub_loop);
  qshifts.set_size(ub_loop);
  sfs.set_size(ub_loop);
  nbas.set_size(ub_loop);
  nbss.set_size(ub_loop);
  resols.set_size(ub_loop);
  allRoughs.set_size(ub_loop);
  ub_loop--;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(thisContrastLayers,sldProfile,reflect,Simul,shifted_dat,thisData,thisSsubs,thisChiSquared,thisResol,thisNbs,thisNba,thisSf,thisQshift,thisBackground,loop_ub,c_i)

  for (int b_i = 0; b_i <= ub_loop; b_i++) {
    //  Parallel over all the contrasts
    //  Extract the relevant parameter values for this contrast
    //  from the input arrays.
    //  First need to decide which values of the backrounds, scalefactors
    //  data shifts and bulk contrasts are associated with this contrast
    backSort(cBacks[b_i], cShifts[b_i], cScales[b_i], cNbas[b_i], cNbss[b_i],
             cRes[b_i], backs, shifts, sf, nba, nbs, res, &thisBackground,
             &thisQshift, &thisSf, &thisNba, &thisNbs, &thisResol);

    //  Also need to determine which layers from the overall layers list
    //  are required for this contrast, and put them in the correct order
    //  according to geometry
    allocateLayersForContrast(contrastLayers[b_i].f1, outParameterisedLayers,
      thisContrastLayers);

    //  For the other parameters, we extract the correct ones from the input
    //  arrays
    //  Substrate roughness is always first parameter for standard layers
    //  Now call the core standardTF_stanlay reflectivity calculation
    //  In this case we parallelise over points.
    //  Call the calculation
    b_standardTF_layers_core(thisContrastLayers, params[0], geometry, thisNba,
      thisNbs, resample[b_i], calcSld, thisSf, thisQshift, dataPresent[b_i],
      allData[b_i].f1, dataLimits[b_i].f1, simLimits[b_i].f1, repeatLayers[b_i].
      f1, thisBackground, thisResol, backsType[b_i], nParams, sldProfile,
      reflect, Simul, shifted_dat, thisData, &thisChiSquared, &thisSsubs);

    //  Store returned values for this contrast in the output arrays.
    //  As well as the calculated profiles, we also store a record of
    //  the other values (background, scalefactors etc) for each contrast
    //  for future use.
    outSsubs[b_i] = thisSsubs;
    sldProfiles[b_i].f1.set_size(sldProfile.size(0), sldProfile.size(1));
    loop_ub = sldProfile.size(0) * sldProfile.size(1);
    for (c_i = 0; c_i < loop_ub; c_i++) {
      sldProfiles[b_i].f1[c_i] = sldProfile[c_i];
    }

    reflectivity[b_i].f1.set_size(reflect.size(0), 2);
    loop_ub = reflect.size(0) * reflect.size(1);
    for (c_i = 0; c_i < loop_ub; c_i++) {
      reflectivity[b_i].f1[c_i] = reflect[c_i];
    }

    Simulation[b_i].f1.set_size(Simul.size(0), 2);
    loop_ub = Simul.size(0) * Simul.size(1);
    for (c_i = 0; c_i < loop_ub; c_i++) {
      Simulation[b_i].f1[c_i] = Simul[c_i];
    }

    shifted_data[b_i].f1.set_size(shifted_dat.size(0), 3);
    loop_ub = shifted_dat.size(0) * shifted_dat.size(1);
    for (c_i = 0; c_i < loop_ub; c_i++) {
      shifted_data[b_i].f1[c_i] = shifted_dat[c_i];
    }

    layerSlds[b_i].f1.set_size(thisData.size(0), 3);
    loop_ub = thisData.size(0) * thisData.size(1);
    for (c_i = 0; c_i < loop_ub; c_i++) {
      layerSlds[b_i].f1[c_i] = thisData[c_i];
    }

    chis[b_i] = thisChiSquared;
    backgs[b_i] = thisBackground;
    qshifts[b_i] = thisQshift;
    sfs[b_i] = thisSf;
    nbas[b_i] = thisNba;
    nbss[b_i] = thisNbs;
    resols[b_i] = thisResol;
    allRoughs[b_i] = params[0];
  }
}

//
// File trailer for standardTF_stanlay_paraAll.cpp
//
// [EOF]
//
