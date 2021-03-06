//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  standardTF_stanlay_paraAll.h
//
//  Code generation for function 'standardTF_stanlay_paraAll'
//


#pragma once

// Include files
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
void standardTF_stanlay_paraAll(const emlrtStack *sp, const coder::array<real_T,
  2U> &resample, real_T numberOfContrasts, const coder::array<char_T, 2U>
  &geometry, const coder::array<cell_wrap_0, 2U> &repeatLayers, const coder::
  array<real_T, 2U> &cBacks, const coder::array<real_T, 2U> &cShifts, const
  coder::array<real_T, 2U> &cScales, const coder::array<real_T, 2U> &cNbas,
  const coder::array<real_T, 2U> &cNbss, const coder::array<real_T, 2U> &cRes,
  const coder::array<real_T, 2U> &backs, const coder::array<real_T, 2U> &shifts,
  const coder::array<real_T, 2U> &sf, const coder::array<real_T, 2U> &nba, const
  coder::array<real_T, 2U> &nbs, const coder::array<real_T, 2U> &res, const
  coder::array<real_T, 2U> &dataPresent, const coder::array<cell_wrap_12, 2U>
  &allData, const coder::array<cell_wrap_0, 2U> &dataLimits, const coder::array<
  cell_wrap_0, 2U> &simLimits, real_T nParams, const coder::array<real_T, 2U>
  &params, const coder::array<cell_wrap_12, 2U> &contrastLayers, const coder::
  array<cell_wrap_12, 1U> &layersDetails, const coder::array<real_T, 2U>
  &backsType, real_T calcSld, coder::array<real_T, 1U> &outSsubs, coder::array<
  real_T, 1U> &backgs, coder::array<real_T, 1U> &qshifts, coder::array<real_T,
  1U> &sfs, coder::array<real_T, 1U> &nbas, coder::array<real_T, 1U> &nbss,
  coder::array<real_T, 1U> &resols, coder::array<real_T, 1U> &chis, coder::array<
  cell_wrap_6, 1U> &reflectivity, coder::array<cell_wrap_6, 1U> &Simulation,
  coder::array<cell_wrap_12, 1U> &shifted_data, coder::array<cell_wrap_7, 1U>
  &layerSlds, coder::array<cell_wrap_12, 1U> &sldProfiles, coder::array<
  cell_wrap_11, 1U> &allLayers, coder::array<real_T, 1U> &allRoughs);

// End of code generation (standardTF_stanlay_paraAll.h)
