//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// standardTF_stanLay_reflectivityCalculation.cpp
//
// Code generation for function 'standardTF_stanLay_reflectivityCalculation'
//

// Include files
#include "standardTF_stanLay_reflectivityCalculation.h"
#include "allocateLayersForContrast.h"
#include "backSort.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_internal_types.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "standardTF_layers_core.h"
#include "standardTF_stanlay_paraContrasts.h"
#include "standardTF_stanlay_paraPoints.h"
#include "sum.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
void standardTF_stanLay_reflectivityCalculation(
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
  const coder::array<cell_wrap_2, 1U> *layersDetails;
  coder::array<cell_wrap_15, 2U> outParameterisedLayers;
  coder::array<double, 2U> r;
  coder::array<double, 2U> sldProfile;
  coder::array<double, 1U> backgs;
  double thisOutLayer[5];
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
  int loop_ub;
  boolean_T b_bool;
  //  Standard layers reflectivity calculation for standardTF
  //  This function decides on parallelisation options before calling the
  //  relevant version ofthe main standard layers calculation. Parallelisation
  //  is either over the outer loop ('contrasts'), or the inner loop
  //  ('points'). The easiest way to do this is to have multiple versions of
  //  the same core calculation, rather than trying to make the paralell
  //  for loops conditional (although that would be much neater) There are:
  //  points    - parallelise over points in the reflectivity calculation
  //  contrasts - parallelise over contrasts (outer for loop)
  //  Pre-allocation - It's necessary to
  //  pre-allocate the memory for all the arrays
  //  for compilation, so do this in this block.
  loop_ub = static_cast<int>(problemDef->numberOfContrasts);
  problem->ssubs.set_size(static_cast<int>(problemDef->numberOfContrasts));
  for (i = 0; i < loop_ub; i++) {
    problem->ssubs[i] = 0.0;
  }
  problem->backgrounds.set_size(
      static_cast<int>(problemDef->numberOfContrasts));
  for (i = 0; i < loop_ub; i++) {
    problem->backgrounds[i] = 0.0;
  }
  problem->qshifts.set_size(static_cast<int>(problemDef->numberOfContrasts));
  for (i = 0; i < loop_ub; i++) {
    problem->qshifts[i] = 0.0;
  }
  problem->scalefactors.set_size(
      static_cast<int>(problemDef->numberOfContrasts));
  for (i = 0; i < loop_ub; i++) {
    problem->scalefactors[i] = 0.0;
  }
  problem->nbairs.set_size(static_cast<int>(problemDef->numberOfContrasts));
  for (i = 0; i < loop_ub; i++) {
    problem->nbairs[i] = 0.0;
  }
  problem->nbsubs.set_size(static_cast<int>(problemDef->numberOfContrasts));
  for (i = 0; i < loop_ub; i++) {
    problem->nbsubs[i] = 0.0;
  }
  problem->calculations.all_chis.set_size(
      static_cast<int>(problemDef->numberOfContrasts));
  for (i = 0; i < loop_ub; i++) {
    problem->calculations.all_chis[i] = 0.0;
  }
  problem->resolutions.set_size(
      static_cast<int>(problemDef->numberOfContrasts));
  for (i = 0; i < loop_ub; i++) {
    problem->resolutions[i] = 0.0;
  }
  problem->allSubRough.set_size(
      static_cast<int>(problemDef->numberOfContrasts));
  for (i = 0; i < loop_ub; i++) {
    problem->allSubRough[i] = 0.0;
  }
  reflectivity.set_size(static_cast<int>(problemDef->numberOfContrasts));
  for (b_i = 0; b_i < loop_ub; b_i++) {
    reflectivity[b_i].f1.set_size(2, 2);
    reflectivity[b_i].f1[0] = 1.0;
    reflectivity[b_i].f1[1] = 1.0;
    reflectivity[b_i].f1[reflectivity[b_i].f1.size(0)] = 1.0;
    reflectivity[b_i].f1[reflectivity[b_i].f1.size(0) + 1] = 1.0;
  }
  Simulation.set_size(static_cast<int>(problemDef->numberOfContrasts));
  for (b_i = 0; b_i < loop_ub; b_i++) {
    Simulation[b_i].f1.set_size(2, 2);
    Simulation[b_i].f1[0] = 1.0;
    Simulation[b_i].f1[1] = 1.0;
    Simulation[b_i].f1[Simulation[b_i].f1.size(0)] = 1.0;
    Simulation[b_i].f1[Simulation[b_i].f1.size(0) + 1] = 1.0;
  }
  shifted_data.set_size(static_cast<int>(problemDef->numberOfContrasts));
  for (b_i = 0; b_i < loop_ub; b_i++) {
    shifted_data[b_i].f1.set_size(2, 3);
    for (i = 0; i < 3; i++) {
      shifted_data[b_i].f1[shifted_data[b_i].f1.size(0) * i] = 1.0;
      shifted_data[b_i].f1[shifted_data[b_i].f1.size(0) * i + 1] = 1.0;
    }
  }
  layerSlds.set_size(static_cast<int>(problemDef->numberOfContrasts));
  for (b_i = 0; b_i < loop_ub; b_i++) {
    layerSlds[b_i].f1.set_size(2, 3);
    for (i = 0; i < 3; i++) {
      layerSlds[b_i].f1[layerSlds[b_i].f1.size(0) * i] = 1.0;
      layerSlds[b_i].f1[layerSlds[b_i].f1.size(0) * i + 1] = 1.0;
    }
  }
  sldProfiles.set_size(static_cast<int>(problemDef->numberOfContrasts));
  for (b_i = 0; b_i < loop_ub; b_i++) {
    sldProfiles[b_i].f1.set_size(2, 2);
    sldProfiles[b_i].f1[0] = 1.0;
    sldProfiles[b_i].f1[1] = 1.0;
    sldProfiles[b_i].f1[sldProfiles[b_i].f1.size(0)] = 1.0;
    sldProfiles[b_i].f1[sldProfiles[b_i].f1.size(0) + 1] = 1.0;
  }
  allLayers.set_size(static_cast<int>(problemDef->numberOfContrasts));
  for (b_i = 0; b_i < loop_ub; b_i++) {
    allLayers[b_i].f1.set_size(2, 2);
    allLayers[b_i].f1[0] = 1.0;
    allLayers[b_i].f1[1] = 1.0;
    allLayers[b_i].f1[allLayers[b_i].f1.size(0)] = 1.0;
    allLayers[b_i].f1[allLayers[b_i].f1.size(0) + 1] = 1.0;
  }
  //  ------- End memory allocation -------------
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
    //  Single theraded version of the Standard Layers calculation
    //  This is the main reflectivity calculation of the standard layers
    //  calculation type. It extracts the required paramters for the contrasts
    //  from the input arrays, then passes the main calculation to
    //  'standardLayersCore', which carries out the calculation iteslf.
    //  The core calculation is common for both standard and custom layers.
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
    //  Allocate the memory for the output arrays before the main loop
    backgs.set_size(static_cast<int>(problemDef->numberOfContrasts));
    allLayers.set_size(static_cast<int>(problemDef->numberOfContrasts));
    for (b_i = 0; b_i < loop_ub; b_i++) {
      allLayers[b_i].f1.set_size(2, 2);
      allLayers[b_i].f1[0] = 1.0;
      allLayers[b_i].f1[1] = 1.0;
      allLayers[b_i].f1[allLayers[b_i].f1.size(0)] = 1.0;
      allLayers[b_i].f1[allLayers[b_i].f1.size(0) + 1] = 1.0;
    }
    //  end memory allocation.
    //  First we need to allocate the absolute values of the input
    //  parameters to all the layers in the layers list. This only needs
    //  to be done once, and so is done outside the contrasts loop
    layersDetails = &problemDef_cells->f6;
    //  Allocates parameters from the parameter array to the correct layers
    //
    //  This function takes the list of all layers in 'layersDetails',
    //  then loops over all the layers, putting in the correct
    //  parameter value from the parameters array into each layer in
    //  the 'outLayers' cell array
    for (i = 0; i < 5; i++) {
      thisOutLayer[i] = 0.0;
    }
    outParameterisedLayers.set_size(1, problemDef_cells->f6.size(0));
    i = problemDef_cells->f6.size(0);
    for (b_i = 0; b_i < i; b_i++) {
      i1 = (*layersDetails)[b_i].f1.size(1);
      for (kstr = 0; kstr <= i1 - 2; kstr++) {
        if (!std::isnan((*layersDetails)[b_i].f1[kstr])) {
          thisOutLayer[kstr] =
              problemDef
                  ->params[static_cast<int>((*layersDetails)[b_i].f1[kstr]) -
                           1];
        } else {
          thisOutLayer[kstr] = rtNaN;
        }
      }
      thisOutLayer[(*layersDetails)[b_i].f1.size(1) - 1] =
          (*layersDetails)[b_i].f1[(*layersDetails)[b_i].f1.size(1) - 1];
      for (i1 = 0; i1 < 5; i1++) {
        outParameterisedLayers[b_i].f1[i1] = thisOutLayer[i1];
      }
    }
    //  Loop over all the contrasts
    problem->ssubs.set_size(static_cast<int>(problemDef->numberOfContrasts));
    sldProfiles.set_size(static_cast<int>(problemDef->numberOfContrasts));
    reflectivity.set_size(static_cast<int>(problemDef->numberOfContrasts));
    Simulation.set_size(static_cast<int>(problemDef->numberOfContrasts));
    shifted_data.set_size(static_cast<int>(problemDef->numberOfContrasts));
    layerSlds.set_size(static_cast<int>(problemDef->numberOfContrasts));
    problem->calculations.all_chis.set_size(
        static_cast<int>(problemDef->numberOfContrasts));
    problem->qshifts.set_size(static_cast<int>(problemDef->numberOfContrasts));
    problem->scalefactors.set_size(
        static_cast<int>(problemDef->numberOfContrasts));
    problem->nbairs.set_size(static_cast<int>(problemDef->numberOfContrasts));
    problem->nbsubs.set_size(static_cast<int>(problemDef->numberOfContrasts));
    problem->resolutions.set_size(
        static_cast<int>(problemDef->numberOfContrasts));
    problem->allSubRough.set_size(
        static_cast<int>(problemDef->numberOfContrasts));
    for (b_i = 0; b_i < loop_ub; b_i++) {
      //  Extract the relevant parameter values for this contrast
      //  from the input arrays.
      //  First need to decide which values of the backrounds, scalefactors
      //  data shifts and bulk contrasts are associated with this contrast
      backSort(problemDef->contrastBacks[b_i], problemDef->contrastShifts[b_i],
               problemDef->contrastScales[b_i], problemDef->contrastNbas[b_i],
               problemDef->contrastNbss[b_i], problemDef->contrastRes[b_i],
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
      allocateLayersForContrast(problemDef_cells->f5[b_i].f1,
                                outParameterisedLayers, r);
      standardTF_layers_core(
          r, problemDef->params[0], problemDef->geometry, thisNba, thisNbs,
          problemDef->resample[b_i], controls->calcSld, thisSf, thisQshift,
          problemDef->dataPresent[b_i], problemDef_cells->f2[b_i].f1,
          problemDef_cells->f3[b_i].f1, problemDef_cells->f4[b_i].f1,
          problemDef_cells->f1[b_i].f1, thisBackground, thisResol,
          problemDef->contrastBacksType[b_i],
          static_cast<double>(problemDef->params.size(1)), sldProfile,
          reflectivity[b_i].f1, Simulation[b_i].f1, shifted_data[b_i].f1,
          layerSlds[b_i].f1, &problem->calculations.all_chis[b_i],
          &problem->ssubs[b_i]);
      //  Store returned values for this contrast in the output arrays.
      //  As well as the calculated profiles, we also store a record of
      //  the other values (background, scalefactors etc) for each contrast
      //  for future use.
      kstr = sldProfile.size(1);
      sldProfiles[b_i].f1.set_size(sldProfile.size(0), sldProfile.size(1));
      for (i = 0; i < kstr; i++) {
        int b_loop_ub;
        b_loop_ub = sldProfile.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          sldProfiles[b_i].f1[i1 + sldProfiles[b_i].f1.size(0) * i] =
              sldProfile[i1 + sldProfile.size(0) * i];
        }
      }
      backgs[b_i] = thisBackground;
      problem->qshifts[b_i] = thisQshift;
      problem->scalefactors[b_i] = thisSf;
      problem->nbairs[b_i] = thisNba;
      problem->nbsubs[b_i] = thisNbs;
      problem->resolutions[b_i] = thisResol;
      problem->allSubRough[b_i] = problemDef->params[0];
    }
    problem->backgrounds.set_size(backgs.size(0));
    loop_ub = backgs.size(0);
    for (i = 0; i < loop_ub; i++) {
      problem->backgrounds[i] = backgs[i];
    }
    //           [outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,reflectivity,...
    //      Simulation,shifted_data,layerSlds,sldProfiles,allLayers,...
    //      allRoughs] =
    //      standardTF_stanlay_single(problemDef,problemDef_cells,...
    //      problemDef_limits,controls)
  } break;
  case 1:
    standardTF_stanlay_paraPoints(
        problemDef, problemDef_cells, controls, problem->ssubs,
        problem->backgrounds, problem->qshifts, problem->scalefactors,
        problem->nbairs, problem->nbsubs, problem->resolutions,
        problem->calculations.all_chis, reflectivity, Simulation, shifted_data,
        layerSlds, sldProfiles, allLayers, problem->allSubRough);
    break;
  case 2:
    standardTF_stanlay_paraContrasts(
        problemDef, problemDef_cells, controls, problem->ssubs,
        problem->backgrounds, problem->qshifts, problem->scalefactors,
        problem->nbairs, problem->nbsubs, problem->resolutions,
        problem->calculations.all_chis, reflectivity, Simulation, shifted_data,
        layerSlds, sldProfiles, allLayers, problem->allSubRough);
    //      case 'all'
    //            [outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,reflectivity,...
    //               Simulation,shifted_data,layerSlds,sldProfiles,allLayers,...
    //               allRoughs] =
    //               standardTF_stanlay_paraAll(problemDef,problemDef_cells,...
    //               problemDef_limits,controls);
    break;
  }
  problem->calculations.sum_chi = coder::sum(problem->calculations.all_chis);
}

// End of code generation (standardTF_stanLay_reflectivityCalculation.cpp)
