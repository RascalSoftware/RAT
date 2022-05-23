//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// standardTF_custlay_paraContrasts.cpp
//
// Code generation for function 'standardTF_custlay_paraContrasts'
//

// Include files
#include "standardTF_custlay_paraContrasts.h"
#include "backSort.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_internal_types.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "standardTF_layers_core.h"
#include "coder_array.h"

// Function Definitions
void standardTF_custlay_paraContrasts(
    const struct0_T *problemDef, const cell_14 *problemDef_cells,
    const struct2_T *controls, coder::array<double, 1U> &outSsubs,
    coder::array<double, 1U> &backgs, coder::array<double, 1U> &qshifts,
    coder::array<double, 1U> &sfs, coder::array<double, 1U> &nbas,
    coder::array<double, 1U> &nbss, coder::array<double, 1U> &resols,
    coder::array<double, 1U> &chis,
    coder::array<cell_wrap_10, 1U> &reflectivity,
    coder::array<cell_wrap_10, 1U> &Simulation,
    coder::array<cell_wrap_1, 1U> &shifted_data,
    coder::array<cell_wrap_8, 1U> &layerSlds,
    coder::array<cell_wrap_1, 1U> &sldProfiles,
    coder::array<cell_wrap_29, 1U> &allLayers,
    coder::array<double, 1U> &allRoughs)
{
  coder::array<double, 2U> Simul;
  coder::array<double, 2U> layerSld;
  coder::array<double, 2U> reflect;
  coder::array<double, 2U> sldProfile;
  coder::array<double, 2U> thisData;
  double calcSld;
  double thisBackground;
  double thisChiSquared;
  double thisNba;
  double thisNbs;
  double thisQshift;
  double thisResol;
  double thisSf;
  double thisSsubs;
  int b_i;
  int b_loop_ub;
  int i;
  int i1;
  int loop_ub;
  int nParams;
  int ub_loop;
  //  Multi threaded version of the custom layers over reflectivity contrasts
  //  for standardTF reflectivity calculation.
  //  The function extracts the relevant parameters from the input
  //  arrays, allocates these on a pre-contrast basis, then calls the 'core'
  //  calculation (the core layers standardTf calc is shared between multiple
  //  calculation types).
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
  nParams = problemDef->params.size(1);
  calcSld = controls->calcSld;
  //  Pre-Allocation of output arrays...
  backgs.set_size(static_cast<int>(problemDef->numberOfContrasts));
  //    --- End Memory Allocation ---
  //  Single cored over all contrasts
  allRoughs.set_size(static_cast<int>(problemDef->numberOfContrasts));
  allLayers.set_size(static_cast<int>(problemDef->numberOfContrasts));
  outSsubs.set_size(static_cast<int>(problemDef->numberOfContrasts));
  sldProfiles.set_size(static_cast<int>(problemDef->numberOfContrasts));
  reflectivity.set_size(static_cast<int>(problemDef->numberOfContrasts));
  Simulation.set_size(static_cast<int>(problemDef->numberOfContrasts));
  shifted_data.set_size(static_cast<int>(problemDef->numberOfContrasts));
  layerSlds.set_size(static_cast<int>(problemDef->numberOfContrasts));
  chis.set_size(static_cast<int>(problemDef->numberOfContrasts));
  qshifts.set_size(static_cast<int>(problemDef->numberOfContrasts));
  sfs.set_size(static_cast<int>(problemDef->numberOfContrasts));
  nbas.set_size(static_cast<int>(problemDef->numberOfContrasts));
  nbss.set_size(static_cast<int>(problemDef->numberOfContrasts));
  resols.set_size(static_cast<int>(problemDef->numberOfContrasts));
  ub_loop = static_cast<int>(problemDef->numberOfContrasts) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    sldProfile, reflect, Simul, thisData, layerSld, thisSsubs, thisChiSquared, \
    thisResol, thisNbs, thisNba, thisSf, thisQshift, thisBackground, i, b_i,   \
    loop_ub, b_loop_ub, i1)

  for (i = 0; i <= ub_loop; i++) {
    //  Extract the relevant parameter values for this contrast
    //  from the input arrays.
    //  First need to decide which values of the backrounds, scalefactors
    //  data shifts and bulk contrasts are associated with this contrast
    backSort(problemDef->contrastBacks[i], problemDef->contrastShifts[i],
             problemDef->contrastScales[i], problemDef->contrastNbas[i],
             problemDef->contrastNbss[i], problemDef->contrastRes[i],
             problemDef->backs, problemDef->shifts, problemDef->sf,
             problemDef->nba, problemDef->nbs, problemDef->res, &thisBackground,
             &thisQshift, &thisSf, &thisNba, &thisNbs, &thisResol);
    //  Call the custom layers function to get the layers array...
    allRoughs[i] = 3.0;
    allLayers[i].f1.set_size(3, 3);
    for (b_i = 0; b_i < 3; b_i++) {
      allLayers[i].f1[allLayers[i].f1.size(0) * b_i] = dv[b_i][0];
      allLayers[i].f1[allLayers[i].f1.size(0) * b_i + 1] = dv[b_i][1];
      allLayers[i].f1[allLayers[i].f1.size(0) * b_i + 2] = dv[b_i][2];
    }
    //  For the other parameters, we extract the correct ones from the input
    //  arrays
    //  Now call the core standardTF_stanlay reflectivity calculation
    //  In this case we are single cored, so we do not parallelise over
    //  points
    //  Call the reflectivity calculation
    standardTF_layers_core(
        problemDef->geometry, thisNba, thisNbs, problemDef->resample[i],
        calcSld, thisSf, thisQshift, problemDef->dataPresent[i],
        problemDef_cells->f2[i].f1, problemDef_cells->f3[i].f1,
        problemDef_cells->f4[i].f1, problemDef_cells->f1[i].f1, thisBackground,
        thisResol, problemDef->contrastBacksType[i],
        static_cast<double>(nParams), sldProfile, reflect, Simul, thisData,
        layerSld, &thisChiSquared, &thisSsubs);
    //  Store returned values for this contrast in the output arrays.
    //  As well as the calculated profiles, we also store a record of
    //  the other values (background, scalefactors etc) for each contrast
    //  for future use.
    outSsubs[i] = thisSsubs;
    loop_ub = sldProfile.size(1);
    sldProfiles[i].f1.set_size(sldProfile.size(0), sldProfile.size(1));
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = sldProfile.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        sldProfiles[i].f1[i1 + sldProfiles[i].f1.size(0) * b_i] =
            sldProfile[i1 + sldProfile.size(0) * b_i];
      }
    }
    loop_ub = reflect.size(0);
    reflectivity[i].f1.set_size(reflect.size(0), 2);
    b_loop_ub = Simul.size(0);
    Simulation[i].f1.set_size(Simul.size(0), 2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        reflectivity[i].f1[i1 + reflectivity[i].f1.size(0) * b_i] =
            reflect[i1 + reflect.size(0) * b_i];
      }
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        Simulation[i].f1[i1 + Simulation[i].f1.size(0) * b_i] =
            Simul[i1 + Simul.size(0) * b_i];
      }
    }
    loop_ub = thisData.size(1);
    shifted_data[i].f1.set_size(thisData.size(0), thisData.size(1));
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = thisData.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        shifted_data[i].f1[i1 + shifted_data[i].f1.size(0) * b_i] =
            thisData[i1 + thisData.size(0) * b_i];
      }
    }
    loop_ub = layerSld.size(0);
    layerSlds[i].f1.set_size(layerSld.size(0), 3);
    for (b_i = 0; b_i < 3; b_i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        layerSlds[i].f1[i1 + layerSlds[i].f1.size(0) * b_i] =
            layerSld[i1 + layerSld.size(0) * b_i];
      }
    }
    chis[i] = thisChiSquared;
    backgs[i] = thisBackground;
    qshifts[i] = thisQshift;
    sfs[i] = thisSf;
    nbas[i] = thisNba;
    nbss[i] = thisNbs;
    resols[i] = thisResol;
    allRoughs[i] = 3.0;
  }
}

// End of code generation (standardTF_custlay_paraContrasts.cpp)
