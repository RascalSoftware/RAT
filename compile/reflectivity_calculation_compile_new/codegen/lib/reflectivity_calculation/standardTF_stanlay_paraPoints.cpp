//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// standardTF_stanlay_paraPoints.cpp
//
// Code generation for function 'standardTF_stanlay_paraPoints'
//

// Include files
#include "standardTF_stanlay_paraPoints.h"
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
void standardTF_stanlay_paraPoints(
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
  coder::array<double, 2U> backs;
  coder::array<double, 2U> backsType;
  coder::array<double, 2U> cBacks;
  coder::array<double, 2U> cNbas;
  coder::array<double, 2U> cNbss;
  coder::array<double, 2U> cRes;
  coder::array<double, 2U> cScales;
  coder::array<double, 2U> cShifts;
  coder::array<double, 2U> dataPresent;
  coder::array<double, 2U> nba;
  coder::array<double, 2U> nbs;
  coder::array<double, 2U> params;
  coder::array<double, 2U> r;
  coder::array<double, 2U> res;
  coder::array<double, 2U> resample;
  coder::array<double, 2U> sf;
  coder::array<double, 2U> shifts;
  coder::array<double, 2U> sldProfile;
  coder::array<char, 2U> geometry;
  double nParams;
  double numberOfContrasts;
  double numberOfLayers;
  double thisNba;
  double thisNbs;
  double thisResol;
  double thisSf;
  int b_i;
  int i;
  //  Standard Layers calculation paralelised over the inner loop
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
                       nba, nbs, res, dataPresent, &nParams, params,
                       &numberOfLayers, resample, backsType);
  //  Allocate the memory for the output arrays before the main loop
  //    --- Begin memory allocation ---
  i = static_cast<int>(numberOfContrasts);
  backgs.set_size(i);
  allLayers.set_size(i);
  for (b_i = 0; b_i < i; b_i++) {
    allLayers[b_i].f1.set_size(2, 1);
    allLayers[b_i].f1[0] = 1.0;
    allLayers[b_i].f1[1] = 1.0;
  }
  //  ---end memory allocation---
  //  First we need to allocate the absolute values of the input
  //  parameters to all the layers in the layers list. This only needs
  //  to be done once, and so is done outside the contrasts loop
  allocateParamsToLayers(params, layersDetails, outParameterisedLayers);
  //  Single Loop over all the contrasts
  outSsubs.set_size(i);
  sldProfiles.set_size(i);
  reflectivity.set_size(i);
  Simulation.set_size(i);
  shifted_data.set_size(i);
  layerSlds.set_size(i);
  chis.set_size(i);
  qshifts.set_size(i);
  sfs.set_size(i);
  nbas.set_size(i);
  nbss.set_size(i);
  resols.set_size(i);
  allRoughs.set_size(i);
  for (b_i = 0; b_i < i; b_i++) {
    int loop_ub;
    //  Extract the relevant parameter values for this contrast
    //  from the input arrays.
    //  First need to decide which values of the backrounds, scalefactors
    //  data shifts and bulk contrasts are associated with this contrast
    backSort(cBacks[b_i], cShifts[b_i], cScales[b_i], cNbas[b_i], cNbss[b_i],
             cRes[b_i], backs, shifts, sf, nba, nbs, res, &numberOfContrasts,
             &numberOfLayers, &thisSf, &thisNba, &thisNbs, &thisResol);
    //  Also need to determine which layers from the overall layers list
    //  are required for this contrast, and put them in the correct order
    //  according to geometry
    //  For the other parameters, we extract the correct ones from the input
    //  arrays
    //  Substrate roughness is always first parameter for standard layers
    //  Now call the core standardTF_stanlay reflectivity calculation
    //  In this case we parallelise over points.
    //  Call the calculation
    allocateLayersForContrast(contrastLayers[b_i].f1, outParameterisedLayers,
                              r);
    b_standardTF_layers_core(
        r, params[0], geometry, thisNba, thisNbs, resample[b_i],
        controls->calcSld, thisSf, numberOfLayers, dataPresent[b_i],
        allData[b_i].f1, dataLimits[b_i].f1, simLimits[b_i].f1,
        repeatLayers[b_i].f1, numberOfContrasts, thisResol, backsType[b_i],
        nParams, sldProfile, reflectivity[b_i].f1, Simulation[b_i].f1,
        shifted_data[b_i].f1, layerSlds[b_i].f1, &chis[b_i], &outSsubs[b_i]);
    //  Store returned values for this contrast in the output arrays.
    //  As well as the calculated profiles, we also store a record of
    //  the other values (background, scalefactors etc) for each contrast
    //  for future use.
    sldProfiles[b_i].f1.set_size(sldProfile.size(0), sldProfile.size(1));
    loop_ub = sldProfile.size(0) * sldProfile.size(1);
    for (int i1{0}; i1 < loop_ub; i1++) {
      sldProfiles[b_i].f1[i1] = sldProfile[i1];
    }
    backgs[b_i] = numberOfContrasts;
    qshifts[b_i] = numberOfLayers;
    sfs[b_i] = thisSf;
    nbas[b_i] = thisNba;
    nbss[b_i] = thisNbs;
    resols[b_i] = thisResol;
    allRoughs[b_i] = params[0];
  }
}

// End of code generation (standardTF_stanlay_paraPoints.cpp)
