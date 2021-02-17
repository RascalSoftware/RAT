//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: standardTF_custXY_reflectivityCalculation.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Jan-2021 16:52:33
//

// Include Files
#include "standardTF_custXY_reflectivityCalculation.h"
#include "applyBackgroundCorrection.h"
#include "backSort.h"
#include "callReflectivity.h"
#include "chiSquared.h"
#include "matlabEngineCaller_customLayers.h"
#include "reflectivity_calculation.h"
#include "resampleLayers.h"
#include "rt_nonfinite.h"
#include "shiftdata.h"
#include "standardTF_custXY_single.h"
#include "standardTF_reflectivityCalculation.h"

// Function Definitions

//
// Arguments    : const struct0_T *problemDef
//                const cell_13 *problemDef_cells
//                const struct2_T *controls
//                struct4_T *problem
//                coder::array<cell_wrap_14, 1U> *reflectivity
//                coder::array<cell_wrap_8, 1U> *Simulation
//                coder::array<cell_wrap_9, 1U> *shifted_data
//                coder::array<cell_wrap_9, 1U> *layerSlds
//                coder::array<cell_wrap_8, 1U> *sldProfiles
//                coder::array<cell_wrap_15, 1U> *allLayers
// Return Type  : void
//
void c_standardTF_custXY_reflectivit(const struct0_T *problemDef, const cell_13 *
  problemDef_cells, const struct2_T *controls, struct4_T *problem, coder::array<
  cell_wrap_14, 1U> &reflectivity, coder::array<cell_wrap_8, 1U> &Simulation,
  coder::array<cell_wrap_9, 1U> &shifted_data, coder::array<cell_wrap_9, 1U>
  &layerSlds, coder::array<cell_wrap_8, 1U> &sldProfiles, coder::array<
  cell_wrap_15, 1U> &allLayers)
{
  int loop_ub;
  coder::array<double, 1U> chis;
  int i;
  boolean_T b_bool;
  int vlen;
  int exitg1;
  static const char b_cv[6] = { 's', 'i', 'n', 'g', 'l', 'e' };

  coder::array<cell_wrap_8, 1U> r;
  coder::array<cell_wrap_8, 1U> r1;
  coder::array<cell_wrap_1, 1U> b_shifted_data;
  coder::array<cell_wrap_1, 1U> b_layerSlds;
  coder::array<cell_wrap_6, 1U> b_sldProfiles;
  coder::array<cell_wrap_15, 1U> r2;
  coder::array<cell_wrap_6, 1U> b_reflectivity;
  int b_i;
  static const char b_cv1[6] = { 'p', 'o', 'i', 'n', 't', 's' };

  coder::array<cell_wrap_6, 1U> b_Simulation;
  coder::array<double, 1U> backgs;
  coder::array<double, 1U> qshifts;
  double layers;
  coder::array<double, 1U> sfs;
  coder::array<double, 1U> nbas;
  coder::array<cell_wrap_11, 1U> b_allLayers;
  coder::array<double, 1U> nbss;
  coder::array<double, 1U> resols;
  coder::array<double, 1U> allRoughs;
  coder::array<double, 2U> shifted_dat;
  coder::array<double, 2U> b_shifted_dat;
  coder::array<double, 2U> layerSld;
  coder::array<double, 2U> Simul;

  // Extract individual parameters from problemDef
  // nbairs = problemDef.nbairs;
  // nbsubs = problemDef.nbsubs;
  // repeats = problemDef.repeatLayers;
  // allData = problemDef.allData;
  // dataLimits = problemDef.dataLimits;
  // simLimits = problemDef.simLimits;
  // repeatLayers = problemDef.repeatLayers;
  // contrastLayers = problemDef.contrastLayers;
  // layersDetails = problemDef.layersDetails;
  // Pre-allocation
  problem->ssubs.set_size(1);
  problem->ssubs[0] = problemDef->params[0];
  loop_ub = static_cast<int>(problemDef->numberOfContrasts);
  problem->backgrounds.set_size(loop_ub);
  problem->qshifts.set_size(loop_ub);
  problem->scalefactors.set_size(loop_ub);
  problem->nbairs.set_size(loop_ub);
  problem->nbsubs.set_size(loop_ub);
  chis.set_size(loop_ub);
  problem->resolutions.set_size(loop_ub);
  problem->allSubRough.set_size(loop_ub);
  reflectivity.set_size(loop_ub);
  Simulation.set_size(loop_ub);
  shifted_data.set_size(loop_ub);
  layerSlds.set_size(loop_ub);
  sldProfiles.set_size(loop_ub);
  allLayers.set_size(loop_ub);
  for (i = 0; i < loop_ub; i++) {
    problem->backgrounds[i] = 0.0;
    problem->qshifts[i] = 0.0;
    problem->scalefactors[i] = 0.0;
    problem->nbairs[i] = 0.0;
    problem->nbsubs[i] = 0.0;
    chis[i] = 0.0;
    problem->resolutions[i] = 0.0;
    problem->allSubRough[i] = 0.0;
    reflectivity[i].f1.set_size(2, 2);
    reflectivity[i].f1[0] = 1.0;
    reflectivity[i].f1[1] = 1.0;
    reflectivity[i].f1[2] = 1.0;
    reflectivity[i].f1[3] = 1.0;
    Simulation[i].f1.set_size(2, 2);
    Simulation[i].f1[0] = 1.0;
    Simulation[i].f1[1] = 1.0;
    Simulation[i].f1[2] = 1.0;
    Simulation[i].f1[3] = 1.0;
    shifted_data[i].f1.set_size(2, 3);
    layerSlds[i].f1.set_size(2, 3);
    for (b_i = 0; b_i < 6; b_i++) {
      shifted_data[i].f1[b_i] = 1.0;
      layerSlds[i].f1[b_i] = 1.0;
    }

    sldProfiles[i].f1.set_size(2, 2);
    sldProfiles[i].f1[0] = 1.0;
    sldProfiles[i].f1[1] = 1.0;
    sldProfiles[i].f1[2] = 1.0;
    sldProfiles[i].f1[3] = 1.0;
    allLayers[i].f1.set_size(2, 1);
    allLayers[i].f1[0] = 1.0;
    allLayers[i].f1[1] = 1.0;
  }

  b_bool = false;
  if (controls->para.size(1) == 6) {
    vlen = 0;
    do {
      exitg1 = 0;
      if (vlen < 6) {
        if (controls->para[vlen] != b_cv[vlen]) {
          exitg1 = 1;
        } else {
          vlen++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  if (b_bool) {
    vlen = 0;
  } else {
    b_bool = false;
    if (controls->para.size(1) == 6) {
      vlen = 0;
      do {
        exitg1 = 0;
        if (vlen < 6) {
          if (controls->para[vlen] != b_cv1[vlen]) {
            exitg1 = 1;
          } else {
            vlen++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }

    if (b_bool) {
      vlen = 1;
    } else {
      vlen = -1;
    }
  }

  switch (vlen) {
   case 0:
    standardTF_custXY_single(problemDef->numberOfContrasts, problemDef_cells->f1,
      problemDef->contrastBacks, problemDef->contrastShifts,
      problemDef->contrastScales, problemDef->contrastNbas,
      problemDef->contrastNbss, problemDef->contrastRes, problemDef->backs,
      problemDef->shifts, problemDef->sf, problemDef->nba, problemDef->nbs,
      problemDef->res, problemDef->dataPresent, problemDef_cells->f2,
      problemDef_cells->f3, problemDef_cells->f4, static_cast<double>
      (problemDef->params.size(1)), problemDef->params,
      problemDef->modelFilename, problemDef->path, problemDef->contrastBacksType,
      problem->ssubs, problem->backgrounds, problem->qshifts,
      problem->scalefactors, problem->nbairs, problem->nbsubs,
      problem->resolutions, chis, r, r1, b_shifted_data, b_layerSlds,
      b_sldProfiles, r2, problem->allSubRough);
    b_reflectivity.set_size(r.size(0));
    b_i = r.size(0);
    for (vlen = 0; vlen < b_i; vlen++) {
      b_reflectivity[vlen].f1.set_size(r[vlen].f1.size(0), 2);
      loop_ub = r[vlen].f1.size(0) * r[vlen].f1.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_reflectivity[vlen].f1[i] = r[vlen].f1[i];
      }
    }

    b_Simulation.set_size(r1.size(0));
    b_i = r1.size(0);
    for (vlen = 0; vlen < b_i; vlen++) {
      b_Simulation[vlen].f1.set_size(r1[vlen].f1.size(0), 2);
      loop_ub = r1[vlen].f1.size(0) * r1[vlen].f1.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_Simulation[vlen].f1[i] = r1[vlen].f1[i];
      }
    }

    b_allLayers.set_size(r2.size(0));
    b_i = r2.size(0);
    for (vlen = 0; vlen < b_i; vlen++) {
      b_allLayers[vlen].f1.set_size(r2[vlen].f1.size(0), r2[vlen].f1.size(1));
      loop_ub = r2[vlen].f1.size(0) * r2[vlen].f1.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_allLayers[vlen].f1[i] = r2[vlen].f1[i];
      }
    }

    reflectivity.set_size(b_reflectivity.size(0));
    b_i = b_reflectivity.size(0);
    for (vlen = 0; vlen < b_i; vlen++) {
      reflectivity[vlen].f1.set_size(b_reflectivity[vlen].f1.size(0), 2);
      loop_ub = b_reflectivity[vlen].f1.size(0) * b_reflectivity[vlen].f1.size(1);
      for (i = 0; i < loop_ub; i++) {
        reflectivity[vlen].f1[i] = b_reflectivity[vlen].f1[i];
      }
    }

    Simulation.set_size(b_Simulation.size(0));
    b_i = b_Simulation.size(0);
    for (vlen = 0; vlen < b_i; vlen++) {
      Simulation[vlen].f1.set_size(b_Simulation[vlen].f1.size(0), 2);
      loop_ub = b_Simulation[vlen].f1.size(0) * b_Simulation[vlen].f1.size(1);
      for (i = 0; i < loop_ub; i++) {
        Simulation[vlen].f1[i] = b_Simulation[vlen].f1[i];
      }
    }

    shifted_data.set_size(b_shifted_data.size(0));
    b_i = b_shifted_data.size(0);
    for (vlen = 0; vlen < b_i; vlen++) {
      shifted_data[vlen].f1.set_size(b_shifted_data[vlen].f1.size(0), 3);
      loop_ub = b_shifted_data[vlen].f1.size(0) * b_shifted_data[vlen].f1.size(1);
      for (i = 0; i < loop_ub; i++) {
        shifted_data[vlen].f1[i] = b_shifted_data[vlen].f1[i];
      }
    }

    layerSlds.set_size(b_layerSlds.size(0));
    b_i = b_layerSlds.size(0);
    for (vlen = 0; vlen < b_i; vlen++) {
      layerSlds[vlen].f1.set_size(b_layerSlds[vlen].f1.size(0), 3);
      loop_ub = b_layerSlds[vlen].f1.size(0) * b_layerSlds[vlen].f1.size(1);
      for (i = 0; i < loop_ub; i++) {
        layerSlds[vlen].f1[i] = b_layerSlds[vlen].f1[i];
      }
    }

    sldProfiles.set_size(b_sldProfiles.size(0));
    b_i = b_sldProfiles.size(0);
    for (vlen = 0; vlen < b_i; vlen++) {
      sldProfiles[vlen].f1.set_size(b_sldProfiles[vlen].f1.size(0), 2);
      loop_ub = b_sldProfiles[vlen].f1.size(0) * b_sldProfiles[vlen].f1.size(1);
      for (i = 0; i < loop_ub; i++) {
        sldProfiles[vlen].f1[i] = b_sldProfiles[vlen].f1[i];
      }
    }

    allLayers.set_size(b_allLayers.size(0));
    b_i = b_allLayers.size(0);
    for (vlen = 0; vlen < b_i; vlen++) {
      allLayers[vlen].f1.set_size(b_allLayers[vlen].f1.size(0), b_allLayers[vlen]
        .f1.size(1));
      loop_ub = b_allLayers[vlen].f1.size(0) * b_allLayers[vlen].f1.size(1);
      for (i = 0; i < loop_ub; i++) {
        allLayers[vlen].f1[i] = b_allLayers[vlen].f1[i];
      }
    }
    break;

   case 1:
    // coder.extrinsic('callModules');
    // Pre-Allocation...
    problem->ssubs.set_size(loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      problem->ssubs[b_i] = 0.0;
    }

    backgs.set_size(loop_ub);
    qshifts.set_size(loop_ub);
    sfs.set_size(loop_ub);
    nbas.set_size(loop_ub);
    nbss.set_size(loop_ub);
    resols.set_size(loop_ub);
    allRoughs.set_size(loop_ub);
    r2.set_size(loop_ub);
    b_sldProfiles.set_size(loop_ub);
    b_layerSlds.set_size(loop_ub);
    b_shifted_data.set_size(loop_ub);
    chis.set_size(loop_ub);
    r1.set_size(loop_ub);
    r.set_size(loop_ub);
    for (i = 0; i < loop_ub; i++) {
      backSort(problemDef->contrastBacks[i], problemDef->contrastShifts[i],
               problemDef->contrastScales[i], problemDef->contrastNbas[i],
               problemDef->contrastNbss[i], problemDef->contrastRes[i],
               problemDef->backs, problemDef->shifts, problemDef->sf,
               problemDef->nba, problemDef->nbs, problemDef->res, &backgs[i],
               &qshifts[i], &sfs[i], &nbas[i], &nbss[i], &resols[i]);
      matlabEngineCaller_customLayers(problemDef->params, static_cast<double>(i)
        + 1.0, problemDef->modelFilename, problemDef->path, nbas[i], nbss[i],
        shifted_dat, &layers);
      allRoughs[i] = problemDef->params[0];
      r2[i].f1.set_size(0, 0);

      // [outLayers, outSsubs(i)] = groupLayers_Mod(outLayers,allRoughs(i),geometry,nbas(i),nbss(i)); 
      // sldProfile = makeSLDProfiles(nbas(i),nbss(i),outLayers,outSsubs(i),repeatLayers{i}); 
      vlen = shifted_dat.size(0);
      b_sldProfiles[i].f1.set_size(shifted_dat.size(0), 2);

      // if resample(i) == 1
      b_shifted_dat.set_size(shifted_dat.size(0), 2);
      for (b_i = 0; b_i < vlen; b_i++) {
        layers = shifted_dat[b_i];
        b_sldProfiles[i].f1[b_i] = layers;
        b_shifted_dat[b_i] = layers;
      }

      for (b_i = 0; b_i < vlen; b_i++) {
        layers = shifted_dat[b_i + shifted_dat.size(0)];
        b_sldProfiles[i].f1[b_i + b_sldProfiles[i].f1.size(0)] = layers;
        b_shifted_dat[b_i + b_shifted_dat.size(0)] = layers;
      }

      resampleLayers(b_shifted_dat, layerSld);
      b_layerSlds[i].f1.set_size(layerSld.size(0), 3);
      vlen = layerSld.size(0) * layerSld.size(1);
      for (b_i = 0; b_i < vlen; b_i++) {
        b_layerSlds[i].f1[b_i] = layerSld[b_i];
      }

      // else
      //    layerSld = outLayers;
      //    layerSlds{i} = layerSld;
      // end
      shifted_dat.set_size(problemDef_cells->f2[problemDef_cells->f2.size(0) * i]
                           .f1.size(0), 3);
      vlen = problemDef_cells->f2[i].f1.size(0) * problemDef_cells->f2[i].
        f1.size(1);
      for (b_i = 0; b_i < vlen; b_i++) {
        shifted_dat[b_i] = problemDef_cells->f2[i].f1[b_i];
      }

      shiftdata(sfs[i], qshifts[i], problemDef->dataPresent[i], shifted_dat,
                problemDef_cells->f3[i].f1);
      b_shifted_data[i].f1.set_size(shifted_dat.size(0), 3);
      vlen = shifted_dat.size(0) * shifted_dat.size(1);
      for (b_i = 0; b_i < vlen; b_i++) {
        b_shifted_data[i].f1[b_i] = shifted_dat[b_i];
      }

      b_callReflectivity(nbas[i], nbss[i], problemDef_cells->f4[i].f1,
                         problemDef_cells->f1[i].f1, shifted_dat, layerSld, 0.0,
                         resols[i], b_shifted_dat, Simul);
      applyBackgroundCorrection(b_shifted_dat, Simul, shifted_dat, backgs[i],
        problemDef->contrastBacksType[i]);
      r[i].f1.set_size(b_shifted_dat.size(0), 2);
      vlen = b_shifted_dat.size(0) * b_shifted_dat.size(1);
      for (b_i = 0; b_i < vlen; b_i++) {
        r[i].f1[b_i] = b_shifted_dat[b_i];
      }

      r1[i].f1.set_size(Simul.size(0), 2);
      vlen = Simul.size(0) * Simul.size(1);
      for (b_i = 0; b_i < vlen; b_i++) {
        r1[i].f1[b_i] = Simul[b_i];
      }

      chis[i] = chiSquared(shifted_dat, b_shifted_dat, static_cast<double>
                           (problemDef->params.size(1)));
    }

    problem->backgrounds.set_size(backgs.size(0));
    loop_ub = backgs.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      problem->backgrounds[b_i] = backgs[b_i];
    }

    problem->qshifts.set_size(qshifts.size(0));
    loop_ub = qshifts.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      problem->qshifts[b_i] = qshifts[b_i];
    }

    problem->scalefactors.set_size(sfs.size(0));
    loop_ub = sfs.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      problem->scalefactors[b_i] = sfs[b_i];
    }

    problem->nbairs.set_size(nbas.size(0));
    loop_ub = nbas.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      problem->nbairs[b_i] = nbas[b_i];
    }

    problem->nbsubs.set_size(nbss.size(0));
    loop_ub = nbss.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      problem->nbsubs[b_i] = nbss[b_i];
    }

    problem->resolutions.set_size(resols.size(0));
    loop_ub = resols.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      problem->resolutions[b_i] = resols[b_i];
    }

    problem->allSubRough.set_size(allRoughs.size(0));
    loop_ub = allRoughs.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      problem->allSubRough[b_i] = allRoughs[b_i];
    }

    b_reflectivity.set_size(r.size(0));
    b_i = r.size(0);
    for (vlen = 0; vlen < b_i; vlen++) {
      b_reflectivity[vlen].f1.set_size(r[vlen].f1.size(0), 2);
      loop_ub = r[vlen].f1.size(0) * r[vlen].f1.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_reflectivity[vlen].f1[i] = r[vlen].f1[i];
      }
    }

    b_Simulation.set_size(r1.size(0));
    b_i = r1.size(0);
    for (vlen = 0; vlen < b_i; vlen++) {
      b_Simulation[vlen].f1.set_size(r1[vlen].f1.size(0), 2);
      loop_ub = r1[vlen].f1.size(0) * r1[vlen].f1.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_Simulation[vlen].f1[i] = r1[vlen].f1[i];
      }
    }

    b_allLayers.set_size(r2.size(0));
    b_i = r2.size(0);
    for (vlen = 0; vlen < b_i; vlen++) {
      b_allLayers[vlen].f1.set_size(r2[vlen].f1.size(0), r2[vlen].f1.size(1));
      loop_ub = r2[vlen].f1.size(0) * r2[vlen].f1.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_allLayers[vlen].f1[i] = r2[vlen].f1[i];
      }
    }

    reflectivity.set_size(b_reflectivity.size(0));
    b_i = b_reflectivity.size(0);
    for (vlen = 0; vlen < b_i; vlen++) {
      reflectivity[vlen].f1.set_size(b_reflectivity[vlen].f1.size(0), 2);
      loop_ub = b_reflectivity[vlen].f1.size(0) * b_reflectivity[vlen].f1.size(1);
      for (i = 0; i < loop_ub; i++) {
        reflectivity[vlen].f1[i] = b_reflectivity[vlen].f1[i];
      }
    }

    Simulation.set_size(b_Simulation.size(0));
    b_i = b_Simulation.size(0);
    for (vlen = 0; vlen < b_i; vlen++) {
      Simulation[vlen].f1.set_size(b_Simulation[vlen].f1.size(0), 2);
      loop_ub = b_Simulation[vlen].f1.size(0) * b_Simulation[vlen].f1.size(1);
      for (i = 0; i < loop_ub; i++) {
        Simulation[vlen].f1[i] = b_Simulation[vlen].f1[i];
      }
    }

    shifted_data.set_size(b_shifted_data.size(0));
    b_i = b_shifted_data.size(0);
    for (vlen = 0; vlen < b_i; vlen++) {
      shifted_data[vlen].f1.set_size(b_shifted_data[vlen].f1.size(0), 3);
      loop_ub = b_shifted_data[vlen].f1.size(0) * b_shifted_data[vlen].f1.size(1);
      for (i = 0; i < loop_ub; i++) {
        shifted_data[vlen].f1[i] = b_shifted_data[vlen].f1[i];
      }
    }

    layerSlds.set_size(b_layerSlds.size(0));
    b_i = b_layerSlds.size(0);
    for (vlen = 0; vlen < b_i; vlen++) {
      layerSlds[vlen].f1.set_size(b_layerSlds[vlen].f1.size(0), 3);
      loop_ub = b_layerSlds[vlen].f1.size(0) * b_layerSlds[vlen].f1.size(1);
      for (i = 0; i < loop_ub; i++) {
        layerSlds[vlen].f1[i] = b_layerSlds[vlen].f1[i];
      }
    }

    sldProfiles.set_size(b_sldProfiles.size(0));
    b_i = b_sldProfiles.size(0);
    for (vlen = 0; vlen < b_i; vlen++) {
      sldProfiles[vlen].f1.set_size(b_sldProfiles[vlen].f1.size(0), 2);
      loop_ub = b_sldProfiles[vlen].f1.size(0) * b_sldProfiles[vlen].f1.size(1);
      for (i = 0; i < loop_ub; i++) {
        sldProfiles[vlen].f1[i] = b_sldProfiles[vlen].f1[i];
      }
    }

    allLayers.set_size(b_allLayers.size(0));
    b_i = b_allLayers.size(0);
    for (vlen = 0; vlen < b_i; vlen++) {
      allLayers[vlen].f1.set_size(b_allLayers[vlen].f1.size(0), b_allLayers[vlen]
        .f1.size(1));
      loop_ub = b_allLayers[vlen].f1.size(0) * b_allLayers[vlen].f1.size(1);
      for (i = 0; i < loop_ub; i++) {
        allLayers[vlen].f1[i] = b_allLayers[vlen].f1[i];
      }
    }

    //       case 'contrasts'
    //          [outSsubs,...
    //              backgs,...
    //              qshifts,...
    //              sfs,...
    //              nbas,...
    //              nbss,...
    //              resols,...
    //              chis,...
    //              reflectivity,...
    //              Simulation,...
    //              shifted_data,...
    //              layerSlds,...
    //              sldProfiles,...
    //              allLayers,...
    //              allRoughs] = standardTF_custXY_paraContrasts(resample, ...
    //              numberOfContrasts, ...
    //              geometry, ...
    //              repeatLayers , ...
    //              cBacks , ...
    //              cShifts , ...
    //              cScales , ...
    //              cNbas , ...
    //              cNbss, ...
    //              cRes , ...
    //              backs , ...
    //              shifts , ...
    //              sf, ...
    //              nba , ...
    //              nbs , ...
    //              res , ...
    //              dataPresent , ...
    //              allData , ...
    //              dataLimits , ...
    //              simLimits , ...
    //              nParams , ...
    //              params , ...
    //              contrastLayers , ...
    //              numberOfLayers , ...
    //              layersDetails, ...
    //              problemDef_limits, ...
    //              fname, ...
    //              lang, ...
    //              path,...
    //              backsType,...
    //              calcSLD);
    break;
  }

  problem->calculations.all_chis.set_size(chis.size(0));
  loop_ub = chis.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    problem->calculations.all_chis[b_i] = chis[b_i];
  }

  vlen = chis.size(0);
  if (chis.size(0) == 0) {
    layers = 0.0;
  } else {
    layers = chis[0];
    for (loop_ub = 2; loop_ub <= vlen; loop_ub++) {
      layers += chis[loop_ub - 1];
    }
  }

  problem->calculations.sum_chi = layers;

  // problem.calculations.reflectivity = reflectivity;
  // problem.calculations.Simulation = Simulation;
  // problem.shifted_data = shifted_data;
  // problem.layers = layerSlds;
  // problem.calculations.slds = sldProfiles;
  // problem.allLayers = allLayers;
  //  result = cell(1,6);
  //
  //
  //
  //  %result = {{};{};{};{};{};{};{}};
  //  result{1} = reflectivity;
  //  result{2} = Simulation;
  //  result{3} = shifted_data;
  //  result{4} = layerSlds;
  //  result{5} = sldProfiles;
  //  result{6} = allLayers;
  //
  //
  //  %Result coder definitions....
  //   coder.varsize('result{1}',[Inf 1],[1 0]);           %Reflectivity
  //   coder.varsize('result{1}{:}',[Inf 2],[1 0]);
  //  %
  //   coder.varsize('result{2}',[Inf 1],[1 0]);           %Simulatin
  //   coder.varsize('result{2}{:}',[Inf 2],[1 0]);
  //  %
  //   coder.varsize('result{3}',[Inf 1],[1 0]);           %Shifted data
  //   coder.varsize('result{3}{:}',[Inf 3],[1 0]);
  //  %
  //   coder.varsize('result{4}',[Inf 1],[1 0]);           %Layers slds
  //   coder.varsize('result{4}{:}',[Inf 3],[1 0]);
  //  %
  //   coder.varsize('result{5}',[Inf 1],[1 0]);           %Sld profiles
  //   coder.varsize('results{5}{:}',[Inf 2],[1 0]);
  //  %
  //   coder.varsize('result{6}',[Inf 1],[1 0]);           %All layers
  //   coder.varsize('result{6}{:}',[Inf 1],[1 0]);
}

//
// File trailer for standardTF_custXY_reflectivityCalculation.cpp
//
// [EOF]
//
