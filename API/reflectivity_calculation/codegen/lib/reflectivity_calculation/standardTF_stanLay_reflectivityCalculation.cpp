//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: standardTF_stanLay_reflectivityCalculation.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Jan-2021 16:52:33
//

// Include Files
#include "standardTF_stanLay_reflectivityCalculation.h"
#include "allocateLayersForContrast.h"
#include "allocateParamsToLayers.h"
#include "applyBackgroundCorrection.h"
#include "backSort.h"
#include "callReflectivity.h"
#include "chiSquared.h"
#include "groupLayers_Mod.h"
#include "makeSLDProfiles.h"
#include "matlabEngineCaller_customLayers.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "resampleLayers.h"
#include "rt_nonfinite.h"
#include "shiftdata.h"
#include "standardTF_custXY_reflectivityCalculation.h"
#include "standardTF_reflectivityCalculation.h"
#include "standardTF_stanlay_paraContrasts.h"

// Function Definitions

//
// Arguments    : const struct0_T *problemDef
//                const cell_13 *problemDef_cells
//                const struct2_T *controls
//                struct4_T *problem
//                coder::array<cell_wrap_11, 1U> *reflectivity
//                coder::array<cell_wrap_6, 1U> *Simulation
//                coder::array<cell_wrap_1, 1U> *shifted_data
//                coder::array<cell_wrap_1, 1U> *layerSlds
//                coder::array<cell_wrap_11, 1U> *sldProfiles
//                coder::array<cell_wrap_11, 1U> *allLayers
// Return Type  : void
//
void c_standardTF_stanLay_reflectivi(const struct0_T *problemDef, const cell_13 *
  problemDef_cells, const struct2_T *controls, struct4_T *problem, coder::array<
  cell_wrap_11, 1U> &reflectivity, coder::array<cell_wrap_6, 1U> &Simulation,
  coder::array<cell_wrap_1, 1U> &shifted_data, coder::array<cell_wrap_1, 1U>
  &layerSlds, coder::array<cell_wrap_11, 1U> &sldProfiles, coder::array<
  cell_wrap_11, 1U> &allLayers)
{
  int loop_ub;
  coder::array<double, 1U> chis;
  int i;
  boolean_T b_bool;
  int vlen;
  int exitg1;
  static const char b_cv[6] = { 's', 'i', 'n', 'g', 'l', 'e' };

  static const char b_cv1[6] = { 'p', 'o', 'i', 'n', 't', 's' };

  int b_i;
  coder::array<cell_wrap_16, 2U> outParameterisedLayers;
  coder::array<double, 1U> backgs;
  double thisBackground;
  coder::array<double, 1U> qshifts;
  coder::array<double, 1U> sfs;
  coder::array<double, 1U> nbas;
  coder::array<double, 1U> nbss;
  coder::array<double, 1U> resols;
  coder::array<double, 1U> allRoughs;
  double thisQshift;
  double thisSf;
  double thisNba;
  double thisNbs;
  double thisResol;
  coder::array<double, 2U> sldProfile;
  coder::array<double, 2U> layerSld;
  coder::array<double, 2U> reflect;
  coder::array<double, 2U> shifted_dat;

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
      b_bool = false;
      if (controls->para.size(1) == 9) {
        vlen = 0;
        do {
          exitg1 = 0;
          if (vlen < 9) {
            if (controls->para[vlen] != cv[vlen]) {
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
        vlen = 2;
      } else {
        vlen = -1;
      }
    }
  }

  switch (vlen) {
   case 0:
    {
      // Pre-Allocation...
      //
      allLayers.set_size(loop_ub);
      for (i = 0; i < loop_ub; i++) {
        allLayers[i].f1.set_size(2, 1);
        allLayers[i].f1[0] = 1.0;
        allLayers[i].f1[1] = 1.0;
      }

      allocateParamsToLayers(problemDef->params, problemDef_cells->f6,
        outParameterisedLayers);
      problem->ssubs.set_size(loop_ub);
      Simulation.set_size(loop_ub);
      reflectivity.set_size(loop_ub);
      sldProfiles.set_size(loop_ub);
      shifted_data.set_size(loop_ub);
      layerSlds.set_size(loop_ub);
      chis.set_size(loop_ub);
      backgs.set_size(loop_ub);
      qshifts.set_size(loop_ub);
      sfs.set_size(loop_ub);
      nbas.set_size(loop_ub);
      nbss.set_size(loop_ub);
      resols.set_size(loop_ub);
      allRoughs.set_size(loop_ub);
      for (i = 0; i < loop_ub; i++) {
        double thisCalcSld;

        //  Extract the correct parameter values for this contrast
        backSort(problemDef->contrastBacks[i], problemDef->contrastShifts[i],
                 problemDef->contrastScales[i], problemDef->contrastNbas[i],
                 problemDef->contrastNbss[i], problemDef->contrastRes[i],
                 problemDef->backs, problemDef->shifts, problemDef->sf,
                 problemDef->nba, problemDef->nbs, problemDef->res,
                 &thisBackground, &thisQshift, &thisSf, &thisNba, &thisNbs,
                 &thisResol);

        //  Bulid up the layers matrix for this contrast
        allocateLayersForContrast(problemDef_cells->f5[i].f1,
          outParameterisedLayers, sldProfile);
        groupLayers_Mod(sldProfile, problemDef->params[0], problemDef->geometry,
                        thisNba, thisNbs, layerSld, &problem->ssubs[i]);

        //  Make the SLD profiles.
        //  If resampling is done, then enforce th calcSLD flag
        thisCalcSld = controls->calcSld;
        if (problemDef->resample[i] == 1.0) {
          thisCalcSld = 1.0;
        }

        //  If cal SLD flag is set, then calculate the SLD profile
        if (thisCalcSld == 1.0) {
          makeSLDProfiles(thisNba, thisNbs, layerSld, problem->ssubs[i],
                          problemDef_cells->f1[i].f1, reflect);
          sldProfile.set_size(reflect.size(0), 2);
          vlen = reflect.size(0) * reflect.size(1);
          for (b_i = 0; b_i < vlen; b_i++) {
            sldProfile[b_i] = reflect[b_i];
          }
        } else {
          sldProfile.set_size(1, 3);
          sldProfile[0] = 0.0;
          sldProfile[1] = 0.0;
          sldProfile[2] = 0.0;
        }

        //  If required, then resample the SLD
        if (problemDef->resample[i] == 1.0) {
          resampleLayers(sldProfile, layerSld);
        }

        //  Apply scale factors and q shifts to the data
        shifted_dat.set_size(problemDef_cells->f2[problemDef_cells->f2.size(0) *
                             i].f1.size(0), 3);
        vlen = problemDef_cells->f2[i].f1.size(0) * problemDef_cells->f2[i].
          f1.size(1);
        for (b_i = 0; b_i < vlen; b_i++) {
          shifted_dat[b_i] = problemDef_cells->f2[i].f1[b_i];
        }

        shiftdata(thisSf, thisQshift, problemDef->dataPresent[i], shifted_dat,
                  problemDef_cells->f3[i].f1);

        //  Calculate the reflectivity
        callReflectivity(thisNba, thisNbs, problemDef_cells->f4[i].f1,
                         problemDef_cells->f1[i].f1, shifted_dat, layerSld,
                         problem->ssubs[i], thisResol, reflect, Simulation[i].f1);

        //  Apply background correction, either to the simulation or the data
        applyBackgroundCorrection(reflect, Simulation[i].f1, shifted_dat,
          thisBackground, problemDef->contrastBacksType[i]);

        //  Calculate chi squared.
        chis[i] = chiSquared(shifted_dat, reflect, static_cast<double>
                             (problemDef->params.size(1)));

        //  Store relevant values for this contrast in output arrays
        sldProfiles[i].f1.set_size(sldProfile.size(0), sldProfile.size(1));
        vlen = sldProfile.size(0) * sldProfile.size(1);
        for (b_i = 0; b_i < vlen; b_i++) {
          sldProfiles[i].f1[b_i] = sldProfile[b_i];
        }

        reflectivity[i].f1.set_size(reflect.size(0), 2);
        vlen = reflect.size(0) * reflect.size(1);
        for (b_i = 0; b_i < vlen; b_i++) {
          reflectivity[i].f1[b_i] = reflect[b_i];
        }

        shifted_data[i].f1.set_size(shifted_dat.size(0), 3);
        vlen = shifted_dat.size(0) * shifted_dat.size(1);
        for (b_i = 0; b_i < vlen; b_i++) {
          shifted_data[i].f1[b_i] = shifted_dat[b_i];
        }

        layerSlds[i].f1.set_size(layerSld.size(0), 3);
        vlen = layerSld.size(0) * layerSld.size(1);
        for (b_i = 0; b_i < vlen; b_i++) {
          layerSlds[i].f1[b_i] = layerSld[b_i];
        }

        backgs[i] = thisBackground;
        qshifts[i] = thisQshift;
        sfs[i] = thisSf;
        nbas[i] = thisNba;
        nbss[i] = thisNbs;
        resols[i] = thisResol;
        allRoughs[i] = problemDef->params[0];
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
    }
    break;

   case 1:
    {
      // Pre-Allocation...
      //
      allLayers.set_size(loop_ub);
      for (i = 0; i < loop_ub; i++) {
        allLayers[i].f1.set_size(2, 1);
        allLayers[i].f1[0] = 1.0;
        allLayers[i].f1[1] = 1.0;
      }

      allocateParamsToLayers(problemDef->params, problemDef_cells->f6,
        outParameterisedLayers);
      backgs.set_size(loop_ub);
      qshifts.set_size(loop_ub);
      sfs.set_size(loop_ub);
      nbas.set_size(loop_ub);
      nbss.set_size(loop_ub);
      resols.set_size(loop_ub);
      allRoughs.set_size(loop_ub);
      problem->ssubs.set_size(loop_ub);
      sldProfiles.set_size(loop_ub);
      layerSlds.set_size(loop_ub);
      shifted_data.set_size(loop_ub);
      Simulation.set_size(loop_ub);
      reflectivity.set_size(loop_ub);
      chis.set_size(loop_ub);
      for (i = 0; i < loop_ub; i++) {
        double thisCalcSld;
        backSort(problemDef->contrastBacks[i], problemDef->contrastShifts[i],
                 problemDef->contrastScales[i], problemDef->contrastNbas[i],
                 problemDef->contrastNbss[i], problemDef->contrastRes[i],
                 problemDef->backs, problemDef->shifts, problemDef->sf,
                 problemDef->nba, problemDef->nbs, problemDef->res, &backgs[i],
                 &qshifts[i], &sfs[i], &nbas[i], &nbss[i], &resols[i]);
        thisBackground = problemDef->params[0];
        allRoughs[i] = thisBackground;
        allocateLayersForContrast(problemDef_cells->f5[i].f1,
          outParameterisedLayers, sldProfile);
        groupLayers_Mod(sldProfile, thisBackground, problemDef->geometry, nbas[i],
                        nbss[i], layerSld, &problem->ssubs[i]);
        thisCalcSld = controls->calcSld;
        if (problemDef->resample[i] == 1.0) {
          thisCalcSld = 1.0;
        }

        if (thisCalcSld == 1.0) {
          makeSLDProfiles(nbas[i], nbss[i], layerSld, problem->ssubs[i],
                          problemDef_cells->f1[i].f1, reflect);
          sldProfile.set_size(reflect.size(0), 2);
          vlen = reflect.size(0) * reflect.size(1);
          for (b_i = 0; b_i < vlen; b_i++) {
            sldProfile[b_i] = reflect[b_i];
          }
        } else {
          sldProfile.set_size(1, 3);
          sldProfile[0] = 0.0;
          sldProfile[1] = 0.0;
          sldProfile[2] = 0.0;
        }

        sldProfiles[i].f1.set_size(sldProfile.size(0), sldProfile.size(1));
        vlen = sldProfile.size(0) * sldProfile.size(1);
        for (b_i = 0; b_i < vlen; b_i++) {
          sldProfiles[i].f1[b_i] = sldProfile[b_i];
        }

        if (problemDef->resample[i] == 1.0) {
          resampleLayers(sldProfile, layerSld);
          layerSlds[i].f1.set_size(layerSld.size(0), 3);
          vlen = layerSld.size(0) * layerSld.size(1);
          for (b_i = 0; b_i < vlen; b_i++) {
            layerSlds[i].f1[b_i] = layerSld[b_i];
          }
        } else {
          layerSlds[i].f1.set_size(layerSld.size(0), 3);
          vlen = layerSld.size(0) * layerSld.size(1);
          for (b_i = 0; b_i < vlen; b_i++) {
            layerSlds[i].f1[b_i] = layerSld[b_i];
          }
        }

        shifted_dat.set_size(problemDef_cells->f2[problemDef_cells->f2.size(0) *
                             i].f1.size(0), 3);
        vlen = problemDef_cells->f2[i].f1.size(0) * problemDef_cells->f2[i].
          f1.size(1);
        for (b_i = 0; b_i < vlen; b_i++) {
          shifted_dat[b_i] = problemDef_cells->f2[i].f1[b_i];
        }

        shiftdata(sfs[i], qshifts[i], problemDef->dataPresent[i], shifted_dat,
                  problemDef_cells->f3[i].f1);
        b_callReflectivity(nbas[i], nbss[i], problemDef_cells->f4[i].f1,
                           problemDef_cells->f1[i].f1, shifted_dat, layerSld,
                           problem->ssubs[i], resols[i], reflect, Simulation[i].
                           f1);
        applyBackgroundCorrection(reflect, Simulation[i].f1, shifted_dat,
          backgs[i], problemDef->contrastBacksType[i]);
        reflectivity[i].f1.set_size(reflect.size(0), 2);
        vlen = reflect.size(0) * reflect.size(1);
        for (b_i = 0; b_i < vlen; b_i++) {
          reflectivity[i].f1[b_i] = reflect[b_i];
        }

        shifted_data[i].f1.set_size(shifted_dat.size(0), 3);
        vlen = shifted_dat.size(0) * shifted_dat.size(1);
        for (b_i = 0; b_i < vlen; b_i++) {
          shifted_data[i].f1[b_i] = shifted_dat[b_i];
        }

        chis[i] = chiSquared(shifted_dat, reflect, static_cast<double>
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
    }
    break;

   case 2:
    c_standardTF_stanlay_paraContra(problemDef->resample,
      problemDef->numberOfContrasts, problemDef->geometry, problemDef_cells->f1,
      problemDef->contrastBacks, problemDef->contrastShifts,
      problemDef->contrastScales, problemDef->contrastNbas,
      problemDef->contrastNbss, problemDef->contrastRes, problemDef->backs,
      problemDef->shifts, problemDef->sf, problemDef->nba, problemDef->nbs,
      problemDef->res, problemDef->dataPresent, problemDef_cells->f2,
      problemDef_cells->f3, problemDef_cells->f4, static_cast<double>
      (problemDef->params.size(1)), problemDef->params, problemDef_cells->f5,
      problemDef_cells->f6, problemDef->contrastBacksType, controls->calcSld,
      problem->ssubs, problem->backgrounds, problem->qshifts,
      problem->scalefactors, problem->nbairs, problem->nbsubs,
      problem->resolutions, chis, reflectivity, Simulation, shifted_data,
      layerSlds, sldProfiles, allLayers, problem->allSubRough);
    break;
  }

  problem->calculations.all_chis.set_size(chis.size(0));
  loop_ub = chis.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    problem->calculations.all_chis[b_i] = chis[b_i];
  }

  vlen = chis.size(0);
  if (chis.size(0) == 0) {
    thisBackground = 0.0;
  } else {
    thisBackground = chis[0];
    for (loop_ub = 2; loop_ub <= vlen; loop_ub++) {
      thisBackground += chis[loop_ub - 1];
    }
  }

  problem->calculations.sum_chi = thisBackground;
}

//
// File trailer for standardTF_stanLay_reflectivityCalculation.cpp
//
// [EOF]
//
