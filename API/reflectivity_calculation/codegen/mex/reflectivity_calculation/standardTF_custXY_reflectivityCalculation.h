/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_custXY_reflectivityCalculation.h
 *
 * Code generation for function 'standardTF_custXY_reflectivityCalculation'
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
void c_standardTF_custXY_reflectivit(const emlrtStack *sp, const struct0_T
  *problemDef, const cell_13 *problemDef_cells, const struct2_T *controls,
  struct4_T *problem, emxArray_cell_wrap_14 *reflectivity, emxArray_cell_wrap_8 *
  Simulation, emxArray_cell_wrap_9 *shifted_data, emxArray_cell_wrap_9
  *layerSlds, emxArray_cell_wrap_8 *sldProfiles, emxArray_cell_wrap_15
  *allLayers);

/* End of code generation (standardTF_custXY_reflectivityCalculation.h) */
