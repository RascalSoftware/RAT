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

#ifndef STANDARDTF_STANLAY_REFLECTIVITYCALCULATION_H
#define STANDARDTF_STANLAY_REFLECTIVITYCALCULATION_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"

/* Function Declarations */
extern void c_standardTF_stanLay_reflectivi(const struct0_T *problemDef, const
  cell_4 *problemDef_cells, const struct2_T *controls, struct4_T *problem,
  emxArray_cell_wrap_9 *reflectivity, emxArray_cell_wrap_9 *Simulation,
  emxArray_cell_wrap_1 *shifted_data, emxArray_cell_wrap_1 *layerSlds,
  emxArray_cell_wrap_9 *sldProfiles, emxArray_cell_wrap_8 *allLayers);

#endif

/* End of code generation (standardTF_stanLay_reflectivityCalculation.h) */
