//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// standardTF_custLay_reflectivityCalculation.cpp
//
// Code generation for function 'standardTF_custLay_reflectivityCalculation'
//

// Include files
#include "standardTF_custLay_reflectivityCalculation.h"
#include "backSort.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_internal_types.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "standardTF_custlay_paraContrasts.h"
#include "standardTF_custlay_paraPoints.h"
#include "standardTF_layers_core.h"
#include "sum.h"
#include "coder_array.h"

// Function Definitions
void standardTF_custLay_reflectivityCalculation(
    const struct0_T *problemDef, const cell_14 *problemDef_cells,
    const struct2_T *controls, struct4_T *problem,
    coder::array<cell_wrap_7, 1U> &reflectivity,
    coder::array<cell_wrap_7, 1U> &Simulation,
    coder::array<cell_wrap_1, 1U> &shifted_data,
    coder::array<cell_wrap_8, 1U> &layerSlds,
    coder::array<cell_wrap_1, 1U> &sldProfiles,
    coder::array<cell_wrap_1, 1U> &allLayers)
{
  static const char b_cv[6]{'s', 'i', 'n', 'g', 'l', 'e'};
  static const char b_cv1[6]{'p', 'o', 'i', 'n', 't', 's'};
  coder::array<cell_wrap_1, 1U> b_allLayers;
  coder::array<cell_wrap_10, 1U> r;
  coder::array<cell_wrap_10, 1U> r1;
  coder::array<cell_wrap_29, 1U> r2;
  coder::array<cell_wrap_7, 1U> b_Simulation;
  coder::array<cell_wrap_7, 1U> b_reflectivity;
  coder::array<double, 2U> Simul;
  coder::array<double, 2U> reflect;
  coder::array<double, 2U> sldProfile;
  coder::array<double, 1U> backgs;
  coder::array<signed char, 1U> allRoughs;
  double thisBackground;
  double thisNba;
  double thisNbs;
  double thisQshift;
  double thisResol;
  double thisSf;
  int b_i;
  int exitg1;
  int i;
  int kstr;
  int loop_ub_tmp;
  boolean_T b_bool;
  //  Custom layers reflectivity calculation for standardTF
  //  This function decides on parallelisation options before calling the
  //  relevant version of the main custom layers calculation. It is more
  //  efficient to have multiple versions of the core calculation, each dealing
  //  with a different scheme for paralellisation. These are:
  //  single    - single threaded teflectivity calculation
  //  points    - parallelise over points in the reflectivity calculation
  //  contrasts - parallelise over contrasts.
  //  Pre-allocation - It's necessary to
  //  pre-allocate the memory for all the arrays
  //  for compilation, so do this in this block.
  loop_ub_tmp = static_cast<int>(problemDef->numberOfContrasts);
  problem->ssubs.set_size(loop_ub_tmp);
  problem->backgrounds.set_size(loop_ub_tmp);
  problem->qshifts.set_size(loop_ub_tmp);
  problem->scalefactors.set_size(loop_ub_tmp);
  problem->nbairs.set_size(loop_ub_tmp);
  problem->nbsubs.set_size(loop_ub_tmp);
  problem->calculations.all_chis.set_size(loop_ub_tmp);
  problem->resolutions.set_size(loop_ub_tmp);
  problem->allSubRough.set_size(loop_ub_tmp);
  reflectivity.set_size(loop_ub_tmp);
  Simulation.set_size(loop_ub_tmp);
  shifted_data.set_size(loop_ub_tmp);
  layerSlds.set_size(loop_ub_tmp);
  sldProfiles.set_size(loop_ub_tmp);
  allLayers.set_size(loop_ub_tmp);
  for (i = 0; i < loop_ub_tmp; i++) {
    problem->ssubs[i] = 0.0;
    problem->backgrounds[i] = 0.0;
    problem->qshifts[i] = 0.0;
    problem->scalefactors[i] = 0.0;
    problem->nbairs[i] = 0.0;
    problem->nbsubs[i] = 0.0;
    problem->calculations.all_chis[i] = 0.0;
    problem->resolutions[i] = 0.0;
    problem->allSubRough[i] = 0.0;
    reflectivity[i].f1.set_size(2, 2);
    reflectivity[i].f1[0] = 1.0;
    reflectivity[i].f1[1] = 1.0;
    reflectivity[i].f1[reflectivity[i].f1.size(0)] = 1.0;
    reflectivity[i].f1[reflectivity[i].f1.size(0) + 1] = 1.0;
    Simulation[i].f1.set_size(2, 2);
    Simulation[i].f1[0] = 1.0;
    Simulation[i].f1[1] = 1.0;
    Simulation[i].f1[Simulation[i].f1.size(0)] = 1.0;
    Simulation[i].f1[Simulation[i].f1.size(0) + 1] = 1.0;
    shifted_data[i].f1.set_size(2, 3);
    layerSlds[i].f1.set_size(2, 3);
    for (b_i = 0; b_i < 3; b_i++) {
      shifted_data[i].f1[shifted_data[i].f1.size(0) * b_i] = 1.0;
      shifted_data[i].f1[shifted_data[i].f1.size(0) * b_i + 1] = 1.0;
      layerSlds[i].f1[layerSlds[i].f1.size(0) * b_i] = 1.0;
      layerSlds[i].f1[layerSlds[i].f1.size(0) * b_i + 1] = 1.0;
    }
    sldProfiles[i].f1.set_size(2, 2);
    sldProfiles[i].f1[0] = 1.0;
    sldProfiles[i].f1[1] = 1.0;
    sldProfiles[i].f1[sldProfiles[i].f1.size(0)] = 1.0;
    sldProfiles[i].f1[sldProfiles[i].f1.size(0) + 1] = 1.0;
    allLayers[i].f1.set_size(2, 1);
    allLayers[i].f1[0] = 1.0;
    allLayers[i].f1[1] = 1.0;
  }
  //  End pre-allocation
  b_bool = false;
  if (controls->para.size(1) == 6) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 6) {
        if (controls->para[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (b_bool) {
    kstr = 0;
  } else {
    b_bool = false;
    if (controls->para.size(1) == 6) {
      kstr = 0;
      do {
        exitg1 = 0;
        if (kstr < 6) {
          if (controls->para[kstr] != b_cv1[kstr]) {
            exitg1 = 1;
          } else {
            kstr++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (b_bool) {
      kstr = 1;
    } else {
      b_bool = false;
      if (controls->para.size(1) == 9) {
        kstr = 0;
        do {
          exitg1 = 0;
          if (kstr < 9) {
            if (controls->para[kstr] != cv1[kstr]) {
              exitg1 = 1;
            } else {
              kstr++;
            }
          } else {
            b_bool = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (b_bool) {
        kstr = 2;
      } else {
        kstr = -1;
      }
    }
  }
  switch (kstr) {
  case 0: {
    int i1;
    //  Single threaded version of the custom layers, standardTF reflectivity
    //  calculation. The function extracts the relevant parameters from the
    //  input arrays, allocates these on a pre-contrast basis, then calls the
    //  'core' calculation (the core layers standardTf calc is shared between
    //  multiple calculation types). Extract individual cell arrays Splits up
    //  the master input list of all arrays into separate arrays The min input
    //  array 'problemDef_cells' is a master array where all the cell arrays are
    //  grouped together. There are repeatLayers      - controls repeating of
    //  the layers stack allData           - Array of all the data arrays
    //  dataLimits        - Min max limits in q for the data arrays
    //  simLimits         - Limits in Q for the reflkectivity simulations
    //  Layers details    - Master array of all available layers
    //  contrastLayers    - Which specific combination of arrays are needed for
    //                      each contrast.
    //  Custom files      - Filenames and path for any custom files used
    //  Extract individual parameters from problemDef struct
    // Extract individual parameters from problemDef
    //  Pre-Allocation of output arrays...
    backgs.set_size(loop_ub_tmp);
    //    --- End Memory Allocation ---
    //  Single cored over all contrasts
    allRoughs.set_size(loop_ub_tmp);
    r2.set_size(loop_ub_tmp);
    problem->ssubs.set_size(loop_ub_tmp);
    sldProfiles.set_size(loop_ub_tmp);
    r.set_size(loop_ub_tmp);
    r1.set_size(loop_ub_tmp);
    shifted_data.set_size(loop_ub_tmp);
    layerSlds.set_size(loop_ub_tmp);
    problem->calculations.all_chis.set_size(loop_ub_tmp);
    problem->qshifts.set_size(loop_ub_tmp);
    problem->scalefactors.set_size(loop_ub_tmp);
    problem->nbairs.set_size(loop_ub_tmp);
    problem->nbsubs.set_size(loop_ub_tmp);
    problem->resolutions.set_size(loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      int loop_ub;
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
      //  Call the custom layers function to get the layers array...
      allRoughs[i] = 3;
      r2[i].f1.set_size(3, 3);
      for (b_i = 0; b_i < 3; b_i++) {
        r2[i].f1[r2[i].f1.size(0) * b_i] = dv[b_i][0];
        r2[i].f1[r2[i].f1.size(0) * b_i + 1] = dv[b_i][1];
        r2[i].f1[r2[i].f1.size(0) * b_i + 2] = dv[b_i][2];
      }
      //  For the other parameters, we extract the correct ones from the input
      //  arrays
      //  Now call the core standardTF_stanlay reflectivity calculation
      //  In this case we are single cored, so we do not parallelise over
      //  points
      //  Call the reflectivity calculation
      standardTF_layers_core(
          problemDef->geometry, thisNba, thisNbs, problemDef->resample[i],
          controls->calcSld, thisSf, thisQshift, problemDef->dataPresent[i],
          problemDef_cells->f2[i].f1, problemDef_cells->f3[i].f1,
          problemDef_cells->f4[i].f1, problemDef_cells->f1[i].f1,
          thisBackground, thisResol, problemDef->contrastBacksType[i],
          static_cast<double>(problemDef->params.size(1)), sldProfile, reflect,
          Simul, shifted_data[i].f1, layerSlds[i].f1,
          &problem->calculations.all_chis[i], &problem->ssubs[i]);
      //  Store returned values for this contrast in the output arrays.
      //  As well as the calculated profiles, we also store a record of
      //  the other values (background, scalefactors etc) for each contrast
      //  for future use.
      kstr = sldProfile.size(1);
      sldProfiles[i].f1.set_size(sldProfile.size(0), sldProfile.size(1));
      for (b_i = 0; b_i < kstr; b_i++) {
        loop_ub = sldProfile.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          sldProfiles[i].f1[i1 + sldProfiles[i].f1.size(0) * b_i] =
              sldProfile[i1 + sldProfile.size(0) * b_i];
        }
      }
      kstr = reflect.size(0);
      r[i].f1.set_size(reflect.size(0), 2);
      loop_ub = Simul.size(0);
      r1[i].f1.set_size(Simul.size(0), 2);
      for (b_i = 0; b_i < 2; b_i++) {
        for (i1 = 0; i1 < kstr; i1++) {
          r[i].f1[i1 + r[i].f1.size(0) * b_i] =
              reflect[i1 + reflect.size(0) * b_i];
        }
        for (i1 = 0; i1 < loop_ub; i1++) {
          r1[i].f1[i1 + r1[i].f1.size(0) * b_i] =
              Simul[i1 + Simul.size(0) * b_i];
        }
      }
      backgs[i] = thisBackground;
      problem->qshifts[i] = thisQshift;
      problem->scalefactors[i] = thisSf;
      problem->nbairs[i] = thisNba;
      problem->nbsubs[i] = thisNbs;
      problem->resolutions[i] = thisResol;
      allRoughs[i] = 3;
    }
    problem->backgrounds.set_size(backgs.size(0));
    kstr = backgs.size(0);
    for (b_i = 0; b_i < kstr; b_i++) {
      problem->backgrounds[b_i] = backgs[b_i];
    }
    problem->allSubRough.set_size(allRoughs.size(0));
    kstr = allRoughs.size(0);
    for (b_i = 0; b_i < kstr; b_i++) {
      problem->allSubRough[b_i] = 3.0;
    }
    b_reflectivity.set_size(r.size(0));
    b_i = r.size(0);
    for (i1 = 0; i1 < b_i; i1++) {
      kstr = r[i1].f1.size(0);
      b_reflectivity[i1].f1.set_size(r[i1].f1.size(0), 2);
      for (loop_ub_tmp = 0; loop_ub_tmp < 2; loop_ub_tmp++) {
        for (i = 0; i < kstr; i++) {
          b_reflectivity[i1]
              .f1[i + b_reflectivity[i1].f1.size(0) * loop_ub_tmp] =
              r[i1].f1[i + r[i1].f1.size(0) * loop_ub_tmp];
        }
      }
    }
    b_Simulation.set_size(r1.size(0));
    b_i = r1.size(0);
    for (i1 = 0; i1 < b_i; i1++) {
      kstr = r1[i1].f1.size(0);
      b_Simulation[i1].f1.set_size(r1[i1].f1.size(0), 2);
      for (loop_ub_tmp = 0; loop_ub_tmp < 2; loop_ub_tmp++) {
        for (i = 0; i < kstr; i++) {
          b_Simulation[i1].f1[i + b_Simulation[i1].f1.size(0) * loop_ub_tmp] =
              r1[i1].f1[i + r1[i1].f1.size(0) * loop_ub_tmp];
        }
      }
    }
    b_allLayers.set_size(r2.size(0));
    b_i = r2.size(0);
    for (i1 = 0; i1 < b_i; i1++) {
      b_allLayers[i1].f1.set_size(3, 3);
      for (loop_ub_tmp = 0; loop_ub_tmp < 3; loop_ub_tmp++) {
        for (i = 0; i < 3; i++) {
          b_allLayers[i1].f1[i + b_allLayers[i1].f1.size(0) * loop_ub_tmp] =
              r2[i1].f1[i + r2[i1].f1.size(0) * loop_ub_tmp];
        }
      }
    }
    reflectivity.set_size(b_reflectivity.size(0));
    kstr = b_reflectivity.size(0);
    for (b_i = 0; b_i < kstr; b_i++) {
      reflectivity[b_i] = b_reflectivity[b_i];
    }
    Simulation.set_size(b_Simulation.size(0));
    kstr = b_Simulation.size(0);
    for (b_i = 0; b_i < kstr; b_i++) {
      Simulation[b_i] = b_Simulation[b_i];
    }
    allLayers.set_size(b_allLayers.size(0));
    kstr = b_allLayers.size(0);
    for (b_i = 0; b_i < kstr; b_i++) {
      allLayers[b_i] = b_allLayers[b_i];
    }
  } break;
  case 1: {
    int i1;
    standardTF_custlay_paraPoints(
        problemDef, problemDef_cells, controls, problem->ssubs,
        problem->backgrounds, problem->qshifts, problem->scalefactors,
        problem->nbairs, problem->nbsubs, problem->resolutions,
        problem->calculations.all_chis, r, r1, shifted_data, layerSlds,
        sldProfiles, r2, problem->allSubRough);
    b_reflectivity.set_size(r.size(0));
    b_i = r.size(0);
    for (i1 = 0; i1 < b_i; i1++) {
      kstr = r[i1].f1.size(0);
      b_reflectivity[i1].f1.set_size(r[i1].f1.size(0), 2);
      for (loop_ub_tmp = 0; loop_ub_tmp < 2; loop_ub_tmp++) {
        for (i = 0; i < kstr; i++) {
          b_reflectivity[i1]
              .f1[i + b_reflectivity[i1].f1.size(0) * loop_ub_tmp] =
              r[i1].f1[i + r[i1].f1.size(0) * loop_ub_tmp];
        }
      }
    }
    b_Simulation.set_size(r1.size(0));
    b_i = r1.size(0);
    for (i1 = 0; i1 < b_i; i1++) {
      kstr = r1[i1].f1.size(0);
      b_Simulation[i1].f1.set_size(r1[i1].f1.size(0), 2);
      for (loop_ub_tmp = 0; loop_ub_tmp < 2; loop_ub_tmp++) {
        for (i = 0; i < kstr; i++) {
          b_Simulation[i1].f1[i + b_Simulation[i1].f1.size(0) * loop_ub_tmp] =
              r1[i1].f1[i + r1[i1].f1.size(0) * loop_ub_tmp];
        }
      }
    }
    b_allLayers.set_size(r2.size(0));
    b_i = r2.size(0);
    for (i1 = 0; i1 < b_i; i1++) {
      kstr = r2[i1].f1.size(1);
      b_allLayers[i1].f1.set_size(r2[i1].f1.size(0), r2[i1].f1.size(1));
      for (loop_ub_tmp = 0; loop_ub_tmp < kstr; loop_ub_tmp++) {
        int loop_ub;
        loop_ub = r2[i1].f1.size(0);
        for (i = 0; i < loop_ub; i++) {
          b_allLayers[i1].f1[i + b_allLayers[i1].f1.size(0) * loop_ub_tmp] =
              r2[i1].f1[i + r2[i1].f1.size(0) * loop_ub_tmp];
        }
      }
    }
    reflectivity.set_size(b_reflectivity.size(0));
    kstr = b_reflectivity.size(0);
    for (b_i = 0; b_i < kstr; b_i++) {
      reflectivity[b_i] = b_reflectivity[b_i];
    }
    Simulation.set_size(b_Simulation.size(0));
    kstr = b_Simulation.size(0);
    for (b_i = 0; b_i < kstr; b_i++) {
      Simulation[b_i] = b_Simulation[b_i];
    }
    allLayers.set_size(b_allLayers.size(0));
    kstr = b_allLayers.size(0);
    for (b_i = 0; b_i < kstr; b_i++) {
      allLayers[b_i] = b_allLayers[b_i];
    }
  } break;
  case 2: {
    int i1;
    standardTF_custlay_paraContrasts(
        problemDef, problemDef_cells, controls, problem->ssubs,
        problem->backgrounds, problem->qshifts, problem->scalefactors,
        problem->nbairs, problem->nbsubs, problem->resolutions,
        problem->calculations.all_chis, r, r1, shifted_data, layerSlds,
        sldProfiles, r2, problem->allSubRough);
    b_reflectivity.set_size(r.size(0));
    b_i = r.size(0);
    for (i1 = 0; i1 < b_i; i1++) {
      kstr = r[i1].f1.size(0);
      b_reflectivity[i1].f1.set_size(r[i1].f1.size(0), 2);
      for (loop_ub_tmp = 0; loop_ub_tmp < 2; loop_ub_tmp++) {
        for (i = 0; i < kstr; i++) {
          b_reflectivity[i1]
              .f1[i + b_reflectivity[i1].f1.size(0) * loop_ub_tmp] =
              r[i1].f1[i + r[i1].f1.size(0) * loop_ub_tmp];
        }
      }
    }
    b_Simulation.set_size(r1.size(0));
    b_i = r1.size(0);
    for (i1 = 0; i1 < b_i; i1++) {
      kstr = r1[i1].f1.size(0);
      b_Simulation[i1].f1.set_size(r1[i1].f1.size(0), 2);
      for (loop_ub_tmp = 0; loop_ub_tmp < 2; loop_ub_tmp++) {
        for (i = 0; i < kstr; i++) {
          b_Simulation[i1].f1[i + b_Simulation[i1].f1.size(0) * loop_ub_tmp] =
              r1[i1].f1[i + r1[i1].f1.size(0) * loop_ub_tmp];
        }
      }
    }
    b_allLayers.set_size(r2.size(0));
    b_i = r2.size(0);
    for (i1 = 0; i1 < b_i; i1++) {
      kstr = r2[i1].f1.size(1);
      b_allLayers[i1].f1.set_size(r2[i1].f1.size(0), r2[i1].f1.size(1));
      for (loop_ub_tmp = 0; loop_ub_tmp < kstr; loop_ub_tmp++) {
        int loop_ub;
        loop_ub = r2[i1].f1.size(0);
        for (i = 0; i < loop_ub; i++) {
          b_allLayers[i1].f1[i + b_allLayers[i1].f1.size(0) * loop_ub_tmp] =
              r2[i1].f1[i + r2[i1].f1.size(0) * loop_ub_tmp];
        }
      }
    }
    reflectivity.set_size(b_reflectivity.size(0));
    kstr = b_reflectivity.size(0);
    for (b_i = 0; b_i < kstr; b_i++) {
      reflectivity[b_i] = b_reflectivity[b_i];
    }
    Simulation.set_size(b_Simulation.size(0));
    kstr = b_Simulation.size(0);
    for (b_i = 0; b_i < kstr; b_i++) {
      Simulation[b_i] = b_Simulation[b_i];
    }
    allLayers.set_size(b_allLayers.size(0));
    kstr = b_allLayers.size(0);
    for (b_i = 0; b_i < kstr; b_i++) {
      allLayers[b_i] = b_allLayers[b_i];
    }
  } break;
  }
  problem->calculations.sum_chi = coder::sum(problem->calculations.all_chis);
}

// End of code generation (standardTF_custLay_reflectivityCalculation.cpp)
