//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: standardTF_custXY_single.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Jan-2021 16:52:33
//

// Include Files
#include "standardTF_custXY_single.h"
#include "applyBackgroundCorrection.h"
#include "backSort.h"
#include "callReflectivity.h"
#include "chiSquared.h"
#include "matlabEngineCaller_customLayers.h"
#include "reflectivity_calculation.h"
#include "resampleLayers.h"
#include "rt_nonfinite.h"
#include "shiftdata.h"
#include "standardTF_custXY_reflectivityCalculation.h"
#include "standardTF_reflectivityCalculation.h"

// Function Definitions

//
// coder.extrinsic('callModules');
// Arguments    : double numberOfContrasts
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
void standardTF_custXY_single(double numberOfContrasts, const coder::array<
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
  int loop_ub;
  int i;
  coder::array<double, 2U> shifted_dat;
  double layers;
  coder::array<double, 2U> b_shifted_dat;
  coder::array<double, 2U> layerSld;
  coder::array<double, 2U> Simul;

  // Pre-Allocation...
  loop_ub = static_cast<int>(numberOfContrasts);
  outSsubs.set_size(loop_ub);
  for (i = 0; i < loop_ub; i++) {
    outSsubs[i] = 0.0;
  }

  backgs.set_size(loop_ub);
  qshifts.set_size(loop_ub);
  sfs.set_size(loop_ub);
  nbas.set_size(loop_ub);
  nbss.set_size(loop_ub);
  resols.set_size(loop_ub);
  allRoughs.set_size(loop_ub);
  allLayers.set_size(loop_ub);
  sldProfiles.set_size(loop_ub);
  layerSlds.set_size(loop_ub);
  shifted_data.set_size(loop_ub);
  chis.set_size(loop_ub);
  Simulation.set_size(loop_ub);
  reflectivity.set_size(loop_ub);
  for (int b_i = 0; b_i < loop_ub; b_i++) {
    int b_loop_ub;
    backSort(cBacks[b_i], cShifts[b_i], cScales[b_i], cNbas[b_i], cNbss[b_i],
             cRes[b_i], backs, shifts, sf, nba, nbs, res, &backgs[b_i],
             &qshifts[b_i], &sfs[b_i], &nbas[b_i], &nbss[b_i], &resols[b_i]);
    matlabEngineCaller_customLayers(params, static_cast<double>(b_i) + 1.0,
      fname, path, nbas[b_i], nbss[b_i], shifted_dat, &layers);
    allRoughs[b_i] = params[0];
    allLayers[b_i].f1.set_size(0, 0);

    // [outLayers, outSsubs(i)] = groupLayers_Mod(outLayers,allRoughs(i),geometry,nbas(i),nbss(i)); 
    // sldProfile = makeSLDProfiles(nbas(i),nbss(i),outLayers,outSsubs(i),repeatLayers{i}); 
    b_loop_ub = shifted_dat.size(0);
    sldProfiles[b_i].f1.set_size(shifted_dat.size(0), 2);

    // if resample(i) == 1
    b_shifted_dat.set_size(shifted_dat.size(0), 2);
    for (i = 0; i < b_loop_ub; i++) {
      layers = shifted_dat[i];
      sldProfiles[b_i].f1[i] = layers;
      b_shifted_dat[i] = layers;
    }

    for (i = 0; i < b_loop_ub; i++) {
      layers = shifted_dat[i + shifted_dat.size(0)];
      sldProfiles[b_i].f1[i + sldProfiles[b_i].f1.size(0)] = layers;
      b_shifted_dat[i + b_shifted_dat.size(0)] = layers;
    }

    resampleLayers(b_shifted_dat, layerSld);
    layerSlds[b_i].f1.set_size(layerSld.size(0), 3);
    b_loop_ub = layerSld.size(0) * layerSld.size(1);
    for (i = 0; i < b_loop_ub; i++) {
      layerSlds[b_i].f1[i] = layerSld[i];
    }

    // else
    //    layerSld = outLayers;
    //    layerSlds{i} = layerSld;
    // end
    shifted_dat.set_size(allData[allData.size(0) * b_i].f1.size(0), 3);
    b_loop_ub = allData[b_i].f1.size(0) * allData[b_i].f1.size(1);
    for (i = 0; i < b_loop_ub; i++) {
      shifted_dat[i] = allData[b_i].f1[i];
    }

    shiftdata(sfs[b_i], qshifts[b_i], dataPresent[b_i], shifted_dat,
              dataLimits[b_i].f1);
    shifted_data[b_i].f1.set_size(shifted_dat.size(0), 3);
    b_loop_ub = shifted_dat.size(0) * shifted_dat.size(1);
    for (i = 0; i < b_loop_ub; i++) {
      shifted_data[b_i].f1[i] = shifted_dat[i];
    }

    callReflectivity(nbas[b_i], nbss[b_i], simLimits[b_i].f1, repeatLayers[b_i].
                     f1, shifted_dat, layerSld, 0.0, resols[b_i], b_shifted_dat,
                     Simul);
    applyBackgroundCorrection(b_shifted_dat, Simul, shifted_dat, backgs[b_i],
      backsType[b_i]);
    reflectivity[b_i].f1.set_size(b_shifted_dat.size(0), 2);
    b_loop_ub = b_shifted_dat.size(0) * b_shifted_dat.size(1);
    for (i = 0; i < b_loop_ub; i++) {
      reflectivity[b_i].f1[i] = b_shifted_dat[i];
    }

    Simulation[b_i].f1.set_size(Simul.size(0), 2);
    b_loop_ub = Simul.size(0) * Simul.size(1);
    for (i = 0; i < b_loop_ub; i++) {
      Simulation[b_i].f1[i] = Simul[i];
    }

    chis[b_i] = chiSquared(shifted_dat, b_shifted_dat, nParams);
  }
}

//
// File trailer for standardTF_custXY_single.cpp
//
// [EOF]
//
