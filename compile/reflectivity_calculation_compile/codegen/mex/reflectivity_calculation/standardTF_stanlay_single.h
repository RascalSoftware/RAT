/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_stanlay_single.h
 *
 * Code generation for function 'standardTF_stanlay_single'
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
void standardTF_stanlay_single(const emlrtStack *sp, const struct0_T *problemDef,
  const cell_15 *problemDef_cells, const struct2_T *controls, emxArray_real_T
  *outSsubs, emxArray_real_T *backgs, emxArray_real_T *qshifts, emxArray_real_T *
  sfs, emxArray_real_T *nbas, emxArray_real_T *nbss, emxArray_real_T *resols,
  emxArray_real_T *chis, emxArray_cell_wrap_12 *reflectivity,
  emxArray_cell_wrap_7 *Simulation, emxArray_cell_wrap_1 *shifted_data,
  emxArray_cell_wrap_1 *layerSlds, emxArray_cell_wrap_12 *sldProfiles,
  emxArray_cell_wrap_12 *allLayers, emxArray_real_T *allRoughs);

/* End of code generation (standardTF_stanlay_single.h) */
