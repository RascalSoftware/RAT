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
#include "RAT_parse_cells.h"
#include "backSort.h"
#include "extractProblemParams.h"
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
  coder::array<double, 2U> shifts;
  coder::array<double, 2U> sldProfile;
  coder::array<double, 2U> thisData;
  coder::array<char, 2U> geometry;
  double calcSld;
  double nParams;
  double numberOfContrasts;
  double thisBackground;
  double thisChiSquared;
  double thisNba;
  double thisNbs;
  double thisQshift;
  double thisResol;
  double thisSf;
  double thisSsubs;
  int b_i;
  int i;
  int loop_ub;
  int ub_loop;
  //  Multi threaded version of the custom layers over reflectivity contrasts
  //  for standardTF reflectivity calculation.
  //  The function extracts the relevant parameters from the input
  //  arrays, allocates these on a pre-contrast basis, then calls the 'core'
  //  calculation (the core layers standardTf calc is shared between multiple
  //  calculation types).
  //  Extract individual cell arrays
  RAT_parse_cells(problemDef_cells->f1, problemDef_cells->f2,
                  problemDef_cells->f3, problemDef_cells->f4,
                  problemDef_cells->f5, problemDef_cells->f6,
                  problemDef_cells->f14, repeatLayers, allData, dataLimits,
                  simLimits, contrastLayers, layersDetails, customFiles);
  //  Extract individual parameters from problemDef struct
  extractProblemParams(problemDef, &numberOfContrasts, geometry, cBacks,
                       cShifts, cScales, cNbas, cNbss, cRes, backs, shifts, sf,
                       nba, nbs, res, dataPresent, &nParams, params, &calcSld,
                       resample, backsType, cCustFiles);
  calcSld = controls->calcSld;
  //  Pre-Allocation of output arrays...
  backgs.set_size(static_cast<int>(numberOfContrasts));
  //    --- End Memory Allocation ---
  //  Single cored over all contrasts
  allRoughs.set_size(static_cast<int>(numberOfContrasts));
  allLayers.set_size(static_cast<int>(numberOfContrasts));
  outSsubs.set_size(static_cast<int>(numberOfContrasts));
  sldProfiles.set_size(static_cast<int>(numberOfContrasts));
  reflectivity.set_size(static_cast<int>(numberOfContrasts));
  Simulation.set_size(static_cast<int>(numberOfContrasts));
  shifted_data.set_size(static_cast<int>(numberOfContrasts));
  layerSlds.set_size(static_cast<int>(numberOfContrasts));
  chis.set_size(static_cast<int>(numberOfContrasts));
  qshifts.set_size(static_cast<int>(numberOfContrasts));
  sfs.set_size(static_cast<int>(numberOfContrasts));
  nbas.set_size(static_cast<int>(numberOfContrasts));
  nbss.set_size(static_cast<int>(numberOfContrasts));
  resols.set_size(static_cast<int>(numberOfContrasts));
  ub_loop = static_cast<int>(numberOfContrasts) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    sldProfile, reflect, Simul, thisData, layerSld, thisSsubs, thisChiSquared, \
    thisResol, thisNbs, thisNba, thisSf, thisQshift, thisBackground, i, b_i,   \
    loop_ub)

  for (i = 0; i <= ub_loop; i++) {
    //  Extract the relevant parameter values for this contrast
    //  from the input arrays.
    //  First need to decide which values of the backrounds, scalefactors
    //  data shifts and bulk contrasts are associated with this contrast
    backSort(cBacks[i], cShifts[i], cScales[i], cNbas[i], cNbss[i], cRes[i],
             backs, shifts, sf, nba, nbs, res, &thisBackground, &thisQshift,
             &thisSf, &thisNba, &thisNbs, &thisResol);
    //  Call the custom layers function to get the layers array...
    allRoughs[i] = 3.0;
    allLayers[i].f1.set_size(3, 3);
    for (b_i = 0; b_i < 9; b_i++) {
      allLayers[i].f1[b_i] = dv[b_i];
    }
    //  For the other parameters, we extract the correct ones from the input
    //  arrays
    //  Now call the core standardTF_stanlay reflectivity calculation
    //  In this case we are single cored, so we do not parallelise over
    //  points
    //  Call the reflectivity calculation
    standardTF_layers_core(geometry, thisNba, thisNbs, resample[i], calcSld,
                           thisSf, thisQshift, dataPresent[i], allData[i].f1,
                           dataLimits[i].f1, simLimits[i].f1,
                           repeatLayers[i].f1, thisBackground, thisResol,
                           backsType[i], nParams, sldProfile, reflect, Simul,
                           thisData, layerSld, &thisChiSquared, &thisSsubs);
    //  Store returned values for this contrast in the output arrays.
    //  As well as the calculated profiles, we also store a record of
    //  the other values (background, scalefactors etc) for each contrast
    //  for future use.
    outSsubs[i] = thisSsubs;
    sldProfiles[i].f1.set_size(sldProfile.size(0), sldProfile.size(1));
    loop_ub = sldProfile.size(0) * sldProfile.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      sldProfiles[i].f1[b_i] = sldProfile[b_i];
    }
    reflectivity[i].f1.set_size(reflect.size(0), 2);
    loop_ub = reflect.size(0) * 2;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      reflectivity[i].f1[b_i] = reflect[b_i];
    }
    Simulation[i].f1.set_size(Simul.size(0), 2);
    loop_ub = Simul.size(0) * 2;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      Simulation[i].f1[b_i] = Simul[b_i];
    }
    shifted_data[i].f1.set_size(thisData.size(0), thisData.size(1));
    loop_ub = thisData.size(0) * thisData.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      shifted_data[i].f1[b_i] = thisData[b_i];
    }
    layerSlds[i].f1.set_size(layerSld.size(0), 3);
    loop_ub = layerSld.size(0) * 3;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      layerSlds[i].f1[b_i] = layerSld[b_i];
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
