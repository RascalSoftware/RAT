//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  standardTF_stanlay_single.h
//
//  Code generation for function 'standardTF_stanlay_single'
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
void standardTF_stanlay_single(const emlrtStack *sp, const struct0_T *problemDef,
  const cell_14 *problemDef_cells, const struct2_T *controls, coder::array<
  real_T, 1U> &outSsubs, coder::array<real_T, 1U> &backgs, coder::array<real_T,
  1U> &qshifts, coder::array<real_T, 1U> &sfs, coder::array<real_T, 1U> &nbas,
  coder::array<real_T, 1U> &nbss, coder::array<real_T, 1U> &resols, coder::array<
  real_T, 1U> &chis, coder::array<cell_wrap_7, 1U> &reflectivity, coder::array<
  cell_wrap_7, 1U> &Simulation, coder::array<cell_wrap_1, 1U> &shifted_data,
  coder::array<cell_wrap_8, 1U> &layerSlds, coder::array<cell_wrap_1, 1U>
  &sldProfiles, coder::array<cell_wrap_1, 1U> &allLayers, coder::array<real_T,
  1U> &allRoughs);

// End of code generation (standardTF_stanlay_single.h)
