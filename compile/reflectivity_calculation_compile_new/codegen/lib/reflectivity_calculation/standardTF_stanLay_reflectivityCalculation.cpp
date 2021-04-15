//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: standardTF_stanLay_reflectivityCalculation.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 15-Apr-2021 10:46:16
//

// Include Files
#include "standardTF_stanLay_reflectivityCalculation.h"
#include "allocateLayersForContrast.h"
#include "allocateParamsToLayers.h"
#include "backSort.h"
#include "groupLayers_Mod.h"
#include "reflectivity_calculation.h"
#include "rt_nonfinite.h"
#include "standardTF_layers_core.h"
#include "standardTF_stanlay_paraAll.h"
#include "standardTF_stanlay_paraContrasts.h"

// Function Definitions

//
// Pre-allocation - It's necessary to
//  pre-allocate the memory for all the arrays
//  for compilation, so do this in this block.
// Arguments    : const struct0_T *problemDef
//                const cell_14 *problemDef_cells
//                const struct2_T *controls
//                struct4_T *problem
//                coder::array<cell_wrap_7, 1U> *reflectivity
//                coder::array<cell_wrap_7, 1U> *Simulation
//                coder::array<cell_wrap_1, 1U> *shifted_data
//                coder::array<cell_wrap_8, 1U> *layerSlds
//                coder::array<cell_wrap_1, 1U> *sldProfiles
//                coder::array<cell_wrap_12, 1U> *allLayers
// Return Type  : void
//
void c_standardTF_stanLay_reflectivi(const struct0_T *problemDef, const cell_14 *
  problemDef_cells, const struct2_T *controls, struct4_T *problem, coder::array<
  cell_wrap_7, 1U> &reflectivity, coder::array<cell_wrap_7, 1U> &Simulation,
  coder::array<cell_wrap_1, 1U> &shifted_data, coder::array<cell_wrap_8, 1U>
  &layerSlds, coder::array<cell_wrap_1, 1U> &sldProfiles, coder::array<
  cell_wrap_12, 1U> &allLayers)
{
  int loop_ub;
  coder::array<double, 1U> chis;
  int i;
  boolean_T b_bool;
  int vlen;
  int exitg1;
  static const char cv[6] = { 's', 'i', 'n', 'g', 'l', 'e' };

  static const char cv1[6] = { 'p', 'o', 'i', 'n', 't', 's' };

  int b_i;
  coder::array<double, 1U> backgs;
  static const char cv2[9] = { 'c', 'o', 'n', 't', 'r', 'a', 's', 't', 's' };

  double thisBackground;
  static const char cv3[3] = { 'a', 'l', 'l' };

  coder::array<cell_wrap_15, 2U> outParameterisedLayers;
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
  coder::array<double, 2U> r;
  coder::array<double, 2U> sldProfile;
  loop_ub = static_cast<int>(problemDef->numberOfContrasts);
  problem->ssubs.set_size(loop_ub);
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
    problem->ssubs[i] = 0.0;
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
    allLayers[i].f1.set_size(2);
    allLayers[i].f1[0] = 1.0;
    allLayers[i].f1[1] = 1.0;
  }

  b_bool = false;
  if (controls->para.size(1) == 6) {
    vlen = 0;
    do {
      exitg1 = 0;
      if (vlen < 6) {
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
    vlen = 0;
  } else {
    b_bool = false;
    if (controls->para.size(1) == 6) {
      vlen = 0;
      do {
        exitg1 = 0;
        if (vlen < 6) {
          if (controls->para[vlen] != cv1[vlen]) {
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
            if (controls->para[vlen] != cv2[vlen]) {
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
        b_bool = false;
        if (controls->para.size(1) == 3) {
          vlen = 0;
          do {
            exitg1 = 0;
            if (vlen < 3) {
              if (controls->para[vlen] != cv3[vlen]) {
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
          vlen = 3;
        } else {
          vlen = -1;
        }
      }
    }
  }

  switch (vlen) {
   case 0:
    //  Extract individual cell arrays
    //  Extract individual parameters from problemDef struct
    // Extract individual parameters from problemDef
    //  Allocate the memory for the output arrays before the main loop
    backgs.set_size(loop_ub);
    allLayers.set_size(loop_ub);
    for (i = 0; i < loop_ub; i++) {
      allLayers[i].f1.set_size(2);
      allLayers[i].f1[0] = 1.0;
      allLayers[i].f1[1] = 1.0;
    }

    //  end memory allocation.
    //  First we need to allocate the absolute values of the input
    //  parameters to all the layers in the layers list. This only needs
    //  to be done once, and so is done outside the contrasts loop
    allocateParamsToLayers(problemDef->params, problemDef_cells->f6,
      outParameterisedLayers);

    //  Loop over all the contrasts
    problem->ssubs.set_size(loop_ub);
    sldProfiles.set_size(loop_ub);
    reflectivity.set_size(loop_ub);
    Simulation.set_size(loop_ub);
    shifted_data.set_size(loop_ub);
    layerSlds.set_size(loop_ub);
    chis.set_size(loop_ub);
    qshifts.set_size(loop_ub);
    sfs.set_size(loop_ub);
    nbas.set_size(loop_ub);
    nbss.set_size(loop_ub);
    resols.set_size(loop_ub);
    allRoughs.set_size(loop_ub);
    for (i = 0; i < loop_ub; i++) {
      //  Extract the relevant parameter values for this contrast
      //  from the input arrays.
      //  First need to decide which values of the backrounds, scalefactors
      //  data shifts and bulk contrasts are associated with this contrast
      backSort(problemDef->contrastBacks[i], problemDef->contrastShifts[i],
               problemDef->contrastScales[i], problemDef->contrastNbas[i],
               problemDef->contrastNbss[i], problemDef->contrastRes[i],
               problemDef->backs, problemDef->shifts, problemDef->sf,
               problemDef->nba, problemDef->nbs, problemDef->res,
               &thisBackground, &thisQshift, &thisSf, &thisNba, &thisNbs,
               &thisResol);

      //  Also need to determine which layers from the overall layers list
      //  are required for this contrast, and put them in the correct order
      //  according to geometry
      //  For the other parameters, we extract the correct ones from the input
      //  arrays
      //  Substrate roughness is always first parameter for standard layers
      //  Now call the core standardTF_stanlay reflectivity calculation
      //  In this case we are single cored, so we do not parallelise over
      //  points
      //  Call the calculation
      allocateLayersForContrast(problemDef_cells->f5[i].f1,
        outParameterisedLayers, r);
      standardTF_layers_core(r, problemDef->params[0], problemDef->geometry,
        thisNba, thisNbs, problemDef->resample[i], controls->calcSld, thisSf,
        thisQshift, problemDef->dataPresent[i], problemDef_cells->f2[i].f1,
        problemDef_cells->f3[i].f1, problemDef_cells->f4[i].f1,
        problemDef_cells->f1[i].f1, thisBackground, thisResol,
        problemDef->contrastBacksType[i], static_cast<double>
        (problemDef->params.size(1)), sldProfile, reflectivity[i].f1,
        Simulation[i].f1, shifted_data[i].f1, layerSlds[i].f1, &chis[i],
        &problem->ssubs[i]);

      //  Store returned values for this contrast in the output arrays.
      //  As well as the calculated profiles, we also store a record of
      //  the other values (background, scalefactors etc) for each contrast
      //  for future use.
      sldProfiles[i].f1.set_size(sldProfile.size(0), sldProfile.size(1));
      vlen = sldProfile.size(0) * sldProfile.size(1);
      for (b_i = 0; b_i < vlen; b_i++) {
        sldProfiles[i].f1[b_i] = sldProfile[b_i];
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
    break;

   case 1:
    //  Extract individual cell arrays
    //  Extract individual parameters from problemDef
    // Extract individual parameters from problemDef
    //  Allocate the memory for the output arrays before the main loop
    //    --- Begin memory allocation ---
    backgs.set_size(loop_ub);
    allLayers.set_size(loop_ub);
    for (i = 0; i < loop_ub; i++) {
      allLayers[i].f1.set_size(2);
      allLayers[i].f1[0] = 1.0;
      allLayers[i].f1[1] = 1.0;
    }

    //  ---end memory allocation---
    //  First we need to allocate the absolute values of the input
    //  parameters to all the layers in the layers list. This only needs
    //  to be done once, and so is done outside the contrasts loop
    allocateParamsToLayers(problemDef->params, problemDef_cells->f6,
      outParameterisedLayers);

    //  Single Loop over all the contrasts
    problem->ssubs.set_size(loop_ub);
    sldProfiles.set_size(loop_ub);
    reflectivity.set_size(loop_ub);
    Simulation.set_size(loop_ub);
    shifted_data.set_size(loop_ub);
    layerSlds.set_size(loop_ub);
    chis.set_size(loop_ub);
    qshifts.set_size(loop_ub);
    sfs.set_size(loop_ub);
    nbas.set_size(loop_ub);
    nbss.set_size(loop_ub);
    resols.set_size(loop_ub);
    allRoughs.set_size(loop_ub);
    for (i = 0; i < loop_ub; i++) {
      //  Extract the relevant parameter values for this contrast
      //  from the input arrays.
      //  First need to decide which values of the backrounds, scalefactors
      //  data shifts and bulk contrasts are associated with this contrast
      backSort(problemDef->contrastBacks[i], problemDef->contrastShifts[i],
               problemDef->contrastScales[i], problemDef->contrastNbas[i],
               problemDef->contrastNbss[i], problemDef->contrastRes[i],
               problemDef->backs, problemDef->shifts, problemDef->sf,
               problemDef->nba, problemDef->nbs, problemDef->res,
               &thisBackground, &thisQshift, &thisSf, &thisNba, &thisNbs,
               &thisResol);

      //  Also need to determine which layers from the overall layers list
      //  are required for this contrast, and put them in the correct order
      //  according to geometry
      //  For the other parameters, we extract the correct ones from the input
      //  arrays
      //  Substrate roughness is always first parameter for standard layers
      //  Now call the core standardTF_stanlay reflectivity calculation
      //  In this case we parallelise over points.
      //  Call the calculation
      allocateLayersForContrast(problemDef_cells->f5[i].f1,
        outParameterisedLayers, r);
      b_standardTF_layers_core(r, problemDef->params[0], problemDef->geometry,
        thisNba, thisNbs, problemDef->resample[i], controls->calcSld, thisSf,
        thisQshift, problemDef->dataPresent[i], problemDef_cells->f2[i].f1,
        problemDef_cells->f3[i].f1, problemDef_cells->f4[i].f1,
        problemDef_cells->f1[i].f1, thisBackground, thisResol,
        problemDef->contrastBacksType[i], static_cast<double>
        (problemDef->params.size(1)), sldProfile, reflectivity[i].f1,
        Simulation[i].f1, shifted_data[i].f1, layerSlds[i].f1, &chis[i],
        &problem->ssubs[i]);

      //  Store returned values for this contrast in the output arrays.
      //  As well as the calculated profiles, we also store a record of
      //  the other values (background, scalefactors etc) for each contrast
      //  for future use.
      sldProfiles[i].f1.set_size(sldProfile.size(0), sldProfile.size(1));
      vlen = sldProfile.size(0) * sldProfile.size(1);
      for (b_i = 0; b_i < vlen; b_i++) {
        sldProfiles[i].f1[b_i] = sldProfile[b_i];
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
    break;

   case 2:
    c_standardTF_stanlay_paraContra(problemDef, problemDef_cells, controls,
      problem->ssubs, problem->backgrounds, problem->qshifts,
      problem->scalefactors, problem->nbairs, problem->nbsubs,
      problem->resolutions, chis, reflectivity, Simulation, shifted_data,
      layerSlds, sldProfiles, allLayers, problem->allSubRough);
    break;

   case 3:
    standardTF_stanlay_paraAll(problemDef, problemDef_cells, controls,
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
