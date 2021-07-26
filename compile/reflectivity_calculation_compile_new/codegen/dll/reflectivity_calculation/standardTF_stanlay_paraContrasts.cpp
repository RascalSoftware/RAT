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
#include "allocateLayersForContrast.h"
#include "backSort.h"
#include "reflectivity_calculation_internal_types.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "standardTF_layers_core.h"
#include "coder_array.h"
#include <cmath>

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
  const coder::array<cell_wrap_2, 1U> *layersDetails;
  coder::array<cell_wrap_15, 2U> outParameterisedLayers;
  coder::array<double, 2U> Simul;
  coder::array<double, 2U> layerSld;
  coder::array<double, 2U> reflect;
  coder::array<double, 2U> sldProfile;
  coder::array<double, 2U> thisContrastLayers;
  coder::array<double, 2U> thisData;
  double thisOutLayer[5];
  double calcSld;
  double thisBackground;
  double thisChiSquared;
  double thisNba;
  double thisNbs;
  double thisQshift;
  double thisResol;
  double thisSf;
  double thisSsubs;
  int b_loop_ub;
  int c_i;
  int i;
  int i1;
  int i2;
  int loop_ub;
  int nParams;
  int ub_loop;
  //  Standard Layers calculation paralelised over the outer loop
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
  //  Extract individual parameters from problemDef
  // Extract individual parameters from problemDef
  nParams = problemDef->params.size(1);
  calcSld = controls->calcSld;
  //  Allocate the memory for the output arrays before the main loop
  //    --- Begin memory allocation ---
  ub_loop = static_cast<int>(problemDef->numberOfContrasts);
  backgs.set_size(static_cast<int>(problemDef->numberOfContrasts));
  allLayers.set_size(static_cast<int>(problemDef->numberOfContrasts));
  for (i = 0; i < ub_loop; i++) {
    allLayers[i].f1.set_size(2, 1);
    allLayers[i].f1[0] = 1.0;
    allLayers[i].f1[1] = 1.0;
  }
  //    --- End memory allocation ---
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
  for (ub_loop = 0; ub_loop < 5; ub_loop++) {
    thisOutLayer[ub_loop] = 0.0;
  }
  outParameterisedLayers.set_size(1, problemDef_cells->f6.size(0));
  ub_loop = problemDef_cells->f6.size(0);
  for (i = 0; i < ub_loop; i++) {
    int b_i;
    b_i = (*layersDetails)[i].f1.size(1);
    for (int n{0}; n <= b_i - 2; n++) {
      if (!std::isnan((*layersDetails)[i].f1[n])) {
        thisOutLayer[n] =
            problemDef->params[static_cast<int>((*layersDetails)[i].f1[n]) - 1];
      } else {
        thisOutLayer[n] = rtNaN;
      }
    }
    thisOutLayer[(*layersDetails)[i].f1.size(1) - 1] =
        (*layersDetails)[i].f1[(*layersDetails)[i].f1.size(1) - 1];
    for (b_i = 0; b_i < 5; b_i++) {
      outParameterisedLayers[i].f1[b_i] = thisOutLayer[b_i];
    }
  }
  //  Parallel Loop over all the contrasts
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
  allRoughs.set_size(static_cast<int>(problemDef->numberOfContrasts));
  ub_loop = static_cast<int>(problemDef->numberOfContrasts) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    thisContrastLayers, sldProfile, reflect, Simul, thisData, layerSld,        \
    thisSsubs, thisChiSquared, thisResol, thisNbs, thisNba, thisSf,            \
    thisQshift, thisBackground, c_i, loop_ub, i1, b_loop_ub, i2)

  for (c_i = 0; c_i <= ub_loop; c_i++) {
    //  Extract the relevant parameter values for this contrast
    //  from the input arrays.
    //  First need to decide which values of the backrounds, scalefactors
    //  data shifts and bulk contrasts are associated with this contrast
    backSort(problemDef->contrastBacks[c_i], problemDef->contrastShifts[c_i],
             problemDef->contrastScales[c_i], problemDef->contrastNbas[c_i],
             problemDef->contrastNbss[c_i], problemDef->contrastRes[c_i],
             problemDef->backs, problemDef->shifts, problemDef->sf,
             problemDef->nba, problemDef->nbs, problemDef->res, &thisBackground,
             &thisQshift, &thisSf, &thisNba, &thisNbs, &thisResol);
    //  Also need to determine which layers from the overall layers list
    //  are required for this contrast, and put them in the correct order
    //  according to geometry
    allocateLayersForContrast(problemDef_cells->f5[c_i].f1,
                              outParameterisedLayers, thisContrastLayers);
    //  For the other parameters, we extract the correct ones from the input
    //  arrays
    //  Substrate roughness is always first parameter for standard layers
    //  Now call the core standardTF_stanlay reflectivity calculation
    //  In this case we are single cored  over points.
    //  Call the calculation
    standardTF_layers_core(
        thisContrastLayers, problemDef->params[0], problemDef->geometry,
        thisNba, thisNbs, problemDef->resample[c_i], calcSld, thisSf,
        thisQshift, problemDef->dataPresent[c_i], problemDef_cells->f2[c_i].f1,
        problemDef_cells->f3[c_i].f1, problemDef_cells->f4[c_i].f1,
        problemDef_cells->f1[c_i].f1, thisBackground, thisResol,
        problemDef->contrastBacksType[c_i], static_cast<double>(nParams),
        sldProfile, reflect, Simul, thisData, layerSld, &thisChiSquared,
        &thisSsubs);
    //  Store returned values for this contrast in the output arrays.
    //  As well as the calculated profiles, we also store a record of
    //  the other values (background, scalefactors etc) for each contrast
    //  for future use.
    outSsubs[c_i] = thisSsubs;
    loop_ub = sldProfile.size(1);
    sldProfiles[c_i].f1.set_size(sldProfile.size(0), sldProfile.size(1));
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_loop_ub = sldProfile.size(0);
      for (i2 = 0; i2 < b_loop_ub; i2++) {
        sldProfiles[c_i].f1[i2 + sldProfiles[c_i].f1.size(0) * i1] =
            sldProfile[i2 + sldProfile.size(0) * i1];
      }
    }
    loop_ub = reflect.size(0);
    reflectivity[c_i].f1.set_size(reflect.size(0), 2);
    b_loop_ub = Simul.size(0);
    Simulation[c_i].f1.set_size(Simul.size(0), 2);
    for (i1 = 0; i1 < 2; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        reflectivity[c_i].f1[i2 + reflectivity[c_i].f1.size(0) * i1] =
            reflect[i2 + reflect.size(0) * i1];
      }
      for (i2 = 0; i2 < b_loop_ub; i2++) {
        Simulation[c_i].f1[i2 + Simulation[c_i].f1.size(0) * i1] =
            Simul[i2 + Simul.size(0) * i1];
      }
    }
    loop_ub = thisData.size(1);
    shifted_data[c_i].f1.set_size(thisData.size(0), thisData.size(1));
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_loop_ub = thisData.size(0);
      for (i2 = 0; i2 < b_loop_ub; i2++) {
        shifted_data[c_i].f1[i2 + shifted_data[c_i].f1.size(0) * i1] =
            thisData[i2 + thisData.size(0) * i1];
      }
    }
    loop_ub = layerSld.size(0);
    layerSlds[c_i].f1.set_size(layerSld.size(0), 3);
    for (i1 = 0; i1 < 3; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        layerSlds[c_i].f1[i2 + layerSlds[c_i].f1.size(0) * i1] =
            layerSld[i2 + layerSld.size(0) * i1];
      }
    }
    chis[c_i] = thisChiSquared;
    backgs[c_i] = thisBackground;
    qshifts[c_i] = thisQshift;
    sfs[c_i] = thisSf;
    nbas[c_i] = thisNba;
    nbss[c_i] = thisNbs;
    resols[c_i] = thisResol;
    allRoughs[c_i] = problemDef->params[0];
  }
}

// End of code generation (standardTF_stanlay_paraContrasts.cpp)
