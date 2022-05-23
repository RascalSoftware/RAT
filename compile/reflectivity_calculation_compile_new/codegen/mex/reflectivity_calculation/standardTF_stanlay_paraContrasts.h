/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_stanlay_paraContrasts.h
 *
 * Code generation for function 'standardTF_stanlay_paraContrasts'
 *
 */

#pragma once

/* Include files */
#include "reflectivity_calculation_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include "omp.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void c_standardTF_stanlay_paraContra(const emlrtStack *sp, const struct0_T
  *problemDef, const cell_16 *problemDef_cells, const struct2_T *controls,
  emxArray_real_T *outSsubs, emxArray_real_T *backgs, emxArray_real_T *qshifts,
  emxArray_real_T *sfs, emxArray_real_T *nbas, emxArray_real_T *nbss,
  emxArray_real_T *resols, emxArray_real_T *chis, emxArray_cell_wrap_9
  *reflectivity, emxArray_cell_wrap_9 *Simulation, emxArray_cell_wrap_14
  *shifted_data, emxArray_cell_wrap_10 *layerSlds, emxArray_cell_wrap_14
  *sldProfiles, emxArray_cell_wrap_14 *allLayers, emxArray_real_T *allRoughs);

/* End of code generation (standardTF_stanlay_paraContrasts.h) */
