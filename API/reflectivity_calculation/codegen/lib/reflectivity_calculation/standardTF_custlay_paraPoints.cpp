//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: standardTF_custlay_paraPoints.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Jan-2021 16:52:33
//

// Include Files
#include "standardTF_custlay_paraPoints.h"
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
void standardTF_custlay_paraPoints(const coder::array<double, 2U> &resample,
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
  int i;
  coder::array<double, 2U> shifted_dat;
  coder::array<double, 2U> layerSld;
  coder::array<double, 2U> sldProfile;
  coder::array<double, 2U> Simul;

  // Pre-Allocation...
  i = static_cast<int>(numberOfContrasts);
  backgs.set_size(i);
  qshifts.set_size(i);
  sfs.set_size(i);
  nbas.set_size(i);
  nbss.set_size(i);
  resols.set_size(i);
  allRoughs.set_size(i);
  allLayers.set_size(i);
  outSsubs.set_size(i);
  sldProfiles.set_size(i);
  layerSlds.set_size(i);
  shifted_data.set_size(i);
  chis.set_size(i);
  Simulation.set_size(i);
  reflectivity.set_size(i);
  for (int b_i = 0; b_i < i; b_i++) {
    int loop_ub;
    int i1;
    backSort(cBacks[b_i], cShifts[b_i], cScales[b_i], cNbas[b_i], cNbss[b_i],
             cRes[b_i], backs, shifts, sf, nba, nbs, res, &backgs[b_i],
             &qshifts[b_i], &sfs[b_i], &nbas[b_i], &nbss[b_i], &resols[b_i]);
    call_customLayers(params, static_cast<double>(b_i) + 1.0, fname, path,
                      nbas[b_i], nbss[b_i], shifted_dat, &allRoughs[b_i]);
    allLayers[b_i].f1.set_size(shifted_dat.size(0), 3);
    loop_ub = shifted_dat.size(0) * shifted_dat.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      allLayers[b_i].f1[i1] = shifted_dat[i1];
    }

    b_groupLayers_Mod(shifted_dat, allRoughs[b_i], geometry, layerSld,
                      &outSsubs[b_i]);
    makeSLDProfiles(nbas[b_i], nbss[b_i], layerSld, outSsubs[b_i],
                    repeatLayers[b_i].f1, sldProfile);
    sldProfiles[b_i].f1.set_size(sldProfile.size(0), 2);
    loop_ub = sldProfile.size(0) * sldProfile.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      sldProfiles[b_i].f1[i1] = sldProfile[i1];
    }

    if (resample[b_i] == 1.0) {
      resampleLayers(sldProfile, layerSld);
      layerSlds[b_i].f1.set_size(layerSld.size(0), 3);
      loop_ub = layerSld.size(0) * layerSld.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        layerSlds[b_i].f1[i1] = layerSld[i1];
      }
    } else {
      layerSlds[b_i].f1.set_size(layerSld.size(0), 3);
      loop_ub = layerSld.size(0) * layerSld.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        layerSlds[b_i].f1[i1] = layerSld[i1];
      }
    }

    shifted_dat.set_size(allData[allData.size(0) * b_i].f1.size(0), 3);
    loop_ub = allData[b_i].f1.size(0) * allData[b_i].f1.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      shifted_dat[i1] = allData[b_i].f1[i1];
    }

    shiftdata(sfs[b_i], qshifts[b_i], dataPresent[b_i], shifted_dat,
              dataLimits[b_i].f1);
    shifted_data[b_i].f1.set_size(shifted_dat.size(0), 3);
    loop_ub = shifted_dat.size(0) * shifted_dat.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      shifted_data[b_i].f1[i1] = shifted_dat[i1];
    }

    b_callReflectivity(nbas[b_i], nbss[b_i], simLimits[b_i].f1, repeatLayers[b_i]
                       .f1, shifted_dat, layerSld, outSsubs[b_i], resols[b_i],
                       sldProfile, Simul);
    applyBackgroundCorrection(sldProfile, Simul, shifted_dat, backgs[b_i],
      backsType[b_i]);
    reflectivity[b_i].f1.set_size(sldProfile.size(0), 2);
    loop_ub = sldProfile.size(0) * sldProfile.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      reflectivity[b_i].f1[i1] = sldProfile[i1];
    }

    Simulation[b_i].f1.set_size(Simul.size(0), 2);
    loop_ub = Simul.size(0) * Simul.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      Simulation[b_i].f1[i1] = Simul[i1];
    }

    chis[b_i] = chiSquared(shifted_dat, sldProfile, nParams);
  }
}

//
// File trailer for standardTF_custlay_paraPoints.cpp
//
// [EOF]
//
