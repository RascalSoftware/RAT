//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// standardTF_custXY_single.cpp
//
// Code generation for function 'standardTF_custXY_single'
//

// Include files
#include "standardTF_custXY_single.h"
#include "RAT_parse_cells.h"
#include "applyBackgroundCorrection.h"
#include "backSort.h"
#include "callReflectivity.h"
#include "chiSquared.h"
#include "extractProblemParams.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_internal_types.h"
#include "reflectivity_calculation_types.h"
#include "resampleLayers.h"
#include "rt_nonfinite.h"
#include "shiftdata.h"
#include "coder_array.h"

// Function Definitions
void standardTF_custXY_single(
    const struct0_T *problemDef, const cell_14 *problemDef_cells,
    coder::array<double, 1U> &outSsubs, coder::array<double, 1U> &backgs,
    coder::array<double, 1U> &qshifts, coder::array<double, 1U> &sfs,
    coder::array<double, 1U> &nbas, coder::array<double, 1U> &nbss,
    coder::array<double, 1U> &resols, coder::array<double, 1U> &chis,
    coder::array<cell_wrap_10, 1U> &reflectivity,
    coder::array<cell_wrap_10, 1U> &Simulation,
    coder::array<cell_wrap_1, 1U> &shifted_data,
    coder::array<cell_wrap_8, 1U> &layerSlds,
    coder::array<cell_wrap_1, 1U> &sldProfiles,
    coder::array<cell_wrap_23, 1U> &allLayers,
    coder::array<double, 1U> &allRoughs)
{
  coder::array<cell_wrap_0, 2U> dataLimits;
  coder::array<cell_wrap_0, 2U> repeatLayers;
  coder::array<cell_wrap_0, 2U> simLimits;
  coder::array<cell_wrap_1, 2U> allData;
  coder::array<cell_wrap_2, 2U> contrastLayers;
  coder::array<cell_wrap_2, 1U> layersDetails;
  coder::array<cell_wrap_5, 2U> customFiles;
  coder::array<double, 2U> Simul;
  coder::array<double, 2U> b_allData;
  coder::array<double, 2U> backs;
  coder::array<double, 2U> backsType;
  coder::array<double, 2U> cBacks;
  coder::array<double, 2U> cCustFiles;
  coder::array<double, 2U> cNbas;
  coder::array<double, 2U> cNbss;
  coder::array<double, 2U> cRes;
  coder::array<double, 2U> cScales;
  coder::array<double, 2U> cShifts;
  coder::array<double, 2U> dataPresent;
  coder::array<double, 2U> layerSld;
  coder::array<double, 2U> nba;
  coder::array<double, 2U> nbs;
  coder::array<double, 2U> params;
  coder::array<double, 2U> reflect;
  coder::array<double, 2U> res;
  coder::array<double, 2U> resample;
  coder::array<double, 2U> sf;
  coder::array<double, 2U> shifted_dat;
  coder::array<double, 2U> shifts;
  coder::array<char, 2U> geometry;
  double nParams;
  double numberOfContrasts;
  double numberOfLayers;
  int i;
  int loop_ub_tmp;
  //  Extract individual cell arrays
  RAT_parse_cells(problemDef_cells->f1, problemDef_cells->f2,
                  problemDef_cells->f3, problemDef_cells->f4,
                  problemDef_cells->f5, problemDef_cells->f6,
                  problemDef_cells->f14, repeatLayers, allData, dataLimits,
                  simLimits, contrastLayers, layersDetails, customFiles);
  //  Extract individual parameters from problemDef struct
  extractProblemParams(problemDef, &numberOfContrasts, geometry, cBacks,
                       cShifts, cScales, cNbas, cNbss, cRes, backs, shifts, sf,
                       nba, nbs, res, dataPresent, &nParams, params,
                       &numberOfLayers, resample, backsType, cCustFiles);
  // Pre-Allocation...
  loop_ub_tmp = static_cast<int>(numberOfContrasts);
  backgs.set_size(loop_ub_tmp);
  outSsubs.set_size(loop_ub_tmp);
  for (i = 0; i < loop_ub_tmp; i++) {
    outSsubs[i] = 0.0;
  }
  qshifts.set_size(loop_ub_tmp);
  sfs.set_size(loop_ub_tmp);
  nbas.set_size(loop_ub_tmp);
  nbss.set_size(loop_ub_tmp);
  resols.set_size(loop_ub_tmp);
  allRoughs.set_size(loop_ub_tmp);
  sldProfiles.set_size(loop_ub_tmp);
  layerSlds.set_size(loop_ub_tmp);
  allLayers.set_size(loop_ub_tmp);
  shifted_data.set_size(loop_ub_tmp);
  chis.set_size(loop_ub_tmp);
  Simulation.set_size(loop_ub_tmp);
  reflectivity.set_size(loop_ub_tmp);
  for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
    int loop_ub;
    backSort(cBacks[b_i], cShifts[b_i], cScales[b_i], cNbas[b_i], cNbss[b_i],
             cRes[b_i], backs, shifts, sf, nba, nbs, res, &backgs[b_i],
             &qshifts[b_i], &sfs[b_i], &nbas[b_i], &nbss[b_i], &resols[b_i]);
    allRoughs[b_i] = 3.0;
    sldProfiles[b_i].f1.set_size(3, 3);
    for (i = 0; i < 9; i++) {
      sldProfiles[b_i].f1[i] = dv[i];
    }
    resampleLayers(layerSld);
    layerSlds[b_i].f1.set_size(layerSld.size(0), 3);
    loop_ub = layerSld.size(0) * 3;
    allLayers[b_i].f1.set_size(layerSld.size(0), 3);
    for (i = 0; i < loop_ub; i++) {
      layerSlds[b_i].f1[i] = layerSld[i];
      allLayers[b_i].f1[i] = layerSld[i];
    }
    b_allData.set_size(allData[allData.size(0) * b_i].f1.size(0),
                       allData[allData.size(0) * b_i].f1.size(1));
    loop_ub = allData[b_i].f1.size(0) * allData[b_i].f1.size(1) - 1;
    for (i = 0; i <= loop_ub; i++) {
      b_allData[i] = allData[b_i].f1[i];
    }
    shiftdata(sfs[b_i], qshifts[b_i], dataPresent[b_i], b_allData,
              dataLimits[b_i].f1, simLimits[b_i].f1, shifted_dat);
    shifted_data[b_i].f1.set_size(shifted_dat.size(0), shifted_dat.size(1));
    loop_ub = shifted_dat.size(0) * shifted_dat.size(1);
    for (i = 0; i < loop_ub; i++) {
      shifted_data[b_i].f1[i] = shifted_dat[i];
    }
    callReflectivity(nbas[b_i], nbss[b_i], simLimits[b_i].f1,
                     repeatLayers[b_i].f1, shifted_dat, layerSld, 0.0,
                     resols[b_i], reflect, Simul);
    applyBackgroundCorrection(reflect, Simul, shifted_dat, backgs[b_i],
                              backsType[b_i]);
    reflectivity[b_i].f1.set_size(reflect.size(0), 2);
    loop_ub = reflect.size(0) * 2;
    for (i = 0; i < loop_ub; i++) {
      reflectivity[b_i].f1[i] = reflect[i];
    }
    Simulation[b_i].f1.set_size(Simul.size(0), 2);
    loop_ub = Simul.size(0) * 2;
    for (i = 0; i < loop_ub; i++) {
      Simulation[b_i].f1[i] = Simul[i];
    }
    if (dataPresent[b_i] != 0.0) {
      chis[b_i] = chiSquared(shifted_dat, reflect, nParams);
    } else {
      chis[b_i] = 0.0;
    }
  }
}

// End of code generation (standardTF_custXY_single.cpp)
