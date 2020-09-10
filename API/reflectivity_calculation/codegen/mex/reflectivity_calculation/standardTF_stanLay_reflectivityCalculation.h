/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_stanLay_reflectivityCalculation.h
 *
 * Code generation for function 'standardTF_stanLay_reflectivityCalculation'
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
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"

/* Function Declarations */
void c_standardTF_stanLay_reflectivi(const emlrtStack *sp, const struct0_T
  *problemDef, const cell_13 *problemDef_cells, const struct2_T *controls,
  struct4_T *problem, emxArray_cell_wrap_11 *reflectivity, emxArray_cell_wrap_6 *
  Simulation, emxArray_cell_wrap_1 *shifted_data, emxArray_cell_wrap_1
  *layerSlds, emxArray_cell_wrap_11 *sldProfiles, emxArray_cell_wrap_11
  *allLayers);

/* End of code generation (standardTF_stanLay_reflectivityCalculation.h) */
