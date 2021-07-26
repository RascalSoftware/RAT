//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// standardTF_stanlay_paraContrasts.cpp
//
// Code generation for function 'standardTF_stanlay_paraContrasts'
//

// Include files
#include "standardTF_stanlay_paraContrasts.h"
#include "RAT_parse_cells.h"
#include "allocateLayersForContrast.h"
#include "allocateParamsToLayers.h"
#include "backSort.h"
#include "extractProblemParams.h"
#include "reflectivity_calculation_internal_types.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "standardTF_layers_core.h"
#include "coder_array.h"

// Function Definitions
void standardTF_stanlay_paraContrasts(
    const struct0_T *problemDef, const cell_14 *problemDef_cells,
    const struct2_T *controls, coder::array<double, 1U> &outSsubs,
    coder::array<double, 1U> &backgs, coder::array<double, 1U> &qshifts,
    coder::array<double, 1U> &sfs, coder::array<double, 1U> &nbas,
    coder::array<double, 1U> &nbss, coder::array<double, 1U> &resols,
    coder::array<double, 1U> &chis, coder::array<cell_wrap_7, 1U> &reflectivity,
    coder::array<cell_wrap_7, 1U> &Simulation,
    coder::array<cell_wrap_1, 1U> &shifted_data,
    coder::array<cell_wrap_8, 1U> &layerSlds,
    coder::array<cell_wrap_1, 1U> &sldProfiles,
    coder::array<cell_wrap_1, 1U> &allLayers,
    coder::array<double, 1U> &allRoughs)
{
  coder::array<cell_wrap_0, 2U> dataLimits;
  coder::array<cell_wrap_0, 2U> repeatLayers;
  coder::array<cell_wrap_0, 2U> simLimits;
  coder::array<cell_wrap_1, 2U> allData;
  coder::array<cell_wrap_15, 2U> outParameterisedLayers;
  coder::array<cell_wrap_2, 2U> contrastLayers;
  coder::array<cell_wrap_2, 1U> layersDetails;
  coder::array<double, 2U> Simul;
  coder::array<double, 2U> backs;
  coder::array<double, 2U> backsType;
  coder::array<double, 2U> cBacks;
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
  coder::array<double, 2U> thisContrastLayers;
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
  int c_i;
  int loop_ub;
  int ub_loop;
  //  Standard Layers calculation paralelised over the outer loop
  //  This is the main reflectivity calculation of the standard layers
  //  calculation type. It extracts the required paramters for the contrasts
  //  from the input arrays, then passes the main calculation to
  //  'standardLayersCore', which carries out the calculation iteslf.
  //  The core calculation is common for both standard and custom layers.
  //  Extract individual cell arrays
  RAT_parse_cells(problemDef_cells->f1, problemDef_cells->f2,
                  problemDef_cells->f3, problemDef_cells->f4,
                  problemDef_cells->f5, problemDef_cells->f6, repeatLayers,
                  allData, dataLimits, simLimits, contrastLayers,
                  layersDetails);
  //  Extract individual parameters from problemDef
  extractProblemParams(problemDef, &numberOfContrasts, geometry, cBacks,
                       cShifts, cScales, cNbas, cNbss, cRes, backs, shifts, sf,
                       nba, nbs, res, dataPresent, &nParams, params, &calcSld,
                       resample, backsType);
  calcSld = controls->calcSld;
  //  Allocate the memory for the output arrays before the main loop
  //    --- Begin memory allocation ---
  ub_loop = static_cast<int>(numberOfContrasts);
  backgs.set_size(ub_loop);
  allLayers.set_size(ub_loop);
  for (int i{0}; i < ub_loop; i++) {
    allLayers[i].f1.set_size(2, 1);
    allLayers[i].f1[0] = 1.0;
    allLayers[i].f1[1] = 1.0;
  }
  //    --- End memory allocation ---
  //  First we need to allocate the absolute values of the input
  //  parameters to all the layers in the layers list. This only needs
  //  to be done once, and so is done outside the contrasts loop
  allocateParamsToLayers(params, layersDetails, outParameterisedLayers);
  //  Parallel Loop over all the contrasts
  outSsubs.set_size(ub_loop);
  sldProfiles.set_size(ub_loop);
  reflectivity.set_size(ub_loop);
  Simulation.set_size(ub_loop);
  shifted_data.set_size(ub_loop);
  layerSlds.set_size(ub_loop);
  chis.set_size(ub_loop);
  qshifts.set_size(ub_loop);
  sfs.set_size(ub_loop);
  nbas.set_size(ub_loop);
  nbss.set_size(ub_loop);
  resols.set_size(ub_loop);
  allRoughs.set_size(ub_loop);
  ub_loop = static_cast<int>(numberOfContrasts) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    thisContrastLayers, sldProfile, reflect, Simul, thisData, layerSld,        \
    thisSsubs, thisChiSquared, thisResol, thisNbs, thisNba, thisSf,            \
    thisQshift, thisBackground, b_i, loop_ub, c_i)

  for (b_i = 0; b_i <= ub_loop; b_i++) {
    //  Extract the relevant parameter values for this contrast
    //  from the input arrays.
    //  First need to decide which values of the backrounds, scalefactors
    //  data shifts and bulk contrasts are associated with this contrast
    backSort(cBacks[b_i], cShifts[b_i], cScales[b_i], cNbas[b_i], cNbss[b_i],
             cRes[b_i], backs, shifts, sf, nba, nbs, res, &thisBackground,
             &thisQshift, &thisSf, &thisNba, &thisNbs, &thisResol);
    //  Also need to determine which layers from the overall layers list
    //  are required for this contrast, and put them in the correct order
    //  according to geometry
    allocateLayersForContrast(contrastLayers[b_i].f1, outParameterisedLayers,
                              thisContrastLayers);
    //  For the other parameters, we extract the correct ones from the input
    //  arrays
    //  Substrate roughness is always first parameter for standard layers
    //  Now call the core standardTF_stanlay reflectivity calculation
    //  In this case we are single cored  over points.
    //  Call the calculation
    standardTF_layers_core(thisContrastLayers, params[0], geometry, thisNba,
                           thisNbs, resample[b_i], calcSld, thisSf, thisQshift,
                           dataPresent[b_i], allData[b_i].f1,
                           dataLimits[b_i].f1, simLimits[b_i].f1,
                           repeatLayers[b_i].f1, thisBackground, thisResol,
                           backsType[b_i], nParams, sldProfile, reflect, Simul,
                           thisData, layerSld, &thisChiSquared, &thisSsubs);
    //  Store returned values for this contrast in the output arrays.
    //  As well as the calculated profiles, we also store a record of
    //  the other values (background, scalefactors etc) for each contrast
    //  for future use.
    outSsubs[b_i] = thisSsubs;
    sldProfiles[b_i].f1.set_size(sldProfile.size(0), sldProfile.size(1));
    loop_ub = sldProfile.size(0) * sldProfile.size(1);
    for (c_i = 0; c_i < loop_ub; c_i++) {
      sldProfiles[b_i].f1[c_i] = sldProfile[c_i];
    }
    reflectivity[b_i].f1.set_size(reflect.size(0), 2);
    loop_ub = reflect.size(0) * 2;
    for (c_i = 0; c_i < loop_ub; c_i++) {
      reflectivity[b_i].f1[c_i] = reflect[c_i];
    }
    Simulation[b_i].f1.set_size(Simul.size(0), 2);
    loop_ub = Simul.size(0) * 2;
    for (c_i = 0; c_i < loop_ub; c_i++) {
      Simulation[b_i].f1[c_i] = Simul[c_i];
    }
    shifted_data[b_i].f1.set_size(thisData.size(0), thisData.size(1));
    loop_ub = thisData.size(0) * thisData.size(1);
    for (c_i = 0; c_i < loop_ub; c_i++) {
      shifted_data[b_i].f1[c_i] = thisData[c_i];
    }
    layerSlds[b_i].f1.set_size(layerSld.size(0), 3);
    loop_ub = layerSld.size(0) * 3;
    for (c_i = 0; c_i < loop_ub; c_i++) {
      layerSlds[b_i].f1[c_i] = layerSld[c_i];
    }
    chis[b_i] = thisChiSquared;
    backgs[b_i] = thisBackground;
    qshifts[b_i] = thisQshift;
    sfs[b_i] = thisSf;
    nbas[b_i] = thisNba;
    nbss[b_i] = thisNbs;
    resols[b_i] = thisResol;
    allRoughs[b_i] = params[0];
  }
}

// End of code generation (standardTF_stanlay_paraContrasts.cpp)
