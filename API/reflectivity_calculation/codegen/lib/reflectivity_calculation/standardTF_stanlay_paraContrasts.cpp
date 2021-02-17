//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: standardTF_stanlay_paraContrasts.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Jan-2021 16:52:33
//

// Include Files
#include "standardTF_stanlay_paraContrasts.h"
#include "allocateLayersForContrast.h"
#include "allocateParamsToLayers.h"
#include "applyBackgroundCorrection.h"
#include "backSort.h"
#include "callReflectivity.h"
#include "chiSquared.h"
#include "groupLayers_Mod.h"
#include "makeSLDProfiles.h"
#include "reflectivity_calculation.h"
#include "resampleLayers.h"
#include "rt_nonfinite.h"
#include "shiftdata.h"
#include "standardTF_custXY_reflectivityCalculation.h"
#include "standardTF_reflectivityCalculation.h"

// Function Definitions

//
// Pre-Allocation...
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
//                coder::array<cell_wrap_11, 1U> *reflectivity
//                coder::array<cell_wrap_6, 1U> *Simulation
//                coder::array<cell_wrap_1, 1U> *shifted_data
//                coder::array<cell_wrap_1, 1U> *layerSlds
//                coder::array<cell_wrap_11, 1U> *sldProfiles
//                coder::array<cell_wrap_11, 1U> *allLayers
//                coder::array<double, 1U> *allRoughs
// Return Type  : void
//
void c_standardTF_stanlay_paraContra(const coder::array<double, 2U> &resample,
  double numberOfContrasts, const coder::array<char, 2U> &geometry, const coder::
  array<cell_wrap_0, 2U> &repeatLayers, const coder::array<double, 2U> &cBacks,
  const coder::array<double, 2U> &cShifts, const coder::array<double, 2U>
  &cScales, const coder::array<double, 2U> &cNbas, const coder::array<double, 2U>
  &cNbss, const coder::array<double, 2U> &cRes, const coder::array<double, 2U>
  &backs, const coder::array<double, 2U> &shifts, const coder::array<double, 2U>
  &sf, const coder::array<double, 2U> &nba, const coder::array<double, 2U> &nbs,
  const coder::array<double, 2U> &res, const coder::array<double, 2U>
  &dataPresent, const coder::array<cell_wrap_1, 2U> &allData, const coder::array<
  cell_wrap_0, 2U> &dataLimits, const coder::array<cell_wrap_0, 2U> &simLimits,
  double nParams, const coder::array<double, 2U> &params, const coder::array<
  cell_wrap_11, 2U> &contrastLayers, const coder::array<cell_wrap_3, 1U>
  &layersDetails, const coder::array<double, 2U> &backsType, double calcSld,
  coder::array<double, 1U> &outSsubs, coder::array<double, 1U> &backgs, coder::
  array<double, 1U> &qshifts, coder::array<double, 1U> &sfs, coder::array<double,
  1U> &nbas, coder::array<double, 1U> &nbss, coder::array<double, 1U> &resols,
  coder::array<double, 1U> &chis, coder::array<cell_wrap_11, 1U> &reflectivity,
  coder::array<cell_wrap_6, 1U> &Simulation, coder::array<cell_wrap_1, 1U>
  &shifted_data, coder::array<cell_wrap_1, 1U> &layerSlds, coder::array<
  cell_wrap_11, 1U> &sldProfiles, coder::array<cell_wrap_11, 1U> &allLayers,
  coder::array<double, 1U> &allRoughs)
{
  int ub_loop;
  coder::array<cell_wrap_16, 2U> outParameterisedLayers;
  coder::array<double, 2U> thisContrastLayers;
  coder::array<double, 2U> sldProfile;
  coder::array<double, 2U> layerSld;
  coder::array<double, 2U> reflect;
  coder::array<double, 2U> Simul;
  double thisCalcSld;
  double d;
  double d1;
  double d2;
  double d3;
  double d4;
  int loop_ub;
  int c_i;

  //
  ub_loop = static_cast<int>(numberOfContrasts);
  allLayers.set_size(ub_loop);
  for (int i = 0; i < ub_loop; i++) {
    allLayers[i].f1.set_size(2, 1);
    allLayers[i].f1[0] = 1.0;
    allLayers[i].f1[1] = 1.0;
  }

  allocateParamsToLayers(params, layersDetails, outParameterisedLayers);
  backgs.set_size(ub_loop);
  qshifts.set_size(ub_loop);
  sfs.set_size(ub_loop);
  nbas.set_size(ub_loop);
  nbss.set_size(ub_loop);
  resols.set_size(ub_loop);
  allRoughs.set_size(ub_loop);
  outSsubs.set_size(ub_loop);
  sldProfiles.set_size(ub_loop);
  layerSlds.set_size(ub_loop);
  shifted_data.set_size(ub_loop);
  Simulation.set_size(ub_loop);
  reflectivity.set_size(ub_loop);
  chis.set_size(ub_loop);
  ub_loop--;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(thisContrastLayers,sldProfile,layerSld,reflect,Simul,thisCalcSld,d,d1,d2,d3,d4,loop_ub,c_i)

  for (int b_i = 0; b_i <= ub_loop; b_i++) {
    backSort(cBacks[b_i], cShifts[b_i], cScales[b_i], cNbas[b_i], cNbss[b_i],
             cRes[b_i], backs, shifts, sf, nba, nbs, res, &d4, &d3, &thisCalcSld,
             &d2, &d1, &d);
    backgs[b_i] = d4;
    qshifts[b_i] = d3;
    sfs[b_i] = thisCalcSld;
    nbas[b_i] = d2;
    nbss[b_i] = d1;
    resols[b_i] = d;
    thisCalcSld = params[0];
    allRoughs[b_i] = thisCalcSld;
    allocateLayersForContrast(contrastLayers[b_i].f1, outParameterisedLayers,
      thisContrastLayers);
    groupLayers_Mod(thisContrastLayers, thisCalcSld, geometry, d2, d1, layerSld,
                    &d);
    outSsubs[b_i] = d;
    thisCalcSld = calcSld;
    if (resample[b_i] == 1.0) {
      thisCalcSld = 1.0;
    }

    if (thisCalcSld == 1.0) {
      makeSLDProfiles(d2, d1, layerSld, d, repeatLayers[b_i].f1, Simul);
      sldProfile.set_size(Simul.size(0), 2);
      loop_ub = Simul.size(0) * Simul.size(1);
      for (c_i = 0; c_i < loop_ub; c_i++) {
        sldProfile[c_i] = Simul[c_i];
      }
    } else {
      sldProfile.set_size(1, 3);
      sldProfile[0] = 0.0;
      sldProfile[1] = 0.0;
      sldProfile[2] = 0.0;
    }

    sldProfiles[b_i].f1.set_size(sldProfile.size(0), sldProfile.size(1));
    loop_ub = sldProfile.size(0) * sldProfile.size(1);
    for (c_i = 0; c_i < loop_ub; c_i++) {
      sldProfiles[b_i].f1[c_i] = sldProfile[c_i];
    }

    if (resample[b_i] == 1.0) {
      resampleLayers(sldProfile, layerSld);
      layerSlds[b_i].f1.set_size(layerSld.size(0), 3);
      loop_ub = layerSld.size(0) * layerSld.size(1);
      for (c_i = 0; c_i < loop_ub; c_i++) {
        layerSlds[b_i].f1[c_i] = layerSld[c_i];
      }
    } else {
      layerSlds[b_i].f1.set_size(layerSld.size(0), 3);
      loop_ub = layerSld.size(0) * layerSld.size(1);
      for (c_i = 0; c_i < loop_ub; c_i++) {
        layerSlds[b_i].f1[c_i] = layerSld[c_i];
      }
    }

    sldProfile.set_size(allData[allData.size(0) * b_i].f1.size(0), 3);
    loop_ub = allData[b_i].f1.size(0) * allData[b_i].f1.size(1);
    for (c_i = 0; c_i < loop_ub; c_i++) {
      sldProfile[c_i] = allData[b_i].f1[c_i];
    }

    shiftdata(sfs[b_i], qshifts[b_i], dataPresent[b_i], sldProfile,
              dataLimits[b_i].f1);
    callReflectivity(nbas[b_i], nbss[b_i], simLimits[b_i].f1, repeatLayers[b_i].
                     f1, sldProfile, layerSld, outSsubs[b_i], resols[b_i],
                     reflect, Simul);
    applyBackgroundCorrection(reflect, Simul, sldProfile, backgs[b_i],
      backsType[b_i]);
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

    shifted_data[b_i].f1.set_size(sldProfile.size(0), 3);
    loop_ub = sldProfile.size(0) * sldProfile.size(1);
    for (c_i = 0; c_i < loop_ub; c_i++) {
      shifted_data[b_i].f1[c_i] = sldProfile[c_i];
    }

    chis[b_i] = chiSquared(sldProfile, reflect, nParams);
  }
}

//
// File trailer for standardTF_stanlay_paraContrasts.cpp
//
// [EOF]
//
