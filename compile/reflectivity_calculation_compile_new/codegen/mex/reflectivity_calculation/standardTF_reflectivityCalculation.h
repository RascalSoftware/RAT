//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  standardTF_reflectivityCalculation.h
//
//  Code generation for function 'standardTF_reflectivityCalculation'
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
void c_standardTF_reflectivityCalcul(const emlrtStack *sp, const struct0_T
  *problemDef, const cell_14 *problemDef_cells, const struct2_T *controls,
  struct4_T *problem, coder::array<cell_wrap_7, 1U> &reflectivity, coder::array<
  cell_wrap_7, 1U> &Simulation, coder::array<cell_wrap_1, 1U> &shifted_data,
  coder::array<cell_wrap_8, 1U> &layerSlds, coder::array<cell_wrap_1, 1U>
  &sldProfiles, coder::array<cell_wrap_1, 1U> &allLayers);

// End of code generation (standardTF_reflectivityCalculation.h)
