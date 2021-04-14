/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_reflectivityCalculation.h
 *
 * Code generation for function 'standardTF_reflectivityCalculation'
 *
 */

#pragma once

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mex.h"
#include "emlrt.h"
#include "covrt.h"
#include "rtwtypes.h"
#include "reflectivity_calculation_types.h"

/* Function Declarations */
void c_standardTF_reflectivityCalcul(const emlrtStack *sp, const struct0_T
  *problemDef, const cell_15 *problemDef_cells, const struct2_T *controls,
  struct4_T *problem, emxArray_cell_wrap_12 *reflectivity, emxArray_cell_wrap_7 *
  Simulation, emxArray_cell_wrap_1 *shifted_data, emxArray_cell_wrap_1
  *layerSlds, emxArray_cell_wrap_12 *sldProfiles, emxArray_cell_wrap_12
  *allLayers);

/* End of code generation (standardTF_reflectivityCalculation.h) */
