//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: standardTF_custlay_paraContrasts.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Jan-2021 16:52:33
//

// Include Files
#include "standardTF_custlay_paraContrasts.h"
#include "applyBackgroundCorrection.h"
#include "backSort.h"
#include "callReflectivity.h"
#include "call_customLayers.h"
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
// coder.extrinsic('callModules');
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
//                const coder::array<char, 2U> *fname
//                const coder::array<char, 2U> *path
//                const coder::array<double, 2U> *backsType
//                coder::array<double, 1U> *outSsubs
//                coder::array<double, 1U> *backgs
//                coder::array<double, 1U> *qshifts
//                coder::array<double, 1U> *sfs
//                coder::array<double, 1U> *nbas
//                coder::array<double, 1U> *nbss
//                coder::array<double, 1U> *resols
//                coder::array<double, 1U> *chis
//                coder::array<cell_wrap_8, 1U> *reflectivity
//                coder::array<cell_wrap_8, 1U> *Simulation
//                coder::array<cell_wrap_1, 1U> *shifted_data
//                coder::array<cell_wrap_1, 1U> *layerSlds
//                coder::array<cell_wrap_6, 1U> *sldProfiles
//                coder::array<cell_wrap_15, 1U> *allLayers
//                coder::array<double, 1U> *allRoughs
// Return Type  : void
//
void c_standardTF_custlay_paraContra(const coder::array<double, 2U> &resample,
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
  char, 2U> &fname, const coder::array<char, 2U> &path, const coder::array<
  double, 2U> &backsType, coder::array<double, 1U> &outSsubs, coder::array<
  double, 1U> &backgs, coder::array<double, 1U> &qshifts, coder::array<double,
  1U> &sfs, coder::array<double, 1U> &nbas, coder::array<double, 1U> &nbss,
  coder::array<double, 1U> &resols, coder::array<double, 1U> &chis, coder::array<
  cell_wrap_8, 1U> &reflectivity, coder::array<cell_wrap_8, 1U> &Simulation,
  coder::array<cell_wrap_1, 1U> &shifted_data, coder::array<cell_wrap_1, 1U>
  &layerSlds, coder::array<cell_wrap_6, 1U> &sldProfiles, coder::array<
  cell_wrap_15, 1U> &allLayers, coder::array<double, 1U> &allRoughs)
{
  int ub_loop;
  coder::array<double, 2U> layerSld;
  coder::array<double, 2U> reflect;
  coder::array<double, 2U> sldProfile;
  coder::array<double, 2U> shifted_dat;
  double d;
  double d1;
  double d2;
  double d3;
  double d4;
  double d5;
  int loop_ub;
  int b_i;

  // Pre-Allocation...
  ub_loop = static_cast<int>(numberOfContrasts);
  backgs.set_size(ub_loop);
  qshifts.set_size(ub_loop);
  sfs.set_size(ub_loop);
  nbas.set_size(ub_loop);
  nbss.set_size(ub_loop);
  resols.set_size(ub_loop);
  allRoughs.set_size(ub_loop);
  allLayers.set_size(ub_loop);
  outSsubs.set_size(ub_loop);
  sldProfiles.set_size(ub_loop);
  layerSlds.set_size(ub_loop);
  shifted_data.set_size(ub_loop);
  chis.set_size(ub_loop);
  Simulation.set_size(ub_loop);
  reflectivity.set_size(ub_loop);
  ub_loop--;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(layerSld,reflect,sldProfile,shifted_dat,d,d1,d2,d3,d4,d5,loop_ub,b_i)

  for (int i = 0; i <= ub_loop; i++) {
    backSort(cBacks[i], cShifts[i], cScales[i], cNbas[i], cNbss[i], cRes[i],
             backs, shifts, sf, nba, nbs, res, &d5, &d4, &d3, &d2, &d1, &d);
    backgs[i] = d5;
    qshifts[i] = d4;
    sfs[i] = d3;
    nbas[i] = d2;
    nbss[i] = d1;
    resols[i] = d;
    call_customLayers(params, static_cast<double>(i) + 1.0, fname, path, d2, d1,
                      shifted_dat, &d);
    allRoughs[i] = d;
    allLayers[i].f1.set_size(shifted_dat.size(0), 3);
    loop_ub = shifted_dat.size(0) * shifted_dat.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      allLayers[i].f1[b_i] = shifted_dat[b_i];
    }

    b_groupLayers_Mod(shifted_dat, allRoughs[i], geometry, layerSld, &d);
    outSsubs[i] = d;
    makeSLDProfiles(nbas[i], nbss[i], layerSld, d, repeatLayers[i].f1,
                    sldProfile);
    sldProfiles[i].f1.set_size(sldProfile.size(0), 2);
    loop_ub = sldProfile.size(0) * sldProfile.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      sldProfiles[i].f1[b_i] = sldProfile[b_i];
    }

    if (resample[i] == 1.0) {
      resampleLayers(sldProfile, layerSld);
      layerSlds[i].f1.set_size(layerSld.size(0), 3);
      loop_ub = layerSld.size(0) * layerSld.size(1);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        layerSlds[i].f1[b_i] = layerSld[b_i];
      }
    } else {
      layerSlds[i].f1.set_size(layerSld.size(0), 3);
      loop_ub = layerSld.size(0) * layerSld.size(1);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        layerSlds[i].f1[b_i] = layerSld[b_i];
      }
    }

    shifted_dat.set_size(allData[allData.size(0) * i].f1.size(0), 3);
    loop_ub = allData[i].f1.size(0) * allData[i].f1.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      shifted_dat[b_i] = allData[i].f1[b_i];
    }

    shiftdata(sfs[i], qshifts[i], dataPresent[i], shifted_dat, dataLimits[i].f1);
    shifted_data[i].f1.set_size(shifted_dat.size(0), 3);
    loop_ub = shifted_dat.size(0) * shifted_dat.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      shifted_data[i].f1[b_i] = shifted_dat[b_i];
    }

    callReflectivity(nbas[i], nbss[i], simLimits[i].f1, repeatLayers[i].f1,
                     shifted_dat, layerSld, outSsubs[i], resols[i], reflect,
                     sldProfile);
    applyBackgroundCorrection(reflect, sldProfile, shifted_dat, backgs[i],
      backsType[i]);
    reflectivity[i].f1.set_size(reflect.size(0), 2);
    loop_ub = reflect.size(0) * reflect.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      reflectivity[i].f1[b_i] = reflect[b_i];
    }

    Simulation[i].f1.set_size(sldProfile.size(0), 2);
    loop_ub = sldProfile.size(0) * sldProfile.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      Simulation[i].f1[b_i] = sldProfile[b_i];
    }

    chis[i] = chiSquared(shifted_dat, reflect, nParams);
  }
}

//
// File trailer for standardTF_custlay_paraContrasts.cpp
//
// [EOF]
//
