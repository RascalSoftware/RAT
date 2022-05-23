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
#include "backSort.h"
#include "callReflectivity.h"
#include "chiSquared.h"
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
    coder::array<cell_wrap_29, 1U> &allLayers,
    coder::array<double, 1U> &allRoughs)
{
  coder::array<double, 2U> Simul;
  coder::array<double, 2U> b_problemDef_cells;
  coder::array<double, 2U> layerSld;
  coder::array<double, 2U> reflect;
  coder::array<double, 2U> shifted_dat;
  coder::array<double, 1U> b_shifted_dat;
  int i;
  int loop_ub_tmp;
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
  // Pre-Allocation...
  loop_ub_tmp = static_cast<int>(problemDef->numberOfContrasts);
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
    int b_loop_ub;
    int i1;
    int loop_ub;
    backSort(problemDef->contrastBacks[b_i], problemDef->contrastShifts[b_i],
             problemDef->contrastScales[b_i], problemDef->contrastNbas[b_i],
             problemDef->contrastNbss[b_i], problemDef->contrastRes[b_i],
             problemDef->backs, problemDef->shifts, problemDef->sf,
             problemDef->nba, problemDef->nbs, problemDef->res, &backgs[b_i],
             &qshifts[b_i], &sfs[b_i], &nbas[b_i], &nbss[b_i], &resols[b_i]);
    allRoughs[b_i] = 3.0;
    sldProfiles[b_i].f1.set_size(3, 3);
    for (i = 0; i < 3; i++) {
      sldProfiles[b_i].f1[sldProfiles[b_i].f1.size(0) * i] = dv[i][0];
      sldProfiles[b_i].f1[sldProfiles[b_i].f1.size(0) * i + 1] = dv[i][1];
      sldProfiles[b_i].f1[sldProfiles[b_i].f1.size(0) * i + 2] = dv[i][2];
    }
    resampleLayers(layerSld);
    layerSlds[b_i].f1.set_size(layerSld.size(0), 3);
    allLayers[b_i].f1.set_size(layerSld.size(0), 3);
    loop_ub = layerSld.size(0);
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        double d;
        d = layerSld[i1 + layerSld.size(0) * i];
        layerSlds[b_i].f1[i1 + layerSlds[b_i].f1.size(0) * i] = d;
        allLayers[b_i].f1[i1 + allLayers[b_i].f1.size(0) * i] = d;
      }
    }
    b_problemDef_cells.set_size(
        problemDef_cells->f2[problemDef_cells->f2.size(0) * b_i].f1.size(0),
        problemDef_cells->f2[problemDef_cells->f2.size(0) * b_i].f1.size(1));
    loop_ub = problemDef_cells->f2[b_i].f1.size(1) - 1;
    for (i = 0; i <= loop_ub; i++) {
      b_loop_ub = problemDef_cells->f2[b_i].f1.size(0) - 1;
      for (i1 = 0; i1 <= b_loop_ub; i1++) {
        b_problemDef_cells[i1 + b_problemDef_cells.size(0) * i] =
            problemDef_cells->f2[b_i]
                .f1[i1 + problemDef_cells->f2[b_i].f1.size(0) * i];
      }
    }
    shiftdata(sfs[b_i], qshifts[b_i], problemDef->dataPresent[b_i],
              b_problemDef_cells, problemDef_cells->f3[b_i].f1,
              problemDef_cells->f4[b_i].f1, shifted_dat);
    shifted_data[b_i].f1.set_size(shifted_dat.size(0), shifted_dat.size(1));
    loop_ub = shifted_dat.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = shifted_dat.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        shifted_data[b_i].f1[i1 + shifted_data[b_i].f1.size(0) * i] =
            shifted_dat[i1 + shifted_dat.size(0) * i];
      }
    }
    callReflectivity(nbas[b_i], nbss[b_i], problemDef_cells->f4[b_i].f1,
                     problemDef_cells->f1[b_i].f1, shifted_dat, layerSld, 0.0,
                     resols[b_i], reflect, Simul);
    switch (static_cast<int>(problemDef->contrastBacksType[b_i])) {
    case 1:
      // Add background to the simulation
      reflect.set_size(reflect.size(0), 2);
      Simul.set_size(Simul.size(0), 2);
      for (i = 0; i < 2; i++) {
        loop_ub = reflect.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          reflect[i1 + reflect.size(0) * i] =
              reflect[i1 + reflect.size(0) * i] + backgs[b_i];
        }
        loop_ub = Simul.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          Simul[i1 + Simul.size(0) * i] =
              Simul[i1 + Simul.size(0) * i] + backgs[b_i];
        }
      }
      break;
    case 2:
      //          %Subtract the background from the data..
      loop_ub = shifted_dat.size(0) - 1;
      b_shifted_dat.set_size(shifted_dat.size(0));
      for (i = 0; i <= loop_ub; i++) {
        b_shifted_dat[i] = shifted_dat[i + shifted_dat.size(0)] - backgs[b_i];
      }
      loop_ub = b_shifted_dat.size(0);
      for (i = 0; i < loop_ub; i++) {
        shifted_dat[i + shifted_dat.size(0)] = b_shifted_dat[i];
      }
      // shifted_dat(:,3) = shifted_dat(:,3) - backg;
      break;
    }
    loop_ub = reflect.size(0);
    reflectivity[b_i].f1.set_size(reflect.size(0), 2);
    b_loop_ub = Simul.size(0);
    Simulation[b_i].f1.set_size(Simul.size(0), 2);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        reflectivity[b_i].f1[i1 + reflectivity[b_i].f1.size(0) * i] =
            reflect[i1 + reflect.size(0) * i];
      }
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        Simulation[b_i].f1[i1 + Simulation[b_i].f1.size(0) * i] =
            Simul[i1 + Simul.size(0) * i];
      }
    }
    if (problemDef->dataPresent[b_i] != 0.0) {
      chis[b_i] = chiSquared(shifted_dat, reflect,
                             static_cast<double>(problemDef->params.size(1)));
    } else {
      chis[b_i] = 0.0;
    }
  }
}

// End of code generation (standardTF_custXY_single.cpp)
