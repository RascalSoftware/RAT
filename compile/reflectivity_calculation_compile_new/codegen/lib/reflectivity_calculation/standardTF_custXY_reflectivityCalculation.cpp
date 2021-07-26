//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// standardTF_custXY_reflectivityCalculation.cpp
//
// Code generation for function 'standardTF_custXY_reflectivityCalculation'
//

// Include files
#include "standardTF_custXY_reflectivityCalculation.h"
#include "reflectivity_calculation_internal_types.h"
#include "reflectivity_calculation_rtwutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "standardTF_custXY_paraPoints.h"
#include "standardTF_custXY_single.h"
#include "strcmp.h"
#include "sum.h"
#include "coder_array.h"

// Function Definitions
void standardTF_custXY_reflectivityCalculation(
    const struct0_T *problemDef, const cell_14 *problemDef_cells,
    const struct2_T *controls, struct4_T *problem,
    coder::array<cell_wrap_7, 1U> &reflectivity,
    coder::array<cell_wrap_7, 1U> &Simulation,
    coder::array<cell_wrap_1, 1U> &shifted_data,
    coder::array<cell_wrap_8, 1U> &layerSlds,
    coder::array<cell_wrap_1, 1U> &sldProfiles,
    coder::array<cell_wrap_1, 1U> &allLayers)
{
  coder::array<cell_wrap_10, 1U> r;
  coder::array<cell_wrap_10, 1U> r1;
  coder::array<cell_wrap_23, 1U> r2;
  int loop_ub_tmp;
  //  Custom XP profile reflectivity calculation for standardTF
  //  This function decides on parallelisation options before calling the
  //  relevant version of the main custom XY calculation. It is more
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
  for (int i{0}; i < loop_ub_tmp; i++) {
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
    reflectivity[i].f1[2] = 1.0;
    reflectivity[i].f1[3] = 1.0;
    Simulation[i].f1.set_size(2, 2);
    Simulation[i].f1[0] = 1.0;
    Simulation[i].f1[1] = 1.0;
    Simulation[i].f1[2] = 1.0;
    Simulation[i].f1[3] = 1.0;
    shifted_data[i].f1.set_size(2, 3);
    layerSlds[i].f1.set_size(2, 3);
    for (int b_i{0}; b_i < 6; b_i++) {
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
  if (coder::internal::f_strcmp(controls->para)) {
    loop_ub_tmp = 0;
  } else if (coder::internal::g_strcmp(controls->para)) {
    loop_ub_tmp = 1;
  } else if (coder::internal::h_strcmp(controls->para)) {
    loop_ub_tmp = 2;
  } else {
    loop_ub_tmp = -1;
  }
  switch (loop_ub_tmp) {
  case 0:
    standardTF_custXY_single(
        problemDef, problemDef_cells, problem->ssubs, problem->backgrounds,
        problem->qshifts, problem->scalefactors, problem->nbairs,
        problem->nbsubs, problem->resolutions, problem->calculations.all_chis,
        r, r1, shifted_data, layerSlds, sldProfiles, r2, problem->allSubRough);
    cast(r, reflectivity);
    cast(r1, Simulation);
    cast(r2, allLayers);
    break;
  case 1:
    standardTF_custXY_paraPoints(
        problemDef, problemDef_cells, problem->ssubs, problem->backgrounds,
        problem->qshifts, problem->scalefactors, problem->nbairs,
        problem->nbsubs, problem->resolutions, problem->calculations.all_chis,
        r, r1, shifted_data, layerSlds, sldProfiles, r2, problem->allSubRough);
    cast(r, reflectivity);
    cast(r1, Simulation);
    cast(r2, allLayers);
    break;
  case 2:
    standardTF_custXY_single(
        problemDef, problemDef_cells, problem->ssubs, problem->backgrounds,
        problem->qshifts, problem->scalefactors, problem->nbairs,
        problem->nbsubs, problem->resolutions, problem->calculations.all_chis,
        r, r1, shifted_data, layerSlds, sldProfiles, r2, problem->allSubRough);
    cast(r, reflectivity);
    cast(r1, Simulation);
    cast(r2, allLayers);
    break;
  }
  problem->calculations.sum_chi = coder::sum(problem->calculations.all_chis);
}

// End of code generation (standardTF_custXY_reflectivityCalculation.cpp)
